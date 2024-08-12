#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
int check[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(check[j]) continue;
            if(computers[i][j] == 0)continue;
            ++answer;
            queue<int> q;
            q.push(j);
            while(!q.empty()){
                int cur = q.front(); q.pop();
                check[cur] = true;
                for(int k=0;k<n;++k){
                    if(check[k]) continue;
                    if(computers[cur][k] == 0)continue;
                    q.push(k);
                }
            }
        }
    }
    
    return answer;
}