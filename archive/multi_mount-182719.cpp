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
                for(k=1;k<=2*m[j];k++){
                    printf(".");
                }
            }
            else{
                for(k=1;k<=m[j]+(hi-m[j])-i;k++){
                    printf(".");
                }
                printf("/");
                for(k=1;k<=2*(i-(hi-m[j]))-2;k++){
                    printf(".");
                }
                printf("\\");
                for(k=1;k<=m[j]+(hi-m[j])-i;k++){
                    printf(".");
                }
            }
        }
        printf("\n");
    }
    scanf(" ");
}
