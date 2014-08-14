#include<stdio.h>
void display( int [], int [], int, int[]);
int main()
{
	int i,j,numOfProcesses,time,totalWait=0,totalTat=0,smallest;
	int arrivalTime[10],burstTime[10],priority[10],remainingTime[10],remain;
	printf("Enter no of processes : ");
	scanf("%d",&numOfProcesses);
	remain=numOfProcesses;
	for(i=0;i<numOfProcesses;i++)
	{
		printf("Enter arrival time, burst time and priority for process p%d: ",i+1);
		scanf("%d %d %d",&arrivalTime[i],&burstTime[i],&priority[i]);
		remainingTime[i]=burstTime[i];
	}
	priority[9]=11;
	display(burstTime,arrivalTime,numOfProcesses,priority);
	printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
	for(time=0;remain!=0;time++)
	{
		smallest=9;
		for(i=0;i<numOfProcesses;i++)
		{
			if(arrivalTime[i]<=time && priority[i]<priority[smallest] && remainingTime[i]>0)
				smallest=i;
		}
		remainingTime[smallest]--;
		if(remainingTime[smallest]==0)
		{
		remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+1-arrivalTime[smallest],time+1-arrivalTime[smallest]-burstTime[smallest]);
			totalWait+=time+1-arrivalTime[smallest];
			totalTat+=time+1-arrivalTime[smallest]-burstTime[smallest];
		}
	}
	printf("\n\nTotal waiting time = %f",totalWait*1.0);
	printf("\nAverage waiting time = %f",totalWait*1.0/numOfProcesses);
	printf("\nTotal turnaround time = %f",totalTat*1.0);
	printf("\nAverage turnaround time = %f\n",totalTat*1.0/numOfProcesses);
	return 0;
}
void display(int burstTime[10],int arrivalTime[10], int numOfProcesses, int priority[10] )
{
	int i;
	printf("\nProcess\t|Burst Time\t|Arrival Time\t| Priority\n");
     for(i=0; i<numOfProcesses; i++)
	{
		printf("%d\t|\t%d\t|\t%d\t|\t%d\n",i+1,burstTime[i],arrivalTime[i],priority[i]);
	}
}
