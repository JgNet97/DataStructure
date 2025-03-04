#pragma once
/****************
	Stack
****************/
template<typename T>
class Stack
{
private:
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
	Node _front;
	Node _back;
	int  _size;


public:
	Stack() : _size(0)
	{
		_front.back = &_back;
		_front.front = &_front;
		_back.front = &_front;
		_back.back = &_back;
	}

	~Stack()
	{
		while (!Empty()) 
		{
			Pop();
		}
	}

	// ������ ����
	void Push(const T& data) 
	{
		Node* newNode = new Node(data);
		Node* lastNode = _back.front;
		lastNode->back = newNode;
		newNode->front = lastNode;
		newNode->back = &_back;
		_back.front = newNode;

		_size++;
	}

	// ������ ����
	void Pop()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ PopBack");
		}
		
		Node* deleteNode = _back.front;
		Node* frontNode = deleteNode->front;
		frontNode->back = &_back;
		_back.front = frontNode;

		delete deleteNode;
		_size--;
	}
	
	// �� ù ������ Ȯ��
	const T& Top() 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ PopBack");
		}

		return _back.front->data;
	}
	// ������ ������ Ȯ��
	bool Empty() 
	{
		return _size == 0;
	}
	// ������ Ȯ��
	int Size() 
	{
		return _size;
	}
};

