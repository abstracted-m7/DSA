# Linked List - Data Structures & Algorithms

## 🔗 Overview
This folder contains comprehensive implementations and practice problems for various types of linked lists and their operations.

## 📁 Folder Structure
```
Linked List/
├── Singly-Linked-List/
│   ├── implementation.py
│   ├── basic-operations.py
│   └── problems/
├── Doubly-Linked-List/
│   ├── implementation.py
│   ├── basic-operations.py
│   └── problems/
├── Circular-Linked-List/
│   ├── singly-circular.py
│   ├── doubly-circular.py
│   └── problems/
├── Advanced-Problems/
├── Interview-Questions/
└── Notes/
```

## 🏗️ Types of Linked Lists

### 1. Singly Linked List
- **Structure**: Node → Node → Node → NULL
- **Features**: Unidirectional traversal, single pointer per node
- **Use Cases**: Stack implementation, simple data storage

### 2. Doubly Linked List
- **Structure**: NULL ← Node ↔ Node ↔ Node → NULL
- **Features**: Bidirectional traversal, two pointers per node
- **Use Cases**: Browser history, undo/redo operations

### 3. Circular Linked List
- **Singly Circular**: Last node points to first node
- **Doubly Circular**: Bidirectional with circular connections
- **Use Cases**: Round-robin scheduling, music playlists

## 🛠️ Basic Operations Implemented

### Core Operations
- **Insertion**: Beginning, end, at position
- **Deletion**: By value, by position, entire list
- **Traversal**: Forward, backward (for doubly)
- **Search**: Linear search through nodes
- **Display**: Print all elements

### Advanced Operations
- **Reverse**: Iterative and recursive approaches
- **Merge**: Combine two sorted lists
- **Sort**: Various sorting algorithms
- **Cycle Detection**: Floyd's cycle detection algorithm
- **Find Middle**: Two-pointer technique

## 🎯 Problem Categories

### Basic Problems
- Insert/Delete at specific positions
- Find length of linked list
- Search for an element
- Display linked list

### Intermediate Problems
- Reverse a linked list
- Detect and remove cycles
- Find middle element
- Merge two sorted lists
- Remove duplicates

### Advanced Problems
- Clone list with random pointers
- Add two numbers represented as lists
- Flatten a multilevel linked list
- LRU Cache implementation
- Skip list implementation

## ⏰ Time & Space Complexities

| Operation | Singly LL | Doubly LL | Array |
|-----------|-----------|-----------|-------|
| **Access** | O(n) | O(n) | O(1) |
| **Search** | O(n) | O(n) | O(n) |
| **Insert (Beginning)** | O(1) | O(1) | O(n) |
| **Insert (End)** | O(n)* | O(1)** | O(1) |
| **Delete (Beginning)** | O(1) | O(1) | O(n) |
| **Delete (End)** | O(n) | O(1)** | O(1) |

*O(1) if tail pointer maintained  
**With head and tail pointers

## 💡 Key Algorithms & Techniques

### Two Pointer Technique
- Fast and slow pointers for cycle detection
- Finding middle element
- Checking palindrome

### Recursion
- Recursive traversal and operations
- Reverse using recursion
- Merge sort implementation

### Dummy Node Technique
- Simplifies edge cases in insertion/deletion
- Used in merge operations
- Helpful for complex manipulations

## 🔍 Common Interview Questions

### Easy Level
1. Reverse a singly linked list
2. Find the middle of a linked list
3. Detect if a linked list has a cycle
4. Remove duplicates from sorted list

### Medium Level
1. Add two numbers represented as linked lists
2. Remove nth node from end
3. Merge k sorted linked lists
4. Copy list with random pointer

### Hard Level
1. Reverse nodes in k-group
2. Merge sort on linked list
3. LRU Cache using doubly linked list
4. Skip list implementation

## 🧪 Testing Approach
- **Edge Cases**: Empty list, single node, cycles
- **Boundary Conditions**: First/last node operations
- **Memory Management**: Proper node deallocation
- **Performance Testing**: Large datasets

## 📚 Key Concepts to Master
- **Memory Management**: Dynamic allocation and deallocation
- **Pointer Manipulation**: Handling next/prev pointers
- **Edge Case Handling**: Null checks and boundary conditions
- **Space Optimization**: In-place operations when possible

## 🎨 Implementation Tips
- Always check for null pointers
- Use dummy nodes to simplify logic
- Keep track of previous node for deletions
- Consider using tail pointer for efficiency
- Practice both iterative and recursive solutions

## 🔗 Applications in Real World
- **Operating Systems**: Process scheduling, memory management
- **Databases**: Hash table collision handling
- **Web Browsers**: History navigation
- **Music Players**: Playlist management
- **Undo Operations**: Text editors, graphics software

---
*Part of [abstracted-m7/DSA](https://github.com/abstracted-m7/DSA) repository*