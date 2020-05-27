CXX      := g++
SYSTEMC_HOME := /usr/local/systemc-2.3.3
CXXFLAGS := -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64
LDFLAGS  := -L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lm
INCLUDE  := -I$(SYSTEMC_HOME)/include
SRC      := $(wildcard *.cpp)
OBJECTS  := $(SRC:%.cpp=%.o)
WAVEFORM := $(wildcard *.vcd)
DISPLAY  := gtkwave

TARGET   := app

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LDFLAGS)

.PHONY: all clean debug release run

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

run : $(WAVEFORM)
	$(DISPLAY) $^

clean:
	-@rm -rvf *.o $(TARGET) $(WAVEFORM)