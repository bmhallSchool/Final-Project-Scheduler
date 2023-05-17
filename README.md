# Final-Project-Scheduler
Final Project: Extension of Scheduler
Benjamin Hall

VIDEO PRESENTATION FOUND HERE: https://drive.google.com/file/d/16QLO7riCsZ9j6o7pcO9j83Lq5zC2Ancp/view?usp=sharing

This project was done with the goal of extending the basic scheduling approaches initially covered in Project 3 by comparing 3 similar approaches as well as the implementation of the more complex MLFQ approach.

The input now also takes ljf, ltcf, pbs, mlfqFive, and mlfqTen for the process in the scheduling_app arguments and the workloads.txt file must contain 3 integer on a line (for a respective process) the first being start time like before, the second being duration like before, and the new third being the priority of the process (higher priority = higher number, and intensive = 1, interactive = 4).

The 3 simple approaches were Longest-Job-First, Longest-To-Completion-First, and Priority-Based-Scheduling.

Longest-Job-First is very similar to Shortest-Job-First as the name would imply, whenever the CPU is free and just completed running a process it chooses the next process by selecting the available job with the longest duration and running that process to completion. This is not an efficient way of approaching this as response time will be extremely long and serves as a counter to the benefits of sjf.

Longest-To-Completion-First is very similar to Shortest-To-Completion-First, whenever the CPU is free the next process will be chosen by selecting the available job with the longest remaining time and running it for a second and checking again. This again is the not efficient and outlines the benefits of STCF as an abnormally long process arriving first would be prioritized and ran for a long time before the other shorter processes, leading to high average response times.

Priority-Based-Scheduling takes in processes with assigned priority levels. The CPU will when free take the process with the highest priority and run it to completion, before selecting the next process with the highest priority. This could be augmented to check everytime interval for the highest priority similar to LTCF but in both cases the metrics won't fully reflect the benefit of this in that the jobs of the highest priority are run and completed before processing lower-value jobs.

The last is MLFQ which functions by taking in processes, in my case interactive was treated as priority 4 and intensive as 1. The processes available at the time are assigned to their respective queue level, anything above 4 are put in the highest priority queue of levelFour. A process is taken from the highest queue with a process, and it is run for the duration of the specified time slice and if it completes add it to completed, if not then it is demoted in status and sent to the priority level beneath its previous. With the minimum being one where a process would simply remain. On top of this to prevent intensive processes from never being run there is a priority boost implemented. For a specified boost period, for example 5 seconds, every time 5 seconds passes all processes currently available are boosted and assigned to the highest priority level allowing for the intensive processes stuck in the lowest queue to be run for at least a time slice before being demoted. To demonstrate the difference in values of boosting there are 2 mlfq functions with two separate boost period values. # Final-Project-Scheduler