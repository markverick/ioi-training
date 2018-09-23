#include<stdio.h>
char str[250];
char str2[250];
int main(){
    int r,c,a,b;
    int i,j,k;

    scanf("%d %d",&r,&c);
    scanf("%d %d",&a,&b);
    for(i=0;i<c*b;i++){
        if((i/b)%2==0){
            str[i]='X';
            str2[i]='.';
        }
        else{
            str[i]='.';
            str2[i]='X';
        }
    }
     for(i=0;i<r*a;i++){
        if((i/a)%2==0){
            printf("%s\n",str);
        }
        else{
           printf("%s\n",str2);
        }
    }
}
