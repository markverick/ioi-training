#include<stdio.h>
int fac(int z)
{
    if (z <= 1)
        return 1;
    else
        return z * fac(z - 1);
}
int ncr(int n,int r){
    return(fac(n)/(fac(r)*fac(n-r)));


}
int main(){

    int a,b,n,r,z,x,y;
    int i,j,k;
    scanf("%d %d",&y,&x);
    for(i=0;i<=x;i++){
        for(k=x-i;k>0;k--){
            printf("  ");
        }
        for(j=0;j<=i;j++){

            printf("%3d ",y*ncr(i,j));
        }
        printf("\n");
  }

    scanf(" ");


}
