 vector<bool> visited;
 vector<vector<int> >graph;
 
 int sumVector(vector<int> &sum){
     int result = 0;
     
     for(int i=0;i<sum.size();i++){
         result += sum[i];
     }
     
     return result;
 }
 
int dfs(int x, int notPath, int value,vector<int>&data){
    value+=data[x-1];
    
    visited[x] = true;
    
    for(int i=0;i<graph[x].size();i++){
        int y = graph[x][i];
        if(!visited[y]&&y!=notPath) value = dfs(y,notPath, value,data);
    }
    
    
    visited[x] = false;
    return value;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    visited.assign(data.size()+1,0);
    graph.assign(data.size()+1,vector<int>(0));
    
    int sum = sumVector(data);
    int result = INT_MAX;
    
    
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    
    for(int i=0;i<edges.size();i++){
        int difference = dfs(edges[i][0],edges[i][1],0,data);

        if(result>abs(difference-(sum-difference))) result = abs(difference-(sum-difference));
    }
    
    return result;
}