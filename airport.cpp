/*AMIR HOSEIN NOURI 06 january 2025 for the DATA STRUCTURE --vesion 1.0.3 by it works with this formula
.
priority = emergency_code * 100 + 10 * (fuel +1) + time ;
*/
#include <iostream>
#include <iomanip> // just for setw ;
using namespace std;

struct Airplane {
    int serial;
    int priority;
    char status; // L for Landing, T for Takeoff
};

class calculate {
private:
    int airplane_serial;
    int fuel;
    int time;
    int emergency_code;

public:
    calculate(int fuel, int time, int emergency_code, int airplane_serial_input) {
        this->fuel = fuel;
        this->time = time;
        this->emergency_code = emergency_code;
        this->airplane_serial = airplane_serial_input;
    }

    int sum() {
        return ((fuel + 1) * 10) + time + (emergency_code * 100);
    }

    void display() {
        cout << "Airplane Serial: " << airplane_serial << endl;
        cout << "Fuel: " << fuel << ", Time: " << time << ", Emergency Code: " << emergency_code << endl;
    }

    int Priority() { return sum(); }
};

class MinHeap {
private:
    Airplane heap[100];  
    int size;

public:
    MinHeap() : size(0) {} //garanti for empty heap

    void insert(int priority, int serial, char status) {
        if (size < 100) {
            heap[size] = {serial, priority, status};
            size++;
            heapparent(size - 1);
        } else {
            cout << "Heap is full!" << endl;
        }
    }

    void heapchild(int i) {
        int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && heap[left].priority < heap[smallest].priority)
         smallest = left;
        
        if (right < size && heap[right].priority < heap[smallest].priority)
         smallest = right;
        
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapchild(smallest);
        }
    }

    void heapparent(int i) {
        int parent = (i - 1) / 2;//parent place
        if (i > 0 && heap[i].priority < heap[parent].priority) {//not zero,root have not parent 
            swap(heap[i], heap[parent]);
            heapparent(parent);
        }
    }

    int extract() {
        if (size == 0) return -1;  
        int minPriority = heap[0].priority;
        heap[0] = heap[size - 1];
        size--;
        heapchild(0);
        return minPriority;
    }

    void print() {
        if (size == 0) {
            cout << "No airplanes in the queue.\n";
            return;
        }

        cout << left << setw(15) << "Airplane No."
             << setw(15) << "Priority"
             << setw(15) << "Status"
             << endl;
        cout << string(45, '-') << endl;

        for (int i = 0; i < size; i++) {
            cout << left << setw(15) << heap[i].serial
                 << setw(15) << heap[i].priority
                 << setw(15) << (heap[i].status == 'L' ? "Landing" : "Takeoff")
                 << endl;
        }
        cout << string(45, '-') << endl;
    }
};

void display() {
    cout << "\n AIRPORT MENU :\n";
    cout << "1. ADD AIRPLANE \n";
    cout << "2. STATUS OF AIRPORT \n";
    cout << "3. ALLOW AIRPLANE TO LAND OR TAKEOFF \n";
    cout << "4. EXIT \n";
    cout << "enter your choice: ";
}

int main() {
    int choice;
    MinHeap heap;

    do {
        display();
        cin >> choice;

        switch (choice) {
        case 1: {
            int fuel, time, emergency_code, airplane_serial;
            char status;

            cout << "Enter the airplane serial (as an integer): ";
            cin >> airplane_serial;
            cout << "Enter the fuel (0 - 100): ";
            cin >> fuel;
            cout << "Enter the time of the flight (based on sec): ";
            cin >> time;
            cout << "Enter the emergency code (1-3 => one means the most emergency): ";
            cin >> emergency_code;
            cout << "Enter the airplane status (L for Landing, T for Takeoff): ";
            cin >> status;

            calculate plane(fuel, time, emergency_code, airplane_serial);
            int priority = plane.Priority();
            heap.insert(priority, airplane_serial, status);
            cout << "Airplane added with priority " << priority << "\n";
            break;
        }
        case 2: {
            cout << "\n Airport Status:\n";
            heap.print();
            break;
        }
        case 3: {
            int minPriority = heap.extract();
            if (minPriority != -1) {
                cout << "Airplane with priority " << minPriority << " has been given permission to land or take off and removed from the queue.\n";
            } else {
                cout << "No airplanes in the queue.\n";
            }
            break;
        }
        case 4:
            cout << "GOOD BYE.\n";
            break;

        default:
            cout << "Error in choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}