#include<bits/stdc++.h>
using namespace std;
string str;
void pr(char c,int x)
{
    while(x--)
        str+=c;
}
int maps[1135][1135],hsh[1135][1135],X,Y;
int main()
{
	int i,j,k,r,c,mn=1000000000,row,col,len;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
            if((i+j)%2)
                mn=min(mn,maps[i][j]);
        }
    }
	if(r%2)
    {
        for(i=1;i<=r;i++)
        {
            if(i%2==1)
                pr('R',c-1);
            else
                pr('L',c-1);
            pr('D',1);
        }
    }
    else if(c%2)
    {
        for(i=1;i<=c;i++)
        {
            if(i%2==1)
                pr('D',r-1);
            else
                pr('U',r-1);
            pr('R',1);
        }
    }
    else
    {
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if((i+j)%2&&maps[i][j]==mn)
                    X=i,Y=j;
        row=(X+1)/2;
        col=(Y+1)/2;
        for(i=1;i<row;i++)
        {
            pr('R',c-1);
            pr('D',1);
            pr('L',c-1);
            pr('D',1);
        }
        if(Y%2)
        {
            for(i=1;i<col;i++)
                str+="DRUR";
            str+="RDR";
            for(i=col+1;i<=c/2;i++)
                str+="URDR";
            str[str.size()-1]='D';
        }
        else
        {
            for(i=1;i<col;i++)
                str+="DRUR";
            str+="DRR";
            for(i=col+1;i<=c/2;i++)
                str+="URDR";
            str[str.size()-1]='D';
        }
        for(i=row+1;i<=r/2;i++)
        {
            pr('L',c-1);
            pr('D',1);
            pr('R',c-1);
            pr('D',1);
        }
    }
    len=str.size();
    for(i=0;i<len-1;i++)
        printf("%c",str[i]);
}