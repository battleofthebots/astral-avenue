# Astral Avenue -- Off by one

### Emmanuel 

Welcome to the Cosmic Emporium Trading Post, the interstellar marketplace for intrepid explorers like yourself. Our mission is to facilitate honest and prosperous trading among fellow cosmic adventurers. However, recent reports have surfaced about nefarious entities exploiting our platform for their malicious deeds. As one of our esteemed and skilled bounty hunters, we call upon your expertise to uncover and off these bugs one by one.

# Vulnerability Explanation: Heap off by one - WIP


# Solution

`Local solve: python3 exploit.py`

`Local debugging: python3 exploit.py GDB`

`Remote solve: python3 exploit REMOTE <IP> <PORT>`

## SETUP

```
# Build docker image
docker build -t astral-avenue .

# Run image
docker run -p 9002:9002 astral-avenue

```