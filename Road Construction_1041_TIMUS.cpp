//http://lightoj.com/volume_showproblem.php?problem=1041
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int MAX = 1e5;
const int INF = 1e7;
vector <pair <int, int> > graph[MAX];
int dist[MAX];
bool visited[MAX];
int n,d;
//============================================================
void Prim (int begin)
{	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	for (int i = 1; i <= d; i++) 
	{
        dist[i] = INF;
        visited[i] = false;
    }
	pq.push(make_pair(0, begin));
	dist[begin] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++)
			if (!visited[graph[u][i	].first] && dist[graph[u][i].first] > graph[u][i].second)
			{
				dist[graph[u][i].first] = graph[u][i].second;
				pq.push(make_pair(graph[u][i].second, graph[u][i].first));
			}
	}
	int sum = 0;
	for (int j = 1; j <= d; j++)
		sum += dist[j];
	if (sum < INF) cout <<sum <<endl;
	else cout <<"Impossible" <<endl;

}
//============================================================
int main()
{
	int k;
	cin >>k;
	for (int h = 1; h <= k; h++)
	{
		cin >>n;
		map <string, int > m;
		d = 0;
		for (int i = 1; i <= 2*n; i++)
            graph[i].clear();
		for (int i = 1; i <= n; i++)
		{
			string a,b;
			int w;
			cin >>a >>b >>w;
			if (m.find(a) == m.end()) m[a] = ++d;
			if (m.find(b) == m.end()) m[b] = ++d;
			graph[m[a]].push_back(make_pair(m[b], w));
			graph[m[b]].push_back(make_pair(m[a], w));
		}
		cout<<"Case "<<h<<": ";
		Prim(1);
	}
	return 0;
}
