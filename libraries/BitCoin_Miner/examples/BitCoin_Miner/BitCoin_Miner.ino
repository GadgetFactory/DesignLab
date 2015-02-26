/*
 Gadget Factory
 Run a bit coin Miner on your Papilio DUO or Papilio Pro

 To use this sketch do the following steps:
  1) You need to have python installed on your system
  2) Join the mining pool at http://mining.bitcoin.cz (This example is setup to use a Gadget Factory test account so you can skip this step if you just want to test.)
  3) Start the stratum proxy.
    Windows: sketchdir://mining_proxy.exe
    Linux: Follow directions at http://mining.bitcoin.cz/mining-proxy-hotwo
  4) Load the circuit to your Papilio board.
  5) Start the mining python script
    a) Open the sketch folder using CTL-K
    b) From a command line do: "python miner.py --serial COM1" substituting your Com port.
  
 Hardware:
   This example circuit will work with the Papilio DUO or the Papilio Pro with or without the LogicStart Shield or Logicstart MegaWing connected.
   If the LogicStart Sheild/MegaWing is connected then the following features are enabled:
   1) LED0 and LED1 are connected to RX and TX
   2) Whenever a block is found the Seven Segment Display will light up. It will chang patterns as new blocks are found.
   3) SW0 will turn off the display to conserver power. Up is on, down is off.
 

 Tutorials:
   http://learn.gadgetfactory.net
  

 created 2014
 by Jack Gassett
 http://www.gadgetfactory.net
 
 There is no code for this project.
 */
#define circuit BitCoin_Miner


