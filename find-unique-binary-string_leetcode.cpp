//https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20

class Solution {
public:
    void solve(map<string,int>&mp,string &ans,string curr,int &n){
        if(curr.size()==n){
            if(ans=="" && mp[curr]==0){
                ans=curr;
            }
            return;
        }
        solve(mp,ans,curr+"0",n);
        solve(mp,ans,curr+"1",n);
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        string ans="";
        int k=nums[0].size();
        solve(mp,ans,"",k);
        return ans;
    }
};
