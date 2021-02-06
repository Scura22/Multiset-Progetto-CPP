#ifndef MULTISET_H
#define MULTISET_H
/*@file multiset.h*/
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <stddef.h>
#include <iostream>
#include "element.h"
/*@file multiset.h*/
/**@brief Classe che implementa un'eccezione personalizzata per il multiset
**/

class element_not_found : public std::runtime_error{
public:
/**Costruttore che prende come parametro un messaggio
@param msg Messaggio dell'errore
**/
explicit element_not_found(const char *msg) : std::runtime_error(msg){}

};

/**@brief Classe che implementa un multiset. I dati sono coppie
<elemento, numero_occorrenze>. La classe memorizza tali coppie tramite
una lista. La classe richiede la specifica del tipo dell'elemento T e
del funtore funct per la comparazione di due elementi
**/
template <typename T, typename funct>
class Multiset{
  typedef unsigned int size_type;
  /**Struct contenente il nodo elementare della lista di elementi.
  **/
  struct nodo{
    element<T> data;///< dato di tipo T
    nodo *next; ///< puntatore al prossimo elemento della lista

    /**Costruttore del nodo, dato un elemento di tipo T
    @param e elemento di tipo T
    **/
    explicit nodo(const T &e) : data(e),next(nullptr){

    }

    /**Costruttore del nodo, dato un elemento di tipo T e il numero di occorrenze
    @param e elemento di tipo T
    @param no numero di occorrenze dell'elemento e
    **/
    nodo(const T &e, size_type no) : data(e, no), next(nullptr) {

    }

    /**Costruttore del nodo dato un elemento di tipo T
    e il riferimento al nodo successivo
    @param e elemento di tipo T
    @param n puntatore al nodo successivo
    **/
    nodo(const T &e, nodo *n) : data(e), next(n){

    }


    /**Costruttore del nodo dato un elemento di tipo T, il numero di occorrenze
    e il riferimento al nodo successivo
    @param e elemento di tipo T
    @param no numero di occorrenze dell'elemento e
    @param n puntatore al nodo successivo
    **/
    nodo(const T &e, size_type no, nodo *n) : data(e, no), next(n){

    }

    /**Costruttore di default
    **/
    nodo() : next(nullptr){

    }

    /**Distruttore
    **/
    ~nodo() {

    }

    /**Copy constructor => costruttore che copia un nodo in un altro nodo
    @param toCopy nodo da copiare
    **/
    explicit nodo(const nodo &toCopy) : data(toCopy.data), next(toCopy.next){

    }

    /** Operatode di assegnamento
    Assegna a un nodo l'elemento di un altro nodo e il corrispettivo nodo
    successivo
    @param toAssign nodo da assegnare
    **/
    nodo&operator=(const nodo &toAssign){
      if (this != &toAssign) {
        data = toAssign.data;
        next = toAssign.next;
      }
      return *this;
    }

  }; //fine definizione della Struct nodo

    nodo *_head; ///< testa del multiset
    int _dimensione; ///< numero di nodi contenuti nel multiset
    int _numeroelementi; ///< numero totale di elementi contenuti nel multiset

    /**Metodo che ritorna il puntatore all'elemento che viene passato come
    argomento, se esiste, altrimenti viene restituito nullptr
    @param e elemento da cercare
    @return il puntatore al nodo se l'elemento esiste, nullptr altrimenti
    **/
    nodo *find(const T &e) const{
      nodo *corrente = _head;
      funct comp;

      while(corrente!=nullptr){
        if(comp(corrente->data.elemento(), e))
          return corrente;
        corrente = corrente->next;
      }
      return nullptr;
    }

    /**Metodo che ritorna il puntatore al nodo precedente rispetto a quello
    che viene passato come argomento
    @param curr elemento corrente del quale cercare il precedente
    @return il puntatore al nodo precedente se l'elemento esiste, nullptr altrimenti
    **/
    nodo *find_previous(const nodo *curr) const {
      nodo *corrente = _head;
      nodo *next = curr->next;

      while(curr != next){
        corrente = next;
        next = corrente->next;
      }

      return corrente;
    }

  public:
    /**Metodo che ritorna il numero di occorrenze dell'elemento passato come
    argomento
    @param e elemento del quale si desidera sapere il numero di occorrenze
    @return il numero di occorrenze dell'elemento e se è presente nel multiset,
    0 altrimenti
    **/
    int count(const T &e) const{

      nodo *nodoelemento;

      nodoelemento = find(e);

      if (nodoelemento == nullptr)
        return 0;
      else
        return nodoelemento->data.occorrenze();

    }

