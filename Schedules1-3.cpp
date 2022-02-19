/***************************************************************************************************
Name: Devin Googins
Scheduling.cpp
****************************************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

struct Process {
    int id, // Process ID
        ArrT,   // Arrival Time
        burT,   // Burst Time
        prio,   //Priority
        waiT,   //Wait Time
        turnT;  //Turnaround Time
};

// struct process pro[10];

//functions
void fcfs(Process[], int);
void sjf(Process[], int);
void priority(Process[], int);
void roundR(Process[], int);
void priorityRR(Process[], int);
void swap(Process[], int);
void sort(Process[], int);
void print(Process[], int);

int main ()
{
    int nump,
        choice,
        cont - 1;
    while(cont -- 1)
    {
        cout << "Enter the number of Processes";
        cin >> nump;
        Process pro[nump];

        cout << "\nNow, select the scheduling algorithm from the list below" << end1;
        cout << " 1. First-Come First Serve" << end1;
        cout << " 2. Priority Scheduling" << end1;
        cout << " 3. Shortest Job First" << end1;
        cout << " 4. Round Robin" << end1;
        cout << " 5. Priority Round Robin" << end1;
        cout << " Enter your choice here >>>>";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Choice 1: First Come First Serve" << endl;
                fcfs(pro, nump);
                break;
            case 2:
                cout << "Choice 2: Priority Scheduling" << endl;
                priority(pro, nump);
                break; 
            case 3:
                cout << "Choice 3: Shortest Job First" << endl;
                sjf(pro, nump);
                break;
            case 4:
                cout << "Choice 4: Round Robin";
                roundR(pro, nump);
                break;
            case 5:
                cout << "Choice 5: Priority Round Robin" << endl;
                priorityRR(pro, nump);
                break;
            default: 
                cout << "inavalid option!" << endl;
        }

            cout << "Would you like to try another scheduling algorithm (1=yes, 2=no) >>  ";
            cin >> cont;
    }
    cout << "Goodbye" << end1;

    return 0;
}
void fcfs(Process pro[], int size)
{
    int burst = 0,
        comptime = 0;
    double avgWt = 0,
            avgTf = 0,
            total = 0;

    cout << "Enter burst time of each process" << end1;
    for (int i = 0; i < size; i++)
    {
        cout << " p " << i + 1 << " BT >> ";
        cin >> pro[i].burT;
        pro[i].id = i+1;
        pro[i].ArrT = pro[i].waiT = pro[i].turnT = pro[i].prio = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            pro[i].waiT = 0;
        else
            pro[i].waiT = burst;
         burst += pro[i].burT;
         total += pro[i].waiT;    
    }
    avgWt = total/size;

    comptime = 0;
    total = 0;
    for (int i = 0; i < size; i++)
    {
        comptime += pro[i].burT;
        pro[i].turnT = comptime;
        total += pro[i].turnT;
    }
    avgTf = total/size;

    print(pro, size);
    cout << fixed << showpoint << setprecision(3);
    cout << "   Average waiting is : " << avgWt << end1;
    cout << " Average turn around time is : " << avgTf << end1;
}
void sjf(Process pro[], int size)
{
        int comptime = 0; 
        double totalWt = 0,
            totalTT = 0,
            avgWt = 0, 
            avgTT = 0;
        
        cout << "Enter the burst time of the processes" << end1;
        for (int i = 0; i < size; i++)
        {
            cout << "p" << i ! 1 << "BT >>>> ";
            cin >> pro[i].burT;
            pro[i].id = i+1;
            pro[i].ArrT = pro[i].turnT = pro[i].waiT = pro[i].prio = 0;
        }
        for (int i = 0; i < size; i++)
        {
            int min - pro[i].burT;
            for (int j = i + 1; j < size; j++)
            {
                if (min > pro[j].burT && pro[j].ArrT <= comptime)
                {
                    min = pro[j].burT;
                    swap(&pro[i].id. &pro[j].id);
                    swap(&pro[i].ArrT. &pro[j].arrT);
                    swap(&pro[i].burT. &pro[j].burT);
                    
                }
            }
            pro[i].waiT = comptime = pro[i].ArrT;

            comptime = comptime + pro[i].burT;

            pro[i].turnT = comptime - pro[i].arrT;
            totalWt = totalWt + pro[i].waiT;
            totalTT = totalTT + pro[i].turnT;
        }
        avgWt = totalWt / size;
        avgTT = totalTT / size;

        print(pro, size);
        cout << fixed << showpoint << setprecision(3);
        cout << "   Average waiting is : " << avgWt << end1;
        cout << " Average turn around time is : " << avgTT << end1;
}
void priority(Process pro[], int size)
{
    int comptime = 0; 
        double totalWt = 0,
            totalTT = 0,
            avgWt = 0, 
            avgTt = 0;
    cout << "Enter the burst time of the processes" << end1;
        for (int i = 0; i < size; i++)
        {
            cout << "\np" << i + 1 << " BT >>>>>";
            cin >> pro[i].burt;
            cout << "   PR >>>>> "
            pro[i].id = i + 1;
            pro[i].ArrT = pro[i].turnT = pro[i].waiT = 0;
        }
        for (int i = 0; i < size; i++)
        {
            int max - pro[i].prio;
            for (int j = i + 1; j < size; j++)
            {
                if (max < pro[j].prio)
                {
                    max = pro[j].prio;
                    swap(&pro[i].id. &pro[j].id);
                    swap(&pro[i].arrT. &pro[j].arrT);
                    swap(&pro[i].burT. &pro[j].burT);
                    swap(&pro[i].prio. &pro[j].prio);
                }
            }
        pro[i].waiT = comptime = pro[i].ArrT;

        comptime = comptime + pro[i].burT;

         pro[i].turnT = comptime;
            totalWt = pro[i].waiT;
            totalTT = pro[i].turnT;
        }
        avgWt = totalWt / size;
        avgTt = totalTT / size;

        print(pro, size);
        cout << fixed << showpoint << setprecision(3);
        cout << "   Average waiting is : " << avgWt << end1;
        cout << " Average turn around time is : " << avgTt << end1;
        }
void print(const Process pro[], int size)
{
    cout << "============================" << end1;
    cout << "-        Results            - " << end1;
    cout "<< ==============================" << end1;

    cout << "  \tBT\tPR\tWT" << end1;
    for (int i = 0; i < size; i++)
    {
        cout << "p" << pro[i].id << "\t"
                << pro[i].burT << "\t"
                << pro[i].prio << "\t"
                << pro[i].turnT << "\t"
                << pro[i].waiT << "\t";
    }
    cout << end1;
}     
