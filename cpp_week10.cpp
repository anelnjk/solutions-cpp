
//1001.
#include <bits/stdc++.h>
using namespace std;

//i used here string insted of char* because i somehow forgot about it,but other problems are solved with char* array

struct Train
{
  int ID;
  string location;
  string time;
};

void Output(Train* s) //function that outputs the structure
{
  cout<<s->ID<<"_"<<s->location<<"_"<<s->time<<"\n";
}

int main() 
{
  int n,k=-1;
  string city;
  cin>>n;
  Train* train=new Train[n]; //create n number of structures
  for(int i=0;i<n;i++)
  {
    cin>>train[i].ID>>train[i].location>>train[i].time;
    for(int j=0;j<train[i].location.length();j++)
    {
        if(train[i].location[j]>='a'&&train[i].location[j]<='z') //turn lower case into upper case
        {
         train[i].location[j]=train[i].location[j]-32;
        }
    }
  }

  cin>>city; //enter selected city
  for(int i=0;i<city.length();i++)
  {
      if(city[i]>='a'&&city[i]<='z') //turn lower case into upper case
    {
      city[i]=city[i]-32;
    }
  }

  for(int i=0;i<n;i++)
  {
    if(city==train[i].location) //if selected city and city in the ticket are the same
    {
      k=i; //save index of this ticket
    }
  }

  if(k==-1){cout<<"Impossible";} //if there was no same ticket output "impossible"
  if(k!=-1)
  {Output(&train[k]);} //output the ticket
  delete[]train;
  return 0;
}



//1002.
#include <bits/stdc++.h>
using namespace std;
struct Train
{
  int ID;
  char* location;
  char* time;
};
void inputTrain(Train* t, int n) //function that input structures
{
    for(Train* it=t;it!=t+n;it++){
        it->location = new char[100]; //memory for our strings
        it->time=new char[6];
        cin>>it->ID>>it->location>>it->time;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<strlen(t[i].location);j++){
        if(t[i].location[j]>='a'&&t[i].location[j]<='z') //turn into upper case
          {t[i].location[j]-=32;}
      }
    }
}
void Output(Train* s) //function that outputs structure
{
  cout<<s->ID<<"_"<<s->location<<"_"<<s->time<<"\n";
}

int main() 
{
  int n, min=1440, counter=0, k=-1, g; //min=1440, because it is amount of minutes in 1 day
  cin>>n;
  string city;
  Train* train=new Train[n];
  inputTrain(train, n);
  cin>>city;
  for(int i=0;i<city.length();i++)
  {
    if(city[i]>='a'&&city[i]<='z')
    {
      city[i]-=32;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(city==train[i].location) //if city and location are the same
    {
      counter++; //count how many trains to this city we have
      k=i; //remember index of the last train
    }
  }
  Train* sametrain=new Train[counter]; //create another series of structure to save trains to the selected city, in case we have more than 1
  if(k==-1){cout<<"Impossible";}
  if(counter==1) //if there was only one train, output train with index k
  {
    {Output(&train[k]);return 0;}
  }
  if(counter>1) //if there was several trains
  {
    counter=0;
    for(int i=0;i<n;i++)
    {
      if(city==train[i].location) //if traib has the same city, save this structure to "sametrain"
      {
        sametrain[counter++]=train[i];
      }
    }
  }

  for(int i=0;i<counter;i++) //count time when train arrives and find the minimum
  {
    int l=0;
    int time1;
    time1=(10*(sametrain[i].time[l]-'0')+(sametrain[i].time[l+1])-'0')*60+((sametrain[i].time[l+3]-'0')*10)+(sametrain[i].time[l+4]-'0');
    if(time1<min)
    {
      min=time1;
    }
  }
  for(int i=0;i<counter;i++) 
  {
    int l=0;
    int time1;
    time1=(10*(sametrain[i].time[l]-'0')+(sametrain[i].time[l+1])-'0')*60+((sametrain[i].time[l+3]-'0')*10)+(sametrain[i].time[l+4]-'0');
    if(time1==min) //output train that have min time
    {
      Output(&sametrain[i]);
    }
  }
  for(int i=0;i<counter;i++) //deallocate memory
  {
    delete[]sametrain;
  }
  for(int i=0;i<n;i++)
    {
        delete[]train[i].location;
        delete[]train[i].time;
        delete[]train;
    }
  return 0;
}



//1003.
#include <bits/stdc++.h>
using namespace std;

int counter=0;
struct Student{
		int ID;
		char *surname;
		double grade;
	};

void inputStudents(Student* s, int n)//function that inputs structure
{
    for(Student* it=s;it!=s+n;it++)
    {
        it->surname = new char[100];
        cin>>it->ID>>it->surname>>it->grade;
    }
}
void sortGrades(Student* s, int n) //fuction that sort grades
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((s+j)->grade > (s+j+1)->grade)
            swap(*(s+j), s[j+1]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    Student* students = new Student[n];
    inputStudents(students, n);
    sortGrades(students, n);

    double max=students[n-1].grade;
/*after sorting our students by grades, student with max grade will be the last one, this is why [n-1]*/
    for(int i=0;i<n;i++)
    {
      if(students[i].grade==max)//count now many students with max grade do we have
      {
        counter++;
      }
    }
    
    if(counter!=0) //if there was several students, we sort them by ID
    {
      for(int i=n-counter;i<n-1;i++)
      {
        if(students[i].ID>students[i+1].ID)
        {
          swap(students[i].ID, students[i+1].ID);
        }
      }
      for(int i=n-counter;i<n;i++)
      {
        cout<<students[i].ID<<" "<<students[i].surname<<" "<<students[i].grade<<"\n";
      }
    }
    else
    {cout<<students[n-1].ID<<" "<<students[n-1].surname<<" "<<students[n-1].grade<<"\n";}


    for(int i=0;i<n;i++) //deallocate the memory
    {
        delete[]students[i].surname;
        delete[]students;
    }
    return 0;
}



//1004.
#include <bits/stdc++.h>
using namespace std;

int counter=0;
struct Student{
		int ID;
		double grade;
	};

void inputStudents(Student* s, int n) //function inputs students
{
    for(Student* it=s;it!=s+n;it++)
    {
        cin>>it->ID>>it->grade;
    }
}

void sortGrades(Student* s, int n) //sorts them by grades
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((s+j)->grade < (s+j+1)->grade)
            swap(*(s+j), s[j+1]);
        }
    }
}

