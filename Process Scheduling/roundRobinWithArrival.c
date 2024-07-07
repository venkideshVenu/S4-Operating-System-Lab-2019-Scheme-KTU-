
// Implement Round Robin Algorithm with Arrival Time and Calculate Avg. Waiting time and Turnaround Time

#include<stdio.h>

// Global variables declaration
int i, j, n, totalWT = 0, totalTAT = 0, currentTime = 0, completed = 0, noarr[15], ptr = -1, timeQtm;

// Structure for storing process details
struct process {
    int num, status;
    int ATC, BTC, AT, BT, CT, TAT, WT;
} pro[10], temp;

// Function to sort processes based on ATC (Arrival Time of Process to CPU)
void sort(int T) 
{
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if ((T == 1 && pro[j].ATC > pro[j + 1].ATC) || (T == 2 && pro[j].num > pro[j + 1].num)) {
                temp = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = temp;
            }
        }
    }
}

int main() {
    // Input number of processes and time quantum
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    printf("Enter the Time Quantum: ");
    scanf("%d", &timeQtm);

    // Reading process details
    for (i = 0; i < n; i++) {
        printf("Enter Process %d - Arrival Time and Burst Time : ", (i + 1));
        pro[i].num = (i + 1);
        scanf("%d %d", &pro[i].AT, &pro[i].BT);
        pro[i].status = 0;
        pro[i].ATC = pro[i].AT; // Initialize Arrival Time of Process to CPU
        pro[i].BTC = pro[i].BT; // Initialize Burst Time of Process
    }

    // Sort processes based on Arrival Time
    sort(1);
    
    // Print Gantt Chart header
    printf("\n\n  Gantt Chart ");
    printf("\n------------------------------------------------------------------------\n");

    // Process scheduling loop
    while(completed != n)
    {
        for(i = 0; i < n; i++)
        {
            if ((pro[i].ATC <= currentTime) && (pro[i].status == 0))
            {
                printf("|   P%d\t", pro[i].num);
                noarr[ptr++] = currentTime;
                if (pro[i].BTC <= timeQtm)
                {
                    currentTime += pro[i].BTC;
                    pro[i].status = 1;
                    completed++;
                    pro[i].TAT = currentTime - pro[i].AT;
                    pro[i].WT = pro[i].TAT - pro[i].BT;
                    pro[i].CT = currentTime;
                    totalWT += pro[i].WT;
                    totalTAT += pro[i].TAT;
                }
                else
                {
                    currentTime += timeQtm;
                    pro[i].BTC -= timeQtm;
                }
                pro[i].ATC = currentTime;
                break;
            }
        }
        sort(1); // Sort again based on Arrival Time of Process to CPU
    }
    noarr[ptr++] = currentTime;

    // Sort processes based on Process Number
    sort(2);

    // Print Gantt Chart
    printf(" |\n------------------------------------------------------------------------\n0\t");
    for(i = 0; i < ptr; i++)
        printf("%d\t", noarr[i]);

    // Print process details
    printf("\n %15s %15s %15s %15s %15s %15s", "Process", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
    printf("\n-------------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("\n%15d %15d %15d %15d %15d %15d", pro[i].num, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
    }

    // Print average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT / n);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT / n);
    
    return 0;
}





/*

                Output


            Enter the Number of Processes: 6
            Enter the Time Quantum: 5
            Enter Process 1 - Arrival Time and Burst Time : 0 7
            Enter Process 2 - Arrival Time and Burst Time : 1 4
            Enter Process 3 - Arrival Time and Burst Time : 2 15
            Enter Process 4 - Arrival Time and Burst Time : 3 11
            Enter Process 5 - Arrival Time and Burst Time : 4 20
            Enter Process 6 - Arrival Time and Burst Time : 4 9


              Gantt Chart
            ------------------------------------------------------------------------
            |   P1  |   P2  |   P3  |   P4  |   P5  |   P6  |   P1  |   P3  |   P4  |   P5  |   P6  |   P3  |   P4  |   P5  |   P5   |
            ------------------------------------------------------------------------
            0       5       9       14      19      24      29      31      36      41      46      50      55      56      61      66
                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            -------------------------------------------------------------------------------------------------
                          1               0               7              31              31              24
                          2               1               4               9               8               4
                          3               2              15              55              53              38
                          4               3              11              56              53              42
                          5               4              20              66              62              42
                          6               4               9              50              46              37

              Average Waiting Time       : 31.17 ms
              Average TurnAround Time    : 42.17 ms

*/