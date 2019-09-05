#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    {
        double r,x1,y1,x2,y2;
        cin>>r>>x1>>y1>>x2>>y2;
        double ds = (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        r=2*r;
        int steps = (int)ds/r;
        double rm = ds-(double)steps*r;
        if(rm>0.0)
            steps++;
        cout<<steps<<"\n";
    }
}