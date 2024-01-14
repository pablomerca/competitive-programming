#include <iostream>
using namespace std;
    
int main(){

    int T; scanf("%d", &T);
    int precios[10], cantStickers[30]; // precios[i] = precio del i-esimo premio. cantStickers[i] = cant de stickers q tengo de la clase i-1
    bool stickers[10][30];  // stickers[i] = vector de "bools" que me dice los stickers necesarios para conseguir el i-esimo premio.
    while(T--){
        int n,m;  //  n types of prizes, m different types of stickers
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                stickers[i][j] = false;

        for(int i=0; i<n; i++){
            int k; scanf("%d", &k);
            for(int j=0; j<k; j++){
                int st;
                scanf("%d", &st);
                stickers[i][st-1] = true;
            }
            scanf("%d", &precios[i]);
        }
        // llenamos la cantida de stickers disponibles de cada caso.
        for(int i=0; i<m; i++) scanf("%d", &cantStickers[i]);

        // se diferencia de rucksack ya que la consigna dice que no existen 2 premios que compartarn algun sticker.
        // esto hace que se pueda resolver de forma greedy facilmente.
        int res = 0;
        for(int i=0; i<n; i++){
            // recorremos la lista de stickers necesarios del i-esimo premio, j es el j-esimo sticker requerido:
            bool posible = true;
            int menorCantSticker = 1e9;
            for(int j=0; j<m; j++){
                if(!stickers[i][j]) continue;  // si el i-esimo premio no requiere el j-esimo sticker...
                if(cantStickers[j] > 0) menorCantSticker = min(menorCantSticker, cantStickers[j]);
                else posible = false;  // cantStickers == 0;
            }
            res += (posible ? menorCantSticker*precios[i] : 0);
        }
        printf("%d\n", res);
    }
    return 0;
}