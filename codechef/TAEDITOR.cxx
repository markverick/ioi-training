#include<bits/stdc++.h>
using namespace std;
string s[300135],ch[300135];
char out[300135];
int id[300135],seg[1200135],x,l[300135];
char y;
vector<int> ar[300135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=1;
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int query(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        return fst;
    }
    if(x>seg[idx*2])
    {
        x-=seg[idx*2];
        return query(idx*2+1,mid+1,lst);
    }
    else
        return query(idx*2,fst,mid);
}
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        out[fst]=y;
        seg[idx]=0;
        return;
    }
    if(x<=mid)
        add(idx*2,fst,mid);
    else
        add(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int main()
{
    int Q,i,j,k,n=0;
    scanf("%d",&Q);
    for(i=1;i<=Q;i++)
    {
        cin >>ch[i]>>id[i];
        if(ch[i][0]=='+')
            cin >> s[i];
        else
            cin >> l[i];
        n+=s[i].size();
    }
    build(1,1,n);
    for(i=Q;i>=1;i--)
    {
        if(ch[i][0]=='?')
        {
            for(j=id[i];j<id[i]+l[i];j++)
            {
                x=j;
                ar[i].push_back(query(1,1,n));
            }
        }
        else
        {
            for(j=s[i].size()-1;j>=0;j--)
            {
                x=id[i]+1+j;
                y=s[i][j];
                x=query(1,1,n);
                add(1,1,n);
            }
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        printf("%c",out[i]);
//    }
//    printf("\n");
//    system("pause");
    for(i=1;i<=Q;i++)
    {
        if(!ar[i].empty())
        {
            for(j=0;j<ar[i].size();j++)
            {
                printf("%c",out[ar[i][j]]);
            }
            printf("\n");
        }
    }
}
