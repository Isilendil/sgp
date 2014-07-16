//Schedule.cpp

#include "Schedule.h"

using namespace std;

Schedule::Schedule(MatrixIndex sizeMatrix_, ArrayIndex sizeArray_)
  : sizeMatrix(sizeMatrix_), sizeArray(sizeArray_)
{
	data = Matrix();
	for(MatrixIndex i = 0; i < sizeMatrix_; ++i)
	{
		data.push_back(Week(sizeArray_));
	}
	for(vector<Array>::size_type i = 0; i < sizeArray; ++i)
	{
		table.push_back(Array(sizeArray));
	}
}

Schedule::~Schedule()
{
}

double Schedule::getFitness()
{
	return fitness;
}

void Schedule::computeFitness()
{
	for(int i = 0; i < sizeArray; ++i)
	{
		for(int j = 0; j < sizeArray; ++j)
		{
			table[i][j] = 0;
		}
	}
	int count = 0;
	for(MatrixIndex i = 0; i < sizeMatrix; ++i)
	{
		Array &array = data[i].getData();
		cout << i << endl;
		for(ArrayIndex j = 0; j < sizeArray; j+=3)
		{
			cout << j << endl;
		  count += (++table[array[j]-1][array[j+1]-1]);
		  count += (++table[array[j]-1][array[j+2]-1]);
		  count += (++table[array[j+1]-1][array[j+2]-1]);
			cout << j << endl;
		}
	}
	
	for(int i = 0; i < sizeArray; ++i)
	{
		for(int j = 0; j < sizeArray; ++j)
		{
			cout << table[i][j] << '\t';
		}
		cout << '\n';
	}
  cout << count << endl;

  fitness = 1.0 / (count - (sizeArray*(sizeArray-1)/2) + 1);
}

void Schedule::print()
{
	MatrixIndex size = data.size();
	for(MatrixIndex i = 0; i < size; ++i)
	{
		data[i].print();
	}
	cout << endl;
}

Week& Schedule::operator[](size_t index)
{
	return data[index];
}

Matrix& Schedule::getData()
{
	return data;
}
