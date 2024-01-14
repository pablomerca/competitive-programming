#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath> // Use <cmath> instead of <math.h>

using namespace std;

const int INF = 1e9;

vector<int> matching;   // Stores the values of partial matchings
vector<pair<int, int>> coords;  // Renamed from coordenates for clarity
double minVal;

double distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    return hypot(static_cast<double>(p1.first - p2.first), static_cast<double>(p1.second - p2.second));
}

void minAssignmentCost(int i, double currentCost) {
    if (i == coords.size()) {
        minVal = min(minVal, currentCost);
        return;
    }
    if (currentCost > minVal) return;

    // If the point is already assigned, move to the next one
    if (matching[i] != -1) {
        minAssignmentCost(i + 1, currentCost);
        return;
    }
        
    // N = coords.size()
    for (int j = 0; j < coords.size(); j++) {
        // Skip if the point is already assigned or it's the same point
        if (i == j || matching[j] != -1) continue;

        // Match the points
        matching[i] = j;
        matching[j] = i;

        double temp = distance(coords[i], coords[j]);
        minAssignmentCost(i + 1, currentCost + temp);

        // Backtrack, unmatch the points
        matching[i] = -1;
        matching[j] = -1;
    }
}

int main() {
    int nCase = 1;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) break;

        N *= 2;

        coords.resize(N);
        matching.assign(N, -1);

        for (int i = 0; i < N; i++) {
            string name;
            int x, y;
            cin >> name >> x >> y;
            coords[i] = make_pair(x, y);
        }

        minAssignmentCost(0, 0);
        double ans = minVal;

        printf("Case %i: %.2f\n", nCase++, ans);

        minVal = INF;
    }

    return 0;
}
