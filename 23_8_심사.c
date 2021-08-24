#include <stdio.h>

int main(){
    unsigned int num1,num2,num3;
    scanf("%u",&num1);
    scanf("%u",&num2);

    num3 = num1 ^ num2; // XOR
    printf("%u\n",num3);

    num3 = num1 | num2 ; //OR
    printf("%u\n",num3);

    num3 = num1 & num2; // AND
    printf("%u\n",num3);

    num3 = ~num1; //NOT
    printf("%u\n",num3);

    return 0;
}
