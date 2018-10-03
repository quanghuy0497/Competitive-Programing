//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n = 1;
	while (n != 0)
	{
		cin>>n;
		if (n == 0) return 0;
		priority_queue <int, vector<int>, greater<int> >q;
		for (int i=0; i<n; ++i)
		{
			int value;
			cin>>value;
			q.push(value);
		}
		int cost = 0;
		while (q.size() > 1)
		{
			int count = q.top();
			q.pop();
			count += q.top();
			q.pop();
			cost += count;
			q.push(count);
		}
		cout<<cost<<endl;
	}
	return 0;
}
