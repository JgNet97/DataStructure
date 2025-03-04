#pragma once
/****************
	Queue
****************/
template<typename T>
class Queue
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
	Queue() : _size(0)
	{
		_front.back = &_back;
		_front.front = &_front;
		_back.front = &_front;
		_back.back = &_back;
	}

	~Queue()
	{

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

		Node* deleteNode = _front.back;
		Node* backNode = deleteNode->back;
		backNode->front = &_front;
		_front.back = backNode;

		delete deleteNode;
		_size--;
	}

	// �� ù ������ Ȯ��
	const T& Front() 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ PopBack");
		}

		return _front.back->data;
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

