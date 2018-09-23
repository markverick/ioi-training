#include<bits/stdc++.h>
using namespace std;
char S[1135];
int kmp[1135];
int main()
{
    int i,j,k,l,N;
    scanf("%s",S+1);
    N=strlen(S+1);
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
    for(i=1;i<=N;i++)
    {
        printf("%d ",kmp[i]);
        sum+=kmp[i];
    }
    printf("\n=%d\n",sum);
}
