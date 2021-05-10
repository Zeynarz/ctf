#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
int main(){
    //networking stuff
    char buffer[1024];
    char numbers[70],numString[20];
    unsigned long num[3];
    int startIndex = 0;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6000);
    inet_pton(AF_INET, "167.172.155.117", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    read(sock,buffer,1024);
    //taking out the numbers
    for (int b=253,n=0;buffer[b] != 93;b++,n++){
        numbers[n] = buffer[b];
    }
    printf("%s\n",numbers);
    for (int n = 0;n < 3;n++){
        for (int l = 0;l > -1;l++){
            if (numbers[startIndex + l] == 44){
                startIndex = startIndex + l + 2;
                break;
            }
            numString[l] = numbers[startIndex + l];
        }
        num[n] = atoi(numString);
        printf("%s\n",numString);
    }
    printf("%s\n",numbers);
}

//252 is [
