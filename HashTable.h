#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1./ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

using namespace std;


template <typename V>
class HashTable: public Dict<V> {

    private:
	int h(std:: string key){
		int sum=0;

		for(int i =0;i<key.length();i++){
		char letra= key.at(i);
		sum +=int(letra);
	}
	return sum % max;
	}
	int n;
	int max;
	 ListLinked<TableEntry<V>>*table;	
        // ...

    public:
	HashTable(int size){
		table= new ListLinked<TableEntry<V>>[size];
		n=0;
                max=size;

	
	}
	~HashTable(){
		for(int i =0; i < max; i ++)
			table[i]. ~ListLinked();


		delete[] table;
	}
	int capacity(){
		return max;
	}
	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		 out << "HashTable[Entries: " << th.n << ",Capacity: " << th.max << "]\n" << "\n";
		 for(int i=0; i <th.max;i ++){

			 out <<"Cubeta ; "  << "\n";
			 out << th.table[i]<< std::endl;

		 }
		 
		 return out;
	}
	V operator[](std::string key){
		

		int posEntry = table[h(key)].search(key);

		if(posEntry < 0 ){
			throw std::runtime_error("no existe la clave");
		}else{
		V aux = table[h(key)].get(posEntry).value;
		return aux;
			
		}

	
	
	}
	void insert(std::string key, V value)override{
		int posEntry =table[ h(key)].search(key);
		

		if(posEntry >=0 ){
			throw std:: runtime_error("la clave ya existe");
		}
		else{
			TableEntry<V> aux(key,value);
			table[h(key)].prepend(aux);
			n++;
		}	
		
	
		//hay que comprobar que no exista ya el key
	}
	 V search(std::string key)override{
		 int pos = h(key);
		 int posEntry = table[pos].search(key);

       	      if(posEntry < 0){
                      
			throw std:: runtime_error("la clave ya existe");

                }
                
		 V aux = table[pos].get(posEntry).value;
		 return aux;
		// int pos = able[h(key)].search(key);
	}
	 V remove(std::string key)override{
		 int posEntry =table[ h(key)].search(key);

              if(posEntry > max || posEntry  < 0 )
			throw std:: runtime_error("la clave ya existe");
		V aux= table[h(key)].remove(posEntry).value;

		n --;
		return aux;
                        
               

	 }
	int entries()override{
		return n;
	}
        // ...
        
};

#endif
