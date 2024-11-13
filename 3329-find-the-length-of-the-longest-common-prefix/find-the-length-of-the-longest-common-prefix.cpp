class Solution {
public:
    int lcp(int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        string ans ;
        int i=0,j=0;
        while(i<s1.size() and j<s2.size()){
            if(s1[i] == s2[j]){
                ans+=s1[i];
                ++i;
                ++j;
            }
            else{
                break;
            }
        }
        return ans.size();

    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m1 = 0 , m2 = 0 ; 
        for(auto i : arr1)  m1 = max(i,m1);
        for(auto i : arr2)  m2 = max(i,m2);
        if(m1 > m2){
            vector<int>temp = arr1;
            arr1=arr2;
            arr2=temp;
        }

        int n = arr1.size(), m = arr2.size(),longestCommonPrefi=INT_MIN;
        unordered_map<string,int>mp;

        for(int j=0;j<n;j++){
            string s1 = to_string( arr1[j] );
            for(int i=0; i < s1.size() ;  i++){
                string m = s1.substr(0,i+1);
                ++mp[m];
            }
            // cout<<endl;
        }  
        // for(auto i : mp)    cout<<i.first<<" ";
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int temp = lcp( arr1[i], arr2[j] );
        //         if(temp > longestCommonPrefi){
        //             longestCommonPrefi = temp;
        //         }
        //     }
        // }
        for(int i=0;i<m;i++){
            string cur = to_string(arr2[i]);
            // cur = "1000";
            // cout<<"start : "<<cur<<endl;
            
            while(cur.size()>0 and mp.find(cur) == mp.end()){
                // cout<<cur<<endl;
                // cur.erase(cur.size()-1);
                cur = cur.substr(0,cur.size()-1);
            }
            // cout<<"end : "<<cur<<endl;
            
            int temp = cur.size();
            
            if( temp > longestCommonPrefi){
                longestCommonPrefi = temp;
            }
        }
        return longestCommonPrefi;
    }
};
// { 13 ,27 , 25}
// 27 
// { 1,10 ,100 }
// '10'
// longestCommonPrefi = 3
// O ( max(n,m))
