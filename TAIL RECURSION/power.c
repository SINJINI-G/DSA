# include <stdio.h>

int power(int x, int p){
    if(p==1)
        return x;
    else
        return x*power(x,p-1);
}

int main(){
    printf("%d",power(2,10));
    return 0;
}