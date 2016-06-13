#include "dynamic_array.h"

template <typename T>
Dynamic1d<T>::Dynamic1d(int n)
{
	sz = n;
	x = new T[sz];
}

template <typename T>
Dynamic1d<T>::Dynamic1d(int n, const T &value)
{
	sz = n;
	x = new T[sz];
	*x = value;
}

template <typename T>
Dynamic1d<T>::Dynamic1d(const Dynamic1d<T> &obj)
{
	sz = obj.size();
	x = new T[sz];
	for (int i = 0; i < sz; ++i)
		x[i] = obj.x[i];
}

template <typename T>
Dynamic1d<T> &Dynamic1d<T>::operator = (const Dynamic1d<T> &obj)
{
	if (this == &obj)
		return *this;

	if (obj.size() == size())
	{
		for (int i = 0; i < size(); ++i)
			(*this).x[i] = obj.x[i];
	}
	else
	{
		Dynamic1d<T> cp(obj);
		(*this).swap(cp);
	}

	return *this;
}

template <typename T>
Dynamic2d<T>::Dynamic2d(int rows, int cols) : Dynamic1d<Dynamic1d<T> >(rows, Dynamic1d<T>(cols))
{

}

template <typename T>
Dynamic2d<T>::Dynamic2d(int rows, int cols, const T &value) : Dynamic1d<Dynamic1d<T> >(rows, Dynamic1d<T>(cols, value))
{

}

int main()
{
	return 0;
}
