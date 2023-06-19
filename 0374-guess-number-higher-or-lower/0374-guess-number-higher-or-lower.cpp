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
        int l=0;
        int r=n;
        int num=0;
        while(true){
            num=(r-l)/2+l;
            if(guess(num)==0) return num;
            else if(guess(num)==-1) r=num-1;
            else l=num+1;
        }
        
    }
};