//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1338
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <math.h>
#define MAX 760
const int INF = 1e9;
using namespace std;
vector <pair <int, double> > graph[MAX];
vector <double> dist(MAX, INF);
bool visited[MAX];
//============================================================
void Prim (int begin)
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
			}
	}
}
//============================================================
int main()
{
	int n;
	while (cin>>n)
	{
		fflush(stdin);
		int x[MAX], y[MAX];
		for (int i = 1; i <= n; i++)
			cin>>x[i]>>y[i];
		for (int i = 1; i < n; i++)
		  for (int j = i + 1;j <= n; j++)
		  {
		  	double w = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
		  	graph[i].push_back(make_pair(j, w));
		    graph[j].push_back(make_pair(i, w));
		  }
		int q;
		cin >>q;
		for (int i = 1; i <= q; i++)
		{
			int a, b;
			cin >>a >>b;
			graph[a].push_back(make_pair(b, 0));
		    graph[b].push_back(make_pair(a, 0));
		}
	
		Prim(1);
		double sum = 0;
		for (int i = 1; i <= n; i++)
			sum += sqrt(dist[i]);
		if (sum >= INF) sum = -1;
		printf("%0.2f\n", sum);
		for (int i = 1; i <= n; i++)
		{
			visited[i] = false;
			dist[i] = INF;
			graph[i].clear();
		}
	}
	return 0;
}
