main : main.o
	@echo "Criando arquivo executável"
	gcc main.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main

main.o : main.c
	@echo "Criando arquivo main"
	gcc -c main.c -o main.o

clean : 
	@echo "Limpando arquivos"
	rm -f main.o main

run :
	@echo "Abrindo jogo"
	./main