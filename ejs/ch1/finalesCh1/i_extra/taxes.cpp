#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char op[7];
    double numStocks = 0, avgCost = 0;
    while(scanf("%s", op) != EOF){

        if(strcmp(op, "buy") == 0){
            double amount, cost;
            scanf("%lf %lf", &amount, &cost);
            // uptadte values for average cost, up to here, numStocks reflects data before buying.
            avgCost = (avgCost*numStocks + amount*cost)/(numStocks + amount);
            numStocks += amount;
        }
        else if(strcmp(op, "sell") == 0){
            double amount, sellCost;
            scanf("%lf %lf", &amount, &sellCost);  
            double profitPerStock = sellCost - avgCost;
            numStocks -= amount;
        }
        else if(strcmp(op, "split") == 0){
            double splitFactor;
            scanf("%lf", &splitFactor);
            numStocks *= splitFactor;
            avgCost /= splitFactor;
        }
        else if(strcmp(op, "merge") == 0){
            double mergeFactor;
            scanf("%lf", &mergeFactor);
            double rest = int(numStocks)%int(mergeFactor); // implicit type casting
            numStocks = (numStocks-rest)/mergeFactor;
            avgCost *= mergeFactor;
        }
        else{ // dies
            double sellValue;
            scanf("%lf", &sellValue);
            double profitPerStock = sellValue - avgCost;
            printf("%.2lf\n", numStocks*(sellValue - max(0.0, profitPerStock*0.3)));
        }
    }
    return 0;
}

// usar double en vez de float lo soluciona... algun problema de presicion rompe las cosas...