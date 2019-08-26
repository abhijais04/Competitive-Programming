#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int n;
vector <int>adj[10100],costs[10100],indexx[10100];
int basearray[10100],chainindex[10100],chainhead[10100],posinbase[10100],depth[10100],pa[14][10100],otherend[10100],subsize[10100];
int st[60600],qt[60600];
int chainno,ptr;
void make_tree(int cur , int s,int e)
{
    if(s==e-1)
    {
        st[cur] = basearray[s];
        return;
    }
    int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	return ;
}

void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	return ;
}



void query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		qt[cur] = -1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m, e, S, E);
	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
}






int query_up(int u, int v) {
	if(u == v) return 0; // Trivial
	int uchain, vchain = chainindex[v], ans = -1;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainindex[u];
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v) break;
			query_tree(1, 0, ptr, posinbase[v]+1, posinbase[u]+1);
			// Above is call to segment tree query function
			if(qt[1] > ans) ans = qt[1]; // Update answer
			break;
		}
		query_tree(1, 0, ptr, posinbase[chainhead[uchain]], posinbase[u]+1);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		if(qt[1] > ans) ans = qt[1];
		u = chainhead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}


int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<14; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=14-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}


void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ans = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	if(temp > ans) ans = temp; // take the maximum of both paths
	printf("%d\n", ans);
}

void change(int i, int val) {
	int u = otherend[i];
	update_tree(1, 0, ptr, posinbase[u], val);
}


void dfs(int cur,int pre , int dpth=0)
{
    pa[0][cur]=pre;
    depth[cur] = dpth;
    subsize[cur]=1;
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]!=pre)
        {
            otherend[indexx[cur][i]] = adj[cur][i];
            dfs(adj[cur][i],cur,dpth+1);
            subsize[cur]+=subsize[adj[cur][i]];
        }
    }
    return ;
}
void hld(int curnode , int cost ,int pre)
{
    if(chainhead[chainno]==-1)
    {
        chainhead[chainno] = curnode;
    }
    chainindex[curnode] = chainno;
    posinbase[curnode] = ptr;
    basearray [ptr++] = cost;
    int sc=-1,ncost  = 0;


        for(int i=0;i<adj[curnode].size();i++)
        {
            if(adj[curnode][i]!=pre)
           {

            if(sc==-1||subsize[sc] < subsize[adj[curnode][i]])
            {

                sc = adj[curnode][i];
                ncost = costs[curnode][i];
            }
           }
        }
        if(sc!=-1)
        {
            hld(sc,ncost , curnode);
        }

        for(int i=0;i<adj[curnode].size();i++)
        {
            if(adj[curnode][i]!=pre)
            if(sc!=adj[curnode][i])
            {
                chainno++;
                hld(adj[curnode][i] , costs[curnode][i] , curnode);
            }
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ptr=0;
        cin>>n;
        for(int i=0; i<n; i++) {
                //cout<<i<<"\n";
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainhead[i] = -1;
			for(int j=0; j<14; j++) pa[j][i] = -1;
		}
        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
        cin>>a>>b>>c;
            a--;
            b--;
            adj[a].pb(b);
            indexx[a].pb(i);
            indexx[b].pb(i);
            costs[a].pb(c);
            costs[b].pb(c);
            adj[b].pb(a);
        }
        chainno = 0;
        dfs(0 , -1 , 0);
       // cout<<"dfs\n";
        hld(0,-1,-1);
        //cout<<"dfs\n";
        make_tree(1 ,0 ,ptr);
        //cout<<"dfs\n";
        for(int i=1;i<14;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(pa[i-1][j]!=-1)
                pa[i][j] = pa[i-1][pa[i-1][j]];
            }
        }


        while(1) {
			char s[100];
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				query(a-1, b-1);
			} else {
				change(a-1, b);
			}
		}
    }
}
