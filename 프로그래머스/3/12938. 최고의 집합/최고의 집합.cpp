#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    
    int quotient = s/n;
    int remain = s%n;
    
    for(int i=0;i<n;++i){
        if(remain != 0){
            answer.push_back(quotient+1);
            --remain;
        }else{
            answer.push_back(quotient);
        }
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}