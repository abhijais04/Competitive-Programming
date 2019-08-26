#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool visited[1010000];
int val[1000100];
int par[1000100];
void pr(int x)
{
	if (x == -1)
		return;
	pr(par[x]);
	cout << val[x];
}
void bfs(ll n)
{
	ll x = 1 % n;
	visited[x] = 1;
	val[x] = 1;
	par[x] = -1;
	queue<ll> q;
	q.push(x);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (t == 0)
		{
			pr(t);
			cout << "\n";
			return;
			// print answer
		}
		int tt = (10 * t) % n;
		if (!visited[tt])
		{
			q.push(tt);
			visited[tt] = 1;
			val[tt] = 0;
			par[tt] = t;
		}
		tt = (tt + 1) % n;
		if (!visited[tt])
		{
			q.push(tt);
			visited[tt] = 1;
			val[tt] = 1;
			par[tt] = t;
		}
	}
}
void solve()
{
	ll n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		visited[i] = false;
		par[i] = 0;
	}
	bfs(n);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}