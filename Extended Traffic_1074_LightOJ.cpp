//http://www.lightoj.com/volume_showproblem.php?problem=1074
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//=====================================================
#define MAX 205
const int INF = 1e9;
struct triad
{
	int begin, end, weigh;
};
vector<int> dist (MAX, INF);
vector <int> path(MAX, -1);
vector <triad> graph;
int n,m;
//=====================================================
bool BellmanFord(int s, vector <triad> &graph)
{
	dist[s] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		int kt = 0;
		for (int j = 0; j < m; j++)
		  if (dist[graph[j].begin] != INF && (dist[graph[j].begin] + graph[j].weigh < dist[graph[j].end]))
		    {
		    	kt = 1;
				dist[graph[j].end] = dist[graph[j].begin] + graph[j].weigh;
				path[graph[j].end] = graph[j].begin;
		    }
		if (!kt) break;
	}
	for (int j = 0; j < m; j++)
	  if (dist[graph[j].begin] != INF && (dist[graph[j].begin] + graph[j].weigh < dist[graph[j].end]))
	    return false;
	return true;
}
//=====================================================
bool check (int a)
{
	if (path[a] == 0)
	  return true;
	else if (path[a] == -1)
	  return false;
	else return check(path[a]);
}
//=====================================================
int main()
{
	int h;
	cin >> h;
	for (int k = 1; k <= h; k++)
	{
		cin >> n;
		int crowded[n + 1];
		crowded[0] = 0;
		graph.clear();
		dist = vector <int> (n+1, INF);
		path =  vector <int> (n+1, -1);
		for (int i = 1; i <= n; i++)
			cin>>crowded[i];
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin>>u>>v;
			graph.push_back((triad) { u, v, pow(crowded[v] - crowded[u], 3) });
		}
		bool res = BellmanFord(1, graph);
		int q;
		cin>>q;
		cout<<"Case "<<k<<":"<<endl;
		path[1] = 0;
		for (int i = 0; i < q; i++)
		{
			int des;
			cin>>des;
			if (dist[des] < 3 || !check(des))
				cout<<"?"<<endl;
			else
				cout<<dist[des]<<endl;
		}
	}
	return 0;
}
