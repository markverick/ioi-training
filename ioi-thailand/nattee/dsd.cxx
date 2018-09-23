#include<bits/stdc++.h>
using namespace std;
int mem[1005],p[1005];
stack<int> st;
class yoyo
{
public:
    int w,x,y,idx;
    bool operator < (const yoyo &b)
    {
        return true;
    }
    void ass(int a,int b,int c,int d)
    {
        w=a;
        x=b;
        y=c;
        idx=d;
    }
} a[1005];
/*
bool cmp(const sch &a,const sch &b)
{

}
*/
int main()
{
    int n,i,j,w,x,y,mc=0,kb;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y,&w);
        a[i].ass(w,x,y,i);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
        for(j=0;j<i;j++)
        {
            if(a[j].y>a[i].x) break;
            if(mem[j]>mem[p[i]]) p[i]=j;
        }
        mem[i]=mem[p[i]]+a[i].w;
        if(mem[i]>mem[mc]) mc=i;
    }
    kb=mem[mc];
    while(p[mc]!=mc)
    {
        st.push(mc);
        mc=p[mc];
    }
    printf("%d\n%d\n",st.size(),kb);
    while(!st.empty()) printf("%d ",st.top()),st.pop();

}
