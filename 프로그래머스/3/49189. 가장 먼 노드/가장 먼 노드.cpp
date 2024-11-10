#include <bits/stdc++.h>

using namespace std;

int check[20001];
int arrCount[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> v(n+1);
    queue<int> s;
    
    for(int i=0;i<edge.size();++i){
        int start = edge[i][0];
        int end = edge[i][1];
        v[start].push_back(end);
        v[end].push_back(start);
    }
    
    int maxNum = 0;
    s.push(1);
    arrCount[1] = 0;
    check[1] = true;
    while(s.empty() == false){
        int cur = s.front(); s.pop();
        
        for(auto nxt : v[cur]){
            if(check[nxt] == true) continue;
            s.push(nxt);
            check[nxt] = true;
            arrCount[nxt] = arrCount[cur] + 1;
            if(maxNum < arrCount[nxt]) maxNum = arrCount[nxt];
        }
    }
    
    for(int i=1;i<n+1;++i)
        if(arrCount[i] == maxNum) ++answer;    
    
    return answer;
}