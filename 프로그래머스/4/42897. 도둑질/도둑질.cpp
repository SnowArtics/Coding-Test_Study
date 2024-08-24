#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    vector<int> arr1(money.size()+1, 0);//첫번째집을 고름. 마지막 집 안고름
    vector<int> arr2(money.size()+1, 0);//첫번째 집을 안고름.
    arr1[1] = money[0];
    arr1[2] = arr1[1];
    for(int i=3;i<money.size();++i){
        arr1[i] = max(arr1[i-2] + money[i-1], arr1[i-1]);
    }
    
    arr1[1] = 0;
    arr2[2] = money[1];
    for(int i=3;i<money.size()+1;++i){
        arr2[i] = max(arr2[i-2] + money[i-1], arr2[i-1]);
    }
    
    return max(arr1[money.size()-1],arr2[money.size()]);
}