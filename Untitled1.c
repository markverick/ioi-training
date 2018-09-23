#include<bits/stdc++.h>
#define Fill(x,y,c) if(chk(x,y))if(b[x][y]==0)b[x][y]=c;C++;
using namespace std;
char a[13][13];
//char b[13][13];
int n,C=0;
unordered_map<long long,int> mp;
int chk(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=n)
        return 1;
    else
        return 0;
}
//int blk(int x,int y)
//{
//    int cot=0;
//    if(!chk(x,y)||b[x][y]=='/')
//        cot++;
//    if(!chk(x-1,y-1)||b[x-1][y-1]=='/')
//        cot++;
//    if(!chk(x-1,y)||b[x-1][y]=='\\')
//        cot++;
//    if(!chk(x,y-1)||b[x][y-1]=='\\')
//        cot++;
//    return cot;
//}
//int deg(int x,int y)
//{
//    int cot=0;
//    if(chk(x,y)&&b[x][y]=='\\')
//        cot++;
//    if(chk(x-1,y-1)&&b[x-1][y-1]=='\\')
//        cot++;
//    if(chk(x-1,y)&&b[x-1][y]=='/')
//        cot++;
//    if(chk(x,y-1)&&b[x][y-1]=='/')
//        cot++;
//    return cot;
//}
//void Fill(int x,int y,char c)
//{
//    if(chk(x,y))
//        if(b[x][y]==0)
//            b[x][y]=c;
//            C++;
//}
//void FillX(int x,int y)
//{
//    if(b[x+1][y]=='\\'&&b[x][y+1]=='\\'&&b[x+1][y+1]=='/')
//        Fill(x,y,'\\');
//    if(b[x-1][y]=='\\'&&b[x][y-1]=='\\'&&b[x-1][y-1]=='/')
//        Fill(x,y,'\\');
//    if(b[x-1][y]=='/'&&b[x][y+1]=='/'&&b[x-1][y+1]=='\\')
//        Fill(x,y,'/');
//    if(b[x+1][y]=='/'&&b[x][y-1]=='/'&&b[x+1][y-1]=='\\')
//        Fill(x,y,'/');
//}
void dfs(long long bit)
{
    int tmp,i,j;
    mp[bit]=1;
//    while(bit>0)
//    {
//        if(bit%3>0)
//            C++;
//        bit/=3;
//    }
    printf("%lld\n",bit);
    char b[13][13];
    j=0;
    while(bit>0)
    {
        if(bit%3==1)
        {
            b[j/n+1][j%n+1]='/';
        }
        else if(bit%3==2)
        {
            b[j/n+1][j%n+1]='\\';
        }
        else
            b[j/n+1][j%n+1]=0;
        bit/=3;j++;
    }
    int blk=0,deg=0;
    while(C<n*n)
    {
        tmp=C;
        for(i=1;i<=n+1;i++)
        {
            for(j=1;j<=n+1;j++)
            {
                blk=0;
                if(!chk(i,j)||b[i][j]=='/')
                    blk++;
                if(!chk(i-1,j-1)||b[i-1][j-1]=='/')
                    blk++;
                if(!chk(i-1,j)||b[i-1][j]=='\\')
                    blk++;
                if(!chk(i,j-1)||b[i][j-1]=='\\')
                    blk++;
                if(4-blk==a[i][j]-'0')
                {
                    Fill(i,j,'\\');
                    Fill(i-1,j-1,'\\');
                    Fill(i-1,j,'/');
                    Fill(i,j-1,'/');
                }
                deg=0;
                if(chk(i,j)&&b[i][j]=='\\')
                    deg++;
                if(chk(i-1,j-1)&&b[i-1][j-1]=='\\')
                    deg++;
                if(chk(i-1,j)&&b[i-1][j]=='/')
                    deg++;
                if(chk(i,j-1)&&b[i][j-1]=='/')
                    deg++;
                if(deg==a[i][j]-'0')
                {
                    Fill(i,j,'/');
                    Fill(i-1,j-1,'/');
                    Fill(i-1,j,'\\');
                    Fill(i,j-1,'\\');
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(b[i][j]==0)
                {
                    if(b[i+1][j]=='\\'&&b[i][j+1]=='\\'&&b[i+1][j+1]=='/')
                        Fill(i,j,'\\');
                    if(b[i-1][j]=='\\'&&b[i][j-1]=='\\'&&b[i-1][j-1]=='/')
                        Fill(i,j,'\\');
                    if(b[i-1][j]=='/'&&b[i][j+1]=='/'&&b[i-1][j+1]=='\\')
                        Fill(i,j,'/');
                    if(b[i+1][j]=='/'&&b[i][j-1]=='/'&&b[i+1][j-1]=='\\')
                        Fill(i,j,'/');
                }
            }
        }
        if(tmp==C)
            break;
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
//                printf("%c",b[i][j]);
//            }
//            printf("\n");
//        }
//        system("pause");
    }
    if(C==n*n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%c",b[i][j]);
            }
            printf("\n");
        }
        return;
    }
    bit=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            bit*=3;
            if(b[i][j]=='/')
                bit++;
            else if(b[i][j]=='\\')
                bit+=2;
        }
    }
    int l=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            l*=3;
            if(b[i][j]==0)
            {
                C++;
                if(deg(i,j+1)+1<=a[i][j+1]-'0'&&deg(i+1,j)+1<=a[i+1][j]-'0'&&mp.find(bit+l)==mp.end())
                {
                    b[i][j]='/';
                    dfs(bit+l+1);
                }
                b[i][j]=0;
                if(deg(i,j)+1<=a[i][j]-'0'&&deg(i+1,j+1)+1<=a[i+1][j+1]-'0'&&mp.find(bit+l+1)==mp.end())
                {
                    b[i][j]='\\';
                    dfs(bit+l+2);
                }
                b[i][j]=0;
                C--;
            }
        }
    }
}
int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,tmp,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        mp.clear();
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        C=0;
        for(i=1;i<=n+1;i++)
        {
            scanf("%s",a[i]+1);
        }
        for(i=1;i<=n+1;i++)
        {
            for(j=1;j<=n+1;j++)
            {
                if(a[i][j]=='0')
                {
                    Fill(i,j,'/');
                    Fill(i-1,j-1,'/');
                    Fill(i-1,j,'\\');
                    Fill(i,j-1,'\\');
                }
            }
        }
        for(i=1;i<=n+1;i++)
        {
            if(a[1][i]=='2')
            {
                Fill(1,i,'\\');
                Fill(1,i-1,'/');
            }
            if(a[n+1][i]=='2')
            {
                Fill(n,i,'/');
                Fill(n,i-1,'\\');
            }
        }
        if(a[1][1]=='1')
            Fill(1,1,'\\');
        if(a[n+1][n+1]=='1')
            Fill(n,n,'\\');
        if(a[1][n+1]=='1')
            Fill(n,n,'/');
        if(a[n+1][1]=='1')
            Fill(n,n,'\\');
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
//                printf("%c",b[i][j]);
//            }
//            printf("\n");
//        }
        long long bit=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                bit*=3;
                if(b[i][j]=='/')
                    bit++;
                else if(b[i][j]=='\\')
                    bit+=2;
            }
        }
        dfs(bit);
    }
}
