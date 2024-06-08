#include <stdio.h>
#include <string.h>

void xorOperation(char *crc, char *divisor, int len) {
    for(int i = 0; i < len; i++) {
        if(crc[i] == divisor[i])
            crc[i] = '0';
        else
            crc[i] = '1';
    }
}

void crc(char *data, char *divisor, char *remainder) {
    int data_len = strlen(data);
    int divisor_len = strlen(divisor);

    // Append zero bits to the data
    for(int i = 0; i < divisor_len - 1; i++)
        data[data_len + i] = '0';

    // Perform modulo 2 division
    for(int i = 0; i <= data_len; i++) {
        if(data[i] == '1')
            xorOperation(&data[i], divisor, divisor_len);
    }

    // Copy the remainder
    strncpy(remainder, &data[data_len], divisor_len - 1);
    remainder[divisor_len - 1] = '\0';
}

int main() {
    char data[100], divisor[30], remainder[30];

    printf("Enter the data: ");
    scanf("%s", data);

    char copyData[100];
    strcpy(copyData, data);

    printf("Enter the divisor: ");
    scanf("%s", divisor);

    crc(data, divisor, remainder);

    printf("The remainder is: %s\n", remainder);

    printf("The codeword is: %s%s\n", copyData, remainder);
    
    strcat(copyData, remainder);

    char receivedData[100];
    printf("Enter the received data: ");
    scanf("%s", receivedData);

    if(strcmp(receivedData, copyData) == 0)
        printf("No error in the transmitted data.\n");
    else
        printf("Error in the transmitted data.\n");


    return 0;
}