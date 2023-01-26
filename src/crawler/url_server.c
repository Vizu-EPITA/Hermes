#include "../../include/crawler/url_server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>

URLQueue *init_url_queue()
{
    URLQueue *q = malloc(sizeof(URLQueue));
    if(q == NULL)
    {
        errx(EXIT_FAILURE, "Out of memory\n");
    }

    q->size = 0;
    q->first = NULL;

    return q;
}

void add_url(URLQueue *queue, char *url)
{
    URLStruct *urlStruct = malloc(sizeof(URLStruct));
    if(urlStruct == NULL)
    {
        errx(EXIT_FAILURE, "Out of memory\n");
    }  

    char *urlPtr = malloc(sizeof(char) * strlen(url));
    if(urlPtr == NULL)
    {
        errx(EXIT_FAILURE, "Out of memory\n");
    }

    strcpy(urlPtr, url);
    urlStruct->url = urlPtr;

    if(queue->size == 0)
    {
        urlStruct->prev = urlStruct;
        urlStruct->next = urlStruct;
        queue->first = urlStruct;
    }
    else
    {
        urlStruct->prev = queue->first->prev;
        urlStruct->next = queue->first;
        queue->first->prev->next = urlStruct;
        queue->first->prev = urlStruct;
        queue->first = urlStruct; 
    }
    queue->size++;
}

char *pop_url(URLQueue *queue)
{
    URLStruct *tmp;

    if(queue->size == 0)
    {
        return NULL;
    }
    else if(queue->size == 1)
    {
        tmp = queue->first;
        queue->first = NULL;
    }
    else
    {
        tmp = queue->first->prev;
        queue->first->prev->prev->next = queue->first;
        queue->first->prev = queue->first->prev->prev;
    }

    queue->size--;
    char *url = tmp->url;

    free(tmp);

    return url;
}

void free_url_queue(URLQueue *queue)
{
    URLStruct *tmp1 = queue->first->next;
    URLStruct *tmp2 = tmp1->next;

    while(tmp1 != queue->first)
    {
        free(tmp1);
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    free(queue->first);
    free(queue);
}
