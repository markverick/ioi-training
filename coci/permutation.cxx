#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[200135],x;
void build(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=1;
        return;
    }
    build(id*2,fs,md);
    build(id*2+1,md+1,ls);
    seg[id]=seg[id*2]+seg[id*2+1];
}
void Del(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=0;
        return;
    }
    if(x<=md)
        Del(id*2,fs,md);
    else
        Del(id*2+1,md+1,ls);
    seg[id]=seg[id*2]+seg[id*2+1];
}
int sum(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
        return fs;
    if(x>=seg[id*2])
    {
        x-=seg[id*2];
        return sum(id*2+1,md+1,ls);
    }
    else
        return sum(id*2,fs,md);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k,a,y,n;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
        build(1,1,n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            x=a;
            y=sum(1,1,n);
            printf("%d",y);
            if(i<n)printf(" ");
            x=y;
            Del(1,1,n);
        }
        printf("\n");
    }
}
