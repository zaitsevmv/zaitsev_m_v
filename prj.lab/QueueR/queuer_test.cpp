#include <iostream>
#include <vector>
#include "queuer.h"

int main(){
    QueueR m;
    std::vector<int> n{ 4, 2, 6 ,3 ,6, 9 ,2345 , 5 , 532, 3, 5, 5 ,5 ,5};
    for(int i = 0;i < n.size();i++){
        m.push(n[i]);
    }
    for(int i = 0;i < n.size();i++){
        std::cout << m.top() << std::endl;
        m.pop();
    }
    m.pop();
    std::cout << m.isEmpty();
    m.push(6);
    std::cout << m.top() << std::endl;
    std::cout << m.front();
    std::cout << m .isEmpty();
}
