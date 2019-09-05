#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<int> res;
    res.push_back(nums[0]);
    for(int i=1; i<nums.size(); i++) {
        if(nums[i]<res[0])
        res[0]=nums[i];
        else if(nums[i]>res[res.size()-1])
        res.push_back(nums[i]);
        else
        {
            int idx = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
            if(idx<res.size())
            res[idx]=nums[i];

        }

    }
    cout<<res.size()<<"\n";
}