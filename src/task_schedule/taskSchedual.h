#ifndef __TASKSCHEDUAL_H__
#define __TASKSCHEDUAL_H__
#include <pthread.h>

#include "message.h"
//#include "basicClientUserAgent.hxx"

class CTaskSchedual
{
public:
    int start();
    int stop();
    static void* dispatch_message_thread_proc(void *);

    bool dispatch_message_thread_proc_is_running();
    void diapatch_message(message_base* message);
    void do_start_real_play(message_base *message);
    void do_stop_real_play(message_base *message);
    void do_start_preview(message_base *message);
    void do_stop_preview(message_base *message);
    void do_get_directory_info(message_base *message);
    void do_get_record_info(message_base *message);

  private:
  	bool m_dispatch_message_thread_proc_is_running;
    pthread_t m_dispatch_message_pthread_id;
    pthread_t m_respose_deal_proc_pthread_id;
};

#endif // !__TASKSCHEDUAL_H__

