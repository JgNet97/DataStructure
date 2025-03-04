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

	// 데이터 삽입
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

	// 데이터 삭제
	void Pop()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 PopBack");
		}
		
		Node* deleteNode = _back.front;
		Node* frontNode = deleteNode->front;
		frontNode->back = &_back;
		_back.front = frontNode;

		delete deleteNode;
		_size--;
	}
	
	// 맨 첫 데이터 확인
	const T& Top() 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 PopBack");
		}

		return _back.front->data;
	}
	// 데이터 없는지 확인
	bool Empty() 
	{
		return _size == 0;
	}
	// 사이즈 확인
	int Size() 
	{
		return _size;
	}
};

