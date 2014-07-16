//Week.cpp

#include "Week.h"

using namespace std;

Week::Week(ArrayIndex size_)
{
	data = Array(size_);
	randomArray(data);

}

Week::~Week()
{
}

void Week::print()
{
	ArrayIndex size = data.size();
	for(ArrayIndex i = 0; i < size; ++i)
	{
		cout << data[i] << '\t';
	}
  cout << '\n';
}

int& Week::operator[](size_t index)
{
	return data[index];
}

Array& Week::getData()
{
	return data;
}
