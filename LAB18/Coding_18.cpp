/* Program ASCENDING BUBBLE SORT can..
1. Random raw data into 1 dimension Array
2. Sorting and display detail of each step result
3. Display final result
*/
#include <stdio.h>  //use printf                                
#include <conio.h>  //use getch
#include <stdlib.h> //use random
#include <time.h>   //use time
#define MaxData 100 // Define Max Data
int Data[MaxData];
int N;

void PrepareRawData(int N)
{
    int i;
    srand(time(NULL)); // for difference random number in rand()
    for (i = 1; i <= N; i++)
        Data[i] = 1 + rand() % 99; // random difference number 1..99
}
void DispData(int N)
{
    int i;
    for (i = 1; i <= N; i++)
        printf("%2d ", Data[i]);                            
    printf("\n");
}

void BubbleSort(int N)
{
    int i, j, temp;
    printf("----------------------------------------------------------------\n");
    printf(" i ");
    for (i = 1; i <= N; i++)
        printf(" (%2d)", i);
    printf("\n");
    printf("----------------------------------------------------------------\n");
    for (i = 1; i <= N - 1; i++) // loop forward
    {
        if (Data[i] > Data[i + 1]) // if not true position
        {
            printf("%2d. ", i + 1);
            DispData(N);
            j = i + 1;                    // loop backward
            while (Data[j] < Data[j - 1]) // while if remain bubble
            {
                temp = Data[j - 1]; // swap data
                Data[j - 1] = Data[j];
                Data[j] = temp;
                j--; // count down j
                printf("%2d. ", i + 1);
                DispData(N);
            } // end while
        }     // end if
    }         // end for
} // end Fn.

int main()
{
    printf("ASCENDING BUBBLE SORT\n");
    printf("================================================================\n");
    N = 12;
    PrepareRawData(N);
    printf("Raw Data : ");
    DispData(N);
    printf("----------------------------------------------------------------\n");
    printf("Processing Data...\n");
    BubbleSort(N);
    printf("----------------------------------------------------------------\n");
    printf("Sorted Data : ");
    DispData(N); // Sorted Data
    getch();
    return (0);
} // End Main