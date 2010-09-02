
define ConvertToObjectNames
  $(patsubst %.cpp,%.o,$(1))
endef

define CreateCompileTargets
  # Create *.c targets from $(1)
  $(foreach file,$(filter %.cpp,$(1)),
    # Load dependency file (if present)
    -include build_dir/$(file:.cpp=.d)

    #Target first builds a file containing dependencies (for a next time)
    #  then compiles the file
    build_dir/$(file:.cpp=.o): src/$(file) | build_dir
	$(CXX) -MM $(CFLAGS) $(CPPFLAGS) -o build_dir/$(file:.cpp=.d) $$<
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c -o $$@ $$<
  )
endef

# Add targets for the required directories
build_dir bin:
	@mkdir -p $@

