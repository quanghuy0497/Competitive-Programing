//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define MAX 100000
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
	  friends[up] += max(1, friends[vp]);
	parent[vp] = up;
}
//=============================================================
int main()
{
	int k;
	cin >>k;
	while (k--)
	{
		int n;
		cin >>n;
		for (int i = 1; i <= MAX; i++)
		{
			parent[i] = i;
			friends[i] = 1;
		}
		map <string, int > m;
		int d = 0;
		
		for (int i = 0; i < n; i++)
		{
			string sta, stb;
			int a,b;
			cin >>sta >>stb;
			
			if (m.find(sta) == m.end())
				m[sta] = ++d;
			
			if (m.find(stb) == m.end())
				m[stb] = ++d;
		
			a = m[sta];
			b = m[stb];	

			unionSet(a, b);
			cout<<friends[findSet(a)]<<endl;
		}
	}
	return 0;
}
