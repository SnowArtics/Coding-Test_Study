#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    list<char> result = {};

    getline(cin, s);

    for (auto c : s) {
        result.push_back(c);
    }

    auto it = result.end();
    int loopNum = 0;

    cin >> loopNum;

    for (int i = 0; i < loopNum; i++) {
        char instruction = 0;
        cin >> instruction;
        if (instruction == 'L') {
            if (it != result.begin()) {
                it--;
            }
        }
        else if (instruction == 'D') {
            if (it != result.end()) {
                it++;
            }
        }
        else if (instruction == 'B') {
            if (it != result.begin()) {
                it = result.erase(--it);
            }
        }
        else if (instruction == 'P') {
            char word;
            cin >> word;
            result.insert(it, word);
        }
    }

    it = result.begin();
    while (it != result.end()) {
        cout << *it;
        it++;
    }
}