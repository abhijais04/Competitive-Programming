#include <bits/stdc++.h>
using namespace std;
string str;
int l;
int z[2000100];
void compute_z(string s)
{
    int L = 0, R = 0;
    int n = s.length();
    for (int i = 1; i < n; i++) {
    if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
       z[i] = R-L; R--;
    }   else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
        }
    }
    }
    
}
int check_suffix(int x)
{
    string pre = "",post="";
    for(int i=0;i<x;i++)
    {
        pre+=str[i];
        post+=str[l-x+i];
    }
    pre = pre+"$"+post;
    compute_z(pre);
    
    for(int i = x;i<2*x+1;i++)
    {
        if(z[i]+i==2*x+1)
        {
            return z[i];
        }
    }
    return 0;
}
bool check(int x)
{
    //string tmp="";
    for(int i=1;i<l-x;i++) {if(z[i]>=x) return true;}
    return false;
}

int main() {
	cin>>str;
	l = str.length();
	compute_z(str);
	int low = 1,high = l-1;
	int mid=0;
	while(low<=high)
	{
	    mid = (low+high)/2;
	    if(check(mid)) low = mid+1;
	    else high = mid-1;
	}
	//cout<<"High : "<<high<<"\n";
	
	if(high==0)
	{
	    cout<<"Just a legend\n";
	    return 0;
	}
	
	int y = check_suffix(high);
	//cout<<"y : "<<y<<"\n";
	
	if(y==0)
	{
	    cout<<"Just a legend\n";
	    return 0;
	}
	
	
	string t = str.substr(0,y);
	cout<<t<<"\n";
	return 0;
}