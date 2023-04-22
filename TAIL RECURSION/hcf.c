# include <stdio.h>

int hcf(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(b==0)
        return b;
    else
        return hcf(b,a%b);
}

int main(){
    printf("%d",hcf(100,25));
    return 0;
}