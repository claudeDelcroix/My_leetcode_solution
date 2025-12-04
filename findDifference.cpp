#include <iostream>
#include <string>
class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        if(s.size() == 0){
            return t[0];
        }
        int arr[256] = {0};

        for(char& x : s){
            arr[static_cast<int>(x)]++;
        }
        char res = ' ';
        for(char& x : t){
            arr[static_cast<int>(x)]--;
            if(arr[static_cast<int>(x)] < 0){
                res = x;
                break;
            }
        }
        
        return res;
    }
};

int main(){
    
}

//solution a 0ms 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ss = accumulate(s.begin(), s.end(), 0);
        int st = accumulate(t.begin(), t.end(), 0);
        return char(st - ss);
    }
};

//solution avec XOR ^= 
// Solution alternative utilisant XOR
char result = 0;
for (char c : s) result ^= c;
for (char c : t) result ^= c;
return result; // Il reste uniquement le caractère en trop
