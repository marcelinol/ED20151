/* Copyright [2015] <LeoSL>
 * Pilha.hpp
 */
template<typename T>

class Pilha {
 private:
  int top;
  int max;
  T* dados[];

 public:
  Pilha() {
    max = 100;
    dados[max];
    top = -1;
  }

  Pilha<T> (int t) {
    max = t;
    top = -1;
  }

  void empilha(T dado) {
    if (PilhaCheia()) {
      throw "Pilha Cheia!";
    }
    top += 1;
    dados[top] = dado;
  }

  T desempilha() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    top -= 1;
    return dados[top+1];
  }

  T topo() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    return dados[top];
  }

  int getPosTopo() {
    return top;
  }

  void limparPilha() {
    top = -1;
  }

  bool PilhaVazia() {
    return top == -1;
  }

  bool PilhaCheia() {
    return top == (max - 1);
  }
};