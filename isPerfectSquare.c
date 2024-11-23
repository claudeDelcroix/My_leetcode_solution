bool isPerfectSquare(int num) {
    if(num == 1){
        return true;
    }

    int start = 0,end = num / 2;

    while(start <= end){
        long long mid = (start + end)/2;
        long long sqrt = (long long)(mid * mid);

        if(sqrt == num){
            return true;
        }else if(sqrt < num){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return false;
}
