EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Chikito"
Date "2021-05-25"
Rev "v1.0.1"
Comp "CarMap"
Comment1 "Circuito electrónico general del robot."
Comment2 ""
Comment3 ""
Comment4 "Units: Capacitance in Microfarads (uF)"
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U2
U 1 1 60ACBCBE
P 4900 2950
F 0 "U2" H 4256 2996 50  0000 R CNN
F 1 "ATmega328P-PU" H 4256 2905 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 4900 2950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4900 2950 50  0001 C CNN
	1    4900 2950
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR016
U 1 1 60ACC8C3
P 4900 4800
F 0 "#PWR016" H 4900 4550 50  0001 C CNN
F 1 "GND1" H 4905 4627 50  0000 C CNN
F 2 "" H 4900 4800 50  0001 C CNN
F 3 "" H 4900 4800 50  0001 C CNN
	1    4900 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 60ACD989
P 4900 1200
F 0 "#PWR01" H 4900 1050 50  0001 C CNN
F 1 "+5V" H 4915 1373 50  0000 C CNN
F 2 "" H 4900 1200 50  0001 C CNN
F 3 "" H 4900 1200 50  0001 C CNN
	1    4900 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1200 4900 1450
Wire Wire Line
	4900 4800 4900 4450
Text GLabel 6450 4050 2    50   Output ~ 0
M1_out1
Text GLabel 6450 4150 2    50   Output ~ 0
M1_out2
Text GLabel 6450 1750 2    50   Output ~ 0
M2_out1
Text GLabel 6450 1850 2    50   Output ~ 0
M2_out2
Wire Wire Line
	5500 4050 6450 4050
Wire Wire Line
	5500 4150 6450 4150
Wire Wire Line
	5500 1750 6450 1750
Wire Wire Line
	5500 1850 6450 1850
$Comp
L Connector:USB_B J1
U 1 1 60B0DC1A
P 1700 1550
F 0 "J1" H 1757 2017 50  0000 C CNN
F 1 "USB_B" H 1757 1926 50  0000 C CNN
F 2 "Connector_USB:USB_B_Lumberg_2411_02_Horizontal" H 1850 1500 50  0001 C CNN
F 3 " ~" H 1850 1500 50  0001 C CNN
	1    1700 1550
	1    0    0    -1  
$EndComp
NoConn ~ 1600 1950
NoConn ~ 2000 1550
NoConn ~ 2000 1650
$Comp
L power:GND1 #PWR05
U 1 1 60B10391
P 2150 1950
F 0 "#PWR05" H 2150 1700 50  0001 C CNN
F 1 "GND1" H 2155 1777 50  0000 C CNN
F 2 "" H 2150 1950 50  0001 C CNN
F 3 "" H 2150 1950 50  0001 C CNN
	1    2150 1950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 60B109B6
P 2150 1350
F 0 "#PWR02" H 2150 1200 50  0001 C CNN
F 1 "+5V" H 2165 1523 50  0000 C CNN
F 2 "" H 2150 1350 50  0001 C CNN
F 3 "" H 2150 1350 50  0001 C CNN
	1    2150 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Barrel_Jack J2
U 1 1 60B12EE4
P 1700 2650
F 0 "J2" H 1757 2975 50  0000 C CNN
F 1 "Barrel_Jack" H 1757 2884 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 1750 2610 50  0001 C CNN
F 3 "~" H 1750 2610 50  0001 C CNN
	1    1700 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR09
U 1 1 60B16329
P 2150 2750
F 0 "#PWR09" H 2150 2500 50  0001 C CNN
F 1 "GND2" H 2155 2577 50  0000 C CNN
F 2 "" H 2150 2750 50  0001 C CNN
F 3 "" H 2150 2750 50  0001 C CNN
	1    2150 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR06
U 1 1 60B16AF6
P 2150 2550
F 0 "#PWR06" H 2150 2400 50  0001 C CNN
F 1 "+9V" H 2165 2723 50  0000 C CNN
F 2 "" H 2150 2550 50  0001 C CNN
F 3 "" H 2150 2550 50  0001 C CNN
	1    2150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1950 2150 1950
Wire Wire Line
	2000 1350 2150 1350
Wire Wire Line
	2000 2550 2150 2550
Wire Wire Line
	2000 2750 2150 2750
Wire Notes Line width 20
	1100 850  2500 850 
Wire Notes Line width 20
	2500 850  2500 3100
Wire Notes Line width 20
	2500 3100 1100 3100
