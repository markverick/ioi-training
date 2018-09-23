#include<bits/stdc++.h>
using namespace std;
int mat[500][500],a[500];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int r,c,p;
int Pow(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int sum=Pow(a,b/2);
    sum*=sum;
    sum%=p;
    if(b%2)
        sum*=a;
    sum%=p;
    return sum;
}
inline int chk(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c)
        return 0;
    else
        return 1;
}
void Swap(int x,int y)
{
    for(int i=0;i<r*c;i++)
    {
        swap(mat[x][i],mat[y][i]);
    }
}
int main()
{
    int i,j,k,tmp;
    scanf("%d %d %d",&r,&c,&p);
    p++;
    printf("%d\n",Pow(10,4));
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i*r+j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mat[i*r+j][i*r+j]=1;
            for(k=0;k<4;k++)
            {
                if(chk(i+dx[k],j+dy[k]))
                    continue;
                mat[(i+dx[k])*r+(j+dy[k])][i*r+j]=1;
            }
        }
    }
    for(i=0;i<r*c;i++)
    {
        for(j=0;j<r*c;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("%d ",a[i]);
        printf("\n");
    }
    printf("\n");
    for(i=0;i<r*c;i++)
    {
        if(mat[i][i]==0)
        {
            for(j=i+1;j<r*c;j++)
            {
                if(mat[j][i]>0)
                {
                    Swap(i,j);
                    swap(a[i],a[j]);
                    break;
                }
            }
        }
        tmp=Pow(mat[i][i],p-2);
        for(k=0;k<r*c;k++)
        {
            mat[i][k]*=tmp;
            mat[i][k]%=p;
        }
        a[i]*=tmp;
        for(j=i+1;j<r*c;j++)
        {
            if(mat[j][i]>0)
            {
                tmp=Pow(mat[j][i],p-2);
                for(k=0;k<r*c;k++)
                {
                    mat[j][k]*=tmp;
                    mat[j][k]%=p;

                }
                a[j]*=tmp;
                a[j]%=p;
                for(k=0;k<r*c;k++)
                {
                    mat[j][k]=mat[i][k]-mat[j][k];
                    if(mat[j][k]<0)
                        mat[j][k]+=p;
                }
                a[j]=a[i]-a[j];
                if(a[j]<0)
                    a[j]+=p;
            }
        }
        for(j=0;j<r*c;j++)
        {
            for(k=0;k<r*c;k++)
            {
                printf("%d ",mat[j][k]);
            }
            printf(" | %d ",a[j]);
            printf("\n");
        }
        printf("\n");
        system("pause");
    }
}

