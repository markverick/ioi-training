#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m=0;
char maps[550][550],mat[550][550];
pair<int,int> jum[550][550][11];
int qs[550][550],q[30][5],a,b,A,B;
int dp(int x,int y,int w)
{
//    system("pause");
    if(jum[x][y][w].X>=0)
        return jum[x][y][w].X;
    if(w==0)
    {
        return 0;
    }
    int small=1,i=w-1,j,k; ///0 1 x x
    pair<int,int> mn={1000000000,24};
    while(i>0)
        small*=2,i--;
    for(j=0;j<24;j++)
    {
        a=x+small*(q[j][0]/2);b=y+small*(q[j][0]%2);
        A=a+small-1;B=b+small-1;
        i=qs[A+1][B+1]-qs[A+1][b]-qs[a][B+1]+qs[a][b];
        a=x+small*(q[j][1]/2);b=y+small*(q[j][1]%2);
        A=a+small-1;B=b+small-1;
        i+=small*small-(qs[A+1][B+1]-qs[A+1][b]-qs[a][B+1]+qs[a][b]);
//        printf("[%d] %d x %d %d\n",w,x,y,i);
        k=i+dp(x+small*(q[j][2]/2),y+small*(q[j][2]%2),w-1)+dp(x+small*(q[j][3]/2),y+small*(q[j][3]%2),w-1);
        if(k<mn.X)
        {
            mn=MP(k,j);
        }
    }
    jum[x][y][w]=mn;
//    printf("%d %d\n",jum[x][y][w].X,jum[x][y][w].Y);
    return mn.X;
}
void Fill(int x,int y,int w)
{
    int i,j,k=jum[x][y][w].Y,small=1;
    if(w==0)
    {
        mat[x][y]=maps[x][y];
        return;
    }
    i=w-1;
    while(i>0)
        small*=2,i--;
    a=x+small*(q[k][0]/2);b=y+small*(q[k][0]%2);
    A=a+small-1;B=b+small-1;
    for(i=a;i<=A;i++)
        for(j=b;j<=B;j++)
            mat[i][j]='0';
    a=x+small*(q[k][1]/2);b=y+small*(q[k][1]%2);
    A=a+small-1;B=b+small-1;
    for(i=a;i<=A;i++)
        for(j=b;j<=B;j++)
            mat[i][j]='1';
    Fill(x+small*(q[k][2]/2),y+small*(q[k][2]%2),w-1);
    Fill(x+small*(q[k][3]/2),y+small*(q[k][3]%2),w-1);
}
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int i,j,k,n,out,p[]={0,1,2,3};
	for(i=0;i<550;i++)
        for(j=0;j<550;j++)
            for(k=0;k<=10;k++)
                jum[i][j][k].X=-1;
	scanf("%d",&n);
	j=0;
	do
    {
        for(i=0;i<4;i++)
            q[j][i]=p[i];
        j++;
    }
    while(next_permutation(&p[0],&p[4]));
    i=n;
	while(i>1)
	{
	    m++;
        i/=2;
	}
	for(i=0;i<n;i++)
    {
        scanf("%s",maps[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i-1][j-1]-'0';
        }
    }
    out=dp(0,0,m);
    printf("%d\n",out);
    Fill(0,0,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c",mat[i][j]);
        printf("\n");
    }
}
