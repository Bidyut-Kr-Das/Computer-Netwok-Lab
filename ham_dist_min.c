#include <stdio.h>
#include <string.h>

// Function to calculate Hamming distance
int hammingDist(char *str1, char *str2)
{
    int i = 0, count = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

int main()
{
    char X[100], Y[4][100];
    int i, j, d_min, temp;

    printf("Enter the binary string X: ");
    scanf("%s", X);

    printf("Enter the binary strings Y: \n");
    for(i = 0; i < 4; i++) {
        scanf("%s", Y[i]);
    }

    // Initialize d_min to the maximum possible value
    d_min = strlen(X);

    // Calculate the Hamming distance between X and each string in Y
    for(i = 0; i < 4; i++) {
        temp = hammingDist(X, Y[i]);
        if(temp < d_min) {
            d_min = temp;
        }
    }

    printf("The minimal Hamming distance is %d\n", d_min);

    printf("No of error can be detected  = %d\n", d_min-1);
    printf("No of error can be corrected = %d\n", (d_min-1)/2);

    return 0;
}