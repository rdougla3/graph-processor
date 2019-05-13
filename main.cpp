#include "main.h"
#include "heap.h"
#include "graph.h"
#include "util.h"

#include <cmath>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// variables for the parser...
	char c;
	int s, t, f;
	graph* myGraph = new graph(0,0);

	while (1)
	{
		c = nextCommand(&s, &t, &f);
		switch (c)
		{
		case 'e':
		case 'E': printf("COMMAND: %c.\nThe program is going to be terminated.\n", c); exit(0);

		case 'i':
		case 'I': printf("COMMAND: %c.\n", c); myGraph = readElements(); break;

		case 'w':
		case 'W': printf("COMMAND: %c.\n", c); printElements(myGraph); break;

		case 'c':
		case 'C': printf("COMMAND: %c %d %d %d.\n", c, s, t, f); myGraph->Dijkstras(s, t, f); break;

		default: break;

		}
	}
	exit(0);
}
