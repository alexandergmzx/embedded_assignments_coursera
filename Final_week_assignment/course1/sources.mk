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

# Source files defined based on the Platform.    

ifeq ($(PLATFORM), MSP432)
	SRCS =  ./src/main.c \
		./src/memory.c \
		./src/stats.c \
		./src/data.c \
		./src/course1.c \
	        ./src/interrupts_msp432p401r_gcc.c \
	        ./src/startup_msp432p401r_gcc.c \
	        ./src/system_msp432p401r.c
else
	SRCS =  ./src/main.c \
		./src/memory.c \
		./src/stats.c \
		./src/data.c \
		./src/course1.c 
endif

ifeq ($(PLATFORM), MSP432)
	INCLUDES = -I ./include/common \
		       -I ./include/msp432 \
		       -I ./include/CMSIS
else
	INCLUDES = -I ./include/common
endif


