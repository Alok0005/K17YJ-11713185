#include<stdio.h>
#include<stdlib.h>
void push(int x);
int pop();
void sort();
int Queue(int i);



struct process
{
char no;
long Arrt,Complt;
long Burt,Wait,Turnt,Respt;
int comp;
}p[100];
int n;
long q[100];  
int front=-1,rear=-1;

int main()
{
int i,j,t=0,subt=0,Tiquam;
char c;
float avgwt=0,avgtt=0;
printf("\n\nEnter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].no=c;
 printf("\n\nEnter Arrival Time:");
 scanf("%d",&p[i].Arrt);
 printf("\nEnter Burst Time:");
 scanf("%d",&p[i].Burt);
 p[i].Respt=p[i].Burt;
 p[i].comp=0;
 subt+=p[i].Burt;
 
}
printf("\nEnter TIME QUANTUM:");
scanf("%d",&Tiquam);

sort();
push(0);          
printf("\t\t\nProcess execution order: ");

for(t=p[0].Arrt;t<subt;) 
{   i=pop();

if(p[i].Respt<=Tiquam)
{                                                                       
                       
t+=p[i].Respt;
p[i].Respt=0;
p[i].comp=1;          
    printf(" %c ",p[i].no);
            p[i].Wait=t-p[i].Arrt-p[i].Burt;
            p[i].Turnt=t-p[i].Arrt;       
            for(j=0;j<n;j++)                                                        
            {
            if(p[j].Arrt<=t && p[j].comp!=1&& Queue(j)!=1)
            {
            push(j);
            
            }
           }
        }
    else               
    {
    t+=Tiquam;
    p[i].Respt-=Tiquam;
    printf(" %c ",p[i].no);
    for(j=0;j<n;j++)     
            {
            if(p[j].Arrt<=t && p[j].comp!=1&&i!=j&& Queue(j)!=1)
             {
            push(j);
            
            }
           }
           push(i);   
           
    }

    
    
}

printf("\n\nPROCESS\t    ARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\tCOMPLETION TIME");
for(i=0;i<n;i++)
{
  p[i].Turnt=p[i].Burt+p[i].Wait;
  p[i].Complt=p[i].Arrt+p[i].Burt+p[i].Wait;
 avgwt+=p[i].Wait;
 avgtt+=p[i].Turnt;
printf("\n%c\t\t%d      \t\t%d    \t\t%d  \t\t%d  \t\t%d",p[i].no,p[i].Arrt,p[i].Burt,p[i].Wait,p[i].Turnt,p[i].Complt);
}
printf("\nAverage waiting time:%.2f",avgwt/n);
printf("\nAverage Turnaround time:%.2f",avgtt/n);
return 0;
}


void push(int i) 
{
if(rear==100)
{
printf("overflow");
exit(1);
}
rear++;
q[rear]=i;
if(front==-1)
{
front=0;
}
}



int pop()   
{
if(front==-1)
{
printf("underflow");
exit(0);
}
int temp=q[front];
if(front==rear)
front=rear=-1;
else
{
front++;
}
return temp;
}


int Queue(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;
}


void sort()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].Arrt>p[j].Arrt)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}


