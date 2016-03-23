all: sendPT2262

sendPT2262: RCSwitch.o sendPT2262.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o sendPT2262
