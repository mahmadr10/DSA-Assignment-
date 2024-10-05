
// Muhammad Ahmad
// 461348
// BSDS 1-A

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <stdexcept>

using namespace std;

class Node {
public:
    unsigned int data; 
    Node* next;
    Node* prev; 

    // Constructor to initialize node with integer data
    Node(unsigned int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Constructor to initialize node with string data
    Node(string data) {
        // Checking if the string represents a number too large for a 32-bit integer
        if (data.size() == 10) {
            if (data[0] >= '3') {
                throw invalid_argument("Number is too large to store in 32-bit unsigned integer");
            } else if (data[0] == '2') {
                if (data > "2147483647") {
                    throw invalid_argument("Number is too large to store in 32-bit unsigned integer");
                }
            }
        }
        // Convert string to integer and initialize node
        this->data = stoi(data);
        this->next = NULL;
        this->prev = NULL;
    }

    // Method to get the length of the integer stored in the node
    int getLengthofInt() {
        int temp = this->data;
        int count = 0;
        if (temp == 0) return 1; 
        while (temp > 0) {
            temp = temp / 10;
            count++;
        }
        return count;
    }

    // Method to print the node's data
    void printNode() {
        cout << this->data;
    }
};

class LinkedList {
public:
    Node* head; 
    Node* tail; 

    // Default constructor
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    // Constructor to initialize linked list from a string
    LinkedList(string data) {
        this->head = NULL;
        this->tail = NULL;
        int n = data.size();
        int block_size = 9; // Each node will store a maximum of 9 digits
        while (n > 0) {
            // Adding blocks of 9 characters
            this->prependNode(data.substr(max(0, n - block_size), block_size));
            n -= block_size;
        }
    }

    // Function to prepend a new node with given data at the head of the list
    void prependNode(string data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) { 
            this->head = newNode;
            this->tail = newNode;
        } else { 
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
    }

    // Function to print the entire linked list
    void printList() {
        Node* temp = this->head;
        while (temp != NULL) {
            temp->printNode();
            cout << " "; 
            temp = temp->next;
        }
        cout << endl; 
    }

    // Method to check if the number represented by the linked list is prime
    bool isPrime() {
        unsigned long long num = 0;
        Node* current = head;
        unsigned long long place = 1;

        // now I amm Converting the linked list to a number
        while (current != NULL) {
            num += current->data * place;
            place *= 1000000000; // Each node contains at most 9 digits
            current = current->next;
        }

        // Primality test
        if (num < 2) return false; 
        for (unsigned long long i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false; // not prime
        }
        return true; //  prime
    }
};

int main() {

    string inputNumber;
    cout << "Enter a large number (up to 30 digits): ";
    cin >> inputNumber;

    LinkedList list(inputNumber);
    list.printList();

    if (list.isPrime()) {
        cout << "The number is prime." << endl;
    } else {
        cout << "The number is not prime." << endl;
    }

    return 0;
}
