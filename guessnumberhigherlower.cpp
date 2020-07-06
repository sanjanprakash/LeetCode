/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans, l = 1, r = n;
        int status;
        while (l < r) {
            ans = l + (r-l)/2;
            status = guess(ans);
            if (status == 0)
                return ans;
            else if (status == -1)
                r = ans-1;
            else
                l = ans+1;
        }
        return l;
    }
};
