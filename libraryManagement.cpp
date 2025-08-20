#include <bits/stdc++.h>
using namespace std;


class Book{
    private:
        int bookNo;
        static int nextBookNo;
        string title;
        string author;
        bool isIssued;

    public:
        Book(string title,string author){
            bookNo = nextBookNo++;
            this->title = title;
            this->author = author;
            isIssued = false;
        }

        int getBookNo() const {
            return bookNo;
        }
        
        string getTitle() const (){
            return title;
        }

        string getAuthor() const(){
            return author;
        }

        bool getStatus(){
            return isIssued;
        }
    
};

class Library{

    private:

        vector<Book>Books;

    public:
       
   
        void addBook(){

        }

        void issueBook(){

        }

        void showBooks(){


        }

};

int Book :: nextBookNo = 1;

int main(){

     

    
    return 0;
}