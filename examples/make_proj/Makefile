
CXX = em++ -std=c++20 -O3
BIN_DIR = bin
EXE = $(BIN_DIR)/index.html
LIVID_DIR = ../..
SOURCES = elmish.cpp
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
CPPFLAGS = -I$(LIVID_DIR)/include
LDFLAGS = -s WASM=1 --bind
LDFLAGS += --shell-file my_shell.html

%.o:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(EXE)

$(BIN_DIR):
	mkdir $@

serve: all
	python3 -m http.server -d $(BIN_DIR)

$(EXE): $(OBJS) $(BIN_DIR)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(OBJS) $(BIN_DIR)