#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,m[100000],hi=0;
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&m[i]);
    for(i=1;i<=n;i++){
        if(m[i]>=hi)
            hi=m[i];
    }
    for(i=1;i<=hi;i++){
        for(j=1;j<=n;j++){
            if(hi-m[j]>=i){
                if(j==1){
                    for(k=1;k<=hi-i;k++){
                        printf(" ");
                    }
                }

                for(k=1;k<=6;k++){
                    printf(" ");
                }

                //printf(" ");
            }
            else{
                if(j==1){
                    for(k=1;k<=hi-i;k++){
                        printf(" ");
                    }
                }
                printf("x");
                for(k=1;k<=5;k++){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    for(i=1;i<=hi-1;i++){
        for(j=1;j<=n;j++){
            if(hi-m[j]>=hi-i){
                if(j==1){
                    for(k=1;k<=i;k++){
                        printf(" ");
                    }
                }

                for(k=1;k<=6;k++){
                    printf(" ");
                }

                //printf(" ");
            }
            else{
                if(j==1){
                    for(k=1;k<=i;k++){
                        printf(" ");
                    }
                }
                printf("x");
                for(k=1;k<=5;k++){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    scanf(" ");

}
