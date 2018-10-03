//http://poj.org/problem?id=2560
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define MAX 110
#define INF 1e9
using namespace std;
vector <pair <int, long long> > graph[MAX];
vector <int> dist(MAX, INF);
int pathmin[MAX];
bool visited[MAX];
int n, m;
//=======================================================================================
double Prim (int begin)
{
	priority_queue<pair<int, long long>, vector<pair<int, long long> >, greater<pair<int, long long> > > pq;
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
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum += sqrt(dist[i]);
	return sum;
}
//=======================================================================================
int main()
{
	int t;
	cin >>t;
	while (t--)
	{
		cin >> n;
		double a[MAX],b[MAX];
		for (int i = 1; i <= n; i++)
		{
			dist[i] = INF;
			visited[i] = false;
			graph[i].clear();
		}
		for (int i = 1; i <= n; i++)
			cin >>a[i] >>b[i];
		for (int i = 1; i < n; i++)
		  for (int j = i + 1; j <= n; j++)
		  {
		  	double w = pow(a[i] - a[j],2) + pow(b[i] - b[j],2);
		  	graph[i].push_back(make_pair(j, w));
		    graph[j].push_back(make_pair(i, w));
		  }
		printf("%0.2f\n", Prim(1));
		if (t) cout<<endl;
	}
	return 0;
}
