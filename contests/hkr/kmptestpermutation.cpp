#include<bits/stdc++.h>
using namespace std;
char S[1000135];
int kmp[1000135];
int main()
{
    int i,j,k,l,N,mn=1000000000;
    scanf("%s",S+1);
//    for(i=1;i<=10;i++)
//    {
//        S[i]='a';
//    }
//    for(i=11;i<=20;i++)
//    {
//        S[i]='b';
//    }
//    for(i=21;i<=30;i++)
//    {
//        S[i]='c';
//    }
    N=strlen(S+1);
    do
    {

        kmp[1] = 0;
        for (i = 2; i <= N; i = i + 1){
            l = kmp[i - 1];
            while (l > 0 && S[i] != S[l + 1]){
                l = kmp[l];
            }
            if (S[i] == S[l + 1]){
                kmp[i] = l + 1;
            }
            else{
                kmp[i] = 0;
            }
        }
        int sum=0;
//        printf("%s\n",S+1);
        for(i=1;i<=N;i++)
        {
//            printf("%d ",kmp[i]);
            sum+=kmp[i];
        }
//        if(sum==2)
//        {
//            printf("%s\n",S+1);break;
//        }
//        if(sum<mn)
//            printf("%s\n%d\n",S+1,sum),system("pause"),
        mn=min(mn,sum);
        printf("\n=%d\n",sum);
        system("pause");
    }
    while(next_permutation(&S[1],&S[N+1]));
    printf("Min = %d\n",mn);
}
