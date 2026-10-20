# Operating Systems Laboratory

Programs and documentation for the Operating Systems Laboratory (5th Semester B.E. CSE), NMAM Institute of Technology, Nitte.

## Lab Manual
- [**OS_LAB_MANUAL.pdf**](OS_LAB_MANUAL.pdf) - Complete laboratory manual containing experiment aims, C programs, shell scripts, and execution outputs.

## Experiments

| Expt. No. | Folder | Title | Description |
|:---:|---|---|---|
| **1** | [`exp1_exec`](exp1_exec) | `exec()` system call | Prompts for a shell script name and executes it via `execl()` using `/bin/sh`. Includes `largest.sh` to find the greatest of three numbers. |
| **2** | [`exp2_file_read`](exp2_file_read) | File read using system calls | Reads and displays file contents on standard output using low-level system calls `open()`, `read()`, and `write()`. |
| **3** | [`exp3_fork`](exp3_fork) | Child processes using `fork()` | Creates 5 child processes using `fork()`, prints child and parent PIDs, and uses `wait()` to synchronize child termination. |
| **4** | [`exp4_file_write`](exp4_file_write) | File write using system calls | Reads keyboard input and writes it directly to a specified destination file using `open()`, `read()`, and `write()`. |
| **5** | [`exp5_signals`](exp5_signals) | Signal handling | Demonstrates handling of signals (`SIGINT`, `SIGTERM`, `SIGHUP`, `SIGALRM`, `SIGUSR1`) using `signal()`. |
| **6** | [`exp6_fcfs`](exp6_fcfs) | FCFS scheduling | Simulates First Come First Serve CPU scheduling and computes Waiting Time (WT) and Turnaround Time (TAT). |
| **7** | [`exp7_sjf`](exp7_sjf) | SJF scheduling | Simulates Shortest Job First (non-preemptive) CPU scheduling and calculates WT and TAT for given burst times. |
| **8** | [`exp8_round_robin`](exp8_round_robin) | Round Robin scheduling | Simulates Round Robin CPU scheduling for given time quantum and displays WT, TAT, and Gantt chart metrics. |
| **9** | [`exp9_producer_consumer`](exp9_producer_consumer) | Producer-Consumer using semaphores | Simulates the classic Producer-Consumer problem using bounded buffer queue operations. |

## Requirements
- **OS**: Linux or Windows Subsystem for Linux (WSL / WSL2 - Ubuntu recommended)
- **Compiler**: GCC (`build-essential`)

To install GCC in WSL/Ubuntu:
```bash
sudo apt update && sudo apt install -y build-essential gcc
```

## How to Compile and Run

Each experiment folder contains a self-contained `main.c` file. Navigate into any experiment folder and compile using `gcc`:

```bash
# Example for Experiment 1:
cd exp1_exec
chmod +x largest.sh
gcc main.c -o exp1
./exp1

# Example for Experiment 9:
cd exp9_producer_consumer
gcc main.c -o exp9
./exp9
```
