#include<bits/stdc++.h>
using namespace std;
long long a[300000];
long long merge(long long arr[],long long l,long long m,long long r)
{
    long long ans=0;
    long long i,j,k;
    long long n1,n2;
    n1 = m-l+1;
    n2 = r-m;
    long long la[n1],rgt[n2];
    for(i=0;i<n1;i++)
    {
        la[i]=arr[l+i];
    }
    for(i=0;i<n2;i++)
    {
        rgt[i]=arr[m+1+i];
    }

    i=0;j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(la[i]<=rgt[j])
        {
            arr[k]=la[i];
            k++;
            i++;
        }
        else
        {
            ans+=(n1-i);
            arr[k]=rgt[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k++]=la[i++];
    }
    while(j<n2)
    {
        arr[k++]=rgt[j++];
    }
    return ans;

}
long long mergesort(long long arr[],long long l,long long r)
{
    long long inv_cnt=0;
    if(l<r)
    {
        long long mid = l+(r-l)/2;
        inv_cnt+=mergesort(arr,l,mid);
        inv_cnt+= mergesort(arr,mid+1,r);
        inv_cnt+=merge(arr,l,mid,r);
    }
    return inv_cnt;
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        scanf("\n");
    	long long n;
    cin>>n;
    long long i;
    for(i=0;i<n;i++)
        cin>>a[i];
    long long ans = mergesort(a,0,n-1);
    cout<<ans<<"\n";
    }
    //for(i=0;i<n;i++)
    //    cout<<a[i]<<" ";
    return 0;
}
