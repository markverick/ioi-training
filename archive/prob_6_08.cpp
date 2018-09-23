#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void swapc(char *x,char *y){
    char temp;
    temp=*y;
    *y=*x;
    *x=temp;
}
int main(){
    int n,len;
    int i,j,k;
    char ch[1000];
    scanf("%s",ch);
    len = strlen(ch);



    for(i=0;i<len;i++){
        srand(time(NULL));
        n=rand()%len;
        swapc(&ch[n],&ch[i]);
    }
    for(i=0;i<len;i++){
        printf("%c",ch[i]);
    }

}

