#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(!isalnum(s[i]))
            i++;
            else if(!isalnum(s[j]))
            j--;
            else
            {
                if(tolower(s[i])!=tolower(s[j]))
                {
                    return false;
                }
                i++;
                j--;
            }
            

        }
        return true;
        
    }

int main(){

    string k1 = "Harshil♥Prachi";
    string k2 = "Naman ;@";
    string k3 = "Ee eE ";

    cout << "k1-->" << isPalindrome(k1) << endl;
    cout << "k2-->" << isPalindrome(k2) << endl;
    cout << "k3-->" << isPalindrome(k3) << endl;
    return 0;
}    
