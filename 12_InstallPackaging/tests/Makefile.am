if HAVE_CHECK
TESTS = test_converter
check_PROGRAMS = test_converter

test_converter_SOURCES = test_converter.c
test_converter_CPPFLAGS = -I$(top_srcdir)/src $(CHECK_CFLAGS)
test_converter_LDADD = $(top_builddir)/src/libconverter.a $(CHECK_LIBS)
endif