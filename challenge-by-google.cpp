#include <iostream>
using namespace std;

struct Gift {
  int day;
  int cost;
};

int main() {
  /*
   * Receber qtd de presentes;
   */

  int qtyGifts;
  cin >> qtyGifts;

 /*
  * Inicializar lista de presentes, carrinho e orçamento autal;
  */ 

  Gift giftList[qtyGifts] = {};
  Gift cart[1000]; 
  int currBudget = 0; 

  /*
   * Popular a lista de presentes;
   */

  for (int i = 0; i < qtyGifts; i++ ) {
    Gift item;
    cin >> item.day >> item.cost;

    giftList[i] = item;
  };



  int cartSize = 0;
  for (int i = 0; i < qtyGifts; i++ ) {
    Gift currGift = giftList[i];
    cart[cartSize] = currGift;   // Adicinar o presente no carrinho;

    cartSize += 1;
    currBudget = currGift.day; //definir o orçamento atual;

    /*
    * Calcular o total no carrinho;
    */
    int total = 0;
    for(int j = 0; j < cartSize; j++) {
      total += cart[j].cost;
    };


    while (total > currBudget) { //verificar se o total é maior que a capacidade atual 
      int idMax = 0;

      // Pegar o index do presente com maior custo;
      for(int j = 1; j < cartSize; j++) {
        if( cart[j].cost > cart[idMax].cost) {
          idMax = j;
        };
      };

      total -= cart[idMax].cost;

      // realocar os presentes para esquerda do carrinho para remover o presente com maior custo;
      for (int k = idMax; k < cartSize-1; k++) {
        cart[k] = cart[k+1];
      };

      cartSize -= 1; //decrementar a qtd de items no carrinho
    };
  };
  cout << cartSize;
 
  return 0;
}

/*
 - Token não pode ultrapassar os 3kb. 
 - Estudar o Keycloak.
 - Adicionar o sonarqube no front-end;

 lastValue = 0, total = 0;

1:
  budgets = 3;
  currValue = 2;
  if (currValue + total) <= budgets
    cartSize += 1;
    total += currValue; 

2: 
  budgets = 5;
  currValue = 4;
  if (currValue + total) <= budgets 
    cartSize += 1;
    Total += currValue;

3:
  budgets = 6
  currValue = 3;
  if (currValue + total) <= budgets 
    cartSize += 1;
    Total += currValue;

*/