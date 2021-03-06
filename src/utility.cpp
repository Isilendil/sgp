//utility.cpp

#include "utility.h"

using std::vector;

void randomArray(Array &array)
{
	ArrayIndex size = array.size();
	for(ArrayIndex i = 0; i < size; ++i)
	{
		array[i] = i + 1;
	}

	ArrayIndex randomIndex = 0;
	int temp = 0;
	for(; size != 0; --size)
	{
		randomIndex = (rand() % (size-0)) + 0;
		temp = array[randomIndex];
		array[randomIndex] = array[size-1];
		array[size-1] = temp;
	}
}

void mySort(int a, int b, int &max, int &min)
{
	max = a > b ? a : b;
	min = a < b ? a : b;
}

bool compare(Schedule x, Schedule y)
{
	x.computeFitness();
	y.computeFitness();
	return x.getFitness() > y.getFitness();
}
