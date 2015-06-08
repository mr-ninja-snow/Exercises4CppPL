AM_CXXFLAGS = -std=c++11 -D__USE_XOPEN2K8

TESTDC_CPPFLAGS = \
	-I$(top_srcdir)/libs/cpputest/include\
	-I$(top_srcdir)/src

TESTS = testdc
bin_PROGRAMS = testdc
check_PROGRAMS = testdc

testdc_LDADD = \
	$(top_srcdir)/libs/cpputest/lib/libCppUTest.a\
	$(top_srcdir)/libs/cpputest/lib/libCppUTestExt.a\
	$(top_builddir)/src/libdeskcalc.a


TESTDC_SRC = \
	src/TestDeskCalc.cpp\
	TestMain.cpp

testdc_CPPFLAGS = $(TESTDC_CPPFLAGS) $(AM_CPPFLAGS) -ggdb3
testdc_SOURCES = $(TESTDC_SRC)
