xst -intstyle ise -ifn "D:/Dropbox/GadgetFactory/GadgetFactory_Engineering/Papilio-Schematic-Library/examples/Papilio_DUO_QuickStart/DUO_LX9/Papilio_DUO_LX9.xst" -ofn "D:/Dropbox/GadgetFactory/GadgetFactory_Engineering/Papilio-Schematic-Library/examples/Papilio_DUO_QuickStart/DUO_LX9/Papilio_DUO_LX9.syr" 
ngdbuild -intstyle ise -dd _ngo -aul -nt timestamp -uc D:/Dropbox/GadgetFactory/GadgetFactory_Engineering/Papilio-Schematic-Library/examples/Papilio_DUO_QuickStart/Libraries/ZPUino_1/board_Papilio_DUO/papilio_duo.ucf -p xc6slx9-tqg144-2 Papilio_DUO_LX9.ngc Papilio_DUO_LX9.ngd  
map -intstyle ise -p xc6slx9-tqg144-2 -w -logic_opt off -ol high -t 1 -xt 0 -register_duplication off -r 4 -global_opt off -mt off -ir off -pr off -lc off -power off -o Papilio_DUO_LX9_map.ncd Papilio_DUO_LX9.ngd Papilio_DUO_LX9.pcf 
par -w -intstyle ise -ol high -mt off Papilio_DUO_LX9_map.ncd Papilio_DUO_LX9.ncd Papilio_DUO_LX9.pcf 
trce -intstyle ise -v 3 -s 2 -n 3 -fastpaths -xml Papilio_DUO_LX9.twx Papilio_DUO_LX9.ncd -o Papilio_DUO_LX9.twr Papilio_DUO_LX9.pcf 
bitgen -intstyle ise -f Papilio_DUO_LX9.ut Papilio_DUO_LX9.ncd 
