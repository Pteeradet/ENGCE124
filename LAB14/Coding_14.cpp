/* Program create Graph structure by "Adjacency list
representation method".
Can show the result of graph are ..
1. Set of vertex
2. Set of Edge
Note.- can use both Undirected graph and Directed graph
*/
#include <stdio.h>  //use printf
#include <conio.h>  //use getch
#include <stdlib.h> //use molloc
#define MaxNode 4   // Define Max Node of Graph

char NodeName[4] = {'A', 'B', 'C', 'D'};
int graph[MaxNode][MaxNode] = {
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 0},
};          // Declare array and keep data of graph

struct Node // Declare structure of every node
{
    char info;
    struct Node *next;
};

struct Node *Start[MaxNode], *p; // Declare pointer uses

Node *Allocate()                 // Allocate 1 node from storage pool
{
    struct Node *temp;
    temp = (Node *)malloc(sizeof(Node)); // Allocate node by size declare
    return (temp);
}

void CreateHead() // Create Head Node
{
    int i;
    for (i = 0; i < MaxNode; i++) // Count by Maximum of Node
    {
        p = Allocate();
        p->info = NodeName[i]; // Let INFO = Node Name
        p->next = NULL;        // Let NEXT = NULL
        Start[i] = p;          // Let Start of each node = Address of first Node
    }
}

void TransferToAdjacent() // Transfer array to Adjacency list of graph
{
    int i, j;
    struct Node *Rear;            // Counter and point at last pointer finally
    for (i = 0; i < MaxNode; i++) // row loop
    {
        Rear = Start[i];              // pointer Rear Start hear
        for (j = 0; j < MaxNode; j++) // column loop
        {
            if (graph[i][j] == 1) // if PATH?
            {
                p = Allocate();        // get new Node
                p->info = NodeName[j]; // Let info = NodeName[j]
                p->next = NULL;        // Let NEST = NULL
                Rear->next = p;        // Next of Rear point to New Node
                Rear = p;              // Skip Rear pointer to Next Node
            }
        }
    }
}

void DispSetOfVertex() // Display set of Vertex
{
    int i;
    printf("\nSet of Vertex = {");
    for (i = 0; i < MaxNode; i++) // Count only Start Node
    {
        printf("%c", Start[i]->info); // Display each node name
        if (i != MaxNode - 1)
            printf(",");
    }
    printf("}\n");
}

void DispSetOfEdge() // Display set of Edge
{
    int i;
    struct Node *Temp;
    printf("\nSet of Edge = {");
    for (i = 0; i < MaxNode; i++) // row loop
    {
        Temp = Start[i];     // Let Temp pointer Start hear
        Temp = Temp->next;   // Skip Temp pointer to Next Node
        while (Temp != NULL) // Point at Node 2nd
        {
            printf("(%c,%c),", Start[i]->info, Temp->info); // Show each Edge
            Temp = Temp->next;                              // Skip Temp pointer to Next Node
        }
    }
    printf("}\n");
}

int main()
{
    printf("GRAPH (ADJACENCY LIST REPRESENTATION METHOD)\n");
    printf("=============================================\n");
    CreateHead();
    TransferToAdjacent();
    DispSetOfVertex();
    DispSetOfEdge();
    //getch();
    return (0);
} // End Main
