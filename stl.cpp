#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <functional>
// #include <execution>

void heap_algorithms(){
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
}

void sorting_algorithms(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Basic sort
    // More @ https://en.cppreference.com/w/cpp/algorithm/sort
    std::cout << "sort              ";
    std::sort(numbers.begin(), numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Partial sort
    // More @ https://en.cppreference.com/w/cpp/algorithm/partial_sort
    std::cout << "partial_sort      ";
    std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // n'th element sort - element that would be in n'th position if the collection was sorted
    // More at https://en.cppreference.com/w/cpp/algorithm/nth_element
    std::cout << "nth_element       ";
    std::nth_element(numbers.begin(), numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Sort heap
    // More @ https://en.cppreference.com/w/cpp/algorithm/sort_heap
    std::make_heap(numbers.begin(), numbers.end());
    std::sort_heap(numbers.begin(), numbers.end());
    std::cout << "sort_heap         ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Shuffle for demo purpose
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // Inplace Merge 
    // More @ https://en.cppreference.com/w/cpp/algorithm/inplace_merge
    std::sort(numbers.begin(), numbers.begin() + 5);

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    std::cout << "Current State     ";
    std::sort(numbers.begin() + 5, numbers.end());
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::inplace_merge(numbers.begin(), numbers.begin() + 5, numbers.end());
    std::cout << "inplace_merge     ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
}

void partition_algorithms(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 9, 10};

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    // Partition - reorder the input so that elements satisfying the predicate are clustered at the beginning
    // More @ https://en.cppreference.com/w/cpp/algorithm/partition
    auto it = std::partition(numbers.begin(), numbers.end(), [](int i){return i % 2 == 0;});

    std::cout << "After partition   ";
    for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    // Returned iterator points to first element that doesn't satisfy the predicate
    std::cout << "Returned iterator " << *it << std::endl;
    
    // Parititon point - return pointer to first element that doesn't satisfy the predicate partition point
    // This function doesn't modity the elements, only locates the pointer
    // More @ https://en.cppreference.com/w/cpp/algorithm/partition_point
    auto p = std::partition_point(numbers.begin(), numbers.end(), [](int i){ return i % 2 == 0; });
    std::cout << "Partition pointer " << *p << std::endl;
}

void permutation_algorithms(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // rotate - rotate the container (like a belt)
    // More @ https://en.cppreference.com/w/cpp/algorithm/rotate
    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate                ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate                ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // shuffle - shuffle elements (values of elements) in container
    // More @ https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "shuffle               ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // next_permutation - get next permutation of container
    // More @ https://en.cppreference.com/w/cpp/algorithm/next_permutation
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // prev_permutation - get previous permutation
    // More @ https://en.cppreference.com/w/cpp/algorithm/prev_permutation
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::prev_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // reverse - reverse the container
    // More @ https://en.cppreference.com/w/cpp/algorithm/reverse
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::reverse(numbers.begin(), numbers.end());

    std::cout << "reverse               ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
}

void stable_foo_algorithms(){

    std::vector<std::string> animals_sort = {"elephant", "mouse", "rat", "pig", "dog", "cat", "ant", "moth"};
    std::vector<std::string> animals_stable_sort = {"elephant", "mouse", "rat", "pig", "dog", "cat", "ant", "moth"};

    // sorts container with given predicate, physical order is not guaranteed in case of equal elements
    // More @ https://en.cppreference.com/w/cpp/algorithm/sort
    std::sort(animals_sort.begin(), animals_sort.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "sort                  ";  
    for(auto& i : animals_sort)    std::cout << i << " ";    
    std::cout << std::endl;

    // sorts container with given predicate, physical order is not guaranteed in case of equal elements
    // More @ https://en.cppreference.com/w/cpp/algorithm/stable_sort
    std::stable_sort(animals_stable_sort.begin(), animals_stable_sort.end(), [](const auto& a, const auto& b) { return a.size () < b.size (); });
    std::cout << "stable_sort           ";  
    for(auto& i : animals_stable_sort)    std::cout << i << " ";    
    std::cout << std::endl;

    // Explanation: predicate on sorting is length of string. In this case, "rat", "pig", "dog", "cat" and "ant" all have same length
    // Since they are same length, second condition on sorting will be the physical order. In stable_sort is it guarranteed.  
}

void is_foo_algorithms(){
    std::vector<int> numbers = {1, 3, 5, 7, 2, 4, 6, 8, 9, 10};

    // is_sorted - checks if container is sorted or not 
    // More @ https://en.cppreference.com/w/cpp/algorithm/is_sorted
    bool is_sorted =  std::is_sorted(numbers.begin(), numbers.end()); 
    std::cout << "Is sorted?                " << is_sorted << std::endl;

    std::sort(numbers.begin(), numbers.end());
    is_sorted = std::is_sorted(numbers.begin(), numbers.end());
    std::cout << "Is sorted?                " << is_sorted << std::endl;

    // is_heap - checks if container is a heap (BFS of Heap)
    // More @ https://en.cppreference.com/w/cpp/algorithm/is_heap
    bool is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap?                  " << is_heap << std::endl;

    std::make_heap(numbers.begin(), numbers.end());
    is_heap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is heap?                  " << is_heap << std::endl;

    // is_partitioned - returns true if all elements satisfy the predicate
    // More @ https://en.cppreference.com/w/cpp/algorithm/is_partitioned
    bool is_partitioned = std::is_partitioned(numbers.begin(), numbers.end(), [](int i){    return i > 0;   });
    std::cout << "Predicate: is positive?   " << is_partitioned << std::endl;
}

void is_foo_until_algorithms(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Current State     ";
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;  

    // is_sorted_until
    // More @ https://en.cppreference.com/w/cpp/algorithm/is_sorted_until
    auto sorted = std::is_sorted_until(numbers.begin(), numbers.end());
    if(sorted != numbers.end()) std::cout << "Is sorted until " << *sorted << std::endl;
    else                        std::cout << "Is sorted until the end" << std::endl;

    // is_heap_until
    // More @ https://en.cppreference.com/w/cpp/algorithm/is_heap_until
    auto heap = std::is_heap_until(numbers.begin(), numbers.end());
    if(heap != numbers.end())   std::cout << "Is heap until " << *heap << std::endl;
    else                        std::cout << "Is heap until the end" << std::endl;
}

void querying_algorithms(){

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
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
    // auto reduce = std::reduce(std::execution::par, numbers.begin(), numbers.end());
    // std::cout << "reduce        " << reduce << std::endl;

    // transform_reduce

    // partial_sum
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
    
    std::partial_sum(numbers.begin(), numbers.end(), numbers.begin());

    std::cout << "partial_sum         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // inclusive_scan
    // std::inclusive_scan(numbers.begin(), numbers.end(), numbers.begin());
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

    // equal
    // More at 
    std::string word = "radar";
    if(std::equal(word.begin(), word.begin() + word.size()/2, word.rbegin()))
        std::cout << word << " is palindrome" << std::endl;
    else
        std::cout << word << " is not palindrome" << std::endl;

    // is_permutation
    std::string word_one = "apple", word_two = "paple";
    if(std::is_permutation(word_one.begin(), word_one.end(), word_two.begin()))
        std::cout << word_one << " is permutation of " << word_two << std::endl;
    else
        std::cout << word_one << " is not permutation of " << word_two << std::endl;

    // lexicographical_compare
    if(std::lexicographical_compare(word_one.begin(), word_one.end(), word_two.begin(), word_two.end()))
        std::cout << word_one << " is lexicographically less than " << word_two << std::endl;
    else
        std::cout << word_one << " is lexicographically more than " << word_two << std::endl;

    // mismatch
    std::vector<int> numbers_one = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> numbers_two = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    
    auto mismatch = std::mismatch(numbers_one.begin(), numbers_one.end(), numbers_two.begin());
    std::cout << "mismatch at " << *mismatch.first << " of first and " << *mismatch.second << " of second" << std::endl;

    // find 
    // More at 
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    int find_number = 5;
    if(std::find(numbers.begin(), numbers.end(), find_number) != numbers.end())
        std::cout << "Found " << find_number << std::endl;
    else
        std::cout << "Could't find " << find_number << std::endl; 

    std::sort(numbers.begin(), numbers.end());

    // adjacent_find
    auto adj_it = std::adjacent_find(numbers.begin(), numbers.end());
    if(adj_it != numbers.end())
        std::cout << "Found adjacent " << *adj_it << "\'s in collection" << std::endl;
    else
        std::cout << "Couldn't find adjacent elements in collection" << std::endl;

    // equal_range
    numbers = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9};
    find_number = 5;
    auto equal_range = std::equal_range(numbers.begin(), numbers.end(), find_number);
    std::cout << "First element of equal_range " << *equal_range.first << ", last element of equal range " << *equal_range.second << std::endl;

    // lower_bound
    auto lower_bound = std::lower_bound(numbers.begin(), numbers.end(), find_number);
    std::cout << "Lower bound on finding " << find_number << " is " << *lower_bound << std::endl;

    // upper_bound
    auto upper_bound = std::upper_bound(numbers.begin(), numbers.end(), find_number);
    std::cout << "Upper bound on finding " << find_number << " is " << *upper_bound << std::endl;

    // binary_search
    if(std::binary_search(numbers.begin(), numbers.end(), find_number))
        std::cout << find_number << " is in the container" << std::endl;
    else
        std::cout << find_number << " is not in the container" << std::endl;

    // search 

    // find_end

    // find_first_of

    // max_element - returns pointer to max element of the container
    auto max_element = std::max_element(numbers.begin(), numbers.end());
    std::cout << "max_element " << *max_element << std::endl;

    // min_element - returns pointer to min element of the container
    auto min_element = std::min_element(numbers.begin(), numbers.end());
    std::cout << "min_element " << *min_element << std::endl;

    // minmax_element - returns a pair of pointers to min and max elements
    auto minmax_element = std::minmax_element(numbers.begin(), numbers.end());
    std::cout << "min_element " << *minmax_element.first << " max_element " << *minmax_element.second << std::endl;

}

void set_algorithms(){

    std::set<int> s1 {1, 2, 5, 5, 5, 9};
    std::set<int> s2 {2, 5, 7};
    std::set<int> sdiff;
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sdiff, sdiff.begin()));

    std::cout << "Set difference is             ";
    for(auto& i : sdiff)    std::cout << i << " ";
    std::cout << std::endl;

    // Note that sorted vector (or any other container) is also considered a set
    // More @ https://en.cppreference.com/w/cpp/algorithm/set_difference
    std::vector<int> v1 {1, 2, 5, 5, 5, 9};
    std::vector<int> v2 {2, 5, 7};
    std::vector<int> vdiff;
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::inserter(vdiff, vdiff.begin()));

    std::cout << "Set (vector) difference is    ";
    for(auto& i : sdiff)    std::cout << i << " ";
    std::cout << std::endl;

    // set_intersection
    // More @ https://en.cppreference.com/w/cpp/algorithm/set_intersection
    std::set<int> sinter;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sinter, sinter.begin()));

    std::cout << "Set intersection is           ";
    for(auto& i : sinter)    std::cout << i << " ";
    std::cout << std::endl;    
    
    // set_union
    // More @ https://en.cppreference.com/w/cpp/algorithm/set_union
    std::set<int> sunion;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(sunion, sunion.begin()));

    std::cout << "Set union is                  ";
    for(auto& i : sunion)    std::cout << i << " ";
    std::cout << std::endl;    

    // set_symmetric_difference
    // More @ https://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference
    std::set<int> ssymdiff;
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(ssymdiff, ssymdiff.begin()));

    std::cout << "Set symmetric difference is   ";
    for(auto& i : ssymdiff)    std::cout << i << " ";
    std::cout << std::endl;  

    // includes 
    // More @ https://en.cppreference.com/w/cpp/algorithm/includes
    bool includes = std::includes(s1.begin(), s1.end(), s2.begin(), s2.end());
    std::cout << "s1 includes s2?               " << includes << std::endl;

    // merge
    // More @ https://en.cppreference.com/w/cpp/algorithm/merge
    std::set<int> dst;
    std::merge(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(dst, dst.end()));

    std::cout << "Content of dst                ";  
    for(auto& i : dst)    std::cout << i << " ";    
    std::cout << std::endl;
}

