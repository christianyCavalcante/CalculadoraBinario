#include <iostream>
#include <stdio.h>

using namespace std;


void validarBinario(char numero){
  if(numero != '0' && numero != '1'){
      cout << "NÚMERO NAO BINARIO INFORMADO"<<endl;
      exit (EXIT_FAILURE);
    }
}


string soma(string numero1, string numero2){
  
    string result = ""; 
    int s = 0;         
    int tam1 = numero1.size() - 1, tam2 = numero2.size() - 1;
    while (tam1 >= 0 || tam2 >= 0 || s == 1)
    {
        
      if(tam1 >= 0){
        validarBinario(numero1[tam1]);
        s += numero1[tam1]- '0';
      }

      if(tam2 >= 0){
        validarBinario(numero2[tam2]);
        s += numero2[tam2]- '0';
      }  
       
      result = char(s % 2 + '0') + result;
      s /= 2;
  
        
      tam1--; tam2--;
    }
    return result;
}

string subtracao(string numero1, string numero2){
    string result = ""; 
    int s = 0;         
    int tam1 = numero1.size() - 1, tam2 = numero2.size() - 1;
    while (tam1 >= 0 || tam2 >= 0)
    {
        
      if(tam1 >= 0){
        validarBinario(numero1[tam1]);
        s += numero1[tam1]- '0';
      }

      if(tam2 >= 0){
        validarBinario(numero2[tam2]);
        s -= numero2[tam2]- '0';
      }

    

    if(s==-1){
      
      if(tam1 == 0 && tam2 == 0){
        result = "-1" + result;
      }else{
        result = "1" + result;
      }
      
    }else{    
      
      result = char(s + '0') + result;
      s = 0;
    }
  
  
  
    
        
      tam1--; tam2--;
    }
    return result;
    }

string divisao(string numero1, string numero2){
   return  "divisao\n";
}

string multicacao(string numero1, string numero2){
   return  "multicacao\n";
}

string  modulo(string numero1, string numero2){
   return  "modulo\n";
}


int main() {
  // int i = -1;
  // cout<<i<<endl;
  char operacao;
  string numero1;
  string numero2;
  string resultado;
  
    cin >> operacao;
    cin >> numero1;
    cin >> numero2;

    switch(operacao){
      case '+':
        resultado = soma(numero1, numero2);
        break;
      case '-':
        resultado = subtracao(numero1, numero2);
        break;
      case '/':
        resultado = divisao(numero1, numero2);
        break;
      case '*':
        resultado = multicacao(numero1, numero2);
        break;
      case '%':
        resultado = modulo(numero1, numero2);
        break;
      default:
      cout << "OPERACAO INVALIDA\n";
    }

    
  cout << resultado<<endl;
 
return 0;
}


