//http://poj.org/problem?id=3630
#include <iostream>
#include <string>
#define MAX 10
using namespace std;
//=======================================================================================
struct node
{
	struct node *child[MAX];
	int  countLeaf;
};
//=======================================================================================
struct node *newNode()
{
	struct node *Node = new struct node;
	Node->countLeaf = 0;
	for (int i = 0; i < MAX; i++)
		Node->child[i] = NULL;
	return Node;
}
//=======================================================================================
bool Add(struct node *root, string s)
{
	bool flag = false;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		int ch = s[i] - '0';
		if (temp -> child[ch] == NULL)
		{
			temp -> child[ch] = newNode();
			flag = true;  
		}
		temp = temp -> child[ch];
		if (temp -> countLeaf == 1)
		{
			flag = false;
			break;
		}
	}
	temp -> countLeaf = 1;
	return flag;
}
//=======================================================================================
void del(node *root)
{
    for (int i = 0; i<MAX; i++)
		if (root->child[i])
		{
			del(root->child[i]);
			delete root->child[i];
		}
}
//=======================================================================================
int main()
{
	int t;
	cin >>t;
	while (t--)
	{
		struct node *root = newNode();
		int n;
		cin >> n;
		bool check = true;
		for (int i = 0; i < n; i++)
		{
			string word;
			cin>>word;
			if (Add(root, word) == false) check = false;
		}
		if (check == true)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		del(root);	
	}
	return 0;
}
