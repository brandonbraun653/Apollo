Flash the following binaries on iceAMIC110 using SPI flash writer

Binary--------------------------------------------Flash Offset
bootloader_boot_mcspi_noDDR_a8host_release_ti.bin 0x00000
binData1_ti.bin                                   0x14000
binData2_ti.bin                                   0x19000
binData3_ti.bin                                   0x10000
ddrless_app_TEST(App)                             0x20000



Location of binaries:

* App and binData: PDK_INSTALL_PATH\packages\ti\board\bin\iceAMIC110\ddrless_app\spi
* Bootloader: PDK_INSTALL_PATH\ti\ti\starterware\binary\bootloader\bin\amic110-ddrless\gcc