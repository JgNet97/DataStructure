#include "pch.h"
#include "Stack.h"
using namespace std;
int main() 
{
	Stack<int> s;

	for (int i = 20; i < 30; i++) 
	{
		s.Push(i);
	}

	while (!s.Empty()) 
	{
		std::cout << s.Top() << std::endl;
		s.Pop();
	}

	return 0;
}