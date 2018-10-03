//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500000
int parent[MAX], friends[MAX];
//=============================================================
int	findSet(int u)
{
	while (u != parent[u])
		u = parent[u];
	return u;
}
//=============================================================
void unionSet(int u, int v)
{
	int up = findSet(u);
	int vp = findSet(v);
	if (up != vp)
	  friends[up] += friends[vp];
	parent[vp] = up;
}
//=============================================================
int main()
{
	int k;
	cin >>k;
	while (k--)
	{
		int n,m;
		cin >>m >>n;
		for (int i = 1; i <= m; i++)
		{
			parent[i] = i;
			friends[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			int a,b;
			cin >>a >>b;
			unionSet(a, b);
		}
		int max_friends = 0;
		for (int i = 1; i <= m; i++)
		  max_friends = max(max_friends, friends[i]);
		cout<< max_friends <<endl;
	}
	return 0;
}
