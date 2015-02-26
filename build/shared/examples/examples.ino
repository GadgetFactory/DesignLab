/*
OVERVIEW
Thank you for using the Papilio DesignLab IDE! This is the one place to go for all of your Papilio needs.

Use this system to Draw and Debug circuits for your FPGA without learning VHDL! 
Use the included schematic library to draw circuits with basic building blocks such as logic gates, shifters, multiplexers, and more. 
Or get higher level and design circuits with Soft Processors and peripherals such as UARTs, audio chips, VGA adapters, and bit coin miners. 
Debug your circuits with the included Logic Analyzer and virtual instruments such as switches, buttons, LEDs, and seven segment displays.

Papilio DesignLab IDE brings all of the pieces of FPGA development together in one place making it easy to design FPGA circuits without becoming a VHDL guru. 

SETUP
If this is your first time using the Papilio ZAP IDE then please take some time to install Xilinx's ISE software and setup the environment.

LEARN
To discover new tutorials for DesignLab visit:
http://learn.gadgetfactory.net

USAGE
Start with any of the example projects linked below or create a new project with the Papilio/New Papilio Project menu.

When you have a project open you will see icons in the menu bar for loading a circuit, viewing the circuit, or editing the circuit.

If you want to use the circuit as it is then click on the icon to load the circuit to your Papilio FPGA board. 
If the circuit includes a soft processor then you can load the sketch to the soft processor by selecting the appropriate serial port and clicking upload.

If you want to make your own circuit or modify an existing circuit then click on the icon to modify the circuit. 
This will open up the project in Xilinx ISE and allow you to modify the schematic and synthesize a new bit file. 
After the bit file is updated you will have to click on the circuit icon to load the new bit file to your Papilio FPGA.

TROUBLESHOOTING
Visit the following website for common problems.
http://gadgetfactory.net/learn/2014/03/06/papilio-designlab-software-common-problems/

Or visit the Papilio Forums.
http://forum.gadgetfactory.net

TABLE OF CONTENTS FOR EXAMPLE PROJECTS

UTILITY PROJECTS
  Wishbone Slots
        This is a very useful sketch that shows what is connected to the ZPUino Wishbone Slots.
        example://Show_Wishbone_Devices/Show_Wishbone_Devices.ino
  

PAPILIO DUO PROJECTS
  QuickStart
	QuickStart Project - Try out the basic Papilio DUO functionality
        This is the project that comes pre-loaded on the Papilio DUO.
        It outputs the ASCII table on the FPGA serial port and flashes the LED's of any Button/LED Wing connected to any of the Wing Slots.
	example://Papilio_DUO_QuickStart/Papilio_DUO_QuickStart.ino

  GameDuino
        Use the GameDuino as VGA output for your circuits. The FPGA runs the GameDuino chip and the AVR runs the GameDuino sketches.
        For more examples look under File/Examples/Gameduino
	example://Gameduino/4.Demo/ball/ball.ino

  Computing Shield
        Computing Shield Verification - Check all functionality
        This is the project used at the factory to check that everything on the Computing Shield works.
        example://SHIELD_Computing_Shield/examples/Computing_Shield_Verification/Computing_Shield_Verification.ino
      
  LogicStart Shield
        Clock Divider Example - Divide a clock provided by AVR Chip
        This is a quick example of generating a 1Hz clock from the AVR chip and then dividing it and outputting the clock on the LEDs of the LogicStart Shield.
        example://Divider_Example/Divider_Example.ino
  
        LogicStart Shield LEDs Example - Control the LEDs from an AVR sketch
        This project uses a circuit on the FPGA to connect the output of unused AVR pins to the LED's of the LogicStart Shield.
        example://LogicStartShield_LEDs/LogicStartShield_LEDs.ino
        
        LogicStart Shield Verification - Check all functionality
        This is the project used at the factory to check that everything on the LogicStart Shield works.
        example://SHIELD_LogicStart_Shield/examples/LogicStart_Shield_Verification/LogicStart_Shield_Verification.ino
        
  AVR to Wishbone Bridge
        How to access Wishbone peripherals from the AVR.
        Go to File/Examples/AVR_Wishbone_Bridge
		
  ZPUino VGA Adapter
	This exciting VGA adapter lets you change resolutions on the fly and use the AdaFruit GFX library to program it. This is the latest and greatest VGA adapter.
	Go to File/Examples/ZPUino_VGA_Adapter
  
  Debugging
        AVR Dragon JTAG Debug - Debug the ATmega32U4 chip
        Use this circuit to connect the JTAG port of an AVR Dragon debugger to the Papilio DUO. You can use this to program and debug the ATmega32U4 using AVR Studio.
        Example Video included inside the sketch.
        example://Papilio_DUO_AVR_Dragon_Debug_JTAG/Papilio_DUO_AVR_Dragon_Debug_JTAG.ino
        
        AVR Dragon ISP Debug - Debug the ATmega32U4 chip
        Use this circuit to connect the ISP port of an AVR Dragon debugger to the Papilio DUO. You can use this to program and debug the ATmega32U4 using AVR Studio.
        Example Video included inside the sketch.
        example://Papilio_DUO_AVR_Dragon_Debug_SPI/Papilio_DUO_AVR_Dragon_Debug_SPI.ino
          
        HappyJTAG2 Software Debug - Debug the ATmega32U4 chip without any debugging hardware!
        Use this circuit to debug the ATmega32U4 using the HappyJTAG2 software debugger. No debugging hardware required!
        Example Video included inside the sketch.
        example://Papilio_DUO_happyjtag2/Papilio_DUO_happyjtag2.ino
          
HARDWARE
  Audio Wing
	Audio Project - Playing Amiga Mod Files
	Relive the glory days of the Amiga by playing those 16-bit Amiga Mod files on your Papilio. 
	This project uses a ZPUino Soft Processor with a wishbone audio passthrough hardware device connected to a delta-sigma DAC.
	There is a port of a small Amiga Mod player that runs on the ZPUino soft processor and generates audio data that is sent through the wishbone bus to the audio passthrough hardware.
	example://WING_Audio/examples/Audio_ModFile_simple/Audio_ModFile_simple.ino

	Audio Project - Commodore 64 SID
	Play those old Commodore 64 SID files or make a MIDI instrument with the Commodore 64 SID chip. 
	The VHDL model of the Commodore SID chip was created from a famous interview with Bob Yannes where he detailed the digital logic that was used to create the SID chip. 
	VHDL hackers were quick to jump on this information and recreate the SID chip with the exact same details of the original chip. 
	The exciting part is that the source code has the original interview in the comments, so you can go through the interview and see how the VHDL for what Bob Yannes described works. 
	A great learning tool indeed!
	No VHDL is required to use this chip though, its all schematic goodness. Just drop the chip onto a wishbone bus and use the included Arduino style libraries to drive it. This project shows you how.
	example://WING_Audio/examples/Audio_SID_simple/Audio_SID_simple.ino
	
	Audio Project - YM2149 Audio Chip
	Much like the Commodore project but with the YM2149 audio chip used in the Atari ST. There are tons of ym files out there and this chip and included libraries lets you play them all!
	example://WING_Audio/examples/Audio_YM2149_simple/Audio_YM2149_simple.ino
		  
  VGA Wing
	VGA Wing - Hello World
	This is a demo project that shows you how to use the 8 color VGA Wing.
	example://WING_VGA/examples/Hello_World/Hello_World.ino
  
	VGA Wing - Color Bar
	Draw a simple color bar on the 8 color VGA Wing.
	example://WING_VGA/examples/Color_Bar/Color_Bar.ino

	VGA Wing - Bricks Example
	An implementation of the Breakout game on the 8 color VGA Wing.
	example://WING_VGA/examples/Bricks_Example/Bricks_Example.ino
    
	VGA Wing - LCD Demo
	Implement a virtual LCD on the 8 color VGA Wing. This is an example of how easy it is to convert LiquidCrystal code to run on a virtual VGA LCD screen.
	example://WING_VGA/examples/LCD_Demo/LCD_Demo.ino
                
	VGA Wing - Space Invaders Demo
	An alien marches across a virtual LCD on the 8 color VGA Wing. This is an example of how easy it is to convert LiquidCrystal code to run on a virtual VGA LCD screen.
	example://WING_VGA/examples/spaceinvaders_simple/spaceinvaders_simple.ino
	
	ZPUino VGA Adapter
	This exciting VGA adapter lets you change resolutions on the fly and use the AdaFruit GFX library to program it. This is the latest and greatest VGA adapter.
	Go to File/Examples/ZPUino_VGA_Adapter	
    
  LogicStart MegaWing
	Hardware Project - LogicStart MegaWing 
	This is a demo project that shows you how to use draw a circuit that uses all of the LogicStart MegaWing components.
	example://MegaWing_Logicstart/MegaWing_Logicstart.ino

  Arcade MegaWing
	Hardware Project - Arcade MegaWing 
	This is a demo project that shows you how to use draw a circuit that uses all of the Arcade MegaWing components.
	example://MegaWing_Arcade/MegaWing_Arcade.ino

  Analog SPI Wing
	Hardware Project - Analog Wing 
	This is a demo project that shows you how to use draw a circuit to use the SPI ADC Analog Wing.
	example://WING_Analog/WING_Analog.ino	
	
  SD Card Wing
	Hardware Project - SD Card Wing 
	See examples of how to access a SD card in DesignLab
	Go to File/Examples/SD

ZPUINO SOFT PROCESSOR PROJECTS
  QuickStart Project - Try out the basic Papilio functionality
        This is the project that comes pre-loaded on the Papilio One and Papilio Pro boards.
        It outputs the ASCII table on the FPGA serial port and flashes the LED's of any Button/LED Wing connected to any of the Wing Slots.
	example://Papilio_QuickStart/Papilio_QuickStart.ino

  Audio Project - RetroCade Synth
	How about putting all of these audio chips together and putting them under MIDI control? That's what this project does, there is even a special MegaWing to provide high quality audio jacks, MIDI connnectors, and a Digital readout.
	example://Audio_RetroCade_Synth/Audio_RetroCade_Synth.ino
	
  Serial Ports Project
	A project with 9 serial ports all connected to the ZPUino at once.
	example://Multiple_Serial_Ports/Multiple_Serial_Ports.ino
	
  ZPUino Flex Pins
	The ZPUino lets you move certain pins, called Flex Pins, to any other pin on your Papilio board with a couple lines of code.
	This example sketch shows how Flex pins work.
	example://Flex_Pins/Flex_Pins.ino	
	
  Jet Set Willy
	Its the Jet Set Willy game recreated with the help of a ZXSpectrum VGA adapter.
	Go to File/Examples/VGA_ZXSpectrum

BENCHY DEBUGGING PROJECTS
  Waveform Generator
	Generate sin, cos, sawtooth, and square waves and control the frequency using a sketch.
	example://Benchy_Waveform_Generator/Benchy_Waveform_Generator.ino
	
  Stand Alone Logic Analyzer
	This is the "Sump" Logic Analyzer that is used in the Open Bench Logic Sniffer. Use this to make a standalone logic analyzer that is directly connected to the Papilio serial port. Sample at speeds up to 200Mhz!
	example://Benchy_Sump_LogicAnalyzer/Benchy_Sump_LogicAnalyzer.ino

  JTAG Logic Analyzer
	This is the "Sump" Logic Analyzer that is used in the Open Bench Logic Sniffer. This example uses the JTAG channel to communicate with your computer. 
	This allows you to debug your circuits without using the precious serial port. 
	Drop this into your circuit designs and probe your signals without impacting your design. Sample at speeds up to 200Mhz!
	example://Benchy_Sump_LogicAnalyzer_JTAG/Benchy_Sump_LogicAnalyzer_JTAG.ino
	
MISC PROJECTS
  Bitcoin Miner
        Go to File/Examples/BitCoin_Miner to get started mining your very own BitCoins on the Papilio.

*/