#include <chrono>
#include <random>
// #include "matplotplusplus 1.1.0/include/matplot/matplot.h"

#include "first.h"
#include "second.h"

static const int limit = 2*10E5;

std::vector<int> GenerateInput(int& num, int& max, int& unique){
    std::vector<int> input;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dst(num-unique,max);
    for(int i = 0; i < num; i++){
        input.push_back(dst(rng));
    }
    return input;
}


void MeasureTime(std::vector<int>& outputCreation1, std::vector<int>& outputDone1 , std::vector<int>& outputCreation2 ,
                 std::vector<int>& outputDone2, std::vector<int>& input, int& currentStep){

    auto begin = std::chrono::steady_clock::now();
    firstCreate(input);
    auto end = std::chrono::steady_clock::now();

    auto creation_elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time for data collection: " << creation_elapsed_ms1.count() << " ms\n";
    outputCreation1[currentStep] += creation_elapsed_ms1.count() ;

    begin = std::chrono::steady_clock::now();
    firstDone(input);
    end = std::chrono::steady_clock::now();

    auto done_elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time to analyze: " << done_elapsed_ms1.count() << " ms\n";
    outputDone1[currentStep] += done_elapsed_ms1.count();

    begin = std::chrono::steady_clock::now();
    secondCreate(input);
    end = std::chrono::steady_clock::now();

    auto creation_elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time for data collection: " << creation_elapsed_ms2.count() << " ms\n";
    outputCreation2[currentStep] += creation_elapsed_ms2.count();

    begin = std::chrono::steady_clock::now();
    secondDone(input);
    end = std::chrono::steady_clock::now();

    auto done_elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //std::cout << "The time to analyze: " << done_elapsed_ms2.count() << " ms\n";
    outputDone2[currentStep] +=done_elapsed_ms2.count();
}

int main(){
    int n = 0, unique = 0, repeated = 4, max = 100;
    std::vector<int> input;
    int stepsNum = 50;
    std::cin >> stepsNum >> repeated;
    std::vector<int> outputCreation1(stepsNum), outputDone1(stepsNum) ,
        outputCreation2(stepsNum) , outputDone2(stepsNum);

    //max numbers possible,
    for(int j = 0; j < stepsNum; j++){

        n += limit/stepsNum;
        unique = (j+1)*n/stepsNum;
        max = limit;
        input = GenerateInput(n,max,unique);

        for(int i = 0; i < repeated; i++){
            MeasureTime(outputCreation1,outputDone1, outputCreation2,outputDone2,input,j);
        }
    }

    //everything grows
    for(int j = 0; j < stepsNum; j++){

        n += limit/stepsNum;
        unique = (j+1)*n/stepsNum;
        max = n;
        input = GenerateInput(n,max,unique);

        for(int i = 0; i < repeated; i++){
            MeasureTime(outputCreation1,outputDone1, outputCreation2,outputDone2,input,j);
        }
    }

    //unique numbers are maxed
    for(int j = 0; j < stepsNum; j++){

        n += limit/stepsNum;
        unique = n;
        max = limit;
        input = GenerateInput(n,max,unique);

        for(int i = 0; i < repeated; i++){
            MeasureTime(outputCreation1,outputDone1, outputCreation2,outputDone2,input,j);
        }
    }

    //everything maxed
    for(int j = 0; j < stepsNum; j++){

        n = limit;
        unique = n;
        max = limit;
        input = GenerateInput(n,max,unique);

        for(int i = 0; i < repeated; i++){
            MeasureTime(outputCreation1,outputDone1, outputCreation2,outputDone2,input,j);
        }
    }
}