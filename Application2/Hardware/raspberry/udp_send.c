#include "udp_send.h"

struct data_out
{
    short dev_id;
    int msg_id;
    short msg_len;
    double data[MAXSENDSIZE];
};

int packData(const struct data_out *send_data, char *buffer)
{
    // Packing data into a buffer
    memcpy(buffer, &(send_data->dev_id), sizeof(short));
    memcpy(buffer + sizeof(short), &(send_data->msg_id), sizeof(int));
    memcpy(buffer + sizeof(short) + sizeof(int), &(send_data->msg_len), sizeof(short));

    // Calculate the length of the data
    size_t dataLength = send_data->msg_len / sizeof(double);

    memcpy(buffer + sizeof(short) + sizeof(int) + sizeof(short), send_data->data, dataLength * sizeof(double));

    return sizeof(short) + sizeof(int) + sizeof(short) + dataLength * sizeof(double);
}

void sendData(const double *data, size_t size)
{
    struct data_out send_data;
    send_data.dev_id = 1;

    send_data.msg_id = 1;
    send_data.msg_len = size * sizeof(double);

    memcpy(send_data.data, data, send_data.msg_len);

    int sockfd;
    char buffer[sizeof(struct data_out)];

    // Creating a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); 

    // Packing data into a buffer
    int dataLength = packData(&send_data, buffer);

    // Sending data using sendto
    if (sendto(sockfd, buffer, dataLength, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    printf("udp数据发送成功\n");

    // Close the socket.
    close(sockfd);
}