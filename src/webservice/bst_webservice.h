#ifndef __SIPGWSERVICE_H__
#define __SIPGWSERVICE_H__

//#include "sipgw.nsmap"        // XML namespace mapping table (only needed once at the global level)
#include "soapsipgwService.h" // the service class, also #includes "soapH.h" and "soapStub.h"
#include "threads.h"

class CSipgwSvr : public sipgwService
{
    public:
    CSipgwSvr(struct soap *obj);
    CSipgwSvr();
    virtual ~CSipgwSvr();

    public:
	int startup();

	virtual int login(char* user_id, char* password, int& result);
	virtual int logout(char* user_id, char* password, int& result);
	virtual int keepalive(char* user_id, char* password, int& result);
	virtual int get_directory_info(char* target_dev_id, char* target_realm, char** directory_info_buf_out);
	virtual int ptz_control(char* target_dev_id, char* target_realm, int ptz, int ptz_speed, int& result);
	virtual int start_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
	virtual int stop_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
	virtual int start_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result);

	virtual int stop_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result);
	virtual int pause_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);

	virtual int restart_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
 	CSipgwSvr * copy();
};

#endif
