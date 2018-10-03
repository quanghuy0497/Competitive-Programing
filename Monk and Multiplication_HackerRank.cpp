//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//==============================================
int main()
{
	int n, value;
	priority_queue <int> a;
	cin>>n;
	while (n--)
	{
		cin>>value;
		a.push(value); 
		if (a.size() < 3)
		  cout<<-1<<endl;
		else
		{
			long long top1 = a.top();
			a.pop();
			long long top2 = a.top();
			a.pop();
			long long top3 = a.top();
			a.pop();
			cout<<top1 * top2 * top3<<endl;
			a.push(top1);
			a.push(top2);
			a.push(top3);
		}
	}
	return 0;
}
