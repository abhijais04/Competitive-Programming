#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int eos;
	node *child[12];
	node()
	{
        this->eos=0;
        for(int i=0;i<10;i++)
        {
            this->child[i]=NULL;
        }
	}
};
void add(node* root,string str,int idx)
{
    if(root==NULL)
        return ;
	if(idx==str.length())
	{
		root->eos++;
		return;
	}
	if(root->child[(int)(str[idx]-'0')]==NULL)
	{
		root->child[(int)(str[idx]-'0')]=new node();
	}
	add(root->child[(int)(str[idx]-'0')],str,idx+1);
	return;
}
int find(node* root,string str,int idx)
{
	if(root==NULL) return 0;
	if(str.length()==idx)
	{
		return root->eos;
	}
	else if(root->child[(int)(str[idx]-'0')]==NULL) return 0;
	return find(root->child[(int)(str[idx]-'0')],str,idx+1);
}
bool traverse(node *root)
{
	if(root==NULL)
	return false;
	if(root->eos!=0)
	{
		for(int i=0;i<10;i++)
		 if(root->child[i]!=NULL)
		 return true;
		return false;

	}
	for(int i=0;i<10;i++)
	{
		if(root->child[i])
		{
			if(traverse(root->child[i])==true)
			return true;
		}
	}
	return false;
}
void del(node* cur)
{
	if(cur==NULL)
	return ;
	for(int i=0;i<10;i++)
	{
		del(cur->child[i]);
	}
	free(cur);
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		node* root=new node();
		int n;
		scanf("%d",&n);
		int tmp=0;
		for(int i=0;i<n;i++)
		{
			string stmp;
			cin>>stmp;
			add(root,stmp,0);
		}
		tmp = traverse(root);
		if(tmp==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		del(root);
	}
	return 0;
}
