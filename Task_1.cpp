// Muhammad Ahmad
// 461348
// BSDS 1-A

#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int processId;
    int executionTime;
    int remainingTime;

    // Constructor 
    Node(int id, int execTime, int remTime) : processId(id), executionTime(execTime), remainingTime(remTime), next(NULL) {}
};

class CPU {
public:
    Node* head;

    CPU() : head(NULL) {} 

    // Function to add a new Node (process)
    Node* addNode(int id, int execTime, int remTime) {
        Node* newNode = new Node(id, execTime, remTime);

        if (head == NULL) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Here I am maintaining the circular nature of the linked list
        }

        return newNode;
    }

    // Function to delete a node
    Node* deleteNode(Node* nodeToDelete) {
        if (head == NULL) return NULL; 

        if (head->next == head && head == nodeToDelete) {  
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != nodeToDelete && temp->next != head) {  
                temp = temp->next;
            }
            temp->next = nodeToDelete->next;  
            if (nodeToDelete == head) {
                head = nodeToDelete->next;  // Updating head if the head is being deleted
            }
            delete nodeToDelete;
        }

        return head;
    }

    // Function to simulate CPU scheduling for 3 cycles and adding a new process during the run
    void schedule(int timeSlice, int numCycles) {
        Node* current = head;
        int cycle = 0;  // Cycle counter

        cout << "......Cycle begins......" << endl;
        do {
            cycle++;
            cout << "\nCycle " << cycle << ":" << endl;

            // Process each node in the cycle
            Node* temp = current;
            do {
                cout << "Process " << temp->processId << " is running." << endl;

                // Now I'm reducing the remaining time of the current process
                temp->remainingTime -= timeSlice;

                if (temp->remainingTime <= 0) {
                    cout << "Process " << temp->processId << " has completed." << endl;
                    Node* nextProcess = temp->next;
                    deleteNode(temp);
                    temp = nextProcess;  // Update current to the next process or head
                } else {
                    cout << "Process " << temp->processId << " remaining time is now: " << temp->remainingTime << endl;
                    temp = temp->next;
                }

                Display();

            } while (temp != current && head != NULL);  

            //  new process arrival in the second cycle
            if (cycle == 2) {
                cout << "New process arrives: Process 4 (Remaining Time: 9)" << endl;
                addNode(4, 9, 9);
                Display();
            }

            if (cycle == numCycles || head == NULL) { 
                cout << "......Maximum cycle limit reached or no processes remaining......" << endl;
                break;
            }

        } while (head != NULL);

        cout << "......Cycle ends......" << endl;
    }

    // Function to display the current process list
    void Display() {
        if (head == NULL) {
            cout << "No processes remaining." << endl;
            return; 
        }
        Node* temp = head;
        do {
            cout << "Process ID: " << temp->processId << ", Remaining Time: " << temp->remainingTime << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CPU cpu;
    cpu.addNode(1, 10, 10);
    cpu.addNode(2, 5, 5);
    cpu.addNode(3, 8, 8);

    cout << "Initial Processes:" << endl;
    cpu.Display();

    int timeSlice = 3;  
    int numCycles = 3;  
    cout << "\nCPU Time per Process per Cycle: " << timeSlice << "\n" << endl;
    cpu.schedule(timeSlice, numCycles);

    return 0;
}
