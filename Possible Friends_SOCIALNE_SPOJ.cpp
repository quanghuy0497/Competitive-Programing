//http://www.spoj.com/problems/SOCIALNE/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 55
#define INF 1e9
vector <vector <int> > graph, dist;
int n;
//======================================================================
void Gerenadee(string st, int a, int n)
{
	int kt = 0;
	for (int i = 0; i < n; i ++)
	{
		if (st[i] == 'Y') 
		{
			graph[a][i] = 1;
			kt++;
		}
	    else graph[a][i] = INF;
	    if (a == i) dist[a][i] = 0;
	      else dist[a][i] = graph[a][i];
	}
}
//======================================================================
void FloydWarshall(vector<vector<int> > &graph, vector<vector<int> > &dist)
{
	for (int k = 0; k < n; k++)
	  for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
		  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
//======================================================================
int main()
{
	int k;
	cin>>k;
	while (k--)
	{
		string st;
		cin>>st;
		n = st.size();
		graph = vector < vector <int> > (n, vector <int> (n, INF));
		dist = vector < vector <int> > (n, vector <int> (n, INF));
		Gerenadee(st, 0, n);
		for (int i = 1; i < n; i++)
		{
			cin >> st;
			Gerenadee(st, i, n);

		}
		FloydWarshall(graph, dist);
		int max = 0, pos = 0;
		for (int i = 0; i < n; i++)
		{
			int count = 0;
		    for (int j = 0; j < n; j++)
		      if (dist[i][j] == 2) count ++;
		    if (max < count)
		    {
		    	max = count;
		    	pos = i;
			}
		}
		cout<<pos<<" "<<max<<endl;
	}
	return 0;
}
