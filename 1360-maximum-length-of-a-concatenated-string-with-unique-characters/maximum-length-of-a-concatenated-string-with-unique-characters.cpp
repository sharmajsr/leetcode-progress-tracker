class Solution {
public:
    int hasDuplicate(string a,string b){
        unordered_map<char,int>um,um2;
        for(auto i:a){
            if(um[i]>0) return true;
            ++um[i];
        }
        
        for(auto i : b){
            if(um2[i]>0)    return true;
            ++um2[i];
            if(um.find(i)!=um.end())    return true;
        }
        return false;
    }
    int solve(vector<string>arr,int start,string curr){
        // cout<<"solve "<<start<<" "<<curr<<endl;
        if(start>=arr.size()){
            return curr.size();
        }
        int incl = 0 ;
        int excl = 0 ;
        if(hasDuplicate(curr,arr[start])){
            excl = solve(arr,start+1,curr);
        }else{
            excl = solve(arr,start+1,curr);
            incl = solve(arr,start+1,curr+arr[start]);
        }
        return max(incl,excl);
        
    }
    int maxLength(vector<string>& arr) {
        // sort(arr.begin(),arr.end());
        string temp;
        int ans =0 ;
        return solve(arr,0,temp);
        // return ans;
    }
};