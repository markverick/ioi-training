#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[800135],L[800135],R[800135],a[800135],x;
void build(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=0;L[id]=1;R[id]=1;
        return;
    }
    build(id*2,fs,md);
    build(id*2+1,md+1,ls);
    if(ls-fs+1==2)
        seg[id]=0;
    else
        seg[id]=1;
    L[id]=1;R[id]=1;
}
void update(int id,int fs,int ls)
{
    int md=(fs+ls)/2,tmp;
    if(fs==ls)
    {
        a[fs]=1-a[fs];
        seg[id]=0;L[id]=1;R[id]=1;
        return;
    }
//    else if(fs+1==ls)
//    {
//        update(id*2,fs,md);
//        update(id*2+1,md+1,ls);
//        if(a[fs]==a[ls])
//
//
//    }
    if(x<=md)
    {
        update(id*2,fs,md);
    }
    else
    {
        update(id*2+1,md+1,ls);
    }
    seg[id]=max(seg[id*2],seg[id*2+1]);
    if(a[md]!=a[md+1])
    {
        tmp=R[id*2]+L[id*2+1];
        if(R[id*2]==md-fs+1)tmp--;
        if(L[id*2+1]==ls-md)tmp--;
        seg[id]=max(seg[id],tmp);
    }
    else
    {
        tmp=L[id*2+1];
        if(L[id*2+1]==ls-md)tmp--;
        seg[id]=max(seg[id],tmp);
        tmp=R[id*2];
        if(R[id*2]==md-fs+1)tmp--;
        seg[id]=max(tmp,seg[id]);
    }
    if(L[id*2]==md-fs+1&&a[md]!=a[md+1])
        L[id]=L[id*2]+L[id*2+1];
    else
        L[id]=L[id*2];
    if(R[id*2+1]==ls-md&&a[md]!=a[md+1])
        R[id]=R[id*2]+R[id*2+1];
    else
        R[id]=R[id*2+1];
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,q,i,j,k;
    scanf("%d %d",&n,&q);
	build(1,1,n);
    while(q--)
    {
        scanf("%d",&x);
        update(1,1,n);
//        system("pause");
//        printf("%d %d %d\n",L[1],seg[1],R[1]);
        printf("%d\n",max(seg[1],max(L[1],R[1])));
    }
}
