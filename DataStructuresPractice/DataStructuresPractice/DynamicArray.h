#pragma once
template<typename type>
class DynamicArray
{
	type* data=nullptr;
	unsigned int size = 0;
	unsigned int capacity = 0;
	void resize();
public:
	DynamicArray();
	DynamicArray(unsigned int size);
	void pushBack(type data);
	void reserve(unsigned int size);
};

template<typename type>
inline void DynamicArray<type>::resize()
{
}

template<typename type>
inline DynamicArray<type>::DynamicArray()
{
	//data = new type[1];
}

template<typename type>
DynamicArray<type>::DynamicArray(unsigned int size)
{
	data = new type[size];
}

template<typename type>
void DynamicArray<type>::pushBack(type value)
{
	if (!data)
	{
		deta = new type[1];
		size = capacity = 1;
	}
	data[size] = value;
}

template<typename type>
void DynamicArray<type>::reserve(unsigned int size)
{
	if (size > capacity)
	{
		type * temp = data;
		data = new type[size];
	}
}
