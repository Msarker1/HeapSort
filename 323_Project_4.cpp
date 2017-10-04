#include<iostream>
#include<fstream>
using namespace std;



 class HeapSort{
 	private:
 		int sizeOfAry;
		int rootIndex;
 		int fatherIndex;
 		int leftKidIndex;
 		int rightKidIndex;
 		int minKidIndex;
 		int* heapAry;
 	
	 public:
		 HeapSort(){
		 	rootIndex = 0;
		 	fatherIndex = 0;
		 	leftKidIndex = 0;
		 	rightKidIndex = 0;
		 	minKidIndex = 0;
		 	sizeOfAry = 0;
		 	heapAry = NULL;
		 }
		 
		void setArray(int N){
		 	sizeOfAry = N;
	 		heapAry = new int [sizeOfAry];
	 		heapAry[0]=0;
	
		 };
		 
		void buildHeap(char* argv[],ifstream & inFile, ofstream & output1){
		 	rootIndex = 1;
		 	int data = 0;
		 	
			inFile.open(argv[1]);
			while(inFile>>data){
				insertOneDataItem(data);
				output1<<"\n"<<"Insert "<<data<<"\n";
				bubbleUp(heapAry[0]);
				printHeap(output1);
				output1<<"\n";
			}
			inFile.close();
		 };
		 
		void insertOneDataItem(int data){
		 	if(isHeapFull())
		 		return;
		 	else{
		 		heapAry[0]++;
		 		heapAry[heapAry[0]]=data;
		 	}
		 };
		 
		int getRoot(){
		 	return heapAry[rootIndex];
		 };
		 
		 
		 void bubbleUp(int kidIndex){
		 	if( isRoot(kidIndex))
		 		return;
		 	else{
		 		fatherIndex = kidIndex/2;
		 		if(heapAry[kidIndex] <heapAry[fatherIndex]){
					int temp = heapAry[fatherIndex];
					heapAry[fatherIndex] = heapAry[kidIndex];
					heapAry[kidIndex] = temp;
					bubbleUp(fatherIndex);
		 		}
		 		
			 }
		 }
		 
		 void deleteHeap(ofstream& output1, ofstream& output2){
		 	while(!isHeapEmpty()){
			 
		 		int data = getRoot();
		 		output2<<data <<" "; // print to output2 its sorted
		 		
		 		deleteRoot();
		 	
				fatherIndex = rootIndex;
		 		output1<<"\n"<<"Delete "<<data<<"\n";
				bubbleDown(fatherIndex);
		 		printHeap(output1);
		 	}
		 };
		 
		 void deleteRoot(){
		 	heapAry[rootIndex]=heapAry[heapAry[0]];
		 	heapAry[heapAry[0]] = 0;
		 	heapAry[0]--;
		 	
		 };
		 
		 void bubbleDown(int fatherIndex){
		 	if(isLeaf(fatherIndex))
		 		return;
		 	 else{
		 		
		 		leftKidIndex = fatherIndex *2;
		 		rightKidIndex = fatherIndex *2 +1;
		 		
		 		minKidIndex = findMinKidIndex(leftKidIndex,rightKidIndex);
		 		
		 		if(heapAry[minKidIndex]<=heapAry[fatherIndex]){
		 			int temp = heapAry[fatherIndex];
					heapAry[fatherIndex] = heapAry[minKidIndex];
					heapAry[minKidIndex] = temp;
								
					bubbleDown(minKidIndex);
					
				 }
			 }
		 };
		 
		 int findMinKidIndex(int leftKidIndex,int rightKidIndex){
		 	return heapAry[leftKidIndex]<=heapAry[rightKidIndex]? leftKidIndex:rightKidIndex; 	
		 };
		 
		 bool isLeaf(int index){
		 	if(index*2 == heapAry[0]){
		 	
		 		if(heapAry[index*2]<heapAry[index]){
		 			int temp = heapAry[index*2];
		 			heapAry[index*2]=heapAry[index];
		 			heapAry[index]=temp;
		 			
				 }
			 }
		 
		 	return index*2 >heapAry[0] || index*2+1>heapAry[0];
		 };
		 
		 bool isRoot(int index){
		 	return( index == 1);
		 
		 };
		 
		 bool isHeapEmpty(){
		 	return heapAry[0] == 0;
		 };
		 
		 bool isHeapFull(){
		 	return sizeOfAry == heapAry[0];
		 };
		 
		 void printHeap(ofstream & output1){
		 	output1<<"\n";
		 	for(int i = 0 ; i<heapAry[0]+1;i++)
			 	output1<<heapAry[i] << " ";
		 };
	
		
};

int main(int argc, char**argv ){
	if(argc<3){
		cout<<"ERROR WITH ARGUMENTS. * EXAMPLE ARGUMENTS * : File.exe INPUT-FILE OUTPUT-FILE...";
		exit(1);
		}

	int data = 0;
	int count = 0;
	
	HeapSort h;
	
	ifstream inFile1;
	ifstream inFile2;
	ofstream output1;
	ofstream output2;
	
	inFile1.open(argv[1]);
	
	while(inFile1>>data){
		count++;
	}
	inFile1.close();
	

	output1.open(argv[2]);
	output2.open(argv[3]);
	output1<<"DEBUG PURPOSE -buildHEAP"<<"\n";
	h.setArray(count+1);
	h.buildHeap(argv,inFile2,output1);
	output1<<"\n";
	output1<<"DEBUG PURPOSE -deleteHEAP"<<"\n";
	output2<<"SORTED HEAP"<<"\n";
	h.deleteHeap(output1,output2);
	output1.close();
	output2.close();



}
