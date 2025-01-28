//https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

void rec(string &cur,vector<int>&v,string s,set<string>&ans){
        if(cur.size()==s.size()) {
            ans.insert(cur);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                v[i]+=1;
                cur+=s[i];
                //cout<<cur<<endl;
                rec(cur,v,s,ans);
                cur.pop_back();
                v[i]-=1;
            }
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        vector<int>lst(s.size());
        string cur="";
        for(int i=0;i<s.size();i++){
            rec(cur,lst,s,ans);
        }
        vector<string>ak(ans.begin(),ans.end());
        return ak;
        
    }
