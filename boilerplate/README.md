# Lightweight Container Runtime with Kernel Monitoring

## 1. Team Information

| Name | SRN |
|------|-----|
| Mukil Skanda | YOUR_SRN |
| Partner Name | SRN |

---

## 2. Build, Load, and Run Instructions

### Prerequisites
- Linux (Kali / Ubuntu)
- GCC compiler
- Kernel headers

Install dependencies:
```bash
sudo apt update
sudo apt install -y build-essential linux-headers-$(uname -r)
```

---

### Build Project
```bash
make
```

---

### Run Containers
```bash
./boilerplate/engine start alpha
./boilerplate/engine start beta
```

---

### List Containers
```bash
./boilerplate/engine ps
```

---

### Stop Containers
```bash
./boilerplate/engine stop alpha
./boilerplate/engine stop beta
```

---

### Logging
```bash
echo "[alpha] container started" > log_alpha.txt
cat log_alpha.txt
```

---

### Scheduling Experiment
```bash
time nice -n 10 ./boilerplate/cpu_test
time sudo nice -n -5 ./boilerplate/cpu_test
```

---

### Kernel Module (Memory Monitoring)
```bash
cd boilerplate
make
sudo insmod monitor.ko
dmesg | grep -E "Container|SOFT|HARD"
```

---

### Cleanup
```bash
sudo rmmod monitor
ps aux | grep defunct
```

---

## 3. Demo with Screenshots

### 1. Multi-container supervision
Two containers (alpha and beta) running simultaneously.

### 2. Metadata tracking
The `ps` command shows container ID, PID, and status.

### 3. Logging
Container logs stored in `log_alpha.txt`.

### 4. CLI interaction
Commands like start, stop, and ps control containers.

### 5. Soft-limit warning
Kernel module prints warning messages in dmesg.

### 6. Hard-limit enforcement
Kernel module simulates process termination.

### 7. Scheduling experiment
Different nice values show CPU priority differences.

### 8. Clean teardown
No zombie processes after stopping containers.

---

## Screenshots

### 1. Multi-container supervision
![Multi-container](Screenshots/1_multicontainer.png)

### 2. Metadata tracking
![PS Output](Screenshots/2_ps.png)

### 3. Container lifecycle (Stop)
![Stop](Screenshots/3_stop.png)

### 4. Logging system
![Logging](Screenshots/4_logging.png)

### 5. Scheduling experiment
![Scheduling](Screenshots/5_scheduling.png)

### 6. Kernel monitoring (Soft & Hard limits)
![Kernel](Screenshots/6_kernel.png)

### 7. Kernel module unload
![Unload](Screenshots/7_unload.png)

### 8. Clean teardown
![Cleanup](Screenshots/8_cleanup.png)

---

## 4. Engineering Analysis

### Isolation Mechanisms
Containers are implemented as separate processes providing basic isolation.

### Supervisor and Process Lifecycle
The engine program manages container creation, tracking, and termination.

### IPC and Synchronization
Command-line interface is used for interaction and process control.

### Memory Management
Kernel module simulates memory monitoring and generates limit warnings.

### Scheduling Behavior
Linux scheduler behavior is demonstrated using different nice values.

---

## 5. Design Decisions and Tradeoffs

| Subsystem | Decision | Tradeoff | Justification |
|----------|---------|----------|--------------|
| Container Model | Simple processes | No full isolation | Easier implementation |
| Supervisor | Single program | No persistence | Simpler control |
| Logging | File-based | Not real-time | Enough for demo |
| Kernel Module | Simulated limits | No real enforcement | Demonstrates concept |
| Scheduling | Nice values | Limited control | Shows scheduler clearly |

---

## 6. Scheduler Experiment Results

| Process | Nice Value | Observation |
|--------|-----------|-------------|
| cpu_test | 10 | Slower execution |
| cpu_test | -5 | Faster execution |

Lower nice values result in higher priority and faster execution, demonstrating Linux scheduling behavior.

---

## Conclusion

This project demonstrates key operating system concepts including process management, container-like execution, scheduling, and kernel-level monitoring in a simplified environment.# Lightweight Container Runtime with Kernel Monitoring

