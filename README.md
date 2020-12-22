# pluCapstone
Handwritten OS for Raspberry Pi 

# Toolchain Setup
In order to be able to effectivly compile this OS, need to create custom GCC toolchain for the ARM 64-bit chip set
Followed this wiki page for setup: https://wiki.osdev.org/GCC_Cross-Compiler
Needed: Fresh download of GCC & Binutils

Steps(high level):
1)Configure binutils inside folder with following flags;  
configure --target=aarch64-elf --prefix=/path/to/where/want/install/toolchain --with-sysroot --disable-nls --disable-werror

2)Run make and make install for binutils

3)Configure GCC inside folder with following flags;  
configure --target=aarch64-elf --prefix="/path" --disable-nls --enable-languages=c --without-headers

4)Run commands in this order:
make all-gcc  
make all-target-libgcc  
make install-gcc  
make install-target-libgcc  

# Using toolchain
Need to specify into the bin folder inside where installed toolchain to access the tools, i.e. if installed in just Desktop on a linux machine would look like this

$HOME/Desktop/bin/aarch64-elf-gcc

# Using make for kernel creation
Currently need to edit the makefile included to have machine specfic destinations for where the source directory is as well as where the toolchain was setup. Makefile uploaded is specific to my windows machine running the command in a WSL terminal

Key test
