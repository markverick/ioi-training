#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y,ch=0;
int st[8500135];
int lazy[8500135];
string str,s;
//int ch[8000000];
/// 1 = inv 2 = 1 3 = 0
void update(int idx,int type,int fst,int lst)
{
    switch(type)
    {
    case 2:
        st[idx]=lst-fst+1;
        lazy[idx]=2;
        break;
    case 3:
        st[idx]=0;
        lazy[idx]=3;
        break;
    case 1:
        switch(lazy[idx])
        {
        case 0:
            st[idx]=(lst-fst+1)-st[idx];
            lazy[idx]=1;
            break;
        case 1:
            st[idx]=(lst-fst+1)-st[idx];
            lazy[idx]=0;
            break;
        case 2:
            st[idx]=0;
            lazy[idx]=3;
            break;
        case 3:
            st[idx]=(lst-fst+1);
            lazy[idx]=2;
            break;
        }
        break;
    }
}
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]==0)
        return;
    int mid=(fst+lst)/2;
    update(idx*2,lazy[idx],fst,mid);
    update(idx*2+1,lazy[idx],mid+1,lst);
    lazy[idx]=0;
}

void Set(int idx,int type,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        update(idx,type,fst,lst);
        return;
    }
    shift(idx,fst,lst);
    Set(idx*2,type,fst,mid);
    Set(idx*2+1,type,mid+1,lst);
    st[idx]=st[idx*2]+st[idx*2+1];
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        st[idx]=s[fst-1]-'0';
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    st[idx]=st[idx*2]+st[idx*2+1];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx]/*+lazy[idx]*(lst-fst+1)*/;
    }
    shift(idx,fst,lst);
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,T,t,a,b,Q,q;
    char cc[6];

    cin >> T;
    for(t=1;t<=T;t++)
    {
        printf("Case %d:\n",t);
        str.clear();
        s.clear();
        memset(lazy,0,sizeof lazy);
        cin >> m;
        for(i=1;i<=m;i++)
        {
            int a;
            cin >> a;
            cin >> str;
            for(j=1;j<=a;j++)
            {
                s+=str;
            }
        }
        n=s.size();
        build(1,1,n);
        cin >> Q;
        q=1;
        for(i=1;i<=Q;i++)
        {
            //printf("== %d\n",sum(1,1,n));
            cin >> cc >> a >> b;
            a++;b++;
            x=a;y=b;
            if(cc[0]=='F')
            {
                Set(1,2,1,n);
            }
            else if(cc[0]=='E')
            {
                Set(1,3,1,n);
            }
            else if(cc[0]=='I')
            {
                Set(1,1,1,n);
            }
            else
            {
                printf("Q%d: %d\n",q++,sum(1,1,n));
            }
        }
    }
}

