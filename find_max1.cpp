#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int hsh[120000];
int result[100];
int val=1;
void gen(int idx)
{
    if(idx==v.size())
    {
        //printf("%d\n",v.size());
        val=v[v.size()-1];
        int i,j,k;

        for(i=v.size()-2;i>=0;i--)
        {
            if(result[i]==1)
            {
                val*=10;
                val+=v[i];
            }
        }
        //printf("%d\n",val);
        hsh[val]++;
        return;
    }
    result[idx]=0;
    gen(idx+1);
    result[idx]=1;
    gen(idx+1);
}
int main()
{
    int x,y,a,b,i,j,k,idx;
    for(i=1;i<=10;i++)
    {
        a=i;
        idx=0;
        v.clear();
        while(a>0)
        {
            v.push_back(a%10);
            a/=10;
        }
        sort(v.begin(),v.end());
        //printf("%d\n",i);
        gen(0);
    }
    for(i=0;i<=10;i++)
    {
        printf("%d\n",hsh[i]);
    }
    while(scanf("%d %d",&x,&y)!=EOF)
    {

    }
}
