#include<iostream>
#include<string>

using namespace std;




class Process{
private: string name;
private: string status;
private: long remaintime;
		 int pid;

		 /*
		 public: Process(int pid){
		 this->pid=pid;

		 }
		 */

public :Process(){
		}

public :int getPid(){
			return this->pid;
		}
public:void setPid(int pid){
		   this->pid=pid;
	   }

public:void setTime(long time){
		   time=this->remaintime;
	   }

public:long getTime(){
		   return this->remaintime;
	   }

public: void setStatus(string status){
			status=this->status;
		}

public :string getStatsus(){

			return this->status;
		}



};


class ProPool{
private:
	//int CAPACITY=10;
	Process* pros;



public:ProPool(){

		   pros=new Process[10];
		   for(int i=0;i<10;i++){
			   pros[i].setPid(i);
			   cout<<"Process "<<i<<"   is created!"<<endl;
			   cout<<"============================="<<endl;
		   }


		   for(int i=0;i<10;i++){
			   cout<<"Process"<<"   "<<i<<"   "<<"pid is "<<pros[i].getPid()<<endl;
		   }		 

	   }


public: void putBack(Process pro){



	   }

public :Process getOne(int pid){
			//Process *pro;
			Process process;
			for(int i=0;i<10;i++){
				if(this->pros[i].getPid()==pid){
					process=this->pros[i];

					 delete[i] this->pros;

				}
			return process;
		
			}
		}

};


class Status{
	private 
};
class Queue{

public:
	void addToRunning(){
		string status=pro->getStatsus();

		if(status=="RUNNING"){
			runnings

		}

	}



private:Process* running;
		Process* waiting;
		Process* ready;
		Process* pro;



};

int main(){
	//cout<<"gggggggggggggggggggggggggggggggggggggggggggggg"<<endl;
	ProPool pool;


	return 0;
}