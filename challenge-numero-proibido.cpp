#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

template <class T>
class Node {
  private: 
    template <typename U> friend class HashTable;
  public: 
    string key;
    T value;
    Node* next;

    Node (string key, T value) {
      this->key = key;
      this->value = value;
      this->next = NULL;
    };

    Node (Node &object) { //copia do contrutor;
      this->key = object.key;
      this->value =  object.value;
      this->next = NULL;
    };

    ~Node () { //destrutor;
      Node *head = this;
      while ( head != NULL ) {
        Node* currNode = head;
        head = head->next;
        delete currNode;
      };
    };
};

template <class T>
class HashTable {
  private:
    int hashFunction (string key) {
      int bucketIndex;
      ll sum = 0, factor = 31;
      for (int i = 0; i < key.size(); i++) {
        sum = (sum % this->capacity) + ((key[i] - '0') * factor);
        sum %= this->capacity;
        factor = (factor % INT16_MAX) * (31 % INT16_MAX);
        factor %= this->capacity;
      };
      bucketIndex = sum;
      return bucketIndex;
    };
    Node<T>** arr;
  public:
    int numOfElements;
    int capacity;
    HashTable (int size) {
      this->capacity = size;
      this->numOfElements = 0;
      this->arr = new Node<T>* [this->capacity]; 
      this->arr[0] = NULL;
    };

    void insert (string key, T value) {
      int index = this->hashFunction(key);
      if (this->arr[index] == NULL) {
        Node<T>* newNode = new Node<T>(key,value);
        this->arr[index] = newNode;
      } else {
        Node<T>* newNode = new Node<T>(key, value);
        newNode->next = this->arr[index];
        this->arr[index] = newNode;
      };
    };
    
    T search (string key) {
      int index = this->hashFunction(key);
      Node<T>* headNode = this->arr[index];
      if (headNode->key == key) return headNode->value;
      else {
        while (headNode->next != NULL) {
          if (headNode->key == key) return headNode->value;
          headNode = headNode->next;
        }
      };
      return 0;
    }
};

 
int main() {
  // Escreva seu c�digo aqui
  int N;
  cin >> N;
  HashTable<bool> table = HashTable<bool>(N);
  
  string key;
  while (N--) {
    cin >> key;
    table.insert(key, true);
  };
  while (cin >> key) cout << (table.search(key) ? "sim" : "nao") << endl;
  return 0;
};
