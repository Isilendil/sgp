//Population.h

#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "common.h"

class Population
{
public:
  Population(CubeIndex size_ = 1000, 
	  MatrixIndex sizeMatrix_ = 7, ArrayIndex sizeArray_ = 15,
	  double crossoverRate_ = 0.75, double mutationRate_ = 0.02);
	~Population();

  void crossover();
	void mutate();
  void localSearch();

  double getCrossoverRate();
	double getMutationRate();

  void setCrossoverRate(double crossoverRate_);
	void setMutationRate(double mutationRate_);

  Schedule& operator[](size_t index);
	Cube& getData();

protected:

private:
  Cube data;

	double crossoverRate;
	double mutationRate;

	CubeIndex size;
	MatrixIndex sizeMatrix;
	ArrayIndex sizeArray;

};
#endif

