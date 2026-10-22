import random
DATA_SZ = 3

def bubb_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

msg = input("Enter the message:")
msg_chunks = [msg[i:i + DATA_SZ] for i in range(0, len(msg), DATA_SZ)]
frames = list(enumerate(msg_chunks, start=1))
print("Fragmented frames:", frames)
for i in range(len(frames)):
    j = random.randint(0, len(frames) - 1)
    frames[i], frames[j] = frames[j], frames[i]
print("Shuffled frames:", frames)
bubb_sort(frames)
print("Sorted frames:", frames)
print("Sorted message:" + "".join(x[1] for x in frames))
