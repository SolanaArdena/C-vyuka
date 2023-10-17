#include <iostream>

using namespace std;

int main() {
    int V, K; 
    cout << "Zadejte výšku koruny, prosím: ";
    cin >> V;

    cout << "Zadejte šířku kmene, prosím: ";
    cin >> K;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < V - K / 2 - 1 ; j++) {
            cout << " ";
        }
        for (int j = 0; j < K; j++) {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}