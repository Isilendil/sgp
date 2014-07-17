//common.h

#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
//#include <cmath>

class Week;
class Schedule;
class Population;
const double e = 2.71828;

typedef std::vector<int> Array;
typedef std::vector<int>::size_type ArrayIndex;

typedef std::vector<Week> Matrix;
typedef std::vector<Week>::size_type MatrixIndex;

typedef std::vector<Schedule> Cube;
typedef std::vector<Schedule>::size_type CubeIndex;

#include "utility.h"
#include "Week.h"
#include "Schedule.h"
#include "Population.h"

#endif 
