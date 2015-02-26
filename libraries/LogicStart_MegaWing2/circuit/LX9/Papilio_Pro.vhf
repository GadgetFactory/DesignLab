--------------------------------------------------------------------------------
-- Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.1
--  \   \         Application : sch2hdl
--  /   /         Filename : Papilio_Pro.vhf
-- /___/   /\     Timestamp : 02/26/2015 14:05:54
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/AVR_Wishbone_Bridge -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Benchy -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/BitCoin_Miner -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Building_Blocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Clocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Gameduino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/HQVGA -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Papilio_Hardware -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZPUino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZXSpectrum -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_2 -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wishbone_Peripherals -intstyle ise -family spartan6 -flat -suppress -vhdl D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/LogicStart_MegaWing2/circuit/LX9/Papilio_Pro.vhf -w D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/LogicStart_MegaWing2/circuit/Papilio_Pro.sch
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
   signal XLXN_408                                : std_logic_vector (200 
         downto 0);
   signal XLXN_409                                : std_logic_vector (200 
         downto 0);
   signal XLXN_450                                : std_logic_vector (17 downto 
         0);
   signal XLXN_452                                : std_logic;
   signal XLXN_542                                : std_logic_vector (6 downto 
         0);
   signal XLXN_543                                : std_logic_vector (3 downto 
         0);
   signal XLXN_544                                : std_logic;
   signal XLXN_603                                : std_logic;
   signal XLXN_604                                : std_logic;
   signal XLXN_605                                : std_logic;
   signal XLXN_610                                : std_logic;
   signal XLXN_611                                : std_logic_vector (100 
         downto 0);
   signal XLXN_612                                : std_logic_vector (100 
         downto 0);
   signal XLXN_613                                : std_logic_vector (100 
         downto 0);
   signal XLXN_614                                : std_logic_vector (100 
         downto 0);
   signal XLXN_615                                : std_logic_vector (100 
         downto 0);
   signal XLXN_616                                : std_logic_vector (100 
         downto 0);
   signal XLXN_628                                : std_logic_vector (32 downto 
         0);
   signal XLXN_629                                : std_logic_vector (100 
         downto 0);
   signal XLXN_630                                : std_logic_vector (100 
         downto 0);
   signal XLXN_631                                : std_logic_vector (100 
         downto 0);
   signal XLXN_632                                : std_logic_vector (100 
         downto 0);
   signal XLXI_63_SPI_CS_openSignal               : std_logic;
   signal XLXI_63_VGA_Blue0_openSignal            : std_logic;
   signal XLXI_63_VGA_Blue1_openSignal            : std_logic;
   signal XLXI_63_VGA_Green0_openSignal           : std_logic;
   signal XLXI_63_VGA_Green1_openSignal           : std_logic;
   signal XLXI_63_VGA_Green2_openSignal           : std_logic;
   signal XLXI_63_VGA_Hsync_openSignal            : std_logic;
   signal XLXI_63_VGA_Red0_openSignal             : std_logic;
   signal XLXI_63_VGA_Red1_openSignal             : std_logic;
   signal XLXI_63_VGA_Red2_openSignal             : std_logic;
   signal XLXI_63_VGA_Vsync_openSignal            : std_logic;
   signal XLXI_71_wishbone_slot_8_out_openSignal  : std_logic_vector (100 
         downto 0);
   signal XLXI_71_wishbone_slot_9_out_openSignal  : std_logic_vector (100 
         downto 0);
   signal XLXI_71_wishbone_slot_10_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_71_wishbone_slot_12_out_openSignal : std_logic_vector (100 
         downto 0);
   signal XLXI_71_wishbone_slot_13_out_openSignal : std_logic_vector (100 
         downto 0);
   component AUDIO_zpuino_wb_passthrough
      port ( raw_out      : out   std_logic_vector (17 downto 0); 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component AUDIO_zpuino_sa_sigmadeltaDAC
      port ( data_in   : in    std_logic_vector (17 downto 0); 
             audio_out : out   std_logic; 
             clk_96Mhz : in    std_logic);
   end component;
   
   component MISC_zpuino_wb_SevenSeg
      port ( segdata      : out   std_logic_vector (6 downto 0); 
             extra        : out   std_logic_vector (31 downto 0); 
             enable       : out   std_logic_vector (3 downto 0); 
             dot          : out   std_logic; 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component COMM_zpuino_wb_SPI
      port ( miso         : in    std_logic; 
             sck          : out   std_logic; 
             mosi         : out   std_logic; 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component LogicStart_MegaWing_Pinout
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
             Audio        : in    std_logic; 
             SPI_MISO     : out   std_logic; 
             SPI_MOSI     : in    std_logic; 
             SPI_CLK      : in    std_logic; 
             SPI_CS       : in    std_logic; 
             Seg7_dot     : in    std_logic; 
             Seg7_enable  : in    std_logic_vector (3 downto 0); 
             Seg7_segdata : in    std_logic_vector (6 downto 0); 
             VGA_Red2     : in    std_logic; 
             VGA_Red1     : in    std_logic; 
             VGA_Red0     : in    std_logic; 
             VGA_Green2   : in    std_logic; 
             VGA_Green1   : in    std_logic; 
             VGA_Green0   : in    std_logic; 
             VGA_Hsync    : in    std_logic; 
             VGA_Vsync    : in    std_logic; 
             VGA_Bus      : inout std_logic_vector (32 downto 0); 
             VGA_Blue1    : in    std_logic; 
             VGA_Blue0    : in    std_logic);
   end component;
   
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
   
   component VGA_ZPUino
      port ( wishbone_in             : in    std_logic_vector (100 downto 0); 
             wishbone_out            : out   std_logic_vector (100 downto 0); 
             wishbone_slot_video_in  : out   std_logic_vector (100 downto 0); 
             wishbone_slot_video_out : in    std_logic_vector (100 downto 0); 
             VGA_Bus                 : inout std_logic_vector (32 downto 0));
   end component;
   
begin
   XLXI_38 : AUDIO_zpuino_wb_passthrough
      port map (wishbone_in(100 downto 0)=>XLXN_611(100 downto 0),
                raw_out(17 downto 0)=>XLXN_450(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_612(100 downto 0));
   
   XLXI_39 : AUDIO_zpuino_sa_sigmadeltaDAC
      port map (clk_96Mhz=>XLXN_452,
                data_in(17 downto 0)=>XLXN_450(17 downto 0),
                audio_out=>XLXN_610);
   
   XLXI_57 : MISC_zpuino_wb_SevenSeg
      port map (wishbone_in(100 downto 0)=>XLXN_615(100 downto 0),
                dot=>XLXN_544,
                enable(3 downto 0)=>XLXN_543(3 downto 0),
                extra=>open,
                segdata(6 downto 0)=>XLXN_542(6 downto 0),
                wishbone_out(100 downto 0)=>XLXN_616(100 downto 0));
   
   XLXI_60 : COMM_zpuino_wb_SPI
      port map (miso=>XLXN_605,
                wishbone_in(100 downto 0)=>XLXN_613(100 downto 0),
                mosi=>XLXN_604,
                sck=>XLXN_603,
                wishbone_out(100 downto 0)=>XLXN_614(100 downto 0));
   
   XLXI_63 : LogicStart_MegaWing_Pinout
      port map (Audio=>XLXN_610,
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                Seg7_dot=>XLXN_544,
                Seg7_enable(3 downto 0)=>XLXN_543(3 downto 0),
                Seg7_segdata(6 downto 0)=>XLXN_542(6 downto 0),
                SPI_CLK=>XLXN_603,
                SPI_CS=>XLXI_63_SPI_CS_openSignal,
                SPI_MOSI=>XLXN_604,
                VGA_Blue0=>XLXI_63_VGA_Blue0_openSignal,
                VGA_Blue1=>XLXI_63_VGA_Blue1_openSignal,
                VGA_Green0=>XLXI_63_VGA_Green0_openSignal,
                VGA_Green1=>XLXI_63_VGA_Green1_openSignal,
                VGA_Green2=>XLXI_63_VGA_Green2_openSignal,
                VGA_Hsync=>XLXI_63_VGA_Hsync_openSignal,
                VGA_Red0=>XLXI_63_VGA_Red0_openSignal,
                VGA_Red1=>XLXI_63_VGA_Red1_openSignal,
                VGA_Red2=>XLXI_63_VGA_Red2_openSignal,
                VGA_Vsync=>XLXI_63_VGA_Vsync_openSignal,
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                SPI_MISO=>XLXN_605,
                VGA_Bus(32 downto 0)=>XLXN_628(32 downto 0),
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
   
   XLXI_71 : ZPUino_Papilio_Pro_V2
      port map (ext_pins_in(100 downto 0)=>ext_pins_in(100 downto 0),
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_631(100 downto 0),
                wishbone_slot_5_out(100 downto 0)=>XLXN_612(100 downto 0),
                wishbone_slot_6_out(100 downto 0)=>XLXN_614(100 downto 0),
                wishbone_slot_8_out(100 downto 
            0)=>XLXI_71_wishbone_slot_8_out_openSignal(100 downto 0),
                wishbone_slot_9_out(100 downto 
            0)=>XLXI_71_wishbone_slot_9_out_openSignal(100 downto 0),
                wishbone_slot_10_out(100 downto 
            0)=>XLXI_71_wishbone_slot_10_out_openSignal(100 downto 0),
                wishbone_slot_11_out(100 downto 0)=>XLXN_616(100 downto 0),
                wishbone_slot_12_out(100 downto 
            0)=>XLXI_71_wishbone_slot_12_out_openSignal(100 downto 0),
                wishbone_slot_13_out(100 downto 
            0)=>XLXI_71_wishbone_slot_13_out_openSignal(100 downto 0),
                wishbone_slot_14_out(100 downto 0)=>XLXN_630(100 downto 0),
                clk_osc_32Mhz=>open,
                clk_1Mhz=>open,
                clk_96Mhz=>XLXN_452,
                ext_pins_out(100 downto 0)=>ext_pins_out(100 downto 0),
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_632(100 downto 0),
                wishbone_slot_5_in(100 downto 0)=>XLXN_611(100 downto 0),
                wishbone_slot_6_in(100 downto 0)=>XLXN_613(100 downto 0),
                wishbone_slot_8_in=>open,
                wishbone_slot_9_in=>open,
                wishbone_slot_10_in=>open,
                wishbone_slot_11_in(100 downto 0)=>XLXN_615(100 downto 0),
                wishbone_slot_12_in=>open,
                wishbone_slot_13_in=>open,
                wishbone_slot_14_in(100 downto 0)=>XLXN_629(100 downto 0),
                ext_pins_inout(100 downto 0)=>ext_pins_inout(100 downto 0));
   
   XLXI_73 : VGA_ZPUino
      port map (wishbone_in(100 downto 0)=>XLXN_629(100 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_632(100 downto 0),
                wishbone_out(100 downto 0)=>XLXN_630(100 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_631(100 downto 0),
                VGA_Bus(32 downto 0)=>XLXN_628(32 downto 0));
   
end BEHAVIORAL;


