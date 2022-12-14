#include<array> 
#include<iostream>
#include<cstdlib>
#include<ctime> //#include<chrono> 
#include<string>
#include<fstream>
using namespace std;

void C(array<double,500000>&,int);
void C(array<float ,500000>&,int);
void C(array<long  ,500000>&,int);
void C(array<int   ,500000>&,int);
void C(array<string,500000>&,int);

template<class T> //insertion sort
void insertion_sort(array<T,500000>&a,int n){
	for(int i=1;i<n;i++){
		T key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	/*	cout<<"�Ʀnd: ";
	 for(int j=0;j<n;j++){	
		 cout<<a[j]<<" ";
	}	
	cout<<endl;	*/
}
template<class T>  //bubble sort
void bubble_sort(array<T,500000>&a,int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				T temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
/*	cout<<"�Ʀnd: ";
	 for(int j=0;j<n;j++){	
		 cout<<a[j]<<" ";
	}	
	cout<<endl;	*/
}
template<class T>//selection sort
void selection_sort(array<T,500000>&a,int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if (a[j]<a[min])
				min=j;
		}
		T temp=a[min]; //swap(a[i],a[min]);
		a[min]=a[i];
		a[i]=temp;
	}
	
}

// Merge two subarrays L and M into arr
template<class T> 
void merge(array<T,500000>&a, int p, int q, int r) {
  // Create L �� A[p..q] and M �� A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  T * L=new T [n1]; 
  T * M=new T [n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i=0, j=0, k=p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
  	delete[]L;
	delete[]M;
}

// Divide the array into two subarrays, sort them and merge them
template<class T> 
void merge_sort(array<T,500000>&a, int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    // Merge the sorted subarrays
    merge(a, l, m, r);
  }
}