    /**Costruttore di defalut
    **/
  Multiset() : _head(nullptr), _dimensione(0), _numeroelementi(0) {

  }

  /**Distruttore
  **/
  ~Multiset() {
    clear();
  }

  /** Metodo utilizzato per svuotare il multiset
  **/
  void clear(){
    nodo *tmp = nullptr;

    while (_head!=nullptr){
      tmp = _head->next;
      delete _head;
      _head = tmp;
    }

    _numeroelementi = 0;
    _dimensione = 0;
  }

  /**Copy constructor => costruttore che copia multiset in un altro multiset
  @param toCopy multiset da copiare
  **/
  Multiset(const Multiset &toCopy) : _head(nullptr), _dimensione(0), _numeroelementi(0){
    nodo *tmp = toCopy._head;

    try {
      while(tmp!=nullptr){
        add(tmp->data.elemento(), tmp->data.occorrenze());
        tmp = tmp->next;
      }
    }
    catch(...){
      clear();
      throw;
    }
  }

  /**Costruttore che parte da una sequenza di dati generici Q e crea un multiset
  di dati generici T
  @param begin iterator che punta all'inizio della sequenza
  @param end iterator che punta alla fine della sequenza
  **/
  template<typename IteratorT> Multiset(IteratorT begin, IteratorT end) : _head(nullptr), _dimensione(0), _numeroelementi(0) {
    try {
     while(begin != end) {
      add(static_cast<T>(*begin));
      begin++;
     }
    } catch(...) {
     clear();
     throw;
    }
   }

  /** Operatore di assegnamento
  @param toAssign il multiset da assegnare
  @return *this
  **/
  Multiset& operator=(const Multiset &toAssign){
    if (this!=&toAssign){
      Multiset tmp(toAssign);
      std::swap(this->_head,tmp._head);
      std::swap(this->_dimensione, tmp._dimensione);
      std::swap(this->_numeroelementi, tmp._numeroelementi);
    }
    return *this;
  }

  /**Operatore di confronto.
  @param toCheck il multiset da confrontare
  @return true se i due multiset contengono gli stessi elementi con lo stesso
  numero di occorrenze, false altrimenti
  **/
  bool operator==(const Multiset &toCheck) const{
    if(_dimensione != toCheck._dimensione)
      return false;

    nodo *corrente = _head;
    while(corrente!=nullptr){
      if(corrente->data.occorrenze() != toCheck.count(corrente->data.elemento()))
        return false;
      corrente = corrente->next;
    }

    return true;
  }

  /**Metodo che inserisce nel multiset un nuovo elemento base un determinato
  numero di volte
  @param e elemento da inserire
  @param no numero di occorrenze
  **/
  void add(const T &e, size_type no){
    if(!contains(e)){
      if(_head == nullptr)
        _head = new nodo(e,no);
      else
      {
        nodo *tmp = _head;
        _head = new nodo(e,no);
        _head->next = tmp;
      }
      _dimensione++;
      _numeroelementi += no;
    }
    else{
      nodo *tmp = find(e);
      tmp->data.setOccorrenze(tmp->data.occorrenze() + no);
      _numeroelementi += no;
    }
  }
  /**Metodo che inserisce nel multiset un nuovo elemento base una sola volta
  @param e elemento da inserire
  **/
  void add(const T &e){
    try{
      add(e,1);
    }
    catch(...){
      throw;
    }
  }

  /**Metodo che rimuove dal multiset un'occorrenza dell'elemento passato come
  parametro
  @param e elemento da rimuovere
  **/
  void remove(const T &e){
    if(contains(e)){
      nodo *tmp = find(e);
      if(tmp->data.occorrenze() > 1)
        tmp->data.setOccorrenze(tmp->data.occorrenze()-1);
      else{
        if (_head == tmp){
          _head = tmp->next;
          delete tmp;
        }
        else{
          nodo *prec = find_previous(tmp);
          prec->next = tmp->next;
          delete tmp;
        }
        _dimensione--;
      }

      _numeroelementi--;
    }
    else
      throw element_not_found("Element not found");
  }

  /**Metodo che rimuove dal multiset un determinato numero di occorrenze
  di un elemento
  @param e elemento da rimuovere
  @param no numero di occorrenze da rimuovere
  **/
  void remove(const T &e, size_type no){
    for (int i=0; i<no; i++)
      remove(e);
  }

  /**Metodo che valuta l'esistenza dell'elemento nella lista
  @param e l'elemento da cercare
  @return true se l'elemento esiste, false altrimenti
  **/
  bool contains(const T &e) const{
    nodo *tmp = find(e);
    return (tmp != nullptr);
  }

