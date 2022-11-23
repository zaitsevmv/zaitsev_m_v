#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

void firstCreate(std::vector<int>& input) {
    int n = 0;
    n = input.size();
    std::vector<int> as(200001, -1);
    for (int i = 0; i < n; i += 1) {
        int idx = 0;
        idx = input[i];
    }
}

void firstDone(std::vector<int>& input) {
    int n = input.size();
    std::vector<int> as(200001, -1);
    for (int i = 0; i < n; i += 1) {
        as[input[i]] = n - i - 1;
    }
    std::cout << "ans1 " << std::distance(as.begin(),std::max_element(as.begin(), as.end())) << '\n';
}

