#include "common.h"

class MinStack {
public:
	void push(int x) {
		if (m_sortedStack.find(x) != m_sortedStack.end())
			m_sortedStack[x]++;
		else
			m_sortedStack[x] = 1;
		m_vStackImpl.push_back(x);
	}

	void pop() {
		if (--m_sortedStack[m_vStackImpl.back()] == 0)
			m_sortedStack.erase(m_vStackImpl.back());
		m_vStackImpl.pop_back();
	}

	int top() {
		return m_vStackImpl.back();
	}

	int getMin() {
		return	m_sortedStack.begin()->first;
	}

	vector<int> m_vStackImpl;
	map<int, int> m_sortedStack;
};

class MinStack1
{
	size_t s_size;  //stack size
	size_t s_point;//stack index point

	size_t i_size;  //min stack size
	size_t i_point;//min stack index point


public:
	int *stk;             //stack
	int *min_index; //min stack index

	int *buf;            //for realloc
	int min;             //min


	MinStack1()
	{
		s_size = 256;     //init size
		i_size = s_size;

		s_point = 0;
		i_point = 0;

		stk = (int*)malloc(sizeof(int)*s_size);
		min_index = (int*)malloc(sizeof(int)*i_size);

		min_index[0] = 0;    /* stk[0] is min. */

		min = INT_MAX;
	}
	~MinStack1()
	{
		free(stk);
		free(min_index);
	}

	void push(int x)
	{

		stk[s_point++] = x;
		if (x <= min)
		{
			min = x;
			min_index[i_point++] = s_point - 1;
		}
		//if stack has 32768 elm than belows code no necessary in test case.
		if (s_point + 16 > s_size)
		{
			s_size += 256;

			buf = (int*)malloc(sizeof(int)*s_size);
			memcpy(buf, stk, sizeof(int)*(s_point));

			free(stk);
			stk = buf;
		}
		if (i_point + 8 > i_size)
		{
			i_size += 256;
			buf = (int*)malloc(sizeof(int)*i_size);
			memcpy(buf, min_index, sizeof(int)*(i_point));
			free(min_index);
			min_index = buf;
		}
	}

	void pop()
	{
		if (s_point != 0)
		{
			if (stk[s_point - 1] == min)
			{
				i_point--;
				min = stk[min_index[i_point - 1]];
			}
			s_point--;
		}
	}
	int top()
	{
		if (s_point == 0)
			return NULL;
		return stk[s_point - 1];
	}
	int getMin()
	{
		return stk[min_index[i_point - 1]];
	}
};


int main(int argc, char** argv){
	MinStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	s.pop();
	s.push(-1);
	s.push(6);
	cout << s.top() << endl;
	cout << s.getMin() << endl;


	return 0;
}