/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int guessNumber(int n) {
        long long int low = 1;
        long long int high = n;
        long long int mid = (low +high)/2;
        while(low<=high){
            mid = (low +high)/2;
            int guessResult = guess(mid);
            if(guessResult == 0 ){
                return mid;
            }else if(guessResult > 0){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return mid;
    }
};