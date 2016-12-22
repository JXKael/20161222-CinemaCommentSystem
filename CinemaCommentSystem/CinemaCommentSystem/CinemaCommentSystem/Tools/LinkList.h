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
	void Add(const T &element);		// 在链表末尾增加一个元素
	void Insert(const int index, const T &element);// 在index位置插入一个元素

	void Remove(const T &element);	// 移除与参数匹配的元素
	void RemoveAt(const int index);	// 移除对应位置的元素

	bool Contains(const T &element);// 判断是否包含某个元素
	int Find(const T &element);		// 寻找到某个元素并返回其位置

	void Clear();					// 清空所有数据

	T & operator [](const int index);	// 重载下标运算符
	LinkList<T> & operator = (const LinkList<T> &list);// 重载赋值运算符
};

#endif