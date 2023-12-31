#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
# Arguments:
#		CC - Compiler that will perform the build (Native or Cross)
#		CFLAGS - C-programming flags for gcc
#		CPPFLAGS - C-Preprocessor Flags
#		LDFLAGS - Linker Flags
#		PLATFORM - The target platform you are compiling for (Platform Specific)
#		SOURCES - The list of sources files that will need to be compiled (Platform specific)
#		INCLUDES - The list of include directories ( Hint: Use the -I flag )
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# # Architectures Specific Flags
# LINKER_FILE = 
# CPU = 
# ARCH = 
# SPECS = 

# # Compiler Flags and Defines
# CC = 
# LD = 
# LDFLAGS = 
# CFLAGS = 
# CPPFLAGs = 

# General Flags for all platforms
GEN_FLAGS = \
			-Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99

TARGET = c1m2

# Platform Dependant Variables
ifeq ($(PLATFORM), MSP432)
	# MSP432 dependant build options
	CPU = cortex-m4
	ARCH = armv7e-m

	SOURCES += 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES += -I ../include/CMSIS/ \
				-I ../include/msp432/

	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size

	# Linker Flags
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	# Compiler Flags
	CFLAGS = 	$(GEN_FLAGS) \
				-mcpu=$(CPU) \
				-mthumb \
				-march=$(ARCH) \
				-mfloat-abi=hard \
				-mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGS =  -DMSP432 $(INCLUDES)


else
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size

endif

PREP = $(SOURCES:.c=.i)	# Preprocessor Files
DEPS = $(SOURCES:.c=.d)	# Dependancy Files
ASMS = $(SOURCES:.c=.asm) # Assembly Files
OBJS = $(SOURCES:.c=.o)	# Object files

.PHONY: compile-all build clean

# Compile all object files and link into a final executable.
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	
# Generate Preprocesed output of all c-program implementation files (use the -E flag)
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate Dependancy files for each Source File
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@

# Compile all object files, but DO NOT link.
compile-all: $(OBJS)

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f *.out *.map *.o *.asm *.i

