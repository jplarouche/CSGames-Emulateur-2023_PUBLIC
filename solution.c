#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>

#include "fake6502.c"


// La RAM de notre système 6502.
uint8_t MEM[0x10000] ;

// Appelé par le CPU quand il veut lire de la RAM.
uint8_t read6502(uint16_t address){
	return MEM[address] ;
}


// Compteur pour compter les écritures du secret.
int write_cnt = 0 ;

// Appelé par le CPU quand il veut écrire en RAM.
void write6502(uint16_t address, uint8_t value){
	MEM[address] = value ;
	if (address == 0xFFF1){
		// C'est l'addresse qui nous intéresse. On imprime le char à l'écran et on incrémente le compteur
		printf("%c", value) ;
		write_cnt++ ;
	}
}


int main(int argc, char *argv[]){
	if (argc >= 2){
		// Ouvrir le binaire et le copier dans notre RAM
		FILE *f = fopen(argv[1], "rb") ;
    	fread(MEM, 1, 0x10000, f) ;
		fclose(f) ;
    }
    else {
    	printf("Usage: fake6502 BIN_FILE\n") ;
    	exit(0) ;
    }
	// Utile pour voir les chars à mesure et pas juste quand un \n arrive.
	fflush(stdout) ;

	// On a 1000 clés à tester.
	for (int n = 0 ; n < 1000 ; n++){
		char key[4] ;
		sprintf(key, "%03d", n) ;
		printf("key:%s -> ", key) ;

		// Reset le CPU et copie notre clé en RAM à la bonne adresse.
		reset6502() ;
		for (int i = 0 ; i < 3 ; i++){
			MEM[0x200 + i] = key[i] ;
		}

		write_cnt = 0 ;
		// On arrête le CPU après 48 écritures
		while (write_cnt < 48){
			step6502() ;
		}
		printf("\n") ;
		// Si le dernier charactère écrit n'est pas un '#', ça veut dire qu'on a deviné.
		// On peut arrêter.
		if (MEM[0xFFF1] != '#'){
			break ;
		}
	}

	return 0 ;
}
