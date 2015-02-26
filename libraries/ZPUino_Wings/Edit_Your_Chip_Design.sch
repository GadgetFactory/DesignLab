<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <blockdef name="Audio_Wing">
            <timestamp>2014-10-1T6:28:8</timestamp>
            <rect width="160" x="52" y="-64" height="64" />
            <line x2="52" y1="-48" y2="-48" x1="0" />
            <line x2="256" y1="-16" y2="-16" x1="212" />
            <line x2="128" y1="-112" y2="-64" x1="128" />
            <line x2="144" y1="-112" y2="-64" x1="144" />
        </blockdef>
        <block symbolname="Audio_Wing" name="XLXI_48">
            <blockpin name="buttons(3:0)" />
            <blockpin name="leds(3:0)" />
            <blockpin name="wishbone_in(61:0)" />
            <blockpin name="wishbone_out(33:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="1760" height="1360">
        <instance x="704" y="688" name="XLXI_48" orien="R0">
        </instance>
    </sheet>
</drawing>
