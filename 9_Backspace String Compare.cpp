// cpp solution using stack
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>st;
        for(int i=0;i<S.length();i++){
            if(S[i]!='#'){
                st.push(S[i]);
            }
            else if(!st.empty() ){
                st.pop();
            }
        }
        S="";
        while(!st.empty()){
            S=st.top()+S;
            st.pop();
        }
        
        stack<char>st1;
        for(int i=0;i<T.length();i++){
            if(T[i]!='#'){
                st1.push(T[i]);
            }
            if(!st1.empty() && T[i]=='#'){
                st1.pop();
            }
        }
        T="";
        while(!st1.empty()){
            T=st1.top()+T;
            st1.pop();
        }
        if(S==T){
            return true;
        }
        return false;
        
    }
};

//java soln
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.charAt(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.charAt(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
    }
}
