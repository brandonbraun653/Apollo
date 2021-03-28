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
rm -rf tools/flash_writer/nand_flash_writer_AM335x.out
rm -rf tools/flash_writer/spi_flash_writer_AM335X.out
rm -rf binary/


#build instructions for bootloader

ls

alias CLEAN_OBJ="find ./ -name "*.[ao]" -delete"

make clean -s KW_BUILD=no

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=uart PLATFORM=am43xx-evm PROFILE=debug -s KW_BUILD=no ${1}
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=uart PLATFORM=am43xx-evm PROFILE=release -s KW_BUILD=no ${1}

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mmcsd PLATFORM=am43xx-evm PROFILE=debug -s KW_BUILD=no ${1}
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=mmcsd PLATFORM=am43xx-evm PROFILE=release -s KW_BUILD=no ${1}

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=nand PLATFORM=am43xx-evm PROFILE=debug -s KW_BUILD=no ${1}
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=nand PLATFORM=am43xx-evm PROFILE=release -s KW_BUILD=no ${1}

(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=qspi PLATFORM=am43xx-evm PROFILE=debug -s KW_BUILD=no ${1}
(CLEAN_OBJ)
make -s bootloader BUILDCFG=boot BOOTMODE=qspi PLATFORM=am43xx-evm PROFILE=release -s KW_BUILD=no ${1}


make PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

make vpfe_app_capture_display PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make vpfe_app_capture_display PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

make cap_tsc_app PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make cap_tsc_app PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

make dss_app_raster PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make dss_app_raster PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

make qspi_app_flash_writer PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make qspi_app_flash_writer PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

make qspi_app_read_write PROFILE=debug PLATFORM=am43xx-evm -s KW_BUILD=no ${1}
make qspi_app_read_write PROFILE=release PLATFORM=am43xx-evm -s KW_BUILD=no ${1}

# Remove unnecessary files from packaging
find . -name "obj" | xargs rm -rf
find . -name "debug" | xargs rm -rf

#archieve
tar -cf starterware_am437x.tar --exclude='*.tar' ./*

mkdir ti
cd ti
mkdir starterware
cd starterware
tar -xvf ../../starterware_am437x.tar .
rm ../../starterware_am437x.tar

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

tar -cf starterware_am437x.tar --exclude='*.tar' ./
