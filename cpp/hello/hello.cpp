#include <bits/stdc++.h>
using namespace std;


int main() { 
    int maxX = (1U << 31) - 1;
    int minX = ~(1LL << 31) +1; // two complement

    int maxx = INT_MAX;
    int minx = INT_MIN;

    double doublemax = DBL_MAX;
    double doublemin = DBL_MIN;

    cout << maxX << minX << endl;
    cout << maxx << minx << endl;

    cout << doublemax << doublemin << endl;
}
