#include "tinystr.h"
#include "tinyxml.h"
#include "configure.h"
#include "dlogger/dlogger.h"

using namespace dlogger;

CConfigure::CConfigure()
{
}
CConfigure::~CConfigure()
{
}

CConfigure* CConfigure::m_instance = NULL;

bool CConfigure::parese(char* file_name)
{
    char ConfigFile[256+1] = {0};
	snprintf(ConfigFile, 256, "./%s", CONFIG_FILE);
	
	TiXmlDocument Doc(ConfigFile);
	bool bOkay = Doc.LoadFile();
	if (!bOkay)
	{
		LOG("TinyXml Could not load file '%s'. Error='%s'. Exiting. \n", ConfigFile, Doc.ErrorDesc() );
		return false;
	}
	
	TiXmlHandle DocHdl(&Doc);
	TiXmlElement *pElement;
    TiXmlElement *pGlobalEle;
    TiXmlElement *pSipServer;
    TiXmlElement *pSipGw;
	
    //global node configure
	pGlobalEle = DocHdl.FirstChild("root").FirstChild("global").ToElement();
	if (NULL != pGlobalEle)
	{
        pElement = pGlobalEle->FirstChild("sipscheme")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipScheme, "%s", pElement->GetText());
        }

        pElement = pGlobalEle->FirstChild("logtype")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_logType, "%s", pElement->GetText());
        }

        pElement = pGlobalEle->FirstChild("loglevel")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_logLevel, "%s", pElement->GetText());
        }

        pElement = pGlobalEle->FirstChild("useipv4")->ToElement();
        if(NULL != pElement)
        {
            if(!strcmp("1", pElement->GetText()))
            {
                m_useIpv4 = true;
            }
            else
            {
                m_useIpv4 = false;
            }
        }   

        pElement = pGlobalEle->FirstChild("useipv6")->ToElement();
        if(NULL != pElement)
        {
            if(!strcmp("1", pElement->GetText()))
            {
                m_useIpv6 = true;
            }
            else
            {
                m_useIpv6 = false;
            }
        }        
	}

    // sipserver node configure
    pSipServer = DocHdl.FirstChild("root").FirstChild("sipserver").ToElement();
	if (NULL != pSipServer)
	{
        pElement = pSipServer->FirstChild("ip")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipSvrIp, "%s", pElement->GetText());
        }

        pElement = pSipServer->FirstChild("id")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipSvrId, "%s", pElement->GetText());
        }

        pElement = pSipServer->FirstChild("realm")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipSvrRealm, "%s", pElement->GetText());
        }

        pElement = pSipServer->FirstChild("password")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipSvrPassword, "%s", pElement->GetText());
        }   

        pElement = pSipServer->FirstChild("tcpport")->ToElement();
        if(NULL != pElement)
        {
            m_sipSvrTcpPort = atoi(pElement->GetText());
        }      

        pElement = pSipServer->FirstChild("udpport")->ToElement();
        if(NULL != pElement)
        {
            m_sipSvrUdpPort = atoi(pElement->GetText());
        }   

        pElement = pSipServer->FirstChild("tlsport")->ToElement();
        if(NULL != pElement)
        {
            m_sipSvrTlsPort = atoi(pElement->GetText());
        }     
	}

    // sipgw node configure
    pSipGw = DocHdl.FirstChild("root").FirstChild("sipgw").ToElement();
	if (NULL != pSipGw)
	{
        pElement = pSipGw->FirstChild("sipscheme")->ToElement();
        if (NULL != pElement)
        {
            sprintf(m_sipgwScheme, "%s", pElement->GetText());
        }

        pElement = pSipGw->FirstChild("ip")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipgwIp, "%s", pElement->GetText());
        }

        pElement = pSipGw->FirstChild("id")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipgwId, "%s", pElement->GetText());
        }

        pElement = pSipGw->FirstChild("realm")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipgwRealm, "%s", pElement->GetText());
        }

        pElement = pSipGw->FirstChild("password")->ToElement();
        if(NULL != pElement)
        {
            sprintf(m_sipgwPassword, "%s", pElement->GetText());
        }

        pElement = pSipGw->FirstChild("tcpport")->ToElement();
        if(NULL != pElement)
        {
            m_sipgwTcpPort = atoi(pElement->GetText());
        }

        pElement = pSipGw->FirstChild("udpport")->ToElement();
        if (NULL != pElement)
        {
            m_sipgwUdpPort = atoi(pElement->GetText());
        }

        pElement = pSipGw->FirstChild("tlsport")->ToElement();
        if (NULL != pElement)
        {
            m_sipgwTlsPort = atoi(pElement->GetText());
        }

        pElement = pSipGw->FirstChild("registerDuration")->ToElement();
        if(NULL != pElement)
        {
            m_registerDuation = atoi(pElement->GetText());
        }     
	}

    printConfig();
    
    return true;
}

void CConfigure::printConfig()
{
    //global configure
    LOG("\nglobal configure:\n"
    "m_sipScheme : %s\n"
    "m_logType : %s\n"
    "m_logLevel : %s\n"
    "m_useIpv4 : %s\n"
    "m_useIpv6 : %s\n"
    , m_sipScheme
    , m_logType
    , m_logLevel
    , (m_useIpv4 ? "true" : "false")
    , (m_useIpv6 ? "true" : "false"));

    //sipSvr configure
    LOG("\nsipSvr configure:\n"
    "m_sipSvrId : %s\n"
    "m_sipSvrRealm : %s\n"
    "m_sipSvrIp : %s\n"
    "m_sipSvrPassword : %s\n"
    "m_sipSvrTcpPort : %d\n"
    "m_sipSvrUdpPort : %d\n"
    "m_sipSvrTlsPort : %d\n"
    , m_sipSvrId
    , m_sipSvrRealm
    , m_sipSvrIp
    , m_sipSvrPassword
    , m_sipSvrTcpPort
    , m_sipSvrUdpPort
    , m_sipSvrTlsPort);


    //sipgw configure
    LOG("\nsipgw configure:\n"
    "m_sipgwIp : %s\n"
    "m_sipgwId : %s\n"
    "m_sipgwRealm : %s\n"
    "m_sipgwPassword : %s\n"
    "m_sipgwTcpPort : %d\n"
    "m_registerDuation : %d\n"
    , m_sipgwIp
    , m_sipgwId
    , m_sipgwRealm
    , m_sipgwPassword
    , m_sipgwTcpPort
    , m_registerDuation);
}
