#include <bits/stdc++.h>
// #include<string>
using namespace std;

class Grades{

    private:
        string name;
        int rollNo;
        static int nextRollNo;
        map<string,int>subToMarks;

    public:

    //setter
    void setName(string name){
        this->name = name;
        rollNo = nextRollNo++;
        cout<<"Your Roll No is "<<rollNo<<endl;
    }

    void setMarks(string sub, int marks){
        subToMarks[sub] = marks;
    }

    //getter
    string getName(){
        return this->name;
    }

    void getMarks(){
        for(auto i : subToMarks){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }

   
    double getAverage(){
        int divider = 0;
        int sum = 0;
        for(auto i:subToMarks){
            sum += i.second;
            divider++;
        }
        return double(sum)/divider;
    }

    char getGrade(){
        double avg = getAverage();
        if(avg > 90){
            return 'A';
        } else if(avg > 80){
            return 'B';
        } else if(avg > 60){
            return 'C';
        } else if(avg > 40){
            return 'D';
        } else{
            return 'F';
        }
    }
        
    void displayResult(){
        cout<<endl;
        cout<<"Result "<<endl;
        cout<<"Name : "<<getName()<<endl;
        getMarks();
        cout<<"Average Marks : "<<getAverage();
        cout<<endl<<"Grade : "<<getGrade();
        cout<<endl<<"------Done-------"<<endl;
    }

};

int Grades :: nextRollNo=101;

int main()
{
    //Enter marks for eacxh sybject and store in the vector array marks for each subject 
    string name;

    Grades user1;
    cout<<"Enter the name of student : ";
    cin>>name;
    user1.setName(name);

    string subject;
    int marks;
    cout<<"TOtal no. of Subjects : ";
    int total;
    cin>>total;
    //set MArks for all subjects
    while(total >0){
        cout<<"Enter your subject"<<" name : ";
        cin>>subject;

        cout<<"Enter your marks (out of 100) : ";
        cin>>marks;

        user1.setMarks(subject,marks);

        total--;
    }

    user1.displayResult();

    return 0;
}