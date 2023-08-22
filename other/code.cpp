#include <iostream>
using namespace std;

/*
4 1 2 3 4
5 1 2 3 4 5
*/

int main() {
    int cur, cursum;

    while (cin >> cursum) {
        while (cin.get() != '\n') {
            cin >> cur;
            cursum += cur;
        }
        cout << cursum << endl;
    }
}
// 64 位输出请用 printf("%lld")