#include "bst_webservice.h"
#include "utils/myfifo.h"
#include "inside_message/message.h"
#include "dlogger/dlogger.h"

using namespace dlogger;

void *process_request(void *arg)
{
	sipgwService *service = (sipgwService*)arg;

//	THREAD_DETACH(THREAD_ID);
	if (service)
	{
		service->serve();
		service->destroy(); /* clean up */
		delete service;
	}
	return NULL;
}

CSipgwSvr::CSipgwSvr(struct soap *obj)
    :sipgwService(obj)
{
    
}

CSipgwSvr::CSipgwSvr()
{
	this->soap = soap_new();
	this->soap_own = true;
	//sipgwService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	CSipgwSvr(this->soap);
}

CSipgwSvr::~CSipgwSvr()
{
	soap_stream_fault(std::cerr);
	destroy();
}

int CSipgwSvr::startup()
{
    soap->send_timeout = soap->recv_timeout = 5; /* 5 sec socket idle timeout */
	soap->transfer_timeout = 30; 

	SOAP_SOCKET m = bind(NULL, 9800, 100);

	if (soap_valid_socket(m))
	{
		while (soap_valid_socket(accept()))
		{
			pthread_t tid;
			void *arg = (void*)copy();
			/* use updated THREAD_CREATE from plugin/threads.h https://www.genivia.com/files/threads.zip */
			if (arg)
			{
				while (THREAD_CREATE(&tid, (void*(*)(void*))process_request, arg))
				{
					sleep(1);
				}
			}
		}
	}
    else
    {
        return -1;
    }
    return 0;
}

int CSipgwSvr::login(char *user_id, char *password, char **result)
{
    return SOAP_OK;
}

int CSipgwSvr::logout(char *user_id, char *password, char **result)
{
    return SOAP_OK;
}
int CSipgwSvr::keepalive(char *user_id, char *password, char **result)
{
    return SOAP_OK;
}

int CSipgwSvr::get_directory_info(char *target_dev_id, char *target_realm, char **directory_info_buf_out)
{
	*directory_info_buf_out = "haha";
	sleep(3);
    return SOAP_OK;
}
int CSipgwSvr::ptz_control(char *target_dev_id, char *target_realm, int ptz, int ptz_speed, char **result)
{
    return SOAP_OK;
}

int CSipgwSvr::start_real_play(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char **result)
{
		start_real_play_message* p_message = new start_real_play_message();

		memcpy(p_message->m_dev_id, target_dev_id, 20);
		memcpy(p_message->m_real, target_realm, 20);
		memcpy(p_message->m_media_recv_ip, media_recv_ip, 16);
		memcpy(p_message->m_user_id, user_id, 20);
		p_message->m_media_recv_port = media_recv_port;
		p_message->m_message_type =( message_type_e)1;

		LOG("\nwebservice receive start real play message:\n"
        "message.device_id = %s\n"
        "message.realm = %s\n"
        "message.receive_ip = %s\n"
        "message.receive_port = %d\n"
        "message.user_id = %s\n"
		, p_message->m_dev_id
		, p_message->m_real
		, p_message->m_media_recv_ip
		, p_message->m_media_recv_port
		, p_message->m_user_id);

        CMyFifo<message_base*>::get_instance()->push(p_message);

        LOG("webservice push start real play message to fifo.\n");

        *result = user_id;

        return SOAP_OK;
}
int CSipgwSvr::stop_real_play(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char **result)
{
#if 0
		PLAY_MESSAGE_T message;
		memcpy(message.device_id, target_dev_id, 20);
		memcpy(message.realm, target_realm, 20);
		memcpy(message.receive_ip, media_recv_ip, 16);
		memcpy(message.user_id, user_id, 20);
		message.receive_port = media_recv_port;
		message.play_action = real_time_stop;

		printf("webservice receive stop real play message.\n");
		printf("message.device_id = %s\n", message.device_id);
		printf("message.realm = %s\n", message.realm);
		printf("message.receive_ip = %s\n",message.receive_ip);
		printf("message.receive_port = %d\n", message.receive_port);
		printf("message.user_id = %s\n", message.user_id);

		CMyFifo<PLAY_MESSAGE_T>::get_instance()->push(message);

		printf("webservice push stop real play message to fifo.\n");
#endif
		return SOAP_OK;
}

int CSipgwSvr::start_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char *start_time, char *end_time, char **result)
{
    return SOAP_OK;
}
int CSipgwSvr::stop_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char *start_time, char *end_time, char **result)
{
    return SOAP_OK;
}

int CSipgwSvr::pause_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char **result)
{
    return SOAP_OK;
}
int CSipgwSvr::restart_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char **result)
{
    return SOAP_OK;
}

CSipgwSvr * CSipgwSvr::copy()
{
	CSipgwSvr *dup = SOAP_NEW_UNMANAGED(CSipgwSvr);
	if (dup)
	{	
		soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}
