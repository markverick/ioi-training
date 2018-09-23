#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int note[25000];
int out[100000];
int chord[15];
int hsh[200][200];
int result[15];
bool chk[15];
int n,c;
/*void gen(int idx)
{
    int i;
    if(idx==c)
    {
        for(i=0;i<c;i++)
        {
            //printf("%d ",result[i]);
        }
        //printf("\n");
        cot++;
        return;
    }
    for(i=0;i<c;i++)
    {
        if(chk[i]==1)
            continue;
        result[idx]=chord[i];
        chk[i]=1;
        gen(idx+1);
        chk[i]=0;
    }
}*/
int main()
{

    scanf("%d",&n);
    int i,j,k;
    int a;
    for(i=0;i<n;i++)
    {
        scanf("%d",&note[i]);
    }
    scanf("%d",&c);
    int hi=0,lo=100000;
    for(i=0;i<c;i++)
    {
        scanf("%d",&a);
        lo=min(lo,a);
        hi=max(hi,a);
        chord[i]=a;
        //hsh[a]=1;
    }
    //printf("%d %d\n",lo,hi);
   //
   int idx=0;
    for(i=-lo;i<=100;i++)
    {
        for(j=0;j<c;j++)
        {
            hsh[idx][chord[j]+i]=1;
        }
        idx++;
    }

    /*for(i=0;i<78;i++)
    {
        for(j=0;j<=78;j++)
        {
            printf("%d",hsh[i][j]);
        }
        printf("\n");
    }*/
    //system("pause");
    //gen(0);
    //printf("%d",cot);
    int p=0;
    int cot=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=idx;j++)
        {
            cot=0;
            for(k=i;k<=i+2;k++)
            {
                if(hsh[j][note[k]]==1)
                    cot++;
            }
            if(cot==c)
            {
                out[p++]=i;
                break;
            }
        }
    }
    sort(&out[0],&out[p]);
    printf("%d\n",p);
    for(i=0;i<p;i++)
    {
        printf("%d\n",out[i]+1);
    }
}
