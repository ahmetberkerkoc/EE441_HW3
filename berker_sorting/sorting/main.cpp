//Ahmet Berker KOÇ 2232320
#include <iostream> //  Standard Input / Output Streams Library.
#include <fstream>
#include <string>
#include <cstdlib>
#include<time.h>
#include <ctime>
using namespace std;  // instead of using std::
int Comp_Sel_Sort=0; //initialize all global variable as zero they counts comperison and moves operation according to its algorithm
int Moves_Sel_Sort=0;
int Comp_Bubble_Sort=0;
int Moves_Bubble_Sort=0;
int Comp_QS1=0;
int Moves_QS1=0;
int Comp_QS2=0;
int Moves_QS2=0;
int Comp_QS3=0;
int Moves_QS3=0;
int Comp_QS4=0;
int Moves_QS4=0;
int Comp_MYS=0;
int Moves_MYS=0;

void Swap(int &a,int &b){ //swap funtion which is use in algorithims many times
	int temp;
	temp=a;
	a=b;
	b=temp;
}
//selection sort N^2 method
void selection_sort(int array[],int n){
	int i,j,small;

	for(i=0;i<n-1;i++){
		small=i;
		for(j=i+1;j<n;j++){
			Comp_Sel_Sort++;
			if(array[j]<array[small]){

				small=j;
			}
		}
		Moves_Sel_Sort++;
		Swap(array[i],array[small]);


	}

}
//bubble sort N^2 method
void bubble_sort(int array[],int n){
	int i,j,change;
	i=n-1;
	while(i>0){
		change=0;
		for(j=0;j<i;j++){
			Comp_Bubble_Sort++;
			if(array[j+1]<array[j]){
				Moves_Bubble_Sort++;
				Swap(array[j],array[j+1]);
				change=j;
			}
		}
		i=change;
	}
}
//Quick Sort with pivot is first element. Average nlogn

