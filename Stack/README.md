# Stack - Data Structures & Algorithms

## 📚 Overview
This folder contains comprehensive implementations of stack data structure using different approaches and various stack-based problem solutions following the LIFO (Last In, First Out) principle.

## 🏗️ Stack Implementations

### 1. Array-Based Stack
- **Fixed Size**: Static array implementation
- **Dynamic Size**: Resizable array implementation
- **Advantages**: Fast access, cache-friendly
- **Disadvantages**: Fixed size (static), memory waste

### 2. Linked List Stack
- **Dynamic Size**: No size limitations
- **Memory Efficient**: Allocates as needed
- **Advantages**: Dynamic sizing, memory efficient
- **Disadvantages**: Extra memory for pointers

### 3. Stack Using Queues
- **Two Queue Method**: Using two queues
- **One Queue Method**: Optimized approach
- **Educational**: Understanding data structure relationships

## 🛠️ Basic Operations

### Core Operations
| Operation | Description | Time Complexity |
|-----------|-------------|----------------|
| **Push** | Insert element at top | O(1) |
| **Pop** | Remove top element | O(1) |
| **Peek/Top** | View top element | O(1) |
| **isEmpty** | Check if stack is empty | O(1) |
| **Size** | Get number of elements | O(1) |

### Additional Operations
- **Display**: Print all stack elements
- **Search**: Find element in stack
- **Clear**: Empty the entire stack
- **Clone**: Create a copy of stack

## 🎯 Major Applications

### 1. Expression Evaluation
- **Infix to Postfix**: Convert mathematical expressions
- **Infix to Prefix**: Convert to prefix notation
- **Postfix Evaluation**: Evaluate postfix expressions
- **Prefix Evaluation**: Evaluate prefix expressions

### 2. Parentheses Matching
- **Balanced Parentheses**: Check if brackets are balanced
- **Valid Expressions**: Validate mathematical expressions
- **Multiple Bracket Types**: Handle (), [], {}
- **Nested Structures**: Complex bracket combinations

### 3. Function Call Management
- **Call Stack**: Function invocation tracking
- **Recursion**: Managing recursive function calls
- **Local Variables**: Scope management
- **Return Addresses**: Program flow control

### 4. Backtracking Algorithms
- **Maze Solving**: Path finding with backtracking
- **N-Queens Problem**: Chess queen placement
- **Sudoku Solver**: Puzzle solving
- **Graph Traversal**: DFS implementation

## 🧮 Problem Categories

### Basic Problems
- Implement stack using arrays
- Implement stack using linked lists
- Check for balanced parentheses
- Reverse a string using stack

### Intermediate Problems
- **Next Greater Element**: Find next larger element
- **Stock Span Problem**: Calculate stock price spans
- **Min Stack**: Stack with minimum element retrieval
- **Implement Queue using Stacks**: Two-stack queue

### Advanced Problems
- **Largest Rectangle in Histogram**: Maximum area calculation
- **Trapping Rain Water**: Using stack approach
- **Valid Parentheses**: Multiple bracket types
- **Decode String**: String manipulation with stacks
- **Asteroid Collision**: Simulation problems

### Expression Problems
- **Infix to Postfix Conversion**: Shunting yard algorithm
- **Evaluate Postfix Expression**: Stack-based evaluation
- **Evaluate Prefix Expression**: Reverse evaluation
- **Convert Infix to Prefix**: Expression transformation

## 💡 Key Algorithms & Techniques

### Stack-Based Algorithms
- **Monotonic Stack**: Maintaining order in stack
- **Two Pointer with Stack**: Hybrid approaches
- **Stack + HashMap**: Efficient lookups
- **Multiple Stacks**: Problem-specific implementations

### Design Patterns
- **Undo Operations**: Command pattern with stack
- **Browser History**: Navigation implementation
- **Calculator Design**: Expression evaluation
- **Compiler Design**: Syntax parsing

