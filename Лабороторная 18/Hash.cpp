//Минимуллин Радмир, лаб. 18,  Поиск данных с помощью хэш-таблиц.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

int hash(int b);

int hash(int b){
	
	int q = b*b;
	q = q / 99;
	int T = q % 999;
	return T;
}



void** pand(){
	setlocale(LC_ALL, "rus");
	
	string name[] = 
{
	"Владимир", 
	"Генадий", 
	"Петр", 
	"Николай", 
	"Максим", 
	"Митя", 
	"Илья", 
	"Иван", 
	"Тимур", 
	"Мунир", 
	"Константин", 
	"Сергей",
	"Марк"
};
	string surname[] = 
{
"Смирнов",
"Иванов",
"Кузнецов",
"Соколов",
"Попов",
"Лебедев",
"Козлов",
"Новиков",
"Морозов",
"Петров",
"Волков",
"Соловьёв",
"Васильев"
 };
	string patronymics[] = 
	{
	"Владимирович",
	 "Генадевич", 
	 "Петрович", 
	 "Николаевич", 
	 "Максимович", 
	 "Альбертович", 
	 "Ильич", 
	 "Тимурович", 
	 "Мунирович", 
	 "Константинович", 
	 "Сергеевич", 
	 "Робертович", 
	 "Камилевич"
	 };

	void** tern = new void*[5];	tern[0] = new string[12]; tern[1] = new string[12]; tern[2] = new string[12];	tern[3] = new int[102];	tern[4] = new long[102];

	for(int i = 0; i < 12; i++){	((string*)tern[0])[i] = name[i];	((string*)tern[1])[i] = surname[i];		((string*)tern[2])[i] = patronymics[i];	}
	
	cout << "!ФИО:                             !№счета!сумма!"<< endl;
	
		int random_name;
		int random_surname;
		int random_patronymics;
	for(int i = 0; i < 102; i++){
		random_name = rand()%12;
		random_surname = rand()%12;
		random_patronymics = rand()%12;
		((int*)tern[3])[i] = rand()%9000+1000;
	
		((long*)tern[4])[i] = rand()%99999+11111;
		cout << "!";
		cout << ((string*)tern[0])[random_name];
		cout << " " ;
		cout <<  ((string*)tern[1])[random_surname] ;
		cout << " " ;
		cout << 	((string*)tern[2])[random_patronymics];
		
		for(int j = 0; j < 31 - (((string*)tern[0])[random_name].length() +	((string*)tern[1])[random_surname].length() + ((string*)tern[2])[random_patronymics].length()); j++){
			cout << " ";
		}
		cout << "!" << ((int*)tern[3])[i] << "!" << ((int*)tern[4])[i] << "!" << endl;
		cout << "............................................." << endl;
	}
	int *e = new int[102];
	
	for(int i = 0; i < 102; i++){
		e[i] = hash((((int*)tern[3])[i]));
	
	}
	
	int** tabl;
	tabl[0] = e;	
	tabl[1] = new int[102];
	
	for(int i = 0; i < 102; i++){
		int t = ((int*)tern[3])[i];
		((int*)tabl[1])[i] = t;
	}
	cout << " .............." << endl;
	cout << "Хеш-ключ  !  ключ" << endl;
	
	for (int i = 0; i < 102; i++){
		cout << ((int*)tabl[0])[i] << " " << ((int*)tabl[1])[i] << endl;
	}
	cout << "Введите ключ: ";
	int key;
	cin >> key;
	int hash_key = hash(key);
	
	for(int i = 0; i < 102; i++){
		if(hash_key == ((int*)tabl[0])[i]){
				cout << "!";
				cout <<((string*)tern[0])[random_name];
				cout << " ";
				cout << ((string*)tern[1])[random_surname];
				cout << " " << 	((string*)tern[2])[random_patronymics];
				int y = 31 - (((string*)tern[0])[random_name].length() +	((string*)tern[1])[random_surname].length() + ((string*)tern[2])[random_patronymics].length());
		for(int j = 0; j < y; j++)
		{
			cout << " ";
		}
		cout << "!" << ((int*)tern[3])[i] << "!" << ((int*)tern[4])[i] << "!" << endl;
		}
		else{
		}
	}
	
	return tern;
}



int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	pand();
	
	return 0;
}
