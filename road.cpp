#include<stdio.h>
#include<set>
using namespace std;
set<int> s;
int main(){
    int n,m;
    int i,j,k;
    int choice;
    int idx=0;
    int a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++){
        scanf("%d",&choice);
        if(choice==0){
            scanf("%d %d",&a,&b);
            s.insert(a);s.insert(b);
        }
        else if(choice==1){
            scanf("%d %d",&a,&b);
            if(*s.upper_bound(a-1)>*s.end()||*s.lower_bound(b)<*s.begin()){
                printf("0");
            }
            else if(*s.lower_bound(b) > a&&*s.upper_bound(a-1)<b){
                printf("0\n");
            }
            else{
                printf("1\n");
            }

        }
    }

}
