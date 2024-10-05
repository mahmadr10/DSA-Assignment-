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



TASK 2:
Large Number Primality Checker

Approach
This program checks whether a large number (up to 30 digits) is prime using a linked list data structure. The linked list is designed to handle numbers that exceed the storage capacity of standard data types. Each node in the linked list stores up to 9 digits of the number.
Steps:
1.	Node Class: Represents a single digit segment of the number and includes methods for initialization, length calculation, and printing.
2.	LinkedList Class: Manages the linked list of nodes, allowing for:
o	Prepending new nodes.
o	Converting the linked list into a full number.
o	Checking if the constructed number is prime.
3.	Primality Test: Utilizes a basic algorithm to test primality by checking divisibility from 2 to the square root of the number.
Assumptions
•	The input number is provided as a string to handle its large size.
•	The number entered is non-negative and can be up to 30 digits long.
•	The program does not handle negative numbers or non-integer inputs.

GitHub Link

https://github.com/mahmadr10/DSA-Assignment-/blob/main/Task_2.cpp



Challenges Faced
1.	Memory Management: Ensuring proper allocation and deallocation of nodes in the linked list to avoid memory leaks.
2.	Input Validation: Handling very large strings representing numbers while checking for validity.
3.	Efficiency: The naive primality test can be slow for very large numbers, but since we restrict input size, it is manageable.



OUTPUTS:


![image](https://github.com/user-attachments/assets/87f1a7dd-714e-48c2-9ad8-fac397c61fb0)

![image](https://github.com/user-attachments/assets/a421a767-8635-433a-8493-341fd038a176)



