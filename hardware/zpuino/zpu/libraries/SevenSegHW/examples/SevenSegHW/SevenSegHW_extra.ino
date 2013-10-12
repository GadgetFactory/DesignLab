/*
  Gadget Factory
  Seven Segment Hardware Example
  
 Requires a ZPUino bit file with the Seven Segment Core connected to a Wishbone slot
 
 Wiki Page:
 http://www.papilio.cc/index.php?n=Papilio.7Segment-Core-Walid
 
 Hardware:
 There is no pre-built bit file/board type in the ZAP IDE that contains a Seven Segment Core. You will have to synthesize our own for now. The Seven Segment Core VHDL can be found here:
 https://github.com/GadgetFactory/Papilio-SOC/blob/master/zpu/hdl/zpuino/zpuino_sevenseg.vhd
 If using LogicStart MegaWing then select the appropriate "To be determined" board type in the ZAP IDE.
 
 ZPUino Variant:
 There is no pre-built bit file/board type in the ZAP IDE that contains a Seven Segment Core. You will have to synthesize our own for now. The Seven Segment Core VHDL can be found here:
 https://github.com/GadgetFactory/Papilio-SOC/blob/master/zpu/hdl/zpuino/zpuino_sevenseg.vhd

 created 2013
 by Walid Youssef
 http://www.gadgetfactory.net
 
 This example code is in the public domain.
 */

#include <SevenSegHW.h>

SEVENSEGHW sevenseg;

void setup () {
  // set base address :
  sevenseg.begin (IO_SLOT(9));
}

void loop () {

    // Testing simple read/write acces to registers
    for (int i = 0; i< 65535; i++)
    {
      // Simply write the i value
      sevenseg.setExtra (i);
      sevenseg.setIntValue(i,0);
      sevenseg.getExtra ;
      delay (2000);
    }


}
