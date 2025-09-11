# Array - Data Structures & Algorithms

## 📊 Overview
This folder contains comprehensive implementations of array operations, algorithms, and problem-solving techniques. Arrays are the fundamental data structure with elements stored in contiguous memory locations.

## 🏗️ Array Types & Implementations

### 1. Static Arrays
- **Fixed Size**: Size determined at compile time
- **Memory**: Contiguous memory allocation
- **Access**: O(1) random access by index
- **Languages**: C, C++ static arrays

### 2. Dynamic Arrays
- **Resizable**: Size can change during runtime
- **Implementation**: ArrayList (Java), vector (C++), list (Python)
- **Growth Strategy**: Usually doubles when capacity exceeded
- **Examples**: Python lists, Java ArrayList, C++ vector

### 3. Multi-dimensional Arrays
- **2D Arrays**: Matrix representation
- **3D Arrays**: Tensor/cube structures
- **Storage**: Row-major vs Column-major order
- **Applications**: Image processing, game boards, mathematical computations

## 🛠️ Basic Operations

### Core Operations
| Operation | Description | Time Complexity | Space Complexity |
|-----------|-------------|----------------|------------------|
| **Access** | Get element by index | O(1) | O(1) |
| **Search** | Find element in array | O(n) | O(1) |
| **Insert** | Add element at position | O(n) | O(1) |
| **Delete** | Remove element from position | O(n) | O(1) |
| **Update** | Modify element at index | O(1) | O(1) |
| **Traverse** | Visit all elements | O(n) | O(1) |

### Advanced Operations
- **Rotation**: Left/Right circular shifts
- **Reversal**: Reverse array elements
- **Merge**: Combine two sorted arrays
- **Partition**: Rearrange based on condition

## 🔍 Searching Algorithms

### Linear Search
- **Time**: O(n), **Space**: O(1)
- **Use Case**: Unsorted arrays, small datasets
- **Variants**: Sentinel search, recursive linear search

### Binary Search
- **Time**: O(log n), **Space**: O(1)
- **Prerequisite**: Sorted array
- **Variants**: Lower bound, upper bound, search in rotated array

### Ternary Search
- **Time**: O(log₃ n), **Space**: O(1)
- **Use Case**: Finding maximum/minimum in unimodal arrays

## 📈 Sorting Algorithms

### Elementary Sorts
- **Bubble Sort**: O(n²) - Simple but inefficient
- **Selection Sort**: O(n²) - Minimal swaps
- **Insertion Sort**: O(n²) - Good for small/nearly sorted arrays

### Efficient Sorts
- **Merge Sort**: O(n log n) - Stable, divide & conquer
- **Quick Sort**: O(n log n) average - In-place, cache-friendly
- **Heap Sort**: O(n log n) - In-place, consistent performance

### Specialized Sorts
- **Counting Sort**: O(n + k) - For limited range integers
- **Radix Sort**: O(d × n) - For fixed-width integers
- **Bucket Sort**: O(n) average - For uniformly distributed data

## 🎯 Problem-Solving Patterns

### Two Pointer Technique
- **Applications**: Two sum, three sum, pair problems
- **Approach**: Start/end pointers moving towards each other
- **Time**: Often reduces O(n²) to O(n)

```python
# Two Sum Example
def two_sum(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
```

### Sliding Window
- **Applications**: Maximum subarray, substring problems
- **Approach**: Maintain window of elements
- **Variants**: Fixed size, variable size windows

### Prefix Sum
- **Applications**: Range sum queries, subarray problems
- **Preprocessing**: O(n) to build prefix array
- **Query Time**: O(1) for range sums

## 🧮 Subarray Problems

### Maximum Subarray Sum (Kadane's Algorithm)
- **Problem**: Find contiguous subarray with maximum sum
- **Algorithm**: Dynamic programming approach
- **Time**: O(n), **Space**: O(1)

### Subarray with Given Sum
- **Problem**: Find subarray with specific sum
- **Approach**: Sliding window or prefix sum
- **Variants**: Positive numbers, negative numbers included

### Longest Subarray
- **Applications**: Longest increasing subsequence
- **Techniques**: DP, binary search optimization
- **Time**: O(n log n) optimized

## 🔲 Matrix Operations

### Basic Matrix Operations
- **Addition/Subtraction**: Element-wise operations
- **Multiplication**: Row × Column multiplication
- **Transpose**: Swap rows and columns
- **Determinant**: Square matrix property

