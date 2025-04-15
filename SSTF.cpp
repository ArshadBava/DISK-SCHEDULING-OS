#include <stdio.h>
#include <stdlib.h>

void SSTF(int requests[], int n, int head){
    int totalMovement = 0, completed[n];

    for (int i = 0; i < n; i++)
        completed[i] = 0;

    printf("\nSSTF Disk Scheduling:\nSeek Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        int minDist = 1e9, index = -1;

        for (int j = 0; j < n; j++) {
            if (!completed[j] && abs(requests[j] - head) < minDist) {
                minDist = abs(requests[j] - head);
                index = j;
            }
        }

        completed[index] = 1;
        totalMovement += minDist;
        head = requests[index];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement: %d\n", totalMovement);
}

int main(){
    int n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    SSTF(requests, n, head);

    return 0;
}

