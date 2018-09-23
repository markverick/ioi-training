#include<bits/stdc++.h>
using namespace std;
int n;
char result[100];
int cot=0;
int cot2=0;
void gen(int idx)
{
    if(cot>=100000&&n>=16)
    {
        exit(0);
        return;
    }
    if(idx==n)
    {
        int i,j;
        for(i=n-1;i>=0;i--)
        {
            if(result[i]=='1')
                continue;
            if(cot>=100000&&n>=16)
            {
                exit(0);
                return;
            }
            cot++;
            //printf("[%d][%d] = ",cot2,i);
            printf("%s",result);
            printf(" ");
            result[i]='1';
            printf("%s\n",result);
            result[i]='0';

        }
        return;
        //base case
    }
    result[idx]='0';
    gen(idx+1);
    result[idx]='1';
    gen(idx+1);

}
int main()
{

    scanf("%d",&n);
    cot2=0;
    gen(0);
    //printf("\n%d",cot);
}
