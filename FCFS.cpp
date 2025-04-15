#include <stdio.h>
#include <stdlib.h>

void FCFS(int requests[], int n, int head){
    int totalMovement = 0;
    printf("\nFCFS Disk Scheduling:\nSeek Sequence: %d", head);
    
    for (int i = 0; i < n; i++){
        totalMovement += abs(requests[i] - head);
        head = requests[i];
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

    FCFS(requests, n, head);

    return 0;
}

