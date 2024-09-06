#include <bits/stdc++.h>

using namespace std;

unordered_set<string> h_Set;
unordered_map<string, int> h_Map;

vector<int> solution(vector<string> gems) {
    vector<vector<int>> answer;
    
    for(auto a : gems)
        h_Set.insert(a);
    int MaxNum = h_Set.size();
    
    //map에 없으면 bp 증가. 및 map에 값을 추가 및 증가
    //map의 크기가 MaxNum이랑 크기가 같으면 aP를 증가시킴.
    //aP를 증가시키면서 이전 aP가 가리키는 값은 h_Map에서 빼는데, h_Map의 크기가 MaxNum보다 작으면 이전 값으로 리턴
    
    int aP = 0; int bP = 0;
    for(int i=0;i<gems.size();++i){
        ++bP;
        h_Map[gems[i]]++;
        if(h_Map.size() == MaxNum){
            while(true){
                if(h_Map[gems[aP]] == 1){
                    h_Map.erase(gems[aP]);
                    vector<int> temp;
                    temp.push_back(++aP);
                    temp.push_back(bP);
                    answer.push_back(temp);
                    break;
                }else{
                    h_Map[gems[aP]]--;
                    ++aP;
                }
            }
        }
    }
    
    int answerCount = 1000000;
    int answerCheck = -1;
    for(int i=0;i<answer.size();++i){
        int temp = answer[i][1] - answer[i][0];
        if(answerCount > temp){
            answerCount = temp;
            answerCheck = i;
        }
    }
    
    return answer[answerCheck];
}