# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\11800025\Documents\GitHub\Rc_Car_Full_Project\RC_Car_FullProject\RC_Car_LE_Bluetooth.cydsn\RC_Car_LE_Bluetooth.cyprj
# Date: Tue, 15 Sep 2020 19:48:18 GMT
#set_units -time ns
create_clock -name {UART_SCBCLK(FFB)} -period 729.16666666666663 -waveform {0 364.583333333333} [list [get_pins {ClockBlock/ff_div_1}]]
create_clock -name {Clock(FFB)} -period 58833.333333333328 -waveform {0 29416.6666666667} [list [get_pins {ClockBlock/ff_div_7}] [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {Clock_1(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFClk} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 35 71} [list]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 2825 5649} -nominal_period 58833.333333333328 [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 481 961} [list]


# Component constraints for C:\Users\11800025\Documents\GitHub\Rc_Car_Full_Project\RC_Car_FullProject\RC_Car_LE_Bluetooth.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\11800025\Documents\GitHub\Rc_Car_Full_Project\RC_Car_FullProject\RC_Car_LE_Bluetooth.cydsn\RC_Car_LE_Bluetooth.cyprj
# Date: Tue, 15 Sep 2020 19:48:14 GMT