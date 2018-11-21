#include <string.h>
#include <stdio.h>

#include "basicClientUserAgent.hxx"
#include "taskSchedual.h"
#include "utils/myfifo.h"
#include "message.h"
#include "dlogger/dlogger.h"

using namespace resip;
using namespace dlogger;

void * CTaskSchedual::dispatch_message_thread_proc(void* pvoid)
{
	CTaskSchedual* p = (CTaskSchedual*)pvoid;

	while(p->dispatch_message_thread_proc_is_running())
	{
		message_base* p_message = CMyFifo<message_base*>::get_instance()->pop();
		if(p_message)
		{
			p->diapatch_message(p_message);
		}
	}
}

void CTaskSchedual::diapatch_message(message_base *message)
{
	if(!message)
	{
		LOG("void message .\n");
		return;
	}

    switch (message->m_message_type)
    {
        case start_real_play:
        {
            do_start_real_play(message);
        }
    }

}

void CTaskSchedual::do_start_real_play(message_base *message)
{
    if (!message)
    {
        LOG("do_start_real_play recv a bad message. \n");
        return;
    }

    start_real_play_message *p_message = static_cast<start_real_play_message*>(message);
    if (p_message)
    {
		LOG("task_schedual recv a start_real_play_message from fifo. and will send it to sipua.\n")
        p_message->print_message_info();

		//call sipua, send message;
		BasicClientUserAgent::getInstance()->doInvite(p_message->m_user_id, p_message->m_dev_id, p_message->m_real,
						p_message->m_media_recv_ip, p_message->m_media_recv_port);
    }

    delete message;
}
void CTaskSchedual::do_stop_real_play(message_base *message)
{

}

void CTaskSchedual::do_start_preview(message_base *message)
{

}

void CTaskSchedual::do_stop_preview(message_base *message)
{

}

void CTaskSchedual::do_get_directory_info(message_base *message)
{

}

void CTaskSchedual::do_get_record_info(message_base *message)
{

}

int CTaskSchedual::start()
{
    pthread_attr_t attr; 
    pthread_attr_init(&attr); //init

	m_dispatch_message_thread_proc_is_running = true;
    int ret = pthread_create(&m_dispatch_message_pthread_id, &attr, dispatch_message_thread_proc, this);
    if (ret < 0)
    {
        //create dispatch_message_thread_proc failure
        LOG("create dispatch_message_thread_proc failure");
        exit(-1);
    }
}

int CTaskSchedual::stop()
{
	m_dispatch_message_thread_proc_is_running = false;
}

bool CTaskSchedual::dispatch_message_thread_proc_is_running()
{
	return m_dispatch_message_thread_proc_is_running;
}
