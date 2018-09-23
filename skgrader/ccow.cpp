#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
char str[120000];
int len;
int main()
{
    int T,i,j,k;
    scanf("%d %s",&len,str+1);
    long long a=0,b=0,c=0;
    for(i=len;i>=1;i--)
    {
        switch(str[i])
        {
        case 'C':
            a+=b;
            break;
        case 'O':
            b+=c;
            break;
        case 'W':
            c++;
            break;
        }
    }
    printf("%lld",a);
}


