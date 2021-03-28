;--------------------------------------------------------------
; Resource table required by Linux Remoteproc
;--------------------------------------------------------------
  .sect ".resource_table"
  .retain

; struct resource_table {
;        uint32_t ver;
;        uint32_t num;
;        uint32_t reserved[2];
;};

	.word	0x1
	.word	0
	.word	0
	.word	0

 .sect ".version_string"
 .retain
 .include "version_file.h"
