all: sendElro sendRev

sendElro: HomeControl.o sendElro.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendRev: HomeControl.o sendRev.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o sendElro sendRev
