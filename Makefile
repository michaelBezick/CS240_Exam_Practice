push:
	git add .
	git commit -m "Changes"
	git push

compile:
	gcc -g -o main map_main.c -lm
	gcc -g -o map map.c -lm
