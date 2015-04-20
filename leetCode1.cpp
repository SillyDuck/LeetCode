#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> a;
        map<int,int>::iterator it;

        for(int i = 0, s = numbers.size(); i < s; i++){
            a.insert(pair<int,int>(numbers[i],i+1));
        }
        for(int i = 0, s = numbers.size(); i < s; i++){
            it = a.find( target - numbers[i] );
            if (it != a.end()){
		cout << numbers[i] << " " << it->second <<endl;
                if( it->second > i+1 ){ vector<int> ans; ans.push_back(i+1); ans.push_back(it->second); return ans;}
                else{ vector<int> ans; ans.push_back(it->second); ans.push_back(i+1); return ans;}
            }
        }
    }
};

int main(){

    Solution aaa;
	vector<int> gg;
	gg.push_back(3);    
	gg.push_back(2);    
	gg.push_back(4);
    aaa.twoSum(gg,6);
}
