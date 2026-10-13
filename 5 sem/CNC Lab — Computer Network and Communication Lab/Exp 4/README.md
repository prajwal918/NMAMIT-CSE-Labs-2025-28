# Experiment 4: Ethernet LAN with Multiple Traffic Flows, Congestion Window

**Aim.** Simulate an Ethernet LAN using N nodes and set multiple traffic nodes, and determine the collisions across the different nodes. Also plot the congestion window for different source/destination pairs.

**Setup.** `n1` and `n2` connect to `n0` (2 Mb / 10 ms), `n0` to `n3` (1 Mb / 20 ms, queue limit 20), and `n3`-`n8` form an Ethernet LAN (512 kb / 40 ms, `Mac/802_3`). Flow 1: TCP Vegas + FTP `n1` to `n7` (starts 0.5 s). Flow 2: TCP Reno + FTP `n2` to `n8` (starts 1.0 s). Both stop at 5.0 s.

## Files
| File | Purpose |
|---|---|
| `exp4.tcl` | NS-2 simulation script (writes `cwnd1.tr`, `cwnd2.tr` and runs `exp4.awk` to create `tcp1`, `tcp2`) |
| `exp4.awk` | Extracts time and congestion window (`cwnd_`) from a cwnd trace |

## Run
```bash
ns exp4.tcl
xgraph tcp1     # TCP Vegas congestion window
xgraph tcp2     # TCP Reno congestion window
```

## What to expect
* Vegas leaves slow start at 20 packets, settles at about 22.0 packets at t = 2.96 s and then keeps that window.
* Reno leaves slow start at 20 packets and then grows linearly, reaching 30.7 packets at t = 5.10 s.
* The trace file contains no `d` (drop) records: no packet is lost in this scenario.
* Both curves end with a reset of the window to 1 shortly after the sources stop (5.0 s).
