#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_network_range(char *ip_address, int subnet_mask) {
    unsigned int ip_segments[4];
    unsigned int subnet_segments[4];
    unsigned int first_ip[4], last_ip[4];
    int i;

    sscanf(ip_address, "%u.%u.%u.%u", &ip_segments[0], &ip_segments[1], &ip_segments[2], &ip_segments[3]);

    for (i = 0; i < 4; i++) {
        subnet_segments[i] = (subnet_mask > 8) ? 255 : (256 - (1 << (8 - subnet_mask)));
        subnet_mask -= (subnet_mask > 8) ? 8 : subnet_mask;
    }

    for (i = 0; i < 4; i++) {
        first_ip[i] = ip_segments[i] & subnet_segments[i];
        last_ip[i] = first_ip[i] | (~subnet_segments[i] & 255);
    }

    printf("First IP: %u.%u.%u.%u\n", first_ip[0], first_ip[1], first_ip[2], first_ip[3]);
    printf("Last IP: %u.%u.%u.%u\n", last_ip[0], last_ip[1], last_ip[2], last_ip[3]);

    printf("\nAll IP addresses in the network:\n");
    for (i = first_ip[3]; i <= last_ip[3]; i++) {
        printf("%u.%u.%u.%u\n", first_ip[0], first_ip[1], first_ip[2], i);
    }
}

int main() {
    char ip_address[16];
    int subnet_mask;

    printf("Enter IP address in CIDR notation");
    scanf("%15[^/]/%d", ip_address, &subnet_mask);

    calculate_network_range(ip_address, subnet_mask);

    return 0;
}