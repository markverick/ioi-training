#include<bits/stdc++.h>
using namespace std;
char result[12];
int C=1024;
void gen(int idx)
{
    if(idx==10)
    {
        if(C>0)
        {
            printf("%s\n",result);
            C--;
        }

        return;
    }
    result[idx]='+';
    gen(idx+1);
    result[idx]='-';
    if(C<=0)
        return;
    gen(idx+1);
}
int main()
{
    freopen("in.txt","w",stdout);
    printf("%d\n",C);
    gen(0);
}
