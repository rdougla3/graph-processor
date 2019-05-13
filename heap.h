#pragma once

class ELEMENT
{
public:
	int node;
	int p;
	int d;

	ELEMENT();
	ELEMENT(int);
};

class heap
{
public:
	int capacity;
	int size;
	ELEMENT* H;

	heap(int);
	void heapify(int);
	void insert(ELEMENT);
	ELEMENT extractMin();
	int parent(int i);
	int left(int i);
	int right(int i);
	void relax(int, int, int, int);
	void relax(int, int, int);
};

