  .global CycleCountEnable
  .global CycleCounterRegRead

  .text

  .code 32

CycleCountEnable:
  MOV r0, #(1<<0)|(1<<2)
  MCR p15, #0, r0, c9, c12, #0
  MOV r0, #(1<<31)
  MCR p15, #0, r0, c9, c12, #1
  BX  lr

CycleCounterRegRead:
  MRC p15, #0, r0, c9, c13, #0
  BX      lr

