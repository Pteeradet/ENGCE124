/* 
Program calculate Postfix by assigned in variable.
=======================================================================
=========
*/
#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#include <string.h> //use string function
#include <math.h> //use power
#define MaxStack 40 //Set Max Operator Stack 
char postfix1[80] ={"AB+C-d/"}; //Assign INFIX
float ValPostfix[80]; //Keep value of Postfix here
float ValOperandST[MaxStack]; //Operator stack size
int SP = 0; //Initial SP=0
void push(float ValOperand) //PUSH Function
{ 
 if(SP == MaxStack) //Check Stack FULL?
 { 
 printf("ERROR STACK OVER FLOW!!!...\n"); 
 } 
 else
 { 
 SP=SP+1; //Increase SP
 ValOperandST[SP]=ValOperand; //Put data into Stack 
 } 
} 
float pop() //POP Function
{ 
 float ValOperand; 
 if (SP != 0) //Check Stack NOT EMPTY?
 { 
 ValOperand=ValOperandST[SP]; //Get data from Stack
 SP--; //Decrease SP 
 return(ValOperand); //Return data
 } 
 else
 printf("\nERROR STACK UNDER FLOW!!!...\n"); 
} 
void CalPostfix(char postfix[80])
{ 
 float pop1,pop2,value; 
 int i,len; 
 char ch; 
 len = strlen(postfix); 
 printf("Postfix = %s\n",postfix); 
 for (i=0;i<=len-1;i++) //Assign data to OPERAND
 { 
 ch=postfix[i]; //Split Character for assign data
 if (strchr("+-* /^", ch)==0) //Check Is OPERAND?
 { 
 printf("\nAssign Number to %c : ",ch); 
 scanf("%f",&ValPostfix[i]); //Read data from KBD and direct to Value of OPERAND in Array
 } 
 } 
 for (i=0;i<=len-1;i++) //Calculate Value of POSTFIX
 { 
 ch=postfix[i]; //Split Character for prepare to STACK
if (strchr("+-* /^", ch)==0) //Check Is OPERAND?
 { 
 push(ValPostfix[i]); //push value of OPERAND to Stack
 } 
 else
 { 
 pop1=pop(); //Pop 1st
 pop2=pop(); //pop 2nd
 switch (ch)
 { 
 case '+' : value=pop2+pop1; //Calculate
 push(value); //Push value to Stack
 break; 
 case '-' : value=pop2-pop1; 
 push(value); 
 break; 
 case '*' : value=pop2*pop1; 
 push(value); 
 break; 
 case '/' : value=pop2/pop1; 
 push(value); 
 break; 
 case '^' : value=pow(pop2,pop1); 
 push(value); 
 break; 
 } 
 } //End IF 
 } //End IF
 printf("\nANS = %f",pop()); //Last value is ANSWER
} //End Fn.
int main()
{ 
 printf("POSTFIX CALCULATION PROGRAM\n"); 
 printf("=============================\n"); 
 CalPostfix(postfix1); 
 getch(); 
 return(0); 
 
 } //End Main 

