bin_PROGRAMS = temp_converter

temp_converter_SOURCES = main.c converter.c converter.h

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"

AM_CPPFLAGS = -I/opt/homebrew/opt/gettext/include
AM_LDFLAGS = -L/opt/homebrew/opt/gettext/lib
LDADD = -lintl