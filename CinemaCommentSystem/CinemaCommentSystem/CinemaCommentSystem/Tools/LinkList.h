#include <iostream>
#include "LinkNode.h"
using namespace std;

#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename T> class LinkList
{
public:
	// Ĭ�Ϲ��캯��
	LinkList()
	{
		pHead = NULL;
		pEnd = NULL;
		pCurrent = NULL;
		Count = 0;
	}
	// ��ʼ��һ��Ԫ�صĹ��캯��
	LinkList(T &element)
	{
		pHead = new LinkNode<T>(element);
		pEnd = pHead;
		pCurrent = pHead;
		Count = 1;
	}
	// �������캯��
	LinkList(const LinkList<T> &list)
	{
		this->Clear();
		while (this->Count < list.Count)
		{
			// �������ݵĿ������캯��
			T *newData = new T(*list.Get(this->Count));
			this->Add(*newData);
		}
	}
	// ��������
	~LinkList<T>()
	{
		this->Clear();
	}

private:
	LinkNode<T> *pHead;
	LinkNode<T> *pEnd;
	LinkNode<T> *pCurrent;
public:
	int Count;

private:
	inline bool IndexTest(const int &index){ return index >= 0 && index < Count ? true : false; }
	void Add(LinkNode<T> *node)
	{
		if (NULL == pHead)
			pHead = node;
		if (NULL == pEnd)
			pEnd = pHead;
		else
		{
			pEnd->SetNext(node);
			pEnd = pEnd->PNext();
		}
		++Count;
	}
public:
	// ������ĩβ����һ��Ԫ��
	void Add(const T &element)
	{
		LinkNode<T> *newNode = new LinkNode<T>(element);
		this->Add(newNode);
	}
	// ��indexλ�ò���һ��Ԫ��
	void Insert(const int &index, const T &element)
	{
		if (!(index >= 0 && index <= Count))
		{
			cout << "!warning: ���Բ���λ��[" << index << "]Ԫ��ʧ��" << endl;
			return;
		}
		LinkNode<T> *newNode = new LinkNode<T>(element);
		pCurrent = pHead;
		LinkNode<T> *pPrevious = pCurrent;
		int i = 0;
		while (i < index)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->PNext();
			++i;
		}
		if (index == 0)
		{
			newNode->SetNext(pHead);
			pHead = newNode;
		}
		else if (index == Count)
		{
			pEnd->SetNext(newNode);
			pEnd = newNode;
		}
		else
		{
			pPrevious->SetNext(newNode);
			newNode->SetNext(pCurrent);
		}
		++Count;
	}

	// �Ƴ������ƥ�������Ԫ��
	void Remove(const T &element)
	{
		while (Contains(element))
		{
			int index = this->Find(element);
			if (index > 0)
			{
				RemoveAt(index);
			}
		}
	}
	// �Ƴ���Ӧλ�õ�Ԫ��
	void RemoveAt(const int &index)
	{
		if (Count <= 0)
			return;
		if (!this->IndexTest(index))
		{
			cout << "!warning: �����Ƴ�λ��[" << index << "]Ԫ��ʧ��" << endl;
			return;
		}

		int i = 0;
		pCurrent = pHead;
		LinkNode<T> *pPrevious = pCurrent;
		while (i < index)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->PNext();
			++i;
		}
		if (index == 0)
		{
			pHead = pHead->PNext();
		}
		else if (index == Count - 1)
		{
			pEnd = pPrevious;
			pPrevious->SetNextNull();
		}
		else
		{
			pPrevious->SetNext(pCurrent->PNext());
		}
		delete pCurrent;
		--Count;
	}

	// �ж��Ƿ����ĳ��Ԫ��
	bool Contains(const T &element)
	{
		if (Count <= 0)
			return false;
		pCurrent = pHead;
		while (NULL != pCurrent)
		{
			if (element == pCurrent->Data())
				return true;
			else
				pCurrent = pCurrent->PNext();
		}
		return false;
	}
	// Ѱ�ҵ���һ��ĳ��Ԫ�ز�������λ��
	int Find(const T &element)
	{
		if (Count <= 0)
			return false;
		int i = 0;
		pCurrent = pHead;
		while (i < this->Count)
		{
			if (element == pCurrent->Data())
				break;
			pCurrent = pCurrent->PNext();
			++i;
		}
		return i == this->Count ? -1 : i;
	}
	// ���ĳ��λ�õ�Ԫ��
	T *Get(const int &index)
	{
		if (Count <= 0)
			return NULL;
		if (!this->IndexTest(index))
		{
			cout << "!warning: ���Է���λ��[" << index << "]Ԫ��ʧ��" << endl;
			return NULL;
		}

		int i = 0;
		pCurrent = pHead;
		while (i < index)
		{
			pCurrent = pCurrent->PNext();
			++i;
		}
		return &pCurrent->Data();
	}

	// �޸�ĳ��λ�õ�Ԫ��
	void ModifyAt(int index, const T &element)
	{
		if (Count <= 0)
			return;
		if (!this->IndexTest(index))
		{
			cout << "!warning: �����޸�λ��[" << index << "]Ԫ��ʧ��" << endl;
			return;
		}
		pCurrent = pHead;
		for (int i = 0; i < index; ++i)
		{
			pCurrent = pCurrent->PNext();
		}
		pCurrent->SetData(element);
	}

	// �����������
	void Clear()
	{
		while (Count > 0)
		{
			this->RemoveAt(0);
		}
	}

	LinkNode<T> Head(){ return *pHead; }
	LinkNode<T> End(){ return *pEnd; }

	friend ostream &operator<<(ostream &out, LinkList<T> &list)
	{
		if (list.Count == 0)
		{
			cout << "listΪ��"; 
			return out;
		}
		for (int i = 0; i < list.Count; ++i)
		{
			cout << *list.Get(i);
			if (i != list.Count - 1)
				cout << "��";
		}
		return out;
	}
};

#endif