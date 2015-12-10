#include <vigenere.h>
#include <string.h>

/*
 * Este método usa a criptografia de cesar para criptografar menssagens
 * Parametros:
 * 	chave de valor inteiro
 * 	tipo de ação do método "criptografar" ou "descriptografar"
 * 	texto a ser processado
 * O retorno deverá ser o texto criptografado ou descriptografado
 */

unsigned char is_not_char(unsigned char c);

extern unsigned char *vigenere(const char *key, unsigned char action, const char *value){
	int len = strlen(value);
	int klen = strlen(key);
	int x,y=0;

	unsigned char *swap;
	unsigned char *skey;
	skey = (unsigned char*) malloc(klen);
	strcpy(skey,key);
	if(action == CRIPT){ /*Verifica se vai criptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap, value);
		for(x=0; x<len; x++){
			if(is_not_char(swap[x])){
				skey[y] = toupper(skey[y]);
				swap[x] = toupper(swap[x]);	// Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "65" para "0"
				 */
				swap[x] -= 65;
				skey[y] -= 65;
				if(swap[x] < 0 || swap[x] > 26) // se o valor nao estiver entre 0 e 26, nao e' feito a criptografia
					return NULL;
				swap[x] = ((int)swap[x] + (skey[y%klen])) % 26;
				swap[x] += 65;
				y++;
			}
		}
	}
	else if(action == DECRIPT){ /*Verifica se vai descriptografar*/
		swap = (unsigned char*) malloc(len);
		strcpy(swap,value);
		for(x=0; x<len; x++){
			if(is_not_char(swap[x])){
				skey[y] = toupper(skey[y]);
				swap[x] = toupper(swap[x]); // Passa os caracteres para maiusculo
				/*
				 * Este block passa o caracter para "65" para "0"
				 */
				swap[x] -= 65;
				skey[y] -= 65;
				if(swap[x] < 0 || swap[x] > 26) // se o valor nao estiver entre 0 e 26, nao e' feito a criptografia
					return NULL;
				signed int c = ((signed int) swap[x] - (skey[y%klen])%26);
				c = (c < 0 ? 26+c : c);
				swap[x] = (unsigned char) c;
				swap[x] += 65;
				y++;
			}
		}
	}

	return swap;
}

unsigned char is_not_char(unsigned char c){
	if(c <= 32 || (c > 32 && c < 48) || (c > 57 && c < 65) || c > 122)
		return 0;
	return 1;
}
