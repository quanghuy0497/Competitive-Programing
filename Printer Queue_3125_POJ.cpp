//http://poj.org/problem?id=3125
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//=============================================
int main()
{
	int k;
	cin>>k;
	while (k--)
	{
		int n,m, value, time = 1, pos;
		cin >> n >> m;
		queue<int> q;
		priority_queue<int> qp;
		for (int i = 0; i < n; i++)
		{
			cin>>value;
			qp.push(value);
			if (i == m) 
			{
			  pos = value;
			  value = 10;
			}
			q.push(value);
		}
		m = qp.top();
		while (!(q.front() == 10 && pos ==m ))
			if (q.front() < m || (q.front() == 10 && pos < m ))
			{
				value = q.front();
				q.pop();
				q.push(value);
			}
			else
			if (q.front() == m)
			{
				time = time + 1;
				q.pop();
				qp.pop();
				m = qp.top();
			}
		cout<<time <<endl;
	}
	return 0;
}
