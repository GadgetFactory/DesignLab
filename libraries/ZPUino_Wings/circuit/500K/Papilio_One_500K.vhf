--------------------------------------------------------------------------------
-- Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.1
--  \   \         Application : sch2hdl
--  /   /         Filename : Papilio_One_500K.vhf
-- /___/   /\     Timestamp : 02/25/2015 17:41:32
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/AVR_Wishbone_Bridge -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Benchy -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/BitCoin_Miner -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Building_Blocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Clocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Gameduino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/HQVGA -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Papilio_Hardware -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZPUino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZXSpectrum -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_2 -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wishbone_Peripherals -intstyle ise -family spartan3e -flat -suppress -vhdl D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wings/circuit/500K/Papilio_One_500K.vhf -w D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wings/circuit/Papilio_One_500K.sch
--Design Name: Papilio_One_500K
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity Papilio_One_500K is
   port ( ext_pins_in    : in    std_logic_vector (100 downto 0); 
          ext_pins_out   : out   std_logic_vector (100 downto 0); 
          ext_pins_inout : inout std_logic_vector (100 downto 0); 
          WING_AH0       : inout std_logic; 
          WING_AH1       : inout std_logic; 
          WING_AH2       : inout std_logic; 
          WING_AH3       : inout std_logic; 
          WING_AH4       : inout std_logic; 
          WING_AH5       : inout std_logic; 
          WING_AH6       : inout std_logic; 
          WING_AH7       : inout std_logic; 
          WING_AL0       : inout std_logic; 
          WING_AL1       : inout std_logic; 
          WING_AL2       : inout std_logic; 
          WING_AL3       : inout std_logic; 
          WING_AL4       : inout std_logic; 
          WING_AL5       : inout std_logic; 
          WING_AL6       : inout std_logic; 
          WING_AL7       : inout std_logic; 
          WING_BH0       : inout std_logic; 
          WING_BH1       : inout std_logic; 
          WING_BH2       : inout std_logic; 
          WING_BH3       : inout std_logic; 
          WING_BH4       : inout std_logic; 
          WING_BH5       : inout std_logic; 
          WING_BH6       : inout std_logic; 
          WING_BH7       : inout std_logic; 
          WING_BL0       : inout std_logic; 
          WING_BL1       : inout std_logic; 
          WING_BL2       : inout std_logic; 
          WING_BL3       : inout std_logic; 
          WING_BL4       : inout std_logic; 
          WING_BL5       : inout std_logic; 
          WING_BL6       : inout std_logic; 
          WING_BL7       : inout std_logic; 
          WING_CH0       : inout std_logic; 
          WING_CH1       : inout std_logic; 
          WING_CH2       : inout std_logic; 
          WING_CH3       : inout std_logic; 
          WING_CH4       : inout std_logic; 
          WING_CH5       : inout std_logic; 
          WING_CH6       : inout std_logic; 
          WING_CH7       : inout std_logic; 
          WING_CL0       : inout std_logic; 
          WING_CL1       : inout std_logic; 
          WING_CL2       : inout std_logic; 
          WING_CL3       : inout std_logic; 
          WING_CL4       : inout std_logic; 
          WING_CL5       : inout std_logic; 
          WING_CL6       : inout std_logic; 
          WING_CL7       : inout std_logic);
end Papilio_One_500K;

