--------------------------------------------------------------------------------
-- Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.1
--  \   \         Application : sch2hdl
--  /   /         Filename : Papilio_DUO_LX9.vhf
-- /___/   /\     Timestamp : 02/26/2015 13:57:08
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/AVR_Wishbone_Bridge -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Benchy -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/BitCoin_Miner -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Building_Blocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Clocks -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Gameduino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/HQVGA -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Papilio_Hardware -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZPUino -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/VGA_ZXSpectrum -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_2 -sympath D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/ZPUino_Wishbone_Peripherals -intstyle ise -family spartan6 -flat -suppress -vhdl D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Computing_Shield2/circuit/DUO_LX9/Papilio_DUO_LX9.vhf -w D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/Computing_Shield2/circuit/Papilio_DUO_LX9.sch
--Design Name: Papilio_DUO_LX9
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

entity Papilio_DUO_LX9 is
   port ( DUO_SW1        : in    std_logic; 
          ext_pins_in    : in    std_logic_vector (100 downto 0); 
          ARD_RESET      : out   std_logic; 
          ext_pins_out   : out   std_logic_vector (100 downto 0); 
          Arduino_0      : inout std_logic; 
          Arduino_1      : inout std_logic; 
          Arduino_2      : inout std_logic; 
          Arduino_3      : inout std_logic; 
          Arduino_4      : inout std_logic; 
          Arduino_5      : inout std_logic; 
          Arduino_6      : inout std_logic; 
          Arduino_7      : inout std_logic; 
          Arduino_8      : inout std_logic; 
          Arduino_9      : inout std_logic; 
          Arduino_10     : inout std_logic; 
          Arduino_11     : inout std_logic; 
          Arduino_12     : inout std_logic; 
          Arduino_13     : inout std_logic; 
          Arduino_14     : inout std_logic; 
          Arduino_15     : inout std_logic; 
          Arduino_16     : inout std_logic; 
          Arduino_17     : inout std_logic; 
          Arduino_18     : inout std_logic; 
          Arduino_19     : inout std_logic; 
          Arduino_20     : inout std_logic; 
          Arduino_21     : inout std_logic; 
          Arduino_22     : inout std_logic; 
          Arduino_23     : inout std_logic; 
          Arduino_24     : inout std_logic; 
          Arduino_25     : inout std_logic; 
          Arduino_26     : inout std_logic; 
          Arduino_27     : inout std_logic; 
          Arduino_28     : inout std_logic; 
          Arduino_29     : inout std_logic; 
          Arduino_30     : inout std_logic; 
          Arduino_31     : inout std_logic; 
          Arduino_32     : inout std_logic; 
          Arduino_33     : inout std_logic; 
          Arduino_34     : inout std_logic; 
          Arduino_35     : inout std_logic; 
          Arduino_36     : inout std_logic; 
          Arduino_37     : inout std_logic; 
          Arduino_38     : inout std_logic; 
          Arduino_39     : inout std_logic; 
          Arduino_40     : inout std_logic; 
          Arduino_41     : inout std_logic; 
          Arduino_42     : inout std_logic; 
          Arduino_43     : inout std_logic; 
          Arduino_44     : inout std_logic; 
          Arduino_45     : inout std_logic; 
          Arduino_46     : inout std_logic; 
          Arduino_47     : inout std_logic; 
          Arduino_48     : inout std_logic; 
          Arduino_49     : inout std_logic; 
          Arduino_50     : inout std_logic; 
          Arduino_51     : inout std_logic; 
          Arduino_52     : inout std_logic; 
          Arduino_53     : inout std_logic; 
          ext_pins_inout : inout std_logic_vector (100 downto 0));
end Papilio_DUO_LX9;

