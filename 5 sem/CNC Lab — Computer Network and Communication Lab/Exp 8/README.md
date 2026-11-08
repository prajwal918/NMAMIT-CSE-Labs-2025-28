# Experiment 8: File Transfer Using TCP Sockets

**Aim.** Using TCP/IP sockets, write a client-server program in which the client sends the name of a file and the server sends back the contents of the requested file if it is present.

## Files
| File | Purpose |
|---|---|
| `tcp_server.py` | TCP server listening on port 8888; responds with file contents or "File not found" |
| `tcp_client.py` | TCP client requesting file, displaying contents, and saving as `received_<filename>` |
| `sample.txt` | Sample text file for testing transfer |

## How to Run

1. Start the server in Terminal 1:
   ```bash
   python3 tcp_server.py
   ```

2. Run the client in Terminal 2:
   ```bash
   python3 tcp_client.py
   ```
