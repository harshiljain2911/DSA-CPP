#include<iostream>
#include<vector>
using namespace std;


    int searchposition(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] >= target) {
            return i;
        }
    }
    return nums.size();
}




int main(){

    vector<int> v = {1,3,5,6};
    int target = 2;
    
    cout << searchposition(v,target) << endl;

    return 0;
}
