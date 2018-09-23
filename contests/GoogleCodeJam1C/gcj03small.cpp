#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
int a[120];
int c,d,v;
char hsh[120];
char inhsh[120];
int jum[120];
int cot=0;
int c2;
void gen(int coin,int val)
{
    if(hsh[val]==0)
    {
        c2++;
        hsh[val]=1;
    }
    if(coin==d)
    {
        return;
    }
    int i;
    for(i=1;i<=c;i++)
    {
        val+=a[coin];
        gen(coin+1,val);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,T,i,j,k;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        cot=0;
        c2=0;
        //hsh.clear();
        scanf("%d %d %d",&c,&d,&v);
        for(i=0;i<d;i++)
        {
            scanf("%d",&a[i]);
            inhsh[a[i]]=1;
        }
        sort(&a[0],&a[d]);
        gen(0,0);
        for(i=1;i<=v;i++)
        {
            cot=0;
            if(inhsh[i]==1)
                continue;
            for(j=i;j<=v;j+=i)
            {
                if(hsh[j]==0)
                    cot++;
            }
            jum[i]=cot;
        }
        for(i=1;i<=v;i++)
        {

        }
        printf("Case #%d :%d\n",t,v-c2);
    }
}

