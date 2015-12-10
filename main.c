#include <stdio.h>
#include <vegeneri.h>
#include <string.h>

void show_help();	// Mensagem de ajuda
void show_error();	// Mensagem de erro

int main(int argc, char **argv){
	int x,y;
	unsigned char cri = 1;
	char *value;
	char *swap;
	unsigned char *key;
	/*
	 * O for percorre os parametros que iniciem com o caracter "-"
	 * para recolher as configurações
	 */
	for(x=1;x<argc;x++){
		if(argv[x][0] == '-'){
			swap = argv[x];
			for(y=1;y<strlen(swap);y++)
				if(swap[y] == 'k')
					//sscanf(argv[++x],"%i",&key);	// Coleta a chave da criptografia
					key = argv[++x];
				else if(swap[y] == 's')
					value = argv[++x];		// Coleta o texto da criptografia
				else if(swap[y] == 'c')
					cri = 1;			// Define se vai criptografas ou descriptografar o texto
				else if(swap[y] == 'd')
					cri = 0;
				else if(swap[y] == 'h'){		// Chame a documentação
					show_help();
					return 0;
				}
				else{
					show_error();
					return 1;
				}
		}
		else{
			show_error();
			return 1;
		}
	}

	if(cri > 1){
		show_error();
		return 1;
	}

	/*
	 * Executa a ação de criptografia
	 */
	if(cri)
		swap = vigenere(key, CRIPT, value);
	else
		swap = vigenere(key, DECRIPT, value);

	if(!swap)
		show_error();
	printf("%s",swap);// imprime na tela

	return 0;
}

void show_help(){
	puts("Use chars between A-z and a-z.\n");
	puts("Usage: cesar -ksc <number> <string>");
	puts("Usage: cesar -ksd <number> <string>");
	puts("");
	puts("	-k n		Key to cript or decript");
	puts("	-s <str>	String");
	puts("	-c		Cript string");
	puts("	-d		Decript string");
	puts("	-h		Show Help\n");
}
void show_error(){
	puts("Can net cript this string.\nUse -h to show help.");
}
