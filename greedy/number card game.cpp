#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    vector<int> arr;
    int output = 0;
    int current_number = 10001;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i * m; j < (i + 1) * m; j++) {
            if (current_number > arr[j]) {
                current_number = arr[j];
            }
        }
        if (output < current_number) {
            output = current_number;
        }
        current_number = 10001;
    }

    cout << output << endl;
}