#ifndef __SIPGWSERVICE_H__
#define __SIPGWSERVICE_H__

//#include "sipgw.nsmap"        // XML namespace mapping table (only needed once at the global level)
#include "soapsipgwService.h" // the service class, also #includes "soapH.h" and "soapStub.h"
#include "threads.h"
#include "utils/rand_generator.h"

class CSipgwSvr : public sipgwService
{
    public:
    CSipgwSvr(struct soap *obj);
    CSipgwSvr();
    virtual ~CSipgwSvr();

    public:
	int startup();
 	CSipgwSvr * copy();

    private:
    static rand_generator* m_rand_creator;

    char m_ip[16];

    //inherit from parent class

    /// Web service operation 'login' (returns SOAP_OK or error code)
    virtual int login(char *user_id, char *password, char **result) ;
    /// Web service operation 'logout' (returns SOAP_OK or error code)
    virtual int logout(char *user_id, char *password, char **result) ;
    /// Web service operation 'keepalive' (returns SOAP_OK or error code)
    virtual int keepalive(char *user_id, char *password, char **result) ;
    /// Web service operation 'get-directory-info' (returns SOAP_OK or error code)
    virtual int get_directory_info(char *target_dev_id, char *target_realm, char **directory_info_buf_out) ;
    /// Web service operation 'ptz-control' (returns SOAP_OK or error code)
    virtual int ptz_control(char *target_dev_id, char *target_realm, int ptz, int ptz_speed, char **result) ;
    /// Web service operation 'start-real-play' (returns SOAP_OK or error code)
    virtual int start_real_play(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char **call_id) ;
    /// Web service operation 'stop-real-play' (returns SOAP_OK or error code)
    virtual int stop_real_play(char *user_id, char *call_id, char **result) ;
    /// Web service operation 'start-play-back' (returns SOAP_OK or error code)
    virtual int start_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char *start_time, char *end_time, char **call_id) ;
    /// Web service operation 'stop-play-back' (returns SOAP_OK or error code)
    virtual int stop_play_back(char *user_id, char *call_id, char **result) ;
    /// Web service operation 'call-lookup' (returns SOAP_OK or error code)
    virtual int call_lookup(char *user_id, char **result) ;
};

#endif
