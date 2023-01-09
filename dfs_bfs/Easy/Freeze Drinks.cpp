#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > arr;

bool dfs(int y, int x){
    
    if(y>-1&&y<n&&x>-1&&x<m&&arr[y][x]==0){
        arr[y][x] = 1;
    
        dfs(y+1,x);
        dfs(y-1,x);
        dfs(y,x+1);
        dfs(y,x-1);
        
        return true;
    }else{
        return false;
    }
    
}

int main()
{
    
    cin>>n>>m;
    
    vector<int> row;
    string input;
    
    int output=0;
    
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<m;j++){
            int a = input[j]-'0';
            row.push_back(a);
        }
        
        arr.push_back(row);
        
        row.clear();
        row.shrink_to_fit();
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j)){
                output++;
            }
        }
    }
    
    cout<<output;

}