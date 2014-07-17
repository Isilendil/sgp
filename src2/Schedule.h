//Schedule.h

#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_

#include "common.h"

class Schedule
{
public:
  Schedule(MatrixIndex sizeMatrix_, ArrayIndex sizeArray_);
	~Schedule();

  double getFitness();
	void computeFitness();

	void print();

  Week& operator[](size_t index);
	Matrix& getData();

protected:

private:
  double fitness;
	Matrix data;

	MatrixIndex sizeMatrix;
	ArrayIndex sizeArray;

	std::vector<Array> table;


};

#endif
