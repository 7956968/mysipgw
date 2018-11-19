#if defined(HAVE_CONFIG_HXX)
#include "resip/stack/config.hxx"
#endif

#include <cstring>
#include <cassert>

#ifndef __APPLE__
bool TRUE=true;
bool FALSE=false;
#endif

#include "sipua/basicClientUserAgent.hxx"
//#include <resip/stack/SipStack.hxx>
//#include <resip/stack/Uri.hxx>
//#include <rutil/Logger.hxx>

//webservice 
#include "webservice/sipgw.nsmap"
#include "webservice/SipgwService.h"
#include <unistd.h>

#ifdef USE_SSL
#include <resip/stack/ssl/Security.hxx>
#endif

#include <signal.h>

#include "myfifo.h"
#include "message.h"
#include "taskSchedual.h"
#include "configure.h"
#include "dlogger/dlogger.h"

#define CONFIGURE_FILE "configure.xml"

using namespace resip;
using namespace std;
using namespace dlogger;

#define RESIPROCATE_SUBSYSTEM Subsystem::TEST

static bool exitSignalDetected = false;

static void signalHandler(int signo)
{
    std::cerr << "Shutting down" << endl;
    exitSignalDetected = true;
}

int http_get(struct soap *soap)
{
    FILE *fd;
    char *s = strchr(soap->path, '?'); // soap->path has the URL path (soap->endpoint has the full URL)
    char *respose_message = "method not supported\n if you want get wsdl file. please input:"
        "\n\"http://192.168.2.128:9800/SipGwServer?wsdl\" "
        "\nin your web browser.";
    if (!s || strcmp(s, "?wsdl"))
    {
        //return SOAP_GET_METHOD; // GET method not supported
        soap_send_raw(soap, respose_message, strlen(respose_message));
        return SOAP_OK; 
    }

    fd = fopen("sipgw.wsdl", "rb"); // open WSDL file to copy as a response

    if (!fd)
    {
        return 404; // return HTTP 404 not found
    }

    soap->http_content = "text/xml; charset=utf-8"; // HTTP header with text/xml content 
    soap_response(soap, SOAP_FILE); 
    for (;;) 
    {
        size_t r = fread(soap->tmpbuf, 1, sizeof(soap->tmpbuf), fd); 
        if (!r || soap_send_raw(soap, soap->tmpbuf, r)) 
            break;
    } 
    fclose(fd); 
    soap_end_send(soap); 
    return SOAP_OK; 
}

void setup_signal()
{
#ifndef _WIN32
    if ( signal( SIGPIPE, SIG_IGN) == SIG_ERR)
    {
        cerr << "Couldn't install signal handler for SIGPIPE" << endl;
        exit(-1);
    }
#endif
/*
    if ( signal( SIGINT, signalHandler ) == SIG_ERR )
    {
        cerr << "Couldn't install signal handler for SIGINT" << endl;
        exit( -1 );
    }*/

    if ( signal( SIGTERM, signalHandler ) == SIG_ERR )
    {
        cerr << "Couldn't install signal handler for SIGTERM" << endl;
        exit( -1 );
    }
}

int main(int argc, char* argv[])
{
    try
    {
		logger::set_log_type(log_type_file);
		if (!logger::get_instance()->init_logger("log/sipgw.log"))
		{
			return -1;
		}
		setup_signal();

        //read configure file
        CConfigure::getInstance()->parese(CONFIGURE_FILE);

		//create message fifo;
		CMyFifo<message_base*>::get_instance()->set_capacity(500);

		//start taskSchedual
		CTaskSchedual tastSchedual;
		tastSchedual.start();

        //start sipua
        BasicClientUserAgent* pUa = BasicClientUserAgent::getInstance();
        pUa->startup();

        //start webservice
        struct soap ServerSoap;
        ServerSoap.fget = http_get;
        CSipgwSvr sipgwsvr(&ServerSoap);
        sipgwsvr.startup();
    }
#ifdef USE_SSL
    catch (BaseSecurity::Exception& e)
    {
        std::cout<<"Couldn't set up security object:"<< e <<std:endl;
        exit(-1);
    }
#endif
    catch (BaseException& e)
    {
        std::cout << "Caught:" << e << std::endl;
        exit(-1);
    }
    catch( ... )
    {
        std::cout<<"Caught non-resip exception:"<<std::endl;
        exit(-1);
    }
	
	logger::get_instance()->uninit_logger();
    return 0;
}

