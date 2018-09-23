#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int as[4000],bs[4000],sa[4000],sb[4000];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,ch,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d:%d",&ch,&a,&b);
        if(ch==1)as[a*60+b]++;
        else bs[a*60+b]++;
    }
    if(as[0])sa[0]=1;
    if(bs[0])sb[0]=1;
    for(i=1;i<=3000;i++)
    {
        sa[i]=sa[i-1]+as[i];
        sb[i]=sb[i-1]+bs[i];
    }
    int A=0,B=0;
    for(i=0;i<=2879;i++)
    {
        if(sa[i]>sb[i])
            A++;
        else if(sa[i]<sb[i])
            B++;
    }
    printf("%02d:%02d\n%02d:%02d",A/60,A%60,B/60,B%60);
}
