/* Program create Graph structure by "Adjacency Multi list
method".
Can show the result of graph are ..
1. Set of vertex
2. Set of Edge
*/
#include <stdio.h> //use printf
#include <conio.h> //use getch
#define MaxEdge 8  // Define Max Edge of Graph
#define Block 5    // Define Block of each node
#define MaxNode 5  // Define Max Node
char NodeName[5] = {'A', 'B', 'C', 'D', 'E'};
char graph[MaxEdge][Block] = {
    {'0', 'A', 'B', '2', '5'},
    {'0', 'A', 'C', '3', '5'},
    {'0', 'A', 'D', '4', '6'},
    {'0', 'A', 'E', '-', '7'},
    {'0', 'B', 'C', '6', '7'},
    {'0', 'B', 'D', '-', '8'},
    {'0', 'C', 'E', '-', '8'},
    {'0', 'D', 'E', '-', '-'},
}; // Declare array and keep data of graph

void DispArray2D()
{             // Display value in 2D Array
    int i, j; // i=Row, j=Column
    printf(" M V1 V2 E1 E2\n");
    for (i = 0; i < MaxEdge; i++)
    {                                   // row loop
        printf("%d ", i + 1);           // Display number of Row
        for (j = 0; j < Block; j++)     // column loop
            printf("%c ", graph[i][j]); // Display value path
        printf("\n");
    }
}

void DispSetOfVertex()
{ // Display set of Vertex
    int i;
    printf("\nSet of Vertex = {");
    for (i = 0; i < MaxNode; i++)
    {
        printf("%c", NodeName[i]); // Display each node name
        if (i != MaxNode - 1)
            printf(",");
    }
    printf("}\n");
}

void DispSetOfEdge()
{ // Display set of Edge
    int i, j;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxEdge; i++)
    {                                                 // row loop
        printf("(%c,%c),", graph[i][1], graph[i][2]); // Show each Edge1
        printf("(%c,%c),", graph[i][2], graph[i][1]); // Show each Edge2
    }
    printf("}\n");
}

int main()
{
    printf("GRAPH ADJACENCY MULTI-LIST REPRESENTATION METHOD\n");
    printf("=============================================\n");
    DispArray2D();
    DispSetOfVertex();
    DispSetOfEdge();
    //getch();
    return (0);
} // End Main
