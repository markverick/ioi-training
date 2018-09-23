#include<bits/stdc++.h>
#define M 600000
#define X first
#define Y second
#define MP make_pair;
using namespace std;
int x[200135],y[200135],d[200135],a[300135],b[300135],out[200135];
vector<pair<int,int> > N,Q;
int fx[300135],fy[300135],sq[300135];
void addX(int x,int val)
{
    x++;
    while(x<=300005)
    {
        fx[x]+=val;
        x+=x&-x;
    }
}
int sumX(int x)
{
    x++;
    int sm=0;
    while(x>0)
    {
        sm+=fx[x];
        x-=x&-x;
    }
    return sm;
}
void addY(int x,int val)
{
    x++;
    while(x<=300005)
    {
        fy[x]+=val;
        x+=x&-x;
    }
}
int sumY(int x)
{
    x++;
    int sm=0;
    while(x>0)
    {
        sm+=fy[x];
        x-=x&-x;
    }
    return sm;
}
int main()
{
    int n,q,i,j,k;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        N.emplace_back(b[i]+a[i],i);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&d[i]);
        Q.emplace_back(x[i]+y[i]+d[i],i);
        Q.emplace_back(x[i]+y[i]-1,q+i);
    }
    sort(N.begin(),N.end());
    sort(Q.begin(),Q.end());
    j=0;
    for(i=0;i<q*2;i++)
    {
//        printf("!%d\n",i);
        if(Q[i].Y>q)
        {
            while(j<n&&N[j].X<=Q[i].X)
            {
                addX(a[N[j].Y],1);
                addY(b[N[j].Y],1);
                j++;
            }
            sq[Q[i].Y-q]=sumX(x[Q[i].Y-q]-1)+sumY(y[Q[i].Y-q]-1)-j;
//            printf("Box %d = %d %d %d\n",sq[Q[i].Y-q],sumX(x[Q[i].Y-q]-1),sumY(y[Q[i].Y-q]-1),j);

        }
        else
        {
            while(j<n&&N[j].X<=Q[i].X)
            {
                addX(a[N[j].Y],1);
                addY(b[N[j].Y],1);
                j++;
            }
            out[Q[i].Y]=j-sumX(x[Q[i].Y]-1)-sumY(y[Q[i].Y]-1)+sq[Q[i].Y];
//            printf("Out %d = %d %d %d %d\n",out[Q[i].Y],j,sumX(x[Q[i].Y]-1),sumY(y[Q[i].Y]-1),sq[Q[i].Y]);
        }
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",out[i]);
    }
}
