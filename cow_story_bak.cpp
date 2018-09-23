#include<bits/stdc++.h>
int year;
int cot=0;
void fx(int idx,int type) //pTime is time to generate
//type: 1 = primary take 4 pTime|| 2 = secondary take 3 pTime
//return to Number of flippin COW
{
    if(idx>year)
    {
        //cot++;
        return;
    }
    switch (type)
    {
    case 1:
        if(idx+4<year){
            fx(idx+4,2);
            cot++;
        }
        break;
    case 2:
         if(idx+3<year){
            fx(idx+3,2);
            cot++;
        }
        break;
    }
    return;
}
int main()
{
    int sum=0;
    int i,j,k;
    scanf("%d",&year);
    for(i=0;i<year;i++)
    {
        cot++;
        fx(i,1);
    }
    printf("%d",cot);
}
