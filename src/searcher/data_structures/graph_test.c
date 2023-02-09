#include <stdio.h>
#include "graph.h"

int main()
{
    printf("Let's create a web pages network graph !\n");
    printf("How many web pages will be in it ?\n-> ");
    int order;
    scanf("%i", &order);
    struct Graph* graph = createGraph(order);
    printf("\nNow, let's link them ! You will have to: \n");
    printf("- tell me the first node to link\n- press enter, \n- then the second one\n");
    printf("If you added enough, just enter 0 and 0\n\n");
    int node1;
    int node2;
    while(1)
    {
        printf("Enter the first node:\n");
        scanf("%d", &node1);
        printf("Enter the second node:\n");
        scanf("%d", &node2);
        if (node1 == 0 && node2 == 0)
            break;
        addEdge(graph, node1, node2);
        printf("\nEnter a new couple :\n");
    }

    printf("\nOk now lets see if it works :\n");
    printGraph(graph);

    return 0;
}
