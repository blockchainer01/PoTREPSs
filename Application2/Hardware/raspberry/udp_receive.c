#include "udp_receive.h"
#include "udp_send.h"


volatile int exit2_flag = 0;  // Exit flag variable
struct data_in received_data; // Parse the buffer into struct data_in

void unpackBuffer(const char *buffer, struct data_in *received_data);

void *ucp_receive(void *arg)
{
    int sockfd;
    char buffer[sizeof(struct data_in)];
    struct sockaddr_in server_addr, client_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr));

    //printf("waiting for receiving data ...\n");

    while (!exit2_flag)
    {
        int len = sizeof(client_addr);
        // Receive data into the buffer
        if (recvfrom(sockfd, buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&client_addr, &len) == -1) {
            perror("recvfrom");
            exit(1);
        }
        //printf("1");
        
        unpackBuffer(buffer, &received_data);

        // Print received data
        // printf("Received Data:\n");
        // printf("Device ID: %d\n", received_data.dev_id);
        // printf("Message ID: %d\n", received_data.msg_id);
        // printf("Message Length: %d\n", received_data.msg_len);
        printf("UDP Received Data: Data:");
        for (int i = 0; i < received_data.msg_len / sizeof(double); i++) {
            printf("%lf ", received_data.data[i]);
        }
        printf("\n");
        //sendData(received_data.data,1);
    }

    close(sockfd);
    // Thread exit
    pthread_exit(NULL);
}

void unpackBuffer(const char *buffer, struct data_in *received_data) {
    // Use memcpy to copy data from buffer to received_data
    memcpy(&(received_data->dev_id), buffer, sizeof(short));
    memcpy(&(received_data->msg_id), buffer + sizeof(short), sizeof(int));
    memcpy(&(received_data->msg_len), buffer + sizeof(short) + sizeof(int), sizeof(short));

    // Handling byte order issues, converting network byte order to host byte order
    // received_data->dev_id = ntohs(received_data->dev_id);
    // received_data->msg_id = ntohl(received_data->msg_id);
    // received_data->msg_len = ntohs(received_data->msg_len);

    // Calculate the length of the data
    size_t dataLength = received_data->msg_len / sizeof(double);

    // Copy data
    memcpy(received_data->data, buffer + sizeof(short) + sizeof(int) + sizeof(short), dataLength * sizeof(double));

    for (size_t i = 0; i < dataLength; i++) {
        uint64_t temp;
        memcpy(&temp, &(received_data->data[i]), sizeof(uint64_t));
        received_data->data[i] = *((double *)&temp);
    }
}


