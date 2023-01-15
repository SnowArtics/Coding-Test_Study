class Solution {
private:
    vector<vector<int> > graph;

private:
int dfs(int y,int x, int beforeArea){
    int area = beforeArea;

    if(y>-1&&y<graph.size()&&x>-1&&x<graph[0].size()){

        if(graph[y][x]==0)  return area;

        area++;
        graph[y][x]=0;
        area = dfs(y-1,x,area);
        area = dfs(y+1,x,area);
        area = dfs(y,x-1,area);
        area = dfs(y,x+1,area);

        return area;
    }

    return area;
}


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        graph = grid;
        int output = 0;

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[0].size();j++){
                if(graph[i][j]!=0){
                    int area = dfs(i,j,0);
                    if(area>output) output = area;
                }
            }
        }

        return output;
    }
};