#include <iostream>
using namespace std;

class queue {
// Class for queue.

  int data[30];
  int front,rear;
  
  public:
    queue() {
    // Constructor that initialises values for front and rear. 
    front=-1;
    rear=-1;
    }

  int emptyCheck() {
  // Check if it's empty
    if (front==-1 || front>rear) {
      return 1;
    }
    else {
      return 0;
    }
  }
  
  int fullCheck() {
  // Check if it's full
    if (rear>=30) {
      return 1;
    }
    else {
      return 0;
    }
  }

  void enqueue(int x) {
  // Add job to queue
    if (fullCheck()==1) {
      cout<<endl<<"Job queue is full."<<endl;
    }
    
    else {
      if (front==-1) {
        front++;
      }
      rear++;
      data[rear]=x;
    }
  }
  
  void dequeue() {
  // Remove job from queue.
    int x;
    if (emptyCheck()) {
      cout<<endl<<"Job queue is empty."<<endl;
    }
    else {
      x=data[front];
      front++;
      cout<<endl<<"Job ["<<x<<"] has been deleted.";
    }
  }

  void display() {
  // Displaying job queue.
    cout<<"Job queue is:\t[ ";
    for (int i=front; i<=rear; i++) {
      cout<<data[i]<<" | ";
    }
    cout<<"]"<<endl;
  }
};

int main() {
// Main function
  int choice, job, totalJobs;
  queue jobQueue;
  
//Input inital jobs
  cout<<"Enter number of jobs:\t";
  cin>>totalJobs;
  for (int i=0; i<totalJobs; i++) {
   cout<<endl<<"Enter job number "<<i+1<<":\t";
   cin>>job;
   jobQueue.enqueue(job);
  }

  while (1) {
    cout<<endl<<"----- JOB QUEUE MENU -----"<<endl;
    cout<<endl<<"1 -> Add job to queue"<<endl;
    cout<<endl<<"2 -> Delete a job from queue"<<endl;
    cout<<endl<<"3 -> Display queue"<<endl;
    cout<<endl<<"4 -> Exit"<<endl;
    cout<<endl<<endl<<"Choose an option (1-4):\t";
    cin>>choice;
    
    switch (choice) {
      case 1:
        cout<<"Add additional job:\t";
        cin>>job;
        jobQueue.enqueue(job);
        cout<<"\n==============\n";
        jobQueue.display();
        cout<<"=============\n";
        break;

      case 2:
        jobQueue.dequeue();
        cout<<"\n==============\n";
        jobQueue.display();
        cout<<"=============\n";
        break;
        
      case 3:
        cout<<"\n==============\n";
        jobQueue.display();
        cout<<"=============\n";
        break;
      
      case 4:
     
        exit(0);
        
      default:
        cout<<endl<<"Please choose a valid option (1-4)."<<endl;
    }
  }

  return 0;

}
