# Experiment 7: Frame Sorting Technique Used in Buffers

**Aim.** Write a program for the frame sorting technique used in buffers.

A message that does not fit into one frame is cut into pieces of `DATA_SZ = 3` characters, and every piece is assigned a 1-based sequence number. Arrival out of order across a network channel is simulated by shuffling the frames. At the receiver, the frames in the buffer are sorted back into order using bubble sort on their sequence numbers, and reconstructed into the original message.

## Files
| File | Purpose |
|---|---|
| `exp7.py` | Message fragmentation, random order shuffling, bubble sort reassembly |

## Run
```bash
python3 exp7.py
```

## Sample session
```
$ python3 exp7.py
Enter the message:NMAMIT NITTE
Fragmented frames: [(1, 'NMA'), (2, 'MIT'), (3, ' NI'), (4, 'TTE')]
Shuffled frames: [(2, 'MIT'), (3, ' NI'), (1, 'NMA'), (4, 'TTE')]
Sorted frames: [(1, 'NMA'), (2, 'MIT'), (3, ' NI'), (4, 'TTE')]
Sorted message:NMAMIT NITTE
```

## Test runs

| Input message | Frames | Order after shuffling | Restored |
|---|---|---|---|
| `NMAMIT NITTE` | 4 | 2 3 1 4 | yes |
| `HELLO` | 2 | 2 1 | yes |
| `HI` | 1 | 1 | yes |
| `COMPUTER NETWORKS` | 6 | 1 2 6 4 3 5 | yes |
| `COMPUTER NETWORKS LABORATORY` | 10 | 1 7 3 6 10 8 9 5 4 2 | yes |

## Key observations
- **Arbitrary chunk size:** If the message length is not a multiple of `DATA_SZ`, the last frame is shorter (e.g., `HELLO` gives `HEL` and `LO`) and is handled seamlessly.
- **Integer sequence comparison:** Frame sequence numbers are integers, so frame `10` correctly follows frame `9`.
- **Complexity:** For $n$ frames, bubble sort performs $n(n - 1) / 2$ comparisons to restore order in the buffer.

## Viva Voce Questions & Answers

1. **Why must frames in the receive buffer be sorted?**  
   Frames can arrive out of order due to differing routes, network delays, or retransmissions (e.g., Selective Repeat ARQ). The upper layer requires data in sequence, so the receiver buffers incoming frames and sorts them by sequence number.

2. **What is the purpose of the sequence number?**  
   It specifies the original position of the frame in the message, enabling the receiver to reorder fragments, detect missing frames, and discard duplicates.

3. **How does bubble sort work and how many comparisons does it make for $n$ frames?**  
   It compares adjacent pairs of frames and swaps them if they are out of order, bubbling the largest remaining sequence number to the end on each pass. It makes $n(n - 1)/2$ comparisons.

4. **What does `enumerate(msg_chunks, start=1)` do?**  
   It pairs each string chunk with an incremental integer index starting at 1, yielding frames of the form `(1, 'NMA')`.

5. **What happens if the length of the message is not a multiple of `DATA_SZ`?**  
   The final chunk is shorter than `DATA_SZ`. It is numbered and sorted like the other frames without error.
