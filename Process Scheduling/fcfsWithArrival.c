
//  Implement FCFS with arrival time and calculate its total turnaround time and waiting time

#include<stdio.h>

// Global variables declaration
int i, j, n, time = 0, totalWT = 0, totalTAT = 0, arr[10], ptr = 0;

// Structure for storing process details
struct process
{
    int num;    // Process number
    int AT;     // Arrival time
    int BT;     // Burst time
    int CT;     // Completion time
    int TAT;    // Turnaround time
    int WT;     // Waiting time
} pro[10], temp;

// Function to sort processes based on Arrival Time or Process Number
void sort(int T) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if ((T == 1 && pro[j].AT > pro[j + 1].AT) || (T == 2 && pro[j].num > pro[j + 1].num)) {
                     temp = pro[j];
                    pro[j] = pro[j+1];
                    pro[j+1] = temp;
            }
        }
    }
}

int main()
{
    // Input number of processes
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    
    // Reading process details
    for (i = 0; i < n; i++) {    
        printf("Enter Process %d - Arrival Time & Burst Time: ", (i+1));
        pro[i].num = (i+1);
        scanf("%d", &pro[i].AT);
        scanf("%d", &pro[i].BT);
    }
    
    // Sort processes based on Arrival Time
    sort(1);
    arr[0] = 0;

    // Display Gantt Chart
    printf("Gantt Chart:\n\n----------------------------------------------------------\n");
    for (i = 0; i < n; i++) 
    {
        // Idle condition if current time is less than arrival time of the next process
        if (time < pro[i].AT) {      
            printf("| Idle ");
            arr[ptr++] = pro[i].AT;
            time = pro[i].AT;
        }
        printf("|  P%d  ", pro[i].num);
        time += pro[i].BT;
        pro[i].CT = time;
        arr[ptr++] = time;
        
        // Calculations
        pro[i].WT = pro[i].CT - pro[i].AT - pro[i].BT;      
        pro[i].TAT = pro[i].WT + pro[i].BT;
        totalWT += pro[i].WT;
        totalTAT += pro[i].TAT;    
    }
    printf("|\n----------------------------------------------------------\n0");

    for (i = 0; i < ptr; i++)
        printf("%7d", arr[i]);
    
    // Sort processes based on Process Number
    sort(2);
    // Display process details
    printf("\n %15s %15s %15s %15s %15s %15s", "Process", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
    printf("\n--------------------------------------------------------------------------------------------");
    for (i = 0; i < n; i++)
       printf("\n           P%d %13d %15d %15d %15d %15d", pro[i].num, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);
    
    // Display average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT/n);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT/n);
}



/*
                               Output


    Enter the Number of Process : 5
    Enter Process 1 - Arrival Time & Burst Time : 2 2
    Enter Process 2 - Arrival Time & Burst Time : 0 1
    Enter Process 3 - Arrival Time & Burst Time : 2 3
    Enter Process 4 - Arrival Time & Burst Time : 3 5
    Enter Process 5 - Arrival Time & Burst Time : 4 4
    Gantt Chart:

    ----------------------------------------------------------
    |  P2  | Idle |  P1  |  P3  |  P4  |  P5  |
    ----------------------------------------------------------
    0      1      2      4      7     12     16
             Process         Arrival           Burst      Completion      TurnAround         Waiting
    --------------------------------------------------------------------------------------------
               P1             2               2               4               2               0
               P2             0               1               1               1               0
               P3             2               3               7               5               2
               P4             3               5              12               9               4
               P5             4               4              16              12               8

      Average Waiting Time       : 2.80 ms
      Average TurnAround Time    : 5.80 ms

  */