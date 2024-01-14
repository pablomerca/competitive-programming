#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <string>


using namespace std;

int diasHastaMes[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
map<string, int> numeroDeDia = {{"Monday",0}, {"Tuesday",1}, {"Wednesday",2}, {"Thursday",3}, {"Friday",4}, {"Saturday",5}, {"Sunday",6}};
string diaNumero[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


int main(){

    char dayName[12];
    int pstDay, pstMonth, pstYear;

    string pDayName = "Saturday";
    int presDay = 16, presMonth = 12, presYear = 2023;

    printf("input past date : DD/MM/YYYY :");
    scanf("%d/%d/%d", &pstDay, &pstMonth, &pstYear);

    int res = 0;

    res = (presYear - pstYear)*365;
    int temp1 = diasHastaMes[pstMonth-1] + pstDay;
    int temp2 = diasHastaMes[presMonth-1] + presDay;

    if(temp1 > temp2) res += -365 + temp2;  // todavia no cumplimos el anio
    else res += temp2 - temp1;      // temp1 <= temp2, osea que ya cumplimos el anio

    // falta sumar a res los dias extra por cada anio bisiesto
    // #divisores(n) en [A, B] = floor(B/n) - ceil(A/n) + 1
    float cantBisiestos = floor(float(presYear)/4) - ceil(float(pstYear)/4) + 1;
    res += int(cantBisiestos);

    printf("the number of days that passed since the given date: %d\n", res);

    int offset = (-res)%7;
    int indexDiaPasado = numeroDeDia[pDayName] + (offset+7)%7;
    cout<< "that day was " << diaNumero[indexDiaPasado%7]<<endl;

    return 0;
}