#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char str[20];
int n;
int rev(int x)
{
    int i=0;
    while(x>=1)
    {
        str[i++]=x%10+'0';
        x/=10;
    }
    str[i]=0;
    int a;
    sscanf(str,"%d",&a);
    //printf("%d\n",a);
    return a;
}

int dp(int idx,int b4)
{
    printf("%d <- %d\n",idx,b4);
    //system("pause");
    if(idx<=0||idx>n*10)
        return 99999999;
    if(idx==1)
        return 0;
    //printf("%d %d\n",idx,rev(idx));
    int b=rev(idx);
    if(b!=b4&&b!=idx&&b<=idx*10)
        return min(dp(idx-1,idx),dp(b,idx))+1;
    else return dp(idx-1,idx)+1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,i,j,k;
    //printf("%d\n",rev(15));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",dp(n,0));
    }
}

