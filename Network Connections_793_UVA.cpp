//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734
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
	for (int i = 0; i < k; i++)
	{
		int n, unsuc = 0, suc = 0;
		scanf("\n%d\n",&n);
		for (int j = 1; j <= n; j++)
			parent[j] = j;
		while (1)
		{
			char x;
			int a,b;
			if (!getline(cin,st) || st.empty()) 
			   break;
			sscanf(st.c_str(),"%c %d %d",&x,&a,&b);
			if (x == 'c') 
			  unionSet(a, b);
			else findSet(a) == findSet(b) ? suc++ : unsuc++;
		}
		if (i) cout<<endl;
        cout<<suc<<","<<unsuc<<endl);
	}
	return 0;
}
