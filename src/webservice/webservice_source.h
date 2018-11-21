//gsoap ns2  schema namespace: urn:sipgw
//gsoap ns2  schema form:      unqualified
//gsoap ns2  service name:      sipgw
//gsoap ns2  service type:      sipgwPortType 
//gsoap ns2  service location:  http://192.168.2.128:9800/SipGwSvr
//gsoap ns2  service namespace: urn:sipgw
//gsoap ns2  service transport: http://schemas.xmlsoap.org/soap/http 

//gsoap ns2  service method-protocol:      add SOAP
//gsoap ns2  service method-style:         add rpc
//gsoap ns2  service method-encoding:      add http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns2  service method-action:        add ""
//gsoap ns2  service method-output-action: add Response

int ns2__login(char* user_id, char* password, int& result);
int ns2__logout(char* user_id, char* password, int& result);
int ns2__keepalive(char* user_id, char* password, int& result);

int ns2__get_directory_info(char* target_dev_id, char* target_realm, char** directory_info_buf_out);
int ns2__ptz_control(char* target_dev_id, char* target_realm, int ptz, int ptz_speed, int& result);

int ns2__start_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
int ns2__stop_real_play(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);

int ns2__start_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result);
int ns2__stop_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, char* start_time, char* end_time, int& result);

int ns2__pause_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
int ns2__restart_play_back(char* user_id, char* target_dev_id, char* target_realm, char* media_recv_ip, int media_recv_port, int& result);
