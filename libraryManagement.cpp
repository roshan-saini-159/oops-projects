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
        
        string getTitle() const {
            return title;
        }

        string getAuthor() const{
            return author;
        }

        bool getIsIssued(){
            return isIssued;
        }
        
        void bookStatus(){
            if(isIssued){
                cout<<"Not Available ";
            } else{
                cout<<"Available ";
            }
        }

        void printDetails(){
            cout<<"Book No : "<<bookNo<<endl;
            cout<<"Book status : ";
            bookStatus();
            cout<<endl;
            cout<<"Details of Book "<<bookNo <<" are : "<<endl;
            cout<<"Book Name : "<<title<<endl;
            cout<<"Author : "<<author<<endl;
            
        }

        bool issue(){
            isIssued = true;
        }

        bool submit(){
            isIssued = false;
        }
    
};

class Library{

    private:

        vector<Book>Books;

    public:

    
        void addBook(string title,string author){
            Books.push_back(Book(title,author));
        }

        void removeBook(int bookNo){
            for(auto it = Books.begin();it != Books.end();++it){
                    if(it->getBookNo() == bookNo){
                        Books.erase(it);
                        cout<<"Book "<<bookNo<<" Removed Successfully"<<endl;
                        break;
                    }
            }
            

        }

        void issueBook(int bookNo){
            for(auto &book : Books){
                if(book.getBookNo() == bookNo){
                    if(!book.getIsIssued()){ //if Not issued
                        book.issue();
                        cout<<"Book "<< bookNo <<" issued Successfully"<<endl;
                    } else{
                        cout<<"Book "<< bookNo <<" Cannot be issued! It's Already issued!"<<endl;
                    }
                    return;
                }
            }
            cout<<"Book "<<bookNo << " Not Found!"<<endl; 
        }

        void submitBook(int bookNo){
            for(auto &book : Books){
                if(book.getBookNo() == bookNo){
                    if(book.getIsIssued()){
                        book.submit();
                        cout<<"Book "<< bookNo <<" Submitted Successfully!"<<endl;
                    } else{
                        cout<<"Book "<< bookNo <<" Already Their!"<<endl;
                    }
                    return;
                }
            }
            cout<<"Book "<< bookNo <<" Cannot be Submitted! It don't belong to us!"<<endl;
        }

        void showBooks(){
            cout<<endl;
            cout<<"------Printing All Books-------"<<endl;
            for(auto book : Books){
                book.printDetails();
                cout<<endl;
            }
            cout<<"------Done-------"<<endl;
            cout<<endl;
        }

};

int Book :: nextBookNo = 1;

int main(){

    Library lib1;

    lib1.addBook("SCIENCE","ROSHAN");
    lib1.addBook("MATHS","VIKAS");
    lib1.addBook("GEOGRAPHY","AMAY");

    // lib1.showBooks();

    lib1.removeBook(3);

    lib1.issueBook(2);
    lib1.issueBook(2);

    lib1.showBooks();

    lib1.submitBook(3);

    // lib1.showBooks();

  
    
    return 0;
}