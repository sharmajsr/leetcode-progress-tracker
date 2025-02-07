class Solution {
public:
    int findIndexOfMaxElement(vector<int>v, int idx){
        int curMaxEl = INT_MIN , curMaxElIndx = 0 ;
        for(int i= idx - 1; i >= 0;i--){
            if(idx == v[i]){
                return i;
            }
        }
        return curMaxElIndx;
    }
    vector<int>reve(vector<int>arr,int k){
        cout<<"starting rev : "<<endl;
        reverse(arr.begin(),arr.begin()+k);
        return arr;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        vector<int>n2 = arr;
        int j = arr.size() ;
        sort(n2.begin(), n2.end());
        while(n2 != arr){
            cout<<"Value of j : "<<j<<endl;
            int maxEleIdx = findIndexOfMaxElement( arr,j );
            cout<<j<<" "<<maxEleIdx<<endl;
            if(maxEleIdx != j){
                // arr = reve(arr,maxEleIdx);
                reverse(arr.begin(),arr.begin()+maxEleIdx+1);
                // for(auto i : arr)   cout<<i<<" ";
                // cout<<endl;
                // arr = reve(arr,j) ;
                reverse(arr.begin(),arr.begin()+j);
                // for(auto i : arr)   cout<<i<<" ";
                // cout<<endl;
                ans.push_back(maxEleIdx+1);
                ans.push_back(j);
                
            }
            --j;
            // for(auto i : arr)   cout<<i<<" ";
            // cout<<endl;
            
            
        }
        return ans;
    }
};