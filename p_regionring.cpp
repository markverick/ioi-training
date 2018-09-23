#include<bits/stdc++.h>
int maps[1300][1300];
int result[1300];
int sum;
int main()
{
    int n;
    int i,j,k,l;
    int s;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        sum=0;
        scanf("%d",&s);
        for(i=0;i<s;i++)
        {
            for(j=0;j<s;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        result[0]=maps[s/2][s/2];
        printf("%d ",result[0]);
        for(l=1;l<=s/2;l++)
        {
            sum=0;
            for(i=s/2-l;i<=s/2+l;i++){
                //printf("[%d][%d] ",s/2-l,i);
                sum+=maps[s/2-l][i];
                sum+=maps[s/2+l][i];
            }
            for(i=s/2-l+1;i<=s/2+l-1;i++){
                sum+=maps[i][s/2-l];
                sum+=maps[i][s/2+l];
            }
            result[l]=sum;
            printf("%d ",sum);
        }
        printf("\n");

    }
}
