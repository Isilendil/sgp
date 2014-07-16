//Population.cpp

#include "Population.h"

Population::Population(CubeIndex size_, 
  MatrixIndex sizeMatrix_, ArrayIndex sizeArray_,
  double crossoverRate_, double mutationRate_)
  : size(size_), sizeMatrix(sizeMatrix_), sizeArray(sizeArray_),
	  crossoverRate(crossoverRate_), mutationRate(mutationRate_)
{
	data = Cube();
	for(CubeIndex index = 0; index < size; ++index)
	{
		data.push_back(Schedule(sizeMatrix, sizeArray));
	}
}

Population::~Population()
{
}

void Population::crossover()
{
	CubeIndex index1 = (rand() % (size-0)) + 0;
	CubeIndex index2 = (rand() % (size-0)) + 0;
	//CubeIndex index1 = 0;
	//CubeIndex index2 = 1;


	MatrixIndex index3 = (rand() % (sizeMatrix-0)) + 0;
	MatrixIndex index4 = (rand() % (sizeMatrix-0)) + 0;
	//MatrixIndex index3 = 0;
	//MatrixIndex index4 = 0;


	int temp = 0;
  for(ArrayIndex index = 0; index < sizeArray; ++index)
	{
		temp = data[index1][index3][index];
		data[index1][index3][index] = data[index2][index4][index];
		data[index2][index4][index] = temp;
	}
}

void Population::mutate()
{
	CubeIndex index1 = (rand() % (size-0)) + 0;
	//CubeIndex index1 = 0;
	MatrixIndex index2 = (rand() % (sizeMatrix-0)) + 0;
	//MatrixIndex index2 = 0;
	randomArray(data[index1][index2].getData());
}

void Population::localSearch()
{
	CubeIndex index1 = (rand() % (size-0)) + 0;
	//CubeIndex index1 = 0;
	MatrixIndex index2 = (rand() % (sizeMatrix-0)) + 0;
	//MatrixIndex index2 = 0;

	ArrayIndex index3 = (rand() % (sizeArray-0)) + 0;
	ArrayIndex index4 = (rand() % (sizeArray-0)) + 0;

	int temp = data[index1][index2][index3];
	data[index1][index2][index3] = data[index1][index2][index4];
	data[index1][index2][index4] = temp;

}

double Population::getCrossoverRate()
{
	return crossoverRate;
}

double Population::getMutationRate()
{
	return mutationRate;
}

void Population::setCrossoverRate(double crossoverRate_)
{
	crossoverRate = crossoverRate_;
}

void Population::setMutationRate(double mutationRate_)
{
	mutationRate = mutationRate_;
}

Schedule& Population::operator[](size_t index)
{
	return data[index];
}

Cube& Population::getData()
{
	return data;
}
