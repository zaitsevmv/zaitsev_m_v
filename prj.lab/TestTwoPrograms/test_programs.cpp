#include <chrono>
#include "matplotplusplus/source/matplot/matplot.h"

#include "first.h"
#include "second.h"

std::vector<int> GenerateInput(int& num){
    std::vector<int> input;
    for(int i = 0; i < num; i++){
        input.push_back(i);
    }
    return input;
}

int main(){
    int n = 10;
    std::vector<int> input = GenerateInput(n);
    auto begin = std::chrono::steady_clock::now();
    getchar();
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";
    first(input);
    second(input);
}