#include <iostream>
#include <stdio.h>


using namespace std;


void validarBinario(char numero){
  if(numero != '0' && numero != '1'){
      cout << "NÚMERO NAO BINARIO INFORMADO"<<endl;
      exit (EXIT_FAILURE);
    }
}

void completarComZeros(string& numero1, string& numero2){
  //unificar o tamnho das string, adicionando zeros a frente
    while(numero1.length() != numero2.length()){      
      if(numero1.length()> numero2.length()){
        numero2 = "0" +numero2;
      }else{
        numero1 = "0" +numero1;
      }

    }    
}
bool ehMaior(string numero1, string numero2){
    //completar com zeros para comparar as strings
    completarComZeros(numero1,numero2);    
    return numero1 >numero2;
}

bool ehMaiorOuIgual(string numero1, string numero2){
    //completar com zeros para comparar as strings
    completarComZeros(numero1,numero2);    
    return numero1 >= numero2;
}

string soma(string numero1, string numero2){
    completarComZeros(numero1,numero2);  
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
    completarComZeros(numero1,numero2);    

    string sinal = "";

  //se o numero2 for maior, o resultado será negativo.
  //Como o metodo de complemento de dois não suporta essa operação, inverto os valores e acrescento o sinal ao resultado final;
    if(ehMaior(numero2, numero1)){
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

    if(resultadoPacial.length()>1){
      return  sinal + resultadoPacial.substr (1,resultadoPacial.length()); 
    }else{
      return  sinal + resultadoPacial; 
    }

}

string divisao(string numero1, string numero2, string& modulo){
   
   string result = "0";
   string  parcial = numero1;
   
   while(ehMaior(parcial,"0")  && ehMaiorOuIgual(parcial,numero2)){
    
    
    parcial = subtracao(parcial, numero2);
    
    result = soma(result, "1");
   }
   
   modulo = parcial;
   return result;
}

string multicacao(string numero1, string numero2){
  string paciais[numero2.length()];

   
    string completarZeros = "";
    for(int j = numero2.length()-1; j >= 0 ; j--){
      string parcial= "";
      for(int i = numero1.length()-1; i >= 0; i--){
        int r = (numero1[i] - '0') * (numero2[j] - '0') ;        
        parcial = char(r + '0') + parcial;       
      }
      paciais[j]= parcial+completarZeros;
      completarZeros+="0";
    
  }

  string somaParciais = "0";
  for(int j = numero2.length()- 1; j>=0 ; j--){    
    somaParciais = soma(somaParciais, paciais[j]);
  }

   return somaParciais;
}

string  modulo(string numero1, string numero2){
  string mod;
  divisao(numero1,numero2,mod);
   return  mod;
}


int main() {
  

  // int i = -1;
  // cout<<i<<endl;
  char operacao;
  string numero1;
  string numero2;
  string resultado;
  string mod;
  
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
        resultado = divisao(numero1, numero2,mod);
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


