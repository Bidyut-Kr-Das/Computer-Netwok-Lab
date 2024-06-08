#include <stdio.h>

#define FRAME_SIZE 3

// Function to calculate checksum
int calculateChecksum(int frame[FRAME_SIZE]) {
    int i, sum = 0;
    for(i = 0; i < FRAME_SIZE; i++) {
        sum += frame[i];
    }
    return sum % 256;  // Assuming 8-bit data
}

int main() {
    int frame[FRAME_SIZE], i, checksum;

    printf("Enter the elements of the frame:\n");
    for(i = 0; i < FRAME_SIZE; i++) {
        scanf("%d", &frame[i]);
    }

    checksum = calculateChecksum(frame);

    printf("Checksum: %d\n", checksum);

    return 0;
}