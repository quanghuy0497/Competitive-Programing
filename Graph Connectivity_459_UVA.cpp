//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
#include <iostream>
#include <string>
using namespace std;
#define MAX 500000
int parent[MAX];
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
	parent[vp] = up;
}
//=============================================================
int main()
{
	int k;
	string st;
	cin >>k;
	getline(cin, st);
	getline(cin, st);
	for (int i = 0; i < k; i++)
	{
		getline(cin, st);
		int d, n;
		d = n = st[0] - 'A' + 1;
		for (int j = 1; j <= n; j++)
			parent[j] = j;
		while (1)
		{
			if (!getline(cin, st) || st.empty()) 
			   break;
			int a = st[0] - 'A' + 1, b = st[1] - 'A' + 1;
			if (findSet(a) != findSet(b))
			{
                unionSet(a,b);
                d--;
		    }
		}
		if (i) cout<<endl;
       	cout<<d<<endl;
	}
	return 0;
}
