#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

#include "Random.h"
#include "TellerQueue.h"
#include "Customer.h"

const char * LOGFILENAME = "log.txt";

void StartSimulation(int &endTime, double &expectArrive);

int main() 
 {fstream log(LOGFILENAME, ios::out);
  if (!log) {
    cout << "Cannot create a log file." << endl;
    return 1;
  }

  Random random;
  int seed = static_cast<int>(time(0));;
  random.randomize(seed);
  log << "Random number seed: " << seed << endl;

  int curTime; // Current time; one unit = time to served a single customer by a single teller.
  int endTime; // Total number of time units to run
  int maxWait = 0; // Maximum wait time
  double avgWait = 0; //Average wait time
  vector<int> waitTime; //All wait times to gather average at the end
  int hadCust = 2; //Last teller to have customer for load balancing
  double expectArrive; //# of customers expected to arrive per unit time
  int t1 = 0; //Number of customers served by teller 1
  int t2 = 0; //Number of customers served by teller 2
  double idleTime1 = 0; //# of unit times when Teller 1 is idle
  double idleTime2 = 0;//# of unit times when Teller 2 is idle
  int nCustomers = 0; // # of customers processed so far
  int nRefuse = 0; // # of customers refused service
  int maxQueueLength = 10; //Maximum number of customers allowed to be waiting
  
  StartSimulation(endTime, expectArrive);
  log << "End time: " << endTime << endl;
  log << "Expected Arrival rate: " << expectArrive << endl;
  log << "Max Queue Length: " << maxQueueLength << endl << endl;

  //General Queue for Both tellers
  TellerQueue T1Queue(maxQueueLength);

  //Per unit time loop
  for (curTime = 0; curTime <= endTime; curTime++) 
    {//Process Customer Arrivals
     int pr = random.poissonRandom(expectArrive);
     for (int i = 1; i <= pr; i++) 
       {int id = nCustomers++;
        Customer cp(id, curTime);
        cout << "Time " << curTime << ": Customer " << cp.getId() << " ready to be served" << endl;
        log  << "Time " << curTime << ": Customer " << cp.getId() << " ready to be served" << endl;
        if (T1Queue.full()) 
          {//Refuse
           cout << "Time " << curTime << ": Customer " << cp.getId() << " refused service" << endl;
           log  << "Time " << curTime << ": Customer " << cp.getId() << " refused service" << endl;
           nRefuse++;
          } 
        else 
          {//Add to the teller queue
           T1Queue.push(cp);
          }
       }//End of teller request processing
         
    // Serve a customer
     //Load Balance: In cases where queue size is only 1, switch off between tellers
     if (T1Queue.size() == 1)
       {Customer cp = T1Queue.front();
        if (hadCust == 2)
          {Customer cp = T1Queue.front();
           T1Queue.pop(); // remove the plane to land
           waitTime.push_back(curTime - cp.getTime());
           if (waitTime.back() > maxWait)
           maxWait = waitTime.back();
           nCustomers++;
           ++t1;
           cout << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 1;"
                << " in queue " << waitTime.back() << " units" << endl
                << "Time " << curTime << ": Teller 2 IDLE\n";
           log  << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 1;"
                << " in queue " << waitTime.back() << " units" << endl
                << "Time " << curTime << ": Teller 2 IDLE\n";
           ++idleTime2;
           hadCust = 1;
          }
        else if (hadCust == 1)
          {Customer cp = T1Queue.front();
           T1Queue.pop();
           waitTime.push_back(curTime - cp.getTime());
           if (waitTime.back() > maxWait)
           maxWait = waitTime.back();
           nCustomers++;
           ++t2;
           cout << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 2;"
                << " in queue " << waitTime.back() << " units" << endl
                << "Time " << curTime << ": Teller 1 IDLE\n";
           log  << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 2;"
                << " in queue " << waitTime.back() << " units" << endl
                << "Time " << curTime << ": Teller 1 IDLE\n";
           ++idleTime1;
           hadCust = 2;
          }
       }//End of Load Balance Block
     else 
       {if (!T1Queue.empty()) // Serve a customer
          {Customer cp = T1Queue.front();
           T1Queue.pop();
           waitTime.push_back(curTime - cp.getTime());
           if (waitTime.back() > maxWait)
           maxWait = waitTime.back();
           nCustomers++;
           ++t1;
           cout << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 1;"
                << " in queue " << waitTime.back() << " units" << endl;
           log  << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 1;"
                << " in queue " << waitTime.back() << " units" << endl;
          }
        else 
          {++idleTime1; cout << "Time " << curTime << ": Teller 1 IDLE\n";
           log << "Time " << curTime << ": Teller 1 IDLE\n";
          }
        if (!T1Queue.empty())
          {Customer cp = T1Queue.front();
           T1Queue.pop();
           waitTime.push_back(curTime - cp.getTime());
           if (waitTime.back() > maxWait)
             maxWait = waitTime.back();
           nCustomers++;
           ++t2;
           cout << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 2;"
                << " in queue " << waitTime.back() << " units" << endl;
           log  << "Time " << curTime << ": Customer " << cp.getId() << " served by teller 2;"
                << " in queue " << waitTime.back() << " units" << endl;
          }
        else 
          {++idleTime2; cout << "Time " << curTime << ": Teller 2 IDLE\n";
           log << "Time " << curTime << ": Teller 2 IDLE\n";
          }
       } 
    }//End of unit time loop
  //Calculate average time
  for (int i = 0; i < waitTime.size(); i++)
    avgWait += waitTime[i];
  avgWait /= waitTime.size();
  
  //Simulation Results
  cout << setprecision(2)
       << "\n************** Simulation Results *****************\n"
       << "Maximum Waiting Time: " << maxWait << " units" << endl
       << "Average Waiting Time: " << avgWait << " units" << endl
       << "Refused Service: " << nRefuse << " customers" << endl
       << "Teller 1 Idle Time: " << (idleTime1/endTime)*100 << "%"
       << " (Served " << t1 << " customers)" << endl
       << "Teller 2 Idle Time: " << (idleTime2/endTime)*100 << "%"
       << " (Served " << t2 << " customers)" << endl; 
  log  << setprecision(2)
       << "\n************** Simulation Results *****************\n"
       << "Maximum Waiting Time: " << maxWait << " units" << endl
       << "Average Waiting Time: " << avgWait << " units" << endl
       << "Refused Service: " << nRefuse << " customers" << endl
       << "Teller 1 Idle Time: " << (idleTime1/endTime)*100 << "%"
       << " (Served " << t1 << " customers)" << endl
       << "Teller 2 Idle Time: " << (idleTime2/endTime)*100 << "%"
       << " (Served " << t2 << " customers)" << endl;
 }

void StartSimulation(int &endTime, double &expectArrive) 
 {cout << "\nThis program simulates a bank with two tellers." << endl;
  cout << "Up to 2 customers can be served at one unit of time." << endl;
  cout << "\nHow many units of time will the simulation run?: ";
  cin >> endTime;
  

  bool ok = true;
  do 
    {cout << "\nExpected number of arrivals per unit time (real number): ";
     cin >> expectArrive;
     if (expectArrive < 0.0)
       {cout << "Expected arrival rate should be positive." << endl;
        ok = false;
       }
     else
      {ok = true;
      }
    } while (ok == false);
 }
