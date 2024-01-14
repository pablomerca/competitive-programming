#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char saludo[20];
    char english[] = "HELLO";
    char spanish[] = "HOLA";
    char german[] = "HALLO";
    char italian[] = "CIAO";
    char french[] = "BONJOUR";
    char russian[] = "ZDRAVSTVUJTE";

    int nCase = 0;
    while(scanf("%s", saludo), saludo[0]!='#'){
        if(strcmp(saludo, english) == 0) printf("Case %d: ENGLISH\n", ++nCase);
        else if(strcmp(saludo, spanish) == 0) printf("Case %d: SPANISH\n", ++nCase);
        else if(strcmp(saludo, german) == 0) printf("Case %d: GERMAN\n", ++nCase);
        else if(strcmp(saludo, italian) == 0) printf("Case %d: ITALIAN\n", ++nCase);
        else if(strcmp(saludo, french) == 0) printf("Case %d: FRENCH\n", ++nCase);
        else if(strcmp(saludo, russian) == 0) printf("Case %d: RUSSIAN\n", ++nCase);
        else printf("Case %d: UNKNOWN\n", ++nCase);
    }

    return 0;
}