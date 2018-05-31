#include <iostream>
#include <ctime>    // for time()
#include <cstdlib>    // for rand() and srand()
#include "12-5.h"//add 12-5.h,12-5.cpp

const long MIN_PER_HR = 60L;

bool newcustomer(double x);        // is there a new customer?

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

// setting things up
    std::srand(std::time(0));     //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of each queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);            // line queue holds up to qs people
    Queue line2(qs);            // second queue

    cout << "Enter the number of simulation hours: ";
    int hours;                //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles
    Item temp;            //  new customer data
    long turnaways;        //  turned away by full queue
    long customers;         //  joined the queue
    long served;        //  served during the simulation
    long sum_line;        //  cumulative line length
    int wait_time1;        //  time until autoteller1 is free
    int wait_time2;        //  time until autoteller2 is free
    long line_wait;        //  cumulative time in line
     double min_per_cust;    //  average time between arrivals

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    while ( perhour > 0 ) // begin new loop
    {
     min_per_cust = MIN_PER_HR / perhour;
     turnaways = 0;
     customers = 0;
     served = 0;
     sum_line = 0;
     wait_time1 = wait_time2 = 0;
     line_wait = 0;

// running the simulation
     for (long cycle = 0; cycle < cyclelimit; cycle++)
     {
        if (newcustomer(min_per_cust))    // have newcomer
        {
            if (line1.isfull() && line2.isfull())
                turnaways++;
            else // at least one line is not full
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
// add customer to shorter line
                if (line1.queuecount() <= line2.queuecount())
                    line1.enqueue(temp);    // add newcomer to line1
                else
                    line2.enqueue(temp);    // add newcomer to line2
                }
        }
// process customers in first queue
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue (temp);      // attend next customer
            wait_time1 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        sum_line += line1.queuecount();
// process customers in second queue
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue (temp);      // attend next customer
            wait_time2 = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
            wait_time2--;
        sum_line += line2.queuecount();
     }
// reporting results
     if (customers > 0)
     {
        cout << "customers accepted: " << customers << '\n';
        cout << "  customers served: " << served << '\n';
        cout << "         turnaways: " << turnaways << '\n';
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << '\n';
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
     }
     else
        cout << "No customers!\n";
     // clear queues
     while (!line1.isempty())
        line1.dequeue(temp);
     while (!line2.isempty())
        line2.dequeue(temp);

     cout << "Enter new value for customers per hour (0 to quit): ";
     cin >> perhour;
    } // end of new loop
    cout << "Bye\n";

    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (std::rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
