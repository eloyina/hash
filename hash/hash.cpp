#include <iostream>
#include "lista.h"
#include <string>
#include <fstream>
using namespace std;



template <class R, class K,int (*pfd)(void *,int),int tam=11>
class hash
{
   private:
   
      Lista< R > *tabla;
   public:
   hash()
    {
      tabla=new Lista<R> [tam];
    }
   void add(R dato,K key)
   {
      tabla[pfd(key,tam)].Add(dato);
   }
  
   void add(R dato,K key)
   {
      tabla[pfd(key,tam)].remove(dato);
   } 
   bool find(K key,CNodo<R> *&p)
   {
      return tabla[pfd(key,tam)].Find(R(key),p);
   }
   void print()
   {
      for( int i=0;i<tam;i++)
      if  (tabla[i].size>0) cout<<"posicion :"<<i<<" Elementos : "<<tabla[i].size<<endl;
      

   }
   void indexar(char* lee, char* escribe)
   {  
	   ifstream lec(lee);
   	ofstream esc(escribe);
	   char buffer[200];
   	long pos =0;
   	char pal[100];
   	while(!lec.eof())
	   {
         lec>>pal;
  	   	pos = strlen(pal)+pos;
         add(registro(pal,pos),pal);
  	   	lec.getline(buffer,200);
  	   	esc<<pal<<" "<<pos<<endl;
         pos+= strlen(buffer) +1;
	   }
	   lec.close();
   	esc.close();
   }
   
};

int fc(void * pchar, int tam)
{
     char * p = (char*)pchar;
     
     int s =0;
     while(*p)
     {
        s+=*p;
        p++;
     }
     //int t = strlen(p)/2;otra funcion de dispersion
      //return (p[t]*p[t+1])%tam;
     return s%tam;
}


int main()
{
    hash<registro,char * , fc ,7478> A;
    A.indexar("diccionario.txt","index.txt");
    A.print();
/*      CNodo<registro> *p;
      char pal[10],info[500];cout<<"ingrese clave"<<endl;
      cin>>pal;
     if(A.find(pal,p)==true)
     {
      
      cout<<"encontrado"<<endl;
       long pos = p->Dato.pos;
              ifstream Ar("diccionario.txt");
              Ar.seekg(pos,ios::beg);
              Ar.getline(info,500);
              cout<<"traduccion ..."<<info<<endl;
      
     }
     else
     cout<<"no hay!!!!!!!!"<<endl; */
    return 1;

    
 
}
