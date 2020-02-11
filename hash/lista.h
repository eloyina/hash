#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class CNodo
{
   public:
    T Dato;
    CNodo *psig;
   

   CNodo(T d)
   {
   Dato=d;
   psig=NULL;
   }     
  

};
  
//template<class T>
class registro
{
   public:
   
   
   string key;
   long pos;
   registro(){}
   registro(string a){key=a;}
   
   registro(string k, long p)
   {
   key=k;
   pos=p;

   }
   bool operator ==(registro &a)
   {
   if(key==a.key)   return true;
   return false;
   }
   friend ostream & operator << (ostream  & os , registro & r)
   {
         os<<r.key<<endl;
         os<<"Traduccion "<< r.pos<<" "<<endl;
         return os;
   }
        
};

 
 template <class T>
 class Lista
 {
   public:
   CNodo<T> *phead;
   CNodo<T> *plast;
   int size;
   
  Lista()
  {
  size=0;
  phead=NULL;
  plast=NULL;
  }
  bool Find(T d,CNodo<T> *&p)
  {
  p = phead;
  while (p)
   {
      if(d == p->Dato)     return true; //iperativa
      p=p->psig;
   }
  return false;      
  
  }

   bool Find2(T d,CNodo<T> *&p)
  {
  p = phead;
  if(!p) return false;
  if(p->Dato==d)return true;
  Find2(d,p->psig);
  }
  void Add(T d)
  {
  
  CNodo<T> *nuevo= new CNodo<T>(d);
   if(phead==NULL)
      phead=plast=nuevo;
   else  
   {
      plast->psig=nuevo;
      plast=nuevo;
   }
   size++;
  } 
  void Add2(T d,CNodo<T> *&p)
  {
   if(!p){p=new CNodo<T>(d);
         return;}
   Add2(d,p->psig);
  } 
/*  void cargar(char* nombre)
  {

      ifstream lec(nombre);
      char buffer[200];
      char pal[200];
      while(!lec.eof())
      {
         lec>>pal;
         lec.getline(buffer,200);
         registro a (pal,buffer);
         Add(a);
      }
      
  }   */
  void Imprimir()
  {
  CNodo<T> *p= phead;
  while (p)
   {
     cout<< p->Dato<<endl;
     p=p->psig;
   }
  }
/*  void Imprimir2( CNodo<T> *&p=phead)
  {

   if (!p) {return;}
   if (p) {cout<< p->Dato;}
   Imprimir2(p->psig);
  }
  */
  /*void Delete(T d)
  {
  if(
  } */
 
  /* void tam()
   {
   CNodo<T> *aux=phead;
   double total=0;
   while(aux)
   {
      total=total+ sizeof(aux->Dato);
      aux=aux->psig;
   }
      cout<<total<<" bite"<<endl;total=total/1024;
      cout<<total<<" kb"<<endl;total=total/1024;
      cout<<total<<" mb"<<endl;
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
      Add(registro(pal,pos));
  		lec.getline(buffer,200);
      pos+= strlen(buffer) +1;
	}
	
	lec.close();
	esc.close();
}
*/


		bool remove(T d)
		{
			CNodo<T>* p=phead;
			CNodo<T>* q=0;
			if(phead->Dato==d)	
			{	
				phead=phead->psig;
				delete p;
				return true;
			}
			while(p)
			{
				q=p->psig;
				if(q->Dato==d)
				{
					p->psig=q->psig;
					delete q;
					return true;
				}
			}
			return false;
		}

};



