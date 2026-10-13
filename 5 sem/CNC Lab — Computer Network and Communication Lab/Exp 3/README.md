# Experiment 3: Ethernet LAN, Throughput versus Data Rate and Error Rate

**Aim.** Simulate an Ethernet LAN using N nodes (6-10). Change the error rate and the data rate and compare the throughput.

**Setup.** 7 nodes: `n0` is joined to `n1` by a 3 Mb / 20 ms link, and `n1`-`n6` form an Ethernet LAN (`make-lan`, 2 Mb / 40 ms, `Mac/802_3`). TCP + FTP from `n0` to `n6` (1.0 s to 5.0 s).

## Files
| File | Purpose |
|---|---|
| `exp3.tcl` | NS-2 simulation script (also runs `exp3.awk` and writes `exp3.graph`) |
| `exp3.awk` | Throughput (kb/s) against time |
| `exp3_errormodel.tcl` | *Optional variant:* `exp3.tcl` plus an `ErrorModel` on the n0-n1 link (1 % packet errors; change `rate_`) |

## Run
```bash
ns exp3.tcl
xgraph exp3.graph

# optional: with an error rate
ns exp3_errormodel.tcl
xgraph exp3.graph
```

`warning: no class variable LanRouter::debug_` is normal for `make-lan` and can be ignored.

## Changing the data rate / error rate
* **Data rate:** edit `2Mb` in the `make-lan` line (keep the whole command on **one line**), run again and keep a copy of `exp3.graph` for each run (`cp exp3.graph rate_1Mb`); `xgraph exp3.graph rate_1Mb` draws both curves.
* **Error rate:** run `exp3_errormodel.tcl` with `rate_` set to the wanted value (0.01 = 1 %).

Throughput at 5.2 s (kb/s):

| LAN data rate (no errors) | Throughput |
|---|---|
| 0.5 Mb | 535 |
| 1 Mb | 985 |
| 2 Mb | 1327 |
| 3 Mb | 1369 |

| Error rate (LAN 2 Mb) | Throughput |
|---|---|
| 0 % | 1327 |
| 0.1 % | 871 |
| 0.5 % | 842 |
| 1 % | 805 |

