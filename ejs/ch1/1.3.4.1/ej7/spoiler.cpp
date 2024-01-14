#include <iostream>
#include <algorithm>


using namespace std;
int main() {
int p[10], N = 10;
for (int i = 0; i < N; ++i) p[i] = i;
do {
for (int i = 0; i < N; ++i) 
    printf("%c ", 'A'+p[i]); // 'A'+p[i] 'A' es un valor numerico, es index de A en ascii, le suma offset el valor de p[i]
printf("\n");
}
while (next_permutation(p, p+N));  // retorna false, cuando le paso la mayor permutacion lexicograficantemte
}


// p[i] es literalmente la funcion pi() de permutacion, me re-ordena los index
// los index originales de 0 a N, me dicen el offset desde 'A' osea, representan a A B C D ...