architecture BEHAVIORAL of Papilio_One_500K is
   attribute BOX_TYPE   : string ;
   signal XLXN_329                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_330                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_331                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_332                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_335                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_336                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_408                                  : std_logic_vector (200 
         downto 0);
   signal XLXN_409                                  : std_logic_vector (200 
         downto 0);
   signal XLXN_450                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_451                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_452                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_453                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_454                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_455                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_456                                  : std_logic;
   signal XLXN_467                                  : std_logic_vector (17 
         downto 0);
   signal XLXN_468                                  : std_logic_vector (17 
         downto 0);
   signal XLXN_469                                  : std_logic_vector (17 
         downto 0);
   signal XLXN_472                                  : std_logic;
   signal XLXN_473                                  : std_logic;
   signal XLXN_486                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_487                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_521                                  : std_logic;
   signal XLXN_522                                  : std_logic;
   signal XLXN_530                                  : std_logic;
   signal XLXN_531                                  : std_logic;
   signal XLXN_536                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_537                                  : std_logic_vector (100 
         downto 0);
   signal XLXN_547                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_548                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_550                                  : std_logic;
   signal XLXN_551                                  : std_logic;
   signal XLXN_552                                  : std_logic;
   signal XLXN_553                                  : std_logic_vector (7 
         downto 0);
   signal XLXN_554                                  : std_logic_vector (7 
         downto 0);
   signal XLXI_38_Flex_Pin_out_0_openSignal         : std_logic;
   signal XLXI_38_Flex_Pin_out_1_openSignal         : std_logic;
   signal XLXI_38_Flex_Pin_out_2_openSignal         : std_logic;
   signal XLXI_38_Flex_Pin_out_3_openSignal         : std_logic;
   signal XLXI_38_Flex_Pin_out_4_openSignal         : std_logic;
   signal XLXI_38_Flex_Pin_out_5_openSignal         : std_logic;
   signal XLXI_73_wishbone_slot_video_in_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_73_wishbone_slot_9_out_openSignal    : std_logic_vector (100 
         downto 0);
   signal XLXI_73_wishbone_slot_10_out_openSignal   : std_logic_vector (100 
         downto 0);
   signal XLXI_73_wishbone_slot_11_out_openSignal   : std_logic_vector (100 
         downto 0);
   signal XLXI_73_wishbone_slot_13_out_openSignal   : std_logic_vector (100 
         downto 0);
   signal XLXI_73_wishbone_slot_14_out_openSignal   : std_logic_vector (100 
         downto 0);
   component Wing_GPIO
      port ( wt_miso : inout std_logic_vector (7 downto 0); 
             wt_mosi : inout std_logic_vector (7 downto 0));
   end component;
   
   component Papilio_Default_Wing_Pinout
      port ( WING_AH0         : inout std_logic; 
             WING_AH1         : inout std_logic; 
             WING_AH2         : inout std_logic; 
             WING_AH3         : inout std_logic; 
             WING_AH4         : inout std_logic; 
             WING_AH5         : inout std_logic; 
             WING_AH6         : inout std_logic; 
             WING_AH7         : inout std_logic; 
             WING_AL0         : inout std_logic; 
             WING_AL1         : inout std_logic; 
             WING_AL2         : inout std_logic; 
             WING_AL3         : inout std_logic; 
             WING_AL4         : inout std_logic; 
             WING_AL5         : inout std_logic; 
             WING_AL6         : inout std_logic; 
             WING_AL7         : inout std_logic; 
             WING_BH0         : inout std_logic; 
             WING_BH1         : inout std_logic; 
             WING_BH2         : inout std_logic; 
             WING_BH3         : inout std_logic; 
             WING_BH4         : inout std_logic; 
             WING_BH5         : inout std_logic; 
             WING_BH6         : inout std_logic; 
             WING_BH7         : inout std_logic; 
             WING_BL0         : inout std_logic; 
             WING_BL1         : inout std_logic; 
             WING_BL2         : inout std_logic; 
             WING_BL3         : inout std_logic; 
             WING_BL4         : inout std_logic; 
             WING_BL5         : inout std_logic; 
             WING_BL6         : inout std_logic; 
             WING_BL7         : inout std_logic; 
             WING_CL0         : inout std_logic; 
             WING_CL1         : inout std_logic; 
             WING_CL2         : inout std_logic; 
             WING_CL3         : inout std_logic; 
             WING_CL4         : inout std_logic; 
             WING_CL5         : inout std_logic; 
             WING_CL6         : inout std_logic; 
             WING_CL7         : inout std_logic; 
             WING_CH0         : inout std_logic; 
             WING_CH1         : inout std_logic; 
             WING_CH2         : inout std_logic; 
             WING_CH3         : inout std_logic; 
             WING_CH4         : inout std_logic; 
             WING_CH5         : inout std_logic; 
             WING_CH6         : inout std_logic; 
             WING_CH7         : inout std_logic; 
             gpio_bus_out     : in    std_logic_vector (200 downto 0); 
             gpio_bus_in      : out   std_logic_vector (200 downto 0); 
             WingType_miso_BH : inout std_logic_vector (7 downto 0); 
             WingType_miso_BL : inout std_logic_vector (7 downto 0); 
             WingType_miso_AH : inout std_logic_vector (7 downto 0); 
             WingType_mosi_BL : inout std_logic_vector (7 downto 0); 
             WingType_mosi_BH : inout std_logic_vector (7 downto 0); 
             WingType_mosi_CL : inout std_logic_vector (7 downto 0); 
             WingType_mosi_AH : inout std_logic_vector (7 downto 0); 
             WingType_miso_CL : inout std_logic_vector (7 downto 0); 
             WingType_miso_CH : inout std_logic_vector (7 downto 0); 
             WingType_mosi_CH : inout std_logic_vector (7 downto 0); 
             WingType_mosi_AL : inout std_logic_vector (7 downto 0); 
             WingType_miso_AL : inout std_logic_vector (7 downto 0); 
             Flex_Pin_out_0   : in    std_logic; 
             Flex_Pin_out_1   : in    std_logic; 
             Flex_Pin_out_2   : in    std_logic; 
             Flex_Pin_out_3   : in    std_logic; 
             Flex_Pin_out_4   : in    std_logic; 
             Flex_Pin_out_5   : in    std_logic; 
             Flex_Pin_in_0    : out   std_logic; 
             Flex_Pin_in_1    : out   std_logic; 
             Flex_Pin_in_2    : out   std_logic; 
             Flex_Pin_in_3    : out   std_logic; 
             Flex_Pin_in_4    : out   std_logic; 
             Flex_Pin_in_5    : out   std_logic);
   end component;
   
   component AUDIO_zpuino_wb_passthrough
      port ( raw_out      : out   std_logic_vector (17 downto 0); 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component AUDIO_zpuino_wb_YM2149
      port ( data_out     : out   std_logic_vector (17 downto 0); 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component AUDIO_zpuino_wb_sid6581
      port ( clk_1MHZ     : in    std_logic; 
             audio_data   : out   std_logic_vector (17 downto 0); 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component AUDIO_zpuino_sa_audiomixer
      port ( clk       : in    std_logic; 
             rst       : in    std_logic; 
             ena       : in    std_logic; 
             data_in1  : in    std_logic_vector (17 downto 0); 
             data_in2  : in    std_logic_vector (17 downto 0); 
             data_in3  : in    std_logic_vector (17 downto 0); 
             audio_out : out   std_logic);
   end component;
   
   component MISC_zpuino_sa_splitter2
      port ( in1  : in    std_logic; 
             out1 : out   std_logic; 
             out2 : out   std_logic);
   end component;
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component Wing_Audio
      port ( audio_left  : in    std_logic; 
             audio_right : in    std_logic; 
             wt_miso     : inout std_logic_vector (7 downto 0); 
             wt_mosi     : inout std_logic_vector (7 downto 0));
   end component;
   
   component COMM_zpuino_wb_SPI
      port ( miso         : in    std_logic; 
             sck          : out   std_logic; 
             mosi         : out   std_logic; 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component Wing_SDCard
      port ( wt_miso : inout std_logic_vector (7 downto 0); 
             wt_mosi : inout std_logic_vector (7 downto 0); 
             sck     : in    std_logic; 
             mosi    : in    std_logic; 
             miso    : out   std_logic);
   end component;
   
   component ZPUino_Papilio_One_500K_V2
      port ( clk_96Mhz               : out   std_logic; 
             clk_1Mhz                : out   std_logic; 
             clk_osc_32Mhz           : out   std_logic; 
             ext_pins_in             : in    std_logic_vector (100 downto 0); 
             ext_pins_out            : out   std_logic_vector (100 downto 0); 
             ext_pins_inout          : inout std_logic_vector (100 downto 0); 
             gpio_bus_out            : out   std_logic_vector (200 downto 0); 
             gpio_bus_in             : in    std_logic_vector (200 downto 0); 
             wishbone_slot_5_out     : in    std_logic_vector (100 downto 0); 
             wishbone_slot_5_in      : out   std_logic_vector (100 downto 0); 
             wishbone_slot_6_in      : out   std_logic_vector (100 downto 0); 
             wishbone_slot_6_out     : in    std_logic_vector (100 downto 0); 
             wishbone_slot_8_in      : out   std_logic_vector (100 downto 0); 
             wishbone_slot_8_out     : in    std_logic_vector (100 downto 0); 
             wishbone_slot_9_in      : out   std_logic_vector (100 downto 0); 
             wishbone_slot_9_out     : in    std_logic_vector (100 downto 0); 
             wishbone_slot_10_in     : out   std_logic_vector (100 downto 0); 
             wishbone_slot_10_out    : in    std_logic_vector (100 downto 0); 
             wishbone_slot_11_in     : out   std_logic_vector (100 downto 0); 
             wishbone_slot_11_out    : in    std_logic_vector (100 downto 0); 
             wishbone_slot_12_in     : out   std_logic_vector (100 downto 0); 
             wishbone_slot_12_out    : in    std_logic_vector (100 downto 0); 
             wishbone_slot_13_in     : out   std_logic_vector (100 downto 0); 
             wishbone_slot_13_out    : in    std_logic_vector (100 downto 0); 
             wishbone_slot_14_in     : out   std_logic_vector (100 downto 0); 
             wishbone_slot_14_out    : in    std_logic_vector (100 downto 0); 
             wishbone_slot_video_in  : in    std_logic_vector (100 downto 0); 
             wishbone_slot_video_out : out   std_logic_vector (100 downto 0); 
             vgaclkout               : out   std_logic);
   end component;
   
begin
   XLXI_24 : Wing_GPIO
      port map (wt_miso(7 downto 0)=>XLXN_329(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_330(7 downto 0));
   
   XLXI_25 : Wing_GPIO
      port map (wt_miso(7 downto 0)=>XLXN_331(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_332(7 downto 0));
   
   XLXI_27 : Wing_GPIO
      port map (wt_miso(7 downto 0)=>XLXN_335(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_336(7 downto 0));
   
   XLXI_38 : Papilio_Default_Wing_Pinout
      port map (Flex_Pin_out_0=>XLXI_38_Flex_Pin_out_0_openSignal,
                Flex_Pin_out_1=>XLXI_38_Flex_Pin_out_1_openSignal,
                Flex_Pin_out_2=>XLXI_38_Flex_Pin_out_2_openSignal,
                Flex_Pin_out_3=>XLXI_38_Flex_Pin_out_3_openSignal,
                Flex_Pin_out_4=>XLXI_38_Flex_Pin_out_4_openSignal,
                Flex_Pin_out_5=>XLXI_38_Flex_Pin_out_5_openSignal,
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                Flex_Pin_in_0=>open,
                Flex_Pin_in_1=>open,
                Flex_Pin_in_2=>open,
                Flex_Pin_in_3=>open,
                Flex_Pin_in_4=>open,
                Flex_Pin_in_5=>open,
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                WingType_miso_AH(7 downto 0)=>XLXN_553(7 downto 0),
                WingType_miso_AL(7 downto 0)=>XLXN_335(7 downto 0),
                WingType_miso_BH(7 downto 0)=>XLXN_329(7 downto 0),
                WingType_miso_BL(7 downto 0)=>XLXN_331(7 downto 0),
                WingType_miso_CH(7 downto 0)=>XLXN_486(7 downto 0),
                WingType_miso_CL(7 downto 0)=>XLXN_547(7 downto 0),
                WingType_mosi_AH(7 downto 0)=>XLXN_554(7 downto 0),
                WingType_mosi_AL(7 downto 0)=>XLXN_336(7 downto 0),
                WingType_mosi_BH(7 downto 0)=>XLXN_330(7 downto 0),
                WingType_mosi_BL(7 downto 0)=>XLXN_332(7 downto 0),
                WingType_mosi_CH(7 downto 0)=>XLXN_487(7 downto 0),
                WingType_mosi_CL(7 downto 0)=>XLXN_548(7 downto 0),
                WING_AH0=>WING_AH0,
                WING_AH1=>WING_AH1,
                WING_AH2=>WING_AH2,
                WING_AH3=>WING_AH3,
                WING_AH4=>WING_AH4,
                WING_AH5=>WING_AH5,
                WING_AH6=>WING_AH6,
                WING_AH7=>WING_AH7,
                WING_AL0=>WING_AL0,
                WING_AL1=>WING_AL1,
                WING_AL2=>WING_AL2,
                WING_AL3=>WING_AL3,
                WING_AL4=>WING_AL4,
                WING_AL5=>WING_AL5,
                WING_AL6=>WING_AL6,
                WING_AL7=>WING_AL7,
                WING_BH0=>WING_BH0,
                WING_BH1=>WING_BH1,
                WING_BH2=>WING_BH2,
                WING_BH3=>WING_BH3,
                WING_BH4=>WING_BH4,
                WING_BH5=>WING_BH5,
                WING_BH6=>WING_BH6,
                WING_BH7=>WING_BH7,
                WING_BL0=>WING_BL0,
                WING_BL1=>WING_BL1,
                WING_BL2=>WING_BL2,
                WING_BL3=>WING_BL3,
                WING_BL4=>WING_BL4,
                WING_BL5=>WING_BL5,
                WING_BL6=>WING_BL6,
                WING_BL7=>WING_BL7,
                WING_CH0=>WING_CH0,
                WING_CH1=>WING_CH1,
                WING_CH2=>WING_CH2,
                WING_CH3=>WING_CH3,
                WING_CH4=>WING_CH4,
                WING_CH5=>WING_CH5,
                WING_CH6=>WING_CH6,
                WING_CH7=>WING_CH7,
                WING_CL0=>WING_CL0,
                WING_CL1=>WING_CL1,
                WING_CL2=>WING_CL2,
                WING_CL3=>WING_CL3,
                WING_CL4=>WING_CL4,
                WING_CL5=>WING_CL5,
                WING_CL6=>WING_CL6,
                WING_CL7=>WING_CL7);
   
   XLXI_42 : AUDIO_zpuino_wb_passthrough
      port map (wishbone_in(100 downto 0)=>XLXN_450(100 downto 0),
                raw_out(17 downto 0)=>XLXN_467(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_451(100 downto 0));
   
   XLXI_43 : AUDIO_zpuino_wb_YM2149
      port map (wishbone_in(100 downto 0)=>XLXN_452(100 downto 0),
                data_out(17 downto 0)=>XLXN_468(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_453(100 downto 0));
   
   XLXI_44 : AUDIO_zpuino_wb_sid6581
      port map (clk_1MHZ=>XLXN_530,
                wishbone_in(100 downto 0)=>XLXN_454(100 downto 0),
                audio_data(17 downto 0)=>XLXN_469(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_455(100 downto 0));
   
   XLXI_52 : AUDIO_zpuino_sa_audiomixer
      port map (clk=>XLXN_531,
                data_in1(17 downto 0)=>XLXN_469(17 downto 0),
                data_in2(17 downto 0)=>XLXN_468(17 downto 0),
                data_in3(17 downto 0)=>XLXN_467(17 downto 0),
                ena=>XLXN_472,
                rst=>XLXN_473,
                audio_out=>XLXN_456);
   
   XLXI_53 : MISC_zpuino_sa_splitter2
      port map (in1=>XLXN_456,
                out1=>XLXN_521,
                out2=>XLXN_522);
   
   XLXI_60 : VCC
      port map (P=>XLXN_472);
   
   XLXI_61 : GND
      port map (G=>XLXN_473);
   
   XLXI_68 : Wing_Audio
      port map (audio_left=>XLXN_521,
                audio_right=>XLXN_522,
                wt_miso(7 downto 0)=>XLXN_486(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_487(7 downto 0));
   
   XLXI_70 : COMM_zpuino_wb_SPI
      port map (miso=>XLXN_552,
                wishbone_in(100 downto 0)=>XLXN_536(100 downto 0),
                mosi=>XLXN_551,
                sck=>XLXN_550,
                wishbone_out(100 downto 0)=>XLXN_537(100 downto 0));
   
   XLXI_72 : Wing_SDCard
      port map (mosi=>XLXN_551,
                sck=>XLXN_550,
                miso=>XLXN_552,
                wt_miso(7 downto 0)=>XLXN_547(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_548(7 downto 0));
   
   XLXI_73 : ZPUino_Papilio_One_500K_V2
      port map (ext_pins_in(100 downto 0)=>ext_pins_in(100 downto 0),
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                wishbone_slot_video_in(100 downto 
            0)=>XLXI_73_wishbone_slot_video_in_openSignal(100 downto 0),
                wishbone_slot_5_out(100 downto 0)=>XLXN_451(100 downto 0),
                wishbone_slot_6_out(100 downto 0)=>XLXN_453(100 downto 0),
                wishbone_slot_8_out(100 downto 0)=>XLXN_455(100 downto 0),
                wishbone_slot_9_out(100 downto 
            0)=>XLXI_73_wishbone_slot_9_out_openSignal(100 downto 0),
                wishbone_slot_10_out(100 downto 
            0)=>XLXI_73_wishbone_slot_10_out_openSignal(100 downto 0),
                wishbone_slot_11_out(100 downto 
            0)=>XLXI_73_wishbone_slot_11_out_openSignal(100 downto 0),
                wishbone_slot_12_out(100 downto 0)=>XLXN_537(100 downto 0),
                wishbone_slot_13_out(100 downto 
            0)=>XLXI_73_wishbone_slot_13_out_openSignal(100 downto 0),
                wishbone_slot_14_out(100 downto 
            0)=>XLXI_73_wishbone_slot_14_out_openSignal(100 downto 0),
                clk_osc_32Mhz=>open,
                clk_1Mhz=>XLXN_530,
                clk_96Mhz=>XLXN_531,
                ext_pins_out(100 downto 0)=>ext_pins_out(100 downto 0),
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                vgaclkout=>open,
                wishbone_slot_video_out=>open,
                wishbone_slot_5_in(100 downto 0)=>XLXN_450(100 downto 0),
                wishbone_slot_6_in(100 downto 0)=>XLXN_452(100 downto 0),
                wishbone_slot_8_in(100 downto 0)=>XLXN_454(100 downto 0),
                wishbone_slot_9_in=>open,
                wishbone_slot_10_in=>open,
                wishbone_slot_11_in=>open,
                wishbone_slot_12_in(100 downto 0)=>XLXN_536(100 downto 0),
                wishbone_slot_13_in=>open,
                wishbone_slot_14_in=>open,
                ext_pins_inout(100 downto 0)=>ext_pins_inout(100 downto 0));
   
   XLXI_74 : Wing_GPIO
      port map (wt_miso(7 downto 0)=>XLXN_553(7 downto 0),
                wt_mosi(7 downto 0)=>XLXN_554(7 downto 0));
   
end BEHAVIORAL;


