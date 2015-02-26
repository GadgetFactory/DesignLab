--------------------------------------------------------------------------------
-- Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.1
--  \   \         Application : sch2hdl
--  /   /         Filename : Papilio_Pro.vhf
-- /___/   /\     Timestamp : 02/26/2015 14:24:52
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/AVR_Wishbone_Bridge -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Benchy -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/BitCoin_Miner -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Building_Blocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Clocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Gameduino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/HQVGA -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Papilio_Hardware -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZPUino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZXSpectrum -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_2 -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wishbone_Peripherals -intstyle ise -family spartan6 -flat -suppress -vhdl D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Arcade_MegaWing2/circuit/LX9/Papilio_Pro.vhf -w D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Arcade_MegaWing2/circuit/Papilio_Pro.sch
--Design Name: Papilio_Pro
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity Papilio_Pro is
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
end Papilio_Pro;

architecture BEHAVIORAL of Papilio_Pro is
   attribute BOX_TYPE   : string ;
   signal XLXN_408                                : std_logic_vector (200 
         downto 0);
   signal XLXN_450                                : std_logic_vector (100 
         downto 0);
   signal XLXN_451                                : std_logic_vector (100 
         downto 0);
   signal XLXN_452                                : std_logic_vector (100 
         downto 0);
   signal XLXN_453                                : std_logic_vector (100 
         downto 0);
   signal XLXN_454                                : std_logic_vector (100 
         downto 0);
   signal XLXN_455                                : std_logic_vector (100 
         downto 0);
   signal XLXN_456                                : std_logic;
   signal XLXN_467                                : std_logic_vector (17 downto 
         0);
   signal XLXN_468                                : std_logic_vector (17 downto 
         0);
   signal XLXN_469                                : std_logic_vector (17 downto 
         0);
   signal XLXN_472                                : std_logic;
   signal XLXN_473                                : std_logic;
   signal XLXN_530                                : std_logic;
   signal XLXN_531                                : std_logic;
   signal XLXN_532                                : std_logic;
   signal XLXN_533                                : std_logic;
   signal XLXN_549                                : std_logic_vector (200 
         downto 0);
   signal XLXN_554                                : std_logic_vector (32 downto 
         0);
   signal XLXN_555                                : std_logic_vector (100 
         downto 0);
   signal XLXN_556                                : std_logic_vector (100 
         downto 0);
   signal XLXN_557                                : std_logic_vector (100 
         downto 0);
   signal XLXN_558                                : std_logic_vector (100 
         downto 0);
   signal XLXI_39_wishbone_slot_9_out_openSignal  : std_logic_vector (100 
         downto 0);
   signal XLXI_39_wishbone_slot_10_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_39_wishbone_slot_11_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_39_wishbone_slot_12_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_39_wishbone_slot_13_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_69_VGA_Blue0_openSignal            : std_logic;
   signal XLXI_69_VGA_Blue1_openSignal            : std_logic;
   signal XLXI_69_VGA_Blue2_openSignal            : std_logic;
   signal XLXI_69_VGA_Blue3_openSignal            : std_logic;
   signal XLXI_69_VGA_Green0_openSignal           : std_logic;
   signal XLXI_69_VGA_Green1_openSignal           : std_logic;
   signal XLXI_69_VGA_Green2_openSignal           : std_logic;
   signal XLXI_69_VGA_Green3_openSignal           : std_logic;
   signal XLXI_69_VGA_Hsync_openSignal            : std_logic;
   signal XLXI_69_VGA_Red0_openSignal             : std_logic;
   signal XLXI_69_VGA_Red1_openSignal             : std_logic;
   signal XLXI_69_VGA_Red2_openSignal             : std_logic;
   signal XLXI_69_VGA_Red3_openSignal             : std_logic;
   signal XLXI_69_VGA_Vsync_openSignal            : std_logic;
   component ZPUino_Papilio_Pro_V2
      port ( gpio_bus_out            : out   std_logic_vector (200 downto 0); 
             gpio_bus_in             : in    std_logic_vector (200 downto 0); 
             clk_96Mhz               : out   std_logic; 
             clk_1Mhz                : out   std_logic; 
             clk_osc_32Mhz           : out   std_logic; 
             ext_pins_in             : in    std_logic_vector (100 downto 0); 
             ext_pins_out            : out   std_logic_vector (100 downto 0); 
             ext_pins_inout          : inout std_logic_vector (100 downto 0); 
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
             wishbone_slot_video_out : out   std_logic_vector (100 downto 0));
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
   
   component Arcade_MegaWing_Pinout
      port ( gpio_bus_out : in    std_logic_vector (200 downto 0); 
             gpio_bus_in  : out   std_logic_vector (200 downto 0); 
             WING_AL0     : inout std_logic; 
             WING_AL1     : inout std_logic; 
             WING_AL2     : inout std_logic; 
             WING_AL3     : inout std_logic; 
             WING_AL4     : inout std_logic; 
             WING_AL5     : inout std_logic; 
             WING_AL6     : inout std_logic; 
             WING_AL7     : inout std_logic; 
             WING_AH0     : inout std_logic; 
             WING_AH1     : inout std_logic; 
             WING_AH2     : inout std_logic; 
             WING_AH3     : inout std_logic; 
             WING_AH4     : inout std_logic; 
             WING_AH5     : inout std_logic; 
             WING_AH6     : inout std_logic; 
             WING_AH7     : inout std_logic; 
             WING_BL0     : inout std_logic; 
             WING_BL1     : inout std_logic; 
             WING_BL2     : inout std_logic; 
             WING_BL3     : inout std_logic; 
             WING_BL4     : inout std_logic; 
             WING_BL5     : inout std_logic; 
             WING_BL6     : inout std_logic; 
             WING_BL7     : inout std_logic; 
             WING_BH0     : inout std_logic; 
             WING_BH1     : inout std_logic; 
             WING_BH2     : inout std_logic; 
             WING_BH3     : inout std_logic; 
             WING_BH4     : inout std_logic; 
             WING_BH5     : inout std_logic; 
             WING_BH6     : inout std_logic; 
             WING_BH7     : inout std_logic; 
             WING_CL0     : inout std_logic; 
             WING_CL1     : inout std_logic; 
             WING_CL2     : inout std_logic; 
             WING_CL3     : inout std_logic; 
             WING_CL4     : inout std_logic; 
             WING_CL5     : inout std_logic; 
             WING_CL6     : inout std_logic; 
             WING_CL7     : inout std_logic; 
             WING_CH0     : inout std_logic; 
             WING_CH1     : inout std_logic; 
             WING_CH2     : inout std_logic; 
             WING_CH3     : inout std_logic; 
             WING_CH4     : inout std_logic; 
             WING_CH5     : inout std_logic; 
             WING_CH6     : inout std_logic; 
             WING_CH7     : inout std_logic; 
             AUDIO_LEFT   : in    std_logic; 
             AUDIO_RIGHT  : in    std_logic; 
             VGA_Red2     : in    std_logic; 
             VGA_Red1     : in    std_logic; 
             VGA_Red0     : in    std_logic; 
             VGA_Green2   : in    std_logic; 
             VGA_Green1   : in    std_logic; 
             VGA_Green0   : in    std_logic; 
             VGA_Hsync    : in    std_logic; 
             VGA_Vsync    : in    std_logic; 
             VGA_Red3     : in    std_logic; 
             VGA_Green3   : in    std_logic; 
             VGA_Blue3    : in    std_logic; 
             VGA_Blue1    : in    std_logic; 
             VGA_Blue0    : in    std_logic; 
             VGA_Blue2    : in    std_logic; 
             VGA_Bus      : inout std_logic_vector (32 downto 0));
   end component;
   
   component PULLUP
      port ( O : out   std_logic);
   end component;
   attribute BOX_TYPE of PULLUP : component is "BLACK_BOX";
   
   component PULLDOWN
      port ( O : out   std_logic);
   end component;
   attribute BOX_TYPE of PULLDOWN : component is "BLACK_BOX";
   
   component VGA_ZPUino
      port ( wishbone_in             : in    std_logic_vector (100 downto 0); 
             wishbone_out            : out   std_logic_vector (100 downto 0); 
             wishbone_slot_video_in  : out   std_logic_vector (100 downto 0); 
             wishbone_slot_video_out : in    std_logic_vector (100 downto 0); 
             VGA_Bus                 : inout std_logic_vector (32 downto 0));
   end component;
   
