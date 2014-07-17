//Population.cpp

#include "Population.h"

using namespace std;

Population::Population(CubeIndex size_, 
  MatrixIndex sizeMatrix_, ArrayIndex sizeArray_,
  double crossoverRate_, double mutationRate_)
  : size(size_), sizeMatrix(sizeMatrix_), sizeArray(sizeArray_),
	  crossoverRate(crossoverRate_), mutationRate(mutationRate_)
{
	data = Cube();
	tempData = Cube();
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
	int i = 1;
	while(i++ <= size*crossoverRate/2)
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
}

void Population::mutate()
{
	//CubeIndex index1 = (rand() % (size-0)) + 0;
	//CubeIndex index1 = 0;
	for(CubeIndex index1 = 0; index1 < size; ++index1)
	{
		if(rand()/double(RAND_MAX) < mutationRate)
		{
	    MatrixIndex index2 = (rand() % (sizeMatrix-0)) + 0;
	    //MatrixIndex index2 = 0;
	    randomArray(data[index1][index2].getData());
		}
	}
}


void Population::localSearch()
{
	for(CubeIndex index1 = 0; index1 < size; ++index1)
	{
		for(int j = 0; j < K; ++j)
		{
	    MatrixIndex index2 = (rand() % (sizeMatrix-0)) + 0;
	    //MatrixIndex index2 = 0;

	    ArrayIndex index3 = (rand() % (sizeArray-0)) + 0;
	    ArrayIndex index4 = (rand() % (sizeArray-0)) + 0;

      Cube tempCube = Cube(data);
			tempCube[index1][index2][index3] = data[index1][index2][index4];
			tempCube[index1][index2][index4] = data[index1][index2][index3];

      tempCube[index1].computeFitness();
			double delta = tempCube[index1].getFitness() - data[index1].getFitness();

			if( (delta > 0) /*or (rand()/double(RAND_MAX) < pow(e,delta/t))*/ )
			{
			  data[index1][index2][index3] = tempCube[index1][index2][index4];
			  data[index1][index2][index4] = tempCube[index1][index2][index3];
			}
	    int temp = data[index1][index2][index3];
	    data[index1][index2][index3] = data[index1][index2][index4];
	    data[index1][index2][index4] = temp;


		}
	/*
	CubeIndex index1 = (rand() % (size-0)) + 0;
	//CubeIndex index1 = 0;
	MatrixIndex index2 = (rand() % (sizeMatrix-0)) + 0;
	//MatrixIndex index2 = 0;

	ArrayIndex index3 = (rand() % (sizeArray-0)) + 0;
	ArrayIndex index4 = (rand() % (sizeArray-0)) + 0;

	int temp = data[index1][index2][index3];
	data[index1][index2][index3] = data[index1][index2][index4];
	data[index1][index2][index4] = temp;
*/

	}
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

void Population::ga()
{
  //loop
	double fitnessSumLast = 0;
	double fitnessSumCurrent = 0;
	
	//compute
	computeFitness();
	fitnessSumCurrent = getFitnessSum();
	
	ts = 10.0;
	tf = 0.5;
	nrep = 15;
	beta = (ts-tf) / (nrep*ts*tf);
	K = 1;
	t = ts;
		
	while(true)
	{
		//select
		//select();
		//cout << "before select" << '\n';
		rouletteWheelSelect();
		//cout << "after select" << '\n';
		//update
		//cout << "before update" << '\n';
		update();
		//cout << "after update" << '\n';
		//crossover
		crossover();
		//mutate
		mutate();

		//compute
		//computeFitness();

		//local search
		localSearch();
		
		if(t > tf)
		{
			t = t / (1+beta*t);
		}
		else
		{
			t = ts;
		}

		//compute
		computeFitness();

		fitnessSumCurrent = getFitnessSum();


    double max = 0;
		double sumTemp = 0;
		double maxTemp = 0;
    for(CubeIndex i = 0; i < size; ++i)
		{
			maxTemp = data[i].getFitness();
			sumTemp += maxTemp;
			//cout << maxTemp << endl;
			if(maxTemp > max)
			{
				max = maxTemp;
			}
			//if(data[i].getFitness() == 315)
			if(data[i].getFitness() == 1)
			{
				data[i].print();
				return;
			}
		}
		cout << 1.0/max+105-1 << '\t' << max << '\t' << sumTemp/1000 << endl;
		fitnessSumLast = fitnessSumCurrent;
    //cout << fitnessSumCurrent << '\n';
	}
}

void Population::computeFitness()
{
	for(CubeIndex i = 0; i < size; ++i)
	{
		data[i].computeFitness();
	}
}

double Population::getFitnessSum()
{
	double sum = 0;
	for(CubeIndex i = 0; i < size; ++i)
	{
		sum += data[i].getFitness();
	}
	return sum;
}

void Population::rouletteWheelSelect()
{
	double sum = getFitnessSum();
	double average = sum / size;
	//cout << sum << endl;
	double *temp = new double [size];
	temp[0] = data[0].getFitness() / sum;

	double maximum = data[0].getFitness();
	int maxIndex = 0;

	for(CubeIndex i = 1; i < size; ++i)
	{
		if(data[i].getFitness() > maximum)
		{
			maximum = data[i].getFitness();
			maxIndex = i;
		}
		temp[i] = temp[i-1] + data[i].getFitness() / sum;
	}
	//cout << "111" << endl;
	//cout << temp[size-1] << endl;
	double tempRandom = 0;
	CubeIndex index = -1;
	tempData.clear();

	tempData.push_back(data[maxIndex]);

	int num = 1;
  for(CubeIndex i = num; i < size; ++i)
	{
		if( rand()/double(RAND_MAX)<1.7 && data[i].getFitness()>average)
		//if(data[i].getFitness() > 1.5*average)
		{
			tempData.push_back(data[i]);
			++num;
		}
	}

  sort(data.begin(), data.end(), compare);
	for(CubeIndex i = num; i < size; ++i)
	{
		tempData.push_back(data[i-num]);
	}
	
	/*
	for(CubeIndex i = num; i < size; ++i)
	{
		tempRandom = rand() / double(RAND_MAX);
		for(int j = 0; j < size; ++j)
		{
			if(tempRandom < temp[j])
			{
				index = j;
				break;
			}
		}
		//cout << index << endl;

		tempData.push_back(data[index]);
		//cout << "222" << endl;
	}
	*/
	
	delete[] temp;
}

void Population::select()
{
	tempData.clear();
  sort(data.begin(), data.end(), compare);
	for(CubeIndex i = 0; i < size/5; ++i)
	{
		tempData.push_back(data[i]);
	}
	
	CubeIndex index1 = 0;
	CubeIndex index2 = 0;
	for(CubeIndex i = size/5; i < size; ++i)
	{
	  index1 = (rand() % (size-0)) + 0;
	  index2 = (rand() % (size-0)) + 0;
		if( rand()/double(RAND_MAX) < 
			data[index1].getFitness()/(data[index1].getFitness()+data[index2].getFitness()) )
		{
			tempData.push_back(data[index1]);
		}
		else
		{
			tempData.push_back(data[index2]);
		}
	}
	
}


void Population::update()
{
	//data.clear();
	//data = tempData;

	/*
	for(CubeIndex i = 0; i < size; ++i)
	{
		for(MatrixIndex j = 0; j < sizeMatrix; ++j)
		{
			for(ArrayIndex k = 0; k < sizeArray; ++k)
			{
		    cout << (data[i][j][k]-tempData[i][j][k]) << '\t';
			}
		}
	  cout << endl;

	}
	*/

	data.clear();
	data = Cube(tempData);
}
