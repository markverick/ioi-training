#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int n,i,j,k,count=0;
    char c,ch;
    printf("Enter an integer : ");
    scanf("%d",&n);
    printf("Enter a charactor : ");
    ch = getch();
    printf("%c\n",ch);
    for(i=ch-65;i<n;i++){
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
