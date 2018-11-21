#/bin/sh

WEB_SERVICE_H=webservice_source.h
WEB_SERVICE_NAME=sipgw_service

SOAPCPP2=/usr/local/gsoap/bin/soapcpp2
WSDL2H=/usr/local/gsoap/bin/wsdl2h

${SOAPCPP2} -j -r -SL -x ${WEB_SERVICE_H}
