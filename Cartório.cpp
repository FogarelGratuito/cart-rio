#include<stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//variável chamada registro
{
	char arquivo[40]; //char= armazenar na string arquivo([40]= 40 variaveis)
    char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
    char nome[40];//char= armazenar na string nome([40]= 40 variaveis)
    char sobrenome[40];//char= armazenar na string sobrenome([40]= 40 variaveis)
    char cargo[40];//char= armazenar na string cargo([40]= 40 variaveis)
    
      printf("Digite o CPF a ser cadastrado: ");// conversando com o usuário
      scanf("%s", cpf); //scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      strcpy(arquivo, cpf); //strcpy(stringcopy) é responsável por copiar os valores das strings
    
      FILE *file; // criando o arquivo = FILE(acessa o file)*file(recebe o comando file)
      file = fopen(arquivo, "w");//file igual abra um arquivo(fopen) com o nome de(arquivo) e é um arquivo novo("w")
      fprintf(file,cpf);//fprintf=salvando no arquivo file oq o usuário digitar na string cpf
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("Digite o nome a ser cadastrado: ");//conversando com o usuário
      scanf("%s",nome);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,nome);//fprintf=salvando no arquivo file oq o usuário digitar na string nome
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("digite o sobrenome a ser cadastrado: ");//conversando com o usuário
      scanf("%s", sobrenome);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,sobrenome);//fprintf=salvando no arquivo file oq o usuário digitar na string sobrenome
      fclose(file);//fechando o arquivo 
    
	  file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
    
      printf("Digite o cargo a ser cadastrado: ");//conversando com o usuário
      scanf("%s",cargo);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,cargo);//fprintf=salvando no arquivo file oq o usuário digitar na string cargo
      fclose(file);//fechando o arquivo 
    
      file = fopen(arquivo, "a");//file igual abra um arquivo(fopen) com o nome de(arquivo) e eu quero atualizar esse arquivo("a")
      fprintf(file,",");//fprintf=salve no arquivo (file), (",") = para separar
      fclose(file);//fechando o arquivo
      system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
}
int consulta()//variável chamada consulta
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
    char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
    char conteudo[200];//char= armazenar na string conteudo([200]= 200 variáveis)
    
	  printf("Digite o CPF a ser consultado: ");//conversando com o cliente
 	  scanf("%s", cpf);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)
 	
 	  FILE *file;// entrando no campo do arquivo = FILE(acessa o file)*file(recebe o comando file)
 	  file= fopen(cpf,"r");//file igual abra um arquivo(fopen) com o nome de(cpf)e leia o arquivo("r" ler em ingles(read))
 	  
 	  if(file==NULL)//if(se)file for igual(==) a NULL(nulo) não existir
 	  {
 	  	printf("Não foi possivel encontrar o arquivo, digite novamente! \n");//mensagem de erro
	  }
 	  
 	  while(fgets(conteudo, 200, file) !=NULL)//while(enquanto)fgets= vai buscar no arquivo conteudo com tamanho de 200 !=(é para a função parar quando for) NULL(nulo)
 	  {
 	  	printf("\n Essas são as informções do usuário: ");//conversando com o usuário
 	  	printf("%s", conteudo);//mostre para o cliente o conteúdo da %s(string armazenada)
 	  	printf("\n\n");//espaços na mensagem
	  }
 	  	  
}

int deletar()//variável chamada deletar
{
   setlocale(LC_ALL, "portuguese"); //definindo a linguagem
   
   char cpf[40];//char= armazenar na string cpf([40]= 40 variaveis)
   
   printf("Digite o CPF ser deletado: ");//conversando com o usuário
   scanf("%s",cpf);//scanf(tem como objetivo escanear oq o usuario digita) %s(tem como objetivo armazenar na string)   
   
   remove(cpf);//remove(remover) o (cpf) digitado

   	FILE *file;// entrando no campo do arquivo = FILE(acessa o file)*file(recebe o comando file)
 	file= fopen(cpf,"r");//file igual abra um arquivo(fopen) com o nome de(cpf)e leia o arquivo("r" ler em ingles(read))
 	  
 	if(file==NULL)//if(se)file for igual(==) a NULL(nulo) não existir
 	  {
 	  	printf("este arquivo não existe!\n");//mensagem de erro
 	  	system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
	  }
	  
}

int main() //definindo variáveis
{
	int opcao=0; //Variavel chamada opção
	int laco=1; // variavel chamda laco
	
	for(laco=1;laco=1;) //for=laço de repetição
	{  //inicio da seleção
	
	
       setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	   printf("### Cartório Da Rapaziada ### \n\n "); // titulo de entrada do nosso cartório
	   printf("escolha a opção desejada no menu:\n\n"); // dando direção ao usuário
	   printf("\t1 - Registrar aluno\n"); // tecle 1 para registrar o próximo usuário
	   printf("\t2 - Consultar alunos já resgistrado\n"); // tecle 2 para consultar os dados de algum aluno
	   printf("\t3 - Deletar resgistro de alunos\n"); // tecle 3 para deletar os dados de algum aluno
	   printf("\t4 - Sair do sistema\n");//tecle 4 para sair do sistema
	   printf("Opção:");
	   scanf("%d", &opcao); //scanf(tem como objetivo escanear oq o usuario digita) %d(tem como objetivo armazenar na variavel) &variavel(onde vai ser armazenado
	
	   system("cls"); //tem por função limpar a tela depois q o usuário digitar a sua opção
	   
	   switch(opcao)//laço de repetição para a variável opção
	   {
	   	 case 1://caso o usuário digite 1, faça oq pedi na variável registro()
	   	    registro();//variável registro()
	        break;//quebra
	        
	     case 2://caso o usuário digite 2, faça oq pedi na variável consulta()
	      consulta();//variável consulta()
		   break;//quebra
		   
		 case 3://caso o usuário digite 3,faça oq pedi na variável deletar()
		   deletar();//variável deletar()
		   break;//quebra
		 
		 case 4:
		   printf("até uma próxima!!");
		   return 0;
		   break; 
		  
		 default://caso o cliente não escolha nenhuma das opções acima
		   	printf("\tEstá opção não está disponivel\n" );// mensagem caso nenhuma das opções(1, 2, 3) forem escolhidas
		    system("pause");//system("pause")= pause o systema para o cliente ter o tempo que precisar para ver a mensagem
		    break;//quebra
	   }
	
	   } //fim da seleção
	
}

