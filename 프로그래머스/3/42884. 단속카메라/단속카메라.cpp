#include <bits/stdc++.h>

using namespace std;

bool funcSort(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), funcSort);
    
    int start = 0;
    for(int i=1;i<routes.size();++i){
        if(routes[i][0] <= routes[start][1]) continue;
        start = i;
        ++answer;
    }
    ++answer;
    
    return answer;
}