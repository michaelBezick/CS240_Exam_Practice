push:
	git add .
	git commit -m "Changes"
	git push

compile:
	gcc -o main map_main.c
	gcc -o map map.c
