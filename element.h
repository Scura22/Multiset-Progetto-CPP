#ifndef ELEMENT_H
#define ELEMENT_H
/*@file element.h*/
#include <algorithm>
/**@brief Classe che implementa il tipo element, composto dall'elemento di tipo
t e dal numero di occorrenze di quell'elemento
**/
template<typename T>
class element{
  public:
  typedef unsigned int size_type;///< tipo che rappresenta il numero di occorrenze di un elemento

  private:
  T _elemento; ///< elemento
  size_type _occorrenze; ///< numero di occorrenze dell'elemento

  public:

  /**Costruttore di default
  **/
  element() : _occorrenze(0){

  }

  /**Costuttore che crea un elemento con il relativo numero di occorrenze
  @param e elemento
  @param no numero di occorrenze dell'elemento
  **/
  element(const T &e, size_type no) : _elemento(e), _occorrenze(no){

  }

  /**Costruttore che crea un elemento con una sola occorrenza
  @param e elemento
  **/
  explicit element(const T &e) : _elemento(e), _occorrenze(1){

  }

  /**Distruttore
  **/
  ~element() {

	}

  /**Copy constuctor => copia un elemento e il suo numero di occorrenze
    @param toCopy elemento da copiare
  **/
  explicit element(const element &toCopy) : _elemento(toCopy._elemento), _occorrenze(toCopy.occorrenze){

  }

  /**Operatore di assegnamento
  @param toAssign elemento da assegnare
  @return *this
  **/
  element&operator=(const element &toAssign){
    if (this!=&toAssign){
      element tmp(toAssign);
      std::swap(_elemento, tmp._elemento);
      std::swap(_occorrenze, tmp._occorrenze);
    }
    return *this;
  }

  /**Metodo getter dell'elemento
    @return elemento
  **/
  T &elemento(){
    return _elemento;
  }

  /**Metodo getter costante dell'Elemento
  @return elemento costante
  **/
  const T &elemento() const{
    return _elemento;
  }

  /**Metodo getter delle occorrenze dell'elemento
  @return numero occorrenze
  **/
  size_type occorrenze() const{
    return _occorrenze;
  }

  /**Metodo setter delle occorrenze
  @param nuovo numero di occorrenze dell'elemento
  **/
  void setOccorrenze(size_type newValue){
    _occorrenze = newValue;
  }
};//fine classe elemento
#endif
