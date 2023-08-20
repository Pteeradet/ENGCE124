/* 
Program create INSERT/DELETE function of Circular Queue and use its 
by...
1. Display queue value
2. Display queue status (N:NORMAL/ O:OVER FLOW/ U:UNDER FLOW)
3. Display Data waiting in queue
4. Display F and R
5. Display all data in queue
The program will exit when press "E" character.
=============================================================================*/


#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#define N 5 //Set Max Queue 
int Q[N]; //Prepare Queue 0..N-1
int x, Qnumber = 0, F = 0,R = 0; //Declare x and initial Qnumber/Front/Rear variable
char status = 'N'; //Initial Status = NORMAL
char ch; //KBD Read variable

void insertCQ(int y) //INSERT Function
{ 
 if((R==F-1) || (R==N-1 && F==1) ) //Check Queue FULL?
 { 
 printf("!!!OVER FLOW!!!...\n"); 
 status='O'; //set status = OVER FLOW
 } 
 else
 { 
 if(R==N-1) // Loop back of R to 1 if it maximum
 { 
 R=1; 
 } 
 else
 { 
 R++; // increase R if Normal
 if(F==0) //if F is zero set it to 1
 F=1; 
 } 
 Qnumber++; //Increase queue number
 printf("Youe are queue number : %d\n", Qnumber); 
 //Display queue number
 Q[R]=y; //Put data into Queue
 status = 'N'; //Set status to "NORMAL"
 } 
} 

int deleteCQ() //DELETE Function
{ 
 int y; 
 if (F == 0) 
 { 
 printf("\n!!!UNDER FLOW!!!...\n"); 
 status = 'U'; //set STATUS = "UNDER FLOW"
 } 
 else
 { 
 y=Q[F]; //Get data from Queue
 Q[F] = 0; //Set data 0
 if (F==R) //Set both to 0 if F and R are same value
 { 
 F=0; R=0; 
 } 
 else
 { 
 if(F==N-1) //Set F to 1 if F is maximum, otherwise increase F
 F=1; 
else
 F++; 
 } 
 status = 'N'; //Set status to "NORMAL"
 return(y); //Return data 
 } 
} 


int DataInQueue() // Calculate Data waiting in queue
{ 
 int y=0; 
 if (F!= 0 && R!=0) //if not equal then can calculate
 { 
 if (F<=R)
 y=R-F+1; //Normal F and R
 else
 y=(N-1)-F+1+R; //incase loop of R
 } 
 return(y); 
} 

void ShowAllQueue() //Display Function
{ 
 int i; //Counter variable
 printf("N : %d\n",N-1); 
 printf("Status = %c \n",status); //Display STATUS
 printf("Data waiting in queue = %d\n",DataInQueue()); 
//Display Data waitting in queue
 printf(" F = %d / R = %d\n",F,R); //Display F R 
 for ( i = 1; i < N; i++ ) 
 { 
 printf("%d:%d / ",i, Q[i]); //Display all of data in QUEUE
 } 
 printf("\n----------------------------------------------------------\n"); 
}
 
int main()
{ 
 printf("CICULAR QUEUE PROGRAM...\n"); 
 printf("=======================\n"); 
 ch=' '; 
 while (ch != 'E') 
 { 
 printf("\n[1=INSERT : 2=DELETE E:Exit] : "); //Show MENU
 ch = getch(); //Wait and read KBD with out ENTER Press
 switch(ch) //Check ch
 { 
 case '1' : printf("\nInsert Number : "); 
 scanf("%d", &x); //Read data from KBD
 insertCQ(x); //Call INSERTNQ Function
 ShowAllQueue(); //Display all data in Queue
 break; 
 case '2' : x=deleteCQ(); //Delete data
 printf("\nData from Queue = %d\n",x); //Display it
 ShowAllQueue(); //Display all data in Queue
 break; 
 } //End SWITCH CASE
 } //End WHILE Loop
 printf("\n"); //line feed
 return(0); 
}//End MAIN Fn.
