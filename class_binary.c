#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int n, char *binary) {
    for (int i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            strcat(binary, "1");
        else
            strcat(binary, "0");
    }
}

void findClass(char *binary) {
    if (binary[0] == '0')
        printf("Class A\n");
    else if (binary[0] == '1' && binary[1] == '0')
        printf("Class B\n");
    else if (binary[0] == '1' && binary[1] == '1' && binary[2] == '0')
        printf("Class C\n");
    else if (binary[0] == '1' && binary[1] == '1' && binary[2] == '1' && binary[3] == '0')
        printf("Class D\n");
    else
        printf("Class E\n");
}

int main() {
    char ip[20];
    printf("Enter the IP address in dotted decimal format: ");
    scanf("%s", ip);
    char *token = strtok(ip, ".");
    char binary[33] = "";
    char firstOctet[9];
    
    printf("The 32-bit binary IP address is: ");
    int count = 0;
    while (token != NULL) {
        convertToBinary(atoi(token), binary);
        if(count == 0) {
            strcpy(firstOctet, binary);
            count++;
        }
        printf("%s.", binary);
        strcpy(binary, "");
        token = strtok(NULL, ".");
    }
    printf("\n");
    findClass(firstOctet);
    return 0;
}
