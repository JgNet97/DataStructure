#include "pch.h"
#include "Deque.h"
using namespace std;

int main() 
{
	Deque<int> dq;

	dq.PushFront(1);
	dq.PrintAll();
	dq.PushFront(2);
	dq.PrintAll();
	dq.PushFront(3);
	dq.PrintAll();
	dq.PushBack(999);
	dq.PrintAll();
	dq.PushFront(1000);
	dq.PrintAll();
	dq.PushBack(4);
	dq.PrintAll();
	dq.PopBack();
	dq.PrintAll();
	dq.PopFront();
	dq.PrintAll();
	dq.PopFront();
	dq.PrintAll();
	dq.PopBack();
	dq.PrintAll();
	return 0;
}