void movers_algorithms(){

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Content of numbers                    ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // copy (a.k.a. deep copy)
    // More @ https://en.cppreference.com/w/cpp/algorithm/copy
    std::vector<int> cpy;
    std::copy(numbers.begin(), numbers.end(), std::back_inserter(cpy));

    std::cout << "Content of cpy                        ";  
    for(auto& i : cpy)    std::cout << i << " ";    
    std::cout << std::endl;

    // move
    // More @ https://en.cppreference.com/w/cpp/algorithm/move
    std::vector<int> mv;
    std::move(numbers.begin(), numbers.end(), std::back_inserter(mv));

    std::cout << "Content of mv                         ";  
    for(auto& i : mv)    std::cout << i << " ";    
    std::cout << std::endl;

    // swap_ranges
    // More @ https://en.cppreference.com/w/cpp/algorithm/swap_ranges

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::cout << "Content of v1                         ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    std::cout << "Content of v2                         ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;

    std::swap_ranges(v1.begin(), v1.end(), v2.begin());

    std::cout << "Content of v1 after swap              ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    std::cout << "Content of v2 after swap              ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;

    // copy_backward
    // More @ https://en.cppreference.com/w/cpp/algorithm/copy_backward

    std::copy_backward(v1.begin(), v1.begin() + 1, v1.end());

    std::cout << "Content of s2 after copy_backward     ";  
    for(auto& i : v1)    std::cout << i << " ";    
    std::cout << std::endl;

    // move_backward
    // More @ https://en.cppreference.com/w/cpp/algorithm/move_backward

    std::move_backward(v2.begin(), v2.begin() + 1, v2.end());

    std::cout << "Content of s2 after move_backward     ";  
    for(auto& i : v2)    std::cout << i << " ";    
    std::cout << std::endl;
}

