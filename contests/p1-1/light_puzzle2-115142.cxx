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
    k=scanf("%d %d %d",&r,&c,&p);
    p++;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            k=scanf("%d",&a[i*c+j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            mat[i*c+j][i*c+j]=1;
            for(k=0;k<4;k++)
            {
                if(chk(i+dx[k],j+dy[k]))
                    continue;
                mat[(i+dx[k])*c+(j+dy[k])][i*c+j]=1;
            }
        }
    }
//    for(i=0;i<r*c;i++)
//    {
//        for(j=0;j<r*c;j++)
//        {
//            printf("%d ",mat[i][j]);
//        }
//        printf("%d ",a[i]);
//        printf("\n");
//    }
//    printf("\n");
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
        if(mat[i][i]==0)
            continue;
        tmp=Pow(mat[i][i],p-2);
        for(k=0;k<r*c;k++)
        {
            mat[i][k]*=tmp;
            mat[i][k]%=p;
        }
        a[i]*=tmp;
        a[i]%=p;
        for(j=i+1;j<r*c;j++)
        {
            if(mat[j][i]>0)
            {
                tmp=Pow(mat[j][i],p-2);
                for(k=0;k<r*c;k++)
                {
                    mat[j][k]*=tmp;
                    mat[j][k]%=p;
                    mat[j][k]=mat[i][k]-mat[j][k];
                    if(mat[j][k]<0)
                        mat[j][k]+=p;

                }
                a[j]*=tmp;
                a[j]%=p;
                a[j]=a[i]-a[j];
                if(a[j]<0)
                    a[j]+=p;
            }
        }
//        for(j=0;j<r*c;j++)
//        {
//            for(k=0;k<r*c;k++)
//            {
//                printf("%d ",mat[j][k]);
//            }
//            printf(" | %d ",a[j]);
//            printf("\n");
//        }
//        printf("\n");
//        system("pause");
    }
        for(i=0;i<r*c;i++)
    {
        if(mat[i][i]>0)
        {
            tmp=Pow(mat[i][i],p-2);
            mat[i][i]*=tmp;
            mat[i][i]%=p;
            a[i]*=tmp;
            a[i]%=p;
        }
    }

    for(i=r*c-1;i>=0;i--)
    {
        if(mat[i][i]>0)
        {
            tmp=Pow(mat[i][i],p-2);
            for(k=0;k<r*c;k++)
                mat[i][k]*=tmp,mat[i][k]%=p;
            a[i]*=tmp;a[i]%=p;
            for(j=i-1;j>=0;j--)
            {
                if(mat[j][i]>0)
                {
                    tmp=Pow(mat[j][i],p-2);
                    for(k=0;k<r*c;k++)
                    {
                        mat[j][k]*=tmp;mat[j][k]%=p;
                        mat[j][k]=mat[i][k]-mat[j][k];
                        if(mat[j][k]<0)mat[j][k]+=p;
                    }
                    a[j]*=tmp;a[j]%=p;
                    a[j]=a[i]-a[j];
                    if(a[j]<0)
                        a[j]+=p;
                }
            }

        }
//        for(j=0;j<r*c;j++)
//        {
//            for(k=0;k<r*c;k++)
//            {
//                printf("%d ",mat[j][k]);
//            }
//            printf(" | %d ",a[j]);
//            printf("\n");
//        }
//        printf("\n");
//        system("pause");
    }
    for(i=0;i<r*c;i++)
    {
        if(mat[i][i]>0)
        {
            tmp=Pow(mat[i][i],p-2);
            mat[i][i]*=tmp;
            mat[i][i]%=p;
            a[i]*=tmp;
            a[i]%=p;
        }
    }
//    for(j=0;j<r*c;j++)
//    {
//        for(k=0;k<r*c;k++)
//        {
//            printf("%d ",mat[j][k]);
//        }
//        printf(" | %d ",a[j]);
//        printf("\n");
//    }
//    printf("\n");
    for(i=0;i<r*c;i++)
    {
        if(mat[i][i]>0)
        while(a[i]>0)
        {
            printf("%d %d\n",(i/c)+1,(i%c)+1);
            a[i]--;
        }
    }
}
