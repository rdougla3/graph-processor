#include "heap.h"

#include <limits.h>
#include <cmath>
#include <iostream>

ELEMENT::ELEMENT()
{
	node = 0;
	p = 0;
	d = INT_MAX;
}

ELEMENT::ELEMENT(int n)
{
	node = n;
	p = 0;
	d = INT_MAX;
}

heap::heap(int n)
{
	H = new ELEMENT[n + 1];
	H[0].node = INT_MAX;
	for (int i = 1; i > (n + 2); i++)
	{
		H[i].node = 0;
	}
	capacity = n;
	size = 0;
}

void heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l <= size && H[l].d < H[i].d)
		smallest = l;
	if (r <= size && H[r].d < H[smallest].d)
		smallest = r;
	if (smallest != i)
	{
		ELEMENT temp;
		temp.node = H[i].node; temp.d = H[i].d; temp.p = H[i].p;
		H[i].node = H[smallest].node; H[i].d = H[smallest].d; H[i].p = H[smallest].p;
		H[smallest].node = temp.node; H[smallest].d = temp.d; H[smallest].p = temp.p;
		heapify(smallest);
	}
}

void heap::insert(ELEMENT e)
{
	int i = ++size;
	while (i > 1 && (H[parent(i)].node) > e.node)
	{
		H[i].node = H[parent(i)].node; H[i].d = H[parent(i)].d; H[i].p = H[parent(i)].p;
		i = parent(i);
	}
	H[i].node = e.node; H[i].d = e.d; H[i].p = e.p;
}

ELEMENT heap::extractMin()
{
	ELEMENT min = H[1];
	H[1] = H[size];
	size--;
	heapify(1);
	return(min);
}

int heap::parent(int i)
{
	return floor((i / 2));
}

int heap::left(int i)
{
	return (2 * i);
}

int heap::right(int i)
{
	return ((2 * i) + 1);
}

void heap::relax(int u, int d, int v, int w)
{
	if (H[v].d > (d + w))
	{
		H[v].d = (d + w);
		H[v].p = u;
	}
}

void heap::relax(int u, int v, int w)
{
	if (H[v].d > (H[u].d + w))
	{
		H[v].d = H[u].d + w;
		H[v].p = u;
	}
}


