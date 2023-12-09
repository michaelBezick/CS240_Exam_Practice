push:
	git add .
	git commit -m "Changes"
	git push

run:
	gcc -g -o main map_main.c
	./main.exe

