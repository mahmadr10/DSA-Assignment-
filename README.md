# DSA-Assignment-

TASK 1

CPU Scheduling Simulation
Approach
This project simulates a Round-Robin CPU scheduling system using a circular linked list to represent processes. Each process runs for a fixed time slice in each cycle, and the system supports the arrival of a new process during the scheduling simulation.

Key steps in the approach:

Circular Linked List for Processes: Each process is stored in a circular linked list. This ensures that after a process finishes its time slice, the next process in line gets scheduled.
CPU Scheduling: The CPU scheduling happens in cycles. Each process gets a fixed time slice to execute in each cycle. After the time slice, the remaining time of the process is updated, and if a process completes its execution, it is removed from the queue.
New Process Arrival: During the simulation, a new process is added to the list after a specified cycle (e.g., after cycle 2), and the system dynamically handles it.
Display of Process States: After each process executes in a cycle, the updated state (remaining time) of all processes is displayed.
Assumptions
Time Slice: Each process is given a fixed time slice of 3 units per cycle.
New Process Arrival: A new process arrives after the second cycle with a specified remaining time.
Fixed Number of Cycles: The simulation is run for a set number of cycles, specified by the user.
Process Completion: If a process’s remaining time reaches zero or below, it is considered complete and removed from the queue.

GitHub Link: https://github.com/mahmadr10/DSA-Assignment-/blob/main/Task_1.cpp

Challenges Faced
Circular Linked List Management: Ensuring correct circular linked list behavior, especially while deleting a process, took some effort, as it was necessary to keep the circular nature intact even after process removal.
Dynamic Process Arrival: Handling the addition of a new process in the middle of the simulation required careful synchronization of process management and scheduling.
Edge Cases: Managing cases like when all processes complete within the cycle limit or when a new process arrives after some have completed posed some challenges.
Real-Time Display: Displaying the current state of all processes after every execution cycle to keep track of their status in real-time was tricky, especially while handling process deletion.

OUTPUT:

![image](https://github.com/user-attachments/assets/c8e4b4c4-acf9-4904-bd5b-a8fe87101921)
![image](https://github.com/user-attachments/assets/20cdb5a1-6335-4b90-9596-4a955a1aaeba)



TASK 2:

1024-bit Number Primality Test
Approach
This project implements a primality test for a large 1024-bit number represented by a circular linked list. The system generates a random 1024-bit number (comprised of 16 random 64-bit chunks) and tests whether it is a prime number using the Miller-Rabin Primality Test.

Key Steps:
Random Number Generation: The project creates a random 1024-bit number by generating 16 random 64-bit values. These values are stored in a linked list, and the full 1024-bit number is reconstructed by combining these 64-bit blocks.
Modular Exponentiation: This function is used as part of the Miller-Rabin test to efficiently compute powers of large numbers modulo another number.
Miller-Rabin Test: The primality of the generated 1024-bit number is tested using the Miller-Rabin test, a probabilistic test that determines whether a number is composite or probably prime.
Linked List Representation: The number is stored as a linked list of 64-bit values and is reconstructed from the linked list for the primality test.
Assumptions
Random 1024-bit Number: The number is randomly generated using 16 chunks of 64-bit numbers.
Miller-Rabin Test Iterations: The default number of iterations for the Miller-Rabin test is set to 5 (k = 5).
Prime Numbers Handling: Small numbers (like 1, 2, and 3) are handled separately as they are edge cases for primality.

GitHub Link: https://github.com/mahmadr10/DSA-Assignment-/blob/main/Task_2.cpp


Challenges Faced
Handling Large Numbers: Reconstructing a large 1024-bit number from a linked list and performing operations on it efficiently presented challenges, especially in ensuring correctness when combining the 64-bit blocks.
Miller-Rabin Implementation: Implementing the Miller-Rabin test correctly for large numbers required special attention to details such as modular exponentiation and decomposition of numbers for the test.
Random Number Generation: Ensuring that the random number generator produces truly random and large 64-bit values while dealing with edge cases (like very small or very large values) was a challenge.

OUTPUT:

![image](https://github.com/user-attachments/assets/0592d5be-9a25-41e4-8c95-bab6f81b9a6a)


