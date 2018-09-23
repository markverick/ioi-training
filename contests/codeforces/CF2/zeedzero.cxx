#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,a,i,zero,ans;
    long long m,accum;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=n+1;
        accum=0;
        zero=-1;
        map<long long,int> pos,neg;
        map<long long,int>::iterator it,tmp,target;
        for(i=0;i<n;i++)
        {
            cin>>a;
            accum+=a;
            if(accum>=m)
            {
                it=neg.lower_bound(m-accum);
                if(it!=neg.end())
                {
                    ans=min(ans,i-it->second);
                }
                ans=min(ans,i-zero);
            }
            else
            {
                it=pos.lower_bound(m-accum);
                if(it!=pos.end())
                {
                    ans=min(ans,i-it->second);
                }
            }
            if(accum==0)
            {
                zero=i;
            }
            else if(accum<0)
            {
                pos[-accum]=i;
                target=pos.find(-accum);
                for(it=pos.begin();it!=target;)
                {
                    tmp=it;
                    it++;
                    pos.erase(tmp);
                }
            }
            else
            {
                neg[-accum]=i;
                target=neg.find(-accum);
                for(it=neg.begin();it!=target;)
                {
                    tmp=it;
                    it++;
                    neg.erase(tmp);
                }
            }
        }
        if(ans==n+1)ans=-1;
        cout<<ans<<endl;
    }
}
