//https://www.hackerrank.com/challenges/qheap1/problem
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
//==============================================
int main()
{
	int n, value;
	priority_queue <ll, vector <ll>, greater <ll> > q,x;
	cin>>n;
	while (n--)
	{
		int a;
		ll b;
		cin>>a;
		if (a < 3) cin>>b;
		if (a == 1)
		    q.push(b);
		else
		if (a == 2)
			x.push(b);
		else
		if (a == 3)
		{
			while (!x.empty() && q.top() == x.top())
			{
				q.pop();
				x.pop();
			}
			cout<<q.top()<<endl;	
		}
	}
	return 0;
}
