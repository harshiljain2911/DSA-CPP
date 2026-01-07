#include<iostream>
#include<vector>
using namespace std;

int remdup(vector<int>& t) {
    int p = t.size();
    int i = 0;

    for(int j = 1; j < p; j++) {
        if(t[i] != t[j]) {
            i++;
            t[i] = t[j];
        }
    }
    return i + 1;
}

int main() {
    vector<int> v = {0,0,1,2,3,3,4};
    int k = remdup(v);
    cout << k << endl;
    return 0;
}
