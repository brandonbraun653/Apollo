# Go to Starterware root directory
cd ..

find . -name "*.git*" | xargs rm -rf
find . -name ".gitignore" | xargs rm -rf

rm -rf .git
rm -rf tools/ti_image/gcc/
rm -rf tools/ais_gen/
rm -rf tools/out2rprc
rm -rf tools/pru_image
rm -rf tools/bmp2c
rm -rf tools/flash_writer/src/nand-flash-writer_AM335x/bin
rm -rf tools/flash_writer/src/spi-flash-writer_AM335x/bin
rm -rf binary/

#build instructions for bootloader

ls

alias CLEAN_OBJ="find ./ -name "*.[ao]" -delete"

make clean -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=uart PLATFORM=am335x-evm PROFILE=debug -s KW_BUILD=no
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=uart PLATFORM=am335x-evm PROFILE=release -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mmcsd PLATFORM=am335x-evm PROFILE=debug -s KW_BUILD=no
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mmcsd PLATFORM=am335x-evm PROFILE=release -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=nand PLATFORM=am335x-evm PROFILE=debug -s KW_BUILD=no
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=nand PLATFORM=am335x-evm PROFILE=release -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mcspi PLATFORM=am335x-evm PROFILE=debug -s KW_BUILD=no
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mcspi PLATFORM=am335x-evm PROFILE=release -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mcspi PLATFORM=amic110-ddrless PROFILE=debug -s KW_BUILD=no BUILD_ICSS_DDRLESS_BOOT=yes
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mcspi PLATFORM=amic110-ddrless PROFILE=release -s KW_BUILD=no BUILD_ICSS_DDRLESS_BOOT=yes

make PROFILE=debug PLATFORM=am335x-evm -s KW_BUILD=no
make PROFILE=release PLATFORM=am335x-evm -s KW_BUILD=no

make lcdc_app_raster PROFILE=debug PLATFORM=am335x-evm -s KW_BUILD=no
make lcdc_app_raster PROFILE=release PLATFORM=am335x-evm -s KW_BUILD=no

make mcspi_app_flash PROFILE=debug PLATFORM=am335x-evm -s KW_BUILD=no
make mcspi_app_flash PROFILE=release PLATFORM=am335x-evm -s KW_BUILD=no

# Remove unnecessary files from packaging
find . -name "obj" | xargs rm -rf
find . -name "debug" | xargs rm -rf

#archieve

tar -cf starterware_am335x.tar --exclude='*.tar' ./*

mkdir ti
cd ti
mkdir starterware
cd starterware
tar -xvf ../../starterware_am335x.tar .
rm ../../starterware_am335x.tar

${XDC_INSTALL_PATH}/xdc -P board
${XDC_INSTALL_PATH}/xdc -P dal
${XDC_INSTALL_PATH}/xdc -P device
${XDC_INSTALL_PATH}/xdc -P examples/example_utils
${XDC_INSTALL_PATH}/xdc -P soc
${XDC_INSTALL_PATH}/xdc -P utils

# Remove unnecessary XDC files from packaging
find . -name ".executables" | xargs rm
find . -name ".interfaces" | xargs rm
find . -name ".libraries" | xargs rm
find . -name ".xdcenv.mak" | xargs rm
find . -name ".dlls" | xargs rm

tar -cf starterware_am335x.tar --exclude='*.tar' ./
