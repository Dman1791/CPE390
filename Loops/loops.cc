#include <iostream>
using namespace std;

int main() {
        cout << "Triples:" << endl;
        for (int i=1; i <= 10000; i *= 3) {
                cout << i << endl;
        }
        cout << endl;

        cout << "Odds:" << endl;
        for (int i=1; i <= 21; i += 2) {
                cout << i << endl;
        }
        cout << endl;

        cout << "Sum multiples of 3:" << endl;
        int sum = 0;
        for (int i=3; i <= 30; i += 3) {
                sum += i;
        }
        cout << sum;
}
