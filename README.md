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

1024-bit Primality Test with Linked List

Approach
The program stores a large number (up to 1024 bits) in a linked list, where each node holds up to 64-bit unsigned integers. This approach ensures that even a very large number can be managed efficiently across multiple nodes in the linked list.

Steps:
Number Representation: The input number (up to 1024 bits) is split into smaller chunks, with each chunk stored in a separate node in the linked list. Each node stores a 64-bit number, ensuring that the memory can efficiently hold very large numbers.
Linked List Structure: The list stores each segment of the number in reverse order to simplify further operations like appending and traversal.
Primality Test: Once the number is reconstructed from the linked list, the primality check is performed by using a brute force approach, iterating through all possible divisors up to the square root of the number.
Assumptions
The number entered is a positive integer.
The number is represented as a string, allowing for flexibility in handling very large numbers.
We assume that the number is split into chunks of up to 9 digits in each node for manageable storage, as unsigned integers are used.
The primality test checks divisibility starting from 2 up to the square root of the number.

GitHub: https://github.com/mahmadr10/DSA-Assignment-/blob/main/Task_2.cpp  


Challenges Faced
Memory Management: Storing a very large number in a linked list efficiently without exceeding memory limits was tricky. Managing the number using chunks of data in each node helped in overcoming this.
Reconstructing the Number: Reconstructing the number from the linked list across multiple nodes while ensuring no precision loss was a key challenge.
Primality Check for Large Numbers: Testing the primality of a 1024-bit number is computationally intensive. Although a brute force method works for smaller numbers, an optimized primality test like Miller-Rabin may be required for much larger numbers.

OUTPUTS:



![image](https://github.com/user-attachments/assets/abf5545f-8c76-48be-92c7-6e7a0acc56b6)


![image](https://github.com/user-attachments/assets/de916459-a519-4b07-bbca-a3b29f0d305e)




