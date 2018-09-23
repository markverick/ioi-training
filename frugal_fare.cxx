#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
tuple<int,int,int> x[1135];
stack<pair<int,int> > st;
vector<tuple<int,char,int> > ts;
//timeStamp 'U'p/'D'own Quantity
long long dis(long long n,long long k)
{
    return (n*k-k*(k-1)/2)%1000002013;
}
int main()
{
    int n,m,i,j,k,T,a,b,c,ai,bi,ci;
    scanf("%d",&T);
    while(T--)
    {
        while(!st.empty())
            st.pop();
        ts.clear();
        long long sum=0,mc=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            mc+=c*dis(n,b-a);
            mc%=1000002013;
            x[i]=make_tuple(a,b,c);
            ts.emplace_back(a,'U',c);
            ts.emplace_back(b,'V',c);
        }
        sort(ts.begin(),ts.end());
        sort(&x[1],&x[m+1]);
        int time,amount;
        char ch;
        //printf("TS.Size = %d\n",ts.size());
        for(i=0;i<ts.size();i++)
        {
            tie(time,ch,amount)=ts[i];
            //printf("%d\n",i);
            if(ch=='U')
            {
                st.emplace(time,amount);
            }
            else
            {
                while(amount>0&&st.top().Y<=amount)
                {
               // printf("Amount = %d, st.top().Y= %d\n",amount,st.top().Y);

                    sum+=st.top().Y*dis(n,time-st.top().X);
                    sum%=1000002013;
                    amount-=st.top().Y;
                    st.pop();
                }
                if(amount>0)
                {
                    a=st.top().X;b=st.top().Y;
                    sum+=amount*dis(n,time-a);
                    sum%=1000002013;
                    st.pop();
                    st.emplace(a,b-amount);
                }
            }
                //printf("WORK! = %d\n",i);
        }
        if(mc-sum<0)
        {
            mc+=1000002013;
        }
        printf("%lld\n",mc-sum);
    }
}
