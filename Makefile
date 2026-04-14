all:
	gcc boilerplate/engine.c -o boilerplate/engine
	gcc cpu_test.c -o boilerplate/cpu_test

clean:
	rm -f boilerplate/engine boilerplate/cpu_test
