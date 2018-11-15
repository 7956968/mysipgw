#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__
#include "tinystr.h"
#include "tinyxml.h"

#define CONFIG_FILE "configure.xml"
#define CONFIG_FILE_NAME_MAX_LENGTH 200

/**
 * configure.xml

<?xml version="1.0" encoding="UTF-8"?>
<root>
    <global>
        <!-- values: sip, sips -->
        <sipscheme>sip</sipscheme>
        <useipv4>1</useipv4>
        <useipv6>0</useipv6>
        <!--logtype values: 
            cout:print log to terminal; 
            cerr:print log to terminal; 
            file:print log to file;
        -->
        <logtype>file</logtype>
        <!-- values: None, Warning, Info, Debug, Stack -->
        <loglevel>Stack</loglevel>
    </global>

    <!-- sip_server info -->
    <sipserver>
        <ip>192.168.2.128</ip>
        <tcpport>5060</tcpport>
        <udpport>5060</udpport>
        <tlsport>5061</tlsport>
        <id>34020000002000000001</id>
        <realm>3402000000</realm>
        <password>12345678a</password>
    </sipserver>

    <!-- sip_gw info -->
    <sipgw>
        <sipscheme>sip</sipscheme>
        <ip>192.168.2.128</ip>
        <tcpport>5160</tcpport>
        <udpport>5160</udpport>
        <tlsport>5161</tlsport>
        <id>34020000004000000001</id>
        <realm>3402000000</realm>
        <password>12345678a</password>
        <registerDuration>3600</registerDuration>
    </sipgw>
</root>
*/

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

    //sipgw info
    char m_sipgwScheme[20 + 1];
    char m_sipgwIp[20+1];
    char m_sipgwId[20+1];
    char m_sipgwRealm[20+1];
    char m_sipgwPassword[20+1];
    int m_sipgwTcpPort;
    int m_sipgwUdpPort;
    int m_sipgwTlsPort;
    int m_registerDuation;

private:
    CConfigure();
    virtual ~CConfigure();
};

#endif