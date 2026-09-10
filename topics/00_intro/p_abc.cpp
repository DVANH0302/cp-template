#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    vector<int> nums(7);

    for (int i = 0; i < 7; ++i){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());


    printf("%d %d %d\n", nums[0], nums[1], nums[6]-nums[0] -nums[1]);
}