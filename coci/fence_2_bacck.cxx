#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int h[1000135],qs[1000135],x[1000135];
stack<pair<int,int> > st;
vector<pair<int,int> > v[1000135];
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int n,i,j,k,w;
	scanf("%d %d",&n,&w);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    st.emplace(0,1);
    for(i=1;i<=n+1;i++)
    {
        if(h[i]==h[i-1])
            continue;
        if(h[i]<=h[st.top().X])
        {
            while(!st.empty()&&h[i]<=h[st.top().X])
            {
                if(i-st.top().Y>=w)
                    v[h[st.top().X]].emplace_back(st.top().Y,i-1);
                k=st.top().Y;
                st.pop();
            }
            st.emplace(i,k);
        }
        else
        {
            st.emplace(i,i);
        }
    }
//    sort(v.begin(),v.end());
//    for(i=1;i<=1000;i++)
//    {
//        if(!v[i].empty())
//        {
//            for(j=0;j<v[i].size();j++)
//                printf("%d %d %d\n",i,v[i][j].X,v[i][j].Y);
//        }
//    }
    int a,b,c=0;
    for(i=1;i<=1000000;i++)
    {
        if(!v[i].empty())
        {
            qs[v[i][v[i].size()-1].X]+=i-c;
            qs[v[i][v[i].size()-1].Y+1]-=i-c;
            for(j=v[i].size()-2;j>=0;j--)
            {
                if(v[i][j].X==v[i][j+1].X)
                    continue;
                qs[v[i][j].X]+=i-c;
                qs[v[i][j].Y+1]-=i-c;
            }
            c=i;
        }
    }
    long long mn=0;
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1]+qs[i];
        mn+=h[i]-x[i];
//        printf("%d ",x[i]);
    }
//    printf("\n");
    printf("%lld\n",mn);
    memset(qs,0,sizeof qs);
    int sum=0;
    for(i=1;i<=n;i++)
    {
        if(x[i]>x[i-1])
        {
            if(i+w<=n+1&&x[i+w]>=x[i+w-1])
            {
//                printf("%d <-> %d\n",i,i+w-1);
                qs[i]++,qs[i+w]--,sum++;
            }
        }
    }
    for(i=n+1;i>1;i--)
    {
        if(x[i-1]>x[i])
            qs[i]--,qs[i-w]++,sum++;
    }
//    printf("%d\n",sum);
    memset(x,0,sizeof x);
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1]+qs[i];
//        printf("%d ",x[i]);
    }
//    printf("\n");
    for(i=2;i<=n;i++)
    {
        if(x[i]==0&&x[i-1])
        {
            k=min(n+1,i+w);
            for(j=i;j<k;j++)
                x[j]=1;
            i=j-1;
            sum++;
        }
    }
    printf("%d",sum);
}
