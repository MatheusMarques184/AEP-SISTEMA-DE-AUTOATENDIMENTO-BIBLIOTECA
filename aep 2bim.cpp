#include <stdlib.h>
#include <stdio.h>
#include <conio.c>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char parada;
bool valido, valido_login;
char login[20],senha_login[10];
char user[40]="user",senha_user[10]="123456";
char user_adm[40]="adm",senha_adm[10]="123456";
char nome_user[40]="nome",endereco_user[30]="endereço",celular_user[12]="4499729972",email_user[80]="usuario@email.com";
char eventos [15][60]={"Clube do livro: Memórias Póstumas de Brás Cubas",
"Concurso musical","Dia da arte brasileira","Clube do livro: Dom Casmurro"};
char eventosDia [15][15]={"11/06/21 18:30","19/06/21 15:00","26/06/21 16:30","03/07/21 18:30"};
char acervo[50][40]={"Memórias Póstumas de Brás Cubas","Dom Casmurro","Macunaíma","A Paixão Segundo G.H.",
"Capitães da Areia","A Rosa do Povo","Triste Fim de Policarpo Quaresma","Gabriela, Cravo e Canela",
"Os Sertões","O Guarani"};
char acervoAutor[50][40]={"Machado de Assis","Machado de Assis","Mário de Andrade","Clarice Lispector",
"Jorge Amado","Carlos Drummond de Andrade","Lima Barreto","Jorge Amado","Euclides da Cunha","José de Alencar"};
int qntEventos=4, qntItens=9;
char itemEmprestado[3][40];
int itensEmprestimo = 0, multa=0,eventosConfirmados=0;
char nomesEventosConfirmados[15][60],nomesItensEmprestado[15][60];
char dataEntrega[11];
char datasEntrega[50][11];

