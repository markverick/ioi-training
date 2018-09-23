#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    system("COLOR 3B");
    int x;
    scanf("%lf",&x);
    if(x==-2||x==-3){
        printf("This answer is not real number BOOOOOO!");
    }
    else{
        printf("%lf",(sqrt(x)+sqrt(pow(x+1,2))/(sqrt(x+2)+sqrt(x+3))));
    }
    scanf(" ");
}
