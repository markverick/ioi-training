 #include<bits/stdc++.h>
int m;
long long scoreMap[120000];
long long maxScore=0;
long long fx(int x,int score)
{
    long long y,n;
    if(x>=m-1)
    {
        return 0;
    }

    n=fx(x+1,score);
    y=fx(x+3,score)+scoreMap[x+1];
    if(y>n)
    {

        maxScore=y;
    }
    else
    {
        maxScore=n;
    }


}

int main()
{
    scanf("%d",&m);
    int i,j,k;
    for(i=0;i<m;i++){
        scanf("%d",&scoreMap[i]);
    }
    fx(0,0);
    printf("%lld",maxScore);

}

