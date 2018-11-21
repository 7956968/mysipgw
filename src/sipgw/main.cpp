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

//webservice 
#include "webservice/sipgw.nsmap"
#include "webservice/bst_webservice.h"
#include <unistd.h>

#ifdef USE_SSL
#include <resip/stack/ssl/Security.hxx>
#endif

#include <signal.h>

#include "utils/myfifo.h"
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
        LOG("configure have startup. \n");

		//create message fifo;
		CMyFifo<message_base*>::get_instance()->set_capacity(500);
        LOG("message fifo capacity : 500. \n");

        //start taskSchedual
		CTaskSchedual tastSchedual;
		tastSchedual.start();
        LOG("tastSchedual have start up. \n");

        //start sipua
        BasicClientUserAgent* pUa = BasicClientUserAgent::getInstance();
        pUa->startup();
        LOG("sipua have start up. \n");

        CSipgwSvr sipgwsvr;
        sipgwsvr.startup();
        LOG("webservice have start up. \n");
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

