#include <iostream>
#include <string>
#include <iomanip>
# include <regex>
using namespace std;
const regex pattern("[a-zA-Z][a-zA-Z0-9 ]+");


enum Choices{
Requested_Job=1, 
Execute_job=2,
Display_Queue_job=3,
Quit =4
};

class Queue
{
    // Initialize front and rear
    private:
     int rear, front,count1=0,i;
      // Circular Queue
    int size,track[10];
    string *arr;
    unsigned int denied,executed,total;
  public:
    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new string[s];
       denied=executed=total=0;
       i =123;
    }
    void enQueue(string value);
    void deQueue();
    
    // void operator ++ (){  
    //        ++total;
    //        ++denied;  
    //     }  
    friend class print_job;
    //void displayQueue();
};
class print_job
{
public:
void displayQueue(Queue q);
};
  
  
/* Function to create Circular queue */
void Queue::enQueue(string value)
{
  stringstream ss;  
    ss<<i;  
    string s;  
    ss>>s; 
    //cout<<s;
    //track+=std::to_string(i);i++;
  
  if(!regex_match(value,pattern)){
				track[rear]=i++;
			cout<<"Print job name: Improper format/ Denial"<<endl
          <<"Job Name"<<setw(11)<<"Status"<<setw(13)<<"Tracking #\n"
          <<setw(5)<<value<<setw(14)<<"Denied"<<setw(9)<<track[rear];
		
        denied++;
        total++;
        return;
		}
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
      track[rear]=i++;
        cout<<"\nQueue is Full";
        cout<<"\nJob Confirmation:"<<endl
            <<"Job Name"<<setw(11)<<"Status"<<setw(13)<<"Tracking #\n"
            <<setw(5)<<value<<setw(14)<<"Denied"<<setw(9)<<track[rear];
		
        denied++;
        total++;
        return;
    }
  
    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }
  
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
  
    else
    {
        rear++;
        arr[rear] = value;
    }
    track[rear]=i++;
    cout<<"\nJob Confirmation:"<<endl
        <<"Job Name"<<setw(11)<<"Status"<<setw(13)<<"Tracking #"<<setw(13)<<"Position\n"
        <<setw(5)<<value<<setw(16)<<"Accepted"<<setw(10)<<track[rear]<<setw(10)<<count1+1;

    count1++;
    total++;
}
  
// Function to delete element from Circular Queue
void Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;//return INT_MIN;
    }
    string data = arr[front];
    cout<<"Job Name"<<setw(15)<<"Tracking #"<<setw(15) <<"Queued Jobs\n"
        <<setw(4)<<data<<setw(15)<<track[front]<<setw(15)<<count1-1;
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
      front++;
    
  	
  count1--;
  executed++;
    
   
}
// Function displaying the elements
// of Circular Queue
void print_job::displayQueue(Queue q)
{
    if (q.front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    cout<<"\nNumber of print jobs requested: "<<q.total<<endl
        <<"\nNumber of print jobs currently in queue :"<<q.count1<<endl
        <<"\nNumber of print jobs denied : "<<q.denied<<endl
        <<"\nNumber of print jobs executed : "<<q.executed<<endl
        <<"Print jobs\n";
    if (q.rear >= q.front)
    {
        for (int i = q.front; i <= q.rear; i++)
            cout<<"Job "<<i+1<<". "<<q.arr[i]<<endl;
    }
    else
    {
        for (int i = q.front; i < q.size; i++)
             cout<<"Job "<<i+1<<". "<<q.arr[i]<<endl;
  
        for (int i = 0; i <= q.rear; i++)
            cout<<"Job "<<i+1<<". "<< q.arr[i]<<endl;
    }
}
/* Driver of the program */
int main()
{
  Choices opt;
   Queue q(3);
   print_job p;
    int c=0;
  string name;
while(c!=4)
{
cout<< "\nChoose one of the following options:"<<endl
    <<"1.Request a Print Job"<<endl
    <<"2.Execute a Print Job"<<endl
    <<"3.Display number results"<<endl
    <<"4.Quit the program"<<endl;
cin>>c;
opt = Choices(c);

 switch(opt)
 {
   case Requested_Job:
      // q.inputQueue(q);
        cout<<"enter job name: ";
				cin.ignore();
				getline(cin,name,'\n');
				q.enQueue(name); 
  		break;
   case Execute_job:
      q.deQueue();
            break;
	 case Display_Queue_job:
      p.displayQueue(q);
            break;
   case Quit: exit(1);        
 	default: cout<<"enter correct choice";
};
}
return 0;
}

// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       123         1
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       124         2
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       125         3
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 3

// Number of print jobs requested: 3

// Number of print jobs currently in queue :3

// Number of print jobs denied : 0

// Number of print jobs executed : 0
// Print jobs
// Job 1. sd
// Job 2. sd
// Job 3. sd

// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 2
// Job Name     Tracking #   Queued Jobs
//   sd            123              2
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 2
// Job Name     Tracking #   Queued Jobs
//   sd            124              1
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 2
// Job Name     Tracking #   Queued Jobs
//   sd            125              0
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 2

// Queue is Empty
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       126         1
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       127         2
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Job Confirmation:
// Job Name     Status   Tracking #    Position
//    sd        Accepted       128         3
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Queue is Full
// Job Confirmation:
// Job Name     Status  Tracking #
//    sd        Denied      129
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 1
// enter job name: sd

// Queue is Full
// Job Confirmation:
// Job Name     Status  Tracking #
//    sd        Denied      130
// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
// 3

// Number of print jobs requested: 8

// Number of print jobs currently in queue :3

// Number of print jobs denied : 2

// Number of print jobs executed : 3
// Print jobs
// Job 1. sd
// Job 2. sd
// Job 3. sd

// Choose one of the following options:
// 1.Request a Print Job
// 2.Execute a Print Job
// 3.Display number results
// 4.Quit the program
