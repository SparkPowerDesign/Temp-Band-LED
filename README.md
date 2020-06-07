# Body temperature monitoring wrist band device with an LED indicator.
A simple body temperature monitoring device based on the Attiny85 and the MAX30205 body tempreture monitoring chip, with a 3 state LED Indicator.

The included lib from ClosedCube for the MAX30205 includes very minor changes to be compatible with TinyWire.

Written in C and for use with the Aurdino IDE.

Please Note:
The readings from the MAX30205 are subject to skin contact location and duration of contact with the human body. Thresholds for LED states based on readings will need to be tweaked in the code to get an accurate LED indication of normal/fever body temp. The MAX30205, although being clinicly rated for body temp, doesnt read temps. does not always read temperatures exactly because of body placment and the placment of the chip itself on the pcb its mounted to. This is why the temp in C for the code doesnt match up with actual body temp thresholds for normal/fever. Needs tweaking/expermination on placement.
