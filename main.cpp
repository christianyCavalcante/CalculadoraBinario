#include <iostream>


using namespace std;

string soma(string numero1, string numero2){
   return "soma\n";   
}

string subtracao(string numero1, string numero2){
   return  "subtracao\n";
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

    
cout << resultado;

}

