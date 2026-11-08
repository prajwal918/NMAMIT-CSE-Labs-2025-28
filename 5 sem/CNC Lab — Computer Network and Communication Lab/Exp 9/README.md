# Experiment 9: Calculator Using UDP Sockets

**Aim.** Using UDP sockets, write a client-server program in which the client sends two numbers and an operator and the server responds with the result. Display the result and appropriate messages for invalid inputs at the client side.

## Files
| File | Purpose |
|---|---|
| `udp_server.py` | UDP server listening on port 20001; computes arithmetic expression and returns result |
| `udp_client.py` | UDP client sending expression `num1 operator num2` and printing returned calculation |

## How to Run

1. Start the server in Terminal 1:
   ```bash
   python3 udp_server.py
   ```

2. Run the client in Terminal 2:
   ```bash
   python3 udp_client.py
   ```
