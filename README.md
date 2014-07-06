uselesspentabox
===============
A useless box with moody behaviour.

### What is it?

Well, basically it is just a pimped [The Most Useless Machine "Leave Me Alone" Box](http://www.fablabshop.de/anleitunguseless) from [Fab Lab Shop](http://www.fablabshop.de).

### Why is it special?
It's less predictable than the original and shows a variety of different behaviours.

I ignored probably all  of the original instructions for wiring things up and built only the mechanical part according to the original building instructions. Instead of dismantling the servo and making it just run forward or backward (or not at all) depending on the position of the switches, the servo is left intact and a microcontroller is used to control the servo with a PWM signal.

This allows for more variable and precise movements of the arm for switching the main switch off again, and greatly enchances the capability to make the box express different behaviours (or degrees of annoyance about beeing disturbed).

### How?
A defective [pentabug](https://github.com/c3d2/pentabug) PCB has been recycled for this box but the circuit contains only a few components and can be easily build on some PCB prototyping board.

### Hardware

Nearly all the hardware I've got as a bithday present from my most valued colleagues. It comes as a laser cutted [kit]](http://www.fablabshop.de/anleitunguseless) from [Fab Lab Shop](http://www.fablabshop.de). Unfortunately the hinges were broken on arrival.

![it's b0rken!](https://raw.github.com/alxlo/uselesspentabox/master/images/hinges.jpg)

But there is (nearly) nothing you can't fix with some good old methyl acrylate glue. However, I believe this is some design flaw the people at FabLab should improve on.

### How to get things to work

#### Get your toolchain ready

Well, it's just a plain avr gcc toolchain for hacking with atmel microcontrollers:
'''
sudo apt-get install avr-libc binutils-avr gcc-avr avrdude avarice gdb-avr
'''

As we always stumble about this, here is how we make the UsbTinyISP programmer available for non-root using UDEV-Rules:

Create a file `/etc/udev/rules.d/41-usbtiny.rules` and add the line
'''
SUBSYSTEM=="usb", ATTR{idVendor}=="1781", ATTR{idProduct}=="0c9f", GROUP="plugdev", MODE="0666"
'''
Finally set permissions and restart udev
'''
sudo chmod a+r /etc/udev/rules.d/41-usbtiny.rules
sudo restart udev
'''

### Work in progress

These are just some notes and should be considered as a dump of scribbles and snippets that wait to be authored into something more meaningfull for other people.


#### servo wiring and signaling

brown - ground

red   - VCC+

yellow  - signal

PWM timing: http://www.mikrocontroller.net/articles/Modellbauservo_Ansteuerung


#### What Ports

To make use of the 16bit Timer1 for PWM, we connect the servo to PB2 (=OC1B) which is accidentialy availabe on an extension jumper on the Pentabug PCB and just amazingly convenient for that purpose.

