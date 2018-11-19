#include <stdio.h>
#include "logger.h"

namespace dlogger{

dlog_type_e dlogger::m_log_type = log_type_stdout;
dlogger* dlogger::m_instance = NULL;

dlogger::dlogger()
{
    m_fp_logfile = NULL;
}

bool dlogger::init_logger(char* file_name)
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

dlog_type_e dlogger::get_log_type()
{
    return m_log_type;
}

void dlogger::set_log_type(dlog_type_e log_type)
{
    m_log_type = log_type;
}

void dlogger::uninit_logger()
{
    if (NULL != m_fp_logfile)
    {
        fclose(m_fp_logfile);
    }
}

} // namespace dlogger
