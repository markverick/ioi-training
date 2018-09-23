#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
pair<long long,long long> p[100135];
set<pair<long long,long long> > st;
set<pair<long long,long long> > ::iterator it;
set<pair<long long,long long> > ::iterator it2;
long long dist(long long a,long long b)
{
    return abs(p[a].X-p[b].X)+abs(p[a].Y-p[b].Y);
}
int main()
{
    long long i,j,k,n,m;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].Y,&p[i].X);
    }
    if(m==1)
    {
        printf("0\n");return 0;
    }
    sort(&p[1],&p[n+1]);
//    printf("\n");
//    for(i=1;i<=n;i++)
//    {
//        printf("%lld %lld\n",p[i].Y,p[i].X);
//    }
    long long sum=0;
    for(i=1;i<=m;i++)
    {
        st.insert(MP(p[i].Y,i));
    }
    it2=st.begin();
    it2++;
    for(it=st.begin();it2!=st.end();it++,it2++)
    {
        sum+=dist((*it).Y,(*it2).Y);
//        printf("%lld + %lld = %lld\n",(*it).Y,(*it2).Y,sum);
    }
    long long mn=sum;
    for(i=m+1;i<=n;i++)
    {
        it=st.lower_bound(MP(p[i].Y,0));
        if(it==st.begin())
        {
            sum+=dist(i,(*it).Y);
        }
        else if(it==st.end())
        {
            it--;
            sum+=dist(i,(*it).Y);
        }
        else
        {
            sum+=dist(i,(*it).Y);
            it2=it;
            it--;
            sum+=dist(i,(*it).Y);
            sum-=dist((*it).Y,(*it2).Y);
        }
//        printf("%lld\n",sum);
        st.insert(MP(p[i].Y,i));
        it=st.find(MP(p[i-m].Y,i-m));
//        if(it==st.end())
//        {
//            printf("VALUE IN SET NOT FOUND\n");
//            printf("%lld",5/0);
//            return 0;
//        }
        if(it==st.begin())
        {
            it2=it;it2++;
            sum-=dist((*it).Y,(*it2).Y);
        }
        else if(++it==st.end())
        {
            it--;
            it2=it;it2--;
            sum-=dist((*it).Y,(*it2).Y);
        }
        else
        {
            it=st.find(MP(p[i-m].Y,i-m));it--;
            it2=it;
            it++;
            sum-=dist((*it).Y,(*it2).Y);
            it++;it2++;
            sum-=dist((*it).Y,(*it2).Y);
            it2--;
            sum+=dist((*it).Y,(*it2).Y);
        }
        it=st.find(MP(p[i-m].Y,i-m));
        st.erase(it);
//        printf("%lld size = %lld\n",sum,st.size());
        mn=min(mn,sum);
    }
    printf("%lld",mn);

}
