//Week.h

#ifndef _WEEK_H_
#define _WEEK_H_

#include "common.h"

class Week
{
public:
  Week(ArrayIndex size_);
	~Week();

  void print();

  int &operator[](size_t index);
  Array& getData();

protected:

private:
  Array data;


};

#endif
