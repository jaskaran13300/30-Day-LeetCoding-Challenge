# cmax counts the maximum open parenthesis,
# which means the maximum number of unbalanced '(' that COULD be paired.
# cmin counts the minimum open parenthesis,
# which means the number of unbalanced '(' that MUST be paired.

# When you met "(", you know you need one only one ")", cmin = 1 and cmax = 1.
# When you met "(*(", you know you need one/two/three ")", cmin = 1 and cmax=3.

# The string is valid for 2 condition:

# cmax will never be negative.
# cmin is 0 at the end.


class Solution:
    def checkValidString(self, s: str) -> bool:
        cmin=0
        cmax=0
        for ch in s:
            if ch=='(':
                cmin+=1
                cmax+=1
            elif ch==')':
                cmin=max(cmin-1,0)
                cmax=cmax-1
            else:
                cmin=max(cmin-1,0)
                cmax=cmax+1
            if cmax<0:
                return False
        return cmin==0
        
        
// Another java solution
    public boolean checkValidString(String s) {
        Stack<Integer> leftID = new Stack<>();
        Stack<Integer> starID = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(')
                leftID.push(i);
            else if (ch == '*')
                starID.push(i);
            else {
                if (leftID.isEmpty() && starID.isEmpty())   return false;
                if (!leftID.isEmpty())
                    leftID.pop();
                else 
                    starID.pop();
            }
        }
        while (!leftID.isEmpty() && !starID.isEmpty()) {
            if (leftID.pop() > starID.pop()) 
                return false;
        }
        return leftID.isEmpty();
    }
