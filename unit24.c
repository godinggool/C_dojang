#include <stdio.h>

int unit24a (unsigned char x);
int unit24b (unsigned char y, unsigned char z);
int unit24c (char p);
int flagOn (unsigned char flag);
int flagOff (unsigned char flag);

int main(){
    // unsigned long long value;
    // scanf("%llu",&value);
    //
    // value = value << 20 >> 4;
    // printf("%llu\n",value);

    printf("[24a]\n");
    unsigned char num1 = 8;     // 0000 1000
    unit24a(num1);
    printf("______________________\n");


    printf("[24b]\n");
    unsigned char num2 = 240;     // 1111 0000
    unsigned char num3 = 15;      // 0000 1111
    unit24b(num2,num3);
    printf("______________________\n");


    printf("[24c]\n");
    char num4 = -125;   // 1000 0011
    unit24c(num4);      // -4: 1111 1100, 모자라는 공간은 부호비트값은 1로 채워진다.
    char num5 = 67;     // 0100 0011
    unit24c(num5);      // 2: 0000 0010, 모자라는 공간은 부호비트값 0으로 채움.
    printf("______________________\n");


    printf("[flagOn]\n");
    unsigned char flag = 0;
    printf("before turn on : %u\n", flag);
    flagOn(flag);
    printf("______________________\n");


    printf("[flagOff]\n");
    unsigned char flag = 7;
    printf("before turn on : %u\n", flag);
    flagOff(flag);
    printf("______________________\n");


    return 0;
}



/* 1) 시프트 연산과 2의 거듭제곱  */
int unit24a (unsigned char x) {
    //
    printf("8을 오른쪽으로 2번 이동 : %u\n", x << 2);  // 0010 0000 : 32

    // 왼쪽으로 2씩 이동
    printf("8을 쪽으로 2번 이동 :%u\n", x >> 2);   // 0000 0010 : 2

    return 0;
}



/* 2) 시프트 연산으로 자릿수를 넘어서는 경우 */
int unit24b (unsigned char y, unsigned char z) {
    printf("240을 왼쪽으로 두번 : %u\n", y << 2);  // 1100 0000 : 192

    printf("15를 오른쪽으로 두번 : %u\n", z >> 2);  // 0000 0011 : 3
/* 비트를 넘어서면 그대로 사라짐! */
    return 0;
}



/* 3) 부호있는 자료형의 비트 연산 */
int unit24c (char p) {
    printf("%d를 오른쪽으로 5번 이동 : %d\n", p, p >> 5);

    return 0;
/* 부호 유무에 따라 다르게 작용한다는 것!! */
}



/* 4) 비트 연산자로 플래그 처리하기 */


int flagOn (unsigned char flag) {
    flag |= 1;  // 0000 0001 마스크와 비트 OR로 8번째 비트를 켬
    flag |= 2;  // 0000 0001 마스크와 비트 OR로 7번째 비트를 켬
    flag |= 4;  // 0000 0100 마스크와 비트 OR로 6번째 비트를 켬
/*
    OR로 비트를 킬수 있는 이유 : 꺼져있으면 켜고 꺼져있으면 그대로 유지한다
    0|1 -> 1
    1|1 -> 1
*/
    printf("after turning on 6,7,8th bit : %u\n", flag);

    if (flag & 1)   // &로 0000 0001 비트가 켜져있는지 확인
        printf("0000 0001 is on\n");
    else
        printf("0000 0001 is off\n");

    if (flag & 2)
        printf("0000 0010 is on\n");
    else
        printf("0000 0010 is off\n");

    if (flag & 4)
        printf("0000 0100 is on\n");
    else
        printf("0000 0100 is off\n");
/*
    AND을 쓰는 이유 : 두비트가 모두 1이어야 1
    flag : 0000 0111 & 4 : 0000 0100 -> 6번째 비트가 1 이 된다.
*/
    return 0;
}


int flagOff (unsigned char flag) {
    flag &= ~2;
/*
    1. 마스크 값을 ~연산자로 비트를 뒤집고 0000 0010 -> 1111 1101
        -> 끄고자 하는 비트 이외의 값은 모두 1이 된다.
    2. &= 연산자를 사용하여 특정 비트(7th)를 끈다. -> 1111 1101
    3.
*/
    printf("Turn off 7th bit : %u\n", flag);

    if (flag & 1)   // &로 0000 0001 비트가 켜져있는지 확인
        printf("0000 0001 is on\n");
    else
        printf("0000 0001 is off\n");

    if (flag & 2)
        printf("0000 0010 is on\n");
    else
        printf("0000 0010 is off\n");

    if (flag & 4)
        printf("0000 0100 is on\n");
    else
        printf("0000 0100 is off\n");
/*
    AND을 쓰는 이유 : 두비트가 모두 1이어야 1
    flag : 0000 0111 & 4 : 0000 0100 -> 6번째 비트가 1 이 된다.
*/
    return 0;
}
