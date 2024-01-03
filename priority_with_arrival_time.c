#include<stdio.h>

typedef struct{
    int pid,at,bt,tat,wt,rm,priority;
}process;

typedef struct{
    int pin,at,priority;
}buffer;





int main()
{
    int n,i,j,qt,tt=0,c=0;                                                      // tt holds the value of time at an instant
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    process p[n];
    buffer b[n];
    int q[999];

    for(i=0;i<n;i++)
    {
        printf("Process ID , Burst Time , Arrival Time , Priority: ");        // Considering low value has high priority
        scanf("%d %d %d %d",&p[i].pid,&p[i].bt,&p[i].at,&p[i].priority);
        p[i].tat=0;
        p[i].rm=p[i].bt;
        p[i].wt=0;
        b[i].pin=i;
        b[i].at=p[i].at;
        b[i].priority=p[i].priority;
        c+=p[i].bt;
    }

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


    int front=0,x,rear=0;
    int bfront=0,brear=n-1;


    while(b[bfront].at<=0)                          // Processes which have arrived at time t=0;   <= or ==
    {
        q[rear]=b[bfront].pin;
        rear++;
        bfront++;
    }


    while(c!=n)
    {
        int max=999,maxi;
        c=0;

        tt++;

        for(i=0;i<rear;i++)                     //minimum rm index
        {
            if(p[q[i]].rm>0)
            {
                if(max > p[q[i]].priority)
                {
                    max  = p[q[i]].priority;
                    maxi = q[i];
                }
            }
        }


        if(p[maxi].rm>0)
        {
            p[maxi].rm--;

        }


        if(bfront<=brear)                                        // buffer check
        {
            while(b[bfront].at <= tt && bfront<=brear)
            {
                q[rear]=b[bfront].pin;
                rear++;
                bfront++;
            }

        }



        for(i=0;i<rear;i++)
        {
            if(p[q[i]].rm==0)
            {
                p[q[i]].tat = tt - p[q[i]].at;
                p[q[i]].wt = (p[q[i]].tat - p[q[i]].bt);
                p[q[i]].rm = -1;

            }

            else if(p[q[i]].rm == -1)c++;


        }


    }







    int swt=0,stat=0;
    for(int i=0;i<n;i++)
    {
        stat+=p[i].tat;
        swt+=p[i].wt;
    }


        printf(" Process  |   Burst Time   |   Arrival Time     |        Priority       |       Waiting Time    |    Turn-Around Time    |   \n");
    for(int i=0;i<n;i++)
    {
        printf("   %d     |      %d        |        %d          |           %d          |           %d          |           %d            | \n",p[i].pid,p[i].bt,p[i].at,p[i].priority,p[i].wt,p[i].tat,p[i]);
    }

    printf("Average Turn Around Time : %.2f \n",((float)stat/n));
    printf("Average Waiting Time : %.2f \n",((float)swt/n));




return 0;
}

