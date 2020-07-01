class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int c=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(mp.find(itr->first+1)!=mp.end()){
                c+=mp[itr->first];
            }
        }
        return c;
    }
};
