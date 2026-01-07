#include <array>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<int, int> m;
    int target = 9;
    array<int, 4> a = {2, 7, 11, 15};
    int need;
    int current;
    for (int i = 0; i < a.size(); i++) {
        current = a[i];
        need = target - current;
        if (m.find(need) != m.end()) {
            cout << "[" << m[need] << "," << i << "]" << endl;
            break;
        } else {
            m[current] = i;
        }
    }

    return 0;
}