Wire Notes Line width 20
	1100 3100 1100 850 
Text Notes 1350 800  0    100  ~ 20
Power input
Wire Notes Line width 20
	6350 800  6350 5100
Wire Notes Line width 20
	6350 5100 3550 5100
Wire Notes Line width 20
	3550 5100 3550 800 
Wire Notes Line width 20
	6350 800  3550 800 
Text Notes 4350 750  0    100  ~ 20
Arduino Uno Rev3
Text GLabel 7700 2100 0    50   Input ~ 0
M1_out2
Text GLabel 7700 2200 0    50   Input ~ 0
M1_out1
$Comp
L Motor:Motor_DC M1
U 1 1 60ACF829
P 10250 1950
F 0 "M1" H 10408 1946 50  0000 L CNN
F 1 "Motor_DC" H 10408 1855 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 10250 1860 50  0001 C CNN
F 3 "~" H 10250 1860 50  0001 C CNN
	1    10250 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 60AD0238
P 9800 2000
F 0 "C1" H 9915 2046 50  0000 L CNN
F 1 "0.1" H 9915 1955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.0mm_W2.5mm_P5.00mm" H 9838 1850 50  0001 C CNN
F 3 "~" H 9800 2000 50  0001 C CNN
	1    9800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 1850 9800 1750
Wire Wire Line
	9800 1750 10250 1750
Wire Wire Line
	9800 2150 9800 2250
Wire Wire Line
	9800 2250 10250 2250
$Comp
L power:+9V #PWR04
U 1 1 60AD1583
P 8450 1400
F 0 "#PWR04" H 8450 1250 50  0001 C CNN
F 1 "+9V" H 8465 1573 50  0000 C CNN
F 2 "" H 8450 1400 50  0001 C CNN
F 3 "" H 8450 1400 50  0001 C CNN
	1    8450 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 60AD22A5
P 8250 1400
F 0 "#PWR03" H 8250 1250 50  0001 C CNN
F 1 "+5V" H 8265 1573 50  0000 C CNN
F 2 "" H 8250 1400 50  0001 C CNN
F 3 "" H 8250 1400 50  0001 C CNN
	1    8250 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR07
U 1 1 60AD3918
P 7950 2600
F 0 "#PWR07" H 7950 2350 50  0001 C CNN
F 1 "GND1" H 7955 2427 50  0000 C CNN
F 2 "" H 7950 2600 50  0001 C CNN
F 3 "" H 7950 2600 50  0001 C CNN
	1    7950 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR08
U 1 1 60AD5D90
P 8200 2600
F 0 "#PWR08" H 8200 2350 50  0001 C CNN
F 1 "GND2" H 8205 2427 50  0000 C CNN
F 2 "" H 8200 2600 50  0001 C CNN
F 3 "" H 8200 2600 50  0001 C CNN
	1    8200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2600 8200 2600
$Comp
L Device:C C2
U 1 1 60AD83E5
P 8650 2750
F 0 "C2" V 8500 2850 50  0000 C CNN
F 1 "0.1" V 8500 2650 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.0mm_W2.5mm_P5.00mm" H 8688 2600 50  0001 C CNN
F 3 "~" H 8650 2750 50  0001 C CNN
	1    8650 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8500 2500 8500 2750
Wire Wire Line
	8700 2500 8800 2500
Wire Wire Line
	8800 2500 8800 2750
Text GLabel 7700 4050 0    50   Input ~ 0
M2_out2
Text GLabel 7700 4150 0    50   Input ~ 0
M2_out1
Wire Notes Line width 20
	7250 5100 7250 800 
Wire Notes Line width 20
	7250 800  10800 800 
Wire Notes Line width 20
	10800 800  10800 5100
Wire Notes Line width 20
	10800 5100 7250 5100
Text Notes 8600 750  0    100  ~ 20
Motor drivers
Wire Notes Line width 20
	2600 3500 1100 3500
Text Notes 1150 3450 0    100  ~ 20
HC-05 BT Module
$Comp
L power:+5V #PWR013
U 1 1 60B70CB1
P 1450 3750
F 0 "#PWR013" H 1450 3600 50  0001 C CNN
F 1 "+5V" H 1465 3923 50  0000 C CNN
F 2 "" H 1450 3750 50  0001 C CNN
F 3 "" H 1450 3750 50  0001 C CNN
	1    1450 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR017
