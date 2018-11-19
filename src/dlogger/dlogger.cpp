#include <stdio.h>
#include "dlogger.h"

namespace dlogger{

log_type_e logger::m_log_type = log_type_stdout;
logger* logger::m_instance = NULL;

logger::logger()
{
    m_fp_logfile = NULL;
}

bool logger::init_logger(char* file_name)
{
    //FILE* p_logfile;
    m_fp_logfile = fopen(file_name, "w+");
    if (m_fp_logfile)
    {
        printf("create log file success.\n");
        return true;
    }
    else
    {
        printf("create log file failure.\n");
        return false;
    }
}

log_type_e logger::get_log_type()
{
    return m_log_type;
}

void logger::set_log_type(log_type_e log_type)
{
    m_log_type = log_type;
}

void logger::uninit_logger()
{
    if (NULL != m_fp_logfile)
    {
        fclose(m_fp_logfile);
    }
}

}
