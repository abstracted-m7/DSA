# Searching - Data Structures & Algorithms

## 🔍 Overview
This folder contains implementations of various searching algorithms and their applications in different data structures.

## 📁 Folder Structure
```
Searching/
├── Linear-Search/
│   ├── basic-linear-search.py
│   ├── linear-search-variations.py
│   └── problems/
├── Binary-Search/
│   ├── iterative-binary-search.py
│   ├── recursive-binary-search.py
│   ├── binary-search-variations.py
│   └── problems/
├── Advanced-Search/
│   ├── ternary-search.py
│   ├── exponential-search.py
│   ├── interpolation-search.py
│   └── fibonacci-search.py
├── Data-Structure-Specific/
│   ├── tree-search.py
│   ├── graph-search.py
│   └── hash-search.py
├── String-Search/
│   ├── naive-string-search.py
│   ├── kmp-algorithm.py
│   ├── rabin-karp.py
│   └── boyer-moore.py
├── Interview-Problems/
└── Notes/
```

## 🎯 Searching Algorithms Implemented

### Basic Searching
- **Linear Search**: Sequential search through elements
- **Sentinel Linear Search**: Optimized linear search
- **Binary Search**: Divide and conquer on sorted arrays
- **Recursive Binary Search**: Recursive implementation

### Advanced Searching
- **Ternary Search**: Divide array into three parts
- **Exponential Search**: Find range then binary search
- **Interpolation Search**: Position-based search
- **Fibonacci Search**: Using Fibonacci numbers
- **Jump Search**: Block-based searching

### String Searching
- **Naive Pattern Search**: Brute force approach
- **KMP (Knuth-Morris-Pratt)**: Efficient pattern matching
- **Rabin-Karp**: Hash-based pattern search
- **Boyer-Moore**: Backward pattern matching
- **Z Algorithm**: Linear time pattern matching

### Data Structure Specific
- **BST Search**: Binary search tree traversal
- **Trie Search**: Prefix-based searching
- **Hash Table Search**: Constant time average case
- **Graph Search**: BFS/DFS for pathfinding

## ⏰ Time Complexities

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| **Linear Search** | O(1) | O(n) | O(n) | O(1) |
| **Binary Search** | O(1) | O(log n) | O(log n) | O(1) |
| **Ternary Search** | O(1) | O(log₃ n) | O(log₃ n) | O(1) |
| **Exponential Search** | O(1) | O(log n) | O(log n) | O(1) |
| **Interpolation Search** | O(1) | O(log log n) | O(n) | O(1) |
| **Jump Search** | O(1) | O(√n) | O(√n) | O(1) |
| **Fibonacci Search** | O(1) | O(log n) | O(log n) | O(1) |

## 🔧 Key Concepts & Techniques

### Prerequisites for Different Searches
- **Linear Search**: No prerequisites
- **Binary Search**: Sorted array/list
- **Interpolation Search**: Sorted + uniformly distributed data
- **Hash Search**: Good hash function

### Problem-Solving Patterns
- **Two Pointers**: Binary search variations
- **Divide & Conquer**: Binary, ternary search
- **Sliding Window**: String pattern matching
- **Prefix Functions**: KMP algorithm

## 🎯 Problem Categories

### Basic Search Problems
- Find element in array
- First and last occurrence
- Count occurrences
- Find missing number

### Binary Search Applications
- Search in rotated sorted array
- Find peak element
- Search in 2D matrix
- Find square root
- Find minimum in rotated array

### String Search Problems
- Pattern matching in text
- Find all occurrences
- Longest common substring
- String matching with wildcards

### Advanced Applications
- Search in infinite array
- Find element in bitonic array
- Median of two sorted arrays
- K-th smallest element

## 🧠 Algorithm Selection Guide

### When to Use Each Algorithm

**Linear Search**
- Unsorted data
- Small datasets
- Simple implementation needed

**Binary Search**
- Sorted data
- Large datasets
- O(log n) performance required

**Hash Search**
- Fast lookups needed
- Key-value pair storage
- Average O(1) performance

**String Search Algorithms**
- **Naive**: Small patterns, simple implementation
- **KMP**: Repeated patterns, preprocessing acceptable
- **Rabin-Karp**: Multiple pattern search
- **Boyer-Moore**: Large alphabets, long patterns

## 💡 Implementation Tips

### Binary Search Best Practices
```python
# Template for binary search
left, right = 0, len(arr) - 1
while left <= right:
    mid = left + (right - left) // 2  # Avoid overflow
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        left = mid + 1
    else:
        right = mid - 1
return -1
```

### Common Pitfalls
- **Integer Overflow**: Use `left + (right - left) // 2`
- **Infinite Loops**: Ensure proper boundary updates
- **Off-by-One Errors**: Check loop conditions carefully
- **Sorted Array Assumption**: Verify data is sorted for binary search

## 🎨 Optimization Techniques

### Binary Search Optimizations
- **Lower Bound**: First occurrence of element
- **Upper Bound**: Last occurrence of element
- **Range Search**: Find all elements in range
- **Rotated Array**: Handle rotation point

### String Search Optimizations
- **Preprocessing**: Build failure function (KMP)
- **Skip Tables**: Boyer-Moore character skipping
- **Rolling Hash**: Rabin-Karp hash computation
- **Suffix Arrays**: Advanced string processing

## 🧪 Testing Strategies

### Edge Cases to Consider
- Empty arrays/strings
- Single element arrays
- Element not present
- Duplicate elements
- Boundary elements (first/last)

### Performance Testing
- Small vs large datasets
- Best vs worst case scenarios
- Memory usage analysis
- Comparison with built-in functions

## 🔗 Real-World Applications

### Database Systems
- Index searching
- Range queries
- Join operations

### Web Development
- Search functionality
- Auto-complete features
- Content filtering

### System Programming
- File system searches
- Memory management
- Process scheduling

### Data Analysis
- Statistical analysis
- Pattern recognition
- Data mining operations

## 📚 Common Interview Questions

### Easy Level
1. Linear search implementation
2. Binary search in sorted array
3. First/last occurrence of element
4. Search insert position

### Medium Level
1. Search in rotated sorted array
2. Find peak element
3. Search 2D matrix
4. Find minimum in rotated sorted array
5. Pattern matching algorithms

### Hard Level
1. Median of two sorted arrays
2. K-th smallest in sorted matrix
3. Advanced string matching
4. Search in infinite array

---
*Part of [abstracted-m7/DSA](https://github.com/abstracted-m7/DSA) repository*