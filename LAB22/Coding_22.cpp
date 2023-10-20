/* Program ASCENDING RADIX SORT can..
1. Random raw data into 1 dimension Array
2. Sorting and display detail of each step result
3. Display final result
*/
#include <stdio.h>  //use printf
#include <conio.h>  //use getch
#include <stdlib.h> //use random
#include <time.h>   //use time
#define MaxData 100 // Define Max Data
#define MaxRow 10   // 0..9 in Decimal base
#define MaxCol 20   // 0..19
int Data[MaxData];
int Radix[MaxRow][MaxCol]; // Radix is temporary tank. The size is [0..MaxRow,0..MaxCol]
int N, N1;

void ClearStackPT() // Clear every block=0 and use Radix[0] for SP              
{
    int i;
    for (i = 0; i <= MaxRow; i++)
        Radix[i][0] = NULL; // This position keep the SP
}

void PrepareRawData(int N2)
{
    int i;
    srand(time(NULL)); // for difference random number in rand()
    for (i = 0; i < N2; i++)
        Data[i] = (rand() % 899) + 100; // random difference number 100..999
}

void DispData(int N2) // Show Data in array                                 
{
    int i;
    for (i = 0; i < N2; i++)
        printf("%3d ", Data[i]);
    printf("\n");
}

void Push(int Rad, int Dat) // Put data into Parallel Stack by keep SP at (Rad,0)
{
    int SP;
    SP = Radix[Rad][0] + 1; // Skip SP
    Radix[Rad][0] = SP;     // keep new SP
    Radix[Rad][SP] = Dat;   // Push data into that Radix
}

void ReadStack() // Read data from each Stack and transfer to Data[]
{
    int i, j, k, SP;
    k = 0; // Start of Data[] at subscript 0
    for (i = 0; i <= MaxRow; i++)
    {
        SP = Radix[i][0]; // Max Count value of each Radix keep at column 0
        for (j = 1; j <= SP; j++)
        {
            Data[k] = Radix[i][j]; // Transfer data from every Stack to Data[]
            k++;
        }
    } // End for
} // End Fn.

void RadixSort(int N2)
{
    int Digit, i, RadixNo;
    char Txt[2];
    for (Digit = 2; Digit >= 0; Digit--) // Count down
    {
        printf("[Digit : %d]==>\n", 3 - Digit);
        for (i = 0; i < N2; i++) // Data[] counter
        {
            itoa(Data[i], Txt, 10);    // convert Integer to Text [itoa(input,output,base)]
            RadixNo = Txt[Digit] - 48; // covert Text that Digit to Number
            Push(RadixNo, Data[i]);    // Pust Data to Stack at that Radix

        } // End for
        ReadStack();
        DispData(N2);
        ClearStackPT();
    } // End for
} // End Fn.

int main()
{
    printf("ASCENDING RADIX SORT\n");
    printf("=====================================================================\n");
    N = 16; // Change amount of N here
    N1 = N; // Keep N to N1 Because N is 0 when finished RadixSort()!! I don't understand
    PrepareRawData(N);
    printf("Raw Data...\n");
    DispData(N);
    printf("---------------------------------------------------------------------\n");
    printf("Processing Data...\n");
    RadixSort(N);
    // printf("N= %d\n",N); //Problem point!!
    printf("--------------------------------------------------------------Finished\n");
    printf("Sorted Data : \n");
    DispData(N1); // Sorted Data
    getch();
    return (0);
} // End Main