#include<bits/stdc++.h>
using namespace std;
int in[100135];
int fx[100135];
int gx[100135];
int i,j,k;
void add(int idx,int val)
{
    if(val>=in[idx])
    {
        if(gx[idx]!=0)
        {
            printf("R");
            add(gx[idx],val);
        }
        else
        {
            printf("R*\n");
            gx[idx]=i;
        }
    }
    else
    {
        if(fx[idx]!=0)
        {
            printf("L");
            add(fx[idx],val);
        }
        else
        {
            printf("L*\n");
            fx[idx]=i;
        }
    }
}
int main()
{
    int n,idx;
    scanf("%d",&n);
    scanf("%d",&in[1]);
    printf("*\n");
    for(i=2;i<=n;i++)
    {
        scanf("%d",&in[i]);
        add(1,in[i]);
    }
}
