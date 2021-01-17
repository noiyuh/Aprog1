#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 30

typedef struct tm tm;

typedef struct ticketReparacao{
    int numAtend;
    tm tiraTick;
    int balcao;
    char equipamento[max];
    char observacoes[max];
    tm atendimento;
    int inicio;
    int espera;
}reparacao;

typedef struct ticketEntrega{
    int numAtend;
    tm tiraTick;
    int balcao;
    char condicoes[max];
    float valor;
    tm atendimento;
    int inicio;
    int espera;
}entrega;

tm*tempo(){
    time_t rawtime;
    tm*info;
    time(&rawtime);
    info = localtime(&rawtime);
    return info;
}

int disponivel(){
    reparacao pri;
    pri.tiraTick = *tempo();
    return (pri.tiraTick.tm_hour<22 && pri.tiraTick.tm_hour>= 8);
};

void criarTicketReparacao(reparacao repar[],int*n){
    
    
    if(*n<max){
        int rand_num = (rand() % (3 - 1 + 1)) + 1;
        repar[*n].balcao=rand_num;
        
        tm info1= *tempo();
        repar[*n].tiraTick=info1;
        
        char tmp1[30];
        strftime(tmp1,30,"%d/%m/%Y - %X",&repar[*n].tiraTick);
        repar[*n].numAtend=*n+1;
        
        time_t rawtime;
        repar[*n].inicio=time(&rawtime);
        
        printf("----------------------------\n");
        printf("   ****Ticket Reparacao****\n");
        printf("----------------------------\n");
        printf("Numero de Atendimento  :  %d\n",repar[*n].numAtend);
        printf("Data e hora : |%s|\n",tmp1);
        printf("Balcao      : %d\n", repar[*n].balcao);

        (*n)++;
  }
    else
        printf("Atingiu o limite!\n");
}

void criarTicketEntrega(entrega entre[],int*n){
    
    if(*n<max){
        int rand_num = (rand() % (4 - 1 + 1)) + 1;
    
        entre[*n].balcao=rand_num;
        
        tm info1= *tempo();
        entre[*n].tiraTick=info1;
        
        char tmp1[30];
        strftime(tmp1,30,"%d/%m/%Y - %X",&entre[*n].tiraTick);
        entre[*n].numAtend=*n+1;
        
        time_t rawtime;
        entre[*n].inicio=time(&rawtime);
        
        printf("----------------------------\n");
        printf("   ****Ticket Entrega****\n");
        printf("----------------------------\n");
        printf("Numero de Atendimento  :  %d\n",entre[*n].numAtend);
        printf("Data e hora : |%s|\n",tmp1);
        printf("Balcao      : %d\n", entre[*n].balcao);

        (*n)++;
  }
    else
        printf("Atingiu o limite!\n");
}

void atenderTicketReparacao(reparacao repar[],int*atend,int R){
    
    int i;
    
    for(i=*atend;i<R;i++){
        fflush(stdin);
        printf("----------------------------\n");
        printf("   ****Ticket Reparacao****\n");
        printf("----------------------------\n");
        printf("Numero de Atendimento  :  %d\n",repar[i].numAtend);
        printf("Balcao         : %d\n", repar[i].balcao);
        
        printf("Equipamento    :  ");
        fgets(repar[i].equipamento,max,stdin);
        fflush(stdin);
        printf("Observacoes    :  ");
        fgets(repar[i].observacoes,max,stdin);
        fflush(stdin);
        
        
        
        
        char tmp2[30];
        tm info2= *tempo();
        
        
        repar[i].atendimento=info2;
        strftime(tmp2,30,"%d/%m/%Y - %X",&repar[i].atendimento);
        printf("Data e hora : |%s|\n",tmp2);
        
        time_t rawtime;
        repar[i].espera=time(&rawtime)- repar[i].inicio;
        
        
        (*atend)++;
        fflush(stdin);
    }
}

