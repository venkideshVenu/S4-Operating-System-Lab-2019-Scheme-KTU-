
// Implement Priority Scheduling algorithm with arival time and calculate avg, waiting time and avg, turnaround time. ( Non-Preemptive )

#include<stdio.h>

// Global variables declaration
int i, j, n, totalWT = 0, totalTAT = 0, currentTime = 0, completed = 0, noarr[15], ptr = -1;

// Structure for storing process details
struct process {
    int num, status;
    int Prio, AT, BT, CT, TAT, WT;
} pro[10], temp;

// Function to find the process with the highest priority
int findprocess() {
    int flag = 100, index = -1;
    for (j = 0; j < n; j++) {
        if ((pro[j].Prio < flag) && (pro[j].AT <= currentTime) && (pro[j].status == 0)) {
            flag = pro[j].Prio;
            index = j;
        }
    }
    return index;
}

int main() {
    // Input number of processes
    printf("Enter the Number of Process: ");
    scanf("%d", &n);

    // Reading process details
    for (i = 0; i < n; i++) {
        printf("Enter Process %d - Priority, Arrival Time and Burst Time : ", (i + 1));
        pro[i].num = (i + 1);
        scanf("%d %d %d", &pro[i].Prio, &pro[i].AT, &pro[i].BT);
        pro[i].status = 0;
    }
    
    // Sorting processes based on Arrival Time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pro[j].AT > pro[j + 1].AT) {
                temp = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = temp;
            }
        }
    }

    // Initialize the Gantt Chart with the first arrival time
    noarr[ptr++] = currentTime = pro[0].AT;
    printf("\n\n  Gantt Chart ");
    printf("\n------------------------------------------------------------------------\n");

    // Process scheduling loop
    while (completed < n) {
        int id = findprocess();
        printf("|   P%d\t", pro[id].num);
        
        if (id != -1) {
            // Update process completion time and calculate Turnaround and Waiting times
            pro[id].CT = currentTime + pro[id].BT;
            pro[id].TAT = pro[id].CT - pro[id].AT;
            pro[id].WT = pro[id].TAT - pro[id].BT;
            totalWT += pro[id].WT;
            totalTAT += pro[id].TAT;
            pro[id].status = 1;
            currentTime = pro[id].CT;
            completed++;
        }
        // Record the current time in the Gantt Chart
        noarr[ptr++] = currentTime;
    }
    printf(" |\n------------------------------------------------------------------------\n0\t");
    // Print the Gantt Chart
    for(i=0;i<ptr;i++)
        printf("%d\t",noarr[i]);

    // Print process details
    printf("\n %15s %15s %15s %15s %15s %15s %15s", "Process", "Priority", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
    printf("\n-------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("\n%15d %15d %15d %15d %15d %15d %15d", pro[i].num, pro[i].Prio, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
    }

    // Print average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT / n);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT / n);
    
    return 0;
}


/*

                Output


    Enter the Number of Process : 7
    Enter Process 1 - Priority, Arrival Time and Burst Time : 3 0 8
    Enter Process 2 - Priority, Arrival Time and Burst Time : 4 1 2
    Enter Process 3 - Priority, Arrival Time and Burst Time : 4 3 4
    Enter Process 4 - Priority, Arrival Time and Burst Time : 5 4 1
    Enter Process 5 - Priority, Arrival Time and Burst Time : 2 5 6
    Enter Process 6 - Priority, Arrival Time and Burst Time : 6 6 5
    Enter Process 7 - Priority, Arrival Time and Burst Time : 1 10 1


      Gantt Chart
    ------------------------------------------------------------------------
    |   P1  |   P5  |   P7  |   P2  |   P3  |   P4  |   P6   |
    ------------------------------------------------------------------------
    0       8       14      15      17      21      22      27
             Process        Priority         Arrival           Burst      Completion      TurnAround         Waiting
    -------------------------------------------------------------------------------------------------
                  1               3               0               8               8               8               0
                  2               4               1               2              17              16              14
                  3               4               3               4              21              18              14
                  4               5               4               1              22              18              17
                  5               2               5               6              14               9               3
                  6               6               6               5              27              21              16
                  7               1              10               1              15               5               4

      Average Waiting Time       : 9.71 ms
      Average TurnAround Time    : 13.57 ms


*/