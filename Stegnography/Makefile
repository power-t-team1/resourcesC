
steg : main.o encryption.o dycryption.o
	cc $^ -o $@

main.o :  main.c
	cc -c $^

encryption.o : encryption.c
	cc -c $^

dycryption.o : dycryption.c
	cc -c $^

clean : 
	rm *.o steg
