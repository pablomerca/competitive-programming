#include <iostream>
#include <algorithm>
using namespace std;

int main(){


    int nums[3];
    // ponemos \n , ya que despues vamos a scanear char, los cuales no saltean los \n, asi que lo consumimos aca antes.
    scanf("%d %d %d\n", nums, nums+1, nums+2);  

    char letters[4];
    // tambien podria haber escaneado con %s en una sola string directamente, pero queria probar hacerlo con chars y direcciones...
    scanf("%c%c%c", letters, letters+1, letters+2);

    sort(nums, nums+3);
    printf("%d %d %d\n", nums[letters[0] - 'A'], nums[letters[1] - 'A'], nums[letters[2] - 'A']);

    return 0;
}

// char - 'A' = indice (en 0), del char, en la lista de A a Z... ej: el indice de E seria 4.