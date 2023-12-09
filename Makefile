push:
	git add .
	git commit -m "Changes"
	git push

compile:
	gcc -o map map.c -lm
	gcc -o main map_main.c -lm
