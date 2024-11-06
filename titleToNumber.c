int titleToNumber(char* str) {
    long long int ans = 0;
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++){
        ans *= 26;
        ans = ans + (str[i] - 65 + 1);
    }
    return ans;
}
