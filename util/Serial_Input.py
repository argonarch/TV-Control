import serial

S = serial.Serial('/dev/tty/USB0', 9600, timeout=1)

S.write("Hello")
print(S.readline())