void sortID(Student* s, int n) //sorts them by ID
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((s+j)->ID > (s+j+1)->ID)
            swap(*(s+j), s[j+1]);
        }
    }
}


int main()
{
    int n;
    cin>>n;
    Student* students = new Student[n];
    inputStudents(students, n);
    sortID(students, n); //sort students by ID
    sortGrades(students, n); //sort students by Grades
    
    for(int i=0;i<n;i++)
    {
      cout<<students[i].ID<<" "<<students[i].grade<<"\n"; //output the list of students
    }

    delete[]students;
    return 0;
}

//1005.
#include <bits/stdc++.h>
using namespace std;

struct Luggage {
  
  char* descrip;
  int count;
  double weight;
};

struct Passenger {

  int luggageSize;
  char* name;
  Luggage *luggage;
};

int main() 
{
  int n;
  cin>>n;
  Passenger* pas=new Passenger[n]; //allocate memory for n number of passengers
  for(int i=0;i<n;i++)
  {
    pas[i].name=new char[50]; //memory for name
    cin>>pas[i].name;
    cin>>pas[i].luggageSize;
    pas[i].luggage=new Luggage[pas[i].luggageSize]; //memory for luggage, depending on how many luggage does the passenger have
    for(int j=0;j<pas[i].luggageSize;j++)
      {
        pas[i].luggage[j].descrip=new char[50]; //memory for description
        cin>>pas[i].luggage[j].descrip;
        cin>>pas[i].luggage[j].count>>pas[i].luggage[j].weight;
      }
  }
  int maximum=0,k,l;
  for(int i=0;i<n;i++)
  {
    int max=0;
    for(int j=0;j<pas[i].luggageSize;j++) //find the max in each passengers luggage
    {
      if((pas[i].luggage[j].weight)*(pas[i].luggage[j].count)>max)
      {
        max=(pas[i].luggage[j].weight)*(pas[i].luggage[j].count); //max=thing*amount
        l=j;
      }
    }
    if(max>maximum) //compare all maximums and find the max maximum
    {
      maximum=max;
      k=i; //remember the index
    }
  }  
  cout<<pas[k].name<<"\n"<<pas[k].luggage[l].descrip;

  for(int i=0;i<n;i++) //deallocate the memory
  {
    for(int j=0;j<pas[i].luggageSize;j++)
    {
      delete[]pas[i].luggage[j].descrip;
    }
    delete[]pas[i].name;
    delete[]pas[i].luggage;
  }
  delete[]pas;
  return 0;
}

//1006.
#include <bits/stdc++.h>
using namespace std;

struct Train
{
  int ID;
  char* FromAddress;
  char* ToAddress;
  char* time;
};

