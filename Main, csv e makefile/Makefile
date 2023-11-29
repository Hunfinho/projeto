main : main.o arquivos.o pokedex.o colecao.o mochila.o
	@echo "Criando arquivo executável"
	gcc main.o arquivos.o pokedex.o colecao.o mochila.o -o main

main.o : main.c 
	@echo "Criando arquivo main"
	gcc -c main.c

arquivos.o : arquivos.c
	@echo "Gerando biblioteca de arquivos"
	gcc -c arquivos.c

pokedex.o : pokedex.c
	@echo "Gerando biblioteca da pokedex"
	gcc -c pokedex.c

colecao.o : colecao.c
	@echo "Gerando biblioteca da coleção"
	gcc -c colecao.c

mochila.o : mochila.c
	@echo "Gerando biblioteca da mochila"
	gcc -c mochila.c

clean : 
	@echo "Limpando arquivos"
	rm -f main.o arquivos.o pokedex.o colecao.o mochila.o main

run : 
	@echo "Executando programa"
	./main