push:
	git add .
	git commit -m "Changes"
	git push

run:
	gcc -g -o main main.c
	./main.exe