int main(void){     
	ofstream file;       
	file.open("std_arraytime.txt",ios::out); //�}���ɮ� 
	srand(time(NULL));	

    static	array<double, 500000> dr;
	static	array<float , 500000> fr;
	static	array<long  , 500000> lr;
	static	array<int   , 500000> ir;
	static	array<string, 500000> sr;

 	clock_t start ,end,midstart,midend;
    double alltime,time;
    int datesmall[6]={10,20,30,40,50,60};
	int datebig[5]={100000,200000,300000,400000,500000};
	/*		
	C(dr,10);
	for(int i=0;i<10;i++){
		cout<<dr[i]<<" ";
	}
	cout<<endl;
	insertion_sort(dr,10);
	for(int i=0;i<10;i++){
		cout<<dr[i]<<" ";
	}
	cout<<endl;
	*/

	//insertion_sort
    file<<"insertion_sort����ɶ� "<<endl;
    //�H������10�A20�A30�A40�A50�����
    for(int j=0;j<6;j++){
		//double insertionsort 
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			insertion_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��double���insertion_sort�]1000000�����ɶ�: "<<alltime-time<<endl;	//cout<<"��O�ɶ�"<<alltime-time<<endl;

		//float insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			insertion_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��float ���insertion_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	
		//lonf insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			insertion_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��long  ���insertion_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//int insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			insertion_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��int   ���insertion_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//string insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			insertion_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��string���insertion_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	}
	//�H������10�U�A20�U�A30�U�A40�U�A50�U�����
	for(int j=0;j<5;j++){ 
		//double insertionsort
		cout<<datebig[j]<<endl;
		C(dr,datebig[j]);
		start=clock(); //cout<<start<<endl;
		insertion_sort(dr,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��double���insertion_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//float insertionsort
		C(fr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(fr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��float ���insertion_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//lonf insertionsort
		C(lr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(lr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��long  ���insertion_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//int insertionsort
		C(ir,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(ir,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��int   ���insertion_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//string insertionsort
		C(sr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(sr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��string���insertion_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
	}


//bubble_sort
    file<<"bubble_sort����ɶ� "<<endl;
    for(int j=0;j<6;j++){ //�H������10�A20�A30�A40�A50�����
		//double bubble_sort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			bubble_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��double���bubble_sort�]1000000�����ɶ�: "<<alltime-time<<endl;	//cout<<"��O�ɶ�"<<alltime-time<<endl;

		//float bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			bubble_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��float ���bubble_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	
		//lonf bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			bubble_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��long  ���bubble_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//int bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			bubble_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��int   ���bubble_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//string bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			bubble_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��string���bubble_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	}

	
	for(int j=0;j<5;j++){ //�H������10�U�A20�U�A30�U�A40�U�A50�U�����
		//double bubble_sort
		cout<<datebig[j]<<endl;
		C(dr,datebig[j]);
		start=clock(); //cout<<start<<endl;
		bubble_sort(dr,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��double���bubble_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//float bubble_sort
		C(fr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(fr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��float ���bubble_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//lonf bubble_sort
		C(lr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(lr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��long  ���bubble_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//int bubble_sort
		C(ir,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(ir,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��int   ���bubble_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//string bubble_sort
		C(sr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(sr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��string���bubble_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
	}

//selection_sort
	file<<"selection_sort����ɶ� "<<endl;
  	for(int j=0;j<6;j++){ //�H������10�A20�A30�A40�A50�����
		//double selection_sort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			selection_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��double���selection_sort�]1000000�����ɶ�: "<<alltime-time<<endl;	//cout<<"��O�ɶ�"<<alltime-time<<endl;

		//float selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			selection_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��float ���selection_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	
		//lonf selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			selection_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��long  ���selection_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//int selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			selection_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��int   ���selection_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//string selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			selection_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��string���selection_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	}
	
	for(int j=0;j<5;j++){ //�H������10�U�A20�U�A30�U�A40�U�A50�U�����
		//double selection_sort
		cout<<datebig[j]<<endl;
		C(dr,datebig[j]);
		start=clock(); //cout<<start<<endl;
		selection_sort(dr,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��double���selection_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//float selection_sort
		C(fr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(fr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��float ���selection_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//lonf selection_sort
		C(lr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(lr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��long  ���selection_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//int selection_sort
		C(ir,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(ir,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��int   ���selection_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//string selection_sort
		C(sr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(sr,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��string���selection_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
	}

//merge_sort
	file<<"merge_sort����ɶ� "<<endl;
    for(int j=0;j<6;j++){ //�H������10�A20�A30�A40�A50�A60�����
		//double merge_sort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			merge_sort(dr,0,datesmall[j]-1);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��double���merge_sort�]1000000�����ɶ�: "<<alltime-time<<endl;	//cout<<"��O�ɶ�"<<alltime-time<<endl;

		//float merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			merge_sort(fr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��float ���merge_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	
		//lonf merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			merge_sort(lr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��long  ���merge_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//int merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			merge_sort(ir,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��int   ���merge_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
		//string merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			merge_sort(sr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"��O�ɶ�"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"��O�ɶ�"<<time<<endl;
		file<<datesmall[j]<<"  ��string���merge_sort�]1000000�����ɶ�: "<<alltime-time<<endl;//	cout<<"��O�ɶ�"<<alltime-time<<endl;
	}
	
	for(int j=0;j<5;j++){ //�H������10�U�A20�U�A30�U�A40�U�A50�U�����
		cout<<datebig[j]<<endl;
		//double merge_sort
		C(dr,datebig[j]);
		start=clock(); //cout<<start<<endl;
		merge_sort(dr,0,(datebig[j]-1));
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��double���merge_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//float merge_sort
		C(fr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(fr,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��float ���merge_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		
		//long merge_sort
		C(lr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(lr,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��long  ���merge_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//int merge_sort
		C(ir,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(ir,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��int   ���merge_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
		//string merge_sort
		C(sr,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(sr,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"��O�ɶ�"<<time;
		file<<datebig[j]<<"��string���merge_sort���ɶ�: "<<time<<endl;	//cout<<"��O�ɶ�"<<time<<endl;
	}
	file<<"�����w�]��";
	system("pause");
	return 0;
}

