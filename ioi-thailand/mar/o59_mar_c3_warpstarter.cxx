#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
pair<int,int> p[100135];
set<pair<int,int> > st;
set<pair<int,int> > ::iterator it;
set<pair<int,int> > ::iterator it2;
int dist(int a,int b)
{
    return abs(p[a].X-p[b].X)+abs(p[a].Y-p[b].Y);
}
int main()
{
    int i,j,k,n,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].Y,&p[i].X);
    }
    sort(&p[1],&p[n+1]);
//    printf("\n");
//    for(i=1;i<=n;i++)
//    {
//        printf("%d %d\n",p[i].Y,p[i].X);
//    }
    int sum=0;
    for(i=1;i<=m;i++)
    {
        st.insert(MP(p[i].Y,i));
    }
    it2=st.begin();
    it2++;
    for(it=st.begin();it2!=st.end();it++,it2++)
    {
        sum+=dist((*it).Y,(*it2).Y);
//        printf("%d + %d = %d\n",(*it).Y,(*it2).Y,sum);
    }
    int mn=sum;
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
//        printf("%d\n",sum);
        st.insert(MP(p[i].Y,i));
        it=st.find(MP(p[i-m].Y,i-m));
//        if(it==st.end())
//        {
//            printf("VALUE IN SET NOT FOUND\n");
//            return 0;
//        }
        if(it==st.begin())
        {
            it2=it;it2++;
            sum-=dist((*it).Y,(*it2).Y);
        }
        else if(--it==st.end())
        {
            it2=it;it2--;
            sum-=dist((*it).Y,(*it2).Y);
        }
        else
        {
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
//        printf("%d size = %d\n",sum,st.size());
        mn=min(mn,sum);
    }
    printf("%d",mn);

}
