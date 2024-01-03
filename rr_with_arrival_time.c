
#include<stdio.h>

typedef struct{
    int pid,at,bt,tat,wt,rm;
}process;

typedef struct{
    int pin,at;
}buffer;





int main()
{
    int n;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    int i,j,qt,tt=0;
    int front=0,x,rear=0;
    int bfront=0,brear=n-1;
    int swt=0,stat=0;
    process p[n];
    buffer b[n];
    int q[999];

    for(i=0;i<n;i++)
    {
        printf("Process ID , Burst Time , Arrival Time : ");
        scanf("%d %d %d",&p[i].pid,&p[i].bt,&p[i].at);
        p[i].tat=0;
        p[i].rm=p[i].bt;
        p[i].wt=0;
        b[i].pin=i;
        b[i].at=p[i].at;
    }
    printf("Enter the quantum : ");
    scanf("%d",&qt);

    buffer temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(b[j].at > b[j+1].at)
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }


    while(b[bfront].at<=0)                          // Processes which have arrived at time t=0;   <= or ==
    {
        q[rear]=b[bfront].pin;
        rear++;
        bfront++;
    }

    while(front<=rear)
    {
        x=q[front];


        if(p[x].rm>qt)
        {
            printf("\nP NO : %d\n",p[x].pid);
            tt+=qt;
            p[x].rm=p[x].rm-qt;
            front++;

            if(bfront<=brear)
            {
                while(b[bfront].at <=tt && bfront<=brear)
                {
                    q[rear]=b[bfront].pin;
                    rear++;
                    bfront++;
                }
            }

            q[rear]=x;
            rear++;

        }

        else if(p[x].rm<=qt)
        {
            tt+=p[x].rm;
            p[x].rm=0;
            p[x].tat=tt-p[x].at;
            p[x].wt = (p[x].tat-p[x].bt);
            front++;
        }

    }


    for(int i=0;i<n;i++)
    {
        stat+=p[i].tat;
        swt+=p[i].wt;
    }


        printf(" Process  |   Burst Time   |   Arrival Time     |       Waiting Time    |    Turn-Around Time   \n");
    for(int i=0;i<n;i++)
    {
        printf("   %d     |      %d        |        %d          |           %d          |           %d           \n",p[i].pid,p[i].bt,p[i].at,p[i].wt,p[i].tat);
    }

    printf("Average Turn Around Time : %.2f \n",((float)stat/n));
    printf("Average Waiting Time : %.2f \n",((float)swt/n));




return 0;
}

