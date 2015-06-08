AM_CXXFLAGS = -std=c++11 -D__USE_XOPEN2K8

C15_X2_CPPFLAGS = \
	-I$(top_srcdir)/src

bin_PROGRAMS = c15_x2

c15_x2_LDADD = \
	$(top_builddir)/src/libdeskcalc.a

c15_x2_SOURCES = \
	main.cpp

c15_x2_CPPFLAGS = $(C15_X2_CPPFLAGS) $(AM_CPPFLAGS) -ggdb3
