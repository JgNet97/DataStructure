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
	int	 _size;

public:
	LinkedList() : _size(0)
	{
		_head.front = &_head;
		_head.back = &_tail;

		_tail.front = &_head;
		_tail.back = &_tail;
	}

	~LinkedList()
	{

	}

	// 뒤에 데이터 추가
	void PushBack(const T& data)
	{
		// [HEAD]<->[]<->[TAIL]
		Node* tailFrontNode = _tail.front;
		Node* newNode = new Node(data);
		tailFrontNode->back = newNode;
		newNode->front = tailFrontNode;
		_tail.front = newNode;
		newNode->back = &_tail;

		_size++;
	}

	// 뒤에 데이터 삭제
	void PopBack()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 PopBack");
		}

		Node* deleteNode = _tail.front;
		Node* deleteNodeFront = deleteNode->front;

		deleteNodeFront->back = &_tail;
		_tail.front = deleteNodeFront;

		delete deleteNode;
		_size--;
	}

	// 맨 처음 데이터 조회
	const T& Front()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("데이터가 없을때 Front");
		}

		Node* frontNodePtr = _head.back;
		return frontNodePtr->data;
	}

	// 맨 마지막 데이터 조회
	const T& Back()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("데이터가 없을때 Back");
		}

		Node* BackNodePtr = _tail.front;
		return BackNodePtr->data;
	}


	// 데이터 없는지 확인
	bool Empty()
	{
		return _size == 0;
	}
};

