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
    // static void* real_paly_thread_proc(void*);
    // static void* review_thread_proc(void*);
    // static void* ptz_control_thread_proc(void*);
    // static void* deal_directory_info_thread_proc(void*);
    bool dispatch_message_thread_proc_is_running();

    void diapatech_message(message_base* message);

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

    // pthread_t m_real_paly_thread_id;
    // pthread_t m_review_thread_id;
    // pthread_t m_ptz_control_thread_id;
    // pthread_t m_deal_directory_info_thread_id;
};

#endif // !__TASKSCHEDUAL_H__