U 1 1 60B71814
P 1450 4850
F 0 "#PWR017" H 1450 4600 50  0001 C CNN
F 1 "GND1" H 1455 4677 50  0000 C CNN
F 2 "" H 1450 4850 50  0001 C CNN
F 3 "" H 1450 4850 50  0001 C CNN
	1    1450 4850
	1    0    0    -1  
$EndComp
Text GLabel 6450 3450 2    50   Input ~ 0
BT_data_in
Wire Wire Line
	6450 3450 5500 3450
Text GLabel 2050 4200 2    50   Output ~ 0
BT_data_in
Wire Wire Line
	1950 4200 2050 4200
Wire Notes Line width 20
	1100 5100 2600 5100
Wire Notes Line width 20
	2600 5100 2600 3500
Wire Notes Line width 20
	1100 3500 1100 5100
NoConn ~ 5500 3950
NoConn ~ 5500 3850
NoConn ~ 5500 3750
NoConn ~ 5500 3650
NoConn ~ 5500 3550
NoConn ~ 5500 3150
NoConn ~ 5500 3050
NoConn ~ 5500 2950
NoConn ~ 5500 2850
NoConn ~ 5500 2750
NoConn ~ 5500 2650
NoConn ~ 5500 2450
NoConn ~ 5500 2350
NoConn ~ 5500 2250
NoConn ~ 5500 2150
NoConn ~ 5500 2050
NoConn ~ 5500 1950
NoConn ~ 5000 1450
NoConn ~ 4300 1750
$Comp
L Switch:SW_Push SW1
U 1 1 60AECAD3
P 5750 3250
F 0 "SW1" H 5750 3535 50  0000 C CNN
F 1 "SW_Push" H 5750 3444 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5750 3450 50  0001 C CNN
F 3 "~" H 5750 3450 50  0001 C CNN
	1    5750 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR010
U 1 1 60AED601
P 6000 3250
F 0 "#PWR010" H 6000 3000 50  0001 C CNN
F 1 "GND1" H 6250 3250 50  0000 R CNN
F 2 "" H 6000 3250 50  0001 C CNN
F 3 "" H 6000 3250 50  0001 C CNN
	1    6000 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3250 5550 3250
Wire Wire Line
	5950 3250 6000 3250
$Comp
L MyLib_oldICs:LB1641 U1
U 1 1 60CF24EA
P 8500 2000
F 0 "U1" H 8000 2350 60  0000 L CNN
F 1 "LB1641" H 8650 2350 60  0000 L CNN
F 2 "Package_SIP:SIP-9_22.3x3mm_P2.54mm" H 8600 2050 60  0001 C CNN
F 3 "" H 8600 2050 60  0001 C CNN
	1    8500 2000
	1    0    0    -1  
$EndComp
$Comp
L MyLib_KeyestudioModules:BT_BOARD_V2.0 U4
U 1 1 60CF5942
P 1550 4300
F 0 "U4" H 1350 4750 50  0000 R CNN
F 1 "BT_BOARD_V2.0" H 2050 3850 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 1550 3750 50  0001 C CNN
F 3 "" H 1300 3950 50  0001 C CNN
	1    1550 4300
	1    0    0    -1  
$EndComp
NoConn ~ 1950 4000
NoConn ~ 1950 4300
NoConn ~ 1950 4600
NoConn ~ 7800 1800
Wire Wire Line
	8200 2600 8300 2600
Wire Wire Line
	8300 2600 8300 2500
Connection ~ 8200 2600
Wire Wire Line
	8500 2500 8600 2500
Wire Wire Line
	9200 1900 9600 1900
Wire Wire Line
	9600 1900 9600 1850
Wire Wire Line
	9600 1850 9800 1850
Connection ~ 9800 1850
Wire Wire Line
	9200 2100 9600 2100
Wire Wire Line
	9600 2100 9600 2150
Wire Wire Line
	9600 2150 9800 2150
Connection ~ 9800 2150
Wire Wire Line
	7700 2100 7800 2100
Wire Wire Line
	7800 2200 7700 2200
Wire Wire Line
	8250 1400 8250 1500
Wire Wire Line
	8250 1500 8300 1500
Wire Wire Line
	8450 1400 8450 1500
Wire Wire Line
	8450 1500 8400 1500
$Comp
L Motor:Motor_DC M2
U 1 1 60D18C79
P 10250 3900
F 0 "M2" H 10408 3896 50  0000 L CNN
F 1 "Motor_DC" H 10408 3805 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 10250 3810 50  0001 C CNN
F 3 "~" H 10250 3810 50  0001 C CNN
	1    10250 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60D18C7F
