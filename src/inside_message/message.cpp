#include "message.h"
#include <string.h>
#include <stdio.h>
#include "dlogger/dlogger.h"

using namespace dlogger;
/**
 *  class start_real_play_message
*/
start_real_play_message::start_real_play_message()
{
    m_message_type = start_real_play;

    memset(m_call_id, 0x00, 70 + 1);
    memset(m_user_id, 0x00, 50+1);
    memset(m_dev_id, 0x00, 20+1);
    memset(m_real, 0x00, 20+1);
    memset(m_media_recv_ip, 0x00, 20+1);
    m_media_recv_port = 0;

}

start_real_play_message::~start_real_play_message()
{

}

void start_real_play_message::print_message_info()
{
    LOG("message info : \n"
        "message type : start_real_play_message\n"
        "m_call_id:%s\n"
        "m_user_id:%s\n"
        "m_dev_id:%s\n"
        "m_real:%s\n"
        "m_media_recv_ip:%s\n"
        "m_media_recv_port:%d\n",
        m_call_id,
        m_user_id,
        m_dev_id,
        m_real,
        m_media_recv_ip,
        m_media_recv_port);
}

/**
 *  class stop_real_play_message
*/
stop_real_play_message::stop_real_play_message()
{
    m_message_type = stop_real_play;

    memset(m_call_id, 0x00, 70 + 1);
    memset(m_user_id, 0x00, 50 + 1);
}

stop_real_play_message::~stop_real_play_message()
{
}

void stop_real_play_message::print_message_info()
{
    LOG("message info : \n"
        "message type : stop_real_play_message\n"
        "m_call_id:%s\n"
        "m_user_id:%s\n",
        m_call_id,
        m_user_id);
}
