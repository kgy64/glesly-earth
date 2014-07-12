# Makefile for my GLES-based library: Glesly
#

NAME                 =  Glesly_Earth
VERS_MAJOR           =  0
VERS_MINOR           =  1

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

.PHONY: all
all: _everything

export SRCDIR        =  .

SHADER_PATH          =  $(SRCDIR)/shaders

include $(SCRIPTDIR)/makelib
include $(GLSCRIPTS)/shader.rules

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

.PHONY: clean
clean:
	@echo " - Cleaning $(NAME)..."
	@rm -f $(BINDIR)/* $(OBJECTS) $(Y_CPPFILES) $(Y_HEADERS) $(DEPENDS) $(SHADER_HEADERS) $(SHADER_SOURCES)

