#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    for(auto operation : operations){
        char oper = operation[0];
        int num = stoi(operation.substr(2));
        if(oper == 'I'){
            dq.push_back(num);
        }else if(oper == 'D' && !dq.empty()){
            sort(dq.begin(),dq.end());
            if(num == 1){
                dq.pop_back();
            }else{
                dq.pop_front();
            }
        }
    }
    
    sort(dq.begin(),dq.end());
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(*(dq.end()-1));
        answer.push_back(*dq.begin());
    }
    
    return answer;
}