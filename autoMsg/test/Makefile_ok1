objects = main.o MsgAllocator.o

autoMsg:$(objects)
	@echo 'building target:$@'
	g++ -o autoMsg $(objects)
	@echo 'finished building target:$@'
.PHONY:clean
clean:
	rm autoMsg $(objects)
