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


Challenges Faced
Circular Linked List Management: Ensuring correct circular linked list behavior, especially while deleting a process, took some effort, as it was necessary to keep the circular nature intact even after process removal.
Dynamic Process Arrival: Handling the addition of a new process in the middle of the simulation required careful synchronization of process management and scheduling.
Edge Cases: Managing cases like when all processes complete within the cycle limit or when a new process arrives after some have completed posed some challenges.
Real-Time Display: Displaying the current state of all processes after every execution cycle to keep track of their status in real-time was tricky, especially while handling process deletion.

OUTPUT:

![image](https://github.com/user-attachments/assets/c8e4b4c4-acf9-4904-bd5b-a8fe87101921)
![image](https://github.com/user-attachments/assets/20cdb5a1-6335-4b90-9596-4a955a1aaeba)

