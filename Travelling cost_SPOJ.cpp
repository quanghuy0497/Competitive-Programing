//http://www.spoj.com/problems/TRVCOST/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//=================================================================================
#define MAX 505
const int INF = 1e9;
vector <vector < pair<int, int> > > graph = vector<vector<pair<int, int> > >(MAX, vector<pair<int, int> >() );
vector <int> dist = vector<int> (MAX, INF);
//=================================================================================
struct option
{
	bool operator() (const pair <int, int> &a, pair <int, int> &b) const
	{
		return a.second > b.second;
	}
};
//=================================================================================
void Dijkstra(int s)
{
	priority_queue< pair<int, int>, vector<pair<int, int> >, option > pq;
	pq.push(make_pair(s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		pair <int, int> top = pq.top();
		pq.pop();
		for (int i = 0; i < graph[top.first].size(); ++i)
		{
			pair <int, int> neighbor = graph[top.first][i];
			if (top.second + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = top.second + neighbor.second;
				pq.push(pair <int, int> (neighbor.first, dist[neighbor.first]));
			}
		}
	}
}
//=================================================================================
int main()
{
	int n, q, start;
	cin >> n;
	for (int i = 0; i <  n; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(pair<int, int> (b, w));
		graph[b].push_back(pair<int, int> (a, w));
	}
	cin >> start >> q;
	Dijkstra(start);
	for (int i = 0; i < q; i++)
	{
		int end;
		cin >> end;
		if (dist[end] != INF)
			cout<<dist[end]<<endl;
		else cout<<"NO PATH"<<endl;
	}
	return 0;
}
