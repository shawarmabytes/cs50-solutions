import cs50

while True:
    height = cs50.get_int("Height: ")
    if (0 < height <= 8):
        break

for i in range(height):
    print(" "*(height-i-1), end="")  # prints descending dots or spaces
    print("#"*(i+1))  # prints ascending blocks
