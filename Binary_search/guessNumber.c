/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

int guessNumber(int n){
	long long low = 1;
    long long num = -2;
    while(low <= n){
        long long mid = (low + n) / 2;
        int guess_ = guess(mid);
        if(guess_ == 1){
            low = mid + 1;
        }
        else if(guess_ == -1){
            n = mid - 1;
        }else{
            num = mid;
            break;
        }
    }
    return num;
}
