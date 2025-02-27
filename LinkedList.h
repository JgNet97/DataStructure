#pragma once
/****************
	LinkedList
****************/
template<typename T>
class LinkedList
{
	class Node
	{
	public:
		Node* front;
		Node* back;
		T data;

	public:
		Node(const T& pData) : data(pData), front(nullptr), back(nullptr) {}
		Node() : front(nullptr), back(nullptr) {}
		~Node() {}
	};

private:
	Node _head;
	Node _tail;

public:
	LinkedList()
	{
		_head.front = &_head;
		_head.back = &_tail;

		_tail.front = &_head;
		_tail.back = &_tail;
	}

	~LinkedList()
	{

	}

	// �ڿ� ������ �߰�
	void PushBack(const T& data) 
	{
		// [HEAD]<->[]<->[TAIL]
		Node* tailFrontNode = _tail.front;
		Node* newNode = new Node(data);
		tailFrontNode->back = newNode;
		newNode->front = tailFrontNode;
		_tail.front = newNode;
		newNode->back = _tail;
	}

	// �ڿ� ������ ����
	void PopBack() 
	{

	}

	// �߰� ������ ����
	void Insert(Node* insertNode, const T& data) 
	{

	}

	// �߰� ������ ����
};

