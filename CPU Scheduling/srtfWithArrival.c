

// Implement SRTF scheduling Algorithm and calculate Avg. Waiting time and Turnaround Time


#include<stdio.h>

// Global variables declaration
int i, j, nop, totalWT = 0, totalTAT = 0, proarr[20], noarr[20], ptr = -1;
int currentTime = 0, completed = 0, shortest = 0, minRemTime = 9999;

// Structure for storing process details
struct process
{
    int num, TR; // TR represents Remaining Time
    int AT, BT, CT, TAT, WT;
} pro[10], temp;

int main()
{
    // Input number of processes
    printf("Enter the Number of Processes: ");
    scanf("%d", &nop);

    // Reading arrival time and burst time for each process
    for (i = 0; i < nop; i++)
    {      
        printf("Enter Process %d - Arrival Time & Burst Time: ", (i + 1));
        pro[i].num = (i + 1);
        scanf("%d", &pro[i].AT);
        scanf("%d", &pro[i].BT);
        pro[i].TR = pro[i].BT; // Initialize Remaining Time with Burst Time
    }
    
    // Process scheduling loop
    while (completed != nop) {
        for (int i = 0; i < nop; i++) 
        {
            // Find the process with the shortest remaining time and has arrived
            if ((pro[i].AT <= currentTime) && (pro[i].TR < minRemTime) && (pro[i].TR > 0)) {
                shortest = i;
                minRemTime = pro[i].TR;
            }
        }

        pro[shortest].TR--; // Decrement remaining time for the shortest process
        minRemTime = pro[shortest].TR; // Update minimum remaining time
        
        // Update Gantt chart arrays
        if (proarr[ptr] != shortest || ptr == -1 ){
            ptr++;
            proarr[ptr] = shortest;
            noarr[ptr] = currentTime;
        }
        else
            noarr[ptr]++;
        
        if (minRemTime == 0)
            minRemTime = 9999;

        // If process is completed, update its completion time and calculate TAT and WT
        if (pro[shortest].TR == 0) {
            completed++;
            pro[shortest].CT = currentTime + 1;
            pro[shortest].TAT = pro[shortest].CT - pro[shortest].AT;
            pro[shortest].WT = pro[shortest].TAT - pro[shortest].BT;
            totalWT += pro[shortest].WT;
            totalTAT += pro[shortest].TAT;
        }
        currentTime++;
    }

    // Print Gantt Chart
    printf("\n\nGANTT CHART \n---------------------------------------------------------------\n");
    for (i = 0; i <= ptr; i++)
        printf("|  P%d\t", proarr[i] + 1);
    printf("|\n---------------------------------------------------------------\n0\t");

    for (i = 0; i <= ptr; i++)
        printf("%d\t", noarr[i] + 1);

    // Print process details
    printf("\n %15s %15s %15s %15s %15s %15s","Process","Arrival","Burst","Completion","TurnAround","Waiting");
    printf("\n--------------------------------------------------------------------------------------------");
    for (int i = 0; i < nop; i++)
       printf("\n           P%d %13d %15d %15d %15d %15d", pro[i].num, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
    
    // Print average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT / nop);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT / nop);

    return 0;
}




/*

OUTPUT



            Enter the Number of Process : 5
            Enter Process 1 - Arrival Time & Burst Time : 2 1
            Enter Process 2 - Arrival Time & Burst Time : 1 5
            Enter Process 3 - Arrival Time & Burst Time : 4 1
            Enter Process 4 - Arrival Time & Burst Time : 0 6
            Enter Process 5 - Arrival Time & Burst Time : 2 3


            GANTT CHART
            ---------------------------------------------------------------
            |  P4   |  P1   |  P5   |  P3   |  P5   |  P4   |  P2   |
            ---------------------------------------------------------------
            0       2       3       4       5       7       11      16
                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            --------------------------------------------------------------------------------------------
                       P1             2               1               3               1               0
                       P2             1               5              16              15              10
                       P3             4               1               5               1               0
                       P4             0               6              11              11               5
                       P5             2               3               7               5               2

              Average Waiting Time       : 3.40 ms
              Average TurnAround Time    : 6.60 ms


*/