#include<stdio.h>
#include <time.h>/* time_t, struct tm, time, localtime */
#include <stdlib.h>


typedef struct tm tm;
void menu();
int bilhete;
void escolhaBalcao();

typedef struct ticketR{
    int numAtend;
    struct tm time;

}ticketR;
//typedef struct ticketE{
//    int numAtend;
//    struct tm time;
//
//}ticketE;
tm* tempo(){//funçao que vai retornar algo do tipo tm, que é a struct que formata o tempo
    time_t rawtime=time(NULL);//comandos que vai obter segundos desde 1/1/1970
    tm* tmp=localtime(&rawtime);//converto os segundos em valor de data para o fuso horario
    return tmp;
}
void bilheteReparar(){
            ticketR pri;
            pri.numAtend=1; //so um exemplo, imcompleto
            tm*tmp=tempo();
            printf("Numero Atendimento: %d\n", pri.numAtend);
            printf("Hora de atendimento: %s\n",asctime(tmp) );
};

int disponivel(){
    ticketR pri;
    pri.time = *tempo();
    return (pri.time.tm_hour<22 && pri.time.tm_hour>= 8);
};

int escolha(){
    printf("\nTicket de Reparacao(1) , Entrega(2) , Voltar(0)?");
    printf("\nEscolha: ");
    scanf("%d",&bilhete);
    return bilhete;
}
void reparOuEntre(){
                switch(bilhete){
					case 1:
						system("cls");
						printf("Ticket Reparacao\n\n");
						bilheteReparar();
						break;
					case 2:
						system("cls");
						printf("Ticket Entrega\n\n");
						break;
                    case 0:
                        system("cls");
                        printf("*******VOLTAR*******");
                        escolhaBalcao();
                        break;
                    default:
                        printf("Insira uma escolha valida");
					}
}
void escolhaBalcao(){
    system("cls");
    int balcao;
    printf("Escolha um balcao\n-BALCAO 1\n-BALCAO 2\n-BALCAO 3\n-BALCAO 4\n-VOLTAR 0\nEscolha:");
    scanf("%d", &balcao);
            switch(balcao){ 
				case 1:
				    system("cls");
					printf("*******BALCAO 1*******");
					escolha();
					reparOuEntre();
					break;
				case 2:
				    system("cls");
					printf("*******BALCAO 2*******");
					escolha();
					reparOuEntre();
					break;
				case 3:
				    system("cls");
					printf("*******BALCAO 3*******");
					escolha();      
                    reparOuEntre();
                    break;
                case 4:
					system("cls");
					printf("*******BALCAO 4*******");
					printf("\nEste balcao aceita apenas Ticket Entrega\n\n");
					break;
                case 0:
                    system("cls");
                    printf("*******VOLTAR*******");
                    menu();
                    break;
				default:
					system("cls");
					printf("Inserir escolha valida! \n\n");
					escolhaBalcao();
					break;
					}
}
void menu(){
    int ch;
    system("cls");
    do{
        printf("\n==================================");
        printf("\n");
        printf("  \n       Sistema de atendimento ");
        printf("\n");
        printf("\n==================================");

        printf("\n 1 Retirar Ticket");
        printf("\n 2 Ver todos os Tickets");
        printf("\n 3 Encontrar ticket ");
        printf("\n 4 Ver disponibilidade dos balcoes");
        printf("\n 5 Ver todos os tickets");
        printf("\n 0 Sair \n");
        printf("\nInsira a sua escolha:");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                system("cls");
                escolhaBalcao();
                break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				system("cls");
				if (disponivel())
					printf("\n\n\n\nEstado: ABERTO\n\n\n\n");
				else{printf("\n\n\n\nEstado: FECHADO\n\n\n\n");
				}
				break;
			case 5:
				system("cls");
				break;
			case 0:
				system("cls");
				printf("\n\n        A sair...");
				exit(0);
				break;
			default:
				system("cls");
				printf("Inserir escolha valida !\n\n\n\n");
				break;
			}
    }while(ch!=0);

}
int main(){
    menu();
    return 0;
}

//
//typedef struct tm tm;
//int main(void) {
//    
//    time_t rawtime=time(NULL);
//    
//    tm* ptm=localtime(&rawtime);
//    printf("The time is: %02d:%02d:%02d\n", (*ptm).tm_hour, 
//            (*ptm).tm_min, (*ptm).tm_sec);
//
//    return 0;
//}