void value_modifiers_algorithms(){

    // fill 
    // More @ https://en.cppreference.com/w/cpp/algorithm/fill
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::fill(numbers.begin(), numbers.end(), -1);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // generate
    // More @ https://en.cppreference.com/w/cpp/algorithm/generate
    std::generate(numbers.begin(), numbers.end(), [n = 0] () mutable { return n++; });

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // iota
    // More @ https://en.cppreference.com/w/cpp/algorithm/iota
    std::iota(numbers.begin(), numbers.end(), 42);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    // replace
    // More @ https://en.cppreference.com/w/cpp/algorithm/replace
    std::replace(numbers.begin(), numbers.end(), 42, 43);

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;
}

void structure_changers_algorithms(){
    // std::remove(begin(collection), end(collection), 99);
    // More @ https://en.cppreference.com/w/cpp/algorithm/remove

    // collection.erase(std::remove(begin(collection), end(collection), 99), end(collection));


    // std::unique(begin(collection)), end(collection));
    // More @ 

    // collection.erase(std::remove(begin(collection), end(collection), 99), end(collection));

}

void foo_copy_algorithms(){
    // std::remove_copy: removes 'value' and copies elements to destination
    // More @ https://en.cppreference.com/w/cpp/algorithm/remove_copy
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;

    std::vector<int> cpy;
    std::remove_copy(numbers.begin(), numbers.end(), std::back_inserter(cpy), 5);

    std::cout << "Current State         ";  
    for(auto& i : cpy)    std::cout << i << " ";    
    std::cout << std::endl;

    // std::unique_copy
    // More @ 

    // std::reverse_copy
    // More @ 

    // std::rotate_copy
    // More @ 

    // std::replace_copy
    // More @ 

    // std::partition_copy
    // More @ 

    // std::partial_sort_copy
    // More @ 
}

