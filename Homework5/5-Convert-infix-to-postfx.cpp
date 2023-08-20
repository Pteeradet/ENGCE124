/* Program convert infix to postfix by assigned in variable.
====================================================================
============*/



#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#include <string.h> //use string function
#define MaxStack 40 //Set Max Operator Stack 

char infix1[80] ={"A+B*(C^D*E/F)-G"}; //Assign INFIX
char OpSt[MaxStack]; //Operator stack size
int SP = 0; //Initial SP=0
void push(char oper) //PUSH Function
{ 
 if(SP == MaxStack) //Check Stack FULL?
 { 
 printf("ERROR STACK OVER FLOW!!!...\n"); 
 } 
 else
 { 
 SP=SP+1; //Increase SP
 OpSt[SP]=oper; //Put data into Stack
 } 
}
int pop() //POP Function
{ 
 char oper; 
 if (SP != 0) //Check Stack NOT EMPTY?
 { 
 oper=OpSt[SP]; //Get data from Stack
 SP--; //Decrease SP 
 return(oper); //Return data
 } 
 else
 printf("\nERROR STACK UNDER FLOW!!!...\n"); 
} 
int precedenceIP(char oper) //Function for check precedence of input operator
{ 
 switch (oper)
 { 
 case '+' : return(1); 
 case '-' : return(1); 
 case '*' : return(2); 
 case '/' : return(2); 
 case '^' : return(4); 
 case '(' : return(4); 
 } 
} 
int precedenceST(char oper) //Function for check precedence of stack operator
{ 
 switch (oper)
 { 
 case '+' : return(1); 
 case '-' : return(1); 
 case '*' : return(2); 
 case '/' : return(2); 
 case '^' : return(3); 
 case '(' : return(0); 
 } 
} 
void infixTOpostfix(char infix2[80])
{ 
 int i,j, len; 
 char ch,temp;
 printf("INFIX : %s\n ",infix2); //Show infix
 len=strlen(infix2); //Find length of infix
 printf("Infix Length = %d \n",len); //Display length of infix
 printf("POSTFIX IS : "); 
 for (i=0;i<=len-1;i++) //split infix
 { 
 ch=infix2[i]; //Transfer character in to ch variable
 if (strchr("+-* /^()", ch)==0) //Check Is OPERAND?
 printf("%c",ch); //Out to Postfix
 else //If OPERATOR do below
 { 
 if (SP==0) //Stack empty?
 push(ch); //Push any way if Stack empty
 else
 if (ch != ')') //If not ')' do below
 { 
 if(precedenceIP(ch)>precedenceST(OpSt[SP])) //If precedence input > precedence in stack
 push(ch); //Push input operator to Stack
 else
 { 
 printf("%c",pop()); //Out to Postfix
 while(precedenceIP(ch)<=precedenceST(OpSt[SP]) 
&& (SP != 0)) // Do Until precedence input > precedence in stack
 printf("%c",pop()); //Out to Postfix
 push(ch); //Push operator input to Stack 
 } 
 } 
 else
 { 
 temp=pop(); //Pop operator from Stack
 while ((temp != '(') ) // Do if not found '('
 { 
 printf("%c",temp); //Out to Postfix
 temp=pop(); //Pop again and loop
 } 
 } 
 } 
 } 
 j=SP; //Let j for count left Stack
 for(i=1;i<=j;i++) //POP all if Input is NULL
 printf("%c",pop()); //Out to Postfix
} 
int main () 
{
 printf("INFIX to POSTFIX CONVERSION PROGRAM\n"); 
 printf("======================================\n"); 
 infixTOpostfix(infix1); 
 getch(); 
 return(0); 
 
} //End MAIN
