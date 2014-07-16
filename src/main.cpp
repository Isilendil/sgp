//main.cpp

#include "common.h"


using namespace std;

void crossoverTest(Population &p);
void mutateTest(Population &p);
void localSearchTest(Population &p);

int main()
{
	srand(unsigned(time(NULL)));

  Population p;
  
	p[0].computeFitness();
	cout << p[0].getFitness() << endl;

	return 0;
}

void crossoverTest(Population &p)
{
	p[0].print();
	p[1].print();
	cout << endl;
	p.crossover();
	cout << endl;
	p[0].print();
	p[1].print();
}

void mutateTest(Population &p)
{

	p[0].print();
	p.mutate();
	p[0].print();
}

void localSearchTest(Population &p)
{
	p[0].print();
	p.localSearch();
	p[0].print();
}
