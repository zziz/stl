#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    // Make a heap from a collection
    // More @ https://en.cppreference.com/w/cpp/algorithm/make_heap
    std::make_heap(numbers.begin(), numbers.end());

    std::cout << "make_heap     ";
    for(auto& i : numbers) std::cout << i << " ";    
    std::cout << std::endl;

    // Push to heap
    // More @ https://en.cppreference.com/w/cpp/algorithm/push_heap
    numbers.push_back(8);
    std::push_heap(numbers.begin(), numbers.end());

    std::cout << "push_heap     "; 
    for(auto& i : numbers)    std::cout << i << " ";
    std::cout << std::endl;

    // Pop heap
    // More @ https://en.cppreference.com/w/cpp/algorithm/pop_heap
    std::pop_heap(numbers.begin(), numbers.end());

    std::cout << "pop_heap      ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
    return 0;
}