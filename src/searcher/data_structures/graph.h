#ifndef GRAPH_H
#define GRAPH_H

struct Node
{
    int ID;
    struct Node** adjList;
    int nbAdj;
    int adjListSize;
    struct Node** prevList;
    int nbPrev;
    int prevListSize;

};

struct Graph
{
    int order;
    struct Node** nodes;
    int sizeNodesList;
};

struct Node* newNode(int ID);

struct Graph* graphInit(int order);

void addNode(struct Graph* graph);

void addEdge(struct Graph* graph, struct Node* src, struct Node* dest);

void freeGraph(struct Graph*);

void printGraph(struct Graph* graph);





#endif
