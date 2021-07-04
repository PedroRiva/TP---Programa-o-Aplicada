#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct No{
  float info;
  No* proximo;
};

struct Lista{
  No* primeiro;
  No* end;
  No* marcador;
  int len;
};

void CriaListaNull(Lista* pLista){
  pLista->primeiro = NULL;
  pLista->end = NULL;
  pLista->marcador = NULL;
  pLista->len = 0;
}

int lenLista(Lista* pLista){
  return (pLista->len);
}

bool listaVazia(Lista* pLista){
  return (pLista->len==0);
}

bool finalLista(Lista* pLista){
  return (pLista->marcador == NULL);
}

No* criaNo(float item){
  No* no = new No;

  no->info = item;
  no->proximo = NULL;

  return no;
}

void incluirElementoEnd(Lista* pLista, float info){
  No* no;
  no = criaNo(info);

  if (listaVazia(pLista)){pLista->primeiro = no;}
  else{pLista->end->proximo = no;}

  pLista->end = no;
  pLista->marcador = no;
  pLista->len++;
}

void mostrarLista(Lista* pLista){
    pLista->marcador = pLista->primeiro;
    int cont=0;
    while(!finalLista(pLista)){
      float informacao = pLista->marcador->info;
      if (cont==0){ //primeiro numero complexo;
        cout << "----PAR DE COMPLEXOS----" << endl;
        cout << "Z1: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if (cont==1){//segundo numero complexo;
        cout << "Z2: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==2){//soma;
        cout << "SOMA: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==3){//subtracao;
        cout << "SUBTRACAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==4){//multiplicacao;
        cout << "MULTIPLICACAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==5){//divisao;
        cout << "DIVISAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==6){//modulo;
        cout << "MODULO Z1: " << informacao << endl;;
      }else if(cont==7){//modulo;
        cout << "MODULO Z2: " << informacao << endl;
        cont=-1;
      }
      pLista->marcador = pLista->marcador->proximo;
      cont++;
    }
    cout << endl;
}

void lerArquivo(Lista* pLista){
    pLista->marcador = pLista->primeiro;
    ifstream lArquivo;
    lArquivo.open("arquivo.txt", ios::in);
    float leitura;
    while(!lArquivo.eof()){
      lArquivo >> leitura;
      incluirElementoEnd(pLista, leitura);
    }
    lArquivo.close();
}

void gravarArquivo(Lista* pLista){
  pLista->marcador = pLista->primeiro;
  ofstream gArquivo;
  gArquivo.open("arquivo.txt", ios::out);
  int cont=0;
  while(!finalLista(pLista)){
    float informacao = pLista->marcador->info;
    gArquivo << informacao << " ";
    pLista->marcador = pLista->marcador->proximo;
    cont++;
    if (cont % 14 == 0){
      gArquivo << "\n";
    }
  }
  gArquivo.close();
}
//######################################################################################
struct tComplexo {
		float pr1, pr2,p_i1, somareal, somaimag,prod;
		float partei2;
		void soma (float pr1, float p_i1, float pr2, float partei2, Lista* nComplexo)
		{
			float somareal, somaimag;
			somareal= (pr1+pr2);
      incluirElementoEnd(nComplexo, somareal);
			somaimag = (p_i1+partei2);
      incluirElementoEnd(nComplexo, somaimag);
		}
		
		void diff(float pr1, float p_i1, float pr2, float partei2, Lista* nComplexo)
		{
			float diffreal,diffimag;
			diffreal = (pr1-pr2);
      incluirElementoEnd(nComplexo, diffreal);
			diffimag = (p_i1-partei2);
      incluirElementoEnd(nComplexo, diffimag);
		}
		
		void produto (float pr1, float p_i1, float pr2, float partei2, Lista* nComplexo)
		{
			float prodreal,prodimag;
			prodreal = ((pr1*pr2)-(p_i1*partei2));
      incluirElementoEnd(nComplexo, prodreal);
			prodimag = ((pr1*partei2)+(p_i1*pr2));
      incluirElementoEnd(nComplexo, prodimag);
		}
		
