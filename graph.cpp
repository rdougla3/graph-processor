#include "graph.h"
#include "util.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

list::list()
{
	neighbor = 0;
	weight = 0;
	next = NULL;
}

graph::graph(int vertices, int edges)
{
	v = vertices;
	e = edges;
	A = new list*[v+1];
	for (int i = 1; i < (v + 1); i++)
	{
		A[i] = new list();
	}
}

void graph::InitializeSingleSource(int n)
{
	ELEMENT* temp;

	h = new heap(v); //heap to store completed nodes

	q = new heap(v); //priority que for nodes
	for (int i = 1; i < (v + 1); i++)
	{
		temp = new ELEMENT(i);
		if (i == n)
		{
			temp->d = 0;
			temp->p = i;
		}
		q->insert(*temp);
	}

}

void graph::Dijkstras(int s, int t, int f)
{

	if (v == 0)
	{
		printf("Error:  There is no graph to run Dijkstra's algorithm on.\n"); return;
	}
	if (f != 0 && f != 1)
	{
		printf("Error:  Invalid flag value.\n"); return;
	}
	if (s > v || t > v)
	{
		printf("Error:  One or more of the nodes is invalid.\n"); return;
	}

	ELEMENT min;
	list* listptr;

	InitializeSingleSource(s);
	while (q->size != 0)
	{
		for (int i = (q->size+1)/2; i > 0; i--) //puts the list of incomplete nodes in heap order
		{
			q->heapify(i);
		}
		min = q->extractMin();
		h->H[min.node].node = min.node; h->H[min.node].d = min.d; h->H[min.node].p = min.p; h->size++; //put the extracted node into h
		listptr = A[min.node];

		if (min.d != INT_MAX) //if a node is not reachable from the source, there is no point exploring it's adjacencies
		{
			while (listptr->neighbor != 0) //while there are remaining adjacencies...
			{
				int neighborIndex = findNeighbor(listptr->neighbor); //find the adjacent node in q
				if (neighborIndex > 0)
				{
					q->relax(min.node, min.d, neighborIndex, listptr->weight);
				}
				listptr = listptr->next; //move on to the next adjacent node
			}
		}
	}


	if (h->H[t].p == 0)
	{
		printf("Sorry, node %d is not reachable from node %d.\n", t, s); return;
	}

	if (f == 0)
	{

		printf("LENGTH: %d\n", h->H[t].d);
	}
	else if (f == 1)
	{
		ostringstream convert;
		convert << t;
		string output = convert.str();
		int i = t;
		while (i != s) //add each node between the destination and source to the string
		{
			i = h->H[i].p;
			convert.str("");
			convert << h->H[i].node;
			output = (convert.str() + "," + output);
		}
		cout << "PATH: " << output << endl;
	}
		
}

int graph::findNeighbor(int neighbor)
{
	for (int i = q->size; i >= 0; i--)
	{
		if (q->H[i].node == neighbor)
		{
			return i;
		}
	}
	return 0;
}
