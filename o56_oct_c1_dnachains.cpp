#include<bits/stdc++.h>
using namespace std;
int len[100135];
int L[100135],R[100135];
char ch[5];
int main()
{
    int n,i,j,k,T=1,idx=1,rev=0,b4=0,l,a;
    scanf("%d %d",&l,&n);
    for(i=1;i<=l;i++)
    {
        scanf("%d",&len[i]);
        for(j=1;j<=len[i];j++)
        {
            if(j>1)
                L[T]=T-1;
            if(j<len[i])
                R[T]=T+1;
            T++;
        }
    }
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='C')
        {
            scanf("%d",&a);
            if(L[a]==0)
            {
                if(rev==0)
                {
                    if(L[R[idx]]==idx)
                        L[R[idx]]=0;
                    else
                        R[R[idx]]=0;
                    R[idx]=a;
                }
                else
                {
                    if(R[L[idx]]==idx)
                        R[L[idx]]=0;
                    else
                        L[L[idx]]=0;
                    L[idx]=a;
                }
                rev=0;
                L[a]=idx;
                idx=a;
                b4=idx;
            }
            else if(R[a]==0)
            {
                if(rev==0)
                {
                    if(L[R[idx]]==idx)
                        L[R[idx]]=0;
                    else
                        R[R[idx]]=0;
                    R[idx]=a;
                }
                else
                {
                    if(R[L[idx]]==idx)
                        R[L[idx]]=0;
                    else
                        L[L[idx]]=0;
                    L[idx]=a;
                }
                R[a]=idx;
                rev=1;
                //rev=1-rev;
                b4=idx;
                idx=a;
            }
        }
        else if(ch[0]=='B'&&rev==0||ch[0]=='F'&&rev==1)
        {
            if(L[idx]>0)
            {
                if(R[L[idx]]==idx)
                {
                    b4=idx;
                    idx=L[idx];
                }
                else
                {
                    rev=1-rev;
                    b4=idx;
                    idx=L[idx];
                }
            }
        }
        else
        {
            if(R[idx]>0)
            {
                if(L[R[idx]]==idx)
                {
                    b4=idx;
                    idx=R[idx];
                }
                else
                {
                    rev=1-rev;
                    b4=idx;
                    idx=R[idx];
                }
            }
        }
        printf("%d\n",idx);
        //printf("REV[%d] %d <- %d -> %d\n",rev,L[idx],idx,R[idx]);
    }
}
