#include "heap.h"
#pragma once

class list
{
public:
	int neighbor;
	int weight;
	list* next;

	list();
};

class graph
{
public:
	int v; int e;
	heap* h;  heap* q;
	list** A;

	graph(int v, int e);
	void InitializeSingleSource(int);
	int findNeighbor(int);
	void Dijkstras(int, int, int);
};

