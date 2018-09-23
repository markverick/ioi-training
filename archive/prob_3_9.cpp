#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int n,m[100000],hi=0;
    int i,j,k;
    printf("Enter number of mountain : ");
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
                for(k=1;k<=2*m[j]-1;k++){
                    printf(" ");
                }
            }
            else{
                for(k=1;k<=m[j]+(hi-m[j])-i;k++){
                    printf(" ");
                }
                for(k=1;k<=2*(i-(hi-m[j]))-1;k++){
                    printf("*");
                }
                for(k=1;k<=m[j]+(hi-m[j])-i;k++){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    scanf(" ");
}
