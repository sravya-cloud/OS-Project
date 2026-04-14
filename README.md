# Multi-Container Runtime

## Team Members
- Member 1
- Member 2

---

## Project Summary
This project implements a lightweight container runtime in C with a supervisor process that manages multiple containers. Each container is represented as a process. A kernel module is used to simulate memory monitoring with soft and hard limits.

---

## Features
- Multi-container management
- CLI interface (start, ps, stop)
- Logging system (simulated)
- Kernel module for memory monitoring
- Scheduling experiment using nice values

---

## Commands Used

### Start Container
./engine start alpha

### List Containers
./engine ps

### Stop Container
./engine stop alpha

---

## Scheduling Experiment
We used different nice values to observe CPU scheduling behavior.

Example:
nice -n 10 ./cpu_test
sudo nice -n -5 ./cpu_test

Result:
Lower nice value gives higher priority and faster execution.

---

## Memory Monitoring
A kernel module is used to simulate:
- Soft limit → warning
- Hard limit → process termination

Output is observed using:
dmesg | tail

---

## Logging
Container logs are stored in a file:
log_alpha.txt

---

## Cleanup
No zombie processes were observed:
ps aux | grep defunct

---

## Engineering Analysis

### Isolation
Containers are isolated as separate processes.

### IPC
Communication is simulated using command-line interaction.

### Memory
Kernel module monitors memory usage and enforces limits.

### Scheduling
Linux scheduler allocates CPU based on nice values.

---

## Conclusion
The project demonstrates container management, process control, memory monitoring, and scheduling behavior in Linux.
