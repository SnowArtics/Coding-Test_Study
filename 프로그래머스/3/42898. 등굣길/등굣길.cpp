#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> arr(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<puddles.size();++i){
        arr[puddles[i][1]][puddles[i][0]] = -1;
    }
        
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
            if(i==1&&j==1) arr[i][j] = 1;
            else if(arr[i][j] == -1) arr[i][j] = 0;
            else{
                arr[i][j] = (arr[i-1][j] + arr[i][j-1])%1000000007;
            }
        }
    }
    
    return arr[n][m];
}