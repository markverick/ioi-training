#define ll long long
#define mod 1000000007LL
#define F(a,b,c) for(a=b;a<c;a++)
#define Fr(a,b,c) for(a=b;a>=c;a--)
#define pf printf
#define sfd(a) scanf("%d",&a)
#define sfdd(a,b) scanf("%d%d",&a,&b)
#define sfl(a) scanf("%lld",&a)
#define sfll(a,b) scanf("%lld%lld",&a,&b)
#define pfd(a) printf("%d",a)
#define pfl(a) printf("%lld",a)
#define sf scanf
#define line printf("\n")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define let(x,a) __typeof(a) x(a)
#define forall(it,v) for(it=v.begin();it!=v.end();it++)
int n;
int a[505][505];
int dp1[505][505],dp2[505][505];
int fun1(int i,int j){
	if(i==1)
		return 0;
	int k=-1;
	int &xx=dp1[i][j];
	if(xx!=-1)
		return xx;
	F(k,-1,2)
		if(j+k>=1&&j+k<i)
			xx=max(xx,a[i-1][j+k]+fun1(i-1,j+k));
	return xx;
}
int fun2(int i,int j){
	if(j==n)
		return 0;
	int k=-1;
	int &xx=dp2[i][j];
	if(xx!=-1)
		return xx;
	F(k,-1,2)
		if(i+k<=n&&i+k>j)
			xx=max(xx,a[i+k][j+1]+fun2(i+k,j+1));
	return xx;
}
int main(){
    freopen("out.txt","w",stdout);
int t;
scanf("%d",&t);
while(t--){
	int i,j,x;
	sfd(n);
	memset(dp1,-1,sizeof dp1);
	memset(dp2,-1,sizeof dp2);
	F(i,1,1+n)
		F(j,1,i+1)
			sfd(a[i][j]);
	int ma=-1,su=0;
	Fr(i,n,(n+1)/2){
		su+=a[i][n-i+1];
		int k=-1,l=-1,j=n-i+1;
		F(k,-1,2)
			F(l,-1,2)
				if((k!=1||l!=-1)&&j+k<=i-1&&j+k>=1&&i+l<=n&&i+l>=j+1)
				{ma=max(ma,su+a[i-1][j+k]+a[i+l][j+1]+fun1(i-1,j+k)+fun2(i+l,j+1));
				int b=3;}
	}
	pfd(ma),line;
}
return 0;
}
