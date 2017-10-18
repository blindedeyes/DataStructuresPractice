#pragma once

template<typename type>
class LinkedList
{
	struct node
	{
		type data;
		node* next=nullptr;
	};

	node * m_Head=nullptr, m_Tail=nullptr;
	unsigned int m_Count=nullptr;
public:
	LinkedList() {}
	~LinkedList() { clear(); }

	//stack like behavior
	void AddHead(type data);
	//queue like behavior
	void AddTail(type data);
	type PopHead();

	void Clear();

	const unsigned int Count();
};

template<typename type>
inline void LinkedList<type>::AddHead(type data)
{
	node * temp = new node();
	temp->data = data;
	if (!m_Head)
	{
		m_Head = m_Tail = temp;
	}
	else
	{
		temp->next = m_Head;
		m_Head = temp;
	}
}

template<typename type>
inline void LinkedList<type>::AddTail(type data)
{
	node * temp = new node();
	temp->data = data;
	if (!m_Head)
	{
		m_Head = m_Tail = temp;
	}
	else
	{
		m_Tail->next = temp;
		m_Tail = temp;
	}
}

template<typename type>
inline type LinkedList<type>::PopHead()
{
	return type();
}

template<typename type>
inline void LinkedList<type>::Clear()
{
	node* temp;
	while (m_Head)
	{
		temp = m_Head->next;
		delete m_Head;
		m_Head = temp;
	}
	m_Head = nullptr;
}

template<typename type>
inline const unsigned int LinkedList<type>::Count()
{
	return m_Count;
}
