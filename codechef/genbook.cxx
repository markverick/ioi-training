#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
    int T=10000;
    srand(135);
    freopen("in.txt","w",stdout);
    printf("%d\n",T);
	while(T--)
    {
        printf("%lld\n",((long long)(rand())*rand()*rand()*rand())%100000000000000000ll);
    }
}
