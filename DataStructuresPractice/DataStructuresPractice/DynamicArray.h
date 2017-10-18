#pragma once
template<typename type>
class DynamicArray
{
	type* data=nullptr;
	unsigned int m_Size = 0;
	unsigned int m_Capacity = 0;
	void resize();
public:
	DynamicArray();
	DynamicArray(unsigned int size);
	~DynamicArray() { clear(); }
	const unsigned int size() { return m_Size; }
	const unsigned int capacity() { return m_Capacity; }
	void pushBack(type data);
	void reserve(unsigned int size);
	type operator[](unsigned int i)
	{
		//if(i < m_Size)
			return data[i];
		/*else
			assert();*/
	}
	void clear()
	{
		delete data;
		data = nullptr;
		m_Size = m_Capacity = 0;
	}
};

template<typename type>
inline void DynamicArray<type>::resize()
{
	type* temp = data;
	data = new type[m_Capacity * 2];
	memcpy_s(data, sizeof(type)*m_Capacity, temp, sizeof(type)*m_Capacity);
	m_Capacity *= 2;
	delete temp;
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
		data = new type[1];
		m_Capacity = 1;
	}
	else if (m_Size >= m_Capacity)
	{
		resize();
	}
	data[m_Size] = value;
	m_Size++;
}

template<typename type>
void DynamicArray<type>::reserve(unsigned int size)
{
	if (size > m_Capacity)
	{
		type * temp = data;
		data = new type[size];
	}
}