int main() 
{
  int n;
  cin>>n;
  Train* train=new Train[n];
  for(int i=0;i<n;i++)
  {
    cin>>train[i].ID;
    train[i].FromAddress=new char[50];
    train[i].ToAddress=new char[50];
    train[i].time=new char[5];
    cin>>train[i].FromAddress>>train[i].ToAddress>>train[i].time; //input the structure
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<strlen(train[i].FromAddress);j++)
    {
      if(train[i].FromAddress[j]>='a'&&train[i].FromAddress[j]<='z') //turn FromAddress lower case into upper case
      {
        train[i].FromAddress[j]-=32;
      }
    }

    for(int j=0;j<strlen(train[i].ToAddress);j++)
    {
      if(train[i].ToAddress[j]>='a'&&train[i].ToAddress[j]<='z')//turn ToAddress lower case into upper case
      {
        train[i].ToAddress[j]-=32;
      }
    }
  }
  char need[50]; //temporary for addresses of the train
  int need2; //temporary int for ID of the train
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++) //sort trains by ToAddress, compare each letter
    {
      if(strcmp(train[i].ToAddress, train[j].ToAddress)>0) 
/*strcmp compares each element with element of another string, 
so if 1st trains address' letter is bigger in ASCII we swap these lines, just as bubble sorting*/
      {
        strcpy(need,train[i].ToAddress);                 //copy 1st train's address to temporary string
        strcpy(train[i].ToAddress,train[j].ToAddress);   //copy 2nd address into 1st
        strcpy(train[j].ToAddress,need);                 //copy 1st address in the temporary string to 2nd
        strcpy(need,train[i].FromAddress);
        strcpy(train[i].FromAddress,train[j].FromAddress);
        strcpy(train[j].FromAddress,need);
        strcpy(need,train[i].time);
        strcpy(train[i].time,train[j].time);
        strcpy(train[j].time,need);
        need2=train[i].ID;
        train[i].ID=train[j].ID;
        train[j].ID=need2;
      }
    }
  }

  for(int i=0;i<n;i++) //output the list of sorted trains
  {
    cout<<train[i].ID<<" "<<train[i].FromAddress<<" "<<train[i].ToAddress<<" "<<train[i].time<<"\n";
  }
  
  for(int i=0;i<n;i++)//deallocate the memory
  {
    delete[]train[i].FromAddress;
    delete[]train[i].ToAddress;
    delete[]train[i].time;
  }
  delete[]train;
  return 0;
}


//1010.
#include <bits/stdc++.h>
using namespace std;

void output(char* bob, int n, int m) //function outputs chess board
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(*((bob+i*n)+j)-'0'==2) //output all 2's
      {
        cout<<*((bob+i*n)+j);
      }
      else{cout<<"-";} //other colors are "-"
    }
    cout<<"\n";
  }
}

int main() 
{
  char bob[8][8];
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cin>>bob[i][j];
    }
  }
int b=0,w=0,r=0,g=0;
for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++) //count number of each color
    {
      if(bob[i][j]-'0'==0)
      {b++;}
      if(bob[i][j]-'0'==1)
      {w++;}
      if(bob[i][j]-'0'==2)
      {r++;}
      if(bob[i][j]-'0'==3)
      {g++;}
    }
  }
  if(b==0||w==0||r==0||g==0) //if one color was absent, it was bad input list
  {cout<<"BAD INPUT LIST"<<"\n";}
  else
  {
    output((char*)bob, 8, 8);
    cout<<"\n";
    cout<<b<<" "<<w<<" "<<r<<" "<<g<<"\n";
  }
  return 0;
}

//1011.
#include <bits/stdc++.h>
using namespace std;

/*to have valid consequence of brackets our first closing bracket must "delete" the last opening bracket*/

int main() 
{
  char bob[100001], add[100001]; //bob is a main array with sequence of "(",")"
  char need; //need and add are temporaries
  cin>>bob;
  int k=0,i;
  int n=strlen(bob);
  for(i=0;i<n;i++)
  {
    if(bob[0]==')') //if first element is closing ) it is invalid, break
    {break;}
    if(bob[i]=='(') //if it is opening ( we save it as a first element of temp array
    {
      k++;
      add[k]=bob[i];
    }
    else //if it is ) closing, but not the first element of array
    {
      need=add[k]; //we "delete" last opening bracket 
      k--;  //and index will decrease
      if(need=='('&&bob[i]==')') //if bracket that we deleted was opening and last one that we input was closing it is ok, so we continue
      {continue;}
      else //if they both were ) break;
      {break;}
    }
  }
  if((i==n)&&(k==0))
  {
    cout<<"VALID"<<"\n";
  }
  else
  {
    cout<<"INVALID"<<"\n";
  }
  return 0;
}

//1012.
#include <bits/stdc++.h>
using namespace std;

//using the same code as in 1011, but improve it
int main() 
{
  char bob[100001], add[100001];
  char need;
  int num;
  cin>>num; //enter num of brackets
  cin>>bob;
  int k=0,i;
  for(i=0;i<num;i++)
  {
    if((bob[0]==')')||(bob[0]==']')||(bob[0]=='}')) //add [] and {} to condition
    {break;}
    if(bob[i]=='('||(bob[i]=='[')||(bob[i]=='{'))
    {
      k++;
      add[k]=bob[i];
    }
    else
    {
      need=add[k];
      k--;
      if((need=='('&&bob[i]==')')||(need=='['&&bob[i]==']')||(need=='{'&&bob[i]=='}'))
      {continue;}
      else
      {break;}
    }
  }
  if((i==num)&&(k==0))
  {
    cout<<"Yes"<<"\n";
  }
  else
  {
    cout<<"No"<<"\n";
  }
  return 0;
}