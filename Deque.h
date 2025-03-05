#pragma once
/****************
	Deque
****************/
template<typename T>
class Deque
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
	Deque() : _size(0)
	{
		_front.back = &_back;
		_front.front = &_front;
		_back.front = &_front;
		_back.back = &_back;
	}

	~Deque()
	{
		while (!Empty())
		{
			PopFront();
		}
	}
	
	// ���ʿ� ���� �߰�
	void PushFront(const T& value) 
	{
		Node* newNode = new Node(value);
		Node* backNode = _front.back;

		backNode->front = newNode;
		newNode->back = backNode;
		_front.back = newNode;
		newNode->front = &_front;

		_size++;
	}

	// ���ʿ� ���� �߰�
	void PushBack(const T& value) 
	{
		Node* newNode = new Node(value);
		Node* frontNode = _back.front;

		frontNode->back = newNode;
		newNode->front = frontNode;
		newNode->back = &_back;
		_back.front = newNode;

		_size++;
	}

	// ���� ���� ����
	void PopFront() 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ PopFront");
		}

		Node* deleteNode = _front.back;
		Node* backNode = deleteNode->back;
		backNode->front = &_front;
		_front.back = backNode;

		delete deleteNode;

		_size--;
	}

	// ���� ���� ����
	void PopBack()
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

	// ���� ���� ��ȯ
	const T& Front() const 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ Front");
		}

		return _front.back->data;
	}

	// ���� ���� ��ȯ
	const T& Back() const 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("������ �����Ͱ� ������ Back");
		}

		return _back.front->data;
	}

	// ���� ����ִ��� Ȯ��
	bool Empty() const
	{
		return _size == 0;
	}

	// ���� ũ�� ��ȯ
	int Size() const 
	{
		return _size;
	}

	// Debug ��¿�
	void PrintAll() 
	{
		Node* node = _front.back;
		while (node != &_back) 
		{
			std::cout << node->data << " ";
			node = node->back;
		}
		printf("\n");
	}
};

