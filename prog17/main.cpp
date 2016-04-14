#include "List.h"
#include "Car.h"

int main()
  {List<int> intList;//Construct int list
   srand(time(0)); //Generate random seed
   for (int i = 0; i <20; i++)//Push 20 random numbers not higher than 200
    intList.push_back(rand()%201);
   
   cout << "*** INT ORIGINAL LIST ***" << endl;
   intList.print(); //Print original list
   
   intList.mergesort(); //Sort the list
   cout << "\n\n*** INT SORTED LIST ***" << endl;
   intList.print(); //Print sorted list

   List<Car> carList;//Construct Car list
   int minY = 1999;//Minimum year value
   int maxY = 2013;//Maximum year value
   int minP = 4000;//Minimum price value
   int maxP = 30000;//Maximum price value
   
   //Push 20 cars into list with fixed models, but random years and prices based on min and max
   carList.push_back(Car("Hyundai",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Toyota",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Kia",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("BMW",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Mercedes",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Nissan",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Hyundai",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Toyota",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Kia",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("BMW",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Mercedes",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Hyundai",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Toyota",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Kia",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("BMW",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Mercedes",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Nissan",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Hyundai",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Toyota",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   carList.push_back(Car("Kia",rand()%(maxY-minY + 1) + minY,rand()%(maxP-minP + 1) + minP));
   
   cout << "\n\n*** CAR ORIGINAL LIST ***" << endl;
   carList.print();//Print original list
   
   carList.mergesort();//Sort the list
   cout << "\n\n*** CAR SORTED LIST ***" << endl;
   carList.print();//Print sorted list

  }
