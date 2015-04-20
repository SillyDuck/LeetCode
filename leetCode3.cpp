#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
//    int back;
//    int front;
//    int sss;
//    bool t[256];
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int t[256];
        for (int i = 0; i < 256; ++i){
            t[i]=-1;
        }
        // int count[256];
        // int b = -1;
        // int old_b;
        // set<char> accum;
        // int max = 1;
        int mmax=0,m=0;
        for(int i=0,ss=s.size();i<ss;i++){
            m = max(t[s[i]]+1,m);
            cout << s[i] << ",m=" << m;// << endl;
            t[s[i]]=i;
            cout << ",now=" << i-m+1 << endl;
            mmax = max(mmax,i-m+1);

        }
        
        return mmax;

    }
};
int main(){

    Solution aaa;
    string c = "abba";
    cout <<  c<<endl<<   aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "dvdf";
    cout <<   c<<endl<<  aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "ohomm";
    cout <<   c<<endl<<  aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "abc";
    cout <<   c<<endl<<  aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "bdb";
    cout <<  c<<endl<<   aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "tmmzuxt";
    cout <<   c<<endl<<  aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
    c = "vqblqcb";cout <<  c<<endl<<   aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;

    c = "aa";
    cout <<  c<<endl<<   aaa.lengthOfLongestSubstring(c)<<endl<<endl<<endl<<endl;
}
