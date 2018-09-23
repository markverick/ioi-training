#include<stdio.h>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;
map<int,int> num;
int input;
int output[200];
int main(){
    int n;
    int p=0;
    int idx=0;
    int i,j,k;
    int value;
    scanf("%d",&n);
    int divisor,digit,digits;
    for(i=1;i<=n;i++){
        p=0;idx=0;
        scanf("%d",&input);
        while(true){
            idx+=p+(floor(log10(abs(p))));
            if(idx==input){
                printf("%d\n",num[idx]);
                break;
            }
            else if(idx>input){
                printf("%d\n",idx);
                idx-=p+(floor(log10(abs(p))));

                for(i=0;i<p;i++){
                    value=i;
                    digits = log10((float)value) + 1;
                    idx++;
                    //num[idx+i]=i+1+(floor(log10(abs(i))));
                    for (int j = digits - 1; j > 0; j--) {
                        divisor = pow((float)10, j);
                        digit = value / divisor;
                        value -= digit * divisor;
                        idx++;
                        if(idx==digit){
                            printf("%d\n",digit);
                            break;
                        }
                    }
                    if(idx+i==input){
                        printf("%d\n",num[idx+i]);
                    }
                }
            }
            num[idx]=1;
            p++;
        }
    }

}
