// Muhammad Ahmad
// 461348
// BSDS 1-A

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

class Node {
public:
    string data; // Here I amm storing the chunk as a string
    Node* next;
    Node* prev;

    Node(string data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    LinkedList(string data) {
        this->head = NULL;
        this->tail = NULL;
        int n = data.size();
        int block_size = 19; // Each node will store a maximum of 19 digits 
        while (n > 0) {
            string block = data.substr(max(0, n - block_size), block_size);
            prependNode(block); 
            n -= block_size;
        }
    }

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

    // Concatenating chunks back into a single string
    string toString() {
        string result;
        Node* temp = this->tail; 
        while (temp != NULL) {
            result += temp->data;
            temp = temp->prev;
        }
        return result;
    }

    // Checking if a large number represented as a string is prime
    bool isPrimeString(const string& numStr) {
        if (numStr == "1" || numStr.empty()) return false;
        if (numStr == "2") return true;
        if ((numStr.back() - '0') % 2 == 0) return false; 

        // Checking divisibility by odd numbers up to the square root
        uint64_t sqrtNum = static_cast<uint64_t>(sqrt(stod(numStr)));
        for (uint64_t i = 3; i <= sqrtNum; i += 2) {
            if (isDivisible(numStr, to_string(i))) {
                return false;
            }
        }
        return true;
    }

    // Checking if numStr is divisible by divisorStr
    bool isDivisible(const string& numStr, const string& divisorStr) {
        // Using long division algorithm to check for divisibility
        uint64_t remainder = 0;
        for (char digit : numStr) {
            remainder = remainder * 10 + (digit - '0');
            remainder %= stoi(divisorStr);
        }
        return remainder == 0;
    }

    // Now I amm finding and displaying smaller prime numbers from the large number
    void findAndDisplaySmallPrimes(const string& largeNumber) {
        unordered_set<string> foundPrimes;
        int length = largeNumber.length();

        // Checking all substrings up to 19 digits long
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j <= length && j - i <= 19; ++j) {
                string sub = largeNumber.substr(i, j - i);
                if (sub[0] != '0' && foundPrimes.find(sub) == foundPrimes.end() && isPrimeString(sub)) {
                    cout << "Smaller prime number found in the large number: " << sub << endl;
                    foundPrimes.insert(sub);
                }
            }
        }
    }
};

int main() {
    string inputNumber;
    cout << "Enter a large number: ";
    cin >> inputNumber;

    LinkedList list(inputNumber);

    // Regenerating the entire number from the chunks
    string concatenatedNumber = list.toString();

    // Checking if the complete number is prime
    bool prime = list.isPrimeString(concatenatedNumber);

    if (prime) {
        cout << "The large number is prime." << endl;
    } else {
        cout << "The large number is not prime." << endl;
    }

    // Finding and displaying smaller prime numbers
    list.findAndDisplaySmallPrimes(concatenatedNumber);

    return 0;
}
