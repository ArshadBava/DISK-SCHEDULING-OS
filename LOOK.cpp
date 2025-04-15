#include <stdio.h>
#include <stdlib.h>

void LOOK(int requests[], int n, int head, int direction) {
    int totalMovement = 0, index;
    // Sort the request array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    
    // Find the index of the first request greater than or equal to the head position
    for (index = 0; index < n; index++) {
        if (requests[index] >= head) {
            break;
        }
    }
    
    printf("\nLOOK Disk Scheduling:\nSeek Sequence: %d", head);
    
    // If the direction is towards right (up)
    if (direction == 1) {
        // Move right (service requests greater than the head)
        for (int i = index; i < n; i++) {
            printf(" -> %d", requests[i]);
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
        // Then move left (service requests less than the head)
        for (int i = index - 1; i >= 0; i--) {
            printf(" -> %d", requests[i]);
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
    } 
    // If the direction is towards left (down)
    else {
        // Move left (service requests less than the head)
        for (int i = index - 1; i >= 0; i--) {
            printf(" -> %d", requests[i]);
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
        // Then move right (service requests greater than the head)
        for (int i = index; i < n; i++) {
            printf(" -> %d", requests[i]);
            totalMovement += abs(requests[i] - head);
            head = requests[i];
        }
    }
    
    printf("\nTotal Head Movement: %d\n", totalMovement);
}

int main() {
    int n, head, direction;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);
    
    LOOK(requests, n, head, direction);
    
    return 0;
}

