#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,int> co[10000];
int main()
{
    int n,i,j,k;
    int a,b,cot=0;
    int idx=0;
    int buffer;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        co[i]=make_pair(a,b);
    }
    sort(&co[0],&co[n]);
    int hi=-1000000020;
    for(i=0;i<n;i++){
        if(hi<co[i].second)hi=co[i].second;
        if(hi<co[i+1].first-1){
            // if(co[i+1].second>co[i].first)
            cot++;
            hi=-1000000020;
            //printf("chck ");
        }
    }/*
    printf("---\n");
    for(i=0;i<n;i++){
        printf("%d %d\n",co[i].first,co[i].second);
    }*/
    printf("%d",cot+1);

}
