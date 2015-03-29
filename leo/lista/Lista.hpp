/* Copyright [2015] <LeoSL>
 * Lista.hpp
 */
template <typename T>

#define MAXLISTA 100

class Lista {
 private:
  int inicio = 0;
  int pos = 0;
  int ultimo;
  int tam = MAXLISTA;
  T* dados = new T[tam];

 public:
  Lista() {
    init();
  }

  explicit Lista<T>(int size) {
    tam = size;
    init();
  }

  void init() {
    ultimo = -1;
  }

  void adiciona(T dado) {
    adicionaNaPosicao(dado, ultimo);
  }

  void adicionaNoInicio(T dado) {
    adicionaNaPosicao(dado, inicio);
  }

  T retiraDoInicio() {
    return retiraDaPosicao(inicio);
  }

  bool listaCheia() {
    return ultimo == (tam - 1);
  }

  bool listaVazia() {
    return ultimo == -1;
  }

  void destroiLista() {
    ultimo = -1;
  }

  bool contem(T dado) {
    int retorno = posicao(dado);
    return typeid(retorno) == typeid(ultimo);
  }

  bool igual(T dado1, T dado2) {
    return !(maior(dado1, dado2) && menor(dado1, dado2));
  }

  bool menor(T dado1, T dado2) {
    return !(maior(dado1, dado2));
  }

  bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }

  int posicao(T dado) {
    excecaoListaVazia();

    while ((pos <= ultimo) && (dados[pos] != dado)) {
      pos++;
    }

    if (pos > ultimo) {
      throw("Não existe este elemento na Lista!");
    }

    return pos;
  }

  T retira() {
    excecaoListaVazia();
    return retiraDaPosicao(ultimo);
  }

  void adicionaEmOrdem(T dado) {
    excecaoListaCheia();

    while (pos <= ultimo && maior(dado, dados[pos])) {
      pos++;
    }
    return adicionaNaPosicao(dado, pos);
  }

  void adicionaNaPosicao(T dado, int destino) {
    excecaoListaCheia();

    ultimo++;
    pos = ultimo;

    while ((pos > destino)) {
      dados[pos] = dados[pos - 1];
      pos--;
    }

    dados[destino] = dado;
  }

  T retiraDaPosicao(int destino) {
    if (destino < 0 || destino > ultimo + 1) {
      throw("Posicao Invalida!");
    }

    T dado = dados[destino];

    ultimo--;
    pos = destino;

    while (pos <= ultimo) {
      dados[pos] = dados[pos + 1];
      pos++;
    }

    return dado;
  }

  T retiraEspecifico(T dado) {
    excecaoListaVazia();
    return retiraDaPosicao(posicao(dado));
  }

  void excecaoListaVazia() {
    if (listaVazia()) {
      throw("Lista Vazia!");
    }
  }

  void excecaoListaCheia() {
    if (listaVazia()) {
      throw("Lista Vazia!");
    }
  }
};

