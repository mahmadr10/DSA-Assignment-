# DSA-Assignment-

TASK 1

CPU Scheduling Simulation
Approach
This program simulates a simple CPU scheduling mechanism using a circular linked list. Each node represents a process in the system, with an associated process ID, execution time, and remaining time. The scheduling is done in cycles where each process is executed for a fixed time slice until its remaining time becomes zero, at which point it is removed from the list.

The program contains the following key steps:

Circular Linked List Structure: The processes are arranged in a circular linked list to model round-robin scheduling.
Node Class: Each process is represented as a node in the linked list, containing the process ID, execution time, and remaining time.
CPU Class: The CPU class handles the scheduling, process execution, and process removal.
Process Execution: Each process is executed in a cycle, with its remaining time reduced by the time slice. Once the remaining time is exhausted, the process is marked as complete and removed from the list.
Display of Remaining Processes: After each time slice, the list of remaining processes is displayed.
Assumptions
Each process has a fixed execution time.
The time slice for scheduling is given and reduces the remaining time of the current process.
Once the remaining time of a process becomes zero, it is removed from the list.
The processes are arranged in a circular linked list for efficient scheduling in a round-robin manner.
Challenges Faced
Circular Linked List Implementation: Properly implementing the circular nature of the linked list was tricky when adding and removing nodes while ensuring the list remains circular.
Process Removal: Managing node deletion without breaking the circular nature of the list was a challenge, especially when the process being removed was the head of the list.
Edge Cases: Handling edge cases, such as only one process remaining in the system, required careful attention.

OUTPUT:
![image](https://github.com/user-attachments/assets/4f28f30f-f2d7-45bb-aa46-e6039298b726)
