//n must belong to odd number
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==((n/2)+1)){
               printf("*");
            }
            else if((i==1)&&(j==1)){
                printf("*");
            }
            else if((i==1)&&(j<=(n/2))){
                printf(" ");
            }
            else if((i==1)&&(j>(n/2))){
                printf("*");
            }
            else if( (i!=1 && i!=n && i!=(n/2+1))){
                if( j==(n/2+1)){
                    printf("*");
                    }
                else if( (j==1)&& i<=n/2 ){ printf("*");}
                else if( (j==n)&& i>(n/2) ){ printf("*");}
                else{printf(" ");}
            }
            else if (i==n){
                if(j==n){printf("*");}
                else if(j<=n/2+1){printf("*");}
                else if(j>n/2){printf(" ");}
            }


        }
    printf("\n");
    }
}
