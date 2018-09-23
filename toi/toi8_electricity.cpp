#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
int a[550000];
int n,k;
int dp[550000];
multiset<int> st;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    //memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st.insert(a[0]);
    dp[0]=a[0];
    for(i=1;i<=k;i++)
    {
        int mn=999999999;
        for(j=i-1;j>=max(0,i-k);j--)
        {
            mn=min(mn,dp[j]);
        }
        dp[i]=mn+a[i];
        st.insert(dp[i]);
    }
    //st.erase(st.find(dp[0]));
    for(i=k+1;i<n;i++)
    {
        //printf("%d",);
        st.erase(st.find(dp[i-k-1])); //*
        dp[i]=*st.begin()+a[i];
        st.insert(dp[i]);
    }
    //for(i=0;i<n;i++)
      //  printf("%d\n",dp[i]);
    printf("%d",dp[n-1]);
}

