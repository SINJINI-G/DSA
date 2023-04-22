# include <stdio.h>

int lcm(int a, int b, int count){
    if(a==1)
        return b;
    if(b==1)
        return a;
    if(count%a==0&&count%b==0)
        return count;
    else
        return lcm(a,b,count+1);
}

int main(){
    printf("%d",lcm(10,25,25));
    return 0;
}