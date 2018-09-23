#include<bits/stdc++.h>
int n=0;
long long check[10000][4];
long long fx(char word,int idx)
{
    if(check[idx][word-'a']>=0)
    {
        return check[idx][word-'a'];
    }
    if(idx>=n-1)
    {
        return 1;
    }
    if(word=='a')
    {
        return check[idx][word-'a'] = fx('c',idx+1)+fx('a',idx+1);
    }
    else
    {
        return check[idx][word-'a'] = fx('c',idx+1)+fx('b',idx+1)+fx('a',idx+1);
    }

}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++)
            {
                check[i][j]=-1;
            }
        }
        if(n!=0)
            printf("%lld\n",fx('a',0)+2*fx('b',0));
        else
            printf("1\n");
    }
}
