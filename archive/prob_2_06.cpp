#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j,k,count=0;
    char c;
    printf("Enter an integer : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("%c",'A'+i);
        count+=1;
        if(i>=25){
            i=0;
            printf("%c",'A'+i);
        }
        if(count>=n)
            break;
    }
    scanf(" ");
}
