/* Program create Graph structure by "Node directory method".
Can show the result of graph are ..
1. Set of vertex
2. Set of Edge and Weight
Note.- Can use for Weighting Graph in both Undirected graph and
Directed graph
*/
#include <stdio.h> //use printf
#include <conio.h> //use getch
#define MaxNode 4 // Define Max Node
#define Block 4   // Define Block of each node
#define MaxEdge 6 // Define Max Extra of Graph
char Head[MaxNode][Block] = {
    {'A', '-', '1', '1'},
    {'B', '-', '3', '2'},
    {'C', '-', '2', '5'},
    {'D', '-', '0', NULL},

}; // Declare array and keep Head Node of graph
char Edge[MaxEdge][2] = {
    {'2', 'B'},
    {'5', 'A'},
    {'9', 'C'},
    {'7', 'D'},
    {'8', 'B'},
    {'6', 'D'},
};              // Declare array and keep Edge of graph

void DispHead() // Display Head in 2D Array
{
    int i, j; // i=Row, j=Column
    printf("NODE...\n");
    printf("No. Name Data Edge Pointer\n");
    for (i = 0; i < MaxNode; i++) // row loop
    {
        printf("%d    ", i + 1);          // Display number of Row
        for (j = 0; j < Block; j++)    // column loop
            printf("%c    ", Head[i][j]); // Display Node
        printf("\n");
    }
}

void DispEdge() // Display Edge in 2D Array
{
    int i, j; // i=Row, j=Column
    printf("EDGE...\n");
    printf("No. Weight Node\n");
    for (i = 0; i < MaxEdge; i++) // row loop
    {
        printf("%d     ", i + 1);          // Display number of Row
        for (j = 0; j < 2; j++)        // column loop
            printf("%c     ", Edge[i][j]); // Display Node
        printf("\n");
    }
}

void DispSetOfVertex() // Display set of Vertex
{
    int i;
    printf("\nSet of Vertex = {");
    for (i = 0; i < MaxNode; i++)
    {
        printf("%c", Head[i][0]); // Display each node name
        if (i != MaxNode - 1)
            printf(",");
    }
    printf("}\n");
}

void DispSetOfEdge() // Display set of Edge
{
    int i, j, AmtEdge, PT;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxNode; i++) // row loop
    {
        AmtEdge = Head[i][2] - 48;    // Convert Character to Integer for Amount of Edge
        PT = Head[i][3] - 48;         // Convert Character to Integer for Start point of Array
        for (j = 0; j < AmtEdge; j++) // Loop follow by Amount of Edge
        {
            printf("(%c%c)%c,", Head[i][0], Edge[PT - 1 + j][1], Edge[PT - 1 + j][0]);
            // Show Edge and Weight
        }
    }
    printf("}\n");
}

int main()
{
    printf("GRAPH NODE DIRECTORY REPRESENTATION METHOD\n");
    printf("=============================================\n");
    DispHead();
    DispEdge();
    DispSetOfVertex();
    DispSetOfEdge();
    getch();
    return (0);
} // End Main
