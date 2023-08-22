// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// /*
// 4
// a d cc ddf
// */
// int main() {
//     int n;
//     cin >> n;
//     vector<string> vec(n);
//     for (int i = 0; i < n; i++) {
//         cin >> vec[i];
//     }
//     sort(vec.begin(), vec.end());

//     for (int i = 0; i < n; i++) {
//         cout << vec[i] << " ";
//     }
// }
// // 64 位输出请用 printf("%lld")


#include <bits/stdc++.h>

using namespace std;

// a,d,bb,c
int main() {
    string s, n;
    while (getline(cin, s)) {
        vector<string> v;
        stringstream ss(s);
        string temp;
        while (getline(ss, temp, ',')) {
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] << ",";
        }
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}