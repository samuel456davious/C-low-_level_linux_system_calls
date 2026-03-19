#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char mac[18];
    char command[100];

    printf("Enter the MAC address (XX:XX:XX:XX:XX:XX): ");
    scanf("%17s", mac); 

    printf("Attempting to change wlan0 to %s...\n", mac);

    // 1. Bring interface down
    system("sudo ip link set dev wlan0 down");

    

    // 3. Bring interface back up
    system("sudo ip link set dev wlan0 up");

    return 0;
}