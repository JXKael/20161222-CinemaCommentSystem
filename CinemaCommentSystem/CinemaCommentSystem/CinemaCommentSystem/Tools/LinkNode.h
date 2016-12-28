#ifndef LINK_NODE_H
#define LINK_NODE_H

#include <cstddef>
using namespace std;

namespace tools
{
	template<typename T> class LinkNode {
	public:
		// Ĭ�Ϲ��캯��
		inline LinkNode<T>()
		{
			this->data = null;
			this->pNext = null;
		}
		// ��ʼ��һ��Ԫ�صĹ��캯��
		inline LinkNode<T>(const T &data)
		{
			if (this->data != NULL)
				delete this->data;
			this->data = new T(data);
			this->pNext = NULL;
		}
		inline LinkNode<T>(const T &data, LinkNode<T> pNext)
		{
			if (this->data != null)
				delete this->data;
			this->data = &data;
			this->pNext = pNext;
		}
		// �������캯����ֻ�ı�����
		inline LinkNode<T>(const LinkNode<T> &node)
		{
			if (this->data != null)
				delete this->data;
			this->data = new T(node.Data());
		}
		// ��������
		inline ~LinkNode<T>()
		{
			if (NULL != data)
				delete this->data;
			this->pNext = NULL;
		}
	private:
		T *data;
		LinkNode<T> *pNext;
	public:
		inline T &Data() { return *this->data; }
		inline LinkNode<T> &Next() { return *this->pNext; }
		inline LinkNode<T> *PNext() { return this->pNext; }
		inline void SetNext(LinkNode<T> *node) { this->pNext = node; }
		inline void SetData(const T &data)
		{
			if (NULL �� = this->data)
				delete this->data;
			this->data = new T(data);
		}
		inline void SetNextNull() { this->pNext = NULL; }
	};
}

#endif