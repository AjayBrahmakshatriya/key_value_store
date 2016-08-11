all:
	@mkdir -p build
	$(MAKE) -C lib
	$(MAKE) -C examples

clean:
	@rm -rf build
