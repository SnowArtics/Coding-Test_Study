#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int playerX, playerY, playerD;

    cin>>n>>m;
    cin>>playerY>>playerX>>playerD;
    
    int direction[4] = {3,2,1,0};  //동서남북 훼이크 바꾸는게 어려웠당
    int moveX[4] = {-1,0,1,0};
    int moveY[4] = {0,1,0,-1};
    int **map = new int*[n];       //2차원 배열 동적할당
    
    int count = 1;
    
    for(int i=0;i<n;i++){
        map[i]=new int[m];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int input;
            cin>>input;
            map[i][j] = input;
        }
    }
    
    map[playerY][playerX] = 1;
    
    for(int i=0;i<4;i++){
        if(playerD != 0){
            playerD = direction[4-playerD];
        }else{
            playerD = direction[0];
        }
        
        playerY = playerY + moveY[3-playerD];
        playerX = playerX+moveX[3-playerD];
        
        if(map[playerY][playerX]!=1){
            map[playerY][playerX]=1;
            i=0;
            count ++;
        }else{
            playerY = playerY - moveY[3-playerD];
            playerX = playerX-moveX[3-playerD];
        }
        
        if(i==3){
            cout<<count<<endl;
            return 0;
        }
    }
}