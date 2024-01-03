#include<stdio.h>

typedef struct{
    int pid,at,bt,tat,wt,rm;
}process;

int main()
{
    int n,i,j,qt,tt=0;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    process p[n];
    int q[999];

    for(i=0;i<n;i++)
    {
        printf("Process ID and Burst Time : ");
        scanf("%d %d",&p[i].pid,&p[i].bt);
        p[i].at=0;
        p[i].tat=0;
        p[i].rm=p[i].bt;
        p[i].wt=0;
        q[i]=i;
    }
    printf("Enter the quantum : ");
    scanf("%d",&qt);

    int front=0,x,rear=n-1;
    while(front<=rear)
    {
        x=q[front];

        if(p[x].rm>qt)
        {
            tt+=qt;
            p[x].rm=p[x].rm-qt;
            front++;

            //INSERT LOGIC FOR
            //ROUND ROBIN WITH
            //ARRIVAL TIME


            rear++;
            q[rear]=x;

        }

        else if(p[x].rm<=qt)
        {
            tt+=p[x].rm;
            p[x].rm=0;
            front++;

            p[x].tat=tt-p[x].at;
            p[x].wt = (p[x].tat-p[x].bt);
        }

    }


    int swt=0,stat=0;
    for(int i=0;i<n;i++)
    {
        stat+=p[i].tat;
        swt+=p[i].wt;
    }


    printf(" Process  |   Burst Time   |   Turn-Around Time  | Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("   %d     |      %d        |        %d          |      %d      \n",p[i].pid,p[i].bt,p[i].tat,p[i].wt);
    }

    printf("Average Turn Around Time : %.2f \n",((float)stat/n));
    printf("Average Waiting Time : %.2f \n",((float)swt/n));




return 0;
}

