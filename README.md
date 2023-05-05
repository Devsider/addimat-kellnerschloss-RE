# addimat-kellnerschloss-RE


I Reverse-Engineered the Working Priciple of the ["Addimat Kellnerschlösser"](https://direct.karley.de/kellnerschloss/addimat_kellnerschloss_usb_2_schwarz_mit_05m_kabel) used in Restaurants.

The Original Device costs around 130€. I thorught that they can't be that expensive to make. 5€ Later i made one myself.

## Original Device
The original set is a "Key" - a stick with 2 contacts and a reading device which plugs in via USB. 

![image of reading device](https://kassen.net/images/product_images/original_images/Addimat-Kellnerschloss-USB.jpg)
![image of key](https://kassen-store.de/images/product_images/info_images/adimat_2.jpg)
![image of both together](https://net-dream.de/images/product_images/info_images/addimat_kellnerschloss_2.jpg)

## The Key
Simple Key - No Battery - 2 Contacts

First thing that came to my mind was OneWire, a protocol used to get sensor data using only 2! wires. Data and Power is transfered over the same wire.

## Tesing
I tried the Arduino Example DS18S20 OneWire Temperature Chip Reading Sketch.
It spit out the following:
```
R=1 7A 23 55 16 0 0 9B Device family is not recognized: 0x1
```

The Value After "R=" Changed depending on the key. 
Next problem, the Original Reader Spit out something like:
```
9B00002645697A01OUT
```

so, i wrote code to convert it!

Now, the Arduino Acts exactly like the original Reader does, but for 5€ and not 130€ :)

## Arduino Circuit
I used an Arduino / ESP8266 to test.

D1 / Pin 5 gets Connected to A 4.7k resistor which gets connected to 5V.
The D1 Pin also gets COnnected to the Side Metal of the Key.

GND of the Arduino gets connected to the Tip of the Key.


```
    D1-----------------------------------.  SIDE OF KEY
         |                               |
        .|.                              |
        | | 4.7k                         |
        | |                        .-----o----------------.
        '-'                      .-.                      |
         |     .-----------------' |                      |
    5V---'     |                 '-'                      |
               |      TIP OF KEY   '----------------------'
               |
               |
               |
               |
   GND --------
```
(created by AACircuit v1.28.7 beta 10/23/16 www.tech-chat.de)

## The Code

I coded it to behave as close to the original Reader as Possible, so it should be intercompatible without any issue.
I did not recreate the "Keyboard" mode of the original device. If someone wants to add that, please create a pull request. 
(Pretty easily doable with a keyboard emulating arduino (ATMega32U4 chip arduinos, ...)


## Recreating Reader Houseing

Could be Remodeled in 3D and then 3D Printed. 
The "Key Hole" is just a magnet, a plastic spacer and a metal washer with wires stuck in between to create contact. Really simple construction.

## All documents and code are presented "as seen" and without warranty of any kind. 
### For help, feel free to open a Issue. 
