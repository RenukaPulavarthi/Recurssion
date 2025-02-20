//https://leetcode.com/problems/letter-tile-possibilities/?envType=daily-question&envId=2025-02-17

class Solution {
public:
    void solve(string &tiles,map<string,int>&mp,vector<bool>b,string curr){
        mp[curr]++;
        for(int i=0;i<tiles.size();i++){
            if(b[i]==false){
                b[i]=true;
                solve(tiles,mp,b,curr+tiles[i]);
                b[i]=false;
            }
        }

    }
    int numTilePossibilities(string tiles) {
        map<string,int>mp;
        vector<bool>v(tiles.size(),false);
        solve(tiles,mp,v,"");
        return mp.size()-1;
        
    }
};
