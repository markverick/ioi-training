#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<long long,long long> a[500135];
long long qs[500135];
set<pair<long long,long long> > st;
//set<pair<long long,long long> >::iterator it,it2;
long long c;
pair<long long,long long> p;
int main()
{
    long long n,i,j,k,mn=1000000000000000000,lo=1000000000000000000,mc=-100000000000000000;
    long long sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a[i].Y,&a[i].X);
        lo=min(lo,a[i].Y);
    }
    sort(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        qs[i]=qs[i-1]+a[i].X;
        st.insert(make_pair(a[i].Y,i));
//        printf("%lld %lld\n",a[i].X,a[i].Y);
    }
//    sum+=st.begin().X;
//    mn=a[st.begin().Y].X-a[st.begin().Y].Y;
//    st.erase(st.begin());
    mn=a[1].Y-a[1].X;
    printf("%lld\n",(*st.begin()).X);
    st.erase(st.find(make_pair(a[1].Y,1)));
    for(i=2;i<=n;i++)
    {
        p=*st.begin();
//        if(qs[i-1]+p.X<qs[i-1]+mn+a[i].X)
//        {
//            printf("%lld",qs[i-1]+p.X);
//        }
//        printf("qs[i-1]=%lld mc=%lld\n",qs[i-1],mn);
//        printf("%lld %lld\n",qs[i-1]+p.X,qs[i-1]+mn+a[i].X);
        printf("%lld\n",qs[i-1]+min(p.X,mn+a[i].X));
        mn=min(mn,a[i].Y-a[i].X);
        st.erase(st.find(make_pair(a[i].Y,i)));
    }
}
