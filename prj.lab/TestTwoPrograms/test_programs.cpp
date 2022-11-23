#include <chrono>
#include <random>
//#include "matplot/matplot.h"

#include "first.h"
#include "second.h"

std::vector<int> GenerateInput(int& num){
    std::vector<int> input;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dst(0,num);
    for(int i = 0; i < num; i++){
        input.push_back(dst(rng));
    }
    return input;
}

int main(){
    int n = 200000;
    std::vector<int> input = GenerateInput(n);
    auto begin = std::chrono::steady_clock::now();
    first(input);
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms1.count() << " ms\n";

    begin = std::chrono::steady_clock::now();
    second(input);
    end = std::chrono::steady_clock::now();

    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms2.count() << " ms\n";
}