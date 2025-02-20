//https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

class Solution {
public:
    void gen(int n,string curr,vector<string>&ans){
       if(curr.size()==n){
         ans.push_back(curr);
         return;
       }
       if(curr.size()==0 || curr[curr.size()-1]!='a'){
         gen(n,curr+"a",ans);
       }
       if(curr.size()==0 || curr[curr.size()-1]!='b'){
         gen(n,curr+"b",ans);
       }
       if(curr.size()==0 || curr[curr.size()-1]!='c'){
         gen(n,curr+"c",ans);
       } 
       return;
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        gen(n,"",ans);
        if(ans.size()<k) return "";
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};
