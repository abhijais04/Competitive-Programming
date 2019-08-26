#include<iostream>
using namespace std;
bool visited[100010];
int f;
struct node
{
	int val;
	node *next;
	node(){}
	node(int _x)
	{
		val = _x;
		next = NULL;
	}
};
struct adjlist
{
	int val;
	node *head;
	node *tail;
	adjlist(){}
	adjlist(int _val)
	{
		val = _val;
		head = NULL;
		tail = NULL;
	}
};
adjlist arr[100010];
void addEdge(int a,int b)
{
	// add a directed Edge between a and b
	node *tmp = new node(b);
	if (arr[a].tail== NULL)
	{
		arr[a].head = arr[a].tail = tmp;
	}
	else
	{
		arr[a].tail->next = tmp;	
		arr[a].tail = arr[a].tail->next;
	}
}
void dfs(int x,int par)
{
	if (visited[x])
	{
		f = 0;
		return;
	}
	visited[x] = 1;
	node *tmphead = arr[x].head;
	while (tmphead != NULL)
	{
		if (tmphead->val!=par)
		dfs(tmphead->val,x);
		tmphead = tmphead->next;
	}
	return;
}
int main()
{
	int n, m;
	f = 1;
	cin >> n >> m;
	if (n - 1 != m)
		f = 0;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		addEdge(a, b);
		addEdge(b, a);
	}
	dfs(1,0);
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			f = 0;
	}

	if (f)
		cout << "YES\n";
	else
	cout << "NO\n";

	return 0;
}