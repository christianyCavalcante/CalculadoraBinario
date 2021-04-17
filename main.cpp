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

//subtração utilizando método de complemento de dois
string subtracao(string numero1, string numero2){
    numero1 = "0"+numero1;
    numero2 = "0"+numero2;
    string sinal = "";

  //se o numero2 for maior, o resultado será negativo.
  //Como o metodo de complemento de dois não suporta essa operação, inverto os valores e acrescento o sinal ao resultado final;
    if(numero2 > numero1){
      string aux = numero1;
      numero1 = numero2;
      numero2 = aux;
      sinal = "-";
    }

    string complemento1 = "";
    for(int i = 0; i<numero2.size(); i++){      
      complemento1 = complemento1 + (numero2[i] == '0' ? '1' : '0');
    }
    

    string completemento2 = soma(complemento1, "1");
    

    string resultadoPacial = soma(numero1,completemento2);
    cout<<"resultadoPacial"<<resultadoPacial<<endl;

    if(resultadoPacial.length()>1){
      return  sinal + resultadoPacial.substr (1,resultadoPacial.length()); 
    }else{
      return  sinal + resultadoPacial; 
    }

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


