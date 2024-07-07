#include<stdio.h>

// Structure to represent a process
struct process {
    int ID, AT, BT, WT, TAT, CT, PR, RBT, T;
} pro[20], temp, a[20];

int main() {
    int n, time = 0;
    float totalWT = 0, totalTAT = 0;
    
    // Get the number of processes
    printf("Enter the Number of Process: ");
    scanf("%d", &n);
    
    // Input Priority, Arrival Time and Burst Time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d - Priority, Arrival Time and Burst Time: ", (i + 1));
        scanf("%d%d%d", &pro[i].PR, &pro[i].AT, &pro[i].BT);
        pro[i].ID = i + 1;
        pro[i].RBT = pro[i].BT;  // Remaining Burst Time initially equals to Burst Time
    }
    
    // Sort processes by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pro[j].AT > pro[j + 1].AT) {
                temp = pro[j + 1];
                pro[j + 1] = pro[j];
                pro[j] = temp;
            }
        }
    }
    
    int j = 0, end, completed = 0, status = -1;
    
    // Print Gantt Chart header
    printf("\n\n     Gantt Chart    \n");
    printf("------------------------------------------------------------------------\n |");
    
    do {
        int minindex = -1;
        int minpr = 999;
        
        // Find the process with the highest priority (lowest priority value) that is ready to execute
        for (int i = 0; i < n; i++) {
            if (pro[i].AT <= time && pro[i].PR < minpr && pro[i].RBT > 0) {
                minindex = i;
                minpr = pro[i].PR;
            }
        }
        
        // If no process is ready, the CPU is idle
        if (minindex == -1) {
            printf("IDLE|");
            pro[j].T = time;
            time++;
            j++;
            continue;
        }
        
        // Print process ID in Gantt Chart if it's different from the last executed process
        if (status != pro[minindex].ID) {
            printf("  P%d  |", pro[minindex].ID);
            pro[j].T = time;
            status = pro[minindex].ID;
        }
        
        // Execute the process
        pro[minindex].RBT--;
        time++;
        
        // If process is completed, calculate its metrics
        if (pro[minindex].RBT == 0) {
            completed++;
            pro[minindex].CT = time;  // Completion Time
            end = time;
            pro[minindex].TAT = pro[minindex].CT - pro[minindex].AT;  // Turnaround Time
            pro[minindex].WT = pro[minindex].TAT - pro[minindex].BT;  // Waiting Time
            totalTAT += pro[minindex].TAT;
            totalWT += pro[minindex].WT;
            j++;
        }
        
    } while (completed < n);
    
    // Print Gantt Chart footer
    printf("\n------------------------------------------------------------------------\n");
    printf(" 0\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", pro[i].T);
    printf("%d\t\n", end);

    // Print process details
    printf("\n %15s %15s %15s %15s %15s %15s %15s", "Process", "Priority", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
    printf("\n--------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("\n%15d %15d %15d %15d %15d %15d %15d", pro[i].ID, pro[i].PR, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
    }

    // Print average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT / n);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT / n);

    return 0;
}




/*                       OUTPUT

            Enter the Number of Process: 7
            Enter Process 1 - Priority, Arrival Time and Burst Time: 3 0 8
            Enter Process 2 - Priority, Arrival Time and Burst Time: 4 1 2
            Enter Process 3 - Priority, Arrival Time and Burst Time: 4 3 4
            Enter Process 4 - Priority, Arrival Time and Burst Time: 5 4 1
            Enter Process 5 - Priority, Arrival Time and Burst Time: 2 5 6
            Enter Process 6 - Priority, Arrival Time and Burst Time: 6 6 5
            Enter Process 7 - Priority, Arrival Time and Burst Time: 1 10 1


                 Gantt Chart
            ------------------------------------------------------------------------
             |  P1  |  P5  |  P7  |  P5  |  P1  |  P2  |  P3  |  P4  |  P6  |
            ------------------------------------------------------------------------
             0      10      11      12      15      17      21      22      27

                     Process        Priority         Arrival           Burst      Completion      TurnAround         Waiting
            --------------------------------------------------------------------------------------------------------
                          1               3               0               8              15              15               7
                          2               4               1               2              17              16              14
                          3               4               3               4              21              18              14
                          4               5               4               1              22              18              17
                          5               2               5               6              12               7               1
                          6               6               6               5              27              21              16
                          7               1              10               1              11               1               0

              Average Waiting Time       : 9.86 ms
              Average TurnAround Time    : 13.71 ms



*/