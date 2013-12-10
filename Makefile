all: sendElro sendRev

sendElro: HomeControl.o HomeControlAPI.o sendElro.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendRev: HomeControl.o HomeControlAPI.o sendRev.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
        $(RM) *.o sendElro sendRev