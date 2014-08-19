#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// necessary global variables for comparison
float totalWaitPQ, totalWaitSJF, averageWaitPQ, averageWaitSJF, totalTATPQ, totalTATSJF, averageTATPQ, averageTATSJF;

// the functions used
void PQ();
void SJF();
void displaySJF();
void displayPQ();

int main() {
	// call the functions
	PQ();
	SJF();
	
	// output certain statements depending on the results
	if(totalWaitPQ > totalWaitSJF)
		printf("The total wait time for the PQ was larger than the total wait time for the SJF, and thus the SJF is better.\n");
	else if(totalWaitPQ < totalWaitSJF)
		printf("The total wait time for the PQ was smaller than the total wait time for the SJF, and thus the PQ is better.\n");
		
	if(averageWaitPQ > averageWaitSJF)
		printf("The average wait time for the PQ was larger than the average wait time for the SJF, and thus the SJF is better.\n");
	else if(averageWaitPQ < averageWaitSJF)
		printf("The average wait time for the PQ was smaller than the average wait time for the SJF, and thus the PQ is better.\n");
		
	if(totalTATPQ > totalTATSJF)
		printf("The total turnaround time for the PQ was larger than the total turnaround time for the SJF, and thus the SJF is better.\n");
	else if(totalTATPQ < totalTATSJF)
		printf("The total turnaround time for the PQ was smaller than the total turnaround time for the SJF, and thus the PQ is better.\n");
	
	if(averageTATPQ > averageTATSJF)
		printf("The average turnaround time for the PQ was larger than the average turnaround time for the SJF, and thus the SJF is better.\n");
	else if(averageTATPQ < averageTATSJF)
		printf("The average turnaround time for the PQ was smaller than the average turnaround time for the SJF, and thus the PQ is better.\n");
	
	return 0;
}

// the PQ scheduling function; calculates and saves to the PQ global variables the times
void PQ() {
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
	displayPQ(burstTime,arrivalTime,numOfProcesses,priority);
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
	
	totalWaitPQ = totalWait*1.0;
	averageWaitPQ = totalWait*1.0/numOfProcesses;
	totalTATPQ = totalTat*1.0;
	averageTATPQ = totalTat*1.0/numOfProcesses;
	printf("\n\nTotal waiting time = %f",totalWaitPQ);
	printf("\nAverage waiting time = %f",averageWaitPQ);
	printf("\nTotal turnaround time = %f",totalTATPQ);
	printf("\nAverage turnaround time = %f\n",averageTATPQ);
}

// the SJF scheduling function; calculates and saves to the SJF global variables the times
void SJF() {
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
	displaySJF(burstTime,arrivalTime,numOfProcesses);
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
	
	totalWaitSJF = totalWait*1.0;
	averageWaitSJF = totalWait*1.0/numOfProcesses;
	totalTATSJF = totalTat*1.0;
	averageTATSJF = totalTat*1.0/numOfProcesses;
	printf("\n\nTotal waiting time = %f",totalWaitSJF);
	printf("\nAverage waiting time = %f",averageWaitSJF);
	printf("\nTotal turnaround time = %f",totalTATSJF);
	printf("\nAverage turnaround time = %f\n",averageTATSJF);
}

// display the results on their own
void displaySJF(int burstTime[10],int arrivalTime[10], int numOfProcesses )
{
	int i;
	printf("\nProcess\t|Burst Time\t| Arrival Time\n");
     for(i=0; i<numOfProcesses; i++)
	{
		printf("%d\t|\t%d\t|\t%d\n",i+1,burstTime[i],arrivalTime[i]);
	}
}

// display the results on their own
void displayPQ(int burstTime[10],int arrivalTime[10], int numOfProcesses, int priority[10] )
{
	int i;
	printf("\nProcess\t|Burst Time\t|Arrival Time\t| Priority\n");
     for(i=0; i<numOfProcesses; i++)
	{
		printf("%d\t|\t%d\t|\t%d\t|\t%d\n",i+1,burstTime[i],arrivalTime[i],priority[i]);
	}
}
