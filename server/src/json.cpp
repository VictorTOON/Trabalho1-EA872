

#include <iostream>

#include <vector>

#include "json.hpp"
using nlohmann::json;

// Solucao naive: nao faca isso!!!!
class MinhaClasse : public json  {
  public:
    int get_value() { return (*this)["i"]; };
    void set_value(int i) { (*this)["i"] = i; };
};

// Veja como definimos uma macro...
class OutraClasse {
  private:
    int i;

  public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(OutraClasse, i);
    int get_value() { return i; };
    void set_value(int i0) { i=i0; };
};

// A estrutura de arvore das suas classes vai aparecer
// no arquivo JSON...
class Conteiner {
  private:
    OutraClasse c;
  public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Conteiner, c);
    int get_value() { return c.get_value(); };
    void set_value(int i0) { c.set_value(i0); };
};
