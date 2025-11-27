// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n == 1)return n;
    long long low = 1, high = n;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        printf("mid = %d\n",mid);
        if(!isBadVersion(mid)){
            low = mid + 1;
        }else{
            high = mid - 1;
            first = mid;
        }
    }
    return first;
}
