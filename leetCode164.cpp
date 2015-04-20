#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        
        /*int* a = new int[num.size()];
        for(int i=0,s=num.size();i<s;i++){
            a[i]= num[i];
        }*/
        for (unsigned qq = 0; qq < 8; ++qq){

            for(int i=0,s=num.size();i<s;i++){
                bucket[ (num[i] >> (qq*4)) & 0xf ].push(num[i]);
                cout << hex << num[i] << " pushed to bucket " << ((num[i] >> (qq*4)) & 0xf) << endl;
            }
            //cout << '\n\n\n';
            int j = 0;
            for(int i=0;i<16;i++){
                while(!bucket[i].empty()){
                    num[j] = bucket[i].front();
                    bucket[i].pop();
                    j++;
                }
            }
        }

        
        int max = 0;
        for(int i=1,s=num.size();i<s;i++){
            if((num[i] - num[i-1]) > max) max = (num[i] - num[i-1]);
            
        }
        for(int i=0,s=num.size();i<s;i++){
            cout << dec <<num[i] << " ";
            
        }
        
        return max;
    }
    queue<int> bucket[16];


};

int main(){
    Solution s;
    vector<int> g;
    /*for (int i = 10; i >=0 ; --i){
      g.push_back(rand());
    }*/
    g.push_back(100);
    g.push_back(3);
    g.push_back(2);
    g.push_back(1);
    //g.push_back(100);
    //g.push_back(1000000);
    cout << s.maximumGap(g) <<endl;
}