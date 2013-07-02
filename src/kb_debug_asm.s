.syntax unified
.cpu cortex-m3
.thumb

.global HardFaultVector
.extern hard_fault_handler_c

HardFaultVector:
  TST LR, #4
  ITE EQ
  MRSEQ R0, MSP
  MRSNE R0, PSP
  B hard_fault_handler_c
