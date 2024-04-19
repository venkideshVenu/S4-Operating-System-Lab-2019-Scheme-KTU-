// Implement FCFS without arrival time and calculate Avg. Waiting time and Turnaround Time


#include<stdio.h> 

// Global variables declaration
int i, n, totalWT = 0, totalTAT = 0; 

// Structure for storing process details
struct process 
{ 
    int num; // Process number
    int BT, CT, TAT, WT, RT; // Burst Time, Completion Time, Turnaround Time, Waiting Time, Remaining Time
} pro[10]; 

int main() 
{ 
    // Input number of processes
    printf("Enter the Number of Processes : "); 
    scanf("%d", &n); 
    
    // Reading burst time for each process
    for (i = 0; i < n; i++) 
    { 
        printf("Enter Burst Time for Process %d : ", (i + 1)); 
        pro[i].num = (i + 1); 
        scanf("%d", &pro[i].BT); 
    } 
    
    // Calculating completion time, turnaround time, and waiting time for each process
    pro[0].TAT = pro[0].CT = pro[0].BT; 
    pro[0].WT = 0; 
    totalTAT = pro[0].TAT; 
    for (i = 1; i < n; i++) 
    { 
        pro[i].CT = pro[i - 1].CT + pro[i].BT; 
        pro[i].TAT = pro[i].CT; 
        pro[i].WT = pro[i - 1].CT; 
        totalWT += pro[i].WT; 
        totalTAT += pro[i].TAT; 
    } 
    
    // Printing process details
    printf("\n %15s %15s %15s %15s %15s","Process","Burst","Completion","TurnAround","Waiting"); 
    printf("\n ------------------------------------------------------------------"); 
    for (i = 0; i < n; i++)
        printf("\n P%d %15d %15d %15d  %15d", pro[i].num, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT); 

    printf("\n -----------------------------------------------------------------"); 
    
    // Printing Gantt Chart
    printf("\n\n Gantt Chart "); 
    printf("\n---------------------------\n"); 
    for(i = 0; i < n; i++)
    { 
        printf("|"); 
        printf(" P%d\t", pro[i].num); 
    } 
    printf("|\n---------------------------\n0\t"); 
    for(i = 0; i < n; i++) 
        printf("%d\t", pro[i].CT); 

    // Printing average waiting time and average turnaround time
    printf("\n\n Average Waiting Time : %.2f ms", (float)totalWT / n); 
    printf("\n Average TurnAround Time : %.2f ms", (float)totalTAT / n); 

    return 0; 
} 




/*
            Output
            
    Enter the Number of Process : 3
    Enter Process 1 Burst Time :24
    Enter Process 2 Burst Time :3
    Enter Process 3 Burst Time :3

            Process           Burst      Completion      TurnAround         Waiting
    ------------------------------------------------------------------
    P1              24              24              24                0
    P2               3              27              27               24
    P3               3              30              30               27
    -----------------------------------------------------------------

    Gantt Chart
    ---------------------------
    | P1    | P2    | P3    |
    ---------------------------
    0       24      27      30

    Average Waiting Time : 17.00 ms
    Average TurnAround Time : 27.00 ms
 
 */