CXX      := g++
SYSTEMC_HOME := /usr/local/systemc-2.3.3
CXXFLAGS := -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64
LDFLAGS  := -L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lm
INCLUDE  := -I$(SYSTEMC_HOME)/include
SRC      :=  $(wildcard *.cpp)
OBJECTS  := $(SRC:%.cpp=%.o)

TARGET   := app

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LDFLAGS)

.PHONY: all clean debug release

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf *.o $(TARGET)