//https://www.geeksforgeeks.org/problems/word-search/1?page=2&category=Recursion&status=unsolved,attempted&sortBy=submissions



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(vector<vector<char>>&mat,string& s,int i,int j,int k,vector<vector<int>>&v,bool& ans){
        if(k==s.size()){
            ans=true;
            return;
        }
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || v[i][j]==1 || mat[i][j]!=s[k] || ans==true) return;
        
        v[i][j]=1;
        solve(mat,s,i+1,j,k+1,v,ans);
        solve(mat,s,i-1,j,k+1,v,ans);
        solve(mat,s,i,j+1,k+1,v,ans);
        solve(mat,s,i,j-1,k+1,v,ans);
        v[i][j]=0;
        
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        map<vector<int>,int> mp;
        vector<vector<int>>visit;
        for(int i=0;i<mat.size();i++){
            visit.push_back(vector<int>(mat[0].size(),0));
        }
        bool ans=false;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(ans==true) break;
                if(mat[i][j]==word[0]) solve(mat,word,i,j,0,visit,ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
