#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[111][111];
int qs[111][111],lol[111][111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int r,c,i,j,k,fk=0,mc,a,b,xa,ya,xb,yb,all=0,sum=0;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",s[i]+1);
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='x')
            {
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+1;
                all++;
            }
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='x')
            {
                fk=1;
                for(k=i+1;k<=r;k++)
                {
                    if(s[k][j]!='x')
                        break;
                }
                a=k-i;
                for(k=j+1;k<=c;k++)
                {
                    if(s[i][k]!='x')
                        break;
                }
                a=min(a,k-j);
                xa=i;ya=j;
                break;
            }
        }
        if(fk)break;
    }
    for(i=xa;i<xa+a;i++)
    {
        for(j=ya;j<ya+a;j++)
        {
            s[i][j]='a';
        }
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='x')
            {
                lol[i][j]=lol[i-1][j]+lol[i][j-1]-lol[i-1][j-1]+1;
                sum++;
            }
            else
                lol[i][j]=lol[i-1][j]+lol[i][j-1]-lol[i-1][j-1];
        }
    }
//    for(i=1;i<=r;i++)
//    {
//        printf("%s\n",s[i]+1);
//    }
    fk=0;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(s[i][j]=='x')
            {
                fk=1;
                for(k=i+1;k<=r;k++)
                {
                    if(s[k][j]!='x')
                        break;
                }
                b=k-i;
                for(k=j+1;k<=c;k++)
                {
                    if(s[i][k]!='x')
                        break;
                }
                b=max(b,k-j);
                break;
            }
        }
        if(fk)break;
    }
//    printf("%d %d\n",a,b);
    for(i=1;i<=r-b+1;i++)
    {
        for(j=1;j<=c-b+1;j++)
        {
//            if(i==8&&j==3)
//            {
////                printf("%d %d ~ %d %d\n",i,j,i+b-1,j+b-1);
////                printf("%d %d %d %d\n",qs[i+b-1][j+b-1],qs[i-1][j+b-1],qs[i+b-1][j-1],qs[i-1][j-1]);
////                printf("%d == %d\n",qs[i+b-1][j+b-1]-qs[i-1][j+b-1]-qs[i+b-1][j-1]+qs[i-1][j-1],b*b);
//            }
            if(qs[i+b-1][j+b-1]-qs[i-1][j+b-1]-qs[i+b-1][j-1]+qs[i-1][j-1]==b*b)
            {
                if(lol[i+b-1][j+b-1]-lol[i-1][j+b-1]-lol[i+b-1][j-1]+lol[i-1][j-1]==sum)
                {
                    printf("%d %d %d\n%d %d %d",xa,ya,a,i,j,b);
                    return 0;
                }
            }
        }
    }
    printf("%d %d %d\n%d %d %d",xa,ya,a,xa,ya,a);
}
