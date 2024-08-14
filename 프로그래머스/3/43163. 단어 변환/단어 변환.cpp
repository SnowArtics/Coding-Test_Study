#include <string>
#include <vector>

using namespace std;

int answer = 50;
bool check[50];

bool OneCheck(string& _a, string& _b){
    int size = 0;
    for(int i=0;i<_a.size();++i){
        if(_a[i] != _b[i]) ++size;
    }
    
    if(size == 1) return true;
    else return false;
}

void BackTracking(string begin, string target, vector<string> words, int step){
    if(answer <= step)
        return;
    
    if(begin == target){
        answer = min(answer,step);
        return;
    }
    
    for(int i=0;i<words.size();++i){
        if(OneCheck(begin, words[i]) && !check[i]){
            check[i] = true;
            BackTracking(words[i], target, words, step+1);
            check[i] = false;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    int check = false;
    for(int i=0;i<words.size();++i){
        if(words[i] == target){
            check = true;
            break;
        }
    }
    
    if(check == false)
        return 0;
    
    BackTracking(begin, target, words, 0);
    
    return answer;
}