# Overview

This repo contains the software for a timer that is used for dribbling excercises in soccer. The idea is simple: you place the ball in front of the device, turn the device on, and when it detects the ball has been moved from its place, it starts a timer. The timer stops when the ball is detected once again. The device can be programmed to wait until the nth detection before turning off the timer. This is useful if, say, the user wants to time how long it takes for them to run to the end of the field and back 10 times. When n is set to 10, it won't stop the timer until it detects the ball in front of it for the 10th time. 

Parts: Arduino Uno R3, ultransonic sensor, several 7-seg displays and a couple of buttons. 

# How It Works:
The ultrasonic sensor detects if an object) is within a certain distance from it. When it detects there is no longer an object in front of it, it begins the timer. There is a 3 second buffer before it begins detecting for the ball again. This is done so that it does not accidently register the players legs as a ball. The time is shown on 7-seg displays, and the buttons are used to program the number of ball blocks it must count before stopping the timer. 
