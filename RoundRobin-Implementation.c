#include <stdio.h>
#define MAX 100

int main(){

    int timeQuantum,time=0,nprocess=0,i=0,j=1,k=0,flag=0;
    int burstTArray[MAX],arrivalTArray[MAX],remainingTArray[MAX],turnaArray[MAX],waitArray[MAX],indexArray[MAX];
    float waitT=0,turnaroundT=0;

    printf("Enter number of processes: ");
    scanf("%d",&nprocess);

    for(i=0;i<nprocess;i++){
        printf("Enter Arrival Time and Burst Time for Process %d : ",j);
        scanf("%d",&arrivalTArray[i]);
        scanf("%d",&burstTArray[i]);
        remainingTArray[i] = burstTArray[i];
        indexArray[i] = j;
        j++;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&timeQuantum);
    
    k = nprocess;
    printf("\n\t**Processes arranged according to Completion Time**\n");
    printf("\n\tProcesses\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time \n");
    for(time=0,i=0;k!=0;) {

    //if remaining burst time is less than time quantum or equal, flag is set to 1 to indicate end of process and remaining burst time is set to 0
    if(remainingTArray[i]<=timeQuantum && remainingTArray[i]>0) 
    { 
      time+=remainingTArray[i]; 
      remainingTArray[i]=0; 
      flag=1; 
    } 
    //if exists remaining burst time, subtract time quantum and add overall time
    else if(remainingTArray[i]>0) 
    { 
      remainingTArray[i]-=timeQuantum; 
      time+=timeQuantum; 
    } 
    //when remaining burst time is zero, subtract number of processes and display
    if(remainingTArray[i]==0 && flag==1) 
    { 
      k--; 
      printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",indexArray[i],arrivalTArray[i],burstTArray[i],time,time-arrivalTArray[i],time-arrivalTArray[i]-burstTArray[i]);
      waitT+=time-arrivalTArray[i]-burstTArray[i]; 
      turnaroundT+=time-arrivalTArray[i]; 
      flag=0; 
    } 
    //end loop when all processes have ended, and i is nprocess-1
    if(i==nprocess-1) 
      i=0; 
    //else continue and check if arrival time is less than actual time
    else if(arrivalTArray[i+1]<=time || arrivalTArray[i+1] >= time) 
      i++; 
    else 
      i=0; 
     }
  printf("\nAverage Waiting Time = %.2f\n",waitT*1.0/nprocess); 
  printf("Average Turnaround Time = %.2f\n",turnaroundT*1.0/nprocess); 
  

}