## ⏰ Complexity Analysis

### Time Complexities
| Implementation | Push | Pop | Peek | Space |
|----------------|------|-----|------|--------|
| **Array-based** | O(1)* | O(1) | O(1) | O(n) |
| **Linked List** | O(1) | O(1) | O(1) | O(n) |
| **Dynamic Array** | O(1) amortized | O(1) | O(1) | O(n) |

*O(n) for dynamic resizing in worst case

### Space Complexities
- **Array Implementation**: O(n) where n is maximum size
- **Linked List**: O(n) where n is current number of elements
- **Auxiliary Space**: O(1) for operations

## 🧪 Stack vs Other Data Structures

### Stack vs Queue
- **Stack**: LIFO principle, restricted access
- **Queue**: FIFO principle, both ends access
- **Use Cases**: Different problem requirements

### Stack vs Array
- **Stack**: Restricted operations, LIFO access
- **Array**: Random access, multiple operations
- **Performance**: Similar for stack operations

### Stack vs Linked List
- **Stack**: Specialized operations
- **Linked List**: General-purpose, flexible access

## 🎨 Implementation Best Practices

### Error Handling
```python
class Stack:
    def pop(self):
        if self.is_empty():
            raise Exception("Stack Underflow")
        return self.items.pop()
    
    def peek(self):
        if self.is_empty():
            raise Exception("Stack is Empty")
        return self.items[-1]
```

### Memory Management
- Check for stack overflow in fixed-size implementations
- Handle dynamic resizing efficiently
- Proper cleanup in linked list implementations

### Thread Safety
- Consider synchronization for concurrent access
- Implement lock mechanisms when needed
- Handle race conditions properly

## 🔍 Common Patterns & Tricks

### Monotonic Stack Pattern
- Used in "Next Greater Element" problems
- Maintains increasing/decreasing order
- Efficient O(n) solutions for many problems

### Two Stack Technique
- Implement queue using two stacks
- Min stack implementation
- Undo/redo operations

### Stack + Hash Map
- O(1) lookup with stack ordering
- Frequency counting with ordering
- Cache implementations

## 🧪 Testing Strategies

### Edge Cases
- Empty stack operations
- Single element stack
- Full stack (array implementation)
- Large dataset performance

### Test Scenarios
- **Functional Testing**: All operations work correctly
- **Boundary Testing**: Edge cases handled
- **Performance Testing**: Large data efficiency
- **Memory Testing**: No memory leaks

## 🔗 Real-World Applications

### Software Development
- **Call Stack**: Function execution tracking
- **Undo/Redo**: Text editors, graphics software
- **Expression Parsing**: Compilers, calculators
- **Memory Management**: Stack frame allocation

### System Programming
- **Process Stack**: Operating system management
- **Interrupt Handling**: System call management
- **Compiler Design**: Syntax analysis
- **Runtime Systems**: Memory allocation

### Web Development
- **Browser History**: Navigation stack
- **JavaScript Call Stack**: Function execution
- **Template Parsing**: HTML/XML processing
- **State Management**: Application state

## 📚 Common Interview Questions

### Easy Level
1. Implement stack using arrays
2. Check for balanced parentheses
3. Reverse string using stack
4. Implement stack using linked list

### Medium Level
1. Min stack implementation
2. Next greater element
3. Valid parentheses (multiple types)
4. Implement queue using stacks
5. Stock span problem

### Hard Level
1. Largest rectangle in histogram
2. Trapping rainwater using stack
3. Expression evaluation (infix/postfix)
4. Decode string with nested patterns
5. Design a stack with getMin() in O(1)

## 💫 Advanced Topics
- **Multi-Stack**: Multiple stacks in single array
- **Stack Machine**: Virtual machine implementation
- **Threaded Stack**: Concurrent stack operations
- **Persistent Stack**: Immutable stack versions

---
*Part of [abstracted-m7/DSA](https://github.com/abstracted-m7/DSA) repository*
