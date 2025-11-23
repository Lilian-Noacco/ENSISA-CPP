#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void countFrequencyBrutForce(const vector<int>& numbers) {
    set<int> uniqueNumbers(numbers.begin(), numbers.end());
    for (int num : uniqueNumbers) {
        int count = 0;
        for (int val : numbers) {
            if (val == num)
                count++;
        }
        cout << num << ": " << count << " times" << endl;
    }
}
map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> freq;
    for (int num : numbers)
        freq[num]++;
    return freq;
}

int main() {
    vector<int> numbers = {1,2,3,2,4,1,5,5,6};

    // Test countFrequencyBrutForce
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBrutForce(numbers);

    // // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int,int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }
    return 0;
}