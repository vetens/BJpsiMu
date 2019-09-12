# Set project directory to one level above build directory. CURDIR is current working directory
# Also set Source and Build directories
PROJDIR := $(realpath $(CURDIR)/..)
SOURCEDIR := $(PROJDIR)/source
BUILDDIR := $(PROJDIR)/build
OBJDIR := $(BUILDDIR)/obj

# CFLAGS and LIBS are flags required for building with ROOT

CFLAGS=$(shell root-config --cflags)
LIBS=$(shell root-config --libs)

# To make in debug mode (gdb), just type 
# make DEBUG=true

ifdef DEBUG
CFLAGS+= -g
LIBS+= -g
endif

# read the make commands from the bottom up ;], that's the order they're executed from when everything's clean
# it's defined this way so that calling `make` will automatically run `all` with all prerequisites
# make only remakes the objects and libraries if theyre older than the source files
#---------------------------------------------------------------------------------------------------------------
#
# Finally, we set making the target as the default make command

all: $(BUILDDIR)/genlevel.exe

# here's the step where the executable is compiled, drawing on all our object and library files

$(BUILDDIR)/genlevel.exe: $(OBJDIR)/GLPlots.o $(OBJDIR)/GenLevel.o $(BUILDDIR)/GenLevel.cxx
	g++ $^ -o $@ $(LIBS) $(CFLAGS)

# This object file has two prerequisites, because its based off of a program split into multiple files
# Needs both as prerequisites, but .h as a header file doesn't need to be explicitly called by g++
# hence the $< rather than $^

$(OBJDIR)/GenLevel.o: $(SOURCEDIR)/GenLevel.C $(SOURCEDIR)/GenLevel.h 
	g++ -c $< -o $@ $(CFLAGS)

# % here is a wildcard. It basically tells make, for every .h file, make a corresponding .cxx Library file
# and root .pcm dictionary module with the same name. Rootcint automatically makes both of them.
# $^ means all the prerequisites, not just the first (which is what $< means, see below)

$(BUILDDIR)/%.cxx: $(SOURCEDIR)/%.h
	rm -f $@
	rootcint $@ -c $^

# $< means the first prerequisite, in this case GetFR.C
# $@ means the file being made, in this case GETFR.o
# | $(OBJDIR) means that if OBJDIR doesn't exist, make that first!
# $(CFLAGS) means compiling with some of the needed flags for things to work with root
# -c means that $<, aka GetFR.C is the source file used, it is being compiled but not linked
# -o means we are specifying the output file as $(OBJDIR)/$@, aka build/obj/GetFR.o

$(OBJDIR)/GLPlots.o: $(SOURCEDIR)/GLPlots.C | $(OBJDIR)
	g++ -c $< -o $@ $(CFLAGS)

# make the object directory if it doesn't already exist

$(OBJDIR):
	mkdir $(OBJDIR)

# get rid of all the generated libraries and executables
# the `.PHONY:` basically tells make that this isn't some file named clean

.PHONY: clean

clean:
	rm -f -r $(OBJDIR) *.cxx *.pcm genlevel.exe
