#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__
#include "tinystr.h"
#include "tinyxml.h"

#define CONFIG_FILE "configure.xml"
#define CONFIG_FILE_NAME_MAX_LENGTH 200

class CConfigure
{
public:
    static CConfigure* m_instance;
    static CConfigure* getInstance()
    {
        if(NULL == m_instance)
        {
            m_instance = new CConfigure();
            return m_instance;
        }
        else
        {
            return m_instance;
        }
    }

    static void releaseInstance()
    {
        if(NULL == m_instance)
        {
            // do nothing
        }
        else
        {
            delete m_instance;
        }
    }

    //bool readConfigFile(char* file_name);
    bool parese(char* file_name);
    void printConfig();

public:
    //globle info
    bool m_useIpv4;
    bool m_useIpv6;
    char m_sipScheme[20+1];
    char m_logType[20+1];
    char m_logLevel[20+1];

    //sipsvr info
    char m_sipSvrId[20+1];
    char m_sipSvrRealm[20+1];
    char m_sipSvrIp[20+1];
    char m_sipSvrPassword[20+1];
    int m_sipSvrTcpPort;
    int m_sipSvrUdpPort;
    int m_sipSvrTlsPort;

    char m_sipgwIp[20+1];
    char m_sipgwId[20+1];
    char m_sipgwRealm[20+1];
    char m_sipgwPassword[20+1];
    int m_sipgwPort;
    int m_registerDuation;

private:
    CConfigure();
    virtual ~CConfigure();
};

#endif