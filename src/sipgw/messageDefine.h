#ifndef __MESSAGEDEFINE_H__
#define __MESSAGEDEFINE_H__

typedef enum REAL_TIME_ACTION
{
    real_time_paly = 1,
    real_time_stop = 2
}REAL_TIME_ACTION_E;

typedef enum REVIEW_ACTION
{
    review_paly = 1,
    review_pause,
    review_continue,
    review_stop
}REVIEW_ACTION_E;

typedef struct PLAY_MESSAGE
{
    PLAY_MESSAGE()
    {

    }
    PLAY_MESSAGE(int)
    {
        user_id = NULL;
        device_id = NULL;
        realm = NULL;
        receive_ip = NULL;
        receive_port = 0;
        play_action = real_time_paly;
    }

    char* user_id;
    char* device_id;
    char* realm;
    char* receive_ip;
    int receive_port;
    REAL_TIME_ACTION_E play_action;
} PLAY_MESSAGE_T;

#endif // !__MESSAGEDEFINE_H__

