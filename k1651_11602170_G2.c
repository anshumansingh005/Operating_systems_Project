#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0,pr[10],pos,total;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("\nEnter the No. of processes :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\tEnter the burst time of process no. %d  :",i+1);
scanf(" %d",&bt[i]);
printf("\tEnter the arrival time of process no. %d :",i+1);
scanf(" %d",&at[i]);
}

/*Sorting According to Arrival Time*/

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}

/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/

for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
i=k;
while(i<n)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
i++;
}
k++;
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}

wavg=(wsum/n);
i= 0;
while(i<n)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
++i;
}

tavg=(tsum/n);

 for ( i = 0; i < n; ++i)
 {
 	pr[i]=1+(wt[i]/bt[i]);
  }

  i=0;
  while(i<n)
  {
    pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        ++i;
  }

   wt[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    wavg=total/n;      //average waiting time

printf("************************");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
    total=0;

for(i=0;i<n;i++)
{ tt[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tt[i];
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
}
tavg= total/n;

printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}
