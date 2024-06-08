#include <stdio.h>
#include <string.h>

int main() {
    char ip[17];
    int octet[4] = {0};
    int i, j, dotCount = 0, pos = 0;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    // Split the IP address into octets
    for(i = 0; i < strlen(ip) && dotCount < 4; i++) {
        if(ip[i] == '.') {
            dotCount++;
            pos = 0;
        } else {
            octet[dotCount] = octet[dotCount] * 10 + (ip[i] - '0');
        }
    }

    // Identify the class and network ID
    if(octet[0] >= 1 && octet[0] <= 126) {
        printf("Class: A\n");
        printf("Network ID: %d.0.0.0\n", octet[0]);
    } else if(octet[0] >= 128 && octet[0] <= 191) {
        printf("Class: B\n");
        printf("Network ID: %d.%d.0.0\n", octet[0], octet[1]);
    } else if(octet[0] >= 192 && octet[0] <= 223) {
        printf("Class: C\n");
        printf("Network ID: %d.%d.%d.0\n", octet[0], octet[1], octet[2]);
    } else if(octet[0] >= 224 && octet[0] <= 239) {
        printf("Class: D\n");
        printf("Network ID: Not applicable\n");
    } else if(octet[0] >= 240 && octet[0] <= 255) {
        printf("Class: E\n");
        printf("Network ID: Not applicable\n");
    } else {
        printf("Invalid IP address\n");
    }

    return 0;
}