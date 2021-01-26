TESTQSPROGRAMS = testqs0 testqs1 testqs2 testqs3 testqs4 testqs5
ALLPROGRAMS = $(TESTQSPROGRAMS)

all: $(ALLPROGRAMS)

include ../../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

testqs: $(TESTQSPROGRAMS)

testqs0: testqs0.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs1: testqs1.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs2: testqs2.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs3: testqs3.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs4: testqs4.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

testqs5: testqs5.o qslib.o allowexec.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR) qs.jarr qsml qs.cmi qs.cmo *.class

.PHONY: all clean
