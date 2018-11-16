#ifndef __TASKSCHEDUAL_H__
#define __TASKSCHEDUAL_H__
#include <pthread.h>
#include "basicClientUserAgent.hxx"

class CTaskSchedual
{
public:
    int start();
    static void* real_paly_thread_proc(void*);
    static void* review_thread_proc(void*);
    static void* ptz_control_thread_proc(void*);
    static void* deal_directory_info_thread_proc(void*);

private:
    pthread_t m_real_paly_thread_id;
    pthread_t m_review_thread_id;
    pthread_t m_ptz_control_thread_id;
    pthread_t m_deal_directory_info_thread_id;
};

#endif // !__TASKSCHEDUAL_H__

