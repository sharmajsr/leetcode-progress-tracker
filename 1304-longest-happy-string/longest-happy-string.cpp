class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap;
        if( a>0 ) maxHeap.push({a,'a'});
        if( b>0 ) maxHeap.push({b,'b'});
        if( c>0 ) maxHeap.push({c,'c'});

        string ans ;
        while(!maxHeap.empty()){
            auto [ count, character ] = maxHeap.top();
            maxHeap.pop();
            int n = ans.size();
            if( n >=2  and ans[n-1] == character and ans[n-2] == character){
                if(maxHeap.empty())
                break;

                auto [ nextCount, nextCharacter ] = maxHeap.top();
                maxHeap.pop();
                ans+= nextCharacter;
                --nextCount;
                if(nextCount > 0 ) maxHeap.push({nextCount,nextCharacter});

            }
            else{
                --count;
                ans += character;
            }
            if(count > 0 ){
                maxHeap.push({count,character});
            }
            
        }
        cout<<" max heap size " << maxHeap.size()<<endl;
        return ans;
    }
};