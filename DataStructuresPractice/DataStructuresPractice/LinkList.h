#pragma once
template<typename type>
class LinkedListIter;

template<typename type>
class LinkedList
{
	friend LinkedListIter;
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

	void Remove(LinkedListIter* itr);
	void Insert(LinkedListIter* itr);
};

template<typename type>
class LinkedListIter
{
	friend LinkedList;
	LinkedList<type> * m_list;
	LinkedList<type>::node* m_curr, *m_prev;

public:
	LinkedListIter(LinkedList* l)
	{
		m_list = l;
	}
	~LinkedListIter(){}

	void operator++()
	{
		m_prev = m_curr;
		m_curr = m_curr->next;
	}

	const type const current() { return m_curr->data; }
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

template<typename type>
void LinkedList<type>::Remove(LinkedListIter * itr)
{
	m_prev->next = m_curr->next;
	delete m_curr;
	m_curr = m_prev->next;
}

template<typename type>
void LinkedList<type>::Insert(LinkedListIter * itr, type data)
{
	node* n = new node();
	n->data = data;
	m_prev->next = n;
	n->next = m_curr;
	m_curr = n;
}
