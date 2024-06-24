#include <bits/stdc++.h>

using namespace std;

vector<int> arr[1000001];
map<int,int> indegreeM;
map<int,int> outdegreeM;
int check[1000001];

vector<int> solution(vector<vector<int>> edges) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> answer;
    fill(check,check+1000001,false);
    
    for(auto a : edges){
        arr[a[0]].push_back(a[1]);
        outdegreeM[a[0]]++;
        indegreeM[a[1]]++;
    }
    
    int createdVertex = 0;
    int vertexMaxNum = 0;
    for(int i = 1; i<1000001;++i){
        if(outdegreeM[i] > 1 && indegreeM[i] == 0) createdVertex = i;
    }
    
    vector<int> startVertex;
    for(auto a : arr[createdVertex])
        startVertex.push_back(a);
    
    answer.push_back(createdVertex);
    
    outdegreeM.clear();
    indegreeM.clear();
    arr[createdVertex].clear();    
    
    int donutNum = 0;
    int stickNum = 0;
    int eightNum = 0;
    
    for(int i=0;i<startVertex.size();++i){
        int vertexNum = 0;
        int edgeNum = 0;
        queue<int> qQ;
        qQ.push(startVertex[i]);
        while(!qQ.empty()){
            int cur = qQ.front(); qQ.pop();
            check[cur] = true;
            vertexNum++;
            for(auto nxt : arr[cur]){
                edgeNum++;
                if(check[nxt])continue;
                qQ.push(nxt);
            }
        }
        int num = vertexNum - edgeNum;
        if( num == 0) donutNum++;
        if(num == 1) stickNum++;
        if(num == -1) eightNum++;
    }
    
    answer.push_back(donutNum);
    answer.push_back(stickNum);
    answer.push_back(eightNum);
    
    return answer;
}