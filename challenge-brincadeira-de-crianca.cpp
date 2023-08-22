#include <iostream>
using namespace std;

template <typename T>
class Node {
  private: 
    template<typename U> friend class MyQueue;
  public: 
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node () {
      this->next = nullptr;
      this->prev = nullptr;
  };
};

template <class T>
class MyQueue {
  public: 
    Node<T>* head;
    Node<T>* tail;
    int size;
    MyQueue () {
      this->head = nullptr;
      this->tail =  nullptr;
      this->size =  0; 
    };

    void enqueue (T value) {
      Node<T>* newNode = new Node<T>[1];
      newNode->data = value;
      if (!head) {
        head = newNode;
        tail = this->head;
      } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
      };
      size += 1;
    };

    T pop () {
      if (this->isEmpty()) return -1;
      T result = tail->data;
      if (size == 1) {
        head = NULL;
        tail = head;
      } else {
        tail = tail->prev;
        tail->next = NULL;
      };
      size -= 1;
      return result;
    };

    bool isEmpty () {
      return head == NULL && size == 0; 
    };

    T dequeue () {
      T result;
      if (this->isEmpty()) return -1;
      result = head->data;
      if ( size == 1 ) {
        head = NULL;
        tail = head;
      } else {
        head = head->next;
        head->prev = NULL;
      };
      size -= 1;
      return result;
    };

    T removeByIndex ( int index ) {
      // verifica se a lista está vazia;
      if (this->isEmpty()) return -1;

      Node<T> *temp, *before, *after;
      T result;

      // retorna o primeiro elemento se o indice for 1;
      if (index == 1) {
        result =  this->dequeue();
        return result;
      };

      // retorna o ultimo elemento se o indice for igual size;
      if (index == size){
        result = this->pop();
        return result;
      };

      // itera sobre a a fila enquanto o input é diferente do indice;
      temp = head->next;
      int i = 2; 
      while (i != index ) {
        if (i == size-1 ) {
          result = -1;
          break;
        };
        i += 1;
        temp = temp->next;
      };
      result = temp->data;
      // liga os elemntos que ficaram
      before = temp->prev; 
      after = temp->next;
      before->next = after;
      after->prev = before;
      
      size -= 1;
      delete temp;
      
      return result;
    };

    T removeByValue ( T value ) {
      // verifica se a lista está vazia;
      if (this->isEmpty()) return -1;

      Node<T> *temp, *before, *after;
      T result;

      // retorna o primeiro elemento se o indice for 1;
      if (value == head->data) {
        result =  this->dequeue();
        return result;
      };

      // retorna o ultimo elemento se o indice for igual size;
      if (value == tail->data){
        result = this->pop();
        return result;
      };

      // itera sobre a a fila enquanto o input é diferente do indice;
      temp = head->next;
      int i = 2; 
      while (value != temp->data) {
        if ( i == size-1 ) {
          result = -1;
          break;
        };
        i += 1;
        temp = temp->next;
      };
      result = temp->data;
      // liga os elemntos que ficaram
      before = temp->prev; 
      after = temp->next;
      before->next = after;
      after->prev = before;
      
      size -= 1;
      delete temp;
      
      return result;
    };
};

int main() {
  // Escreva seu código aqui
  int qtyPlayers, qtyRounds, test = 0;
  while (
    cin >> qtyPlayers >> qtyRounds && 
    (qtyPlayers && qtyRounds)
  ) {
    
    //Enfileirar jogadores;
    MyQueue<int> queue;
    int player;
    for (int i  = 0; i < qtyPlayers; i++) {
      cin >> player;
      queue.enqueue(player);
    };

    int currRound = qtyRounds;
    while (currRound--) {
      int currQtyPlayers, command, action, excluded = 0;
      cin >> currQtyPlayers >> command;
      for (int i = 0; i < currQtyPlayers; i++) {
        cin >> action;
        if (action != command) {
          queue.removeByIndex(i+1-excluded);
          excluded += 1;
        };
      };
    } ;

    cout << "Teste " <<  ++test << endl; 
    cout << queue.dequeue() << endl;
    cout << endl; 
  };
  return 0;
};

/*
  partida 1
  participantes, rodadas
  fila organizada pelo chefe
  nparticipantes ordem açao açao
*/