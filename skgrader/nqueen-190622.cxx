#include<bits/stdc++.h>
using namespace std;
int n;
//int row[20];
//int up_d[20];
//int lo_d[20];
int OK;
int cot=0;
int result[20];
int hsh[70536];
void queen(int idx,int row,int lo_d,int up_d)
{
    int i;
    if(row==OK)
    {
        if(cot<3)
        {
            for(i=0;i<n;i++)
            {
                printf("%d ",result[i]);
            }
            printf("\n");
        }

        cot++;
        return;
    }
    //printf("%d %d %d\n",row,lo_d,up_d);
    int pos=OK&(~(row|lo_d|up_d));
    int x;
    while(pos>0)
    {
        x=pos&(-pos);pos-=x;
        result[idx]=hsh[x]+1;
        queen(idx+1,row|x,(lo_d|x)<<1,(up_d|x)>>1);
    }

}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<16;i++)
    {
        hsh[1<<i]=i;
    }
    OK=(1<<n)-1;
    queen(0,0,0,0);
    printf("%d\n",cot);
}
