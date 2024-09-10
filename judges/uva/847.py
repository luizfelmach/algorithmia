from sys import stdin

for line in stdin:
    a =  9
    prev = 1
    cur = [9, 2]
    ganhou = True

    n = int(line)

    for i in range(1, 20):
        # print(f"{prev}-{a} {ganhou}")
        if (n >= prev and n <= a):
            if (ganhou):
                print("Stan wins.")
            else:
                print("Ollie wins.")
            break

        top = cur.pop()
        ganhou = not ganhou
        prev = a
        a  *= top
        cur.insert(0, top)
