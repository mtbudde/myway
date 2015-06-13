# Matthew Budde
# 6.12.15
# Simulation of the PID loop as it is currently.

target = 90
current = 94

kp = 2
ki = 3
kd = 2

intError = 0
lastError = 0
GUARD_GAIN = 20
K = 1

def constrain(n,  minn,  maxn):
    return max(min(maxn,  n),  minn)

for x in range(0,  100):
    error = target - current
    p = kp * error
    intError += error
    i = ki * constrain(error,  -GUARD_GAIN,  GUARD_GAIN)
    d = kd * (error - lastError)
    lastError = error
    print -constrain(K * (p + i + d),  -127,  127)