void atenderTicketEntrega(entrega entre[],int*atend, int E){//preenche as informaçoes do ticket entrega
    int i;
    
    
    for(i=*atend;i<E;i++){
        
        fflush(stdin);
        printf("----------------------------\n");
        printf("   ****Ticket Entrega****\n");
        printf("----------------------------\n");
        printf("Numero de Atendimento    :  %d\n",entre[i].numAtend);
        printf("Balcao      : %d\n", entre[i].balcao);
        
        printf("Condicoes de Mercadoria    :  ");
        fgets(entre[i].condicoes,max,stdin);
        fflush(stdin);
        do{
                
            printf("Valor a pagar            :   ");
            scanf(" %f*c", &entre[i].valor);
            
            fflush(stdin);
        }while(entre[i].valor<0);
        
        char tmp2[30];
        tm info2= *tempo();
        entre[i].atendimento=info2;
        strftime(tmp2,30,"%d/%m/%Y - %X",&entre[i].atendimento);
        printf("Data e hora de atendimento: |%s|\n",tmp2);
        
        time_t rawtime;
        entre[i].espera=time(&rawtime)- entre[i].inicio;

        
        (*atend)++;
        fflush(stdin);
    }
    
}

int tipoDeTick(){ //escolher o tipo de ticket, reparacao ou entrega
      int ch;

  printf("\nTicket Reparacao(1) ou Entrega(2)?: \n");
  do {
      scanf("%d",&ch);
     
      switch(ch) {
      case 1:
        break;
      case 2:
        break;
      default:
        printf("Opcao mal escolhida!\n");
    } 
    fflush(stdin);
  } while(ch != 1 && ch !=2);
    return ch;
}

