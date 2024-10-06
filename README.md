# DSA-Assignment-

TASK 1

CPU Scheduling Simulation

Approach
This project simulates a Round-Robin CPU scheduling system using a circular linked list to represent processes. Each process runs for a fixed time slice in each cycle, and the system supports the arrival of a new process during the scheduling simulation.
Key steps in the approach:
1.	Circular Linked List for Processes: Each process is stored in a circular linked list. This ensures that after a process finishes its time slice, the next process in line gets scheduled.
2.	CPU Scheduling: The CPU scheduling happens in cycles. Each process gets a fixed time slice to execute in each cycle. After the time slice, the remaining time of the process is updated, and if a process completes its execution, it is removed from the queue.
3.	New Process Arrival: During the simulation, a new process is added to the list after a specified cycle (e.g., after cycle 2), and the system dynamically handles it.
4.	Display of Process States: After each process executes in a cycle, the updated state (remaining time) of all processes is displayed.
Assumptions
•	Time Slice: Each process is given a fixed time slice of 3 units per cycle.
•	New Process Arrival: A new process arrives after the second cycle with a specified remaining time.
•	Fixed Number of Cycles: The simulation is run for a set number of cycles, specified by the user.
•	Process Completion: If a process’s remaining time reaches zero or below, it is considered complete and removed from the queue.


GitHub Link:

https://github.com/mahmadr10/DSA-Assignment-/blob/main/Task_1.cpp

Challenges Faced
1.	Circular Linked List Management: Ensuring correct circular linked list behavior, especially while deleting a process, took some effort, as it was necessary to keep the circular nature intact even after process removal.
2.	Dynamic Process Arrival: Handling the addition of a new process in the middle of the simulation required careful synchronization of process management and scheduling.
3.	Edge Cases: Managing cases like when all processes complete within the cycle limit or when a new process arrives after some have completed posed some challenges.
4.	Real-Time Display: Displaying the current state of all processes after every execution cycle to keep track of their status in real-time was tricky, especially while handling process 


OUTPUT:

![image](https://github.com/user-attachments/assets/c8e4b4c4-acf9-4904-bd5b-a8fe87101921)
![image](https://github.com/user-attachments/assets/20cdb5a1-6335-4b90-9596-4a955a1aaeba)



TASK-2

1024 Bit Number Primality Check

Approach
This project involves creating a linked list to store a large random number (up to 1024 bits or 309 digits) and checking its primality. The approach includes:

Linked List Structure: Each node in the linked list holds a substring of the large number (up to 19 digits) to facilitate easy management and processing of large numbers.
Primality Testing: The entire number is checked for primality using the isPrimeString function, which utilizes trial division for efficiency.
Finding Smaller Primes: The program also finds and displays smaller prime numbers (up to 19 digits) contained within the large number.
Assumptions
The input number will be valid and contain only numeric characters.
The number will be less than or equal to 309 digits.
Each node can hold a maximum of 19 digits.
The user understands that the input number may not be prime.

GitHub Link
DSA-Assignment-/Task_2.cpp at main · mahmadr10/DSA-Assignment- · GitHub



Challenges Faced
Handling Large Numbers: Managing very large numbers (beyond typical integer limits) required careful implementation of string operations.
Efficiency: Optimizing the primality test to avoid excessive computation for large numbers was a challenge.
Substring Extraction: Efficiently checking all possible substrings for primality while avoiding duplicates and leading zeros.


OUTPUTS:



![image](https://github.com/user-attachments/assets/7e15c59a-7196-4fb3-89a1-86c6d0189964)
![image](https://github.com/user-attachments/assets/ce27a664-54e3-4efd-8735-3f0be12229fe)






