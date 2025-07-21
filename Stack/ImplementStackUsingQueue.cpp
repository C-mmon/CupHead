//Implement a stack using queues
#include <bits/stdc++.h>

using namespace std;

class Stack
{
	queue <int> q1;
	queue <int> q2;
	int maxSize;
	int currentSize;

	Stack(int sz)
	{
		maxSize = sz;
		currentSize =0;
	}
public:
	bool push(int x)
	{
		if(currentSize >= maxSize)
		{
			return false;
		}
		q2.push(x);
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		swap(q1, q2); //this will make the q2 empty, because originally q1 was empty
		currentSize++;
        return true;
	}

	bool pop()
	{
        if (currentSize == 0) {
            return false; // stack underflow
        }

        q1.pop();
        currentSize--;
        return true;
	}

};

