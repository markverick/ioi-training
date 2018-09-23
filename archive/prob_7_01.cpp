#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("prob_7_01out.txt","w");
    if(fp==NULL){
        printf("INVALID i/o");
    }
    int i;
    int ch='A';
    for(i=1;i<=26;i++,ch++){
        fputc(ch,fp);
    }
}
