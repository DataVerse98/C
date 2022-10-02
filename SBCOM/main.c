#include <stdio.h>
#include <string.h>

struct Station{
	int statNum;
	int destination;
	int ArrivalDepartureStation[];
};

//Functions declarations/prototype
//void assign(struct Station b[], int len);
//void getNext(struct Station b[], int len);
int sizeOfArray(struct Station arr);

main(){
	int t_station,leg;
	printf("Insert Total Station:\n");
	scanf("%d", &t_station);
	printf("\nInsert Legs(How Far one station can go):\n");
	scanf("%d", &leg);

	struct Station s[t_station];

	//assign(s, stat);
	//getNext(s, stat);
	
	int i,j,k,l,m,n;
	for(i=0;i<t_station;i++){
		s[i].statNum = i+1;
		s[i].ArrivalDepartureStation[0] = i+1;	//set current station to the arrival/departure 
		printf("\nInsert The Next Station After Station %d: \n",i+1);
		scanf("%d",&s[i].destination);
	}
	//printf("\n__________________________________________\n");
	//int x=0;//,count=0;
	//int z;
	/*for(z=0;z<t_station;z++){
		x=sizeof(s[z].ArrivalDepartureStation);
		printf("\n%d\n",x);
		/*while(x!=NULL){
			printf("\n%d\n",x);
			x=s[z].ArrivalDepartureStation[count];
			count++;
		}*/
	//}*/
	
	struct Station temp, nextStation, copyS[t_station];
	
	/*for(m=0;m<t_station;m++){
		copyS[m] = s[m];
		//copyS[m].statNum = s[m].statNum;
		//copyS[m].destination = s[m].destination;
		//copyS[m].ArrivalDepartureStation = s[m].ArrivalDepartureStation;
	}*/
	//printf("\n__________________________________________\n");
	int a, nextDestination=0, size=0;
	int station=0,d=0;
	for(j=0;j<t_station;j++){
		station = s[j].statNum;
		d = s[j].destination;
		k=1;
		//printf("\n__________________________________________\n");
		//printf("\nvalue d is %d\n",d);
		//printf("\nstation %d\n",d-1);
		//printf("\nvalue station d-1 is %d\n",s[d-1].statNum);
		do{
			size = sizeOfArray(s[d-1]);
			s[d-1].ArrivalDepartureStation[size] = station;
			//printf("\nsize %d\n",size);
			//printf("\nstation %d is added into station %d\n",s[d-1].ArrivalDepartureStation[size],s[d-1].statNum);
			d = s[d-1].destination;
			k++;
			
		}while(k<=leg);
	}
	/*printf("\n__________________________________________\n");
	int x=0,
	x=s[4].ArrivalDepartureStation[0];
	while(x!=NULL){
		printf("\n%d\n",x);
		x=s[4].ArrivalDepartureStation[count];
		count++;
	} */
	int count=0;
	int array[t_station];
	int stationNumber[t_station];
	int q;
	
	/*int ds=0;
	ds = sizeOfArray(s[0].ArrivalDepartureStation);
	printf("\n__________________________________________\n");
	int x=0;
	while(x<ds){
		printf("\n%d\n",s[0].ArrivalDepartureStation[x]);
		x++;
	}*/
	
	
	int displaySize=0,displayStation=0;
	printf("\n__________________________________________\n");
	//simplify the item inside array arrivaldeparture
	for(q=0;q<t_station;q++){
		displaySize = sizeOfArray(s[q]);
		//printf("\n%d\n",displaySize);
		int p=0;
		while(p<t_station){
			stationNumber[p] = 0;
			p++;
		}
		int h=0;
		while(h<displaySize){
			int b=0;
			while(b<t_station){
				if(s[q].ArrivalDepartureStation[h]==s[b].statNum){
			
					if(stationNumber[q]!=1){
						stationNumber[q]=1;					
						array[q]++;
					}
			
				}
				b++;
			}
			h++;
		}
	}
	
	printf("\n__________________________________________\n");
	
	for(q=0;q<t_station;q++){
		printf("\n%d\n",array[q]);
	}
	
	/*
	printf("\n%d\n",displaySize);
	for(l=0;l<displaySize;l++){
		printf("\n%d\n",s[5].ArrivalDepartureStation[l]);
	}*/
	/*for(l=0;l<t_station;l++){
		//displaySize = sizeOfArray(s[l].ArrivalDepartureStation);
		printf("\n%d\n",displaySize);
		//displayStation = s[l].destination;
		//printf("\n%d\n",displayStation);
	}*/

	//return 0;
}

int sizeOfArray(struct Station arr){
	int size = 0;
	int value;
	value = arr.ArrivalDepartureStation[size];
	while(value!=NULL){
		size++;
		value = arr.ArrivalDepartureStation[size];
	}
	size--;
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