## 1. Team Information

| Name | SRN |
|------|-----|
| Mukil Skanda | YOUR_SRN |
| Partner Name | SRN |

---

## 2. Build, Load, and Run Instructions

### Prerequisites
- Linux (Kali / Ubuntu)
- GCC compiler
- Kernel headers

Install dependencies:
```bash
sudo apt update
sudo apt install -y build-essential linux-headers-$(uname -r)
```

---

### Build Project
```bash
make
```

---

### Run Containers
```bash
./boilerplate/engine start alpha
./boilerplate/engine start beta
```

---

### List Containers
```bash
./boilerplate/engine ps
```

---

### Stop Containers
```bash
./boilerplate/engine stop alpha
./boilerplate/engine stop beta
```

---

### Logging
```bash
echo "[alpha] container started" > log_alpha.txt
cat log_alpha.txt
```

---

### Scheduling Experiment
```bash
time nice -n 10 ./boilerplate/cpu_test
time sudo nice -n -5 ./boilerplate/cpu_test
```

---

### Kernel Module (Memory Monitoring)
```bash
cd boilerplate
make
sudo insmod monitor.ko
dmesg | grep -E "Container|SOFT|HARD"
```

---

### Cleanup
```bash
sudo rmmod monitor
ps aux | grep defunct
```

---

## 3. Demo with Screenshots

### 1. Multi-container supervision
Two containers (alpha and beta) running simultaneously.

### 2. Metadata tracking
The `ps` command shows container ID, PID, and status.

### 3. Logging
Container logs stored in `log_alpha.txt`.

### 4. CLI interaction
Commands like start, stop, and ps control containers.

### 5. Soft-limit warning
Kernel module prints warning messages in dmesg.

### 6. Hard-limit enforcement
Kernel module simulates process termination.

### 7. Scheduling experiment
Different nice values show CPU priority differences.

### 8. Clean teardown
No zombie processes after stopping containers.

---

## Screenshots

### 1. Multi-container supervision
![Multi-container](Screenshots/1_multicontainer.png)

### 2. Metadata tracking
![PS Output](Screenshots/2_ps.png)

### 3. Container lifecycle (Stop)
![Stop](Screenshots/3_stop.png)

### 4. Logging system
![Logging](Screenshots/4_logging.png)

### 5. Scheduling experiment
![Scheduling](Screenshots/5_scheduling.png)

### 6. Kernel monitoring (Soft & Hard limits)
![Kernel](Screenshots/6_kernel.png)

### 7. Kernel module unload
![Unload](Screenshots/7_unload.png)

### 8. Clean teardown
![Cleanup](Screenshots/8_cleanup.png)

---

## 4. Engineering Analysis

### Isolation Mechanisms
Containers are implemented as separate processes providing basic isolation.

### Supervisor and Process Lifecycle
The engine program manages container creation, tracking, and termination.

### IPC and Synchronization
Command-line interface is used for interaction and process control.

### Memory Management
Kernel module simulates memory monitoring and generates limit warnings.

### Scheduling Behavior
Linux scheduler behavior is demonstrated using different nice values.

---

## 5. Design Decisions and Tradeoffs

| Subsystem | Decision | Tradeoff | Justification |
|----------|---------|----------|--------------|
| Container Model | Simple processes | No full isolation | Easier implementation |
| Supervisor | Single program | No persistence | Simpler control |
| Logging | File-based | Not real-time | Enough for demo |
| Kernel Module | Simulated limits | No real enforcement | Demonstrates concept |
| Scheduling | Nice values | Limited control | Shows scheduler clearly |

---

## 6. Scheduler Experiment Results

| Process | Nice Value | Observation |
|--------|-----------|-------------|
| cpu_test | 10 | Slower execution |
| cpu_test | -5 | Faster execution |

Lower nice values result in higher priority and faster execution, demonstrating Linux scheduling behavior.

---

## Conclusion

This project demonstrates key operating system concepts including process management, container-like execution, scheduling, and kernel-level monitoring in a simplified environment.
