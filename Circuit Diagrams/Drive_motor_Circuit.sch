<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC" urn="urn:adsk.eagle:symbol:26928/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" urn="urn:adsk.eagle:component:26957/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VCC" device="" value="+7.2V"/>
<part name="SUPPLY1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<description>Part 2_1</description>
<plain>
<wire x1="53.34" y1="71.12" x2="55.88" y2="71.12" width="0.254" layer="94"/>
<wire x1="55.88" y1="71.12" x2="58.42" y2="71.12" width="0.254" layer="94"/>
<wire x1="58.42" y1="71.12" x2="60.96" y2="71.12" width="0.254" layer="94"/>
<wire x1="60.96" y1="71.12" x2="63.5" y2="71.12" width="0.254" layer="94"/>
<wire x1="63.5" y1="71.12" x2="66.04" y2="71.12" width="0.254" layer="94"/>
<wire x1="66.04" y1="71.12" x2="68.58" y2="71.12" width="0.254" layer="94"/>
<wire x1="68.58" y1="71.12" x2="71.12" y2="71.12" width="0.254" layer="94"/>
<wire x1="71.12" y1="71.12" x2="73.66" y2="71.12" width="0.254" layer="94"/>
<wire x1="73.66" y1="71.12" x2="76.2" y2="71.12" width="0.254" layer="94"/>
<wire x1="76.2" y1="71.12" x2="78.74" y2="71.12" width="0.254" layer="94"/>
<wire x1="78.74" y1="71.12" x2="81.28" y2="71.12" width="0.254" layer="94"/>
<wire x1="81.28" y1="71.12" x2="83.82" y2="71.12" width="0.254" layer="94"/>
<wire x1="83.82" y1="71.12" x2="86.36" y2="71.12" width="0.254" layer="94"/>
<wire x1="86.36" y1="71.12" x2="88.9" y2="71.12" width="0.254" layer="94"/>
<wire x1="88.9" y1="71.12" x2="91.44" y2="71.12" width="0.254" layer="94"/>
<wire x1="91.44" y1="71.12" x2="91.44" y2="53.34" width="0.254" layer="94"/>
<wire x1="91.44" y1="53.34" x2="88.9" y2="53.34" width="0.254" layer="94"/>
<wire x1="88.9" y1="53.34" x2="86.36" y2="53.34" width="0.254" layer="94"/>
<wire x1="86.36" y1="53.34" x2="83.82" y2="53.34" width="0.254" layer="94"/>
<wire x1="83.82" y1="53.34" x2="81.28" y2="53.34" width="0.254" layer="94"/>
<wire x1="81.28" y1="53.34" x2="78.74" y2="53.34" width="0.254" layer="94"/>
<wire x1="78.74" y1="53.34" x2="76.2" y2="53.34" width="0.254" layer="94"/>
<wire x1="76.2" y1="53.34" x2="73.66" y2="53.34" width="0.254" layer="94"/>
<wire x1="73.66" y1="53.34" x2="71.12" y2="53.34" width="0.254" layer="94"/>
<wire x1="71.12" y1="53.34" x2="68.58" y2="53.34" width="0.254" layer="94"/>
<wire x1="68.58" y1="53.34" x2="66.04" y2="53.34" width="0.254" layer="94"/>
<wire x1="66.04" y1="53.34" x2="63.5" y2="53.34" width="0.254" layer="94"/>
<wire x1="63.5" y1="53.34" x2="60.96" y2="53.34" width="0.254" layer="94"/>
<wire x1="60.96" y1="53.34" x2="58.42" y2="53.34" width="0.254" layer="94"/>
<wire x1="58.42" y1="53.34" x2="55.88" y2="53.34" width="0.254" layer="94"/>
<wire x1="55.88" y1="53.34" x2="53.34" y2="53.34" width="0.254" layer="94"/>
<wire x1="53.34" y1="53.34" x2="53.34" y2="71.12" width="0.254" layer="94"/>
<wire x1="55.88" y1="50.8" x2="55.88" y2="53.34" width="0.254" layer="94"/>
<wire x1="58.42" y1="50.8" x2="58.42" y2="53.34" width="0.254" layer="94"/>
<wire x1="60.96" y1="50.8" x2="60.96" y2="53.34" width="0.254" layer="94"/>
<wire x1="63.5" y1="50.8" x2="63.5" y2="53.34" width="0.254" layer="94"/>
<wire x1="66.04" y1="50.8" x2="66.04" y2="53.34" width="0.254" layer="94"/>
<wire x1="68.58" y1="50.8" x2="68.58" y2="53.34" width="0.254" layer="94"/>
<wire x1="71.12" y1="50.8" x2="71.12" y2="53.34" width="0.254" layer="94"/>
<wire x1="73.66" y1="50.8" x2="73.66" y2="53.34" width="0.254" layer="94"/>
<wire x1="76.2" y1="50.8" x2="76.2" y2="53.34" width="0.254" layer="94"/>
<wire x1="78.74" y1="50.8" x2="78.74" y2="53.34" width="0.254" layer="94"/>
<wire x1="81.28" y1="50.8" x2="81.28" y2="53.34" width="0.254" layer="94"/>
<wire x1="83.82" y1="50.8" x2="83.82" y2="53.34" width="0.254" layer="94"/>
<wire x1="86.36" y1="50.8" x2="86.36" y2="53.34" width="0.254" layer="94"/>
<wire x1="88.9" y1="50.8" x2="88.9" y2="53.34" width="0.254" layer="94"/>
<wire x1="55.88" y1="71.12" x2="55.88" y2="73.66" width="0.254" layer="94"/>
<wire x1="58.42" y1="71.12" x2="58.42" y2="73.66" width="0.254" layer="94"/>
<wire x1="60.96" y1="71.12" x2="60.96" y2="73.66" width="0.254" layer="94"/>
<wire x1="63.5" y1="71.12" x2="63.5" y2="73.66" width="0.254" layer="94"/>
<wire x1="66.04" y1="71.12" x2="66.04" y2="73.66" width="0.254" layer="94"/>
<wire x1="68.58" y1="71.12" x2="68.58" y2="73.66" width="0.254" layer="94"/>
<wire x1="71.12" y1="71.12" x2="71.12" y2="73.66" width="0.254" layer="94"/>
<wire x1="73.66" y1="71.12" x2="73.66" y2="73.66" width="0.254" layer="94"/>
<wire x1="76.2" y1="71.12" x2="76.2" y2="73.66" width="0.254" layer="94"/>
<wire x1="78.74" y1="71.12" x2="78.74" y2="73.66" width="0.254" layer="94"/>
<wire x1="81.28" y1="71.12" x2="81.28" y2="73.66" width="0.254" layer="94"/>
<wire x1="83.82" y1="71.12" x2="83.82" y2="73.66" width="0.254" layer="94"/>
<wire x1="86.36" y1="71.12" x2="86.36" y2="73.66" width="0.254" layer="94"/>
<wire x1="88.9" y1="71.12" x2="88.9" y2="73.66" width="0.254" layer="94"/>
<text x="55.88" y="55.88" size="1.778" layer="94" rot="R90">GND</text>
<text x="58.42" y="55.88" size="1.778" layer="94" rot="R90">0</text>
<text x="60.96" y="55.88" size="1.778" layer="94" rot="R90">1</text>
<text x="63.5" y="55.88" size="1.778" layer="94" rot="R90">2</text>
<text x="66.04" y="55.88" size="1.778" layer="94" rot="R90">3</text>
<text x="68.58" y="55.88" size="1.778" layer="94" rot="R90">4</text>
<text x="71.12" y="55.88" size="1.778" layer="94" rot="R90">5</text>
<text x="73.66" y="55.88" size="1.778" layer="94" rot="R90">6</text>
<text x="76.2" y="55.88" size="1.778" layer="94" rot="R90">7</text>
<text x="78.74" y="55.88" size="1.778" layer="94" rot="R90">8</text>
<text x="81.28" y="55.88" size="1.778" layer="94" rot="R90">9</text>
<text x="83.82" y="55.88" size="1.778" layer="94" rot="R90">10</text>
<text x="86.36" y="55.88" size="1.778" layer="94" rot="R90">11</text>
<text x="88.9" y="55.88" size="1.778" layer="94" rot="R90">12</text>
<text x="58.42" y="66.04" size="1.778" layer="94" rot="R90">GND</text>
<text x="55.88" y="66.04" size="1.778" layer="94" rot="R90">5V</text>
<text x="60.96" y="66.04" size="1.778" layer="94" rot="R90">3.3</text>
<text x="63.5" y="66.04" size="1.778" layer="94" rot="R90">23</text>
<text x="66.04" y="66.04" size="1.778" layer="94" rot="R90">22</text>
<text x="68.58" y="66.04" size="1.778" layer="94" rot="R90">21</text>
<text x="71.12" y="66.04" size="1.778" layer="94" rot="R90">20</text>
<text x="73.66" y="66.04" size="1.778" layer="94" rot="R90">19</text>
<text x="76.2" y="66.04" size="1.778" layer="94" rot="R90">18</text>
<text x="78.74" y="66.04" size="1.778" layer="94" rot="R90">17</text>
<text x="81.28" y="66.04" size="1.778" layer="94" rot="R90">16</text>
<text x="83.82" y="66.04" size="1.778" layer="94" rot="R90">15</text>
<text x="86.36" y="66.04" size="1.778" layer="94" rot="R90">14</text>
<text x="88.9" y="66.04" size="1.778" layer="94" rot="R90">13</text>
<text x="66.04" y="60.96" size="1.778" layer="94">TEENSY_LC</text>
<wire x1="-10.16" y1="35.56" x2="-7.62" y2="35.56" width="0.254" layer="94"/>
<wire x1="-7.62" y1="35.56" x2="-2.54" y2="35.56" width="0.254" layer="94"/>
<wire x1="-2.54" y1="35.56" x2="2.54" y2="35.56" width="0.254" layer="94"/>
<wire x1="2.54" y1="35.56" x2="7.62" y2="35.56" width="0.254" layer="94"/>
<wire x1="7.62" y1="35.56" x2="12.7" y2="35.56" width="0.254" layer="94"/>
<wire x1="12.7" y1="35.56" x2="17.78" y2="35.56" width="0.254" layer="94"/>
<wire x1="17.78" y1="35.56" x2="20.32" y2="35.56" width="0.254" layer="94"/>
<wire x1="20.32" y1="35.56" x2="20.32" y2="20.32" width="0.254" layer="94"/>
<wire x1="20.32" y1="20.32" x2="15.24" y2="20.32" width="0.254" layer="94"/>
<wire x1="15.24" y1="20.32" x2="7.62" y2="20.32" width="0.254" layer="94"/>
<wire x1="7.62" y1="20.32" x2="2.54" y2="20.32" width="0.254" layer="94"/>
<wire x1="2.54" y1="20.32" x2="-5.08" y2="20.32" width="0.254" layer="94"/>
<wire x1="-5.08" y1="20.32" x2="-10.16" y2="20.32" width="0.254" layer="94"/>
<wire x1="-10.16" y1="20.32" x2="-10.16" y2="22.86" width="0.254" layer="94"/>
<wire x1="-10.16" y1="22.86" x2="-10.16" y2="27.94" width="0.254" layer="94"/>
<wire x1="-10.16" y1="27.94" x2="-10.16" y2="33.02" width="0.254" layer="94"/>
<wire x1="-10.16" y1="33.02" x2="-10.16" y2="35.56" width="0.254" layer="94"/>
<wire x1="-2.54" y1="38.1" x2="-2.54" y2="35.56" width="0.254" layer="94"/>
<wire x1="2.54" y1="38.1" x2="2.54" y2="35.56" width="0.254" layer="94"/>
<wire x1="7.62" y1="38.1" x2="7.62" y2="35.56" width="0.254" layer="94"/>
<wire x1="-5.08" y1="20.32" x2="-5.08" y2="17.78" width="0.254" layer="94"/>
<wire x1="2.54" y1="20.32" x2="2.54" y2="17.78" width="0.254" layer="94"/>
<wire x1="7.62" y1="20.32" x2="7.62" y2="17.78" width="0.254" layer="94"/>
<wire x1="15.24" y1="20.32" x2="15.24" y2="17.78" width="0.254" layer="94"/>
<wire x1="-12.7" y1="27.94" x2="-10.16" y2="27.94" width="0.254" layer="94"/>
<wire x1="-12.7" y1="22.86" x2="-10.16" y2="22.86" width="0.254" layer="94"/>
<text x="5.08" y="33.02" size="1.778" layer="94">J1</text>
<text x="20.32" y="27.94" size="1.778" layer="94">L298 Driver Module</text>
<wire x1="12.7" y1="38.1" x2="12.7" y2="35.56" width="0.254" layer="94"/>
<wire x1="17.78" y1="38.1" x2="17.78" y2="35.56" width="0.254" layer="94"/>
<text x="0" y="38.1" size="1.778" layer="94" rot="R90">IN 1</text>
<text x="5.08" y="38.1" size="1.778" layer="94" rot="R90">IN 2</text>
<text x="10.16" y="38.1" size="1.778" layer="94" rot="R90">IN 3</text>
<text x="15.24" y="38.1" size="1.778" layer="94" rot="R90">IN 4</text>
<text x="20.32" y="38.1" size="1.778" layer="94" rot="R90">GND</text>
<text x="5.08" y="22.86" size="1.778" layer="94">J2</text>
<text x="-7.62" y="27.94" size="1.778" layer="94">J3</text>
<text x="-7.62" y="20.32" size="1.778" layer="94">MOTOR A</text>
<text x="7.62" y="20.32" size="1.778" layer="94">MOTOR B</text>
<text x="-17.78" y="27.94" size="1.778" layer="94">VS</text>
<text x="-17.78" y="22.86" size="1.778" layer="94">GND</text>
<wire x1="78.74" y1="25.4" x2="76.2" y2="25.4" width="0.254" layer="94"/>
<wire x1="101.6" y1="25.4" x2="99.06" y2="25.4" width="0.254" layer="94"/>
<text x="50.8" y="25.4" size="1.778" layer="94">DC MOTOR</text>
<circle x="88.9" y="25.4" radius="10.4726875" width="0.254" layer="94"/>
<circle x="55.88" y="25.4" radius="10.4726875" width="0.254" layer="94"/>
<wire x1="68.58" y1="25.4" x2="66.04" y2="25.4" width="0.254" layer="94"/>
<wire x1="45.72" y1="25.4" x2="43.18" y2="25.4" width="0.254" layer="94"/>
<text x="83.82" y="25.4" size="1.778" layer="94">DC MOTOR</text>
<wire x1="-12.7" y1="33.02" x2="-10.16" y2="33.02" width="0.254" layer="94"/>
<text x="-17.78" y="33.02" size="1.778" layer="94">VSS</text>
<wire x1="-7.62" y1="38.1" x2="-7.62" y2="35.56" width="0.254" layer="94"/>
<text x="-5.08" y="38.1" size="1.778" layer="94" rot="R90">GND</text>
</plain>
<instances>
<instance part="P+1" gate="VCC" x="-22.86" y="81.28" smashed="yes">
<attribute name="VALUE" x="-25.4" y="78.74" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="SUPPLY1" gate="1" x="-22.86" y="0" smashed="yes">
<attribute name="VALUE" x="-24.765" y="-3.175" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="P+1" gate="VCC" pin="VCC"/>
<wire x1="-22.86" y1="78.74" x2="-22.86" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="27.94" x2="-12.7" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<wire x1="-12.7" y1="22.86" x2="-22.86" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="22.86" x2="-22.86" y2="2.54" width="0.1524" layer="91"/>
<pinref part="SUPPLY1" gate="1" pin="GND"/>
<wire x1="-22.86" y1="2.54" x2="104.14" y2="2.54" width="0.1524" layer="91"/>
<junction x="-22.86" y="2.54"/>
<wire x1="104.14" y1="2.54" x2="104.14" y2="76.2" width="0.1524" layer="91"/>
<wire x1="104.14" y1="76.2" x2="58.42" y2="76.2" width="0.1524" layer="91"/>
<wire x1="58.42" y1="76.2" x2="58.42" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<wire x1="-5.08" y1="17.78" x2="-5.08" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="5.08" x2="101.6" y2="5.08" width="0.1524" layer="91"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<wire x1="-2.54" y1="38.1" x2="-2.54" y2="55.88" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="55.88" x2="30.48" y2="55.88" width="0.1524" layer="91"/>
<wire x1="30.48" y1="55.88" x2="30.48" y2="48.26" width="0.1524" layer="91"/>
<wire x1="30.48" y1="48.26" x2="66.04" y2="48.26" width="0.1524" layer="91"/>
<wire x1="66.04" y1="48.26" x2="66.04" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<wire x1="76.2" y1="25.4" x2="76.2" y2="7.62" width="0.1524" layer="91"/>
<wire x1="76.2" y1="7.62" x2="2.54" y2="7.62" width="0.1524" layer="91"/>
<wire x1="2.54" y1="7.62" x2="2.54" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<wire x1="27.94" y1="45.72" x2="27.94" y2="53.34" width="0.1524" layer="91"/>
<wire x1="27.94" y1="53.34" x2="2.54" y2="53.34" width="0.1524" layer="91"/>
<wire x1="2.54" y1="53.34" x2="2.54" y2="38.1" width="0.1524" layer="91"/>
<wire x1="27.94" y1="45.72" x2="68.58" y2="45.72" width="0.1524" layer="91"/>
<wire x1="68.58" y1="45.72" x2="68.58" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<wire x1="43.18" y1="25.4" x2="43.18" y2="12.7" width="0.1524" layer="91"/>
<wire x1="43.18" y1="12.7" x2="15.24" y2="12.7" width="0.1524" layer="91"/>
<wire x1="15.24" y1="12.7" x2="15.24" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<wire x1="68.58" y1="25.4" x2="68.58" y2="10.16" width="0.1524" layer="91"/>
<wire x1="68.58" y1="10.16" x2="7.62" y2="10.16" width="0.1524" layer="91"/>
<wire x1="7.62" y1="10.16" x2="7.62" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<wire x1="83.82" y1="50.8" x2="83.82" y2="40.64" width="0.1524" layer="91"/>
<wire x1="12.7" y1="38.1" x2="12.7" y2="48.26" width="0.1524" layer="91"/>
<wire x1="12.7" y1="48.26" x2="22.86" y2="48.26" width="0.1524" layer="91"/>
<wire x1="22.86" y1="48.26" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="40.64" x2="83.82" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<wire x1="81.28" y1="43.18" x2="81.28" y2="50.8" width="0.1524" layer="91"/>
<wire x1="81.28" y1="43.18" x2="25.4" y2="43.18" width="0.1524" layer="91"/>
<wire x1="25.4" y1="43.18" x2="25.4" y2="50.8" width="0.1524" layer="91"/>
<wire x1="25.4" y1="50.8" x2="7.62" y2="50.8" width="0.1524" layer="91"/>
<wire x1="7.62" y1="50.8" x2="7.62" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="-12.7" y1="33.02" x2="-20.32" y2="33.02" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="33.02" x2="-20.32" y2="76.2" width="0.1524" layer="91"/>
<wire x1="-20.32" y1="76.2" x2="55.88" y2="76.2" width="0.1524" layer="91"/>
<wire x1="55.88" y1="76.2" x2="55.88" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
