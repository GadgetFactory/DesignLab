DesignLab IDE - A modified version of the Arduino IDE for the Papilio FPGA board. 
previously name ZAP IDE

Arduino is an open-source physical computing platform based on a simple i/o
board and a development environment that implements the Processing/Wiring
language. Arduino can be used to develop stand-alone interactive objects or
can be connected to software on your computer (e.g. Flash, Processing, MaxMSP).
The boards can be assembled by hand or purchased preassembled; the open-source
IDE can be downloaded for free.

For more information, see the website at: http://www.arduino.cc/
or the forums at: http://arduino.cc/forum/

To report a bug in the software, go to:
http://github.com/arduino/Arduino/issues

For other suggestions, use the forum:
http://arduino.cc/forum/index.php/board,21.0.html

INSTALLATION
Detailed instructions are in reference/Guide_Windows.html and
reference/Guide_MacOSX.html.  For Linux, see the Arduino playground:
http://www.arduino.cc/playground/Learning/Linux

CREDITS
Arduino is an open source project, supported by many.

The Arduino team is composed of Massimo Banzi, David Cuartielles, Tom Igoe,
Gianluca Martino, Daniela Antonietti, and David A. Mellis.

Arduino uses the GNU avr-gcc toolchain, avrdude, avr-libc, and code from
Processing and Wiring.

Icon and about image designed by ToDo: http://www.todo.to.it/

DesignLab 1.0.3 - 2015.02.27
[zpuino]
Enabled DMA channels
Increase the memory address lines of Papilio DUO to support 2MB
Disable POSIX interface for Papilio One boards to save memory.
Allow new 2.0 libraries to specify the Wishbone slot using (Wishbone(1)).
Full malloc() support.

[ide]
Merged in the Arduino 1.5.8 code.
Serial ports are detected and labels are added to identify the type of board connected.
Warn if people forget to synthezie bit files.
Comment out #define circuit when saving a library.

[DesignLab Libraries]
New DMA VGA adapter with 16-bit color and dynamic resolution and uses AdaFruit_GFX library.
PNG and JPG libraries for use with the new VGA adapter.
Dynamic PLL library.
SD card library and examples.
FatFS for use with POSIX names and VGA adapter.
Dual DeltaSigma DAC library.
Basic Building Blocks library with Counters, bus taps, Dividers, etc.

DesignLab 1.0.1 - 2015.01.22
[zpuino]
Fixed boards.txt file for the Hyperion variant.

[DesignLab Libraries]
Fixed the Arcade MegaWing pullups.

DesignLab 1.0.0 - 2015.01.21
[ide]
*Fix symbols not closing properly.
*Check for comments before #define circuit statements

[designlab libraries]
*Separate Arcade MegaWing and LogicStart MegaWing circuits to their own libraries.
*Update Utility.sch with Papilio DUO IO connections.
*Add ZPUino Hyperion variant for Papilio One 500K.
*Added Pullups to the Arcade MegaWing Circuit.

DesignLab 0.2.1 - 2015.01.01
[ide]
*Digitally signed the drivers for easy install in Windows 8

ZAP 2.3.0 - 2014.3.25
[ide]
*Program bit files with the internal loader instead of loading externally.
*Made a table of contents for all projects that is loaded as the default sketch.
*Everything works in Linux now.
*There is a option in the preferences window to set location of adobe reader and ISE.
*AVR8 works under Linux now.
*Logic Analyzer client is in a shared location now.
*Papilio Loader is included in a shared location.
*Papilio menu is re-organized.
*New project option added to the Papilio menu.

ZAP 2.2.0 - 2014.1.30
[ide]
*Updates to make linux build work
*Copy entire contents of a sketch directory when doing a SaveAs

[Papilio Schematic Libary - Version 1.6]
-Moved libraries into sketch folder so sketches can be saved in any location
-JTAG Logic Analyzer Example
-Analog Wing Example
-Updated RetroCade Synth example with support for Analog readout

ZAP 2.1	- 2014.1.16
[ide]
* Allow clickable URLs in the sketch for bit files, ISE projects, and schematics.
* Add Papilio Menu
* Add Papilio Schematic Library 1.5

[zpuino]
* Fix missing Papilio Pro ID from bootloader/board type.
* Add SPI library
* Add SPIADC library
* Add SevenSegment Hardware library
* Update all libraries to allow selecting what wishbone slot to use.

ZAP 2.0.7 BETA - 2013.11.26

[zpuino]
* Updated audio libraries to allow specifying the wishbone slot. This is for Papilio Schematic Library.
* Removed ZPU 2.0, it was confusing people.

ZAP 2.0.6 BETA - 2013.10.16

[zpuino]
* Added all RetroCade libraries, YM2149, SID, YM2149 Player, SID Player, Modplayer

ZAP 2.0.5 BETA - 2013.07.17

[avr8]
* Ethercard library to support enc28J60 boards including the soon to come Ethernet Wing. Greg Samsa responded to the hacking challenge and made this library work with the Papilio.

ZAP 2.0.4 BETA - 2013.07.03

[avr8]
* BUG Fix: Compiling a sketch more then once would not result in updated code loaded to Papilio board. Makefile was updated to detect change to the hex file.

ZAP 2.0.3 BETA - 2013.06.26

[zpuino]
* Removed 2.0 interrupts from 1.0 code base.

ZAP 2.0.2 BETA - 2013.06.05

[zpuino]
* Fix for bootloader issue introduced in 2.0.1
* Fix for VGALiquidCrystal library

ZAP 2.0.1 BETA - 2013.06.04

[zpuino]
* Fix for missing Hyperion board type from VGA.h

ZAP 2.0.0 BETA - 2013.06.04

[zpuino]
* Added Hyperion variants for LogicStart and Arcade MegaWing board types
* Added bootloader functionality that associates bit files with each board type
* Libraries moved to ZPUino hardware type
* Experimental ZPUino 2.0 plugin added

