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
	
	// 앞쪽에 원소 추가
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

	// 뒤쪽에 원소 추가
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

	// 앞쪽 원소 제거
	void PopFront() 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 PopFront");
		}

		Node* deleteNode = _front.back;
		Node* backNode = deleteNode->back;
		backNode->front = &_front;
		_front.back = backNode;

		delete deleteNode;

		_size--;
	}

	// 뒤쪽 원소 제거
	void PopBack()
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

	// 앞쪽 원소 반환
	const T& Front() const 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 Front");
		}

		return _front.back->data;
	}

	// 뒤쪽 원소 반환
	const T& Back() const 
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 Back");
		}

		return _back.front->data;
	}

	// 덱이 비어있는지 확인
	bool Empty() const
	{
		return _size == 0;
	}

	// 덱의 크기 반환
	int Size() const 
	{
		return _size;
	}

	// Debug 출력용
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

