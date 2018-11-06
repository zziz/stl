#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>

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
    std::cout << "rotate                ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    std::cout << "rotate                ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // shuffle - shuffle elements (values of elements) in container
    // More @ https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(0));
    std::cout << "shuffle               ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // next_permutation - get next permutation of container
    // More @ https://en.cppreference.com/w/cpp/algorithm/next_permutation
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::next_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // prev_permutation - get previous permutation
    // More @ https://en.cppreference.com/w/cpp/algorithm/prev_permutation
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::prev_permutation(numbers.begin(), numbers.end());
    std::cout << "next_permutation      ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;

    // reverse - reverse the container
    // More @ https://en.cppreference.com/w/cpp/algorithm/reverse
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "reverse               ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
}

void stable_foo_algorithms(){

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
}

void is_foo_algorithms(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
}

void is_foo_until_algorithms(){
    // is_sorted_until
    // is_heap_until
    // is_partitioned_until
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
    std::cout << "Current State         ";  for(auto& i : numbers)    std::cout << i << " ";    std::cout << std::endl;
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

    //  SEARCHING A VALUE IN SORTED CONTAINER
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

    // max_element

    // min_element

    // minmax_element

}

void set_algorithms(){
    // set_difference

    // set_intersection

    // set_union

    // set_symmetric_difference

    // includes

    // merge
}

void movers_algorithms(){
    // copy
    // std::copy(first, last, out);

    // move
    // std::move(first, last, out);

    // swap_ranges
    // std::swap_ranges

    // copy_backward
    // std::copy_backward

    // move_backward
    // std::move_backward
}

void value_modifiers_algorithms(){
    // fill 
    // generate

    // std::generate(first, last, )
    // iota
    // std::iota(first, last, 42);

    // std::replace(first, last, 42, 43);
}

void structure_changers_algorithms(){
    // std::remove(begin(collection), end(collection), 99);
    // collection.erase(std::remove(begin(collection), end(collection), 99), end(collection));
    // std::unique(begin(collection)), end(collection));
    // collection.erase(std::remove(begin(collection), end(collection), 99), end(collection));

}

void foo_copy_algorithms(){
    // std::remove_copy
    // std::unique_copy
    // std::reverse_copy
    // std::rotate_copy
    // std::replace_copy
    // std::partition_copy
    // std::partial_sort_copy
}

void foo_if_algorithms(){
    // std::find_if
    // std::find_if_not
    // std::count_if
    // std::remove_if
    // std::remove_copy_if
    // std::replace_if
    // std::replace_copy_if
    // std::copy_if
}

void other_algorithms(){
    // std::transform() // has 2 overloads
    // std::for_each(begin(collection), end(collection), f)
}

void raw_memory_algorithms(){
    // std::uninitialized_fill
    // std::uninitialized_copy
    // std::uninitialized_move
    // std::destroy(first, last)

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
    permutation_algorithms();
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