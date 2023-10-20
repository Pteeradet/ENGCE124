/* Program ASCENDING SELECTION SORT can..
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
int N;

void PrepareRawData(int N)
{
    int i;
    srand(time(NULL)); // for difference random number in rand()
    for (i = 1; i <= N; i++)
        Data[i] = 1 + rand() % 99; // random difference number 1..99        
}

void DispData(int N, int out) // Show Data in array 2 format
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (out >= i)
            printf("[%2d] ", Data[i]); // show [] if it's Output
        else
            printf("%2d ", Data[i]); // show normal form it is not Output       
    }
    printf("\n");
}

void swap(int a, int b)
{
    int temp;
    temp = Data[a];
    Data[a] = Data[b];                                                          
    Data[b] = temp;
}

int Minimum(int j) // Find Minimum data in Data[] between j..N                      
{
    int i, temp, Location;
    Location = j;   // set first Location
    temp = Data[j]; // set begin value
    for (i = j + 1; i <= N; i++)
    {
        if (temp > Data[i])
        {
            temp = Data[i]; // change new minimum data
            Location = i;   // keep new Location
        }
    }
    return (Location); // return address of Minimum data
} // End Fn.

void SelectionSort(int N)
{
    int i, j, Location;
    printf("---------------------------------------------------------------------\n");
    printf(" i LOC ");
    for (i = 1; i <= N; i++)
        printf("(%2d) ", i);
    printf("\n ");
    DispData(N, 0); // Show every step sorting
    printf("---------------------------------------------------------------------\n");
    for (i = 1; i <= N; i++)
    {
        Location = Minimum(i); // Find Minimum Location between i..N
        swap(i, Location);
        printf("(%2d) (%2d) ", i, Location); // show location of array
        DispData(N, i);                      // Show every step sorting
    }
} // End Fn.

int main()
{
    printf("ASCENDING SELECTION SORT\n");
    printf("=====================================================================\n");
    N = 12; // Change amount of N here
    PrepareRawData(N);
    printf("Raw Data...");
    DispData(N, 0);
    printf("Processing Data...\n");
    SelectionSort(N);
    printf("---------------------------------------------------------------------\n");
    printf("Sorted Data : ");
    DispData(N, N); // Sorted Data
    //getch();
    return (0);
} // End Main