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
    char str1[100], str2[100];

    printf("Enter the first binary string: ");
    scanf("%s", str1);

    printf("Enter the second binary string: ");
    scanf("%s", str2);

    // Check if lengths are equal
    if(strlen(str1) == strlen(str2)) {
        printf("Hamming Distance between %s and %s is %d\n", str1, str2, hammingDist(str1, str2));
    } else {
        printf("Strings are not of equal length. Hamming distance cannot be calculated.\n");
    }

    return 0;
}