		void divisao (float pr1, float p_i1, float pr2, float partei2, Lista* nComplexo)
		{
			float mod1,mod2,alpha1,alpha2,modres,alphares,conver1,conver2;
			mod1 = sqrt(((pr1*pr1)+(p_i1*p_i1)));
			mod2 = sqrt(((pr2*pr2)+(partei2*partei2)));
			alpha1 = atan (p_i1/pr1);
			alpha2 = atan (partei2/pr2);
			modres = mod1/mod2;
			alphares = alpha1-alpha2;
			conver1 = modres*cos(alphares);
      incluirElementoEnd(nComplexo, conver1);
			conver2 = modres*sin(alphares);
      incluirElementoEnd(nComplexo, conver2);
		}
		
		
		void modulo (float pr1, float p_i1, float pr2, float partei2, Lista* nComplexo)
		{
			float modulo1, modulo2;
			modulo1 = sqrt(((pr1*pr1)+(p_i1*p_i1)));
      incluirElementoEnd(nComplexo, modulo1);
			modulo2 = sqrt(((pr2*pr2)+(partei2*partei2)));
      incluirElementoEnd(nComplexo, modulo2);
		}
	};
//############################################################################
void Gravar(Lista* nComplexo, tComplexo Comp){
  cout<<"Digite parte real 1: ";
	cin>>Comp.pr1;
  incluirElementoEnd(nComplexo, Comp.pr1);
	cout<<"Digite imaginaria 1: ";
	cin>>Comp.p_i1;
  incluirElementoEnd(nComplexo, Comp.p_i1);
	cout<<"Digite parte real 2: ";
	cin>>Comp.pr2;
  incluirElementoEnd(nComplexo, Comp.pr2);
	cout<<"Digite imaginaria 2: ";
	cin>>Comp.partei2;
  incluirElementoEnd(nComplexo, Comp.partei2);
	
	Comp.soma (Comp.pr1, Comp.p_i1, Comp.pr2, Comp.partei2, nComplexo);
  Comp.diff(Comp.pr1, Comp.p_i1, Comp.pr2, Comp.partei2, nComplexo);
  Comp.produto(Comp.pr1, Comp.p_i1, Comp.pr2, Comp.partei2, nComplexo);
  Comp.divisao(Comp.pr1, Comp.p_i1, Comp.pr2, Comp.partei2, nComplexo);
  Comp.modulo(Comp.pr1, Comp.p_i1, Comp.pr2, Comp.partei2, nComplexo);
}
//############################################################################
int main ()
{
  ofstream gArquivo;
    gArquivo.open("arquivo.txt", ios::out);
    gArquivo << " 0 0 0 0 0 0 0 0 0 0 0 0 0 0";
    gArquivo.close();
  Lista* nComplexo = new Lista; //separa um espaço de memória para a lista;

  CriaListaNull(nComplexo); //cria a lista como vazia;

	tComplexo Comp; //define o objeto comp do tipo tComplexo;
 
  int opcao=0;
  while(true){
    cout << "VOCE DESEJA: " << endl;
    cout << "1) escrever no arquivo." << endl;
    cout << "2) ler o arquivo." << endl;
    cout << "3) sair." << endl;
    cout << "Opcao: ";
    cin >> opcao;
    if (opcao == 3){ //fecha o programa
      break;
    }
    else{
      if (opcao == 1){ //grava
        int quant=0;
        cout << "Quantos pares de numeros complexos voce quer inserir?" << endl;
        cout << "Quantidade deve ser par: ";
        cin >> quant;
        for (int i=0; i<quant; i++){
          Gravar(nComplexo,Comp);
          cout << "------------------" << endl;
        }
        gravarArquivo(nComplexo);
        CriaListaNull(nComplexo);//zera a primeira posição da lista
      }
      else if (opcao == 2){ //le
        lerArquivo(nComplexo);
        mostrarLista(nComplexo);
      }
    }
  }
}