//http://lightoj.com/volume_showproblem.php?problem=1224
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 4
using namespace std;
//=========================================================================
struct node
{
	struct node *child[MAX];
	int weight;
	int end ;
};
//=========================================================================
int get(char ch)
{
    if(ch == 'A')
        return 0;
    if(ch == 'C')
        return 1;
    if(ch == 'G')
        return 2;
    if(ch == 'T')
        return 3;
}
//=========================================================================
struct node *newNode()
{
	struct node *Node = new struct node;
	Node-> end = 0;
	Node -> weight = 0;
	for (int i = 0; i < MAX; i++)
		Node->child[i] = NULL;
	return Node;
}
//=========================================================================
void Add(struct node *root, string s)
{
	struct node *temp = root;
	for (int i = 0; i < s.length(); i++)
	{
		int ch = get(s[i]);
		if (temp -> child[ch] == NULL)
		  temp -> child[ch] = newNode();
		temp = temp -> child[ch];
		temp ->weight++;
	}
	temp -> end ++;
}
//=========================================================================
int Find(struct node *root, string s)
{
	struct node *temp = root;
	int maxx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int ch = get(s[i]);
		temp = temp -> child[ch];
		maxx = max(temp -> weight * (i + 1), maxx);
	}
	return maxx;
}
//=========================================================================
void del(node *root)
{
    for(int i = 0; i < 4; i++)
        if(root->child[i])
            del(root->child[i]);
    delete(root);
}
//=========================================================================
int main()
{
	int k, count = 0;
	cin >>k;
	while (k--)
	{
		struct node *root = newNode();
		int n;
		cin >>n;
		string word[50010];
		for (int i = 0; i < n; i++)
		{
			cin >> word[i];
			Add(root, word[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, Find(root, word[i]));
		cout << "Case " << ++count <<": "<< ans << endl;
		del(root);
	}
	return 0;	
}
