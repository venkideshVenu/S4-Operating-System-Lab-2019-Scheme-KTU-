
// Implement SJF scheduling Algorithm and calculate Avg. Waiting time and Turnaround Time

#include<stdio.h>

// Global variables declaration
int i, j, n, totalWT = 0, totalTAT = 0;

// Structure for storing process details
struct process
{
    int num;
    int BT, CT, TAT, WT;
} pro[10], temp;

// Function to sort processes based on Burst Time or Process Number
void sort(int T) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if ((T == 1 && pro[j].BT > pro[j + 1].BT) || (T == 2 && pro[j].num > pro[j + 1].num)) {
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

    // Reading burst time for each process
    for (i = 0; i < n; i++)
    {      
        printf("Enter Process %d - Burst Time: ", (i+1));
        pro[i].num = (i+1);
        scanf("%d", &pro[i].BT);
    }

    // Sort processes based on Burst Time
    sort(1);
    
    // Calculate completion time, turnaround time, and waiting time for each process
    pro[0].TAT = pro[0].CT = pro[0].BT;
    pro[0].WT = 0;
    totalTAT = pro[0].TAT;

    for (i = 1; i < n; i++)
    {
        pro[i].CT = pro[i-1].CT + pro[i].BT;
        pro[i].TAT = pro[i].CT;
        pro[i].WT = pro[i].TAT - pro[i].BT;
        totalWT += pro[i].WT;
        totalTAT += pro[i].TAT;
    }

    // Print Gantt Chart
    printf("\n\nGANTT CHART ");
    printf("\n----------------------------------\n");
    for(i = 0; i < n; i++)
        printf("|  P%d\t", pro[i].num);
    printf("|\n----------------------------------\n");
    printf("%d\t", 0);
    for(i = 0; i < n; i++)
        printf("%d\t", pro[i].CT);

    // Sort processes based on Process Number
    sort(2);

    // Print process details
    printf("\n %15s %15s %15s %15s %15s", "Process", "Burst", "Completion", "TurnAround", "Waiting");
    printf("\n--------------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++)
        printf("\n           P%d %13d %15d %15d %15d", pro[i].num, pro[i].BT, pro[i].CT, pro[i].TAT, pro[i].WT);

    // Print average waiting time and average turnaround time
    printf("\n\n  Average Waiting Time       : %.2f ms", (float)totalWT / n);
    printf("\n  Average TurnAround Time    : %.2f ms", (float)totalTAT / n);

    return 0;
}


/*

                Output


    Enter the Number of Process : 4
    Enter Process 1 - Burst Time : 6
    Enter Process 2 - Burst Time : 8
    Enter Process 3 - Burst Time : 7
    Enter Process 4 - Burst Time : 3


    GANTT CHART
    ----------------------------------
    |  P4   |  P1   |  P3   |  P2   |
    ----------------------------------
    0       3       9       16      24
             Process           Burst      Completion      TurnAround         Waiting
    --------------------------------------------------------------------------------------------
               P1             6               9               9               3
               P2             8              24              24              16
               P3             7              16              16               9
               P4             3               3               3               0

      Average Waiting Time       : 7.00 ms
      Average TurnAround Time    : 13.00 ms


*/