/* Program ASCENDING INSERTION SORT can..
1. Random raw data into 1 dimension Array
2. Sorting and display detail of each result
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

void InsertionSort(int N)
{
    int i, j, temp;
    printf("---------------------------------------------------------------------\n");
    printf(" i ");
    for (i = 1; i <= N; i++)
        printf(" (%2d)", i);
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    printf("%2d. ", 0);
    DispData(N);            // Show every step sorting
    for (i = 1; i < N; i++) // Count i forward
    {
        if (Data[i + 1] < Data[i]) // If next data < previous data
        {
            temp = Data[i + 1]; // Keep insert data into temp
            Data[i + 1] = NULL;
            j = i;                 // let counter j loop backward
            while (temp < Data[j]) // loop if temp remain < Data[j]
            {
                Data[j + 1] = Data[j]; // Skip data forward to next block of array
                Data[j] = NULL;
                printf("%2d. ", i + 1);
                DispData(N);    // Show every time sorting
                j = j - 1;      // count backward of j
            }                   // End while
            Data[j + 1] = temp; // Put temp into Data[j+1] finally
            printf("%2d. ", i + 1);
            DispData(N); // Show every time sorting
        }                // end if
    }                    // ENd for
} // End Fn.

int main()
{
    printf("ASCENDING INSERTION SORT\n");
    printf("==============================\n");
    N = 12;
    PrepareRawData(N);
    printf("Raw Data...");
    DispData(N);
    printf("Processing Data...\n");
    InsertionSort(N);
    printf("----------------------------------------------------------------\n");
    printf("Sorted Data : ");
    DispData(N); // Sorted Data
    getch();
    return (0);
} // End Main