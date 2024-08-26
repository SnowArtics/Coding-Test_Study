#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int arr2[100001];

int solution(vector<int> sticker)
{
    int answer =0;
    
    if(sticker.size() == 1)
        return sticker[0];

    //첫번째를 반드시 포함한 경우, 마지막은 반드시 포함안함
    arr[1] = sticker[0];
    arr[2] = sticker[0];
    for(int i=3;i<sticker.size();++i){
        arr[i] = max(arr[i-2] + sticker[i-1], arr[i-1]);
    }
    
    //첫번째를 포함하지 않고, 마지막은 반드시 포함함.
    arr2[1] = 0;
    arr2[2] = sticker[1];
    for(int i=3;i<sticker.size()+1;++i){
        arr2[i] = max(arr2[i-2] + sticker[i-1], arr2[i-1]);
    }
    
    answer = max(arr[sticker.size()-1], arr2[sticker.size()]);

    return answer;
}