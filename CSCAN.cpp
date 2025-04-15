#include <stdio.h>
#include <stdlib.h>

void CSCAN(int requests[], int n, int head, int diskSize) {
    int totalMovement = 0, index;
    requests[n] = head;
    requests[n + 1] = diskSize - 1;
    n += 2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    for (index = 0; index < n; index++) {
        if (requests[index] == head)
            break;
    }

    printf("\nC-SCAN Disk Scheduling:\nSeek Sequence: %d", head);

    for (int i = index; i < n; i++) {
        printf(" -> %d", requests[i]);
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf(" -> 0");
    totalMovement += head;
    head = 0;

    for (int i = 0; i < index; i++) {
        printf(" -> %d", requests[i]);
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("\nTotal Head Movement: %d\n", totalMovement);
}

int main() {
    int n, head, diskSize;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n + 2];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk size: ");
    scanf("%d", &diskSize);
    CSCAN(requests, n, head, diskSize);
    return 0;
}

