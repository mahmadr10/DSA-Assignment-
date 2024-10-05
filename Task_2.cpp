
// Muhammad Ahmad
// 461348
// BSDS 1-A

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    uint64_t value; // Each node holds a 64-bit value
    Node* next;     

    Node(uint64_t val) : value(val), next(nullptr) {} // Constructor 
};

// LinkedList class 
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {} // Constructor

    // Function to append a new node
    void append(uint64_t val) {
        if (!head) {
            head = new Node(val); 
            return;
        }
        Node* current = head;
        while (current->next) { 
            current = current->next;
        }
        current->next = new Node(val); 
    }

    // Function to get the head of the linked list
    Node* getHead() const {
        return head;
    }

    // Destructor to clean up allocated memory for the linked list
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current; 
            current = next; 
        }
    }
};

// Function for modular exponentiation, used in primality testing
uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp >>= 1; 
        base = (base * base) % mod; 
    }
    return result;
}

// Function to check if the number represented by the linked list is prime
bool is_prime(LinkedList& list, int k = 5) {
    uint64_t n = 0; 
    Node* current = list.getHead();
    int shift = 0;

    // Reconstruct the full number from the linked list
    while (current) {
        n |= (current->value << shift); 
        shift += 64;
        current = current->next;
    }

    // Handle small numbers and check for evenness
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    // Decompose n-1 into d * 2^r
    uint64_t r = 0, d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Miller-Rabin primality test
    for (int i = 0; i < k; i++) {
        uint64_t a = 2 + rand() % (n - 4); // Random base
        uint64_t x = mod_exp(a, d, n); // a^d % n

        if (x == 1 || x == n - 1) continue; // Check if x is a trivial witness

        bool found = false;
        for (uint64_t j = 0; j < r - 1; j++) {
            x = (x * x) % n; 
            if (x == n - 1) {
                found = true; 
                break;
            }
        }
        if (!found) return false; // n is composite
    }
    return true; // n is prime
}

// Function to format the 1024-bit number from the linked list for output
string format_large_number(LinkedList& list) {
    string large_number = "";
    Node* current = list.getHead();
    while (current) {
        large_number = to_string(current->value) + large_number;
        current = current->next;
    }
    return large_number; 
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness

    LinkedList list;
    for (int i = 0; i < 16; ++i) {
        uint64_t random_value = rand() % UINT64_MAX; // Generating a random 64-bit value
        list.append(random_value); 
    }

    string large_number = format_large_number(list); //  linked list into a string
    cout << "Input: A random 1024-bit number is represented as:\n" << large_number << endl;

    bool prime_result = is_prime(list); // Checking if the generated number is prime
    cout << "Output: " << (prime_result ? "True (the number is prime)" : "False (the number is not prime)") << endl;

    return 0; 
}