void foo_if_algorithms(){
    std::vector<int> numbers = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    // std::find_if
    // More @ 
    std::vector<int>::iterator it = std::find_if (numbers.begin(), numbers.end(), [](int n){    return n % 7 == 0;});
    std::cout << "Found number " << *it << std::endl;

    // std::find_if_not
    // More @ 
    it = std::find_if_not (numbers.begin(), numbers.end(), [](int n){    return n % 2 == 0;});
    std::cout << "Found number " << *it << std::endl;

    // std::count_if
    // More @ 
    int divisible_by_three = std::count_if(numbers.begin(), numbers.end(), [](int i){return i % 3 == 0;});
    std::cout << "Number of entries divisible by three " << divisible_by_three << std::endl;

    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl; 

    // std::remove_if
    // More @ https://en.cppreference.com/w/cpp/algorithm/remove
    // Important: note that remove_if returns pointer to first elements that satisfy the predicate,
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int n){ return n % 7 == 0;}));
    
    std::cout << "Current State         ";  
    for(auto& i : numbers)    std::cout << i << " ";    
    std::cout << std::endl;    

    // std::remove_copy_if
    // More @ 

    // std::replace_if
    // More @ 

    // std::replace_copy_if
    // More @ 

    // std::copy_if
    // More @ 
}

void other_algorithms(){

    std::vector<int> numbers = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // std::transform() 
    // More @ 
    std::vector<int> numbers_two(numbers.size());
    std::transform (numbers.begin(), numbers.end(), numbers_two.begin(), [](int i){ return i + 10;});

    std::cout << "Current State         ";  
    for(auto& i : numbers_two)    std::cout << i << " ";    
    std::cout << std::endl; 

    // second overload of std::transform
    std::transform (numbers.begin(), numbers.end(), numbers_two.begin(), numbers.begin(), std::plus<int>());

    std::cout << "Current State         ";  
    for(auto& i : numbers_two)    std::cout << i << " ";    
    std::cout << std::endl; 

    // std::for_each(begin(collection), end(collection), f)
}

void raw_memory_algorithms(){
    // std::uninitialized_fill
    // More @ 

    // std::uninitialized_copy
    // More @ 

    // std::uninitialized_move
    // More @ 

    // std::destroy(first, last)
    // More @ 

    // #_n
    
    // std::copy_n
    // std::fill_n
    // std::generate_n
    // std::search_n
    // std::for_each_n
    // std::uninitialized_copy_n
    // std::uninitialized_fill_n
    // std::uninitialized_move_n
    // std::uninitialized_default_construct_n
    // std::uninitialized_value_construct_n
    // std::destroy_n
}

int main(){
    // heap_algorithms();
    // sorting_algorithms();
    // partition_algorithms();
    // permutation_algorithms();
    // stable_foo_algorithms();
    // is_foo_algorithms();
    // is_foo_until_algorithms();
    // querying_algorithms();
    // set_algorithms();
    // movers_algorithms();
    // value_modifiers_algorithms();
    // structure_changers_algorithms();
    // foo_copy_algorithms();
    // foo_if_algorithms();
    // other_algorithms();
    // raw_memory_algorithms();
    return 0;
}