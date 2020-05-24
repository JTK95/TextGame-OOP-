#pragma once
#include "stdafx.h"

//------------------------------
// MY STL
//------------------------------
template <typename T>
class CList
{
public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	class CIterator
	{
	public:
		// ���ڷ� ���� Node �����͸� ����
		CIterator(Node* node = nullptr)
			:node(node)
		{}

		// ���� ��带 ���� ���� �̵� (����)
		CIterator& operator++()
		{
			this->node = this->node->next;

			return *this;
		}

		// (����)
		CIterator& operator++(int)
		{
			CIterator temp = this->node;
			this->node = this->node->next;

			return temp;
		}

		CIterator& operator--()
		{
			this->node = this->node->prev;

			return *this;
		}

		CIterator& operator--(int)
		{
			CIterator temp = this->node;
			this->node = this->node->prev;

			return *this;
		}

		bool operator==(const CIterator& iter)
		{
			return this->node == iter.node;
		}

		bool operator!=(const CIterator& iter) const
		{
			return this->node != iter.node;
		}

		// ���� ����� �����͸� ����
		T& operator*() const
		{
			return this->node->data;
		}

		// ��� ��ȯ
		Node* getNode()
		{
			return this->node;
		}

		Node* operator->() const
		{
			return this->node;
		}

		/*T operator->()
		{
			return this->node->data;
		}*/

	private:
		Node* node;
	};


public:
	// List �ʱ�ȭ
	CList()
		:nodeCount(0)
	{
		this->head.data = 0;
		this->head.prev = nullptr;
		this->head.next = &(this->tail);
		
		this->tail.data = 0;
		this->tail.prev = &(this->head);
		this->tail.next = nullptr;
	}

	~CList()
	{}

	// ù��° ��带 ����Ű�� CIterator ����
	CIterator begin()
	{
		CIterator begin(this->head.next);

		return begin;
	}

	// �ǳ� ��带 ����Ű�� CIterator ����
	CIterator end()
	{
		CIterator end(&(this->tail));

		return end;
	}

	// �� �� ��� �߰�
	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		(this->nodeCount)++;

		newNode->prev = &(this->head);
		newNode->next = this->head.next;
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		(this->nodeCount)++;

		newNode->prev = this->tail.prev;
		newNode->next = &(this->tail);
		newNode->prev->next = newNode;
		newNode->next->prev = newNode;
	}

	void pop_front()
	{
		Node* pNode = this->head.next;

		if (pNode != &(this->tail))
		{
			pNode->data = 0;
			(this->nodeCount)--;

			pNode->next->prev = &(this->head);
			pNode->prev->next = pNode->next;

			delete pNode;
		}
	}

	void pop_back()
	{
		Node* pNode = this->tail.prev;

		if (pNode != &(this->head))
		{
			pNode->data = 0;
			(this->nodeCount)--;

			pNode->next->prev = pNode->prev;
			pNode->prev->next = &(this->tail);

			delete pNode;
		}
	}

	/*void remove(T Data)
	{
		CList<T>::CIterator iter;
		for (iter = ListInt.begin(); iter != ListInt.end(); ++iter)
		{
			if (*iter == Data)
				erase(iter);
		}
	}*/

	// ���� ��� �α׸� �����
	void clear()
	{
		while (this->nodeCount != 0)
		{
			pop_front();
		}
	}

	// ��� ����
	int size() const
	{
		return this->nodeCount;
	}

	// CIterator�� �� ��带 ���� �׸��� ���� ����� ���� ��带 ����Ű�� �ϴ� CIterator ����
	CIterator erase(CIterator iter)
	{
		CIterator temp = iter;
		Node* pNode = temp.getNode();
		temp++;

		pNode->data = 0;
		pNode->next->prev = pNode->prev;
		pNode->prev->next = pNode->next;
		delete pNode;

		return temp;
	}

private:
	int nodeCount;
	Node head;
	Node tail;
};

