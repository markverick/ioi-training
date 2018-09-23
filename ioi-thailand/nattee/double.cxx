#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,all=0,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        all+=a[i];
    }
    if(all%2)
    {
        printf("NO");
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(sum+a[i]>all/2)
            break;
        sum+=a[i];
    }
    if(sum==all/2)
    {
        printf("%d\n",i-1);
        return 0;
    }
    j=n;
    pair<int,int> mn=MP(MI,MI);
    for(i=i-1;i>=1;i--)
    {
        while(sum+a[j]<=all/2)
        {
            sum+=a[j];
            j--;
        }
//        printf("%d %d\n",i-1,j);
        if(sum==all/2)
        {
            mn=min(mn,MP(i,j));
        }
        sum-=a[i];
    }
    if(mn.X<MI)
        printf("%d %d",mn.X,mn.Y);
    else
        printf("NO");
}
