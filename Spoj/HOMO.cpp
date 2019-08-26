#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	map <int,int>m;
	set <int>st;
	int is=0,de=0;
	while(n--)
	{
	    string s;
	    int i;
	    cin>>s;
	    cin>>i;
	    if(s[0]=='i')
	    {
	        m[i]++;
	        st.insert(i);
	        is++;
	    }
	    else
	    {
	        if(m.count(i)!=0)
	        {
                
	            if(m[i]==1)
	            {
	                m.erase(m.find(i));
	                st.erase(st.find(i));
	                de++;
	            }
	            else
	            {
	                m[i]--;
	                de++;
	            }
	        }
	    }
       // cout<<"set_size "<<st.size()<<" insertion and deletion "<<is<<" "<<de<<"\n";
	    if(st.size()>1&&(is-de)>st.size())
	    {
	        cout<<"both\n";
	    }
	    else if(st.size()>1)
	    cout<<"hetero\n";
	    else if(is-de>st.size())
	    cout<<"homo\n";
	    else
	    cout<<"neither\n";
	}
	return 0;
}
