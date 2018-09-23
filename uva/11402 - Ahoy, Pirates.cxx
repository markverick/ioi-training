#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[55];
string str;
int seg[4100000],x,y,val,lv;
int lazy[4100000];
int tl[4100000],ti[4100000];
void upt(int id,int op,int fs,int ls)
{
    switch(op)
    {
    case 1: ///Invert
        switch(lazy[id])
        {
        case 1:
            seg[id]=ls-fs+1-seg[id];lazy[id]=0;break;
        case 0:
            seg[id]=ls-fs+1-seg[id];lazy[id]=1;break;
        case 2:
            seg[id]=0;lazy[id]=3;break;
        case 3:
            seg[id]=ls-fs+1;lazy[id]=2;break;
        }
        break;
    case 2:
        seg[id]=ls-fs+1;lazy[id]=2;
        break;
    case 3:
        seg[id]=0;lazy[id]=3;
        break;
    }
}
void shift(int id,int fs,int ls)
{
    if(lazy[id]>=0)
    {
        int md=(fs+ls)/2;
        upt(id*2,lazy[id],fs,md);
        upt(id*2+1,lazy[id],md+1,ls);
        lazy[id]=0;
    }
}
void build(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(fs==ls)
    {
        seg[id]=str[fs]-'0';
        return;
    }
    build(id*2,fs,md);
    build(id*2+1,md+1,ls);
    seg[id]=seg[id*2]+seg[id*2+1];
}
void update(int id,int op,int fs,int ls)
{
    int md=(fs+ls)/2;
    if(ls<x||fs>y)
        return;
    if(fs>=x&&ls<=y)
    {
        update(id,op,fs,ls);
        shift(id,fs,ls);
        return;
    }
    shift(id,fs,ls);
    update(id*2,op,fs,md);
    update(id*2+1,op,md+1,ls);
    seg[id]=seg[id*2]+seg[id*2+1];
}
int sum(int id,int fs,int ls)
{
    int md=(fs+ls)/2;
    shift(id,fs,ls);
    if(ls<x||fs>y)
        return 0;
    if(fs>=x&&ls<=y)
        return seg[id];
    return sum(id*2,fs,md)+sum(id*2+1,md+1,ls);
}
int main()
{
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,T,n,m,len,Q,q=1,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(lazy,0,sizeof lazy);
        memset(seg,0,sizeof seg);
        str.clear();
        scanf("%d",&n);
        q=1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            scanf("%s",s);
            while(m--)
            {
                str+=s;
            }
        }
        len=str.size();
        build(1,0,len-1);
//        printf("%s\n",str);
        printf("Case %d:\n",t);
        scanf("%d",&Q);
        lv=1;
        while(Q--)
        {
            scanf("%s %d %d",s,&x,&y);
            if(s[0]=='F')
            {
                val=1;
                update(1,2,0,len-1);
            }
            else if(s[0]=='E')
            {
                val=0;
                update(1,3,0,len-1);
            }
            else if(s[0]=='I')
            {
                update(1,1,0,len-1);
            }
            else
            {
                printf("Q%d: %d\n",q,sum(1,0,len-1));
                q++;
            }
            lv++;
        }
    }
}
