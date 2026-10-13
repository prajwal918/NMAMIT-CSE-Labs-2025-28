# Experiment 2: TCP and UDP Traffic, Packet Counts and Throughput

**Aim.** Simulate a four-node point-to-point network and connect the links as follows: n0-n2, n1-n2 and n2-n3. Apply a TCP agent between n0-n3 and a UDP agent between n1-n3. Apply relevant applications over the TCP and UDP agents, change the parameters, determine the number of packets sent by TCP and UDP and analyse the throughput.

**Setup.** All links 1 Mb / 10 ms, DropTail, queue limit 50. TCP + FTP from `n0` to `n3` (0.75 s to 4.75 s); UDP + CBR (500 bytes every 5 ms) from `n1` to `n3` (0.5 s to 4.5 s).

## Files
| File | Purpose |
|---|---|
| `exp2.tcl` | NS-2 simulation script |
| `exp2.awk` | Counts TCP and UDP (`cbr`) trace records |
| `exp2_throughput.awk` | Throughput (kb/s) against time |
| `plot_tcp`, `plot_udp` | XGraph data: bandwidth vs. packet count |

## Run
```bash
ns exp2.tcl
awk -f exp2.awk out.tr
xgraph plot_tcp
xgraph plot_udp
awk -f exp2_throughput.awk out.tr > plot_throughput
xgraph plot_throughput
```

## Expected output
```
The number of packets by TCP =846
The number of packets by UDP =4786
```

Counts for different link bandwidths (edit `1Mb` in the three `duplex-link` lines):

| Bandwidth (Mb) | TCP records | UDP records |
|---|---|---|
| 1 | 846 | 4786 |
| 1.25 | 1509 | 4791 |
| 1.5 | 2071 | 4805 |
| 1.75 | 2892 | 4806 |
| 2 | 3582 | 4806 |

Throughput at the end of the run: 2013 kb/s (1 Mb), 2876 kb/s (1.5 Mb), 3856 kb/s (2 Mb).

> The AWK script counts trace *records* of each packet type (a packet produces several records: enqueue, dequeue and receive on every link), so the numbers are used to compare TCP with UDP and the different bandwidths.