void login_prim();
void usuario();
void adm();
void cadastro();
void telaInicial();
void telaInicialAdm();
void consultaEventos();
void consultaAcervo();
void perfil();
void cadastrarEvento();
void cadastrarAcervo();
void modificarEventos();
void modificarAcervo();
void dadosUser();
//------------------------------------------------------------------------------
int main(){ 
  CONSOLE_CURSOR_INFO cursor = {1,FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  setlocale(LC_ALL,"portuguese");
  login_prim();
}

void login_prim() {   
  int p=1,x,tecla;
  char item[5][16]={"","Usúario       ","Administrador ","Criar cadastro","Sair          "};
  do{
    CONSOLE_CURSOR_INFO cursor = {1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    system("cls");
    textcolor(1);
    gotoxy(36,2); printf("L O G I N");
    textcolor(15); 
    textbackground(0);
    for (x=1; x<=4; x++){
      gotoxy(10,9+x);
      printf(item[x]);  
    }
    textcolor(1);
    textbackground(3);
    gotoxy(10,9+p);
    printf("%s",item[p]);
    textcolor(15); 
    textbackground(0); 
    tecla=getch();
    if (tecla==224 || tecla==0){
      tecla=getch();
    }
    switch (tecla){
      case 72:p--; break;     
      case 80:p++; break;            
    }
    if (p==0) p=4;
    if (p==5) p=1;
    if (tecla==13){
       switch(p) {
         case 1:usuario(); break;     
         case 2:adm(); break;
         case 3:cadastro();break ;
         case 4:tecla=27;break ;                
       }
    }
  }while (tecla!=27);
} 
  
void usuario(){
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);   
  system("cls");
  valido_login=true;
  textcolor(2);
  printf("Para testes sem ter que realizar o cadastro pode ser usado \n");
  printf("USUARIO:user / Caso ja tenha feito o cadastro seria: %s\n",user);
  printf("SENHA:123456  / caso ja tenha feito o cadastro seria: %s\n",senha_user);
  textcolor(1);
  gotoxy(34,4); printf("U S U Á R I O");
  textcolor(LIGHTCYAN);
  gotoxy(6,6); printf("Usúario: \n");
  textcolor(15);
  gotoxy(6,7);
  gets(login);
  if(strcmp(login,user)!=0){
    valido_login=false;
  }
  textcolor(LIGHTCYAN);
  gotoxy(6,9); printf("Senha: \n");
  textcolor(15);
  gotoxy(6,10);
  gets(senha_login);
  if(strcmp(senha_login,senha_user)!=0){
    valido_login=false;
  }
  if(valido_login==false){
    system("cls");
    textcolor(4);
    printf(" As Informaçãos de login foram invalidas, confirme os dados ou crie um cadastro .\n\n");
    printf(" Clique em qualquer tecla para ser redirecionado a tela inicial .\n");
    textcolor(15);
    parada=getch();
  }
  if(valido_login==true){
    system("cls");
    telaInicial();
  }
}

void adm(){   
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);   
  system("cls");
  valido_login=true;
  textcolor(2);
  printf("Para testes sem ter que realizar o cadastro pode ser usado \n");
  printf("USUARIO:adm / Caso ja tenha feito o cadastro seria: %s\n",user_adm);
  printf("SENHA:123456 / caso ja tenha feito o cadastro seria: %s\n",senha_adm);
  textcolor(1);
  gotoxy(34,4); printf("A D M N I S T R A D O R");
  textcolor(LIGHTCYAN);
  gotoxy(6,6); printf("Usúario: \n");
  textcolor(15);
  gotoxy(6,7);
  gets(login);
  if(strcmp(login,user_adm)!=0){
    valido_login=false;
  }
  textcolor(LIGHTCYAN);
  gotoxy(6,9); printf("Senha: \n");
  textcolor(15);
  gotoxy(6,10);
  gets(senha_login);
  if(strcmp(senha_login,senha_adm)!=0){
    valido_login=false;
  }
  if(valido_login==false){
    system("cls");
    textcolor(4);
    printf(" As Informaçãos de login foram invalidas, confirme os dados ou crie um cadastro .\n\n");
    printf(" Clique em qualquer tecla para ser redirecionado a tela inicial .\n");
    textcolor(15);
    parada=getch();
  }
  if(valido_login==true){
    system("cls");
    telaInicialAdm();
  }
}

void cadastro(){
  int y=0;   
  system("cls");
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);   
  do{
    valido=true;
    textcolor(LIGHTCYAN);                   
    printf("Informe seu nome completo: \n");
    textcolor(15);
    gets(nome_user);
    for(int x=0;x<=strlen(nome_user)-1;x++){
      y = nome_user[x];
      if(y<65 or y>90 and y<97 or y>122){
        valido=false;
      } 
      if(y==32){
        valido=true;
      }
    }
    if(valido==false){
      textcolor(4);
      printf(" Informação invalida, escreva apenas letras.\n");
      textcolor(15);
    }
  }while(valido==false);
  printf("\n"); 
  do{
    valido=true;
    textcolor(LIGHTCYAN);
    printf("Informe seu endereço: \n");
    textcolor(15);
    gets(endereco_user);
    for(int x=0;x<=strlen(endereco_user)-1;x++){
      y = endereco_user[x];
      if(y<65 or y>90 and y<97 or y>122){
        valido=false;
      }
      if(y==32){
        valido=true;
      }
    }
      if(valido==false){
        textcolor(4);
        printf(" Informação invalida, escreva apenas letras.\n");
        textcolor(15);
      }
  }while(valido==false);
  printf("\n");
  do{
    valido=true;
    textcolor(LIGHTCYAN);
    printf("Informe o número do seu celular(apenas números): \n");
    textcolor(15);
    gets(celular_user);
    for(int x=0;x<=strlen(celular_user)-1;x++){
      y = celular_user[x];
      if(y<48 or y>57){
        valido=false;
      }
    }
    if(valido==false){
      textcolor(4);
      printf(" Informação invalida, escreva apenas números.\n");
      textcolor(15);
    }
    if(strlen(celular_user)!=11){
      textcolor(4);
      printf(" Informação invalida, digite os 11 digitos.\n");
      textcolor(15);
    }
  }while(strlen(celular_user)!=11 || valido==false);
  printf("\n");
  do{          
    valido=false;
    textcolor(LIGHTCYAN);  
    printf("Informe o e-mail que sera utilizado para login: \n");
    textcolor(15);
    gets(user);
    for(int x=0;x<=strlen(user)-1;x++){
      y = user[x];
      if(y==64){
        valido=true;
      }
    }
    if(valido==false){
      textcolor(4);
      printf(" Informação invalida, escreva um email valido.\n");
      textcolor(15);
    }
  }while(valido==false);
  printf("\n"); 
  do{          
    valido=true;
    textcolor(LIGHTCYAN);  
    printf("Informe uma senha númerica de no minímo 6 caracteres: \n");
    textcolor(15);
    gets(senha_user);
    if(strlen(senha_user)<6 or strlen(senha_user)>10){
      valido=false;
      textcolor(4);
      printf(" Digite no minimo 6 caracteres(max 10 caracteres).\n");
      textcolor(15);
    }           
    for(int x=0;x<=strlen(senha_user)-1;x++){
      y = senha_user[x];
      if(y<48 or y>57){
        valido=false;
      }
    }
    if(valido==false){
      textcolor(4);
      printf(" Informação invalida, escreva apenas numero.\n");
      textcolor(15);
    }
  }while(valido==false);
  printf("\n");      
}

