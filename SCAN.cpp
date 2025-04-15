#include <stdio.h>
#include <stdlib.h>
void SCAN(int requests[], int n, int head, int direction, int diskSize){
int totalMovement = 0, index, seekSequence[n + 2];
requests[n] = head;
requests[n + 1] = (direction == 1) ? diskSize - 1 : 0;
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
printf("\nSCAN Disk Scheduling:\nSeek Sequence: %d", head);
if (direction == 1) {
for (int i = index; i < n; i++) {
printf(" -> %d", requests[i]);
totalMovement += abs(requests[i] - head);
head = requests[i];
}
for (int i = index - 1; i >= 0; i--) {
printf(" -> %d", requests[i]);
totalMovement += abs(requests[i] - head);
head = requests[i];
}
}else{
for (int i = index; i >= 0; i--) {
printf(" -> %d", requests[i]);
totalMovement += abs(requests[i] - head);
head = requests[i];
}
for (int i = index + 1; i < n; i++) {
printf(" -> %d", requests[i]);
totalMovement += abs(requests[i] - head);
head = requests[i];
}
}
printf("\nTotal Head Movement: %d\n", totalMovement);
}
int main(){
int n, head, direction, diskSize;
printf("Enter the number of requests: ");
scanf("%d", &n);
int requests[n];
printf("Enter the request queue: ");
for (int i = 0; i < n; i++)
scanf("%d", &requests[i]);
printf("Enter the initial head position: ");
scanf("%d", &head);
printf("Enter the disk size: ");
scanf("%d", &diskSize);
printf("Enter direction (1 for right, 0 for left): ");
scanf("%d", &direction);
SCAN(requests, n, head, direction, diskSize);
return 0;
}
