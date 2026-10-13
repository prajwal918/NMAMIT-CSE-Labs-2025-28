# Experiment 6: Error Detection Using CRC (CRC-CCITT)

**Aim.** Write a program for an error-detecting code using CRC-CCITT (16-bit).

The program appends the CRC (remainder of modulo-2 division by the generator `div`) to the data, lets you flip one bit, and checks the received codeword.

## Files
| File | Purpose |
|---|---|
| `exp6.py` | CRC generation and checking with the generator `div = [1, 0, 1, 1]` (x^3 + x + 1) |
| `exp6_ccitt.py` | *Optional variant:* the same program with the 16-bit CRC-CCITT generator x^16 + x^12 + x^5 + 1 (enter at least 17 data bits) |

## Run
```bash
python3 exp6.py
python3 exp6_ccitt.py
```

## Sample session (no error introduced)
```
$ python3 exp6.py
Enter the number of bits:4
Enter bit 1:1
Enter bit 2:0
Enter bit 3:0
Enter bit 4:1
Initial Codeword: [1, 0, 0, 1, 0, 0, 0]
Codeword to be transmitted is: [1, 0, 0, 1, 1, 1, 0]
Introduce Error - Y -> YES N->NO:N
The message received is: [1, 0, 0, 1, 1, 1, 0]
No Error
Successfully Transferred
```

Data `1001` gives the codeword `1001110` (CRC `110`). Choosing `Y` and position `1` corrupts the first bit and the program prints `Error!`.
