#include <bits/stdc++.h>

using namespace std;

int main()
{
    int output =0;
    string input;
    getline(cin,input);
    
    int X = input[0];
    int Y = input[1]-'0';
    
    int xArr[8]={-1,1,2,2,1,-1,-2,-2};
    int yArr[8]={-2,-2,-1,1,2,2,1,-1};
    
    cout<<X<<' '<<Y<<endl;
    
    int positionX=0;
    int positionY =0;
    for(int i=0;i<8;i++){
        positionX = X+xArr[i];
        positionY = Y+yArr[i];
        
        cout<<positionX<<' '<<positionY<<endl;
        
        if(positionX>='a'&&positionX<='f'&&positionY>=1&&positionY<=8){
            output++;
        }
    }
    
    cout<<"결과는"<<output;
}