### Matrix Traversal Patterns
- **Row-wise**: Standard left-to-right, top-to-bottom
- **Column-wise**: Top-to-bottom, left-to-right
- **Spiral**: Clockwise/counterclockwise spiral
- **Diagonal**: Main diagonal, anti-diagonal traversal

### Advanced Matrix Problems
- **Rotation**: 90°, 180°, 270° rotations
- **Search**: Search in row/column sorted matrix
- **Path Problems**: Minimum path sum, unique paths

## 💡 Advanced Array Problems

### Dutch National Flag Problem
- **Problem**: Sort array of 0s, 1s, and 2s
- **Algorithm**: Three-way partitioning
- **Time**: O(n), **Space**: O(1)

### Merge Intervals
- **Problem**: Merge overlapping intervals
- **Approach**: Sort + merge algorithm
- **Applications**: Calendar scheduling, range merging

### Stock Buy-Sell Problems
- **Variants**: Single transaction, multiple transactions, cooldown
- **Approach**: Dynamic programming, greedy algorithms
- **Applications**: Trading algorithms, profit optimization

### Trapping Rainwater
- **Problem**: Calculate trapped water between bars
- **Approaches**: Two pointers, stack-based, DP
- **Time**: O(n), **Space**: O(1) optimized

## 🚀 Optimization Techniques

### Space Optimization
- **In-place Operations**: Modify array without extra space
- **Constant Space**: O(1) space algorithms
- **Space-Time Tradeoffs**: Hash maps for faster lookups

### Time Optimization
- **Preprocessing**: Build auxiliary structures
- **Memoization**: Cache repeated computations
- **Early Termination**: Break loops when possible

### Cache Optimization
- **Locality of Reference**: Access nearby elements
- **Row-major Access**: Better cache performance
- **Block Processing**: Process data in chunks

## 🧪 Testing Strategies

### Edge Cases
- **Empty Arrays**: Handle zero-length arrays
- **Single Element**: Arrays with one element
- **Duplicate Elements**: Repeated values
- **Boundary Values**: First/last element operations

### Test Categories
- **Functional**: Correctness of operations
- **Performance**: Large dataset efficiency
- **Memory**: Space complexity verification
- **Boundary**: Edge case handling

## 🔗 Real-World Applications

### Systems Programming
- **Memory Management**: Buffer handling
- **File Systems**: Block allocation
- **Database Systems**: Record storage
- **Graphics**: Pixel arrays, image processing

### Data Processing
- **Signal Processing**: Audio/video data
- **Scientific Computing**: Numerical arrays
- **Machine Learning**: Feature vectors, datasets
- **Statistics**: Data analysis, sampling

### Web Development
- **Frontend**: DOM manipulation, data tables
- **Backend**: Request processing, caching
- **APIs**: JSON array handling
- **Databases**: Result set processing

## 📚 Common Interview Questions

### Easy Level
1. Find maximum/minimum element
2. Reverse an array
3. Linear search implementation
4. Check if array is sorted
5. Remove duplicates from sorted array

### Medium Level
1. Two Sum problem
2. Maximum subarray sum (Kadane's)
3. Rotate array by k positions
4. Find missing number
5. Merge two sorted arrays
6. Search in rotated sorted array

### Hard Level
1. Trapping rainwater
2. Median of two sorted arrays
3. Three sum problem
4. Longest increasing subsequence
5. Maximum rectangle in histogram
6. Dutch national flag problem

### Matrix Problems
1. Spiral matrix traversal
2. Rotate matrix 90 degrees
3. Search in 2D matrix
4. Set matrix zeros
5. Minimum path sum in grid

## 🎨 Best Practices

### Code Quality
- **Bounds Checking**: Prevent index out of bounds
- **Input Validation**: Check for null/empty arrays
- **Clear Naming**: Use descriptive variable names
- **Documentation**: Comment complex algorithms

### Performance
- **Algorithm Selection**: Choose appropriate algorithm for data size
- **Memory Usage**: Consider space-time tradeoffs
- **Early Optimization**: Profile before optimizing

### Maintainability
- **Modularity**: Break down complex operations
- **Reusability**: Create generic utility functions
- **Testing**: Write comprehensive test cases

---
*Part of [abstracted-m7/DSA](https://github.com/abstracted-m7/DSA) repository*
