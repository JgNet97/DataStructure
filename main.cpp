#include "pch.h"
#include "Queue.h"
using namespace std;
int main() 
{
	Queue<int> q;

	for (int i = 20; i < 30; i++) 
	{
		q.Push(i);
	}

	while (!q.Empty()) 
	{
		std::cout << q.Front() << std::endl;
		q.Pop();
	}

	return 0;
}