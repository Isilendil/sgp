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
		//cout << i << endl;
		for(ArrayIndex j = 0; j < sizeArray; j+=3)
		{
			//cout << j << endl;
			int x = array[j] - 1;
			int y = array[j+1] - 1;
			int z = array[j+2] - 1;

			int max_;
			int min_;
			int &max = max_;
			int &min = min_;

      mySort(x, y, max, min);
		  count += (++(table[max][min]));
      mySort(x, z, max, min);
		  count += (++(table[max][min]));
      mySort(y, z, max, min);
		  count += (++(table[max][min]));
			//cout << j << endl;
		}
	}
	
	/*
	for(int i = 0; i < sizeArray; ++i)
	{
		for(int j = 0; j < sizeArray; ++j)
		{
			cout << table[i][j] << '\t';
		}
		cout << '\n';
	}
  cout << count << endl;
	*/

	//cout << count << endl;
  //fitness = 315-(count-(sizeArray*(sizeArray-1)/2));
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
