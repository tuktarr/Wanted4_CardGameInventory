#pragma once

template <typename T>
class Vector
{
public:
	Vector() : data(nullptr), size(0), capacity(0)
	{
		capacity = 100;
		data = new T[capacity];
	}

	~Vector()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
	}

private:
	T* data;
	int size;
	int capacity;
};

