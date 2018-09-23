#include<stdio.h>
int main(){
    FILE *fp;
    fp=fopen("prob_7_02in.txt","r");
    if(fp!=NULL){
        char ch[11];

        fgets(ch,11,fp);
        printf("%s",ch);
    }


}