void QuickSort1(int *array,int low,int high){
	int pivot;
	if(low<high){
		int scanup=low+1;
		int scandown=high;
		pivot=array[low];
		while(true){
			while(array[scanup]<=pivot && scanup<high ){
				Comp_QS1++;//comparison operation
				scanup++;
			}
			while(array[scandown]>pivot &&scandown>low){
				Comp_QS1++;	 //comparison operation
				scandown--;
			}
			if(scanup<scandown){
				Swap(array[scandown],array[scanup]);
				Moves_QS1++; //move operation
			}
			else
				break;
		}
		Moves_QS1++; //move operation
		Swap(array[scandown],array[low]);
		QuickSort1(array,low,scandown-1);
		QuickSort1(array,scandown+1,high);

	}
}
//Quick Sort with pivot is middle element.
void QuickSort2(int *array,int low,int high){
	int pivot;

	if(low<high){
		int scanup=low+1;
		int scandown=high;
		Swap(array[(high+low)/2],array[low]); //middle elemetn to pivot
		pivot=array[low];
		while(true){
			while(array[scanup]<=pivot && scanup<high ){
				Comp_QS2++;//comparison operation
				scanup++;
			}
			while(array[scandown]>pivot &&scandown>low){
				Comp_QS2++;//comparison operation
				scandown--;
			}
			if(scanup<scandown){
				Moves_QS2++; //move operation
				Swap(array[scandown],array[scanup]);
			}
			else
				break;
		}
		Moves_QS2++; //move operation
		Swap(array[scandown],array[low]);
		QuickSort2(array,low,scandown-1);
		QuickSort2(array,scandown+1,high);

	}
}
//Quick Sort with pivot is random element. Average nlogn
void QuickSort3(int *array,int low,int high){
	int pivot;
	int index;

	if(low<high){
		int scanup=low+1;
		int scandown=high;

		index=low + rand()%(high-low+1); //randoom pivot index;
		Swap(array[index],array[low]);
		pivot=array[low];
		while(true){
			while(array[scanup]<=pivot && scanup<high ){
				Comp_QS3++;//comparison operation
				scanup++;
			}
			while(array[scandown]>pivot &&scandown>low){
				Comp_QS3++;//comparison operation
				scandown--;
			}
			if(scanup<scandown){
				Moves_QS3++; //move operation
				Swap(array[scandown],array[scanup]);
			}
			else
				break;
		}
		Moves_QS3++; //move operation
		Swap(array[scandown],array[low]);
		QuickSort3(array,low,scandown-1);
		QuickSort3(array,scandown+1,high);

	}
}
//Quick sort with mean pivot
void QuickSort4(int *array,int low,int high){

	int pivot;
	int index1;
	int index2;
	int index3;
	int index[3];
	if(low<high){
		int scanup=low+1;
		int scandown=high;

		index1=low + rand()%(high-low+1); //random index1
		index2=low + rand()%(high-low+1);//random index2
		index3=low + rand()%(high-low+1);//random index3
		index[0]=array[index1];//random element1
		index[1]=array[index2];//random element2
		index[2]=array[index3];//random element3
		selection_sort(index,3); //go selection sort
		if(array[index1]==index[1]) //find mean
			Swap(array[index1],array[low]);
		else if(array[index2]==index[1])//find mean
			Swap(array[index2],array[low]);
		else if(array[index3]==index[1])//find mean
			Swap(array[index3],array[low]);
		pivot=array[low];//mean is taken as pibot
		while(true){
			while(array[scanup]<=pivot && scanup<high ){
				Comp_QS4++; //comp operation
				scanup++;
			}
			while(array[scandown]>pivot &&scandown>low){
				Comp_QS4++; //comp operation
				scandown--;
			}
			if(scanup<scandown){
				Moves_QS4++; //move operation
				Swap(array[scandown],array[scanup]);
			}
			else
				break;
		}
		Moves_QS4++; //move operation
		Swap(array[scandown],array[low]);
		QuickSort4(array,low,scandown-1);
		QuickSort4(array,scandown+1,high);

	}
}


void MySort(int *array,int low,int high){
	int pivot;
	if(low<high){
		int scanup=low+1;
		int scandown=high;
		pivot=array[low];
		while(true){
			while(array[scanup]<=pivot && scanup<high ){
				Comp_MYS++;		//comparison operation
				scanup++;
			}
			while(array[scandown]>pivot &&scandown>low){
				Comp_MYS++;//comparison operation
				scandown--;
			}
			if(scanup<scandown){
				Moves_MYS++; //move operation
				Swap(array[scandown],array[scanup]);
			}
			else
				break;
		}
		Moves_MYS++; //move operation
		Swap(array[scandown],array[low]);
		if((scandown-low)>10)
			MySort(array,low,scandown-1);
		else
			selection_sort(array+low,(scandown-low));
		if((high-scandown)>10)
			MySort(array,scandown+1,high);
		else
			selection_sort(array+scandown+1,(high-scandown));	//with selection sort if length of array is less than 10

	}
}




void print(int *array,int N){
	for(int i=0;i<N;i++){
	cout<<array[i]<<" ";
	}
	cout<<endl;
}

void INIT_ARRAY(int  *array,int N){	//read from file and initliaze array

    	fstream myfile("input_array.txt", ios_base::in); //this file has 100 element change it with 1000.txt,5000.txt,10000.txt,25000.txt in my zip file
		int i=0;
    	int a;
    	while (myfile >> a)
    	{

    		    array[i]=a;
				i++;
    	}
	}


