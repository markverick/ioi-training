#include<bits/stdc++.h>
//coti2010/3-5
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[300135];
long long L[300135],R[300135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,fst=1,lst=1;
	stack<pair<int,int> > st;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(!st.empty())st.pop();
    for(lst=1;lst<=n;lst++)
    {
        while(!st.empty())
        {
            if(st.top().X>a[lst])
                break;
            st.pop();
        }
        if(!st.empty())
            L[lst]=(lst-st.top().Y);
        else
            L[lst]=lst;
        st.emplace(a[lst],lst);
    }
    while(!st.empty())st.pop();
    for(lst=n;lst>=1;lst--)
    {
        while(!st.empty())
        {
            if(st.top().X>=a[lst])
                break;
            st.pop();
        }
        if(!st.empty())
            L[lst]*=(st.top().Y-lst);
        else
            L[lst]*=n-lst+1;
        st.emplace(a[lst],lst);
    }
    for(i=1;i<=n;i++)
        a[i]=-a[i];
    while(!st.empty())st.pop();
    for(lst=1;lst<=n;lst++)
    {
        while(!st.empty())
        {
            if(st.top().X>a[lst])
                break;
            st.pop();
        }
        if(!st.empty())
            R[lst]=(lst-st.top().Y);
        else
            R[lst]=lst;
        st.emplace(a[lst],lst);
    }
    while(!st.empty())st.pop();
    for(lst=n;lst>=1;lst--)
    {
        while(!st.empty())
        {
            if(st.top().X>=a[lst])
                break;
            st.pop();
        }
        if(!st.empty())
            R[lst]*=(st.top().Y-lst);
        else
            R[lst]*=n-lst+1;
        st.emplace(a[lst],lst);
    }
    long long sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=L[i]*(-a[i])+R[i]*a[i];
    }
    printf("%lld",sum);
}