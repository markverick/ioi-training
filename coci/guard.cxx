#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define INF 1000000000
#define EPS 0.00001
using namespace std;
vector<tuple<int,int,int,int> > v;
bool overlap(tuple<int,int,int,int> a,tuple<int,int,int,int> b)
{
    double i1,i2,i3,i4,k1,k2,k3,k4;
    tie(i1,k1,i2,k2)=a;
    tie(i3,k3,i4,k4)=b;
    double m1,m3,c1,c3,x,y;
    if(abs(i2-i1)>0.0001)
        m1=(k2-k1)/(i2-i1);
    else
        m1=INF;
    if(abs(i4-i3)>0.0001)
        m3=(k4-k3)/(i4-i3);
    else
        m3=INF;
    if(abs(m1-m3)<0.0001)
    {
        return 0;
    }
    else
    {
        c1=k1-m1*i1;c3=k3-m3*i3;
        x=(c1-c3)/(m3-m1);
        y=m1*x+c1;
    }
    printf("%f %f\n",x,y);
    if(i1>i2)swap(i1,i2);
    if(i3>i4)swap(i3,i4);
    if(k1>k2)swap(k1,k2);
    if(k3>k4)swap(k3,k4);
    if(x>=i1-EPS&&x<=i2+EPS&&x>=i3-EPS&&x<=i4+EPS&&
       y>=k1-EPS&&y<=k2+EPS&&y>=k3-EPS&&y<=k4+EPS)
        return 1;
    return 0;

}
int main()
{
	int i,j,k,n,a,b,c,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a!=c||b!=d)
            v.emplace_back(a,b,c,d);
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    int sum=0;
    for(i=0;i<v.size();i++)
    {
        for(j=i+1;j<v.size();j++)
        {
            for(k=j+1;k<v.size();k++)
            {
                if(overlap(v[i],v[j])&&overlap(v[i],v[k])&&overlap(v[j],v[k]))
                   sum++;
            }
        }
    }
    printf("%d",sum);
}
