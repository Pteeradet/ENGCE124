/* Program ASCENDING HEAP SORT can..
1. Random raw data into one dimension Array
2. Sorting and display detail of each step result
3. Display final result
*/
#include <stdio.h>  //use printf
//#include <conio.h>  //use getch
#include <stdlib.h> //use random
#include <time.h>   //use time
#define MaxData 100 // Define Max Data                                      
int Data1[MaxData], Data2[MaxData];
int N;

void PrepareRawData(int N)
{
    int i;
    srand(time(NULL)); // for difference random number in rand()
    for (i = 1; i <= N; i++)
        Data1[i] = 1 + rand() % 99; // random difference number 1..99
}

void DispData(int Data[], int out) // Out is point of Outputted Number backward
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if (i < out)
            printf("%2d ", Data[i]); // Show 2 width of number
        else
            printf("[%2d] ", Data[i]); // Show [ ] if it's Output
    }
    printf("\n");
}

void swap(int a, int b)
{
    int temp;
    temp = Data2[a];
    Data2[a] = Data2[b];                                                
    Data2[b] = temp;
}

int Maximum(int a, int b) // Fine Maximum from 2 Data                   
{
    if (a > b)
        return (a);
    else
        return (b);
}

void AdjustTree(int LastNode)                                       
{
    int i, Max, lson, rson, son;
    bool result;
    i = 1;
    result = false; // False is NOT Finish Adjustment yet
    while (!result)
    {
        lson = (2 * i);     // Calculate LSon
        rson = (2 * i) + 1; // Calculate RSon
        son = 0;            // Set default Son
        if (lson == LastNode)
        {
            son = 1;
            if (Data2[i] < Data2[lson]) // Check Father Data < LSon data ?                          
            {
                swap(i, lson);
                DispData(Data2, LastNode + 1); // Show each step result
            }
            result = true; // Finish Adjustment
        }
        if (rson <= LastNode)
        {
            son = 2;
            Max = Maximum(Data2[lson], Data2[rson]); // Find Maximum Data
            if (Data2[i] < Max)                      // Check Father Data < Max ?
            {
                if (Max == Data2[lson]) // Max == Data Lson?
                {
                    swap(i, lson);
                    DispData(Data2, LastNode + 1); // Show each step result
                    if (rson == LastNode)          // Check for Last Node
                        result = true;             // Finish Adjustment
                    else
                        i = lson; // Let i follow to LSon
                }

                else // if Data RSon is Maximum
                {
                    swap(i, rson);
                    DispData(Data2, LastNode + 1); // Show each step
                    if (rson == LastNode)          // Check for Last Node
                        result = true;             // Finish Adjustment
                    else
                        i = rson; // Let i follow to RSon
                }
            }
            else
                result = true; // Finish Adjustment
        }
        if (son == 0)
            result = true; // Finish Adjustment
    }                      // End While
    printf("---------------------------------------------------Adjust Tree Finished at N=%d \n", LastNode);
} // End Fn.

void CreateHeapTree() // Create form Data1 into Data2
{
    int i, j, k, father;
    bool result;
    // Craete Heap Tree
    Data2[1] = Data1[1];    // First node of Heap Tree
    DispData(Data2, N + 1); // Show each step result
    for (i = 2; i <= N; i++)
    {
        Data2[i] = Data1[i];
        DispData(Data2, N + 1); // Show each step result
        result = true;
        j = i; // set backward counter start here
        while (result)
        {
            father = j / 2;                            // Calculate Father
            if ((Data2[j] > Data2[father]) && (j > 1)) // Heap tree adjusting
            {
                swap(j, father);
                DispData(Data2, N + 1); // Show each step result
                j = father;             // Let j follow to new Father
                result = true;
            }
            else
                result = false;
        } // End While
    }     // End for

    printf("---------------------------------------------------Create Heap Tree Finished \n");
    for (k = 1; k <= N; k++) // Display Array subscript                                 
        printf("(%d) ", k);
    printf("\n");
    for (i = N; i > 1; i--)
    {
        swap(1, i);         // Output Root Node
        DispData(Data2, i); // Show each step result
        AdjustTree(i - 1);  // Call Adjust Heap Tree
    }                       // End for
} // End Fn.

int main()
{
    printf("ASCENDING HEAP SORT\n");
    printf("===================================================\n");
    N = 8;
    PrepareRawData(N);
    printf("Raw Data : ");
    DispData(Data1, N + 1);
    printf("---------------------------------------------------Raw Data Finished \n");
    printf("Create Heap Tree...\n");
    CreateHeapTree();
    printf("Sorted Data is : ");
    DispData(Data2, 1); // Sorted Data
    printf("---------------------------------------------------Sort Finished \n");
    //getch();
    return (0);
} // End Main