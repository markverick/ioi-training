#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[305][20005],lazy[305][20005],val,x,y;
multiset<int> st;
void shift(int id,int fs,int ls,int x)
{
    if(lazy[x][id]>=0)
    {
        seg[x][id]=lazy[x][id];
        if(fs!=ls)
        {
            lazy[x][id*2]=lazy[x][id];
            lazy[x][id*2+1]=lazy[x][id];
        }
        lazy[x][id]=-1;
    }
}
void upd(int id,int fs,int ls,int x)
{
    int md=(fs+ls)/2;
    shift(id,fs,ls,x);
//    printf("%d %d %d\n",id,fs,ls);
    if(fs==ls)
    {
        seg[x][id]=val;
        return;
    }
    if(y<=md)
        upd(id*2,fs,md,x);
    else
        upd(id*2+1,md+1,ls,x);
    shift(id*2,fs,md,x);
    shift(id*2+1,md+1,ls,x);
    seg[x][id]=min(seg[x][id*2],seg[x][id*2+1]);
//    printf("%d <- %d %d -> %d\n",fs,seg[x][id*2],seg[x][id*2+1],ls);
}
int Min(int id,int fs,int ls,int x)
{
    int md=(fs+ls)/2;
    shift(id,fs,ls,x);
//    printf("%d %d %d\n",id,fs,ls);
    if(fs==ls)
        return seg[x][id];
    if(y<=md)
        return Min(id*2,fs,md,x);
    else
        return Min(id*2+1,md+1,ls,x);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c,m,ch,n;
	memset(lazy,-1,sizeof lazy);
	scanf("%d %d %d",&r,&c,&m);
	for(i=1;i<=r;i++)
        st.insert(0);
	while(m--)
    {
        scanf("%d",&ch);

        if(ch==1)
        {
            scanf("%d %d %d",&x,&y,&val);
            shift(1,1,c,x);
            k=seg[x][1];
//            if(st.find(k)==st.end())
//                printf("CHK1\n");
            st.erase(st.find(k));
            upd(1,1,c,x);
//            printf("%d %d\n",k,val);
            shift(1,1,c,x);
//            printf("!! %d -> %d !!\n",k,seg[x][1]);
            st.insert(seg[x][1]);
//            printf("!");

        }
        else if(ch==2)
        {
            scanf("%d %d",&x,&val);
            shift(1,1,c,x);
//            if(st.find(seg[x][1])==st.end())
//                printf("CHK2\n");
            st.erase(st.find(seg[x][1]));
            lazy[x][1]=val;
            shift(1,1,c,x);
            st.insert(val);

        }
        else if(ch==3)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",Min(1,1,c,x));
        }
        else
        {
            printf("%d\n",*(st.begin()));
        }
//        for(auto it=st.begin();it!=st.end();it++)
//            printf("%d ",*it);
//        printf("\n");
    }
}