//LISTAR TODOS OS TICKETS
void listarTicketsEntrega(entrega entre[],int E){//fazer isto para dar para todos os tickets
    fflush(stdin);
    int i;
    for(i=0;i<E;i++){
        
                printf("\n**************\n");
                printf("Numero atendimento    : %d\n", entre[i].numAtend);
                printf("Balcao                : %d\n", entre[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%d/%m/%Y - %X",&entre[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%d/%m/%Y - %X",&entre[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                
                printf("Condicoes             : %s", entre[i].condicoes);
                printf("Valor Pago            : %.2f EUR", entre[i].valor);
                
                int h,m,s;
                h=(entre[i].espera/3600);
                m=(entre[i].espera-(3600*h))/60;
                s=(entre[i].espera-(3600*h)-(m*60));
                
                printf("\nTempo de espera       : %02dH:%02dM:%02dS", h,m,s);
                printf("\n**************\n\n");
        }
}

void listarTicketsReparcao(reparacao repar[],int R){//fazer isto para dar para todos os tickets
    fflush(stdin);
    int i;
    for(i=0;i<R;i++){
                printf("\n**************\n");
                printf("Numero atendimento    : %d\n", repar[i].numAtend);
                printf("Balcao                : %d\n", repar[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%d/%m/%Y - %X",&repar[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%d/%m/%Y - %X",&repar[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                
                printf("Equipamento           : %s", repar[i].equipamento);
                printf("Observacoes           : %s", repar[i].observacoes);
                
                int h,m,s;
                h=(repar[i].espera/3600);
                m=(repar[i].espera-(3600*h))/60;
                s=(repar[i].espera-(3600*h)-(m*60));
                
                
                printf("Tempo de espera        : %02dH:%02dM:%02dS", h,m,s);
                printf("\n**************\n\n");
    }
}
                        
//listar cada ticket individualmente                      
 void listarTicketReparcao(reparacao repar[],int R){//fazer isto para dar para todos os tickets
    fflush(stdin);
    int i;
    int num;
    printf("\n=================================\n");
    printf("Qual o numero de atendimento do Ticket que quer consultar? \n");
    scanf(" %d", &num);
    
    for(i=0;i<R;i++){
            if(repar[i].numAtend==num){
                printf("**************\n");
                printf("Numero atendimento    : %d\n", repar[i].numAtend);
                printf("Balcao                : %d\n", repar[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%c",&repar[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%c",&repar[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                
                printf("Equipamento           : %s", repar[i].equipamento);
                printf("Observacoes           : %s", repar[i].observacoes);
                
                int h,m,s;
                h=(repar[i].espera/3600);
                m=(repar[i].espera-(3600*h))/60;
                s=(repar[i].espera-(3600*h)-(m*60));
                
                
                printf("Tempo de espera        : %02dH:%02dM:%02dS", h,m,s);
                printf("\n**************\n");
            }
    }
}                       
                    
void listarTicketEntrega(entrega entre[],int E){//fazer isto para dar para todos os tickets
    fflush(stdin);
    int i;
    int num;
    printf("\n=================================\n");
    printf("Qual o numero de atendimento do Ticket que quer consultar? \n");
    scanf(" %d", &num);
    
    for(i=0;i<E;i++){
        if(entre[i].numAtend==num){
                printf("**************\n");
                printf("Numero atendimento    : %d\n", entre[i].numAtend);
                printf("Balcao                : %d\n", entre[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%c",&entre[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%c",&entre[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                
                printf("Condicoes             : %s\n", entre[i].condicoes);
                printf("valor                 : %.2f EUR", entre[i].valor);
                
                int h,m,s;
                h=(entre[i].espera/3600);
                m=(entre[i].espera-(3600*h))/60;
                s=(entre[i].espera-(3600*h)-(m*60));
                
                printf("\nTempo de espera       : %02dH:%02dM:%02dS", h,m,s);
                printf("\n**************\n");
        }
    }
}
                                               
void procurarData(int *dia, int *mes, int *ano){

    printf("Insira uma data para pesquisar Tickets");
    printf("\nDia->");scanf(" %d",dia);
    printf("Mes->");scanf(" %d",mes);
    printf("Ano->");scanf(" %d",ano);
    
    (*mes)=*mes-1;//valores de meses sao de 0 a 11
    (*ano)=*ano-1900;//valores de ano contam a partir de 1900
}

void listarPorData(entrega entre[],reparacao repar[],int nE,int nR){
    int i;
    
    int dia=0, mes=0,ano=0;
    procurarData(&dia,&mes,&ano);
    
    for(i=0;i<nE;i++){
        if(entre[i].atendimento.tm_mday==dia && entre[i].atendimento.tm_mon==mes && entre[i].atendimento.tm_year==ano){
                printf("****************************************");
                printf("\n         TICKET   ENTREGA                \n");
                printf("****************************************\n");
                printf("Numero atendimento    : %d\n", entre[i].numAtend);
                printf("Balcao                : %d\n", entre[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%c",&entre[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%c",&entre[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                printf("Condicoes             : %s", entre[i].condicoes);
                printf("valor                 : %.2f EUR", entre[i].valor);
                
                int h,m,s;
                h=(entre[i].espera/3600);
                m=(entre[i].espera-(3600*h))/60;
                s=(entre[i].espera-(3600*h)-(m*60));
                
                printf("\nTempo de espera       : %02dH:%02dM:%02dS", h,m,s);
                printf("\n**************\n");
            }
        }
    for(i=0;i<nR;i++){
        if(repar[i].atendimento.tm_mday==dia && repar[i].atendimento.tm_mon==mes && repar[i].atendimento.tm_year==ano){
                printf("****************************************");
                printf("\n          TICKET   REPARACAO               \n");
                printf("****************************************\n");
                printf("Numero atendimento    : %d\n", repar[i].numAtend);
                printf("Balcao                : %d\n", repar[i].balcao);
                
                char tmp1[30];
                strftime(tmp1,30,"%c",&repar[i].tiraTick);
                printf("Bilhete retirado a    : |%s|\n",tmp1);
                
                char tmp2[30];
                strftime(tmp2,30,"%c",&repar[i].atendimento);
                printf("Hora de Atendimento   : |%s|\n",tmp2);
                printf("Equipamento           :  %s", repar[i].equipamento);
                printf("Observacoes           :  %s", repar[i].observacoes);
                
                int h,m,s;
                h=(repar[i].espera/3600);
                m=(repar[i].espera-(3600*h))/60;
                s=(repar[i].espera-(3600*h)-(m*60));
                
                printf("Tempo de espera       : %02dH:%02dM:%02dS", h,m,s);
                printf("\n_______________________________________\n");
            }
        }
}
                        
 void valorTotalPorData(entrega entre[],int n){

    int i;
    int dia=0,mes=0,ano=0;
    procurarData(&dia,&mes,&ano);
    
    float total=0;
    for(i=0;i<n;i++){
        if(entre[i].atendimento.tm_mday==dia && entre[i].atendimento.tm_mon==mes && entre[i].atendimento.tm_year==ano)
            total+=entre[i].valor;
    }
    int mesreal=mes+1;
    int anoreal=ano+1900;
    printf("Valor Total no dia %d/%d/%d ->>>%.2f EUR",dia,mesreal,anoreal,total);
} 
                
void ticketsAtendPorData(entrega entre[],reparacao repar[],int nE,int nR){
    int dia=0,mes=0,ano=0;
    int i;
    int totalE=0,totalR=0,total=0;
    procurarData(&dia,&mes,&ano);
    for(i=0;i<nE;i++){
        if(entre[i].atendimento.tm_mday==dia && entre[i].atendimento.tm_mon==mes && entre[i].atendimento.tm_year==ano)
            totalE+=1;
    }
    for(i=0;i<nR;i++){
        if(repar[i].atendimento.tm_mday==dia && repar[i].atendimento.tm_mon==mes && repar[i].atendimento.tm_year==ano)
            totalR+=1;
    }
    int mesreal=mes+1;
    int anoreal=ano+1900;
    
    total=totalR+totalE;
    if(total>0){
        printf("\n\nTickets atendidos no dia %d/%d/%d ->>> %d\n",dia,mesreal,anoreal,total);
        printf("Numero de Tickets Entrega-> %d\nNumero de Tickets Reparacaoo-> %d\n\n",totalE,totalR);
    }
    else
        printf("\n\n  Nenhum Ticket Atendido na Data indicada\n\n ");
}                        
                                                               
void valorMedio(entrega entre[], int n){//valor medio das entregas
    int i;
    float total=0;
    float media=0;
    
    for(i=0;i<n;i++){
        total+=entre[i].valor;
    }
//    printf(" count %f",count);
//    printf(" total %d")
    if(n>0){
        media=(total/n);
        printf("Media do valor : %.2f EUR\n",media);
    }
    else{
        printf("\nNao foram atendidos Tickets Entrega\n\n");
    }
} 
  
float valorTotal(entrega entre[], int n){//valor total das entregas
    int i;
    float total=0;
    for(i=0;i<n;i++){
        total+=entre[i].valor;
    }
    return total;
} 

void mediaEspera(entrega entre[],reparacao repar[], int nR,int nE){//MEDIA DE ESPERA
    int i;
    int totalR=0,totalE=0;
    float sec=0,totalSoma;
    
    for(i=0;i<nR;i++){
        
        totalR+=repar[i].espera;
        
    }
    for(i=0;i<nE;i++){
        
        totalE+=entre[i].espera;
        
    }
        
        int nSoma = nE + nR;
        totalSoma = totalE + totalR;


        if(nSoma>0){
            sec=(totalSoma/nSoma);
            int h,m,s;
                h=(sec/3600);
                m=(sec-(3600*h))/60;
                s=(sec-(3600*h)-(m*60));
                
                
                printf("\nTempo medio de espera  : %02dH:%02dM:%02dS\n\n", h,m,s);
            
        }
        else{
            printf("\n Primeiro atenda pelo menos 1 Ticket\n\n");
        }
}
    
void mediaEsperaPorData(entrega entre[],reparacao repar[], int nR,int nE){//MEDIA DE ESPERA
    int i;
    int dia=0,mes=0,ano=0;
    int totalR=0,totalE=0;
    float sec=0,totalSoma;
    
    procurarData(&dia,&mes,&ano);
    for(i=0;i<nR;i++){
        if(repar[i].atendimento.tm_mday==dia && repar[i].atendimento.tm_mon==mes && repar[i].atendimento.tm_year==ano)
            totalR+=repar[i].espera;
        
    }
    for(i=0;i<nE;i++){
        if(entre[i].atendimento.tm_mday==dia && entre[i].atendimento.tm_mon==mes && entre[i].atendimento.tm_year==ano)       
            totalE+=entre[i].espera;
        
    }
        
        int nSoma = nE + nR;
        totalSoma = totalE + totalR;


        if(totalSoma>0){
            sec=(totalSoma/nSoma);
            int h,m,s;
                h=(sec/3600);
                m=(sec-(3600*h))/60;
                s=(sec-(3600*h)-(m*60));
                
                
                printf("\nTempo medio de espera  : %02dH:%02dM:%02dS\n\n", h,m,s);
        }
        
        else{
            printf("\n Nenhum Ticket Atendido na Data indicada\n\n");
        }
}
    
void produtividadeBalcao(reparacao repar[],entrega entre[], int nR,int nE){
    int i=0;
    int countb1=0,countb2=0,countb3=0,countb4=0;
    int maior=0,balcao=0;
    
    for(i=0;i<nR;i++){
        if(repar[i].balcao==1)
            countb1++;
        if(repar[i].balcao==2)
            countb2++;
        if(repar[i].balcao==3)
            countb3++;
    }
    for(i=0;i<nE;i++){
    if(entre[i].balcao==1)
        countb1++;
    if(entre[i].balcao==2)
        countb2++;
    if(entre[i].balcao==3)
        countb3++;
    if(entre[i].balcao==4)
        countb4++;
    }
    
    int a[4]={countb1,countb2,countb3,countb4};
    int menor=a[0];
    
    for(i=0;i<4;i++){
        if(a[i]>maior){
            maior=a[i];
            balcao=i+1;
        }
    }
    printf("O balcao mais produtivo foi o %d, de onde foram retirados %d Tickets\n",balcao,maior);
    
    for(i=0;i<4;i++){
        if(a[i]<menor){
            menor=a[i];
            balcao=i+1;
        }
    }
    printf("O balcao menos produtivo foi o %d, de onde foram retirados %d Tickets\n",balcao,menor);
}
    
void subMenu(reparacao repar[],entrega entre[],int atendE,int atendR){
    int ch;
    char character;
    do{
        printf("\n==================================");
        printf("  \n     Sub Menu ");
        printf("\n==================================");
        printf("\n »Tickets por Data(1)");
        printf("\n »Produtividade dos Balcoes(2)");
        printf("\n »Valor Total Entregue por Data(3)");
        printf("\n »Tickets Atendidos por Data(4)");
        printf("\n »Media de Espera por Data(5)");
        printf("\n »Sair(0) \n");
        printf("Escolha\n->");
        scanf(" %c",&character);
        ch = (int) character;//transforma o valor do caracter no seu equivalente decimal
        if(ch>=48 && ch<=57){//manter o range aceitavel entre 48 e 57(0 a 9 em valor de caracter)
                ch=ch-48;//transmutar o o range para 0-9
                
                fflush(stdin);
                switch(ch){
                    case 1:
                        listarPorData(entre,repar,atendE,atendR);
                        break;
                    case 2://boom
                        produtividadeBalcao(repar,entre,atendR,atendE);
                        break;
                    case 3://boom
                         valorTotalPorData(entre,atendE);
                        break;
                    case 4://boom
                         ticketsAtendPorData(entre,repar,atendE,atendR);
                        break;
                    case 5://boom
                         mediaEsperaPorData(entre,repar,atendR,atendE);
                        break;
                    
                    case 0:
                        printf("Fim do Sub Menu");
                        break;
                    default:
                        printf("Inserir escolha valida !\n\n\n\n");
                }   
        }
        else
            ch=100;
          fflush(stdin);

     }while(ch!=0);
}

void menu(){
    printf("\n==================================");
    printf("\n");
    printf("  \n     SISTEMA DE ATENDIMENTO  ");
    printf("\n");
    printf("\n==================================");

    printf("\n         Gerar Ticket(1)");
    printf("\n           Atender(2) ");
    printf("\n     Listar Todos os Tickets(3)");
    printf("\n     Listar Ticket Individual(4) ");
    printf("\n      Media de Valor Entregue(5)");
    printf("\n       Valor Total Entregue(6)");
    printf("\n         Media de espera(7)");
    printf("\n           Sub Menu(8)");
    printf("\n             Sair(0) \n");
    printf("Escolha\n->");
}

int main(){
    srand(time(0));
    int tipo;
    int numR=0,numE=0,countE=0,countR=0,atendR=0,atendE=0;
    char character;
    float total;
    int ch;
    
    reparacao repar[max];
    entrega entre[max];
    do{
        menu();
        scanf(" %c",&character);
        ch = (int) character;//transforma o valor do caracter no seu equivalente decimal
        if(ch>=48 && ch<=57){//manter o range aceitavel entre 48 e 57(0 a 9 em valor de caracter)
                ch=ch-48;//transmutar o o range para 0-9
            switch (ch){
                    case 1:
                        if(disponivel()){
                            printf("\nESTADO: ABERTO\n\n");
                            tipo=tipoDeTick();
                            if(tipo==1){
                                fflush(stdin);
                                criarTicketReparacao(repar,&numR);
                                countR++;
                            }
                            if(tipo==2){
                                fflush(stdin);
                                criarTicketEntrega(entre,&numE);
                                countE++;
                            }
                        }
                        else{
                            printf("\n      Estado: FECHADO");
                            printf("\nApenas aberto entre as 8h e as 22h \n\n");
                        }
                        break;
                    case 2://atender
                        fflush(stdin);
                        tipo=tipoDeTick();
                        if(tipo==1){
                            fflush(stdin);
                            atenderTicketReparacao(repar,&atendR,countR);
                        }
                        if(tipo==2){
                            fflush(stdin);
                            atenderTicketEntrega(entre,&atendE,countE);    
                        }

                        break;
                    case 3://listar
                        fflush(stdin);
                            printf("\n   ___________________________________");
                            printf("     \n\n           ***REPARACAO***\n");
                            printf("\n   ___________________________________");
                            fflush(stdin);
                            listarTicketsReparcao(repar,atendR);
                            printf("\n   ___________________________________");
                            printf("        \n\n          ***ENTREGA***\n");
                            printf("\n   ___________________________________");
                            fflush(stdin);
                            listarTicketsEntrega(entre,atendE);
                        break;
                    case 4:
                        fflush(stdin);
                        tipo=tipoDeTick();
                        if(tipo==1){
                            fflush(stdin);
                            listarTicketReparcao(repar,atendR);
                        }
                        if(tipo==2){
                            fflush(stdin);
                            listarTicketEntrega(entre,atendE);
                        }
                        break;
                    case 5://sdasdasdas
                        
                        valorMedio(entre,atendE);
        //                printf("Valor médio das entregas  :  %02f EUR",media);
                        break;
                    case 6:
                        total=valorTotal(entre,atendE);
                        printf("Valor total das entregas  :  %.2f EUR",total);
                        break;
                    case 7://boom
                        mediaEspera(entre,repar,atendR,atendE);
                        break;
                    case 8:
                        subMenu(repar,entre,atendE,atendR);
                        break;
                    case 0:
                        printf("\n\n        A sair...");
                        exit(0);
                        break;
                    default:
                        printf("Inserir escolha valida !\n\n\n\n");
                }
        }
        else
            ch=100;
        
    }while (ch!=0);
    return 0;
}
    