void telaInicial(){  
  int p=1,x,tecla;
  char item[5][25]={"","Consultar eventos    ","Consultar acervo     ","Perfil               ","Sair                 "};
  do{
    CONSOLE_CURSOR_INFO cursor = {1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    system("cls");
    textcolor(1);
    gotoxy(37,2); printf("H O M E");
    textcolor(15); 
    textbackground(0);
    for (x=1; x<=4; x++){
      gotoxy(10,9+x);
      printf(item[x]);  
    }
    textcolor(1);
    textbackground(3);
    gotoxy(10,9+p);
    printf("%s",item[p]);
    textcolor(15); 
    textbackground(0); 
    tecla=getch();
    if (tecla==224 || tecla==0){
      tecla=getch();
    }
    switch (tecla){
      case 72:p--; break;     
      case 80:p++; break;            
    }
    if (p==0) p=4;
    if (p==5) p=1;
    if (tecla==13){
       switch(p) {
         case 1:consultaEventos(); break;     
         case 2:consultaAcervo();break;
         case 3:perfil();break ;
         case 4:tecla=27;break ;                
       }
    }
  }while (tecla!=27);
}

void telaInicialAdm(){   
  int p=1,x,tecla;
  char item[9][28]={"","Consultar eventos          ","Consultar acervo           ",
  "Cadastrar eventos          ","Cadastrar itens do acervo  ","Modificar eventos          ",
  "Modificar itens do acervo  ","Modificar/Consultar dados  ","Sair                       "};
  do{
    CONSOLE_CURSOR_INFO cursor = {1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    system("cls");
    textcolor(1);
    gotoxy(37,2); printf("H O M E");
    textcolor(15); 
    textbackground(0);
    for (x=1; x<=8; x++){
      gotoxy(10,9+x);
      printf(item[x]);  
    }
    textcolor(1);
    textbackground(3);
    gotoxy(10,9+p);
    printf("%s",item[p]);
    textcolor(15); 
    textbackground(0); 
    tecla=getch();
    if (tecla==224 || tecla==0){
      tecla=getch();
    }
    switch (tecla){
      case 72:p--; break;     
      case 80:p++; break;            
    }
    if (p==0) p=8;
    if (p==9) p=1;
    if (tecla==13){
       switch(p) {
         case 1:consultaEventos(); break;     
         case 2:consultaAcervo();break;
         case 3:cadastrarEvento();break ; 
         case 4:cadastrarAcervo();break ; 
         case 5:modificarEventos();break ;
         case 6:modificarAcervo();break ;
         case 7:dadosUser();break ;
         case 8:tecla=27;break ;                
       }
    }
  }while (tecla!=27);
}

void consultaEventos(){
  int codigo=-1;
  system("cls");
  gotoxy(1,4);
  for(int x=0; x<sizeof(eventos)/sizeof(eventos[0]);x++){
    CONSOLE_CURSOR_INFO cursor ={2,TRUE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    int retorno = strcmp(eventos[x], " ");
    if(retorno==1){
      textcolor(1);
      printf("Codigo: %i  ",x);
      printf("Evento: %s \n\n",eventos[x]);
      textcolor(15);
      printf("Data: %s \n\n",eventosDia[x]);
      }
    }
    char res[4];
    gotoxy(1,1);printf("Aperte ENTER para cancelar,para confirmar a presença em algum evento digite: sim");
    gotoxy(1,2);gets(res);
    if(strcmp(res,"sim")==0){
      gotoxy(1,1); printf("                                                                                                        "); 
      gotoxy(1,2); printf("                                                                                                        ");                    
      gotoxy(1,1); printf("Escreva o codigo do evento que deseja confirmar presença: ");
      gotoxy(1,2); scanf("%i",&codigo);
      fflush(stdin);
      }
    else{
      codigo=-1;
      }
    if(codigo!=-1){
      system("cls");
      for(int x=1; x<15; x++){
        int retorno = strcmp(nomesEventosConfirmados[x], eventos[codigo]);
        if(retorno==0){
          printf("A sua presença no evento ja foi confirmada \n\n");
          break;             
        }
        else{
          textcolor(1);
          printf("Presença confirmada \n\n");
          printf("Evento: %s \n\n",eventos[codigo]);
          textcolor(15);
          printf("Data: %s \n\n",eventosDia[codigo]);
          eventosConfirmados++;
          strcpy(nomesEventosConfirmados[eventosConfirmados],eventos[codigo]);
          break;
        }
      }
    printf("Para finalizar aperte ESC\n\n");
    CONSOLE_CURSOR_INFO cursor ={1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    parada=getch();
  }
}

void consultaAcervo(){
  int codigo = -1;
  system("cls");
  gotoxy(1,4);
  for(int x=0; x<sizeof(acervo)/sizeof(acervo[0]);x++){
    CONSOLE_CURSOR_INFO cursor ={2,TRUE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    int retorno = strcmp(acervo[x], " ");
    if(retorno==1){
      textcolor(1);
      printf("Codigo: %i  ",x);
      printf("Evento: %s \n\n",acervo[x]);
      textcolor(15);
      printf("Autor: %s \n\n",acervoAutor[x]);
      }
    }
  char res[4];
  gotoxy(1,1);printf("Aperte ENTER para cancelar,para realizar o emprestimo de algo digite: sim");
  gotoxy(1,2);gets(res);
  if(strcmp(res,"sim")==0){
    gotoxy(1,1); printf("                                                                                                        "); 
    gotoxy(1,2); printf("                                                                                                        ");                        
    gotoxy(1,1); printf("Escreva o codigo do item que deseja realizar o emprestimo: ");
    gotoxy(1,2); scanf("%i",&codigo);
    fflush(stdin);
    }
  else{
    codigo=-1;
    }
  if(codigo!=-1 and itensEmprestimo<3){
    system("cls");
    for(int x=1; x<15; x++){
      int retorno = strcmp(nomesItensEmprestado[x], acervo[codigo]);
      if(retorno==0){
        printf("O item do acervo está emprestado.\n\n");
        break;             
      }
      else{
        strcpy(dataEntrega,"");
        textcolor(1);
        printf("Emprestimo confirmado\n\n");
        printf("Nome: %s \n\n",acervo[codigo]);
        itensEmprestimo++;
        strcpy(nomesItensEmprestado[itensEmprestimo],acervo[codigo]);\
        struct tm *data_hora_atual;
        time_t segundos;
        time(&segundos);
        data_hora_atual = localtime(&segundos);
        if(data_hora_atual->tm_mday<10){
          strcat(dataEntrega,"0");
          }
        char dia[3];
        snprintf(dia, 3, "%d", data_hora_atual->tm_mday);
        strcat(dataEntrega,dia);
        strcat(dataEntrega,"/");
        if(data_hora_atual->tm_mon+2<10){
          strcat(dataEntrega,"0");
          }
        char mes[3];
        snprintf(mes, 3, "%d", data_hora_atual->tm_mon+2);
        strcat(dataEntrega,mes);
        strcat(dataEntrega,"/");
        char ano[5];
        snprintf(ano, 5, "%d", data_hora_atual->tm_year+1900);
        strcat(dataEntrega,ano);
        strcpy(datasEntrega[itensEmprestimo],dataEntrega);
        break;
        }
    }
    textcolor(15);
    printf("Para finalizar aperte ESC\n\n");
    CONSOLE_CURSOR_INFO cursor ={1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    parada=getch(); 
  } 
}

void perfil(){
  system("cls");
  textcolor(1);
  printf("Usuario: ",login);
  textcolor(15);
  printf("%s \n\n",login);
  textcolor(1);
  printf("Eventos confirmado: ");
  textcolor(15);
  printf("%i \n\n",eventosConfirmados);
  textcolor(1);
  for(int x=0; x<sizeof(nomesEventosConfirmados)/sizeof(nomesEventosConfirmados[0]);x++){
    int retorno = strcmp(nomesEventosConfirmados[x], " ");
    if(retorno==1){
      textcolor(1);
      printf("Nome do evento: ");
      textcolor(15);
      printf("%s \n\n",nomesEventosConfirmados[x]);
      }   
    }
  textcolor(1);
  printf("Itens em emprestimo: ");
  textcolor(15);
  printf("%i \n\n",itensEmprestimo);
  if(itensEmprestimo>0){
    for(int x=1; x<=itensEmprestimo; x++){                   
      textcolor(1);
      printf("Nome: ");
      textcolor(15);
      printf("%s \n\n",nomesItensEmprestado[x]);
      textcolor(1);
      printf("Data de entrega: ");
      textcolor(15);
      printf("%s \n\n",datasEntrega[x]);
      textcolor(1);
      printf("Multa/Divida: ");
      textcolor(15);
      printf("%i \n\n",multa);
      }
    }
  parada=getch();
} 
 
void cadastrarEvento(){
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  system("cls");
  do{
    textcolor(1);
    printf("Nome do evento: ");
    textcolor(15);
    gets(eventos[qntEventos]);
    textcolor(1);
    printf("\nData do evento(DD/MM/AA HH:MM): ");
    textcolor(15);
    gets(eventosDia[qntEventos]);
    qntEventos++;
    printf("Se deixa continuar aperte ENTER, caso deseja finalizar aperte ESC\n\n");
    CONSOLE_CURSOR_INFO cursor ={1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    parada=getch();
    if(parada!=27){
      CONSOLE_CURSOR_INFO cursor ={2,TRUE};
      SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);           
      }
  }while(parada!=27);
}
void cadastrarAcervo(){
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  system("cls");
  do{
    textcolor(1);
    printf("Nome do item: ");
    textcolor(15);
    gets(acervo[qntItens]);
    textcolor(1);
    printf("\nNome do autor: ");
    textcolor(15);
    gets(acervoAutor[qntItens]);
    qntItens++;
    printf("Se deixa continuar aperte ENTER, caso deseja finalizar aperte ESC\n\n");
    CONSOLE_CURSOR_INFO cursor ={1,FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    parada=getch();
    if(parada!=27){
      CONSOLE_CURSOR_INFO cursor ={2,TRUE};
      SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);           
      }
  }while(parada!=27);
}
void modificarEventos(){
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  do{ 
    int codigo=0;
    system("cls");
    gotoxy(1,4);
    for(int x=0; x<sizeof(eventos)/sizeof(eventos[0]);x++){
      int retorno = strcmp(eventos[x], " ");
      if(retorno==1){
        textcolor(1);
        printf("Codigo: %i. %s \n\n",x,eventos[x]);
        textcolor(15);
        printf("%s \n\n",eventosDia[x]);
        }
      }
    gotoxy(1,1); printf("Escreva o codigo do evento que deseja modificar");
    gotoxy(1,2); scanf("%i",&codigo);
    fflush(stdin);
    system("cls");
    textcolor(1);
    printf("Evento selecionado: %s \n\n",eventos[codigo]);
    textcolor(15);
    printf("Data do evento: %s \n\n",eventosDia[codigo]);
    char temp[60]=" ";
    textcolor(1);
    printf("Caso não quiser fazer alteração no campo aperte ENTER. \n\n");
    printf("Digite o novo nome para o evento: ");
    gets(temp);
    if(strlen(temp)>0){
      strcpy(eventos[codigo], temp);
      }
    textcolor(15);
    printf("\n\nDigite a nova data do evento(DD/MM/AA HH:MM): ");
    gets(temp);
    if(strlen(temp)>0){
      strcpy(eventosDia[codigo], temp);
      }
    printf("Se deixa continuar aperte ENTER, caso deseja finalizar aperte ESC\n\n");
    parada=getch();
  }while(parada!=27);  
}
void modificarAcervo(){
  CONSOLE_CURSOR_INFO cursor ={2,TRUE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  do{ 
    int codigo=0;
    system("cls");
    gotoxy(1,4);
    for(int x=0; x<sizeof(acervo)/sizeof(acervo[0]);x++){
      int retorno = strcmp(acervo[x], " ");
      if(retorno==1){
        textcolor(1);
        printf("Codigo: %i. %s \n\n",x,acervo[x]);
        textcolor(15);
        printf("%s \n\n",acervoAutor[x]);
        }
      }
    gotoxy(1,1); printf("Escreva o codigo do evento que deseja modificar");
    gotoxy(1,2); scanf("%i",&codigo);
    fflush(stdin);
    system("cls");
    textcolor(1);
    printf("Item selecionado: %s \n\n",acervo[codigo]);
    textcolor(15);
    printf("Autor: %s \n\n",acervoAutor[codigo]);
    char temp[60]=" ";
    textcolor(1);
    printf("Caso não quiser fazer alteração no campo aperte ENTER. \n\n");
    printf("Digite o novo nome para o item: ");
    gets(temp);
    if(strlen(temp)>0){
      strcpy(acervo[codigo], temp);
      }
    textcolor(15);
    printf("\n\nDigite novo nome do autor: ");
    gets(temp);
    if(strlen(temp)>0){
      strcpy(acervoAutor[codigo], temp);
      }
    printf("Se deixa continuar aperte ENTER, caso deseja finalizar aperte ESC\n\n");
    parada=getch();
  }while(parada!=27);
}
void dadosUser(){
  CONSOLE_CURSOR_INFO cursor ={1,FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
  system("cls");
  textcolor(1);
  printf("Usuario: ");
  textcolor(15);
  printf("%s\n\n",user);
  textcolor(1);
  printf("Nome: ");
  textcolor(15);
  printf("%s\n\n",nome_user);
  textcolor(1);
  printf("Endereço: ");
  textcolor(15);
  printf("%s\n\n",endereco_user);
  textcolor(1);
  printf("Celular: ");
  textcolor(15);
  printf("%s\n\n",celular_user);
  textcolor(1);
  printf("Email: ");
  textcolor(15);
  printf("%s\n\n",email_user);
  parada=getch(); 
}
