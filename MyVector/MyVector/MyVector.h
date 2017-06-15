#pragma once

template<typename T>
class MyVector
{
	T *ptr;
	unsigned int size;
	unsigned int capacity;
	static unsigned int objectCounter;
	static unsigned int currentObjectCounter;
public:
	MyVector();
	MyVector(T *arr, unsigned int size);
	MyVector(const MyVector& newClass);
	MyVector(MyVector&& newClass);
	~MyVector();
	bool empty() const;
	unsigned int get_size() const;
	unsigned int get_capacity() const;
	void push_back(const T);
	T pop_back();
	T& at(unsigned const int) const;
	void print() const;
	T get_min() const;
	T get_max() const;
	unsigned int getCurrentObjectCounter() const;
	unsigned int getObjectCounter() const;
	MyVector& operator=(const MyVector&);
	MyVector& operator=(MyVector&&);
	bool operator>(const MyVector&) const;
	bool operator<(const MyVector&) const;
	bool operator==(const MyVector&) const;
	bool operator!=(const MyVector&) const;
	bool operator>=(const MyVector&) const;
	bool operator<=(const MyVector&) const;
	T& operator[](int) const;
	void clear();
	void reserve(int);
	void insert(const int, const unsigned int);
	void resize(const unsigned int);
	void resize(const unsigned int, const int);
};

template<typename T>
unsigned int MyVector<T>::objectCounter = 0;
template<typename T>
unsigned int MyVector<T>::currentObjectCounter = 0;

template<typename T>
MyVector<T>::MyVector() : capacity(32), size(0)
{
	++objectCounter;
	++currentObjectCounter;
	ptr = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(T *arr, unsigned int newSize) : size(newSize), capacity(32)
{
	++objectCounter;
	++currentObjectCounter;
	while (capacity < newSize)
	{
		capacity *= 2;
	}

	ptr = new T[capacity];

	for (unsigned int i = 0; i < size; ++i)
	{
		ptr[i] = arr[i];
	}
}

template<typename T>
MyVector<T>::MyVector(const MyVector& Class) : size(Class.size), capacity(Class.capacity)
{
	++objectCounter;
	++currentObjectCounter;
	ptr = new T[capacity];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = Class.ptr[i];
	}
}

template<typename T>
MyVector<T>::MyVector(MyVector&& Class) : size(Class.size), capacity(Class.capacity), ptr(Class.ptr)
{
	//std::cout << "Ctor move" << std::endl;
	Class.size = 0;
	Class.capacity = 0;
	Class.ptr = nullptr;
}

template<typename T>
MyVector<T>::~MyVector()
{
	--currentObjectCounter;
	delete[] ptr;
}

template<typename T>
bool MyVector<T>::empty() const
{
	return size == 0;
}

template<typename T>
unsigned int MyVector<T>::get_size() const
{
	return size;
}

template<typename T>
unsigned int MyVector<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
void MyVector<T>::push_back(const T newElement)
{
	if (size < capacity)
	{
		ptr[size] = newElement;
		++size;
	}
	else
	{
		capacity = capacity * 2;
		T *newPtr = new T[capacity];

		for (unsigned int i = 0; i < size; ++i)
		{
			newPtr[i] = ptr[i];
		}
		delete[]ptr;
		ptr = newPtr;

		ptr[size] = newElement;
		++size;
	}
}

template<typename T>
T MyVector<T>::pop_back()
{
	if (!empty())
	{
		--size;
		return ptr[size];
	}
	else
	{
		std::cout << "ERROR: Vector is empty" << std::endl;
		exit(1);
	}
}

template<typename T>
T& MyVector<T>::at(unsigned const int index) const
{
	if (index < size)
	{
		return ptr[index];
	}
	else
	{
		//std::cout << "ERROR: out of range" << std::endl;
		return ptr[0];
	}
}

template<typename T>
void  MyVector<T>::print() const
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << ptr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
T MyVector<T>::get_min() const
{
	T min = ptr[0];
	for (unsigned int i = 0; i < size; ++i)
	{
		if (ptr[i] < min)
		{
			min = ptr[i];
		}
	}
	return min;
}

template<typename T>
T MyVector<T>::get_max() const
{
	T max = ptr[0];
	for (unsigned int i = 0; i < size; ++i)
	{
		if (ptr[i] > max)
		{
			max = ptr[i];
		}
	}
	return max;
}

template<typename T>
unsigned int MyVector<T>::getCurrentObjectCounter() const
{
	return currentObjectCounter;
}

