using namespace std;

#ifndef LINK_NODE_H
#define LINK_NODE_H

template<typename T> class LinkNode
{
public:
	LinkNode<T>();
	LinkNode<T>(T &data);
	inline ~LinkNode<T>() { delete data; }

	T *data;
	LinkNode *pNext;
};

#endif