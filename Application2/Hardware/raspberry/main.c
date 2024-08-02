// #include "udp.h"
#include "udp_receive.h"
#include "udp_send.h"
#include <pthread.h>

double udpsenddata[2]={1,2,3};

int main()
{
    pthread_t serverThread;

    // Create a server thread for UDP receiving data
    if (pthread_create(&serverThread, NULL, ucp_receive, NULL) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }


    sendData(udpsenddata,3); 
   
    // Waiting for the UDP server thread to finish
    pthread_join(serverThread, NULL);

    return 0;

}

