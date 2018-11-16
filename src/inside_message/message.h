#ifndef __message_base_h__
#define __message_base_h__

typedef enum message_type
{
    start_real_play = 1,
    stop_real_play = 2,

    start_preview = 3,
    stop_preview = 4,

    record_info = 5,

    directory_info = 6
} message_type_e;

class message_base
{
  public:
    message_base() {}
    virtual ~message_base() {}

    message_type_e get_message_type() { return m_message_type; }

  private:
    message_type_e m_message_type;
};

class start_real_play_message : public message_base
{
    public:
    start_real_play_message();
    ~start_real_play_message();

    public:
    char m_user_id[50];
    char m_dev_id[20];
    char m_real[20];
    char m_media_recv_ip[20];
    unsigned short m_media_recv_port;
};

#endif