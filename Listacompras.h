#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H

#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct Nodo{
	string dato;
	Nodo *siguiente;
};

class ListaCompras{
	public:
		int a;
		ListaCompras(int);
		void eliminarNodo(Nodo *&,string);
		void mostrarLista(Nodo *);
		void eliminarLista(Nodo *&,string&);
		void insertarLista(Nodo *&,string);
		void buscarProducto(ifstream &);
};

ListaCompras::ListaCompras(int _a){
	a=_a;
}

Nodo *lista = NULL;

void ListaCompras::insertarLista(Nodo *&lista,string n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) ){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void ListaCompras::mostrarLista(Nodo *lista){
	system("CLS");
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<" ";
		actual = actual->siguiente;
	}
}

void ListaCompras::eliminarNodo(Nodo *&lista,string n){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		while((aux_borrar != NULL) && (aux_borrar->dato !=n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void ListaCompras::eliminarLista(Nodo *&lista,string &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}

int a;
ListaCompras L1(a);

void ListaCompras::	buscarProducto(ifstream &Lec){
	system("cls");	
	Lec.open("Productos.txt", ios::in);
	string nombre,dato;
	
	cout<<"Indtroduce el nombre del producto que deseas elegir"<<endl;
	cin>>dato;
	
	bool encontrado = false;
	
	while(!Lec.eof() && !encontrado){
		if(nombre == dato){
			L1.insertarLista(lista,dato);
			encontrado = true;
		}
		Lec>>nombre;
	}
	Lec.close();
	
	if(!encontrado){
		cout<<"Dato no encontrado"<<endl;
	}
}

#endif
