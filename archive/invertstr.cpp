#include<stdio.h>
int main(){
	char ch[10000];
	int i,j,k,cot=0;
	scanf("%s",&ch);
	for(i=0;ch[i]!='\0';i++,cot++){;}
	for(i=cot;i>=0;i--)+printf("%c",ch[i]);
	
}