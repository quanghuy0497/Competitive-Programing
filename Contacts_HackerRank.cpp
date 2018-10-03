//https://www.hackerrank.com/challenges/contacts/problem
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
	int  countLeaf;
};
//=========================================================================
struct node *newNode()
{
	struct node *Node = new struct node;
	Node->countLeaf = 0;
	Node ->weight = 0;
	for (int i = 0; i < MAX; i++)
		Node->child[i] = NULL;
	return Node;
}
//=========================================================================
void Add(struct node *root, string s)
{
	int ch;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp -> child[ch] == NULL)
		  temp -> child[ch] = newNode();
		temp = temp -> child[ch];
		temp -> weight++;
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
		if (temp -> child[ch] == NULL) return 0;
		temp = temp -> child[ch];
		max = temp ->weight;
	}
	return max;
}
//=========================================================================
int main()
{
	struct node *root = newNode();
	int n;
	cin >>n;
	for (int i = 0; i < n; i++)
	{
		string com, word;
		cin >> com>> word;
		if (com == "add")
		  Add(root, word);
		if (com == "find")
		  cout<<Find(root, word)<<endl;
	}
	
	return 0;
}
