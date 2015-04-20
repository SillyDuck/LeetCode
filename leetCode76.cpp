#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:

    int *bucket;
    int *itemNowHave;
    int front;
    int back;
    int s_size;
    string* _S;
    int bs;
    int distances;
    char pivot;
    int min;
    inline void init(){
        bucket = new int['z'+1]();
        itemNowHave = new int['z'+1]();
        front = 0;
        back = 0;
        min = 1e9;
        distances = -1;
    }
    inline bool try_and_decrease(int pos){
        if(bucket[ (*_S)[pos] ] == 0) return true;

        if( (itemNowHave[ (*_S)[pos] ] - 1) < bucket[ (*_S)[pos] ] ) return false;
        else{ itemNowHave[ (*_S)[pos] ]--;}
        return true;
    }
    inline bool not_enough(){
        for (unsigned i = 0, s = 'z'+1; i < s; ++i){
            if(itemNowHave[i] < bucket[i]) return true;
        }   
        return false;
    }
    inline bool not_enough2(){
        if (itemNowHave[pivot] < bucket[pivot]) return true;   
        return false;
    }
    inline void front_forward(){
        while( not_enough() && front <= s_size-1 ){
            if(bucket[ (*_S)[front] ] > 0){
                itemNowHave[ (*_S)[front] ]++;
            }
            front++;
        }
        front--;
    }
    inline void front_forward2(){
        while( not_enough2() && front <= s_size-1 ){
            if(bucket[ (*_S)[front] ] > 0){
                itemNowHave[ (*_S)[front] ]++;
            }
            front++;
        }
        front--;
    }
    inline void push_back(){
        while( try_and_decrease(back) && back < front){
            back++;
        }
    }
    inline void save(){
        if ( (front-back+1) < min ){
            bs = back;
            distances = min = front-back+1;
        }
    }
    string minWindow(string S, string T){

        init();
        s_size = S.size();
        _S = &S;
        for (unsigned i = 0, ss = T.size(); i < ss; ++i){
            bucket[T[i]]++;
        }
        front_forward();
        if(not_enough()) return "";
        push_back();
        if(!not_enough())save();
        

        // cout << itemNowHave['a'] << endl;
        // cout << itemNowHave['b'] << endl;
        // cout << itemNowHave['d'] << endl;
        // cout << front << endl;
        // cout << back << endl;
        // cout << S.substr(back,front-back+1)<<endl;
        
        while(front < s_size-1){
            pivot = S[back];
            back++;
            itemNowHave[ pivot ]--;
            front++;
            front_forward2();
            push_back();
            
            if(!not_enough2())save();
        }

        if(distances == -1){return "";}
        string ans = S.substr(bs,distances);
        return ans;
    }

};

int main(){

    Solution aaa;
    
            //            1         2         3         4         5
    //          012345678901234567890123456789012345678901234567890123
    //string s = "XXAXXXXXXXXXXAXAXXXBXXXXXXBXXXXBXXBXAXXXXXXAXXXXAXXBAXC";
    //string t = "AB";
    string s = "acbdbaab";
    string t = "aabd";
    
    cout << aaa.minWindow(s,t) << endl;
}
