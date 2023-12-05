#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int result[26];

    for (int i = 0; i < 26; i++) {
        result[i] = 0;
    }

    cin >> s;

    for (auto c : s) {
        result[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << result[i] << ' ';
    }
}