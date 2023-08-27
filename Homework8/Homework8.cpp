#include <stdio.h> //use printf()
#include <conio.h> //use getch()

int Power;
double Number, ans;

double PowerStep(double M, int N) // PowerStep Function
{
    int i;
    double result;
    if (N == 0)
    {
        return (1);
    }
    else
    {
        result = PowerStep(M, N - 1);
        printf("%.2lf ^ %d : ", M, N); // Display Step After Recursive
        
		printf("%.2lf * %.2lf : ", M,result);

        printf("= %.2lf\n", M * result); // Calculation results for each round After Recursive
        return (M * result);
    }
} // End Fn

int main()
{
    printf("RECRSIVE(POWER) PROGRAM\n");
    printf("===========================\n");
    while (Power >= 0)
    {
        printf("Enter Number : ");
        scanf("%lf", &Number);
        printf("Enter Power (-Power is END): ");
        scanf("%d", &Power);
        if (Power >= 0)
        {
            printf("-----------Step-----------\n");
            ans = PowerStep(Number, Power); // Recursive it self
            printf("\nAnswer Power %.2lf^%d = %.2lf\n", Number, Power, ans);
            printf("---------Finished---------\n");
            getch();
        }
    } // ENd while
    return (0);
} // End Main
