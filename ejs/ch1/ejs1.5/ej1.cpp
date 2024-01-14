#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char res[30*10 + 15], line[35];
    while(1){
        // fgets(line, 35, stdin);  // de esta manera hay un \n por default al final de line, no quiero eso.
        scanf("%s", line); // esto esta escaneando palabra por palabra, no linea por linea !!!!
        if(strncmp(line, ".......", 7) == 0) break;
        strcat(res, " ");
        strcat(res, line);
    }
    printf("%s\n", res);  // el /n no deberia ser parte del string res, asi que esta bien.
    return 0;
}


