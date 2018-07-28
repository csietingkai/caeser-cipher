CPP=g++
CPPFLAGS=-g -pthread -std=c++11
LDFLAGS=-g

EXENAME=cipher.exe
OBJS=main.o common.o Encoder.o Decoder.o Dictionary.o Checker.o

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(CPP) $(LDFLAGS) -o $(EXENAME) $(OBJS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

common.o: common.cpp common.h
	$(CPP) $(CPPFLAGS) -c common.cpp

Encoder.o: Encoder.cpp Encoder.h
	$(CPP) $(CPPFLAGS) -c Encoder.cpp

Decoder.o: Decoder.cpp Decoder.h
	$(CPP) $(CPPFLAGS) -c Decoder.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	$(CPP) $(CPPFLAGS) -c Dictionary.cpp

Checker.o: Checker.cpp Checker.h
	$(CPP) $(CPPFLAGS) -c Checker.cpp

clean:
	rm -rf $(OBJS)

