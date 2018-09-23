#include<bits/stdc++.h>
int n,w,l;
char result[70000];
void gen(int idx,int idxW,int idxL)
{
    int i;
    if(idxW==n)
    {
        for(i=0;i<idx;i++)
        {
            printf("%c ",result[i]);
        }
        printf("\n");
        //idx=0;
        return;
    }
    if(idxL==n)
    {
        for(i=0;i<idx;i++)
        {
            printf("%c ",result[i]);
        }
        printf("\n");
        //idx=0;
        return;
    }
    result[idx]='W';
    gen(idx+1,idxW+1,idxL);
    result[idx]='L';
    gen(idx+1,idxW,idxL+1);


}
int main()
{
    scanf("%d %d %d",&n,&w,&l);
    gen(0,w,l);
}
