//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
#include <iostream>
#include <string>
#include <queue>
#define MAX 26
using namespace std;
//=========================================================================
struct node
{
	struct node *child[MAX];
	int weight;
	int countLeaf;
};
//=========================================================================
struct node *newNode()
{
	struct node *Node = new struct node;
	Node->countLeaf = 0;
	for (int i = 0; i < MAX; i++)
		Node->child[i] = NULL;
	return Node;
}
//=========================================================================
void Add(struct node *root, string s, int k)
{
	int ch;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp -> child[ch] == NULL)
		{
		  temp -> child[ch] = newNode();
		  temp -> child[ch] -> weight = k;
		}
		temp = temp -> child[ch];
	}
	temp -> countLeaf ++;
}
//=========================================================================
int Find(struct node *root, string s)
{
	int ch;
	int max = 0;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp -> child[ch] == NULL) return -1;
		temp = temp -> child[ch];
		max = temp ->weight;
	}
	return max;
}
//=========================================================================
int main()
{
	struct node *root = newNode();
	int n, q;
	cin >> n >> q;
	priority_queue<pair<int, string>, vector<pair<int, string> > > pq;
 
	for (int i = 0; i < n; i++)
	{
		string word;
		int k;
		cin >> word >> k;
		pq.push(make_pair(k, word));
	}
	for (int i = 0; i < n; i++)
	{
		pair<int, string> temp = pq.top();
		pq.pop();
		Add(root, temp.second, temp.first);
	}
	for (int i = 0; i < q; i++)
	{
		string word;
		cin >> word;
		cout << Find(root, word) << endl;
	}
	return 0;
}
