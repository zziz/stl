# stl

### Heap Algorithms
```cpp
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
```

#### Output
```
make_heap     10 9 7 4 5 6 3 2 1 
push_heap     10 9 7 4 8 6 3 2 1 5 
pop_heap      9 8 7 4 5 6 3 2 1 10 
```

### Sorting Algorithms
```cpp
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
std::cout << "sort_heap     ";
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
std::cout << "inplace_merge         ";  
for(auto& i : numbers)    std::cout << i << " ";    
std::cout << std::endl;
```

#### Output
```
Current State     4 1 5 9 6 2 10 7 3 
sort              1 2 3 4 5 6 7 9 10 
Current State     4 1 5 9 6 2 10 7 3 
partial_sort      1 2 3 4 5 9 10 7 6 
Current State     4 1 5 7 9 2 6 10 3 
nth_element       3 1 2 4 5 6 7 10 9 
Current State     4 3 5 10 6 1 9 7 2 
sort_heap         1 2 3 4 5 6 7 9 10 
Current State     4 1 5 9 6 2 10 7 3 
Current State     1 4 5 6 9 2 10 7 3 
Current State     1 4 5 6 9 2 3 7 10 
inplace_merge     1 2 3 4 5 6 7 9 10 
```

### Partition Algorithms
```cpp
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
```

#### Output
```
Current State     1 2 3 4 5 6 7 9 10 
After partition   10 2 6 4 5 3 7 9 1 
Returned iterator 5
Partition pointer 5
```

### Permutation Algorithms
```cpp
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
```

#### Output
```
rotate                2 3 4 5 6 7 8 9 10 1 
rotate                3 4 5 6 7 8 9 10 1 2 
shuffle               5 10 4 9 1 3 7 2 8 6 
Current State         5 10 4 9 1 3 7 2 8 6 
next_permutation      5 10 4 9 1 3 7 6 2 8 
Current State         5 10 4 9 1 3 7 6 2 8 
next_permutation      5 10 4 9 1 3 7 2 8 6 
Current State         5 10 4 9 1 3 7 2 8 6 
reverse               6 8 2 7 3 1 9 4 10 5 
```

### stable_#### Algorithms
```cpp
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

```

#### Output
```
sort                  rat pig dog cat ant moth mouse elephant 
stable_sort           rat pig dog cat ant moth mouse elephant 
```

### is_#### Algorithms
```cpp
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
```

#### Output 
```
Is sorted?                0
Is sorted?                1
Is heap?                  0
Is heap?                  1
Predicate: is positive?   1
```