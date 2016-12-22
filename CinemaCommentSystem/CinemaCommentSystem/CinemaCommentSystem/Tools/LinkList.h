#include "LinkNode.h"
using namespace std;

#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename T> class LinkList
{
public:
	LinkList()
	{
		this->pHead = null;
		this->pEnd = null;
		this->pCurrent = null;
		this->Count = 0;
	}
	LinkList(T &element)
	{
		this->pHead = new LinkNode<T>(element);
		this->pEnd = pHead;
		this->pCurrent = pHead;
		this->Count = 1;
	}
	LinkList(LinkList<T> &list)
	{
		this->Clear();
		*this = list;
	}
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


public:
	void Add(const T &element);		// ������ĩβ����һ��Ԫ��
	void Insert(const int index, const T &element);// ��indexλ�ò���һ��Ԫ��

	void Remove(const T &element);	// �Ƴ������ƥ���Ԫ��
	void RemoveAt(const int index);	// �Ƴ���Ӧλ�õ�Ԫ��

	bool Contains(const T &element);// �ж��Ƿ����ĳ��Ԫ��
	int Find(const T &element);		// Ѱ�ҵ�ĳ��Ԫ�ز�������λ��

	void Clear();					// �����������

	T & operator [](const int index);	// �����±������
	LinkList<T> & operator = (const LinkList<T> &list);// ���ظ�ֵ�����
};

#endif