# Compiler flags: all warnings + debugger meta-data
CFLAGS = -Wall -g

# External libraries: only math in this example
LIBS = -lm

# Pre-defined macros for conditional compilation
DEFS = #-DDEBUG_FLAG -DEXPERIMENTAL=0

# The final executable program file, i.e. name of our program
BIN = AppExample

# Build directory for the final executable
BUILD_DIR = ../build

# Compiler (gcc or # $(CC) for clang)
COMPILER = gcc #$(CC) 

# Object files from which $BIN depends
OBJS = LOGGER.o RBUFFER.o VSAPPS_helpers.o

# This default rule compiles the executable program
$(BIN): $(OBJS) $(BIN).c
	$(COMPILER) $(CFLAGS) $(DEFS) $(LIBS) $(OBJS) $(BIN).c -o $(BUILD_DIR)/$(BIN)

# This rule compiles each module into its object file
%.o: %.c %.h
	$(COMPILER) -c $(CFLAGS) $(DEFS) $< -o $@
clean:
	rm -r -f *~ *.o $(BUILD_DIR)/*.dSYM $(BUILD_DIR)/$(BIN)
depend:
	makedepend -Y -- $(CFLAGS) $(DEFS) -- *.c