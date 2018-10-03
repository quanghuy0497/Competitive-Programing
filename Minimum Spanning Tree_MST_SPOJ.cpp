//http://www.spoj.com/problems/MST/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1000000
const int INF = 1e9;
vector <pair <int, int> > graph[MAX];
vector <int> dist(MAX, INF);
bool visited[MAX];
int n;
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
	int m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >>u >>v >>w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	Prim(1);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dist[i];
	cout<<ans<<endl;
	return 0;
}
