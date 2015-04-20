#include <iostream>
using namespace std;

const int xd = 3;

int dict[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    string convertToTitle(int n) {
    
        string ans;
    
        while(n > 0){
            ans += dict[(n-1)%xd];
            n=(n-1)/xd;
	    cout << n << endl;
        }
        
        string real_ans;
        
        for(int i =ans.size()-1;i>=0;i--){
            real_ans += ans[i];
        }
        return real_ans;
    }
int main (){

    //for (unsigned i = 0; i < 20; ++i){
        cout << convertToTitle(14) << endl;
    //}

}
