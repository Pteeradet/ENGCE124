/* Program ASCENDING QUICK SORT can..
1. Random raw data into 1 dimension Array
2. Sorting and display detail of each result
3. Display final result
*/
#include <stdio.h>  //use printf                                
//#include <conio.h>  //use getch
#include <stdlib.h> //use random
#include <time.h>   //use time
#define MaxData 100 // Define Max Data
int Data[MaxData];
int i, N;

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
        printf(" %2d ", Data[i]);                           
    printf("\n");
}

void swap(int a, int b)
{
    int temp;
    temp = Data[a];
    Data[a] = Data[b];                                          
    Data[b] = temp;
}

void QuickSort(int f, int r) // Recursive Fn.
{
    int f1, r1;
    bool direction;
    f1 = f;
    r1 = r; // keep old Front & Rear values
    direction = true;
    while (f != r)
    {
        if (Data[f] > Data[r]) // Ascending case
        {
            printf("%2d %2d : ", f, r);
            DispData(N);
            swap(f, r);
            printf("%2d %2d : ", f, r);
            DispData(N);
            direction = !direction; // change moving pointer direction
        }
        if (direction) // move r to left if TRUE
            r--;
        else
            f++; // move f right if FALSE
    }
    printf("k1=[%2d]--------------------------------------------------------\n", Data[f]); //
    // process in left hand
    if ((f > f1) && (f - 1 != f1))
        QuickSort(f1, f - 1); // recursive new position F&R
    // process in right hand
    if ((r < r1) && (r + 1 != r1))
        QuickSort(r + 1, r1); // recursive set new position F&R
}

int main()
{
    printf("ASCENDING QUICK SORT\n");
    printf("==============================\n");
    N = 12;
    PrepareRawData(N);
    printf("Raw Data : ");
    DispData(N);
    printf("Processing Data...\n");
    printf(" F R ");
    for (i = 1; i <= N; i++)
        printf(" (%2d)", i);
    printf("\n");
    QuickSort(1, N);
    printf("----------------------------------------------------------------\n");
    printf("Sorted Data : ");
    DispData(N); // Sorted Data
    //getch();
    return (0);
} // End Main