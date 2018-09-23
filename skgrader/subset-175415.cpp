#include<bits/stdc++.h>
int result[100];
int n;
void gen(int idx)
{
    //printf("%d\n",idx);
    int i;
    if(idx==n)
    {
        for(i=0;i<idx;i++)
        {
            printf("%d",result[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        result[idx]=0;
        gen(idx+1);
        result[idx]=1;
        gen(idx+1);
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    gen(0);

}
