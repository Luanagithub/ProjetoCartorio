#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.


int registro()//Opção número (1)
{
//abertura da função de registrar	

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
//definição de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Mensagem ao usuário pedindo o CPF
	scanf("%s", cpf); //Armazenar valor
	
	strcpy(arquivo, cpf);
	//Copiar de uma pasta para outra
	
	FILE *file;//Iniciar
	file = fopen(cpf,"w"); //Abrir pasta cpf
	fprintf(file,cpf); //Imprimir na pasta
	fclose(file); //Fechar pasta
	
	file = fopen(arquivo,"a"); //Abrir pasta de arquivo
	fprintf(file,","); //Imprime espaço
	fclose(file); //Fechar pasta
	
	printf("Digite o nome a ser cadastrado:");//Pedir para inserir o nome
	scanf("%s",nome);//Armazenar com "&s" a info em -nome-
	
	file = fopen(arquivo,"a"); //Abrir a pasta no local arquivo
	fprintf(file,nome); //Definir espaço com o valor inserido -nome-
	fclose(file); //Fechar a pasta
	
	file = fopen(arquivo,"a"); //Chamar a pasta no local arquivo
	fprintf(file,","); //Imprimir espaço na pasta
	fclose(file); //Fechar a pasta
	
	printf("Digite o sobrenome a ser cadastrado: "); //Pedir para inserir as informações
	scanf("%s",sobrenome); //Salvar o valor -sobrenome-
	
	file = fopen(arquivo,"a");//Abrir a pasta no local arquivo
	fprintf(file,sobrenome);//Definir no espaço -sobrenome-
	fclose(file);//Fechar a pasta
	
	file = fopen(arquivo,"a"); //Abrir a pasta no local arquivo
	fprintf(file,","); //Imprimir espaço no arquivo
	fclose(file); //Fechar a pasta
	
	printf("Digite o cargo a ser cadastrado: "); //Pedir para digitar o cargo do cadastro
	scanf("%s",cargo); //Armazenar a informação em -cargo-.
	
	file = fopen(arquivo,"a");//Abre a pasta;
	fprintf(file,cargo);//Imprime -cargo- na pasta;
	fclose(file);//fechar a pasta;
	
}


int consulta()//Opção número (2)
{
	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem dentro da função.
	
	char cpf[40]; //cadeia de caracteres
	char conteudo[200]; //cadeia de caracteres
	
	printf("Digite o CPF a ser consultado: "); //informação requisitada
	scanf("%s",cpf); //cpf armazenado
	
	FILE *file;
	file = fopen(cpf,"r"); //ler a pasta cpf
	//r = read?
	
	if(file == NULL)  
	//Condição para pasta vazia
	{
		printf("Não foi possível abrir o arquivo,não foi localizado!.\n");
	}
	while(fgets(conteudo,200,file) != NULL)//Condição While esperada
	{
		printf("Essas são as informações do usuário.\n");
		printf("%s",conteudo);
		printf("\n\n");//imprimindo na tela o que foi armazenado %s
	}

}


int deletar()//Opção número (3)
{
	printf("Você escolheu deletar nomes!\n"); //Mensagem ao escolher (3)

	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s para receber strings e armazenar em cpf
	
	//Usar função importada 'remove'
	//O programa acessa a pasta principal e remove.
	FILE *file;//"ponteiro"
	file=fopen(cpf,"r");//Procurar o arquivo cpf. Ler o cpf(string)
	remove(cpf);
		if(file) 
	{
		//Se o arquivo for "nulo"/não encontrado/-o programa responde o seguinte-
		
		printf("O usuário não se encontra no sistema!. \n");
		
		system("pause");
		// system pause, aguarda pressionar tecla
	}
	fclose(file);
}


int main()
{
	int opcao=0;//variável que armazena o valor da escolha
	int laco=1;//variável do laco
	char senhadigitada[10]; 
	int loop=1;
	
for(loop=1;loop=1;){
	
	printf("###Cartorio da EBAC ###\n");
	printf("###Sistema de Log-in!###\n\nDigite a senha de acesso:");
	scanf("%s",senhadigitada);
	system("cls");
	

		
	if(strcmp(senhadigitada,"admin") == 0 ){

		
		for(laco=1;laco=1;)//loop 1x
		//for faz "iniciar" o sistema.
		{
			system ("cls");
			
			//system ("cls")limpar a tela.
			
			setlocale(LC_ALL,"Portuguese");//Definindo a linguagem.
			
			printf("### Escolha a opção desejada do menu ### \n\n");//Início do menu.
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1-Registrar nomes \n");//mensagem 1
			printf("\t2-Consultar nomes \n");//mensagem 2
			printf("\t3-Deletar nomes\n");//mensagem 3
			printf("\t4-Sair do Sistema\n");//mensagem 4
			printf("Opção:");
			
			scanf("%d",&opcao); 
		
			
			system("cls"); //Responsável por limpar a tela de menu.
			
			switch(opcao) //Início da seleção.
			//retorna funções.
			{
				case 1:
					registro();
					system("pause");
					break;
					
				case 2:
					consulta();
					system("pause");
					break;
					
				case 3:
					deletar();
					system("pause");
					break;
					
				case 4:
					printf("\nVocê selecionou fechar o sistema.\n");
					return 0;
					break;
					
				default:
					printf("Essa opção não está disponível!\n");
					system("pause");
					break;

				}		
			}
		}
		
	printf("---------------------------------\n");
	printf("|       Senha incorreta!        |\n---------------------------------\n\nTente outra senha de Log-in.\n\n");
  	
   }
}

	
