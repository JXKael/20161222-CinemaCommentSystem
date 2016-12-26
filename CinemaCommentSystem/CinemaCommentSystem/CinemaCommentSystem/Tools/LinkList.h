#include <iostream>
#include "LinkNode.h"
using namespace std;

#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename T> class LinkList
{
public:
	// 默认构造函数
	LinkList()
	{
		pHead = NULL;
		pEnd = NULL;
		pCurrent = NULL;
		Count = 0;
	}
	// 初始化一个元素的构造函数
	LinkList(T &element)
	{
		pHead = new LinkNode<T>(element);
		pEnd = pHead;
		pCurrent = pHead;
		Count = 1;
	}
	// 拷贝构造函数
	LinkList(const LinkList<T> &list)
	{
		this->Clear();
		while (this->Count < list.Count)
		{
			// 调用数据的拷贝构造函数
			T *newData = new T(*list.Get(this->Count));
			this->Add(*newData);
		}
	}
	// 析构函数
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
	// 在链表末尾增加一个元素
	void Add(const T &element)
	{
		LinkNode<T> *newNode = new LinkNode<T>(element);
		this->Add(newNode);
	}
	// 在index位置插入一个元素
	void Insert(const int &index, const T &element)
	{
		if (!(index >= 0 && index <= Count))
		{
			cout << "!warning: 尝试插入位置[" << index << "]元素失败" << endl;
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

	// 移除与参数匹配的所有元素
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
	// 移除对应位置的元素
	void RemoveAt(const int &index)
	{
		if (Count <= 0)
			return;
		if (!this->IndexTest(index))
		{
			cout << "!warning: 尝试移除位置[" << index << "]元素失败" << endl;
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

	// 判断是否包含某个元素
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
	// 寻找到第一个某个元素并返回其位置
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
	// 获得某个位置的元素
	T *Get(const int &index)
	{
		if (Count <= 0)
			return NULL;
		if (!this->IndexTest(index))
		{
			cout << "!warning: 尝试访问位置[" << index << "]元素失败" << endl;
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

	// 修改某个位置的元素
	void ModifyAt(int index, const T &element)
	{
		if (Count <= 0)
			return;
		if (!this->IndexTest(index))
		{
			cout << "!warning: 尝试修改位置[" << index << "]元素失败" << endl;
			return;
		}
		pCurrent = pHead;
		for (int i = 0; i < index; ++i)
		{
			pCurrent = pCurrent->PNext();
		}
		pCurrent->SetData(element);
	}

	// 清空所有数据
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
			cout << "list为空"; 
			return out;
		}
		for (int i = 0; i < list.Count; ++i)
		{
			cout << *list.Get(i);
			if (i != list.Count - 1)
				cout << "、";
		}
		return out;
	}
};

#endif