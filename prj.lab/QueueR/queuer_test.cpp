#include <iostream>
#include <vector>
#include "queuer.h"

int main(){
    QueueR m;
    std::vector<int> n{ 4, 2, 6 ,3 ,6, 9 ,2345 , 5 , 532, 3, 5, 5 ,5 ,5};
    for(int i = 0;i < n.size();i++){
        m.push(i);
    }
}
