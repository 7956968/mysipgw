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
		memset(user_id, 0x00, 20);
		memset(device_id, 0x00, 20);
		memset(realm, 0x00, 20);
		memset(receive_ip, 0x00, 16);
        play_action = real_time_paly;
    }
    PLAY_MESSAGE(int)
    {
		memset(user_id, 0x00, 20);
		memset(device_id, 0x00, 20);
		memset(realm, 0x00, 20);
		memset(receive_ip, 0x00, 16);
        play_action = real_time_paly;
    }

    char user_id[20];
    char device_id[20];
    char realm[20];
    char receive_ip[16];
    int receive_port;
    REAL_TIME_ACTION_E play_action;
} PLAY_MESSAGE_T;

#endif // !__MESSAGEDEFINE_H__

