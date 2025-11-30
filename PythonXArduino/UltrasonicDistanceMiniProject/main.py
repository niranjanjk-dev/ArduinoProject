from Reduino import target
from Reduino.Sensors import Ultrasonic
from Reduino.Actuators import Led, Buzzer



ultrasonicSensor=Ultrasonic(trig=6,echo=7)
redLed=Led(4)
orangeLed=Led(3)
greenLed=Led(2)
buzzer=Buzzer(9)

target("/dev/ttyUSB0")

while True:
    distance=ultrasonicSensor.measure_distance()
    
    if distance<10:
        redLed.set_brightness(255)
        greenLed.set_brightness(0)
        orangeLed.set_brightness(0)
        buzzer.melody("notify")

    elif distance>10 and distance<40:
        redLed.set_brightness(0)
        greenLed.set_brightness(0)
        orangeLed.set_brightness(255)
        

    else:
        orangeLed.set_brightness(0)
        redLed.set_brightness(0)
        greenLed.set_brightness(255)