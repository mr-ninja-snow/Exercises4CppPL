AM_CXXFLAGS = -std=c++11 -D__USE_XOPEN2K8

THESE_CPPFLAGS = \
	-I$(srcdir)/src

THESE_SRC = \
	desk_calc.cpp\
	desk_calc_err.cpp\
	TokenParser.cpp

noinst_LIBRARIES = libdeskcalc.a
libdeskcalc_a_SOURCES = $(THESE_SRC)
libdeskcalc_a_CPPFLAGS = $(THESE_CPPFLAGS) $(AM_CXXFLAGS) -ggdb3