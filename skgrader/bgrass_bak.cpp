#include<stdio.h>
char maps[300][300];
int hash[300][300];
int stx[10000],sty[10000];
int main(){
	int r,c;
	int i,j,k,p,q;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++){
		scanf("%s",maps[i]);
	}
	int idx;
	int x,y;
	int cot=0;
	cot=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){

			if(hash[i][j]==0&&maps[i][j]=='#'){
				x=i;y=j;
				idx=0;
				stx[0]=i;sty[0]=j;
				idx=1;
				hash[x][y]++;
				while(idx>=0){
                    x=stx[idx-1];y=sty[idx-1];
                    /*if(i==2&&j==4){
                        printf("%d [%d] %d\n",x,idx,y);
                    }*/
					if(x+1<r&&hash[x+1][y]==0&&maps[x+1][y]=='#'){
						stx[idx]=x+1;
						sty[idx]=y;
						idx++;
						x++;
						hash[x][y]++;
						//printf("CHKX+1\n");
					}
					else if(x-1>=0&&hash[x-1][y]==0&&maps[x-1][y]=='#'){
						stx[idx]=x-1;
						sty[idx]=y;
						idx++;
						x--;
						hash[x][y]++;

					}
					else if(y+1<c&&hash[x][y+1]==0&&maps[x][y+1]=='#'){
						stx[idx]=x;
						sty[idx]=y+1;
						idx++;
						y++;
						hash[x][y]++;

					}
                    else if(y-1>=0&&hash[x][y-1]==0&&maps[x][y-1]=='#'){
						stx[idx]=x;
						sty[idx]=y-1;
						idx++;
						y--;
						hash[x][y]++;
					}
					else{
                        //printf("F ");
						idx--;
					}
					/*for(k=0;k<idx;k++){
                        //printf("\n\t%d %d\n",stx[k],sty[k]);
					}*/
				}
				cot++;
				/*for(p=0;p<r;p++){
                    for(q=0;q<c;q++){
                        printf("%d ",hash[p][q]);
                    }
                    printf("\n");
				}*/
				//printf("[%d][%d]\n",i,j);
			}

		}
	}
	printf("%d",cot);
}
/*
.***
.*.*
*.****
***.*.
*/