  /**Metodo che ritorna il numero di elementi totali del multiset
  @return il numero di elementi totali del multiset
  **/
  int getNumeroElementi() const{
    return _numeroelementi;
  }

  /**Metodo che ritorna la dimensione del multiset
  @return la dimensione del multiset
  **/
  int getSize() const{
    return _dimensione;
  }

  /**@brief Classe che implementa un forward iterator di sola lettura
  **/
  class const_iterator{
    public:
      typedef std::forward_iterator_tag catIteratore;
      typedef T value_type;
      typedef ptrdiff_t difference_type;
      typedef T* ptr;
      typedef T& ref;

      /**Costruttore di default
      **/
      const_iterator(){
        n = nullptr;
        no = 0;
      }

      /**Copy constructor => costruttore che copia un iteratore in un altro
      iteratore
      @param toCopy iteratore da copiare
      **/
      const_iterator(const const_iterator &toCopy){
        n = toCopy.n;
        no = toCopy.no;
      }

      /**Operatore di assegnamento
      @param toAssign iteratore da assegnare
      @return *this
      **/
      const_iterator& operator=(const const_iterator &toAssign){
        n = toAssign.n;
        no = toAssign.no;
        return *this;
      }

      /** Distruttore
      **/
      ~const_iterator() {

      }

      /**Dereferenziamento dell'oggetto T per reference
      @return riferimento costante all'elemento
      **/
      const T&operator*()const{
        return (n->data.elemento());
      }

      /**Dereferenziamento dell'oggetto T per puntatore
      @return puntatore costante all'elemento
      **/
      const T*operator->()const{
        return &(n->data.elemento());
      }

      /**Operatore di pre incremento
      @return iteratore alla coppia <elemento, numero occorrenze> successiva
      **/
      const_iterator& operator++(){
        if (no > 1){
          no--;
          return *this;
        }
        else{
          n = n->next;
          if (n!=nullptr){
            no=n->data.occorrenze();
          }
          else{
            no = 0;
          }
          return *this;
        }
      }


      /**Operatore di post incremento
      @return l'iteratore alla coppia <elemento, numero occorrenze> precedente
      **/
      const_iterator operator++(int){
        const_iterator tmp(*this);
        if (no > 1){
          no--;
          return tmp;
        }
        else{
          n = n->next;
          if (n!=nullptr){
            no=n->data.occorrenze();
          }
          else{
            no = 0;
          }
          return tmp;
        }
      }

      /**Operatore di confronto per uguaglianza
      @param toCheck iteratore da confrontare
      @return true se i due iteratori puntano alla stessa posizione, false altrimenti
      **/
      bool operator==(const const_iterator &toCheck) const{
        return (n==toCheck.n && no==toCheck.no);
      }

      /**Operatore di confronto per disuguaglianza
      @param toCheck iteratore da confrontare
      @return true se i due iteratori puntano a posizioni diverse, false altrimenti
      **/
      bool operator!=(const const_iterator &toCheck) const{
        return (n!=toCheck.n || no!=toCheck.no);
      }

    private:
      const nodo *n;///< puntatore al nodo corrente del multiset;
      size_type no;///< numero occorrenze elemento e relativo al nodo n
      friend class Multiset;

      /**Costruttore secondario di inizializzazione
      @param pn puntatore ad un nodo della lista del multiset
      **/
      const_iterator(const nodo *pn) : n(pn){
        if (pn!=nullptr)
        {
          no = pn->data.occorrenze();
        }
        else{
          no = 0;
        }
      }

  }; //fine classe const_iterator

  /**Iteratore di inizio sequenza
  @return iteratore al primo elemento della sequenza
  **/
  const_iterator begin() const{
    return const_iterator(_head);
  }

  /**Iteratore di fine sequenza
  @return iteratore all'ultimo elemento della sequenza
  **/
  const_iterator end() const{
    return const_iterator(nullptr);
  }
};//fine classe multiset

  /**Operatore di stream output per la stampa del multiset nella forma <elemento, numero occorrenze>
    @param os stream di output
    @param m multiset da stampare
    @return stream di output
  **/
  template <typename T, typename F>
  std::ostream&operator<<(std::ostream &os, const Multiset<T,F> &m){

    typename Multiset<T, F>::const_iterator ibegin = m.begin(), iend = m.end();
    	os << '{';
    	while(ibegin != iend) {
    		T tmp = *ibegin;
    		int no = 1;
    		ibegin++;
    		while(ibegin != iend && *ibegin == tmp) {
    			no++;
    			ibegin++;
    		}
    		os << '<' << tmp << ", " << no << '>';
    		if(ibegin != iend)
    			os << ',';
    	}
    	os << '}';

    return os;
  }
#endif
