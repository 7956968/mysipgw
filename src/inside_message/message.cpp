#include "message.h"
#include <string.h>
#include <stdio.h>

/**
 *  class start_real_play_message
*/
start_real_play_message::start_real_play_message()
{
    m_message_type = start_real_play;

    memset(m_user_id, 0x00, 50);
    memset(m_dev_id, 0x00, 20);
    memset(m_real, 0x00, 20);
    memset(m_media_recv_ip, 0x00, 20);
    m_media_recv_port = 0;

}

start_real_play_message::~start_real_play_message()
{

}

void start_real_play_message::print_message_info()
{
    printf("message info : \n"
           "message type : start_real_play_message\n"
           "m_user_id:%s\n"
           "m_dev_id:%s\n"
           "m_real:%s\n"
           "m_media_recv_ip:%s\n"
           "m_media_recv_port:%d\n",
           m_user_id,
           m_dev_id,
           m_real,
           m_media_recv_ip,
           m_media_recv_port);
}
