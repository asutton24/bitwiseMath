#include <stdio.h>

int add(int a, int b){
    int c;
    while (a & b){
        c = a;
        a = a^b;
        b = (b & c)<<1;
    }
    return a | b;
}

int inc(int a){
    return add(a, 1);
}

int dec(int a){
    return add(a, -1);
}

int sub(int a, int b){
    return add(a, inc(~b));
}

int lastBit(int a){
    return !(a == (a>>1)<<1);
}

int firstBit(int a){
    return !(a == (a<<1)>>1);
}

int magnitude(int a){
    int mag = 31;
    while (mag > 0){
        if (firstBit(a)){
            return mag;
        }
        a = a << 1;
        mag = dec(mag);
    }
    return mag;
}

int mult(int a, int b){
    int sum = 0;
    for (int i = 0; i < 32; i = inc(i)){
        if (lastBit(b)){
            sum = add(sum, a<<i);
        }
        b = b>>1;
    }
    return sum;
}

int div(int a, int b){
    return 0;
}
int main(){
    printf("%d", add(1, 1));
    return 0;
}