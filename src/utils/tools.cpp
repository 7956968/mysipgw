#include "tools.h"

bool get_ip(char *network_card_name, char *ip)
{
    struct ifreq temp;
    struct sockaddr_in *myaddr;
    int fd = 0;
    int ret = -1;

    strcpy(temp.ifr_name, network_card_name);
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return false;
    }

    ret = ioctl(fd, SIOCGIFADDR, &temp);

    if (ret < 0)
    {
        close(fd);
        return false;
    }
    close(fd);

    myaddr = (struct sockaddr_in *)&(temp.ifr_addr);
    strcpy(ip, inet_ntoa(myaddr->sin_addr));

    return true;
}