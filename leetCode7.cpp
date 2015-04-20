#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

    int myAtoi(string str) {
        if(str.size()==0) return 0;
        int s = str.size();
        int ans = 0;
        int mul = 1;
        if(!isspace(str[0]) && !isdigit(str[0]) && str[0]!='+' && str[0]!='-') return 0;
        int start = 0;
        while(start < s && isspace(str[start])){
            start++;
        }
        if(start == s) return 0;
        if(!isdigit(str[start]) && str[start]!='+' && str[start]!='-')return 0;
        if(str[start] == '+') start++;
        else if(str[start] == '-'){start++;mul=-1;}
        if(!isdigit(str[start]))return 0;
        int end = start;
        while(end < s && isdigit(str[end])){
            end++;
        }
        for(int i = start;i<end;i++){
            if(ans== 214748364){
                if(mul ==1){
                    if(str[i]>='7') return INT_MAX;
                } 
                else {
                    if(str[i]>='8') return INT_MIN;
                }
                
            }else if(ans > 214748364){
                if(mul ==1) return INT_MAX;
                else return INT_MIN;
            }
            ans*=10;
            ans += str[i]-'0';
            
            
        }
        //if(ans>(1<<31)-1)) return INT_MAX;
        return ans*mul;
    }
int main(){
    cout << myAtoi("      -11919730356x") <<endl;
}
