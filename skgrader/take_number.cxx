#include<bits/stdc++.h>
using namespace std;
int hsh[531];
int main()
{
    int n,i,cot,a;
    while(cin >> n!=0)
    {
        cot=0;
        memset(hsh,0,sizeof hsh);
        for(i=1;i<=n;i++)
        {
            cin >> a;
            hsh[a]=1;
        }
        for(i=1;i<500;i++)
        {
            if(hsh[i]==1)
            {
               cot++;
               if(hsh[i+1]==1)i++;
            }
        }
        cout << cot << "\n";
    }
}
