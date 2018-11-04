#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

int main(){
    // this is a simple vector that we are going to use throughout examples
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    /*** HEAP ***/
    // Make a heap from a collection
    // more @ https://en.cppreference.com/w/cpp/algorithm/make_heap
    std::make_heap(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Push to heap
    // More at
    numbers.push_back(8);
    std::push_heap(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Pop heap
    std::pop_heap(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    /*** SORTING ***/

    // Shuffle 
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Basic sort
    // More at
    std::sort(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Shuffle for next demo
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));

    // Partial sort
    // More at
    std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));

    // n'th element sort - element that would be in n'th position if the collection was sorted
    // More at https://en.cppreference.com/w/cpp/algorithm/nth_element
    std::nth_element(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Sort heap
    // More at
    std::make_heap(numbers.begin(), numbers.end());
    std::sort_heap(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // Inplace Merge 
    // More at 
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::sort(numbers.begin(), numbers.begin() + 5);
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;    
    std::sort(numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::inplace_merge(numbers.begin(), numbers.begin() + 5, numbers.end());
    std::cout << "inplace_merge         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    /*** PARTITION ***/ 
    // Get iterator to number with certain predicate
    auto it = std::partition(numbers.begin(), numbers.end(), [](int i){return i % 2 == 0;});
    std::copy(std::begin(numbers), it, std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;

    // Parititon point
    // auto p = std::partition_point(numbers.begin(), numbers.end(), [](int i){ return i % 2 == 0; });
    // std::copy(numbers.begin(), p, std::ostream_iterator<int>(std::cout, " "));

    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    /*** PERMUTATIONS ***/

    // rotate
    // More at 
    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // shuffle
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "shuffle         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // next_permutation
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // prev_permutation
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::prev_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // reverse
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "reverse         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    /*** STABLE_# ***/
    // stable_sort - guarantees that relative order is kept
    std::vector<std::string> animals1 = { "mouse", "dog", "cat", "ant", "moth", "elephant" };
    std::vector<std::string> animals2 = { "mouse", "dog", "cat", "ant", "moth", "elephant" };
    // auto animals_for_sort = animals;
    std::sort(animals1.begin(), animals1.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "sort         ";  for(auto& i : animals1)    std::cout << i << " ";    std::cout << std::endl;
    // auto animals_for_stable_sort = animals;
    std::stable_sort(animals2.begin(), animals2.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "stable_sort         ";  for(auto& i : animals2)    std::cout << i << " ";    std::cout << std::endl;

    // stable_partition

    /*** IS_# ***/

    // is_sorted
    // More at 
    bool is_sorted =  std::is_sorted(numbers.begin(), numbers.end()); 
    std::cout << "Is sorted? " << is_sorted << std::endl;
    std::sort(numbers.begin(), numbers.end());
    is_sorted = std::is_sorted(numbers.begin(), numbers.end());
    std::cout << "Is sorted? " << is_sorted << std::endl;

    // is_heap
    // More at
    bool is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap? " << is_heap << std::endl;
    std::make_heap(numbers.begin(), numbers.end());
    is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap? " << is_heap << std::endl;

    // is_partitioned
    // More at 

    /*** IS_#_UNTIL ***/

    // is_sorted_until
    // is_heap_until
    // is_partitioned_until

    /*** QUERYING ***/

    // count
    int count = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Count of 5 = " << count << std::endl;
    numbers.push_back(5);
    count  = std::count(numbers.begin(), numbers.end(), 5);
    std::cout << "Count of 5 = " << count << std::endl;

    // accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of numbers in vector = " << sum << std::endl;

    // reduce
    // transform_reduce

    // partial_sum
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());
    std::cout << "partial_sum         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // inclusive_scan
    // transform_inclusive_scan
    // exclusive_scan
    // transform_exclusive_scan

    // inner_product
    auto inner_product = std::inner_product(numbers.begin(), numbers.end(), numbers.begin(), 0);
    std::cout << "Inner Product: " << inner_product << std::endl;
    
    // adjacent_difference
    std::adjacent_difference(numbers.begin(), numbers.end(), numbers.begin());
    std::cout << "Adjacent Difference         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // sample -     
    // More at 
    std::vector<int> sample(5);
    std::sample(numbers.begin(), numbers.end(), sample.begin(), sample.size(),  std::default_random_engine(0));
    std::cout << "Random Sample         ";  for(auto& i : sample)    std::cout << i << " ";    std::cout << std::endl;

    // all_of
    if (std::all_of(numbers.cbegin(), numbers.cend(), [](int i){ return i > 0; }))
        std::cout << "All of numbers are posivite" << std::endl;

    // any_of
    if (std::any_of(numbers.cbegin(), numbers.cend(), [](int i){ return i % 2 == 0; }))
        std::cout << "At least one of numbers is even" << std::endl;

    // none_of
    if (std::none_of(numbers.cbegin(), numbers.cend(), [](int i){ return i < 0; }))
        std::cout << "None of numbers are negative" << std::endl;

    
}