#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[100135],isp[100135],sumvld[100135];
vector<int> prm,v[100135];
int mat[7][7],m,s,a[]={1,3,3,1,3},b[]={1,1,3,5,1};
void dfs(int st)
{
    int i,j,k,l,I;
    if(st==10)
    {
        j=0;k=0;l=0;I=0;
        for(i=0;i<5;i++)
        {
            k*=10;j*=10;l*=10;I*=10;
            k+=mat[4][i];j+=mat[i][4];l+=mat[i][i];I+=mat[5-i-1][i];
        }
        if(!sumvld[k]||!sumvld[j]||!isp[k]||!isp[j]||!sumvld[l]||!isp[l]||!sumvld[I]||!isp[I])
            return;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                printf("%d",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
//        system("pause");
        return;
    }
    if(st==0)
    {
        mat[0][0]=m;
        for(i=0;i<v[m].size();i++)
        {
            k=v[m][i];
            for(j=4;j>=1;j--)
            {
                mat[0][j]=k%10;
                k/=10;
            }
            dfs(1);
        }
        return;
    }
    int fk=0;
    for(i=0;i<5;i++)
    {
        if(mat[4][i]!=a[i])
            fk=1;
    }
    for(i=0;i<5;i++)
    {
        if(mat[0][i]!=b[i])
            fk=1;
    }
//    if(fk==0)
//    {
//        if(st==10)
//            printf("!!\n");
////        printf("%d\n",st);
//    }
    int x=st/2+st%2,y=st/2;
//    printf("%d %d\n",x,y);
//    system("pause");
//    if(fk==0&&st==10)
//    {
//        printf("!\n");
//        for(i=0;i<5;i++)
//        {
//            for(j=0;j<5;j++)
//            {
//                printf("%d ",mat[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//        system("pause");
//
//    }
    if(st%2)
    {
        I=0;
        if(mat[0][y]==0)return;
        for(j=0;j<x;j++)
        {
            I*=10;
            I+=mat[j][y];
        }
        for(j=0;j<v[I].size();j++)
        {
            k=v[I][j];
            l=4;
            while(l>=x)
            {
                mat[l][y]=k%10;
                k/=10;l--;
            }
            dfs(st+1);
        }
    }
    else
    {
        I=0;
        if(mat[x][0]==0)return;
        for(j=0;j<y;j++)
        {
            I*=10;
            I+=mat[x][j];
        }
        for(j=0;j<v[I].size();j++)
        {
            k=v[I][j];
            l=4;
            while(l>=y)
            {
                mat[x][l]=k%10;
                k/=10;l--;
            }
            dfs(st+1);
        }
    }
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n=5,i,j,k,l,sum=0;
	for(i=2;i<=99999;i++)
    {
        if(!hsh[i])
        {
            prm.emplace_back(i);
            isp[i]=1;
            for(j=i;j<=99999;j+=i)
                hsh[j]=1;
        }
    }
    scanf("%d %d",&s,&m);
    for(i=10000;i<=99999;i++)
    {
        k=i;sum=0;
        while(k>0)
        {
            sum+=k%10;
            k/=10;
        }
        if(sum==s)
            sumvld[i]=1;
    }
//    for(i=0;i<10;i++)
//        printf("%d %d\n",i,isp[i]);
	for(i=1;i<=99999;i++)
    {
        if(i)
            k=nearbyint(floor(log10(i)));
        else k=0;
        l=1;
        k=5-k-1;
        while(k--)
            l*=10;
        for(j=0;j<l;j++)
        {
            if(sumvld[i*l+j]&&isp[i*l+j])
            {
                v[i].emplace_back(j);
            }
        }
    }
//    for(i=1;i<=99999;i++)
//    {
//        for(j=0;j<v[i].size();j++)
//            printf("%d %d\n",i,v[i][j]);
//    }
//    system("pause");
    dfs(0);
}
