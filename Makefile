push:
	git add .
	git commit -m "Changes"
	git push

run:
	gcc -g -o palindrome is_palindrome.c
	./palindrome.exe
