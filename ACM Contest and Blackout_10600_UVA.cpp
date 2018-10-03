//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=1541&mosmsg=Submission+received+with+ID+21500857
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <math.h>
#define MAX 150
const int INF = 1e9;
using namespace std;
vector <pair <int, int> > graph[MAX];
vector <int> dist(MAX, INF);
int path[MAX], pathmin[MAX];
bool visited[MAX];
int n, m;
//============================================================
int Prim (int begin)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, begin));
	dist[begin] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++)
			if (!visited[graph[u][i].first] && dist[graph[u][i].first] > graph[u][i].second)
			{
				dist[graph[u][i].first] = graph[u][i].second;
				pq.push(make_pair(graph[u][i].second, graph[u][i].first));
				path[graph[u][i].first] = u;
			}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += dist[i];
	return sum;
}
//============================================================
void reset()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = false;
		dist[i] = INF;
		path[i] = -1;
	}
}
//============================================================
int main()
{
	int k;
	cin>>k;
	while (k--)
	{
		cin >>n >>m;
		for (int i = 1; i <= n; i++)
		{
			dist[i] = INF;
			path[i] = -1;
		}
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			cin >>a >>b >>w;
			graph[a].push_back(make_pair(b, w));
		    graph[b].push_back(make_pair(a, w));
		}
	
		int first= Prim(1), second = INF;
		for (int i = 1; i <= n; i++)
		  pathmin[i] = path[i];
		reset();

		for (int i = 2; i <= n; i++) 
		{
			int u,v;
            for (u = 0; u < graph[i].size(); u++)
            	if (graph[i][u].first == pathmin[i]) break;
            	
            for (v = 0; v < graph[pathmin[i]].size(); v++)
            	if (graph[pathmin[i]][v].first == i) break;
            	
            int tmp = graph[i][u].second;
            graph[i][u].second = graph[pathmin[i]][v].second = INF;
            
			int k = Prim(1);
			reset();
		    if (k >= 0 && k < second) second = k;
            
			graph[pathmin[i]][v].second = graph[i][u].second = tmp;
        }
        
		if (second == INF) second  = first;
		cout<<first<<" "<<second<<endl;
		for (int i = 1; i <= n; i++)
			graph[i].clear();
	}
	return 0;
}
