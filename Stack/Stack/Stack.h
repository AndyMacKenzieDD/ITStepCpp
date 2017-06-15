#pragma once

template<typename T>
class Stack
{
	T *ptr;
	int head;
	int capacity;
public:
	Stack();
	Stack(const Stack&);
	Stack(Stack&&);
	~Stack();

	bool empty() const;
	int size() const;
	void push(const T&);
	void print() const;

	T pop();
	T top() const;

	Stack<T>& operator=(const Stack&);
	Stack<T>& operator=(Stack<T>&&);

	bool operator==(const Stack&) const;
	bool operator!=(const Stack&) const;
};

template<typename T>
Stack<T>::Stack() : head(0), capacity(2)
{
	ptr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
	delete [] ptr;
}

template<typename T>
bool Stack<T>::empty() const
{
	return !head;
}

template<typename T>
int Stack<T>::size() const
{
	return head;
}

template<typename T>
void Stack<T>::push(const T& newElement)
{
	if (head < capacity)
	{
		ptr[head] = newElement;
		++head;
	}
	else
	{
		capacity = capacity * 2;
		T *newPtr = new T[capacity];

		for (unsigned int i = 0; i < head; ++i)
		{
			newPtr[i] = ptr[i];
		}
		delete[]ptr;
		ptr = newPtr;

		ptr[head] = newElement;
		++head;
	}
}

template<typename T>
T Stack<T>::pop()
{
	if (!empty())
	{
		--head;
		return ptr[head];
	}
	/*
	if (!empty())
	{
		--head;
		return ptr[head];
	}
	else
	{
		std::cout << "ERROR: Stack is empty" << std::endl;
		exit(1);
	}
	*/
}

template<typename T>
T Stack<T>::top() const
{
	if (!empty())
	{
		return ptr[head - 1];
	}
}

template<typename T>
Stack<T>::Stack(const Stack<T>& obj) : head(obj.head), capacity(obj.capacity)
{
	ptr = new T[capacity];
	for (int i = 0; i < head; ++i)
	{
		ptr[i] = obj.ptr[i];
	}
}

template<typename T>
Stack<T>::Stack(Stack<T>&& obj) : head(obj.head), capacity(obj.capacity), ptr(obj.ptr)
{
	std::cout << "Ctor move" << std::endl;
	obj.head = 0;
	obj.capacity = 0;
	obj.ptr = nullptr;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	head = obj.head;
	capacity = obj.capacity;
	delete [] ptr;
	ptr = new T[capacity];

	for (int i = 0; i < head; ++i)
	{
		ptr[i] = obj.ptr[i];
	}

	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	head = obj.head;
	capacity = obj.capacity;
	delete [] ptr;
	ptr = obj.ptr;
	obj.size = 0;
	obj.capacity = 0;
	obj.ptr = nullptr;

	return *this;
}

template<typename T>
bool Stack<T>::operator==(const Stack& obj) const
{
	if (head != obj.head)
	{
		return false;
	}
	if (head == obj.head)
	{
		for (unsigned int i = 0; i < head; ++i)
		{
			if (ptr[i] != obj.ptr[i])
			{
				return false;
			}
		}
	}

	return true;
}

template<typename T>
bool Stack<T>::operator!=(const Stack& obj) const
{
	return !(*this == obj);
}

template<typename T>
void Stack<T>::print() const
{
	for (int i = 0; i < head; ++i)
	{
		std::cout << ptr[i] << " ";
	}
	std::cout << std::endl;
}