P 9800 3950
F 0 "C3" H 9915 3996 50  0000 L CNN
F 1 "0.1" H 9915 3905 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.0mm_W2.5mm_P5.00mm" H 9838 3800 50  0001 C CNN
F 3 "~" H 9800 3950 50  0001 C CNN
	1    9800 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 3800 9800 3700
Wire Wire Line
	9800 3700 10250 3700
Wire Wire Line
	9800 4100 9800 4200
Wire Wire Line
	9800 4200 10250 4200
$Comp
L power:+9V #PWR012
U 1 1 60D18C89
P 8450 3350
F 0 "#PWR012" H 8450 3200 50  0001 C CNN
F 1 "+9V" H 8465 3523 50  0000 C CNN
F 2 "" H 8450 3350 50  0001 C CNN
F 3 "" H 8450 3350 50  0001 C CNN
	1    8450 3350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 60D18C8F
P 8250 3350
F 0 "#PWR011" H 8250 3200 50  0001 C CNN
F 1 "+5V" H 8265 3523 50  0000 C CNN
F 2 "" H 8250 3350 50  0001 C CNN
F 3 "" H 8250 3350 50  0001 C CNN
	1    8250 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR014
U 1 1 60D18C95
P 7950 4550
F 0 "#PWR014" H 7950 4300 50  0001 C CNN
F 1 "GND1" H 7955 4377 50  0000 C CNN
F 2 "" H 7950 4550 50  0001 C CNN
F 3 "" H 7950 4550 50  0001 C CNN
	1    7950 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR015
U 1 1 60D18C9B
P 8200 4550
F 0 "#PWR015" H 8200 4300 50  0001 C CNN
F 1 "GND2" H 8205 4377 50  0000 C CNN
F 2 "" H 8200 4550 50  0001 C CNN
F 3 "" H 8200 4550 50  0001 C CNN
	1    8200 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4550 8200 4550
$Comp
L Device:C C4
U 1 1 60D18CA2
P 8650 4700
F 0 "C4" V 8500 4800 50  0000 C CNN
F 1 "0.1" V 8500 4600 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.0mm_W2.5mm_P5.00mm" H 8688 4550 50  0001 C CNN
F 3 "~" H 8650 4700 50  0001 C CNN
	1    8650 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8500 4450 8500 4700
Wire Wire Line
	8700 4450 8800 4450
Wire Wire Line
	8800 4450 8800 4700
$Comp
L MyLib_oldICs:LB1641 U3
U 1 1 60D18CAB
P 8500 3950
F 0 "U3" H 8000 4300 60  0000 L CNN
F 1 "LB1641" H 8650 4300 60  0000 L CNN
F 2 "Package_SIP:SIP-9_22.3x3mm_P2.54mm" H 8600 4000 60  0001 C CNN
F 3 "" H 8600 4000 60  0001 C CNN
	1    8500 3950
	1    0    0    -1  
$EndComp
NoConn ~ 7800 3750
Wire Wire Line
	8200 4550 8300 4550
Wire Wire Line
	8300 4550 8300 4450
Connection ~ 8200 4550
Wire Wire Line
	8500 4450 8600 4450
Wire Wire Line
	9200 3850 9600 3850
Wire Wire Line
	9600 3850 9600 3800
Wire Wire Line
	9600 3800 9800 3800
Connection ~ 9800 3800
Wire Wire Line
	9200 4050 9600 4050
Wire Wire Line
	9600 4050 9600 4100
Wire Wire Line
	9600 4100 9800 4100
Connection ~ 9800 4100
Wire Wire Line
	7700 4050 7800 4050
Wire Wire Line
	7800 4150 7700 4150
Wire Wire Line
	8250 3350 8250 3450
Wire Wire Line
	8250 3450 8300 3450
Wire Wire Line
	8450 3350 8450 3450
Wire Wire Line
	8450 3450 8400 3450
Text Label 5550 1750 0    50   ~ 0
Pin_8
Text Label 5550 1850 0    50   ~ 0
Pin_9
Text Label 5550 4050 0    50   ~ 0
Pin_6
Text Label 5550 4150 0    50   ~ 0
Pin_7
Text Notes 7350 1200 0    50   ~ 10
Motor 1, izq
Text Notes 7350 3150 0    50   ~ 10
Motor 2, der
Wire Wire Line
	1450 4800 1450 4850
Wire Wire Line
	1450 3800 1450 3750
$EndSCHEMATC
