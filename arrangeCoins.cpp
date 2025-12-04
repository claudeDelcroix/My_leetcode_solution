#include <iostream>

class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1, resultat = -1;
        while(n >= 0){
            n -= row;
            if(n == 0){
                resultat = row;
            }
            if(n < 0){
                resultat = row - 1;
            }
        }
        return resultat;
    }
};

int main(){

    return 0;
}

//0 ms
int func(int x) {
    if ((x + 1) % 2 == 0) return ((x + 1) / 2) * x;
    return (x / 2) * (x + 1);
}
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = 65535;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (func(mid) < n) left = mid + 1;
            else if (func(mid) == n) return mid;
            else right = mid - 1;
        }
        return right;
    }
};
