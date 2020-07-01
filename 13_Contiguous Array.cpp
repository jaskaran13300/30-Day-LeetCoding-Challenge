// make 0 as -1 
// if compute the element sum
// if same sum repeats then compare with max size
// if it will become 0 then it will always be the max starting index will be 0

class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int maxsize = 0, startindex; 
        int n=arr.size();
        if(n==0){
            return 0;
        }
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int a=arr[i];
            if(a==0){
                a=-1;
            }
            count+=a;
            if(count==0){
                if(maxsize<i){
                    maxsize=i+1;
                }
            }
            if(mp.find(count)==mp.end()){
                mp[count]=i;
            }
            else{
                if(i-mp[count]>=maxsize){
                    maxsize=i-mp[count];
                }
            }
        }
        return maxsize;
        } 
};
