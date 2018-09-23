#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long x[10135],y[10135],p[10135],q[10135],r[10135];
vector<tuple<long long,long long,long long> > v;
int main()
{
    long long i,j,k,T,X,B,C,fst,mid,lst,sum,ch,id,fk=0,mn;
    scanf("%lld",&T);
    while(T--)
    {
        v.clear();
        scanf("%lld",&X);
        scanf("%lld",&B);
        for(i=1;i<=B;i++)
        {
            scanf("%lld %lld",&x[i],&y[i]);
            v.emplace_back(x[i],1,i);
        }
        scanf("%lld",&C);
        for(i=1;i<=C;i++)
        {
            scanf("%lld %lld %lld",&p[i],&q[i],&r[i]);
            v.emplace_back(p[i],2,i);
        }
        sort(v.begin(),v.end());
        fst=0;lst=4000000000000000000;mn=4000000000000000000;sum=0;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
//            printf("%lld <- %lld -> %lld\n",fst,mid,lst);
            sum=mid;fk=0;
            for(i=0;i<v.size();i++)
            {
                tie(k,ch,id)=v[i];
                if(ch==1)
                {
//                    printf("!! %lld %lld\n",sum,id);
                    if(sum>y[id])
                    {
                        sum-=y[id];
                    }
                    else
                    {
                        fk=1;break;
                    }
                }
                else
                {
                    if(sum>=q[id])
                    {
                        sum+=r[id];
                    }
                }
            }
            if(fk==0)
            {
                mn=min(mn,mid);
                lst=mid-1;
            }
            else
            {
                fst=mid+1;
            }
        }
        printf("%lld\n",mn);
    }
}
