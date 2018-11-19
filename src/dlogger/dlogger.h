/**
 *  description:
 *     a simple log system, which will runing on windows and linux.
 * 
 *  author: YandDong
 *  date:   20181117
 * 
 * */

#ifndef __DLOGGER_H__
#define __DLOGGER_H__

#include "stdio.h"
#include "stdint.h"

namespace dlogger{

typedef enum log_type
{
    log_type_stdout = 1,
    log_type_file = 2
}log_type_e;

class logger
{
public:
    static log_type_e m_log_type;
    static logger* m_instance;
    static logger* get_instance()
    {
        if (NULL != m_instance)
        {
            return m_instance;
        }
        else
        {
            m_instance = new logger();
            return m_instance;
        }
    }
    static log_type_e get_log_type();
    static void set_log_type(log_type_e log_type);

    bool init_logger(char* file_name);
    void uninit_logger();

    ~logger() {}
public:
    FILE* m_fp_logfile;
private:
    logger();

private:  
};

#define LOG(fmt, ...) do{\
    if(log_type_stdout == logger::get_log_type() )\
    {\
        fprintf(stdout, "[DEBUG] %s\n%s:%d:" fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    else if(log_type_file == logger::get_log_type() )\
    {\
        if(NULL != logger::get_instance()->m_fp_logfile)\
        {\
            fprintf(logger::get_instance()->m_fp_logfile, "%s\n%s:%d:" fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
        }\
        else\
        {\
            printf("log_file not init.\n");\
        }\
    }}while(0);
	
}

#endif // !__DLOGGER_H__

