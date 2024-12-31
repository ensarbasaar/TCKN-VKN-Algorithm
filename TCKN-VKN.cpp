#include <iostream>
#include <string>
#include <cmath>
#include <locale.h>
#include "ConsoleColor.h"

using namespace std;

int validateTCKN(const string &tckn) {
    int array1[11]; 
    int toplam = 0;
    int toplamtek= 0;
    int toplamcift= 0;
    int mod10=0;
    int sum=0;
    int summod;
    for (int i = 0; i < 12; i++) {
        array1[i] = tckn[i] - '0'; 	  
    }
    toplamtek=array1[0]+array1[2]+array1[4]+array1[6]+array1[8];
    
    toplam=toplamtek*7;
    
    toplamcift=array1[1]+array1[3]+array1[5]+array1[7];
    
    toplam-=toplamcift;
    
    mod10=toplam%10;
    
    
    
    
    for(int k=0;k<10;k++){
    	sum+=array1[k];
	}
	summod=sum%10;
	
	
	
    if((mod10==array1[9])&&(summod==array1[10])){
	
    	return true;
	}
	
	
    else{
    	return false;
	}

    
}


int validateVKN(const string &vkn) {
    int array[10]; 
    int array2[10];
    int sayac;
    int toplamvkn=0;
    int i;
    int c=0;
    int d=0;
     for (i = 0; i < 11; i++) {
        array[i] = vkn[i] - '0'; 	  
    }
     for(int i=0;i<11;i++){
	 
         array2[c]=array[i];  
         c=c+1;
     }
     c=0;
    
    for(int j=9;j>=1;j--){
	  	
    	array2[c]+=j;
    	array2[c]=array2[c]%10;
    	array2[c]=pow(2,j)*array2[c];
    	array2[c]=array2[c]%9;
    	
    	c=c+1;
    	
    
    	if(c==9){
    	   break;	
		}
    
    }
    
    
    
    for(sayac=0;sayac<9;sayac++){
    	toplamvkn+=array2[sayac];
    	
	}
	
	
	if(toplamvkn%10==array2[9]){
    	return true;
    
	}
	else{
	    return false;
}
}



int main()
{
	jump:
	
	int sayac;
	setlocale(LC_ALL, "Turkish");
	int toplam=0;
 	int number;
    cout<<"VKN Dogrulama icin 1 e týklayýnýz\nTCKN Doðrulama için 2 e týklayýnýz.\n";
    cin>>number;
    cin.ignore();
    
	
    if(number==1){
    
    
    string inputvkn;
    cout << "VKN giriniz: ";
    cin >> inputvkn;
    cin.ignore();
    int boyut=inputvkn.size();
    
    
    if(validateVKN(inputvkn)&&(boyut==10)){
    	 cout <<blue<<"Geçerli bir VKN girdiniz...\n"<<white;
    	 goto jump;
    } 
	else {
        cout <<red<<"Geçersiz bir VKN girdiniz...\n"<<white;
        goto jump;
    }
}
  if(number==2){
  
  	string input;
    cout << "TCKN giriniz: ";
    cin >> input;
    cin.ignore();
    bool b1;
    b1=(input[0]-48)>0;
    
    int boyut=input.size();
    
    
    
     if (validateTCKN(input)&&b1&&(boyut==11)) {
        cout <<blue<<"Geçerli bir TCKN girdiniz...\n"<<white;
        goto jump;
    } 
	else {
        cout <<red<<"Geçersiz bir TCKN girdiniz...\n"<<white;
        goto jump;
    }
  
	}
	system("pause");

    return 0;
	}
   

