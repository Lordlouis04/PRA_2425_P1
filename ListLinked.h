#include <ostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>
using namespace std;
template <typename T>
class ListLinked : public List<T> {

private:
	Node<T>* first;
	int n;
public:
	ListLinked(){
	   this->first = nullptr;
           this->n = 0;
	}

	~ListLinked(){
	   while(first!=nullptr){
	   	Node<T>* aux = first->next;
                delete first;
		first=aux;
	   }
	}

	T operator[](int pos){
	    if(pos < 0 || pos > n-1){   
	        throw std::out_of_range("posicion inexistente");
	    }
	    else{
	        Node<T>* aux = first;
	        for(int i = 0;i<pos;i++){
		   aux = aux->next;
		}	
		return aux->data;
		}
	}
	friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
	    Node<T>* aux = list.first;
            
            out<<"List => [";
            for(int i=0;i<list.n;i++){
                out<<aux->data<<", ";
		aux = aux->next;
            }
	    out<<"]"<<endl;
	    return out;
	}

	void insert(int pos, T e) override {
	    if(pos < 0 || pos > n ){
		throw std::out_of_range("posicion inexistente");
	    }
	    else if(pos == 0){
		first = new Node(e,first);
		n++;
	    }
	    else{
		Node<T>* aux = first;
		Node<T>* aux2;
		for(int i=0;i<pos-1;i++){
		  aux=aux->next;
		}
		aux2=aux->next;
		aux->next = new Node(e,aux2);
	        n++;
	    }
	}

	void append(T e) override{
	    insert(n,e);
	}
	void prepend(T e) override{
	    insert(0,e);
	}
	T remove(int pos) override{
	    T value;
   	    if(pos < 0 || pos > n-1 ){
	        throw std::out_of_range("posicion inexistente");
	    }
	    else if(pos == 0){
		T value = first->data;
		Node<T>* aux = first->next;
	        delete first;
	        first = aux;
	    }
	    else{
		T value;
	        Node<T>* aux = first;
	        Node<T>* aux2;
	        for(int i=0;i<pos;i++){
		    aux=aux->next;
		}
	        aux2=aux->next;
		aux->next=aux2->next;
		value=aux2->data;
		delete aux2;
	    }
	        n--;
		return value;
	 }

	T get(int pos) override{
	    return (*this)[pos];
	}

        int search(T e) override{
            int pos = -1;
            for(int i=0;i<n;i++){
                 if((*this)[i]==e){
                     pos = i;
                     break;
                 }
             }
             return pos;
         }

         bool empty() override{
             return n>0;
          }

          int size() override{
             return n;
          }
};
