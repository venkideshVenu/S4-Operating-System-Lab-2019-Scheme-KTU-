
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
            if ((T == 1 && pro[j].ATC >= pro[j + 1].ATC) || (T == 2 && pro[j].num > pro[j + 1].num)) {
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
    printf("\n\n %15s %15s %15s %15s %15s %15s", "Process", "Arrival", "Burst", "Completion", "TurnAround", "Waiting");
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


OUTPUT 1

            Enter the Number of Processes: 5
            Enter the Time Quantum: 15
            Enter Process 1 - Arrival Time and Burst Time : 0 75
            Enter Process 2 - Arrival Time and Burst Time : 10 40
            Enter Process 3 - Arrival Time and Burst Time : 10 25
            Enter Process 4 - Arrival Time and Burst Time : 55 30
            Enter Process 5 - Arrival Time and Burst Time : 95 45


              Gantt Chart
            ------------------------------------------------------------------------
            |   P1  |   P2  |   P3  |   P1  |   P2  |   P3  |   P4  |   P1  |   P2  |   P5  |   P4  |   P1  |   P5  |   P1  |   P5   |
            ------------------------------------------------------------------------
            0       15      30      45      60      75      85      100     115     125     140     155     170     185     200     215


                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            -------------------------------------------------------------------------------------------------
                          1               0              75             200             200             125
                          2              10              40             125             115              75
                          3              10              25              85              75              50
                          4              55              30             155             100              70
                          5              95              45             215             120              75

              Average Waiting Time       : 79.00 ms
              Average TurnAround Time    : 122.00 ms

                                    

OUTPUT 2

            Enter the Number of Processes: 5
            Enter the Time Quantum: 3
            Enter Process 1 - Arrival Time and Burst Time : 0 8
            Enter Process 2 - Arrival Time and Burst Time : 5 2
            Enter Process 3 - Arrival Time and Burst Time : 1 7
            Enter Process 4 - Arrival Time and Burst Time : 6 3
            Enter Process 5 - Arrival Time and Burst Time : 8 5


              Gantt Chart
            ------------------------------------------------------------------------
            |   P1  |   P3  |   P1  |   P2  |   P4  |   P3  |   P5  |   P1  |   P3  |   P5   |
            ------------------------------------------------------------------------
            0       3       6       9       11      14      17      20      22      23      25

                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            -------------------------------------------------------------------------------------------------
                          1               0               8              22              22              14
                          2               5               2              11               6               4
                          3               1               7              23              22              15
                          4               6               3              14               8               5
                          5               8               5              25              17              12

              Average Waiting Time       : 10.00 ms
              Average TurnAround Time    : 15.00 ms



OUTPUT 3


            Enter the Number of Processes: 5
            Enter the Time Quantum: 4
            Enter Process 1 - Arrival Time and Burst Time : 0 11
            Enter Process 2 - Arrival Time and Burst Time : 5 13
            Enter Process 3 - Arrival Time and Burst Time : 9 6
            Enter Process 4 - Arrival Time and Burst Time : 13 9
            Enter Process 5 - Arrival Time and Burst Time : 17 12


              Gantt Chart
            ------------------------------------------------------------------------
            |   P1  |   P1  |   P2  |   P1  |   P3  |   P2  |   P4  |   P5  |   P3  |   P2  |   P4  |   P5  |   P2  |   P4  |   P5   |
            ------------------------------------------------------------------------
            0       4       8       12      15      19      23      27      31      33      37      41      45      46      47      51


                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            -------------------------------------------------------------------------------------------------
                          1               0              11              15              15               4
                          2               5              13              46              41              28
                          3               9               6              33              24              18
                          4              13               9              47              34              25
                          5              17              12              51              34              22

              Average Waiting Time       : 19.40 ms
              Average TurnAround Time    : 29.60 ms


OUTPUT 4

            Enter the Number of Processes: 5
            Enter the Time Quantum: 4
            Enter Process 1 - Arrival Time and Burst Time : 0 10
            Enter Process 2 - Arrival Time and Burst Time : 2 6
            Enter Process 3 - Arrival Time and Burst Time : 3 4
            Enter Process 4 - Arrival Time and Burst Time : 6 2
            Enter Process 5 - Arrival Time and Burst Time : 10 8


              Gantt Chart
            ------------------------------------------------------------------------
            |   P1  |   P2  |   P3  |   P1  |   P4  |   P2  |   P5  |   P1  |   P5   |
            ------------------------------------------------------------------------
            0       4       8       12      16      18      20      24      26      30

                     Process         Arrival           Burst      Completion      TurnAround         Waiting
            -------------------------------------------------------------------------------------------------
                          1               0              10              26              26              16
                          2               2               6              20              18              12
                          3               3               4              12               9               5
                          4               6               2              18              12              10
                          5              10               8              30              20              12

              Average Waiting Time       : 11.00 ms
              Average TurnAround Time    : 17.00 ms
*/