architecture BEHAVIORAL of Papilio_DUO_LX9 is
   attribute BOX_TYPE   : string ;
   signal XLXN_408                                      : std_logic_vector (200 
         downto 0);
   signal XLXN_409                                      : std_logic_vector (200 
         downto 0);
   signal XLXN_450                                      : std_logic_vector (17 
         downto 0);
   signal XLXN_629                                      : std_logic;
   signal XLXN_630                                      : std_logic;
   signal XLXN_633                                      : std_logic;
   signal XLXN_634                                      : std_logic;
   signal XLXN_635                                      : std_logic;
   signal XLXN_639                                      : std_logic;
   signal XLXN_640                                      : std_logic;
   signal XLXN_649                                      : std_logic;
   signal XLXN_650                                      : std_logic_vector (17 
         downto 0);
   signal XLXN_651                                      : std_logic_vector (17 
         downto 0);
   signal XLXN_653                                      : std_logic;
   signal XLXN_662                                      : std_logic;
   signal XLXN_663                                      : std_logic;
   signal XLXN_664                                      : std_logic;
   signal XLXN_665                                      : std_logic;
   signal XLXN_666                                      : std_logic;
   signal XLXN_667                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_668                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_669                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_670                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_671                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_672                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_681                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_682                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_683                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_684                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_685                                      : std_logic_vector (32 
         downto 0);
   signal XLXN_686                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_687                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_688                                      : std_logic_vector (100 
         downto 0);
   signal XLXN_689                                      : std_logic_vector (100 
         downto 0);
   signal XLXI_95_VGA_Blue0_openSignal                  : std_logic;
   signal XLXI_95_VGA_Blue1_openSignal                  : std_logic;
   signal XLXI_95_VGA_Blue2_openSignal                  : std_logic;
   signal XLXI_95_VGA_Blue3_openSignal                  : std_logic;
   signal XLXI_95_VGA_Green0_openSignal                 : std_logic;
   signal XLXI_95_VGA_Green1_openSignal                 : std_logic;
   signal XLXI_95_VGA_Green2_openSignal                 : std_logic;
   signal XLXI_95_VGA_Green3_openSignal                 : std_logic;
   signal XLXI_95_VGA_Hsync_openSignal                  : std_logic;
   signal XLXI_95_VGA_Red0_openSignal                   : std_logic;
   signal XLXI_95_VGA_Red1_openSignal                   : std_logic;
   signal XLXI_95_VGA_Red2_openSignal                   : std_logic;
   signal XLXI_95_VGA_Red3_openSignal                   : std_logic;
   signal XLXI_95_VGA_Vsync_openSignal                  : std_logic;
   signal XLXI_98_AVR_Wishbone_Bridge_Enable_openSignal : std_logic;
   signal XLXI_98_wishbone_slot_9_out_openSignal        : std_logic_vector (100 
         downto 0);
   signal XLXI_98_wishbone_slot_10_out_openSignal       : std_logic_vector (100 
         downto 0);
   signal XLXI_98_wishbone_slot_13_out_openSignal       : std_logic_vector (100 
         downto 0);
   component AUDIO_zpuino_wb_passthrough
      port ( raw_out      : out   std_logic_vector (17 downto 0); 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component COMM_zpuino_wb_UART
      port ( rx           : in    std_logic; 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0); 
             tx           : out   std_logic);
   end component;
   
   component COMM_zpuino_wb_SPI
      port ( miso         : in    std_logic; 
             sck          : out   std_logic; 
             mosi         : out   std_logic; 
             wishbone_in  : in    std_logic_vector (100 downto 0); 
             wishbone_out : out   std_logic_vector (100 downto 0));
   end component;
   
   component MISC_zpuino_sa_splitter4
      port ( in1  : in    std_logic; 
             out1 : out   std_logic; 
             out2 : out   std_logic; 
             out3 : out   std_logic; 
             out4 : out   std_logic);
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
   
   component GND
      port ( G : out   std_logic);
   end component;
   attribute BOX_TYPE of GND : component is "BLACK_BOX";
   
   component VCC
      port ( P : out   std_logic);
   end component;
   attribute BOX_TYPE of VCC : component is "BLACK_BOX";
   
   component Computing_Shield_Pinout
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
             VGA_Red2     : in    std_logic; 
             VGA_Red1     : in    std_logic; 
             VGA_Red0     : in    std_logic; 
             VGA_Green2   : in    std_logic; 
             VGA_Green1   : in    std_logic; 
             VGA_Green0   : in    std_logic; 
             VGA_Hsync    : in    std_logic; 
             VGA_Vsync    : in    std_logic; 
             Audio1_Left  : in    std_logic; 
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
             SD_MISO      : out   std_logic; 
             SD_MOSI      : in    std_logic; 
             RS232_RX     : in    std_logic; 
             RS232_TX     : out   std_logic; 
             SD_SCK       : in    std_logic; 
             Audio1_Right : in    std_logic; 
             Audio2_Right : in    std_logic; 
             Audio2_Left  : in    std_logic; 
             WING_BL0     : inout std_logic; 
             WING_BL1     : inout std_logic; 
             WING_BL2     : inout std_logic; 
             WING_BL3     : inout std_logic; 
             WING_BL4     : inout std_logic; 
             WING_BL5     : inout std_logic; 
             WING_BL6     : inout std_logic; 
             WING_BL7     : inout std_logic; 
             WING_DL0     : inout std_logic; 
             WING_DL1     : inout std_logic; 
             WING_DL2     : inout std_logic; 
             WING_DL3     : inout std_logic; 
             WING_DL4     : inout std_logic; 
             WING_DL5     : inout std_logic; 
             WING_DL6     : inout std_logic; 
             WING_DL7     : inout std_logic; 
             WING_DH0     : inout std_logic; 
             WING_DH1     : inout std_logic; 
             WING_DH2     : inout std_logic; 
             WING_DH3     : inout std_logic; 
             WING_DH4     : inout std_logic; 
             WING_DH5     : inout std_logic; 
             WING_DH6     : inout std_logic; 
             WING_DH7     : inout std_logic; 
             VGA_Red3     : in    std_logic; 
             VGA_Green3   : in    std_logic; 
             VGA_Blue3    : in    std_logic; 
             VGA_Blue1    : in    std_logic; 
             VGA_Blue0    : in    std_logic; 
             VGA_Blue2    : in    std_logic; 
             VGA_Bus      : inout std_logic_vector (32 downto 0));
   end component;
   
   component ZPUino_Papilio_DUO_V2
      port ( gpio_bus_out               : out   std_logic_vector (200 downto 
            0); 
             gpio_bus_in                : in    std_logic_vector (200 downto 
            0); 
             clk_96Mhz                  : out   std_logic; 
             clk_1Mhz                   : out   std_logic; 
             clk_osc_32Mhz              : out   std_logic; 
             ext_pins_in                : in    std_logic_vector (100 downto 
            0); 
             ext_pins_out               : out   std_logic_vector (100 downto 
            0); 
             ext_pins_inout             : inout std_logic_vector (100 downto 
            0); 
             AVR_Wishbone_Bridge_Enable : in    std_logic; 
             wishbone_slot_5_out        : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_5_in         : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_6_in         : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_6_out        : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_8_in         : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_8_out        : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_9_in         : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_9_out        : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_10_in        : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_10_out       : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_11_in        : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_11_out       : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_12_in        : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_12_out       : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_13_in        : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_13_out       : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_14_in        : out   std_logic_vector (100 downto 
            0); 
             wishbone_slot_14_out       : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_video_in     : in    std_logic_vector (100 downto 
            0); 
             wishbone_slot_video_out    : out   std_logic_vector (100 downto 
            0));
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
      port map (wishbone_in(100 downto 0)=>XLXN_669(100 downto 0),
                raw_out(17 downto 0)=>XLXN_450(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_670(100 downto 0));
   
   XLXI_48 : INV
      port map (I=>DUO_SW1,
                O=>ARD_RESET);
   
   XLXI_81 : COMM_zpuino_wb_UART
      port map (rx=>XLXN_630,
                wishbone_in(100 downto 0)=>XLXN_681(100 downto 0),
                tx=>XLXN_629,
                wishbone_out(100 downto 0)=>XLXN_682(100 downto 0));
   
   XLXI_82 : COMM_zpuino_wb_SPI
      port map (miso=>XLXN_633,
                wishbone_in(100 downto 0)=>XLXN_683(100 downto 0),
                mosi=>XLXN_634,
                sck=>XLXN_635,
                wishbone_out(100 downto 0)=>XLXN_684(100 downto 0));
   
   XLXI_84 : MISC_zpuino_sa_splitter4
      port map (in1=>XLXN_653,
                out1=>XLXN_639,
                out2=>XLXN_640,
                out3=>XLXN_665,
                out4=>XLXN_666);
   
   XLXI_87 : AUDIO_zpuino_wb_YM2149
      port map (wishbone_in(100 downto 0)=>XLXN_671(100 downto 0),
                data_out(17 downto 0)=>XLXN_651(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_672(100 downto 0));
   
   XLXI_89 : AUDIO_zpuino_wb_sid6581
      port map (clk_1MHZ=>XLXN_649,
                wishbone_in(100 downto 0)=>XLXN_667(100 downto 0),
                audio_data(17 downto 0)=>XLXN_650(17 downto 0),
                wishbone_out(100 downto 0)=>XLXN_668(100 downto 0));
   
   XLXI_92 : AUDIO_zpuino_sa_audiomixer
      port map (clk=>XLXN_662,
                data_in1(17 downto 0)=>XLXN_650(17 downto 0),
                data_in2(17 downto 0)=>XLXN_651(17 downto 0),
                data_in3(17 downto 0)=>XLXN_450(17 downto 0),
                ena=>XLXN_664,
                rst=>XLXN_663,
                audio_out=>XLXN_653);
   
   XLXI_93 : GND
      port map (G=>XLXN_663);
   
   XLXI_94 : VCC
      port map (P=>XLXN_664);
   
   XLXI_95 : Computing_Shield_Pinout
      port map (Audio1_Left=>XLXN_639,
                Audio1_Right=>XLXN_640,
                Audio2_Left=>XLXN_665,
                Audio2_Right=>XLXN_666,
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                RS232_RX=>XLXN_629,
                SD_MOSI=>XLXN_634,
                SD_SCK=>XLXN_635,
                VGA_Blue0=>XLXI_95_VGA_Blue0_openSignal,
                VGA_Blue1=>XLXI_95_VGA_Blue1_openSignal,
                VGA_Blue2=>XLXI_95_VGA_Blue2_openSignal,
                VGA_Blue3=>XLXI_95_VGA_Blue3_openSignal,
                VGA_Green0=>XLXI_95_VGA_Green0_openSignal,
                VGA_Green1=>XLXI_95_VGA_Green1_openSignal,
                VGA_Green2=>XLXI_95_VGA_Green2_openSignal,
                VGA_Green3=>XLXI_95_VGA_Green3_openSignal,
                VGA_Hsync=>XLXI_95_VGA_Hsync_openSignal,
                VGA_Red0=>XLXI_95_VGA_Red0_openSignal,
                VGA_Red1=>XLXI_95_VGA_Red1_openSignal,
                VGA_Red2=>XLXI_95_VGA_Red2_openSignal,
                VGA_Red3=>XLXI_95_VGA_Red3_openSignal,
                VGA_Vsync=>XLXI_95_VGA_Vsync_openSignal,
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                RS232_TX=>XLXN_630,
                SD_MISO=>XLXN_633,
                VGA_Bus(32 downto 0)=>XLXN_685(32 downto 0),
                WING_AH0=>Arduino_8,
                WING_AH1=>Arduino_9,
                WING_AH2=>Arduino_10,
                WING_AH3=>Arduino_11,
                WING_AH4=>Arduino_12,
                WING_AH5=>Arduino_13,
                WING_AL0=>Arduino_0,
                WING_AL1=>Arduino_1,
                WING_AL2=>Arduino_2,
                WING_AL3=>Arduino_3,
                WING_AL4=>Arduino_4,
                WING_AL5=>Arduino_5,
                WING_AL6=>Arduino_6,
                WING_AL7=>Arduino_7,
                WING_BL0=>Arduino_21,
                WING_BL1=>Arduino_20,
                WING_BL2=>Arduino_19,
                WING_BL3=>Arduino_18,
                WING_BL4=>Arduino_17,
                WING_BL5=>Arduino_16,
                WING_BL6=>Arduino_15,
                WING_BL7=>Arduino_14,
                WING_CH0=>Arduino_38,
                WING_CH1=>Arduino_40,
                WING_CH2=>Arduino_42,
                WING_CH3=>Arduino_44,
                WING_CH4=>Arduino_46,
                WING_CH5=>Arduino_48,
                WING_CH6=>Arduino_50,
                WING_CH7=>Arduino_52,
                WING_CL0=>Arduino_22,
                WING_CL1=>Arduino_24,
                WING_CL2=>Arduino_26,
                WING_CL3=>Arduino_28,
                WING_CL4=>Arduino_30,
                WING_CL5=>Arduino_32,
                WING_CL6=>Arduino_34,
                WING_CL7=>Arduino_36,
                WING_DH0=>Arduino_37,
                WING_DH1=>Arduino_35,
                WING_DH2=>Arduino_33,
                WING_DH3=>Arduino_31,
                WING_DH4=>Arduino_29,
                WING_DH5=>Arduino_27,
                WING_DH6=>Arduino_25,
                WING_DH7=>Arduino_23,
                WING_DL0=>Arduino_53,
                WING_DL1=>Arduino_51,
                WING_DL2=>Arduino_49,
                WING_DL3=>Arduino_47,
                WING_DL4=>Arduino_45,
                WING_DL5=>Arduino_43,
                WING_DL6=>Arduino_41,
                WING_DL7=>Arduino_39);
   
   XLXI_98 : ZPUino_Papilio_DUO_V2
      port map 
            (AVR_Wishbone_Bridge_Enable=>XLXI_98_AVR_Wishbone_Bridge_Enable_openSignal,
                ext_pins_in(100 downto 0)=>ext_pins_in(100 downto 0),
                gpio_bus_in(200 downto 0)=>XLXN_409(200 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_688(100 downto 0),
                wishbone_slot_5_out(100 downto 0)=>XLXN_670(100 downto 0),
                wishbone_slot_6_out(100 downto 0)=>XLXN_672(100 downto 0),
                wishbone_slot_8_out(100 downto 0)=>XLXN_668(100 downto 0),
                wishbone_slot_9_out(100 downto 
            0)=>XLXI_98_wishbone_slot_9_out_openSignal(100 downto 0),
                wishbone_slot_10_out(100 downto 
            0)=>XLXI_98_wishbone_slot_10_out_openSignal(100 downto 0),
                wishbone_slot_11_out(100 downto 0)=>XLXN_682(100 downto 0),
                wishbone_slot_12_out(100 downto 0)=>XLXN_684(100 downto 0),
                wishbone_slot_13_out(100 downto 
            0)=>XLXI_98_wishbone_slot_13_out_openSignal(100 downto 0),
                wishbone_slot_14_out(100 downto 0)=>XLXN_687(100 downto 0),
                clk_osc_32Mhz=>open,
                clk_1Mhz=>XLXN_649,
                clk_96Mhz=>XLXN_662,
                ext_pins_out(100 downto 0)=>ext_pins_out(100 downto 0),
                gpio_bus_out(200 downto 0)=>XLXN_408(200 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_689(100 downto 0),
                wishbone_slot_5_in(100 downto 0)=>XLXN_669(100 downto 0),
                wishbone_slot_6_in(100 downto 0)=>XLXN_671(100 downto 0),
                wishbone_slot_8_in(100 downto 0)=>XLXN_667(100 downto 0),
                wishbone_slot_9_in=>open,
                wishbone_slot_10_in=>open,
                wishbone_slot_11_in(100 downto 0)=>XLXN_681(100 downto 0),
                wishbone_slot_12_in(100 downto 0)=>XLXN_683(100 downto 0),
                wishbone_slot_13_in=>open,
                wishbone_slot_14_in(100 downto 0)=>XLXN_686(100 downto 0),
                ext_pins_inout(100 downto 0)=>ext_pins_inout(100 downto 0));
   
   XLXI_99 : VGA_ZPUino
      port map (wishbone_in(100 downto 0)=>XLXN_686(100 downto 0),
                wishbone_slot_video_out(100 downto 0)=>XLXN_689(100 downto 0),
                wishbone_out(100 downto 0)=>XLXN_687(100 downto 0),
                wishbone_slot_video_in(100 downto 0)=>XLXN_688(100 downto 0),
                VGA_Bus(32 downto 0)=>XLXN_685(32 downto 0));
   
end BEHAVIORAL;


