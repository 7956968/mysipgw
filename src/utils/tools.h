#ifndef __TOOLS_H__
#define __TOOLS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>

bool get_ip(char *network_card_name, char *ip);

#endif