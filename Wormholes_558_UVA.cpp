//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
#include <iostream>
#include <vector>
using namespace std;
//=====================================================
#define MAX 2005
const int INF = 1e9;
struct triad
{
	int begin, end, weigh;
};
vector<int> dist (MAX, INF);
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
		    }
		if (!kt) break;
	}
	for (int j = 0; j < m; j++)
	  if (dist[graph[j].begin] != INF && (dist[graph[j].begin] + graph[j].weigh < dist[graph[j].end]))
	    return false;
	return true;
}
//=====================================================
int main()
{
	int k;
	cin >> k;
	while (k --)
	{
		cin >> n >> m;
		graph.clear();
		dist = vector <int> (n, INF);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin>>u>>v>>w;
			graph.push_back((triad) {u, v, w});
		}
		if (!BellmanFord(0, graph))
		  cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
	}
	return 0;
}
