//https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void ans_rec(vector<int>ca,int n,int target,int s,int idx,vector<vector<int>>&ans,vector<int>cur){
        if(s==target){
            ans.push_back(cur);
            return;
        }
        if(idx>=n || s>target) return;
        ans_rec(ca,n,target,s,idx+1,ans,cur);
        cur.push_back(ca[idx]);
        ans_rec(ca,n,target,s+ca[idx],idx,ans,cur);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>cur;
        ans_rec(candidates,candidates.size(),target,0,0,v,cur);
        return v;
    }
};
