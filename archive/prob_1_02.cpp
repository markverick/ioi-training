#include<stdio.h>
int main(){
    int n,pan,ha,roi;
    int panx,
    hax;
    scanf("%d",&n);
    pan = n/1000;
    panx=n%1000;
    ha = panx/500;
    hax = panx%500;
    roi = hax/100;
    printf("B1000 = %d\n",pan);
    printf("B500 = %d\n",ha);
    printf("B100 = %d\n",roi);


}
