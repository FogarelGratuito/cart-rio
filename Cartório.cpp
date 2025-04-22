#include<stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//vari�vel chamada registro
{
	char arquivo[40]; //char= armazenar na string arquivo([40]= 40 variaveis)
    char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
    char nome[40];//char= armazenar na string nome([40]= 40 variaveis)
    char sobrenome[40];//char= armazenar na string sobrenome([40]= 40 variaveis)
    char cargo[40];//char= armazenar na string cargo([40]= 40 variaveis)
    
      printf("Digite o CPF a ser cadastrado: ");// conversando com o usu�rio
      scanf("%s", cpf); //scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      strcpy(arquivo, cpf); //strcpy(stringcopy) � respons�vel por copiar os valores das strings
    
      FILE *file; // criando o arquivo = FILE(acessa o file)*file(recebe o comando file)
      file = fopen(arquivo, "w");//file igual abra um arquivo(fopen) com o nome de(arquivo) e � um arquivo novo("w")
      fprintf(file,cpf);//fprintf=salvando no arquivo file oq o usu�rio digitar na string cpf
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("Digite o nome a ser cadastrado: ");//conversando com o usu�rio
      scanf("%s",nome);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,nome);//fprintf=salvando no arquivo file oq o usu�rio digitar na string nome
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("digite o sobrenome a ser cadastrado: ");//conversando com o usu�rio
      scanf("%s", sobrenome);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,sobrenome);//fprintf=salvando no arquivo file oq o usu�rio digitar na string sobrenome
      fclose(file);//fechando o arquivo 
    
	  file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("Digite o cargo a ser cadastrado: ");//conversando com o usu�rio
      scanf("%s",cargo);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,cargo);//fprintf=salvando no arquivo file oq o usu�rio digitar na string cargo
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
      system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
}
int consulta()//vari�vel chamada consulta
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
    char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
    char conteudo[200];//char= armazenar na string conteudo([200]= 200 vari�veis)
    
	  printf("Digite o CPF a ser consultado: ");//conversando com o cliente
 	  scanf("%s", cpf);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
 	
 	  FILE *file;// entrando no campo do arquivo = FILE(acessa o file)*file(recebe o comando file)
 	  file= fopen(cpf,"r");//file igual abra um arquivo(fopen) com o nome de(cpf)e leia o arquivo("r" ler em ingles(read))
 	  
 	  if(file==NULL)//if(se)file for igual(==) a NULL(nulo) n�o existir
 	  {
 	  	printf("N�o foi possivel encontrar o arquivo, digite novamente! \n");//mensagem de erro
	  }
 	  
 	  while(fgets(conteudo, 200, file) !=NULL)//while(enquanto)fgets= vai buscar no arquivo conteudo com tamanho de 200 !=(� para a fun��o parar quando for) NULL(nulo)
 	  {
 	  	printf("\n Essas s�o as inform��es do usu�rio: ");//conversando com o usu�rio
 	  	printf("%s", conteudo);//mostre para o cliente o conte�do da %s(string armazenada)
 	  	printf("\n\n");//espa�os na mensagem
	  }
 	  	  
}

int deletar()//vari�vel chamada deletar
{
   setlocale(LC_ALL, "portuguese"); //definindo a linguagem
   
   char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
   
   printf("Digite o CPF ser deletado: ");//conversando com o usu�rio
   scanf("%s",cpf);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)   
   
   remove(cpf);//remove(remover) o (cpf) digitado

   	FILE *file;// entrando no campo do arquivo = FILE(acessa o file)*file(recebe o comando file)
 	file= fopen(cpf,"r");//file igual abra um arquivo(fopen) com o nome de(cpf)e leia o arquivo("r" ler em ingles(read))
 	  
 	if(file==NULL)//if(se)file for igual(==) a NULL(nulo) n�o existir
 	  {
 	  	printf("este arquivo n�o existe!\n");//mensagem de erro
 	  	system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
	  }
	  
}

int main() //definindo vari�veis
{
	int opcao=0; //Variavel chamada op��o
	int laco=1; // variavel chamda laco
	
	for(laco=1;laco=1;) //for=la�o de repeti��o
	{  //inicio da sele��o
	
	
       setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	   printf("### Cart�rio Da Rapaziada ### \n\n "); // titulo de entrada do nosso cart�rio
	   printf("escolha a op��o desejada no menu:\n\n"); // dando dire��o ao usu�rio
	   printf("\t1 - Registrar aluno\n"); // tecle 1 para registrar o pr�ximo usu�rio
	   printf("\t2 - Consultar alunos j� resgistrado\n"); // tecle 2 para consultar os dados de algum aluno
	   printf("\t3 - Deletar resgistro de alunos\n"); // tecle 3 para deletar os dados de algum aluno
	   printf("\t4 - Sair do sistema\n");//tecle 4 para sair do sistema
	   printf("Op��o:");
	   scanf("%d", &opcao); //scanf(tem como objetivo escanear oq o usuario digita) %d(tem como objetivo armazenar na variavel) &variavel(onde vai ser armazenado
	
	   system("cls"); //tem por fun��o limpar a tela depois q o usu�rio digitar a sua op��o
	   
	   switch(opcao)//la�o de repeti��o para a vari�vel op��o
	   {
	   	 case 1://caso o usu�rio digite 1, fa�a oq pedi na vari�vel registro()
	   	    registro();//vari�vel registro()
	        break;//quebra
	        
	     case 2://caso o usu�rio digite 2, fa�a oq pedi na vari�vel consulta()
	      consulta();//vari�vel consulta()
		   break;//quebra
		   
		 case 3://caso o usu�rio digite 3,fa�a oq pedi na vari�vel deletar()
		   deletar();//vari�vel deletar()
		   break;//quebra
		 
		 case 4:
		   printf("at� uma pr�xima!!");
		   return 0;
		   break; 
		  
		 default://caso o cliente n�o escolha nenhuma das op��es acima
		   	printf("\tEst� op��o n�o est� disponivel\n" );// mensagem caso nenhuma das op��es(1, 2, 3) forem escolhidas
		    system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
		    break;//quebra
	   }
	
	   } //fim da sele��o
	
}

