#include <iostream>

using namespace std;

int main(){

    // char str[] = "abcdefg";
    // printf("original string = %s\n", str);
    // int len = 7;
    // reverse(str, str+len);
    // printf("reversed string = %s\n", str);

    char num1[4], num2[4];
    scanf("%s %s", &num1, &num2);

    // ya que tienen long 3, podemos hacer el reverse con 1 solo sawp en cada numero, en vez de usar reverse
    swap(num1[0], num1[2]);
    swap(num2[0], num2[2]);

    // atoi solo hace conversiones C-string a int, tomando valores en base 10, no sirve para pasar de bases
    int i1 = atoi(num1);  
    int i2 = atoi(num2);
    printf("%d\n", max(i1, i2));

    return 0;
}