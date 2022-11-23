#include <chrono>
#include <random>
#include "matplotplusplus 1.1.0/include/matplot/matplot.h"

#include "first.h"
#include "second.h"

std::vector<int> GenerateInput(int& num, int& max, int& unique){
    std::vector<int> input;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dst(max-unique,max);
    for(int i = 0; i < num; i++){
        input.push_back(dst(rng));
    }
    return input;
}

int main(){
    /*int n = 100, unique = 100, repeated = 4, max = 100;
    std::vector<int> input;
    std::vector<int> outputCreation1 , outputDone1 , outputCreation2 , outputDone2;
    for(int i = 0; i < repeated; i++){

        input = GenerateInput(n,max,unique);

        auto begin = std::chrono::steady_clock::now();
        firstCreate(input);
        auto end = std::chrono::steady_clock::now();

        auto creation_elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "The time for data collection: " << creation_elapsed_ms1.count() << " ms\n";
        outputCreation1.push_back(creation_elapsed_ms1.count());

        firstDone(input);
        end = std::chrono::steady_clock::now();
        auto done_elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin - creation_elapsed_ms1);
        std::cout << "The time to analyze: " << done_elapsed_ms1.count() << " ms\n";
        outputDone1.push_back(done_elapsed_ms1.count());

        begin = std::chrono::steady_clock::now();
        secondCreate(input);
        end = std::chrono::steady_clock::now();

        auto creation_elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "The time for data collection: " << creation_elapsed_ms2.count() << " ms\n";
        outputCreation2.push_back(creation_elapsed_ms2.count());

        secondDone(input);
        end = std::chrono::steady_clock::now();
        auto done_elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin - creation_elapsed_ms1);
        std::cout << "The time to analyze: " << done_elapsed_ms2.count() << " ms\n";
        outputDone2.push_back(done_elapsed_ms2.count());
    }*/
    matplot::plot({1,2});
    matplot::show();

}