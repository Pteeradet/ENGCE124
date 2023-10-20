/* Program create Graph structure by "2 dimension array
representation method".
Can show the result of graph are ..
1. Set of vertex
2. Set of Edge
Note.- can use both Undirected graph and Directed graph
*/

// #include <conio.h> //use getch
#include <stdio.h> //use printf
#define MaxNode 6 // Define Max Node of Graph
int graph[MaxNode][MaxNode] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0}};                                 // Declare array and keep data of graph
char NodeName[MaxNode] = {'A', 'B', 'C', 'D', 'E', 'F'}; // Keep Node Name

void DispArray2D()                                       // Display value in 2D Array
{
    int i, j; // i=Row, j=Column
    printf(" ");
    for (j = 0; j <= MaxNode; j++) // Display column name of array
        printf("%c ", NodeName[j]);
    printf("\n");                 // line feed
    for (i = 0; i < MaxNode; i++) // row loop
    {
        printf("%c ", NodeName[i]);     // Display row name of array
        for (j = 0; j < MaxNode; j++)   // column loop
            printf("%d ", graph[i][j]); // Display value path
        printf("\n");
    }
}

void DispSetOfVertex() // Display set of Vertex
{
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

void DispSetOfEdge() // Display set of Edge
{
    int i, j;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxNode; i++)     // row loop
        for (j = 0; j < MaxNode; j++) // column loop
        {
            if (graph[i][j] == 1)
                printf("(%c,%c),", NodeName[i], NodeName[j]); // Show each Edge
        }
    printf("}\n");
}

int main()
{
    printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHOD)\n");
    printf("===============================================\n");
    DispArray2D();
    DispSetOfVertex();
    DispSetOfEdge();
    //getch();
    return (0);
} // End Main