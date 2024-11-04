#include <bits/stdc++.h>

using namespace std;

bool check[101];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    int startPoint = 0;
    
    vector<pair<int, int>> v[101];
    for(int i=0;i<costs.size();++i){
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        v[start].push_back({end, cost});
        v[end].push_back({start,cost});
        startPoint = start;
    }
    
    priority_queue<tuple<int,int,int>
                    , vector<tuple<int,int,int>>
                    , greater<tuple<int,int,int>>> pq;    
    
    check[startPoint] = true;
    for(auto cur : v[startPoint]){
        pq.push({cur.second, startPoint, cur.first});
    }
    int count = 1;
    while(count < n){
        int cost, start, end;
        tie(cost, start, end) = pq.top(); pq.pop();
        if(check[end] == true) continue;
        check[end] = true;
        answer += cost;
        ++count;
        for(auto a : v[end]){
            if(check[a.first] == false)
                pq.push({a.second, end, a.first});
        }
    }
    
    
    return answer;
}