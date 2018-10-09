#include "SipgwService.h"

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


//以下实现父类函数
int sipgwService::login(char* user_id, char* password, int& result)
{
    return SOAP_OK;
}

int sipgwService::logout(char* user_id, char* password, int& result)
{
    return SOAP_OK;
}
int sipgwService::keepalive(char* user_id, char* password, int& result)
{
    return SOAP_OK;
}

int sipgwService::get_directory_info(char* target_dev_id, char* target_realm, char** directory_info_buf_out)
{
	*directory_info_buf_out = "haha";
	sleep(3);
    return SOAP_OK;
}
int sipgwService::ptz_control(char* target_dev_id, char* target_realm, int ptz, int ptz_speed, int& result)
{
    return SOAP_OK;
}

int sipgwService::start_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result)
{
    return SOAP_OK;
}
int sipgwService::stop_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result)
{
    return SOAP_OK;
}

int sipgwService::start_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result)
{
    return SOAP_OK;
}
int sipgwService::stop_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result)
{
    return SOAP_OK;
}

int sipgwService::pause_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result)
{
    return SOAP_OK;
}
int sipgwService::restart_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result)
{
    return SOAP_OK;
}
