#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
pair<int,int> dat[60000];
pair<int,int> din[60000];
map<int,int> hsh;
int ha[60000];
int main()
{
    int n;
    int cot=0;
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        dat[i]=MP(b,-a*c);
        din[i]=MP(b,(-a-1)*c);
    }
    sort(&dat[0],&dat[n]);
    sort(&din[0],&din[n]);
    int b=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(i==j)
                continue;
            if(din[j].second<dat[i].second&&dat[j].second>din[i].second)
            {
                if(ha[i]==0)
                {
                    ha[j]=1;
                    //ha[i]=1;
                    b++;
                }
                //cot++;
            }
            else
            {


            }
        }
    }
    printf("%d",n-b);
}
