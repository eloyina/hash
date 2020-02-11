#include<iostream>

using namespace std;

template<class t>

class nodo
{
	public:
		t dato;
		nodo<t>* psig;
		nodo(){};
		nodo(t d)
		{
			dato=d;	
			psig=0;
		}
};

template<class t>

class lista
{
	private:
		nodo<t>* phead;
		nodo<t>* plast;
	public:
		lista()
		{
			phead=plast=0;
		}
		
		void add2(t d)		
		{
			nodo<t> **p;
			if(find(d,p)) return;
			nodo<t>* nuevo=new nodo<t>(d);
			nuevo->psig=*p;
			*p=nuevo;
		}
		
		bool find(t d, nodo<t> ** & p)
		{
			p=&phead;
			while(*p)
			{
				if((*p)->dato == d) return 1;
				if((*p)->dato > d) return 0;
				p= &((*p)->psig);
			}
			return 0;
		}
		void printl()
		{
			nodo<t>* temp=phead;
			while(temp)
			{
				cout<<"dato: "<<temp->dato<<endl;
				temp=temp->psig;
			}
		}


		void remove(t d)
		{
			nodo<t>* p=phead;
			nodo<t>* q=0;
			if(phead->dato==d)	
			{	
				phead=phead->psig;
				delete p;
				return;
			}
			while(p)
			{
				q=p->psig;
				if(q->dato==d)
				{
					p->psig=q->psig;
					delete q;
					return;
				}
			}
		}
		
};

int main() 
{
	lista<int> A;
	A.add2(6);
	A.add2(7);
	A.add2(3);
	A.add2(8);
	A.add2(14);
	//A.find(4);
	//A.cargar("spanish.txt");
	//registro r("car","");
	//nodo<registro> * q;
	//if (A.find(r , q) )
	//cout<<q->dato;
	    
	A.printl();
	cout<<endl;
	A.remove(6);
	A.printl();
	return 0;
}


