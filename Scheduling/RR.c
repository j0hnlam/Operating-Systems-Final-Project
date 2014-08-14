#include<stdio.h>
void display( int [], int [], int);
int main()
{
	int i,j,numOfProcesses,time,remain,flag=0,timeQuantum;
	int totalWait=0,totalTat=0,arrivalTime[10],burstTime[10],remainingTime[10];
	printf("Enter no of processes: ");
	scanf("%d",&numOfProcesses);
	remain=numOfProcesses;
	for(i=0;i<numOfProcesses;i++)
	{
		printf("Enter arrival time and burst time for Process P%d: ",i+1);
		scanf("%d %d",&arrivalTime[i],&burstTime[i]);
		remainingTime[i]=burstTime[i];
	}
	printf("Enter time quantum: ");
	scanf("%d",&timeQuantum);
	display(burstTime,arrivalTime,numOfProcesses);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	for(time=0,i=0;remain!=0;)
	{
		
		if(remainingTime[i]<=timeQuantum && remainingTime[i]>0)
		{
			time+=remainingTime[i];
			remainingTime[i]=0;
			flag=1;
		}
		else if(remainingTime[i]>0)
		{
			remainingTime[i]-=timeQuantum;
			time+=timeQuantum;
		}
		if(remainingTime[i]==0 && flag==1)
		{
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrivalTime[i],time-arrivalTime[i]-burstTime[i]);
			totalWait+=time-arrivalTime[i]-burstTime[i];
			totalTat+=time-arrivalTime[i];
			flag=0;
		}
		if(i==numOfProcesses-1)
			i=0;
		else if(arrivalTime[i+1]<=time)
			i++;
		else
			i=0;
	}
	printf("\n\nTotal waiting time = %f",totalWait*1.0);
	printf("\nAverage waiting time = %f",totalWait*1.0/numOfProcesses);
	printf("\nTotal turnaround time = %f",totalTat*1.0);
	printf("\nAverage turnaround time = %f\n",totalTat*1.0/numOfProcesses);
	return 0;
}
void display(int burstTime[10],int arrivalTime[10], int numOfProcesses )
{
	int i;
	printf("\nProcess\t|Burst Time\t| Arrival Time\n");
     for(i=0; i<numOfProcesses; i++)
	{
		printf("%d\t|\t%d\t|\t%d\n",i+1,burstTime[i],arrivalTime[i]);
	}
}