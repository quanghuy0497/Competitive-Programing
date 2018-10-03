//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/description/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//=================================================================================================
struct Topics
{
	int ID;
	long long newscore, changescore;
	bool operator() (const Topics &a, const Topics &b) const
	{
		return a.changescore > b.changescore || (a.changescore == b.changescore && a.ID < b.ID);
	}
};
//=================================================================================================
int main()
{
	int n, id;
	long long oldscore, p, l, c, s;
	cin >> n;
	priority_queue<Topics, vector<Topics>, Topics> pq;
	while (n--)
	{
		Topics tmp;
		cin >> id >> oldscore >> p >> l >> c >> s;
		tmp.ID = id;	
		tmp.newscore = p * 50 + l * 5 + c * 10 + s * 20;
		tmp.changescore = oldscore - tmp.newscore;
		pq.push(tmp);
	}
	for (int i = 1; i <= 5; i++)
	{
		Topics value;
		value = pq.top();
		pq.pop();
		cout << value.ID << " " << value.newscore << endl;
	}
	return 0;
}

