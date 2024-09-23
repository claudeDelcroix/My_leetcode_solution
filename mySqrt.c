int mySqrt(int x) {
    if(x == 1)return 1;
    if(x < 2){
        return 0;
    }

  //start = 0 ou start = 1 pour les deux valeurs le programme fonctionne
    int start = 0, end = x / 2, result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long sqr = (long)mid * mid;

        if (sqr == x) {
            return mid;
        } else if (sqr < x) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    return result;
}
