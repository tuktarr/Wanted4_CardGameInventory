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

public:
	void Push_back(const T& value)
	{
		if (size == capacity)
		{
			Resize(capacity * 2);
		}

		data[size] = value;
		size++;
	}

	T& operator[](int index)
	{
		return data[index];
	}

	int GetSize() const { return size; }

private:
	void Resize(int newCapacity)
	{
		T* newData = new T[newCapacity];
		for (int i = 0; i < size; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

private:
	T* data;
	int size;
	int capacity;
};

