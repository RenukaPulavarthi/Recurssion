//https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28

class Solution {
public:
    void rec(vector<vector<int>>grid,int i,int j,int &cur,map<vector<int>,int>&mp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || mp[{i,j}]!=0){
            return;
        }
        mp[{i,j}]=1;
        cur+=grid[i][j];
        rec(grid,i+1,j,cur,mp);
        rec(grid,i-1,j,cur,mp);
        rec(grid,i,j+1,cur,mp);
        rec(grid,i,j-1,cur,mp);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    map<vector<int>,int>mp;
                    int cur=0;
                    rec(grid,i,j,cur,mp);
                    ans=max(ans,cur);
                }
            }
        }
        return ans;
    }
};
