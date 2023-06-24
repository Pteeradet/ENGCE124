#include<stdio.h>
#include <math.h>

int main()
{
	int num,h,j,i=1,d=0,m,l;
	int bin[100];
	do{	
	printf("Mode 1 Decimal to Binary \n");
	printf("Mode 2 Binary to Decimal \n");
	printf("Mode 3 Decimal to ASCII \n");
	printf("Select Mode :");
	scanf("%d",&num);
	printf("---------------------------------\n");
	}while(num<1 || num>3);
	
	if(num==1)
	{
		printf("**Decimal to Binary** \n");
		printf("Input Number : ");
		scanf("%d",&h);
		do
    {
        bin[d] = h % 2;
        h /= 2;
        d++;
    }while(h > 0);
 
 	printf("Binary value is :");
     
    for(j = d - 1; j >= 0; j--)
    {
        printf("%d", bin[j]);   
    }
    }
	else if (num==2)
	{
		printf("**Binary to Decimal** \n");
		printf("Input Number : ");
		scanf("%d",&h);	
		while(h>0){
               m=h%10;
               l+=m*pow(2,d);
			   h=h/10;
               d++;
          }	
          printf("Decimal value is %d ",l);
	}
	else if (num==3)
	{
	printf("**Decimal to ASCII**\n");
	printf("Number Decimal to ASCII : ");
	scanf("%d",&h);	
	printf("ASCII : %c",h);
	}
}
