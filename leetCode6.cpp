#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        string ans = "";
        int mod = nRows+1;
        int a = nRows/2;
        int g = s.size()/mod;

        for(int k = 0;k<a;k++)
            for(int i = 0;i<=g;i++){
                if(i*mod+k > s.size()) continue;
                else ans += s[i*mod+k];
            }
        for(int i = 0;i<=g;i++){
            if(i*mod+a > s.size()) continue;
            else ans += s[i*mod+a];
            if(i*mod+nRows > s.size()) continue;
            else ans += s[i*mod+nRows];
        }
        for(int k = a+1;k<nRows;k++)
            for(int i = 0;i<=g;i++){
                if(i*mod+k > s.size()) continue;
                else ans += s[i*mod+k];
            }
            
        return ans;
    }
};
int main(){

    Solution aaa;
    cout << aaa.convert("A",1);
}
