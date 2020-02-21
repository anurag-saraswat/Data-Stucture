#include <stdio.h>

void toh(int n,char src, char dest , char aux){
      if(n==1){
          printf("\nmove disk %d from %c to %c",n,src,dest);
          return;
          }
    else{
         toh(n-1,src,aux,dest);
         printf("\nmove disk %d from %c to %c",n,src,dest);
         toh(n-1,aux,dest,src);

    }  

}

int main() {
    
    toh(4,'A','B','C');
}
