# Experiment 1: Point-to-Point Network, Queue Size, Bandwidth and Packet Drops

**Aim.** Simulate a three-node point-to-point network with duplex links between them. Set the queue size, vary the bandwidth and find the number of packets dropped.

**Setup.** `n0 - n1 - n2`, duplex links of 1 Mb / 10 ms with DropTail queues (limit 50 packets). A UDP agent with a CBR source (500 bytes every 5 ms = 800 kb/s) sends from `n0` to `n2` between 0.5 s and 4.5 s.

## Files
| File | Purpose |
|---|---|
| `exp1.tcl` | NS-2 simulation script |
| `exp1.awk` | Counts the dropped packets (`d` events) in `out.tr` |
| `plot_graph_1` | XGraph data: bandwidth (Mb) vs. packets dropped |
| `plot_graph_2` | XGraph data: queue limit vs. packets dropped |

## Run
```bash
ns exp1.tcl
awk -f exp1.awk out.tr
xgraph plot_graph_1
xgraph plot_graph_2
```

## Expected output
With the default 1 Mb links the 800 kb/s load fits in the link, so nothing is dropped:
```
 The number of packets dropped =0 
```

## Varying the parameters
Edit `1Mb` in the two `duplex-link` lines (bandwidth) or `50` in the two `queue-limit` lines (queue size), run again and note the count.

| Bandwidth (queue limit 50) | Packets dropped |
|---|---|
| 0.25 | 502 |
| 0.5 | 252 |
| 0.75 | 2 |
| 1 | 0 |

| Queue limit (bandwidth 0.75 Mb) | Packets dropped |
|---|---|
| 10 | 42 |
| 20 | 32 |
| 30 | 22 |
| 40 | 12 |

