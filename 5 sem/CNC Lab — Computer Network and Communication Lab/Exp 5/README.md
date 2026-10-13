# Experiment 5: Bit Stuffing in the Data-Link Layer

**Aim.** Write a program to implement the bit stuffing (or byte stuffing) concept in the data-link layer.

The program stuffs a `0` after every five consecutive `1`s (sender) and removes it again (receiver).

## Files
| File | Purpose |
|---|---|
| `exp5.py` | Bit stuffing and destuffing |

## Run
```bash
python3 exp5.py
```

## Sample session
```
$ python3 exp5.py
Enter the input data:1011111101
Original data: 1011111101
Bit Stuffed data: 10111110101
Bit Destuffed data: 1011111101
```

| Input | Bit stuffed | Bit destuffed |
|---|---|---|
| `1011111101` | `10111110101` | `1011111101` |
| `11111` | `111110` | `11111` |
| `1111111111` | `111110111110` | `1111111111` |
| `0000` | `0000` | `0000` |

