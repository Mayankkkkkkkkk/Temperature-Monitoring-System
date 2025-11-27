import serial
import time

port = "COM3"
baud = 9600

ser = serial.Serial(port, baud, timeout=1)
time.sleep(2)

print("Reading temperature...\n")

while True:
    if ser.in_waiting:
        temp = ser.read().decode(errors="ignore")
        if temp.isdigit():
            print(f"Temperature: {temp} °C")
    time.sleep(0.2)
