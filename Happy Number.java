// another method of doint question is by using extra space 
// if square sum of the digits repeats itself then it will never become 1
// we will use set and we will insert sum in set everytime and checks if the sum is present in set then we will return false


class Solution {
    public boolean isHappy(int n) {
        int slow=sqSOD(n);
        int fast=sqSOD(sqSOD(n));
        while(true){
            
            if(slow==1 || fast==1){
                return true;
            }
            slow=sqSOD(slow);
            fast=sqSOD(sqSOD(fast));
            if(slow==fast){
                return false;
            }
        }
    }
    public int sqSOD(int n){
        int sum=0;
        while(n!=0){
            int rem=n%10;
            sum=sum+(rem*rem);
            n=n/10;
        }
        return sum;
    }
}
