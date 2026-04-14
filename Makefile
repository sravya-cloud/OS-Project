all:
	gcc engine.c -o engine
	gcc cpu_test.c -o cpu_test

clean:
	rm -f engine cpu_test
