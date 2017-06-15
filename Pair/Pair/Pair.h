#pragma once

template<typename T, typename U>
class Pair
{
	T f;
	U s;
public:
	Pair() : f(NULL), s(NULL)
	{
	}

	Pair(const T newF, const U newS) : f(newF), s(newS)
	{
	}
	~Pair() = default;

	T first() const;
	U second() const;
	static Pair<T, U> make_pair(const T, const U);
};

template<>
class Pair <bool, bool>
{
	bool f;
	bool s;
public:
	Pair() : f(false), s(false)
	{
	}

	Pair(const bool newF, const bool newS) : f(newF), s(newF)
	{
	}
	~Pair() = default;

	bool first() const;
	bool second() const;
	static Pair make_pair(const bool a, const bool b)
	{
		return Pair(a, a);
	}
};

template<typename T, typename U>
T Pair<T, U>::first() const
{
	return f;
}

template<typename T, typename U>
U Pair<T, U>::second() const
{
	return s;
}

template<typename T, typename U>
Pair<T, U> Pair<T, U>::make_pair(const T newF, const U newS)
{
	return Pair(newF, newS);
}

bool Pair<bool, bool>::first() const
{
	return f;
}

bool Pair<bool, bool>::second() const
{
	return s;
}