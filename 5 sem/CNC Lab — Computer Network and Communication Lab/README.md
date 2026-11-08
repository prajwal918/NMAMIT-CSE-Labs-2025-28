# Computer Networks and Communication Laboratory

Programs and documentation for the Computer Networks Laboratory (5th Semester B.E.): four network simulations written for **NS-2** (Tcl scripts, AWK analysis, XGraph plots), five network and data-link layer programs written in **Python 3**, and a distance vector routing algorithm in **C**.

## Lab Manuals
- [**CN_Lab_Manual.pdf**](CN_Lab_Manual.pdf) - Complete laboratory manual and record (Experiments 1–10) containing theory, topology diagrams, program scripts, execution workflows, sample outputs, viva voce question bank, and troubleshooting guide.
- [**CSE_CNC_LAB_MANUAL-20CS502_2023.pdf**](CSE_CNC_LAB_MANUAL-20CS502_2023.pdf) - Department course syllabus and lab manual.

## Experiments

| # | Folder | Topic | Tools |
|---|---|---|---|
| 1 | [Exp 1](<Exp 1>) | Point-to-point network: packet drops vs. bandwidth and queue size | NS-2, AWK, XGraph |
| 2 | [Exp 2](<Exp 2>) | TCP and UDP traffic: packet counts and throughput | NS-2, AWK, XGraph |
| 3 | [Exp 3](<Exp 3>) | Ethernet LAN: throughput vs. data rate and error rate | NS-2, AWK, XGraph |
| 4 | [Exp 4](<Exp 4>) | Ethernet LAN with two TCP flows: congestion window of Vegas and Reno | NS-2, AWK, XGraph |
| 5 | [Exp 5](<Exp 5>) | Bit stuffing and destuffing | Python 3 |
| 6 | [Exp 6](<Exp 6>) | CRC error detection (CRC-CCITT) | Python 3 |
| 7 | [Exp 7](<Exp 7>) | Frame sorting technique used in buffers | Python 3 |
| 8 | [Exp 8](<Exp 8>) | File transfer using TCP sockets | Python 3 |
| 9 | [Exp 9](<Exp 9>) | Calculator using UDP sockets | Python 3 |
| 10 | [Exp 10](<Exp 10>) | Distance vector routing algorithm | C (GCC) |

## Requirements
Ubuntu / Linux with **NS-2 2.35**, **NAM**, **XGraph**, `awk` (mawk or gawk), **Python 3**, and **GCC**.

## How to Run
Every experiment folder is self-contained. Open a terminal inside the experiment folder and follow its `README.md`. For example:

```bash
cd "Exp 1"
ns exp1.tcl
awk -f exp1.awk out.tr
```

> **Note:** Do not start `ns` without a script name; it opens an interactive prompt.

## Generated Files
The simulations write trace, NAM, and graph output files (`out.tr`, `*.nam`, `exp3.graph`, `tcp1`, `tcp2`, etc.). These are ignored via `.gitignore` to keep the repository clean.
