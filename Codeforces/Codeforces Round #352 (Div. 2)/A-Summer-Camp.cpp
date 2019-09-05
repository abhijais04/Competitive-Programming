#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int>v;
    v.push_back(0);
    int i=1;
    while(v.size()<1002)
    {
        int tmp=i;
        vector <int>vtm;
        while(tmp)
        {
            vtm.push_back(tmp%10);
            tmp/=10;
        }
        for(int j=vtm.size()-1;j>=0;j--)
            v.push_back(vtm[j]);
        i++;
    }
  //  while(1)
    int n;
    cin>>n;
    cout<<v[n];
    return 0;
}