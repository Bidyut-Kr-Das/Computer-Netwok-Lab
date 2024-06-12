#include <stdio.h>
#include <stdint.h>

// Function to calculate checksum in decimal
uint8_t calculateChecksum(uint8_t *data, size_t length) {
    uint8_t checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
        // Data folding: If overflow occurs, wrap around and add 1
        if (checksum < data[i]) {
            checksum++;
        }
    }
    // Complement the checksum to get the final checksum in decimal
    return ~checksum;
}

// Function to verify checksum in decimal
int verifyChecksum(uint8_t *data, size_t length, uint8_t receivedChecksum) {
    uint8_t checksum = calculateChecksum(data, length);
    // Check if the calculated checksum matches the received checksum
    return checksum == receivedChecksum;
}

// Function to print binary representation of a decimal number
void printBinary(uint8_t number) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
}

int main() {
    uint8_t data[3];
    uint8_t receivedChecksum;
    int temp;

    // Input data in decimal
    printf("Enter 3 decimal values for the data frame: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &temp);
        data[i] = (uint8_t)temp;
    }

    // Input checksum in decimal
    printf("Enter the checksum value in decimal: ");
    scanf("%d", &temp);
    receivedChecksum = (uint8_t)temp;

    // Calculate checksum for the input data
    uint8_t checksum = calculateChecksum(data, 3);
    printf("Calculated Checksum (Decimal): %u\n", checksum);
    printf("Calculated Checksum (Binary): ");
    printBinary(checksum);
    printf("\n");

    // Verify checksum
    if (verifyChecksum(data, 3, receivedChecksum)) {
        printf("Data is correct.\n");
    } else {
        printf("Error detected in data.\n");
    }

    return 0;
}
