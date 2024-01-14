#include <iostream>
#include <cstring>
using namespace std;

inline bool isDigit(char ch){
    return (48 <= int(ch) && int(ch) <= 57);
}
inline bool isVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i'|| ch=='o'|| ch=='u');
}
inline bool isCons(char ch){
    return (97 <= int(ch) && int(ch) <= 122 && !isVowel(ch));
}

int main(){
    
    char str[] = "fasEfaFGASj %34 62 kk dfaslAbE Uuio 9";
    int nVowels = 0, nCons = 0, nDigits = 0;
    for(int i=0; i<size(str); i++){

        if(isupper(str[i])) str[i] = tolower(str[i]);

        char ch = str[i];
        if(isVowel(ch)) nVowels++;
        else if(isCons(ch)) nCons++;
        else if(isDigit(ch)) nDigits++;
    }
    printf("vowels: %d, consonants: %d, digits: %d\n", nVowels, nCons, nDigits);
    printf("string resultante: %s\n", str);
    return 0;
}