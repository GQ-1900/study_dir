objects = main.o MsgAllocator.o

autoMsg:$(objects)
	@echo 'building target:$@'
	g++ -o autoMsg $(objects)
	@echo 'finished building target:$@'
clean:
	rm autoMsg $(objects)
