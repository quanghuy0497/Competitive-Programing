//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1524
#include <iostream>
#define MAX 50010
using namespace std;
int n,m;
int parent[MAX];
//=======================================================================================
int	findSet(int u)
{
	while (u != parent[u])
		u = parent[u];
	return u;
}
//=======================================================================================
void unionSet(int u, int v)
{
	int up = findSet(u);
	int vp = findSet(v);
	parent[vp] = up;
}
//=======================================================================================
int main()
{
	int n,m, h = 0;
	while (1)
	{
		cin >>n >>m;
		int t = n;
		if (n == 0 && m == 0) return 0;
		for (int i = 1; i <= n; i++)
		  parent[i] = i;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >>a >>b;
			if (findSet(a) != findSet(b))
			{
				unionSet(a,b);
				t--;
			}
		}
		cout<<"Case "<<++h<<": "<<t<<endl;
	}
	return 0;
}
