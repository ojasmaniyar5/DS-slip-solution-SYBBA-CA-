#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure containing adjacency list
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node in the adjacency list
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for an array of adjacency lists
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to display the adjacency list
void displayGraph(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices;

    // Read the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Create a graph with the given number of vertices
    struct Graph* graph = createGraph(numVertices);

    // Read the adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            int value;
            scanf("%d", &value);

            // If there is an edge (value = 1), add it to the graph
            if (value == 1) {
                addEdge(graph, i, j);
            }
        }
    }

    // Display the adjacency list
    displayGraph(graph);

    return 0;
}
