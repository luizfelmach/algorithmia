from sys import stdin

lastVel = 0
lastQuery = 0
tot = 0

for line in stdin:
    l = line.replace("\n", "").split(" ")


    if (len(l) == 1):
        h, m, s = l[0].split(":")
        h, m, s = int(h), int(m), int(s)
        query = h + m/60 + s/3600
        tot += lastVel * (query - lastQuery)
        lastQuery = query
        print(f"{l[0]} {tot:.2f} km")

    else:
        h, m, s = l[0].split(":")
        h, m, s = int(h), int(m), int(s)
        vel = int(l[1])
        newQuery = h + m/60 + s/3600
        tot += lastVel * (newQuery - lastQuery)

        lastVel = vel
        lastQuery = newQuery
