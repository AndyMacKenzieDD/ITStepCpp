#pragma once
#include <exception>

template <typename T>
class ForwardList {
	struct node {
		T data;
		node* next = nullptr;
	};
	node* head = nullptr;
	node* tail = nullptr;
	size_t list_size = 0;
	
public:
	ForwardList() = default;
	~ForwardList()
	{
		auto it = head;
		for (int i = 0; i < list_size; ++i)
		{
			auto tmp = it;
			it = it->next;
			delete tmp;
		}
	}

	size_t size() const;
	bool empty() const;
	void push_back(const T& );
	void push_front(const T&);
	bool insert(const T&, const T&);	
	T pop_back();
	T pop_front();
	bool erase(const T&);	
	void print();
private:
	node* create_node(const T&);
	void create_first_node(const T&);
	node* find_node(const T&);
	node* find_previous_node(const T&);
};

template <class T>
size_t ForwardList<T>::size() const
{
	return list_size;
}

template <class T>
bool ForwardList<T>::empty() const
{
	return !list_size;
}

template <class T>
void ForwardList<T>::push_back(const T& a)
{
	if (empty())
	{
		create_first_node(a);
	}
	else
	{
		node* newElem = create_node(a);
		tail->next = newElem;
		tail = newElem;
	}
	++list_size;
}

template <class T>
void ForwardList<T>::push_front(const T& a)
{
	if (empty())
	{
		create_first_node(a);
	}
	else
	{
		node* newElem = create_node(a);
		newElem->next = head;
		head = newElem;
	}
	++list_size;
}

template <class T>
bool ForwardList<T>::insert(const T& a, const T& pos)
{
	node* newElem = create_node(a);
	node* cur = find_node(pos);
	if (!cur)
	{
		return false;
	}
	else if (!cur->next)
	{
		push_back(a);
	}
	else
	{
		newElem->next = cur->next;
		cur->next = newElem;
		++list_size;
	}
	return true;
}

template <class T>
T ForwardList<T>::pop_back()
{
	if (empty())
	{
		throw std::logic_error("List is empty");
	}
	auto it = head;
	auto prev = head;
	for (int i = 0; i < list_size - 1; ++i)
	{
		prev = it;
		it = it->next;
	}

	T ret = it->data;
	delete it;
	tail = prev;
	prev->next = nullptr;
	--list_size;
	return ret;
}

template <class T>
T ForwardList<T>::pop_front()
{
	if (empty())
	{
		throw std::logic_error("List is empty");	
	}
	auto tmp = head;
	T ret = head->data;
	head = head->next;
	delete tmp;
	--list_size;
	return ret;
}

template <class T>
bool ForwardList<T>::erase(const T& a)
{
	if (empty())
	{
		throw std::logic_error("List is empty");
	}
	auto it = find_node(a);
	node* prev;
	if (it == head)
	{
		pop_front();
		return true;
	}
	else
	{
		prev = find_previous_node(a);
		if (!prev)
		{
			return false;
		}
		else if (prev->next == nullptr)
		{
			pop_back();
		}
		prev->next = it->next;
		--list_size;
	}
	delete it;
	return true;
}

template <class T>
void ForwardList<T>::print()
{
	auto it = head;
	for (int i = 0; i < list_size; ++i)
	{
		std::cout << it->data << " ";
		it = it->next;
	}
	std::cout << std::endl;
}

template <class T>
typename ForwardList<T>::node* ForwardList<T>::create_node(const T& a)
{
	node* newElem = new node;
	newElem->data = a;
	return newElem;
}

template <class T>
void ForwardList<T>::create_first_node(const T& a)
{
	node* newElem = new node;
	newElem->data = a;
	tail = newElem;
	head = newElem;
}

template <class T>
typename ForwardList<T>::node* ForwardList<T>::find_node(const T& a)
{
	auto it = head;

	for (int i = 0; i < list_size; ++i)
	{
		if (it->data == a)
		{
			return it;
		}
		it = it->next;
	}

	return nullptr;
}

template <class T>
typename ForwardList<T>::node* ForwardList<T>::find_previous_node(const T& a)
{

	auto it = head;
	auto prev = head;

	for (int i = 0; i < list_size; ++i)
	{
		if (it->data == a)
		{
			return prev;
		}
		prev = it;
		it = it->next;
	}

	return nullptr;
}