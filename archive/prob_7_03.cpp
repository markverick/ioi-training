#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int cot=0;
void draw(){
    char name[500];
    char ch;
    struct scard{
            int x;
            int a;
        }card;

        card.x=rand()%14;
        card.a=rand()%4;
        switch(card.a){
            case 0 : strcpy(name,"Club");break;
            case 1 : strcpy(name,"Diamond");break;
            case 2 : strcpy(name,"Heart");break;
            case 3 : strcpy(name,"Spade");break;
        }
        card.x++;
        cot++;
        if(card.x<=10)
            printf("\nYour %d time of draw is %d %s\n",cot,card.x,name);
        else{
            switch(card.x){
                case 11 : ch='J';break;
                case 12 : ch='Q';break;
                case 13 : ch='K';break;
                case 14 : ch='A';break;
            }
            printf("\nYour %d time of draw is %c %s\n",cot,ch,name);
        }
}
int main(){
    int i;
    int n;
    printf("Let's start drawing!\nEnter time(s) for drawing card");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        srand(time(NULL)+i);
        draw();
    }


}
