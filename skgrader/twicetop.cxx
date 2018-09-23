#include<bits/stdc++.h>
using namespace std;
char s[200005];
tuple<int,int,int> fs[200005];
int p[20][200005],n;
int com(int a,int b,int kb)
{
    int res=0;
    for(int i=kb-1;i>=0;i--)
    {
        if(a+(1<<i)<=n&&b+(1<<i)<=n&&p[i][a]==p[i][b])
        {
            a+=1<<i;
            b+=1<<i;
            res+=1<<i;
        }
    }
    return res;
}
int main()
{
    int i,j,st,mc=0,kb;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<n;i++)
        p[0][i]=s[i];
    for(i=1,st=1;st<n;i++,st<<=1)
    {
        for(j=0;j<n;j++)
        {
            get<0>(fs[j])=p[i-1][j];
            get<1>(fs[j])= j+st<n ? p[i-1][j+st] : -1;
            get<2>(fs[j])=j;
        }
        sort(fs,fs+n);
        for(j=0;j<n;j++)
            p[i][get<2>(fs[j])]= j>0 && get<0>(fs[j])==get<0>(fs[j-1]) && get<1>(fs[j])==get<1>(fs[j-1]) ? p[i][get<2>(fs[j-1])] : j;
    }
    kb=i;
    for(i=1;i<n;i++)
        mc=max(mc,com(get<2>(fs[i]),get<2>(fs[i-1]),kb));
    printf("%d\n",mc);
}
