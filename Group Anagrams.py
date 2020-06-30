// string -> abc -> 1,1,1,0,0,...,0 -> total 26
// string -> cab -> 1,1,1,0,0,...,0 -> total 26
// create a map of tuples
// O(nk) -> n is number of strings ->k is length of string


class Solution:
    def groupAnagrams(strs):
        ans = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            ans[tuple(count)].append(s)
        return ans.values()
        


// another solution c++
// Complexity O(nklogk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        for(int i=0;i<strs.size();i++){
            temp.push_back(strs[i]);
        }
        for(int i=0;i<temp.size();i++){
            sort(temp[i].begin(),temp[i].end());
        }
        map<string,vector<string>> mp;
        for(int i=0;i<temp.size();i++){
            mp[temp[i]].push_back(strs[i]);
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            cout<<itr->first<<endl;
        }
        vector<vector<string>> ans(mp.size());
        int ind=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            vector<string> aa;
            for(int i=0;i<(itr->second).size();i++){
                aa.push_back(itr->second[i]);
            }
            ans[ind++]=aa;
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
    
};
