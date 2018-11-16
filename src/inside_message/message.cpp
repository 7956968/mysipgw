#include "message.h"
#include <string.h>

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