begin
   XLXI_39 : ZPUino_Papilio_Pro_V2
      port map (ext_pins_in(100 downto 0)=>ext_pins_in(100 downto 0),
                gpio_bus_in(200 downto 0)=>XLXN_549(200 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_557(100 downto 0),
                wishbone_slot_5_out(100 downto 0)=>XLXN_451(100 downto 0),
                wishbone_slot_6_out(100 downto 0)=>XLXN_453(100 downto 0),
                wishbone_slot_8_out(100 downto 0)=>XLXN_455(100 downto 0),
                wishbone_slot_9_out(100 downto 
            0)=>XLXI_39_wishbone_slot_9_out_openSignal(100 downto 0),
                wishbone_slot_10_out(100 downto 
            0)=>XLXI_39_wishbone_slot_10_out_openSignal(100 downto 0),
                wishbone_slot_11_out(100 downto 
            0)=>XLXI_39_wishbone_slot_11_out_openSignal(100 downto 0),
                wishbone_slot_12_out(100 downto 
            0)=>XLXI_39_wishbone_slot_12_out_openSignal(100 downto 0),
                wishbone_slot_13_out(100 downto 
            0)=>XLXI_39_wishbone_slot_13_out_openSignal(100 downto 0),
                wishbone_slot_14_out(100 downto 0)=>XLXN_556(100 downto 0),
                clk_osc_32Mhz=>open,
                clk_1Mhz=>XLXN_530,
                clk_96Mhz=>XLXN_531,
                ext_pins_out(100 downto 0)=>ext_pins_out(100 downto 0),
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_558(100 downto 0),
                wishbone_slot_5_in(100 downto 0)=>XLXN_450(100 downto 0),
                wishbone_slot_6_in(100 downto 0)=>XLXN_452(100 downto 0),
                wishbone_slot_8_in(100 downto 0)=>XLXN_454(100 downto 0),
                wishbone_slot_9_in=>open,
                wishbone_slot_10_in=>open,
                wishbone_slot_11_in=>open,
                wishbone_slot_12_in=>open,
                wishbone_slot_13_in=>open,
                wishbone_slot_14_in(100 downto 0)=>XLXN_555(100 downto 0),
                ext_pins_inout(100 downto 0)=>ext_pins_inout(100 downto 0));
   
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
                out1=>XLXN_532,
                out2=>XLXN_533);
   
   XLXI_60 : VCC
      port map (P=>XLXN_472);
   
   XLXI_61 : GND
      port map (G=>XLXN_473);
   
   XLXI_69 : Arcade_MegaWing_Pinout
      port map (AUDIO_LEFT=>XLXN_532,
                AUDIO_RIGHT=>XLXN_533,
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                VGA_Blue0=>XLXI_69_VGA_Blue0_openSignal,
                VGA_Blue1=>XLXI_69_VGA_Blue1_openSignal,
                VGA_Blue2=>XLXI_69_VGA_Blue2_openSignal,
                VGA_Blue3=>XLXI_69_VGA_Blue3_openSignal,
                VGA_Green0=>XLXI_69_VGA_Green0_openSignal,
                VGA_Green1=>XLXI_69_VGA_Green1_openSignal,
                VGA_Green2=>XLXI_69_VGA_Green2_openSignal,
                VGA_Green3=>XLXI_69_VGA_Green3_openSignal,
                VGA_Hsync=>XLXI_69_VGA_Hsync_openSignal,
                VGA_Red0=>XLXI_69_VGA_Red0_openSignal,
                VGA_Red1=>XLXI_69_VGA_Red1_openSignal,
                VGA_Red2=>XLXI_69_VGA_Red2_openSignal,
                VGA_Red3=>XLXI_69_VGA_Red3_openSignal,
                VGA_Vsync=>XLXI_69_VGA_Vsync_openSignal,
                gpio_bus_in(200 downto 0)=>XLXN_549(200 downto 0),
                VGA_Bus(32 downto 0)=>XLXN_554(32 downto 0),
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
   
   XLXI_74 : PULLUP
      port map (O=>WING_CH7);
   
   XLXI_75 : PULLDOWN
      port map (O=>WING_CH6);
   
   XLXI_76 : PULLDOWN
      port map (O=>WING_CH4);
   
   XLXI_77 : PULLUP
      port map (O=>WING_CH5);
   
   XLXI_78 : PULLUP
      port map (O=>WING_CH3);
   
   XLXI_79 : PULLUP
      port map (O=>WING_CH2);
   
   XLXI_80 : PULLUP
      port map (O=>WING_CH1);
   
   XLXI_81 : PULLUP
      port map (O=>WING_CH0);
   
   XLXI_85 : PULLDOWN
      port map (O=>WING_AL2);
   
   XLXI_86 : PULLDOWN
      port map (O=>WING_AL0);
   
   XLXI_87 : PULLUP
      port map (O=>WING_AL1);
   
   XLXI_88 : PULLUP
      port map (O=>WING_AL3);
   
   XLXI_89 : PULLUP
      port map (O=>WING_BH5);
   
   XLXI_90 : PULLUP
      port map (O=>WING_BH4);
   
   XLXI_91 : PULLUP
      port map (O=>WING_BH7);
   
   XLXI_92 : PULLUP
      port map (O=>WING_BH6);
   
   XLXI_94 : VGA_ZPUino
      port map (wishbone_in(100 downto 0)=>XLXN_555(100 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_558(100 downto 0),
                wishbone_out(100 downto 0)=>XLXN_556(100 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_557(100 downto 0),
                VGA_Bus(32 downto 0)=>XLXN_554(32 downto 0));
   
end BEHAVIORAL;


