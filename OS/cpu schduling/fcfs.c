#include<stdio.h>

// Function to swap two integer values by reference
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    // Arrays for process ID, arrival time, burst time, completion time, turnaround time, and waiting time
    int p[n], at[n], bt[n], ct[n], tat[n], wt[n], avg_tat=0, avg_wt=0;
    int i, j, count=0, time=0;

    // Input process details
    for(i=0; i<n; i++)
    {
        printf("Enter the process number: ");
        scanf("%d",&p[i]);
        printf("Enter the arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter the burst time: ");
        scanf("%d",&bt[i]);
    }

    // Sort processes by arrival time using bubble sort
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(at[j] > at[j+1])
            {
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
    }

    i=0;
    // Calculate completion time, turnaround time, and waiting time
    while(count < n)
    {
        if(time < at[i])  // Adjust the time if no process has arrived yet
        {
            time += at[i];
            continue;
        }
        
        time += bt[i];            // Increment current time by burst time of the selected process
        ct[i] = time;              // Set completion time
        tat[i] = ct[i] - at[i];    // Calculate turnaround time (TAT = CT - AT)
        wt[i] = tat[i] - bt[i];    // Calculate waiting time (WT = TAT - BT)
        count++;
        i++;
    }

    // Display process details
    printf("PRO\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0; i<n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Display average turnaround time and average waiting time
    printf("Average TAT: %f\n", avg_tat / (float)n);
    printf("Average WT: %f\n", avg_wt / (float)n);
}
