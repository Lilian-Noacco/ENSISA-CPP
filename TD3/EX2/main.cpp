#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j}; // Retourne les indices
            }
        }
    }
    return {}; // Pas de solution
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> map; // map[valeur] = indice

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }

        map[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0]
         << ","
         << indicesBruteForce[1]
         << "]" << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0]
         << ","
         << indicesOptimal[1]
         << "]" << endl;

    return 0;
}