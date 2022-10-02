#include <stdio.h>
#include <string.h>

struct Station{
	int statNum;
	int destination;
	int ArrivalDepartureStation[100];
};

//Functions declarations/prototype
//void assign(struct Station b[], int len);
//void getNext(struct Station b[], int len);
int sizeOfArray(int arr[]);

main(){
	int t_station,leg;
	printf("Insert Total Station:\n");
	scanf("%d", &t_station);
	printf("\nInsert Legs(How Far one station can go):\n");
	scanf("%d", &leg);

	struct Station s[t_station];

	//assign(s, stat);
	//getNext(s, stat);
	
	int i,j,k,l,m,n=0;
	for(i=0;i<t_station;i++){
		s[i].statNum = i+1;
		s[i].ArrivalDepartureStation[0] = i+1;	//set current station to the arrival/departure 
		printf("\nInsert The Next Station After Station %d: \n",i+1);
		scanf("%d",&s[i].destination);
	}
	
	//printf("\n__________________________________________\n");
	int s3size;
	s3size = sizeOfArray(s[4].ArrivalDepartureStation);
	//printf("\nsize %d on station %d\n",s3size,s[4].statNum);
	
	int nextDestination=0, size=0;
	int station=0,d=0;
	for(j=0;j<t_station;j++){
		station = s[j].statNum;
		
		d = s[j].destination;
		
		//printf("\n__________________________________________\n");
		//printf("\nvalue d is %d\n",d);
		
		k=1;
		while(k<=leg){
			size = sizeOfArray(s[d-1].ArrivalDepartureStation);
			//printf("\nsize %d on station %d\n",size,s[d-1].statNum);
			s[d-1].ArrivalDepartureStation[size] = station;
			//printf("\nsize %d\n",size);
			//printf("\nstation %d is added into station %d\n",s[d-1].ArrivalDepartureStation[size],s[d-1].statNum);
			d = s[d-1].destination;
			//printf("\nvalue d is %d\n",d);
			k++;
		}
	}
	/*
	int a;
	
	int displaySize=0;
	for(l=0;l<t_station;l++){
		printf("\n__________________________________________\n");
		displaySize = sizeOfArray(s[l].ArrivalDepartureStation);
		printf("\n%d\n",displaySize);
		
		a=0;
		printf("\n__________________________________________\n");
		while(a<displaySize){
			printf("\n%d\n",s[l].ArrivalDepartureStation[a]);
			a++;
		}
		
		
	}
	*/
	int count;
	int setter[t_station], counter[t_station];
	for(i=0;i<t_station;i++){
		size = sizeOfArray(s[i].ArrivalDepartureStation);
		j=0;
		count=0;
		for(k=0;k<t_station;k++){
			setter[k] = 0;
		}
		while(j<size){
			for(l=0;l<t_station;l++){
				if(s[i].ArrivalDepartureStation[j]==s[l].statNum){
					if(setter[l]!=1){
						setter[l]=1;
						count++;
					}
				}
			}
			j++;
		}
		counter[i] = count;
	}
	printf("\n__________________________________________\n");
	for(i=0;i<t_station;i++){
		printf("\n%d\n",counter[i]);
	}

	//return 0;
}

int sizeOfArray(int arr[]){
	int size = 0;
	int value;
	value = arr[size];
	while(value!=NULL){
		size++;
		value = arr[size];
		
	}
	return size;
}

/*void assign(struct Station s[], int len)
{
	for(int j=0; j<len; j++)
	{
		b[j].station = j+1;
		b[j].array = 0;
		//printf("%d \n", b[j].station);
	}
}

void getNext(struct Station s[], int len)
{
	for(int i=0; i<len; i++)
	{
		scanf("%d", &b[i].next);
	}
*/

