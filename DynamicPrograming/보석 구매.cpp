/*
보석장에서 보석을 사야한다. 보석장에는 일렬로 보석들이 나열되어 있다.
보석들은 각자 가격을 가지고 있다.
보석을 구매할 때는 원하는 범위의 모든 보석을 구매해야 한다.
또한 최소 구매 가격, 최대 구매 가격이 정해져 있다.
범위 안의 보석을 구매할 때, 보석의 가격 합은 최소 구매 가격보다 크거나 같아야 하고, 최대 구매 가격보다 작거나 같아야 한다.
n , L , R이 주어진다. n은 보석의 개수 L은 최소 구매 가격, R은 최대 구매 가격이다.

인풋 예시:
5 5 9
1 2 3 4 5
아웃풋 예시:
6

인풋 예시:
5 0 15
1 2 3 4 5
아웃풋 예시:
15
*/

#include <iostream>
#include <vector>
#include <algorithm>  // std::lower_bound, std::upper_bound

using namespace std;

int count_valid_ranges(const vector<int>& prices, int L, int R) {
    int n = prices.size();
    vector<int> prefix_sum(n + 1, 0);

    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + prices[i];
    }

    int count = 0;
    vector<int> sorted_prefix;

    for (int ps : prefix_sum) {
        // Use lower_bound and upper_bound to find the range
        auto left = lower_bound(sorted_prefix.begin(), sorted_prefix.end(), ps - R);
        auto right = upper_bound(sorted_prefix.begin(), sorted_prefix.end(), ps - L);

        count += distance(left, right);

        // Insert the current prefix sum in sorted order
        sorted_prefix.insert(upper_bound(sorted_prefix.begin(), sorted_prefix.end(), ps), ps);
    }

    return count;
}

int main() {
    vector<int> prices = { 1, 2, 3, 4, 5 };
    int L = 5;
    int R = 9;

    cout << count_valid_ranges(prices, L, R) << endl;

    return 0;
}
