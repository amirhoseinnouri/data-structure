# Airport Management System

## Overview
The **Airport Management System** is a C++ project that efficiently manages airplane landings using a **Min-Heap Tree Algorithm**. The system prioritizes airplanes based on factors such as **fuel levels, landing time, and emergency codes**. This ensures that airplanes with urgent needs land first, optimizing the overall airport operations.

## Features
- **Min-Heap Tree Implementation**: Prioritizes airplane landing requests.
- **Airplane Queue Management**: Users can add airplanes based on priority.
- **Structured Airplane Data**: Includes details such as fuel levels, arrival time, and emergency codes.
- **Emergency Handling**: Airplanes with emergency codes get higher priority.
- **Efficient Landing System**: Ensures optimal use of airport resources.

## Technologies Used
- **C++**
- **Min-Heap Tree Algorithm**
- **Structs & Priority Queue**

## Installation
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/amirhoseinnouri/airport-management.git
   ```
2. **Navigate to the Project Folder**:
   ```sh
   cd airport-management
   ```
3. **Compile the Code**:
   ```sh
   g++ airport_management.cpp -o airport_management
   ```
4. **Run the Program**:
   ```sh
   ./airport_management
   ```

## Usage
1. **Add an Airplane**:
   - Enter airplane details (Fuel Level, Arrival Time, Emergency Code).
   - The system automatically places it in the correct priority order.
2. **Process Landings**:
   - The airplane with the highest priority (lowest fuel, highest emergency) lands first.
   - The Min-Heap is updated accordingly.
3. **View Pending Landings**:
   - Displays all airplanes waiting to land.
   
## Code Structure
```cpp
struct Airplane {
    int id;              // Unique airplane ID
    int fuel;            // Remaining fuel level
    int arrivalTime;     // Time of arrival
    int emergencyCode;   // Emergency status (higher value = higher priority)
};
```
- The Min-Heap stores `Airplane` structs and processes them based on priority.
- Lower fuel levels and higher emergency codes increase landing priority.

## Example Run
```sh
Welcome to Airport Management System
1. Add Airplane
2. Process Landing
3. View Queue
4. Exit
Choice: 1
Enter Airplane ID: 101
Enter Fuel Level: 20
Enter Arrival Time: 5
Enter Emergency Code (0-5): 3
Airplane added successfully!
```
---


A Min Heap is a type of binary heap data structure where the parent node always has a value less than or equal to the values of its child nodes. This ensures that the minimum value is always at the root.

Properties of a Min Heap
Complete Binary Tree:
A min heap is always a complete binary tree, meaning all levels are completely filled except possibly the last one, which is filled from left to right.
Heap Property (Min Heap Property):
Every parent node has a value less than or equal to its children:
𝐴
[
𝑝
𝑎
𝑟
𝑒
𝑛
𝑡
]
≤
𝐴
[
𝑙
𝑒
𝑓
𝑡
𝐶
ℎ
𝑖
𝑙
𝑑
]
and
𝐴
[
𝑝
𝑎
𝑟
𝑒
𝑛
𝑡
]
≤
𝐴
[
𝑟
𝑖
𝑔
ℎ
𝑡
𝐶
ℎ
𝑖
𝑙
𝑑
]
A[parent]≤A[leftChild]andA[parent]≤A[rightChild]
Operations on a Min Heap
Insertion (O(log n))

Insert the new element at the end of the tree.
Heapify up (or bubble up) to maintain the heap property by swapping with the parent if necessary.
Deletion (Extract Min) (O(log n))

The root (minimum element) is removed.
Replace the root with the last element.
Heapify down (or bubble down) to restore heap order.
Peek (Get Minimum) (O(1))

The minimum value is always at the root, so this operation is constant time.
Heapify (O(n))

Convert an unsorted array into a heap by applying heapify to each node from the bottom up.


---
## Future Improvements
- Implement a **Graphical User Interface (GUI)**.
- Add real-time **weather impact analysis**.
- Enhance **multi-airport coordination**.

## Contributing
Contributions are welcome! Feel free to submit **issues** or **pull requests**.

## License
This project is licensed under the **MIT License**.

## Contact
click [here](https://t.me/Nouri_AmirHosein) to contact me 

---
**Star this repository** ⭐ if you found this useful!

