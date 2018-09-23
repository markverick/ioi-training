#include<stdio.h>
int cus[100000],bal[100000],cost[100000];
int main(){
    int i=0,j=0;
    int c;
    int num=0;
    int item=0;
    while(c!='E'){
        c=getchar();
        if(c=='A'){
            i++;
            num++;
            scanf("%d",&cus[i]);
            scanf("%d",&bal[i]);
        }
        if(c=='G'){
            j++;
            item++;
            scanf("%d",&cost[j]);
        }
    }
    j=1;
    if(num==0||item==0){;}
    else{
        for(i=1;i<=num;i++){
            if(item<j)break;
            if(bal[i]>=cost[j]){
                printf("%d %d\n",cus[i],bal[i]-cost[j]);
                j++;
            }
    //        if()
        }
    }

}
