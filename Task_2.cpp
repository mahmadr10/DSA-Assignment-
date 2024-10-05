
// Muhammad Ahmad
// 461348
// BSDS 1-A

#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>
#include <stdexcept>

using namespace std;

class Node {
public:
    uint64_t data; // 64-bit integer
    Node* next;
    Node* prev;

    // Constructor to initialize node with 64-bit integer data
    Node(uint64_t data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

    // Constructor to initialize linked list from a string of large numbers
    LinkedList(string data) {
        this->head = NULL;
        this->tail = NULL;
        int n = data.size();
        int block_size = 19; // Each node will store a maximum of 19 digits 
        while (n > 0) {
            // Adding blocks of 19 digits
            string block = data.substr(max(0, n - block_size), block_size);
            prependNode(stoull(block)); // Converting string block to 64-bit number
            n -= block_size;
        }
    }

    // Function to prepend a new node with given 64-bit data at the head of the list
    void prependNode(uint64_t data) {
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

    // Function to print the linked list
    void printList() {
        Node* temp = this->head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Modular exponentiation function 
    uint64_t modExp(uint64_t base, uint64_t exp, uint64_t mod) {
        uint64_t result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }

    // Miller-Rabin primality test on each node 
    bool isPrime(uint64_t n, int iterations) {
        if (n < 2) return false;
        if (n != 2 && n % 2 == 0) return false;

        uint64_t s = n - 1;
        while (s % 2 == 0) s /= 2;

        for (int i = 0; i < iterations; i++) {
            uint64_t a = rand() % (n - 1) + 1;
            uint64_t temp = s;
            uint64_t mod = modExp(a, temp, n);
            while (temp != n - 1 && mod != 1 && mod != n - 1) {
                mod = (mod * mod) % n;
                temp *= 2;
            }
            if (mod != n - 1 && temp % 2 == 0) return false;
        }
        return true;
    }
};

int main() {
    string inputNumber;
    cout << "Enter a large number (max 309 digits): ";
    cin >> inputNumber;

    LinkedList list(inputNumber);
    list.printList();

    // Checking each node's value for primality
    Node* current = list.head;
    bool prime = true;
    while (current != NULL) {
        if (!list.isPrime(current->data, 5)) {
            prime = false;
            break;
        }
        current = current->next;
    }

    if (prime) {
        cout << "The large number is prime." << endl;
    } else {
        cout << "The large number is not prime." << endl;
    }

    return 0;
}

