#include "graph.h"
#include "util.h"

#include <iostream>
#include <fstream>
#include <string>

#pragma warning(disable : 4996)

int nextCommand(int *s, int *t, int *f)
{
	char c;
	while (1)
	{
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		if (c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'W' || c == 'w') {
			break;
		}
		if (c == 'c' || c == 'C') {
			scanf("%d", s); scanf("%d", t);  scanf("%d", f);
			break;
		}
		printf("Invalid Command\n");
	}
	return c;
}

graph* readElements()
{
	int numV;
	int numE;
	int u, v, w;
	list* tail;

	std::fstream myFile;
	myFile.open("Ginput.txt", std::fstream::in | std::fstream::out);
	if (!myFile.is_open())
	{
		printf("Error opening file Ginput1.txt for reading \n");
		return NULL;
	}

	myFile >> numV; myFile >> numE;
	graph* g = new graph(numV, numE);

	for (int i = 1; i < (numE + 1); i++)
	{
		myFile >> u; myFile >> v; myFile >> w;
		if (myFile.eof())
		{
			printf("Error:  The number of edges is less than as specified in the beginning of the file.\n");
		}
		tail = g->A[u];
		while (tail->neighbor != 0)
		{
			tail = tail->next;
		}
		tail->neighbor = v;
		tail->weight = w;
		tail->next = new list();
	}
	return g;
}

void printElements(graph* g)
{
	list* listptr;

	if (g->v == 0)
	{
		printf("Error: There is no graph to print.\n"); return;
	}
	printf("%d %d\n", g->v, g->e);
	for (int i = 1; i < ((g->v) + 1); i++)
	{
		listptr = g->A[i];

		printf("%d : ", i);
		while (listptr->neighbor != 0)
		{
			
			printf("(%d,%d)", listptr->neighbor, listptr->weight);
			listptr = listptr->next;
			if (listptr->neighbor != 0)
			{
				printf(";");
			}
		}
		printf("\n");

	}
}

void printHeap(heap* h)
{
	if (h == NULL)
	{
		printf("Error: heap is not initialized \n");
		return;
	}
	printf("The capcity is %d. \nThe size is %d. \n", h->capacity, h->size);
	for (int i = 1; i < (h->size + 1); i++)
	{
		printf("%d->%d \n", h->H[i].node, h->H[i].d);
	}
}

