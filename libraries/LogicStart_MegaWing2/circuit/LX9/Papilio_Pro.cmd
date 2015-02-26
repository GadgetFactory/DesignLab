xst -intstyle ise -ifn "D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/LogicStart_MegaWing2/circuit/LX9/Papilio_Pro.xst" -ofn "D:/Dropbox/GadgetFactory_Engineering/DesignLab_Examples/libraries/LogicStart_MegaWing2/circuit/LX9/Papilio_Pro.syr" 
ngdbuild -intstyle ise -dd _ngo -sd ../../../AVR_Wishbone_Bridge -sd ../../../Benchy -sd ../../../BitCoin_Miner -sd ../../../Building_Blocks -sd ../../../Clocks -sd ../../../Gameduino -sd ../../../HQVGA -sd ../../../Papilio_Hardware -sd ../../../VGA_ZPUino -sd ../../../VGA_ZXSpectrum -sd ../../../ZPUino_2 -sd ../../../ZPUino_Wishbone_Peripherals -aul -nt timestamp -uc D:/Dropbox/GadgetFactory_Engineering/DesignLab/build/windows/work/examples/00.Papilio_Schematic_Library/Libraries/ZPUino_1/PSL_Papilio_Pro_LX9/papilio_pro.ucf -p xc6slx9-tqg144-2 Papilio_Pro.ngc Papilio_Pro.ngd  
map -intstyle ise -p xc6slx9-tqg144-2 -w -logic_opt off -ol high -t 1 -xt 0 -register_duplication off -r 4 -global_opt off -mt off -ir off -pr off -lc off -power off -o Papilio_Pro_map.ncd Papilio_Pro.ngd Papilio_Pro.pcf 
par -w -intstyle ise -ol high -mt off Papilio_Pro_map.ncd Papilio_Pro.ncd Papilio_Pro.pcf 
trce -intstyle ise -v 3 -s 2 -n 3 -fastpaths -xml Papilio_Pro.twx Papilio_Pro.ncd -o Papilio_Pro.twr Papilio_Pro.pcf 
bitgen -intstyle ise -f Papilio_Pro.ut Papilio_Pro.ncd 
bitgen -intstyle ise -f Papilio_Pro.ut Papilio_Pro.ncd 
