#include<stdio.h>
#include<string.h>
int x[100][100],n[150];
char p[6][31];
int main(){
	char str[150];
	int i,j,k,len;
	scanf("%s",&str);
	for(i=0;str[i]!='\0';i++){
		n[i+1]=str[i]-'0';
	}
	len=i;
	strcpy(p[1],"***** ******  ****************");
	strcpy(p[2],"* * *   *  * ***  *    ** ** *");
	strcpy(p[3],"* * * ***************  *******");
	strcpy(p[4],"* * * *    *  *  ** *  ** *  *");
	strcpy(p[5],"************  *******  *******");
	for(i=1;i<=5;i++){
		for(j=1;j<=len;j++){
			for(k=1;k<=3;k++){				
				x[i][(j-1)*3+k]=p[i][3*n[j]+k-1];
			}
		}
		for(j=1;j<=3*len;j++){
			printf("%c",x[i][j]);
			if(j%3==0)printf(" ");
		}
		printf("\n");
	}
}