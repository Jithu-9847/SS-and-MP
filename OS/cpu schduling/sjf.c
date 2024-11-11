#include<stdio.h>

// Function to swap two integers by reference
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

    // Arrays to store process details
    int p[n], at[n], bt[n], ct[n], tat[n], wt[n], avg_tat=0, avg_wt=0;
    int i, j, k, count=0, time=0;

    // Input process information
    for(i=0;i<n;i++)
    {
        printf("Enter the process number: ");
        scanf("%d",&p[i]);
        printf("Enter the arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter the burst time: ");
        scanf("%d",&bt[i]);
    }

    // Sort processes by arrival time using bubble sort
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }

    // Sort by burst time for processes with the same arrival time
    for(i=1;i<n;i++)
    {
        for(j=1;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }

    // Resolve ties where processes have the same burst and arrival times
    for(i=1;i<n;i++)
    {
        if(bt[i]==bt[i+1] && at[i]>at[i+1])
        {
            swap(&at[i],&at[i+1]);
            swap(&bt[i],&bt[i+1]);
            swap(&p[i],&p[i+1]);
        }
    }

    i=0;
    // Calculate completion, turnaround, and waiting times
    while(count<n)
    {
        if(time < at[i])
        {
            time += at[i];
            continue;
        }
        time += bt[i];
        ct[i] = time;                    // Completion time
        tat[i] = ct[i] - at[i];           // Turnaround time
        wt[i] = tat[i] - bt[i];           // Waiting time
        count++;
        i++;
    }

    // Display process details in a table format
    printf("PRO\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Display average turnaround time and waiting time
    printf("Average TAT: %f\n", avg_tat / (float)n);
    printf("Average WT: %f\n", avg_wt / (float)n);
}
