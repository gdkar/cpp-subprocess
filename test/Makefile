CXXFLAGS += -std=gnu++11 -pthread

targets := $(patsubst %.cc,bin/%,$(wildcard *.cc))

all: ${targets}

bin/%: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@rm -r bin
