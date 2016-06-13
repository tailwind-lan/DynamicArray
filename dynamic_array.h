#include <algorithm>

template <typename T>
class Dynamic1d
{
public:
	Dynamic1d(int n = 0);
	Dynamic1d(int n, const T &value);
	Dynamic1d(const Dynamic1d<T> &obj);
	~Dynamic1d() { delete []x; }

	int size() const { return sz; }
	Dynamic1d<T> &operator = (const Dynamic1d<T> &obj);
	T &operator [](int i) { return x[i]; }
	const T &operator [](int i) const { return x[i]; }
private:
	void swap(Dynamic1d<T> &obj)
	{
		std::swap(sz, obj.sz);
		std::swap(x, obj.x);
	}

private:
	T *x;
	int sz;
};

template <typename T>
class Dynamic2d : public Dynamic1d<Dynamic1d<T> >
{
public:
	Dynamic2d(int rows = 0, int cols = 1);
	Dynamic2d(int rows, int cols, const T &value);
};
