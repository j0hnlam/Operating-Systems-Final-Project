#include<stdio.h>
void display();
void getdata();
void waitTime();
void turnAroundTime();
int numOfProcesses, arrivalTime[10],burstTime[10];
int main()
{
    getdata();
    display();
    waitTime();
    turnAroundTime();
    getchar();
}

void getdata()
{   
	int i;
    char c;
    printf("Enter the no of process: ");
    scanf("%d",&numOfProcesses);
    printf("\nDo you need to enter the arrival time of process [y/n] or [Y/N]\n");
    scanf("%s",&c);
    for(i=0; i<numOfProcesses; i++)
    {
          printf("Enter the %d process burst time : ",i+1);
          scanf("%d",&burstTime[i]);
          if(c=='y' || c=='Y')
          {
                  printf("Enter the %d process arrival time : ",i+1);
                  scanf("%d",&arrivalTime[i]);
          }
          else
          {
                  arrivalTime[i]=0;
          }
    }
}

void display()
{
	int i;
	printf("\nProcess\t|Burst Time\t| Arrival Time\n");
     for(i=0; i<numOfProcesses; i++)
	{
		printf("%d\t|\t%d\t|\t%d\n",i+1,burstTime[i],arrivalTime[i]);
	}
}

void waitTime()
{
     int w[10], i;
     float totalWait=0;
     w[0]=0;
     for(i=1; i<numOfProcesses; i++)
     {
           w[i]=burstTime[i-1]-arrivalTime[i]+w[i-1];
           totalWait=w[i]+totalWait;
     }
     printf("\nTotal Waiting time = %f",totalWait);
     printf("\nAverage Waiting time = %f",totalWait/numOfProcesses); 
}

void turnAroundTime()
{
     int tat[10], i;
     float totalTat=0;
     tat[-1]=0;
     for(i=0; i<numOfProcesses; i++)
     {
             tat[i]=burstTime[i]-arrivalTime[i]+tat[i-1];               
             totalTat=totalTat+tat[i];
     }
     printf("\n\nTotal Turn Around Time(TAT) = %f",totalTat);
     printf("\nAverage Turn Around = %f\n",totalTat/numOfProcesses);
}
