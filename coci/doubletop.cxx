#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
char s[50005];
int pw[50005];
int ra[50005][10],rb[50005][10];
void solve(int res[][10],int a[],int n)
{
    int i,j,sm,all=0;
    pw[0]=1;
    for(i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*10%MOD;
    res[0][a[0]]=1;
    for(i=0,sm=1;i<n-1;i++) sm=(sm+1ll*pw[i]*a[i]%MOD)%MOD,res[i+1][a[i+1]]=sm;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<a[i];j++)
            res[i][j]=pw[i];
        for(j=0;j<10;j++)
            res[i][j]=(res[i][j]+all)%MOD;
        if(i!=0) all=(all+1ll*pw[i-1]*a[i]%MOD)%MOD;
    }
}
int arr[50005];
int main()
{
    int n=50000,i,j,k,sm,res=0,len;

    scanf("%s",s);
    len=strlen(s);
    for(i=len-1;i>=0;i--) arr[len-1-i]=s[i]-'0';
    for(i=0;i<n;i++)
        if(arr[i]!=0)
        {
            arr[i]--;
            break;
        }
    for(i=i-1;i>=0;i--) arr[i]=9;
    solve(ra,arr,n);

    scanf("%s",s);
    len=strlen(s);
    for(i=len-1;i>=0;i--) arr[len-1-i]=s[i]-'0';
    solve(rb,arr,n);
    for(i=n-1;i>=0;i--)
        for(j=0;j<10;j++)
            for(k=j+1;k<10;k++)
                res=(res+1ll*(k-j)*(rb[i][j]-ra[i][j])%MOD*(rb[i][k]-ra[i][k])%MOD*2%MOD)%MOD;
    printf("%d\n",res);
}