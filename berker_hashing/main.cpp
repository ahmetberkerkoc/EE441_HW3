//Ahmet Berker KOÇ 2232320
#include <iostream> //  Standard Input / Output Streams Library.
#include <fstream>
#include <string>
#include <cstdlib>
#include<time.h>
using namespace std;  // instead of using std::
//In order to use Seperate Chaining I create a node class
class Node{

	public:
		long long int data;
		Node *next;

		Node(const long long int &item, Node* prtNext=NULL);
};
//constructor of node

Node::Node(const long long int&item,Node*ptrNext):data(item),next(ptrNext){
}


//Hash class
class Hash{
	private:
	 Node **hashtable; //to change the dimension according to input
	public:
		int collusion;
		int factor;
		Hash();
		void insert(int key,long long int value);
		void deleted(int key,long long int value);
		bool search(int key,long long int value);
		void print(int N);
		void create(int N);
};

	Hash::Hash(){ //constructor
	factor=0;
	collusion=0;
	}
	//create hash table and all initial data is null
	void Hash::create(int N){
		hashtable=new Node*[N];
		for(int i=0;i<N;i++){
			hashtable[i]=NULL;
		}
	}
	//insert method
	 void Hash::insert(int key,long long int value){

		Node* neww;

		neww=new Node(value,NULL);
		factor++;  //factor is increase to calculate lf
		if(hashtable[key]==NULL){ //if first element
			hashtable[key]=neww;

		}
		else { //if not first element, similar to insert after method
			neww->next=hashtable[key];
			hashtable[key]=neww;
			collusion++; //collusion calculation
		}

	}
	//search method
	bool Hash::search(int key,long long int value){

		if(hashtable[key]==NULL){
			return false; //if list is empty in that index
		}
		else{ //examine whole data in that index
		Node* ptr = hashtable[key];
		while(ptr!=NULL){
			if(ptr->data==value){
				return true; //if found return true
			}
			ptr=ptr->next;
			}
			return false; //if not return false
		}
	}
	void Hash::deleted(int key,long long int value){
		Node* ptr=hashtable[key];
		Node* temp;
		if(search(key,value)){ //firstly chech value is exist or not
		factor--; //decrease factor for lf
		if(hashtable[key]->next!=NULL) //check there is collusion
			collusion--; //decrease collusion
		if(hashtable[key]->data==value){ //delete if first element
			temp=hashtable[key];
			hashtable[key]=hashtable[key]->next;
			delete temp;
		}
		else{ //delete if not first
		Node* ptr = hashtable[key];
		while(ptr->next!=NULL){
			temp=ptr->next;
			if(temp->data==value){
				ptr->next=temp->next;
				delete temp;
			}
			ptr=ptr->next;
		}
	}
	}
	else {
		cout<<"ERROR deleted is impossible"<<endl; // if not exist value
	}
}
	void Hash::print(int N){ //print them with hash table line information
		int i;
		Node* current;
		for(i=0;i<N;i++){
			current=hashtable[i];
			while(current!=NULL){
				cout<<current->data<<" line "<<i<<endl;
				current=current->next;
			}
		}
	}

	int Folding(long long int value,int N){ //Folding process according to instruction
		long ten=100000000;
		int i;
		int key=0;
		for(i=0;i<3;i++){
			key+=value/ten;
			value=value%ten;
			ten=ten/1000;
		}
		key+=value;
		key=key%N;
		return key; //return key
	}

	int Middle_Squaring(long long int value,int N){//Middle Square process according to instruction
		int key;
		long square;
		key=value%10000000;
		key=key/10000;
		square=key*key;
		key=square%N;
		return key; //return key
	}

	int Truncation(long long int value,int N){//Truncation process according to instruction
	int key;
	key=value%1000000000;
	key=key%N;
	return key;//return key
	}
	void INIT_HASH_TABLE(Hash &table,int N,int function){ //inintialize hash table from txt file

    	fstream myfile("hash_table_init200.txt", ios_base::in);

    	long long int a;
    	while (myfile >> a)
    	{
    		if(function==1)
        		table.insert(Folding(a,N),a);
    		else if(function==2)
        		table.insert(Middle_Squaring(a,N),a);
			else if(function==3)
        		table.insert(Truncation(a,N),a);
    	}
	}


	int main(){
		int N,function,key,operation;
		long long int TC,d_TC,s_TC;
		Hash berker;
		while(1){ //infinity loop for take all opertation
			cout << "Choose the operation number from the menu"<<endl;  //MENU
			cout<<"1-Initialize Hash Table"<<endl;
			cout<<"2-Load T.C. ID Numbers from file"<<endl;
			cout<<"3-Add new T.C. ID Number"<<endl;
			cout<<"4-Delete a T.C. ID Number"<<endl;
			cout<<"5-Search for a T.C. ID Number"<<endl;
			cout<<"6-Print out Hash Table"<<endl;
			cin>>operation;
			if(operation==1){ //take size and funciton
				cout << "Please enter the size of Hash Table "<<endl;
				cin >> N;
				cout << "Please enter the hash function number  "<<endl<<"1 - Folding"<<endl<<"2 - Middle Square"<<endl<<"3 - Truncation"<<endl;
				cin >> function;
				berker.create(N);
			}
			else if(operation==2){ //initialize N with txt
				INIT_HASH_TABLE(berker,N,function);
			}
			else if(operation==3){ //take a TC for add
				cout << "Please enter TC number(11 digits) to add"<<endl;
				cin >> TC;
				if(function==1) //find key according to function
					key=Folding(TC,N);
				else if(function==2)
					key=Middle_Squaring(TC,N);
				else if(function==3)
					key=Truncation(TC,N);

				if(!berker.search(key,TC)) //first find it is exist or not
					berker.insert(key,TC);	 //if not exist add
				else
					cout<<"TC already exist"<<endl;
			}
			else if(operation==4){
				cout << "Please enter TC number(11 digits) to delete "<<endl; //take a TC for delete
				cin >> d_TC;
				if(function==1)//find key according to function
					key=Folding(d_TC,N);
				else if(function==2)
					key=Middle_Squaring(d_TC,N);
				else if(function==3)
					key=Truncation(d_TC,N);
				berker.deleted(key,d_TC);
			}
			else if(operation==5){
				cout << "Please enter TC number(11 digits) to search "<<endl; //take a TC for search
				cin >> s_TC;
				if(function==1)//find key according to function
					key=Folding(s_TC,N);
				else if(function==2)
					key=Middle_Squaring(s_TC,N);
				else if(function==3)
					key=Truncation(s_TC,N);
				if(berker.search(key,s_TC))
					cout<<"TC is found"<<endl;
				else
					cout<<"TC doesn't exist"<<endl;
			}
			else if(operation==6){ //print the result hash table
				berker.print(N);
				cout<<"Collusion: "<<berker.collusion<<endl;	//collusions
			cout<<"lf: "<<(1.0*berker.factor)/N<<endl;	//and load foctor
			}


		}

		return 0;
	}
