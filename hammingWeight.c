//bit manipulation le nombre de 1 dans un nombre de 32 bit 
//4ms 7.90mb 
//time and espace complexity O(1)
int hammingWeight(int n) {
    uint32_t bit = n, res = 0;
    int count = 0;
    for(int i = 0;i<32;i++){
        if(bit&1){
            count++;
        }
        bit>>=1;
    }
    return count;
}

//0 ms code solution on leetcode 
int hammingWeight(int n) {
    int result = 0;
    while(n>0){
        if(n%2==1){
            result++;
        }
        n = n/2;
    }
    return result;
    
}
