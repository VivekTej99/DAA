/* Large integer multiplication algorithm */

#include<stdio.h>
#include<math.h>

struct Parts {
    int a1;
    int a0;
};

int length(int num){
    int l =0;
    while(num>0) {
        num = num / 10;
        l++;
    }
    return l;

}

int max(int a[], int n) {
    int max=-999;
    for (int i=0; i<n; i++) {
        if(a[i]>max) {
            max = a[i];
        }
    }
    
    return max;
}

struct Parts divide(int n, int l) {
    l = l/2;
    struct Parts num;
    num.a0 = n/(int)pow(10,l);
    num.a1 = n%(int)pow(10,l);
    return num;
}

int multipliy(int num1, int num2) {

    int l1,l2,l;
    l1 = length(num1);
    l2 = length(num2);
    int a[] ={l1,l2};
    l = max(a,2);

    if(l==1) {
        return num1*num2;
    }else {

        struct Parts A = divide(num1, l);
        struct Parts B = divide(num2, l);
        int c2 = multipliy(A.a0, B.a0);
        int c0 = multipliy(A.a1, B.a1);
        int c1 = multipliy(A.a1+A.a0, B.a1+B.a0) - c2 - c0;
        return c2*pow(10,l) + c1*pow(10,l/2) + c0;

    }
    

}



int main() {
    int num1, num2;
    printf("\nEnter the numbers to be multiplied ( _ * _ ) :");
    scanf("%d%d", &num1, &num2);
    
    int result =  multipliy(num1, num2);
    printf("\nThe result is: %d.\n", result);

}