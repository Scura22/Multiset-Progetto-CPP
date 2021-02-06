#include <iostream>
#include "multiset.h"
/*@file main.cpp*/
/**@brief Funtore per confronto tra interi
@param a primo elemento da confrontare
@param b secondo elemento da confrontare
@return true se il primo elemento è uguale al secondo, false altrimenti
**/
struct compare_int{
	bool operator()(int a, int b) const{
		return a==b;
	}
};

/**@brief Funtore per confronto tra stringhe
@param a primo elemento da confrontare
@param b secondo elemento da confrontare
@return true se il primo elemento è uguale al secondo, false altrimenti
**/
struct compare_string{
	bool operator()(const std::string &a, const std::string &b) const {
		return upper(a)==upper(b);
	}

private:
	/**Metodo per convertire le stringhe in stringhe con tutti i caratteri maiuscoli
	**/
	std::string upper(const std::string &s) const{
		std::string upperS(s);
		for (int i=0; i<upperS.size(); i++)
			upperS[i] = std::toupper(upperS[i]);

		return upperS;
	}
};
/**Metodo che effettua un primo set di test
**/
void primoTest(){
	std::cout<<"############## Primo Test ##############"<<std::endl;

	  typename Multiset<int,compare_int>::const_iterator ibegin,iend;

	  std::cout<<"###### Test Costruttore di Default #####"<<std::endl;

	  Multiset<int, compare_int> primoMs;
	  std::cout<<"primoMs "<<primoMs<<std::endl;
	  std::cout<<"Numero Elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	  std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test metodo add #####"<<std::endl;

	  primoMs.add(5);
	  std::cout<<"Add 5: "<<primoMs<<std::endl;
	  for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
	    std::cout<<*ibegin<<" ";
	  std::cout<<std::endl;

		std::cout<<"#########"<<std::endl;

	  primoMs.add(5);
	  std::cout<<"Add secondo 5: "<<primoMs<<std::endl;
	  for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
	    std::cout<<*ibegin<<" ";
	  std::cout<<std::endl;

	  std::cout<<"#########"<<std::endl;

	  primoMs.add(3,5);
	  std::cout<<"Add 5 occorrenze di 3: "<<primoMs<<std::endl;
	  for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
	    std::cout<<*ibegin<<" ";
	  std::cout<<std::endl;

		std::cout<<"#########"<<std::endl;

	  std::cout<<"Numero di elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	  std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test metodo remove #####"<<std::endl;

	  primoMs.remove(3,5);
	  std::cout<<"Remove 5 occorrenze di 3: "<<primoMs<<std::endl;
	  for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
	    std::cout<<*ibegin<<" ";
	  std::cout<<std::endl;
    std::cout<<"Numero di elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	  std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test assegnamento #####"<<std::endl;

	  primoMs.add(2,6);
	  std::cout<<"Aggiungo 6 occorrenze di 2: "<<primoMs<<std::endl;
		for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
			std::cout<<*ibegin<<" ";
		std::cout<<std::endl;

	 	std::cout<<"#########"<<std::endl;

	  Multiset<int, compare_int> secondoMs = primoMs;

	  std::cout<<"Assegnamento secondoMs = primoMs"<<std::endl;
	  std::cout<<"primoMs: "<<primoMs<<std::endl;
		std::cout<<"Numero di elementi primoMs: "<<primoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione primoMs: "<<primoMs.getSize()<<std::endl<<std::endl;
	  std::cout<<"secondoMs: "<<secondoMs<<std::endl<<std::endl;
		std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test costruttore copia #####"<<std::endl;

	  Multiset<int, compare_int> terzoMs(secondoMs);

	  std::cout<<"Costruttore copia tersoMs(secondoMs)"<<std::endl;
	  std::cout<<"secondoMs: "<<secondoMs<<std::endl;
		std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;
	  std::cout<<"terzoMs: "<<terzoMs<<std::endl<<std::endl;
		std::cout<<"Numero di elementi terzoMs: "<<terzoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione terzoMs: "<<terzoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test operatore di confronto #####"<<std::endl;

	  std::cout<<"primoMs: "<<primoMs<<std::endl;
	  std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	  std::cout<<"Sono uguali?: "<<(primoMs==terzoMs)<<std::endl<<std::endl;

	  terzoMs.remove(2,4);
	  std::cout<<"Remove 4 occorrenze di 2 da terzoMs"<<std::endl;
	  std::cout<<"primoMs: "<<primoMs<<std::endl;
	  std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	  std::cout<<"Sono uguali?: "<<(primoMs==terzoMs)<<std::endl<<std::endl;

	  std::cout<<"##### Test metodo clear() #####"<<std::endl;

	  std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	  terzoMs.clear();
	  std::cout<<"Clear terzoMs: "<<terzoMs<<std::endl<<std::endl;
		std::cout<<"Numero di elementi terzoMs: "<<terzoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione terzoMs: "<<terzoMs.getSize()<<std::endl<<std::endl;

	  std::cout<<"##### Test metodo contains() #####"<<std::endl;

	  std::cout<<"secondoMs: "<<secondoMs<<std::endl;
	  std::cout<<"Contiene il valore 2?: "<<secondoMs.contains(2)<<std::endl;
	  std::cout<<"Contiene il valore 1?: "<<secondoMs.contains(1)<<std::endl<<std::endl;

		std::cout<<"##### Test costruttore secondario #####"<<std::endl;
		std::cout<<"secondoMs: "<<secondoMs<<std::endl;
		Multiset<int, compare_int> quartoMs(secondoMs.begin(), secondoMs.end());
		std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;
		std::cout<<"quartoMs: "<<quartoMs<<std::endl;
		std::cout<<"Numero di elementi quartoMs: "<<quartoMs.getNumeroElementi()<<std::endl;
		std::cout<<"Dimensione quartoMs: "<<quartoMs.getSize()<<std::endl<<std::endl;
}
/**Metodo che effettua un secondo set di test
**/
void secondoTest(){
	std::cout<<"############## Secondo Test ##############"<<std::endl;
	typename Multiset<std::string,compare_string>::const_iterator ibegin,iend;

	std::cout<<"###### Test Costruttore di Default #####"<<std::endl;

	Multiset<std::string, compare_string> primoMs;
	std::cout<<"primoMs "<<primoMs<<std::endl;
	std::cout<<"Numero Elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test metodo add #####"<<std::endl;

	primoMs.add("Mario");
	std::cout<<"Add 'Mario': "<<primoMs<<std::endl;
	for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<" ";
	std::cout<<std::endl;

	std::cout<<"#########"<<std::endl;

	primoMs.add("Mario");
	std::cout<<"Add secondo 'Mario': "<<primoMs<<std::endl;
	for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<" ";
	std::cout<<std::endl;

	std::cout<<"#########"<<std::endl;

	primoMs.add("Luigi",5);
	std::cout<<"Add 5 occorrenze di 'Luigi': "<<primoMs<<std::endl;
	for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<" ";
	std::cout<<std::endl;

	std::cout<<"#########"<<std::endl;

	std::cout<<"Numero di elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test metodo remove #####"<<std::endl;

	primoMs.remove("Luigi", 5);
	std::cout<<"Remove 5 occorrenze di 'Luigi': "<<primoMs<<std::endl;
	for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<" ";
	std::cout<<std::endl;
	std::cout<<"Numero di elementi: "<<primoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione: "<<primoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test assegnamento #####"<<std::endl;

	primoMs.add("Toad",6);
	std::cout<<"Aggiungo 6 occorrenze di 'Toad': "<<primoMs<<std::endl;
	for(ibegin=primoMs.begin(), iend=primoMs.end();ibegin!=iend;++ibegin)
		std::cout<<*ibegin<<" ";
	std::cout<<std::endl;

	std::cout<<"#########"<<std::endl;

	Multiset<std::string, compare_string> secondoMs = primoMs;

	std::cout<<"Assegnamento secondoMs = primoMs"<<std::endl;
	std::cout<<"primoMs: "<<primoMs<<std::endl;
	std::cout<<"Numero di elementi primoMs: "<<primoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione primoMs: "<<primoMs.getSize()<<std::endl<<std::endl;
	std::cout<<"secondoMs: "<<secondoMs<<std::endl<<std::endl;
	std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test costruttore copia #####"<<std::endl;

	Multiset<std::string, compare_string> terzoMs(secondoMs);

	std::cout<<"Costruttore copia tersoMs(secondoMs)"<<std::endl;
	std::cout<<"secondoMs: "<<secondoMs<<std::endl;
	std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;
	std::cout<<"terzoMs: "<<terzoMs<<std::endl<<std::endl;
	std::cout<<"Numero di elementi terzoMs: "<<terzoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione terzoMs: "<<terzoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test operatore di confronto #####"<<std::endl;

	std::cout<<"primoMs: "<<primoMs<<std::endl;
	std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	std::cout<<"Sono uguali?: "<<(primoMs==terzoMs)<<std::endl<<std::endl;

	terzoMs.remove("Toad",4);
	std::cout<<"Remove 4 occorrenze di 'Toad' da terzoMs"<<std::endl;
	std::cout<<"primoMs: "<<primoMs<<std::endl;
	std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	std::cout<<"Sono uguali?: "<<(primoMs==terzoMs)<<std::endl<<std::endl;

	std::cout<<"##### Test metodo clear() #####"<<std::endl;

	std::cout<<"terzoMs: "<<terzoMs<<std::endl;
	terzoMs.clear();
	std::cout<<"Clear terzoMs: "<<terzoMs<<std::endl<<std::endl;
	std::cout<<"Numero di elementi terzoMs: "<<terzoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione terzoMs: "<<terzoMs.getSize()<<std::endl<<std::endl;

	std::cout<<"##### Test metodo contains() #####"<<std::endl;

	std::cout<<"secondoMs: "<<secondoMs<<std::endl;
	std::cout<<"Contiene il valore 'Toad'?: "<<secondoMs.contains("Toad")<<std::endl;
	std::cout<<"Contiene il valore 'Peach'?: "<<secondoMs.contains("Peach")<<std::endl<<std::endl;

	std::cout<<"##### Test costruttore secondario #####"<<std::endl;
	std::cout<<"secondoMs: "<<secondoMs<<std::endl;
	Multiset<std::string, compare_string> quartoMs(secondoMs.begin(), secondoMs.end());
	std::cout<<"Numero di elementi secondoMs: "<<secondoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione secondoMs: "<<secondoMs.getSize()<<std::endl<<std::endl;
	std::cout<<"quartoMs: "<<quartoMs<<std::endl;
	std::cout<<"Numero di elementi quartoMs: "<<quartoMs.getNumeroElementi()<<std::endl;
	std::cout<<"Dimensione quartoMs: "<<quartoMs.getSize()<<std::endl<<std::endl;

}


int main() {

	primoTest();
	secondoTest();

	return 0;
}