int main(){
	srand(time(0));
	int N,i,j,operation,sort,k;
	int **timearray;
	int *operationarray[7][100];
	int *array;
	int statstics[3][7];

	while(1){ //infinity loop for take all opertation

	cout << "Choose the operation number from the menu"<<endl;//MENU
	cout<<"1-Initialize input array randomly"<<endl;
	cout<<"2-Load input array from a file"<<endl;
	cout<<"3-Perform Bubble Sort"<<endl;
	cout<<"4-Perform Quick Sort"<<endl;
	cout<<"5-Perform Selection Sort"<<endl;
	cout<<"6-Perform Your Own Sort"<<endl;
	cout<<"7-Compare sorting algorithms"<<endl;
	cin>> operation;
	if(operation==1){
		cout << "Please enter the size of Array "<<endl; //take size
		cin >> N; //txt file has 100 element. For performance evaluation I used other txt files with 1000,5000,10000,25000 element
		array=new int[N];

	}

	else if(operation==2){

	INIT_ARRAY(array,N); //initialize with TXT
	cout<<"Initial Array"<<endl;
		print(array,N);

	timearray=new int*[4]; //timearray is used for 3-4-5-6 operations 4 algorithm is used so initial array is copy 4 times to use 4 algorithm seperately in 3-4-5-6 operations
	for(i=0;i<4;i++)
		timearray[i]=new int[N];
	for(i=0;i<4;i++){
		for(j=0;j<N;j++){
			timearray[i][j]=array[j];
		}
	}

	for(i=0;i<7;i++){ //operation array is used in operation 7 to calculate time for all algroithm there is 7 algorithm and 100 times to be able to calculate time
		for(j=0;j<100;j++){
				operationarray[i][j]=new int[N];
			for(k=0;k<N;k++)

				operationarray[i][j][k]=array[k];
		}
	}
	}


	//bubble sort
	else if(operation==3){
	cout<<"Bubble Sort"<<endl;
	bubble_sort(timearray[0],N);
	print(timearray[0],N);
	}
	else if(operation==4){//Quick sort
		cout<<"Choose one of the Quicksort options"<<endl<<"1. first element as pivot"<<endl<<"2. middle element as pivot"<<endl<<"3. random element as pivot"<<endl<<"4. mean of random 3 element as pivot";
		cin>>sort;
		cout<<"QuicSort with pivot option "<<sort<<endl;
		if(sort==1)
			QuickSort1(timearray[1],0,N-1);
		else if(sort==2)
			QuickSort2(timearray[1],0,N-1);
		else if(sort==3)
			QuickSort3(timearray[1],0,N-1);
		else if(sort==4)
			QuickSort4(timearray[1],0,N-1);

		print(timearray[1],N);

	}
	else if(operation==5){ //selection sort
		cout<<"Selection Sort"<<endl;
		selection_sort(timearray[2],N);
		print(timearray[2],N);
	}

	else if(operation==6){ //My sort
		cout<<"My Own Sort"<<endl;
		MySort(timearray[3],0,N-1);
		print(timearray[3],N);
	}

	else if(operation==7){

			Comp_Sel_Sort=0; //reset to calculate again
			Moves_Sel_Sort=0;
 			Comp_Bubble_Sort=0;
 			Moves_Bubble_Sort=0;
 			Comp_QS1=0;
 			Moves_QS1=0;
 			Comp_QS2=0;
 			Moves_QS2=0;
 			Comp_QS3=0;
 			Moves_QS3=0;
 			Comp_QS4=0;
 			Moves_QS4=0;
 			Comp_MYS=0;
			Moves_MYS=0;

			cout<<"Array size: "<<N<<" numbers"<<endl<<endl;

			cout<<"Bubble Sort: "<<endl; //print type
			double start = double(clock()); //start clock
			for(i=0;i<100;i++) //100 times send to bubble sort operationarray is used for this purpose
				bubble_sort(operationarray[0][i],N);
			double finish = double(clock()); //finis clock
			double elapsed_time = finish - start; //calculate time
			elapsed_time = (elapsed_time*1.0)/100; //avarage it
			cout<<"Data comparision: "<<Comp_Bubble_Sort/100<<endl; // data comparison (avarage it) and print
			cout<<"Data moves: "<<Moves_Bubble_Sort/100<<endl; //data move (avarage it) and print
			cout<<"Time: "<<elapsed_time <<endl;//print time
			cout<<endl;
			//again this operation for all algorithm seperately
			cout<<"Selection Sort: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				selection_sort(operationarray[1][i],N);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<Comp_Sel_Sort/100<<endl;
			cout<<"Data moves: "<<Moves_Sel_Sort/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

			cout<<"Quick Sort1: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				QuickSort1(operationarray[2][i],0,N-1);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<Comp_QS1/100<<endl;
			cout<<"Data moves: "<<Moves_QS1/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

			cout<<"Quick Sort2: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				QuickSort2(operationarray[3][i],0,N-1);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<Comp_QS2/100<<endl;
			cout<<"Data moves: "<<Moves_QS2/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

			cout<<"Quick Sort3: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				QuickSort3(operationarray[4][i],0,N-1);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<Comp_QS3/100<<endl;
			cout<<"Data moves: "<<Moves_QS3/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

			cout<<"Quick Sort4: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				QuickSort4(operationarray[5][i],0,N-1);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<Comp_QS4/100<<endl;
			cout<<"Data moves: "<<Moves_QS4/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

			Comp_Sel_Sort=0;
			Moves_Sel_Sort=0;
			cout<<"My Own Sort: "<<endl;
			start = double(clock());
			for(i=0;i<100;i++)
				MySort(operationarray[6][i],0,N-1);
			finish = double(clock());
			elapsed_time = finish - start;
			elapsed_time = (elapsed_time*1.0)/100;
			cout<<"Data comparision: "<<(Comp_MYS+Comp_Sel_Sort)/100<<endl;
			cout<<"Data moves: "<<(Moves_MYS+Moves_Sel_Sort)/100<<endl;
			cout<<"Time: "<<elapsed_time <<endl;
			cout<<endl;

	}

}
	//int array[11]={25,18,46,85,12,9,556,0,225,7898,55};

	//cout<<"Initial array: "<<endl;
	//print(array,N);
	//double start = double(clock());
	//for(i=0;i<100;i++)
	//	selection_sort(timearray[i],N);
	//selection_sort(array,N);
	//bubble_sort(array,N);
	//QuickSort1(array,0,N-1);
	//QuickSort2(array,0,N-1);
	//QuickSort3(array,0,N-1);
	//MySort(array,0,N-1);
	//MySort2(array,0,N-1);
	//double finish = double(clock());
	//double elapsed_time = finish - start;
	//elapsed_time = (elapsed_time*1.0)/50;
	//cout<<"Sorted array: "<<endl;
	//print(timearray[0],N);
	//cout<<"Data comparision: "<<Comp_Sel_Sort/50<<endl;
	//cout<<"Data moves: "<<Moves_Sel_Sort/50<<endl;
	//cout<<"Data comparision: "<<Comp_Bubble_Sort<<endl;
	//cout<<"Data moves: "<<Moves_Bubble_Sort<<endl;
	//cout<<"Data comparision: "<<Comp_QS1<<endl;
	//cout<<"Data moves: "<<Moves_QS1<<endl;
	//cout<<"Data comparision: "<<Comp_QS2<<endl;
	//cout<<"Data moves: "<<Moves_QS2<<endl;
	//cout<<"Data comparision: "<<Comp_QS3<<endl;
	//cout<<"Data moves: "<<Moves_QS3<<endl;

	//cout<<"Time: "<<elapsed_time <<endl;
	////////
	//int array[11]={25,18,46,85,12,9,556,0,225,7898,55};
	//selection_sort(array,11);
	//bubble_sort(array,11);
	//QuickSort1(array,0,9);
	//QuickSort2(array,0,9);
	//QuickSort3(array,0,6);
	//MySort(array,0,10);
	//MySort2(array,0,10);

	return 0;
}
