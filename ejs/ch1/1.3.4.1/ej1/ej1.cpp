#include <iostream>


int main(){

    float num;
    while(scanf("%f", &num) != EOF){
        printf("el numero redondeado es: %7.3f\n", num);  
        // 7 de width (right-aligned x default al aplicar width)
        // .3 digitos de precision al redondear
    }


    return 0;
}