template<typename T>
unsigned int MyVector<T>::getObjectCounter() const
{
	return objectCounter;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& Class)
{
	++objectCounter;
	++currentObjectCounter;
	if (this == &Class)
	{
		return *this;
	}

	size = Class.size;
	capacity = Class.capacity;
	ptr = new T[capacity];

	for (int i = 0; i < size; ++i)
	{
		ptr[i] = Class.ptr[i];
	}

	return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& Class)
{
	++objectCounter;
	++currentObjectCounter;
	if (this == &Class)
	{
		return *this;
	}

	size = Class.size;
	capacity = Class.capacity;
	ptr = Class.ptr;
	Class.size = 0;
	Class.capacity = 0;
	Class.ptr = nullptr;

	return *this;
}

template<typename T>
bool MyVector<T>::operator>(const MyVector& Class) const
{
	int minSize;
	size < Class.size ? minSize = size : minSize = Class.size;
	for (unsigned int i = 0; i < minSize; ++i)
	{
		if (ptr[i] != Class.ptr[i])
		{
			if (ptr[i] > Class.ptr[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

template<typename T>
bool MyVector<T>::operator<(const MyVector& Class) const
{
	int minSize;
	size < Class.size ? minSize = size : minSize = Class.size;
	for (unsigned int i = 0; i < minSize; ++i)
	{
		if (ptr[i] != Class.ptr[i])
		{
			if (ptr[i] < Class.ptr[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

template<typename T>
bool MyVector<T>::operator==(const MyVector& Class) const
{
	if (size != Class.size)
	{
		return false;
	}
	if (size == Class.size) //else
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			if (ptr[i] != Class.ptr[i])
			{
				return false;
			}
		}
	}

	return true;
}

template<typename T>
bool MyVector<T>::operator!=(const MyVector& Class) const
{
	if (size != Class.size)
	{
		return true;
	}
	if (size == Class.size) //else
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			if (ptr[i] != Class.ptr[i])
			{
				return true;
			}
		}
	}

	return false;
}

template<typename T>
bool MyVector<T>::operator>=(const MyVector& Class) const
{
	int minSize;
	size < Class.size ? minSize = size : minSize = Class.size;
	for (unsigned int i = 0; i < minSize; ++i)
	{
		if (ptr[i] < Class.ptr[i])
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool MyVector<T>::operator<=(const MyVector& Class) const
{
	int minSize;
	size < Class.size ? minSize = size : minSize = Class.size;
	for (int i = 0; i < minSize; ++i)
	{
		if (ptr[i] > Class.ptr[i])
		{
			return false;
		}
	}

	return true;
}

template<typename T>
T& MyVector<T>::operator[](int index) const
{
	return ptr[index];
}

template<typename T>
void MyVector<T>::clear()
{
	size = 0;
}

template<typename T>
void MyVector<T>::reserve(int cap)
{
	capacity = cap;
	size = capacity;

	T *newPtr = new T[capacity];

	for (unsigned int i = 0; i < size; ++i)
	{
		newPtr[i] = ptr[i];
	}
	delete[]ptr;
	ptr = newPtr;
}

template<typename T>
void MyVector<T>::insert(const int newElement, const unsigned int index)
{
	if (index < 0 || index > size)
	{
		return;
	}

	if (size < capacity)
	{
		for (unsigned int i = size; i > index; --i)
		{
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = newElement;
		++size;
	}
	else
	{
		capacity = capacity * 2;
		T *newPtr = new T[capacity];

		for (unsigned int i = 0; i < index; ++i)
		{
			newPtr[i] = ptr[i];
		}

		newPtr[index] = newElement;
		++size;

		for (unsigned int i = index + 1; i < size; ++i)
		{
			newPtr[i] = ptr[i - 1];
		}

		delete[]ptr;
		ptr = newPtr;	
	}
}

template<typename T>
void MyVector<T>::resize(const unsigned int newSize)
{
	if (newSize <= size)
	{
		size = newSize;
		return;
	}

	while (capacity < newSize)
	{
		capacity *= 2;
	}

	T *newPtr = new T[capacity];

	for (unsigned int i = 0; i < size; ++i)
	{
		newPtr[i] = ptr[i];
	}

	delete[]ptr;
	ptr = newPtr;

	for (unsigned int i = size; i < newSize; ++i)
	{
		ptr[i] = 0;
	}
	size = newSize;
}

template<typename T>
void MyVector<T>::resize(const unsigned int newSize, const int newElement)
{
	if (newSize <= size)
	{
		size = newSize;
		return;
	}

	while (capacity < newSize)
	{
		capacity *= 2;
	}

	T *newPtr = new T[capacity];

	for (unsigned int i = 0; i < size; ++i)
	{
		newPtr[i] = ptr[i];
	}

	delete[]ptr;
	ptr = newPtr;

	for (unsigned int i = size; i < newSize; ++i)
	{
		ptr[i] = newElement;
	}
	size = newSize;
}