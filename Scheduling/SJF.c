#include<stdio.h>
void display( int [], int [], int);
int main()
{
	int time,burstTime[10],arrivalTime[10],sumOfBurst=0,smallest,numOfProcesses,i;
	int totalTat=0,totalWait=0;
	printf("Enter no of processes: ");
	scanf("%d",&numOfProcesses);
	for(i=0;i<numOfProcesses;i++)
	{
		printf("Enter arrival time and burst time for Process P%d : ",i+1);
		scanf("%d %d",&arrivalTime[i],&burstTime[i]);
		sumOfBurst+=burstTime[i];
	}
	display(burstTime,arrivalTime,numOfProcesses);
	burstTime[9]=9999;
	printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
	for(time=0;time<sumOfBurst;)
	{
		smallest=9;
		for(i=0;i<numOfProcesses;i++)
		{
			if(arrivalTime[i]<=time && burstTime[i]>0 && burstTime[i]<burstTime[smallest])
				smallest=i;
		}
		printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+burstTime[smallest]-arrivalTime[smallest],time-arrivalTime[smallest]);
		totalTat+=time+burstTime[smallest]-arrivalTime[smallest];
		totalWait+=time-arrivalTime[smallest];
		time+=burstTime[smallest];
		burstTime[smallest]=0;
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