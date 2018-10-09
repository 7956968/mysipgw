#ifndef __SIPGWSERVICE_H__
#define __SIPGWSERVICE_H__

//#include "sipgw.nsmap"        // XML namespace mapping table (only needed once at the global level)
#include "sipgwsipgwService.h" // the service class, also #includes "soapH.h" and "soapStub.h"
#include "threads.h"

class CSipgwSvr : public sipgwService
{
    public:
    CSipgwSvr(struct soap *obj);
    virtual ~CSipgwSvr();

    public:
	int startup();
};

#endif
