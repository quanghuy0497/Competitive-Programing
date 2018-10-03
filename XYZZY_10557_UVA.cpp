//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//=====================================================
#define MAX 105
const int INF = -1e9;
vector<int> dist (MAX, INF);
vector < pair <int, int> > graph;
int energy[MAX];
int n;
//=====================================================
bool BFS(int s)
{
	queue<int> q;
	vector<bool> visited(n + 10, false);
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (int j = 0; j < graph.size(); j++)
			if (s == graph[j].first && !visited[graph[j].second])
			{
				visited[graph[j].second] = true;
				q.push(graph[j].second);
				if (graph[j].second == n)
					return true;
			}
	}
	return false;
}
//=====================================================
bool BellmanFord(vector <pair <int, int> > &graph)
{
	dist[1] = 100;
	for (int i = 1; i < n; i++)
	  for (int j = 0; j < graph.size(); j++)
		if (dist[graph[j].first] > 0)
		    dist[graph[j].second] = max( dist[graph[j].first] + energy[graph[j].second], dist[graph[j].second]);
	bool check = false;
	for (int j = 0; j < graph.size(); j++)
	  if ( (dist[graph[j].first] > 0) && (dist[graph[j].second] < energy[graph[j].second] + dist[graph[j].first]) && BFS(graph[j].first))
	    {
			check = true;
			break;	
		}
	return check;
}
//=====================================================
int main()
{
	while (cin >> n, n != -1)
	{
		graph.clear();
		dist = vector <int> (n+1, INF);
		for (int i = 1; i <= n; i++)
		{
			int m, value;
			cin >>energy[i] >>m;
			while (m--)
			{
				cin>>value;
				graph.push_back(make_pair(i, value));
			}
		}
		if (BellmanFord(graph) == true || dist[n] >0)
			cout<<"winnable"<<endl;
		else cout<<"hopeless"<<endl;
	}
	return 0;
}
