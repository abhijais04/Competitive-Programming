#include<bits/stdc++.h>
#define pb push_back
#define gc getchar_unlocked
using namespace std;
vector <int>s1,s2;
int v[4][4100];
int bs(int val)
{
    int low=0,high=s2.size(),mid,sz=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(s2[mid]==val)
        {
            int tmp=mid-1;
          //  int tmp2=mid;
            while(mid<s2.size()&&s2[mid]==val)
            {
                sz++;
                mid++;
                //tmp2++;
            }
            while(tmp>=0&&s2[tmp]==val)
            {
                sz++;
                tmp--;
            }
            return sz;
        }
        else if(s2[mid]>val)
        high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
int main()
{
  //  ios_base::sync_with_stdio (false);
    //cin.tie(NULL);
    int n,i,j;
    scanf("%d",&n);
    //read(n);

    //cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&v[j][i]);
           //cin>>x;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            s1.pb(v[0][i]+v[1][j]);
            s2.pb(-1*(v[2][i]+v[3][j]));
        }
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int ans=0;
    for(i=0;i<s1.size();)
    {
        int sz1=0,sz2=bs(s1[i]);
        int tmp=s1[i];
        while(i<s1.size()&&s1[i]==tmp)
            {
                i++;
                sz1++;
            }
        ans+=(sz1*sz2);
    }
    printf("%d\n",ans);
    //write(ans);
}
