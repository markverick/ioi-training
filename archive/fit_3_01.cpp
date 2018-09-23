#include<stdio.h>
int x[15][15];
int y[15][15];
int main(){
       int n;
       int sum=-99999999;
       int hi=-99999999;
       int i,j,k,i2,j2,k2;

       scanf("%d",&n);
       for(i=1;i<=n;i++){
                         for(j=1;j<=n;j++){
                                           scanf("%d",&x[i][j]);
                                           }
                        }
       for(i=1;i<=n-1;i++){//count
                         for(j=1;j<=n;j++){//cut j
                                           for(k=1;k<=n;k++){//cut k
                                                            sum=0;
                                                           // for(i2=0;i2<=n;i2++){
                                                                  //  for(j2=0;j2<=n;j2++){
                                                                            //if(i2==j||j2==k)){
                                                                                                //if(x[i2+1][i2+1]==NULL)break;
                                                                                  //              x[i2][j2]=x[i2+1][i2+1];
                                                                                  //              x[i2+1][i2+1]=-99999999;
                                                                                  //              }

                                                                           // }
                                                                     //   y[i2][j2]=x[i2][j2];
                                                         //   }

                                                            for(i2=1;i2<=n;i2++){//sumi
                                                                            for(j2=01;j2<=n;j2++){//sumj
                                                                                    if((i2!=j&&j2!=k))
                                                                                                //printf("%d")
                                                                                                 sum+=x[i2][j2];
                                                                                                 }
                                                                            }
                                                            //printf("%d ",sum);
                                                            if(hi<=sum){
                                                                         hi=sum;
                                                            }

                                           }
                         }
       }
        printf("%d",hi);
       scanf(" ");
}
