/*
Hoang is a K19 student studying at Bach Khoa University. 
He plans to write a book management software for the library. 
In the class design, Hoang has designed the class Book as follows:

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;
public:
   // some method
}
Your task in this exercise is to implement functions marked with /  * STUDENT ANSWER   *    /.
Note: For exercises in Week 2, we have #include <bits/stdc++.h> and using namespace std;

For example:
___________________________________________________________________
Test	                                         |  Result
___________________________________________________________________
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);|  Giai tich 1
book1.printBook();                               |  Nguyen Dinh Huy
                                                 |  2000
___________________________________________________________________
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);|  Giai tich 1
Book book2 = book1;                              |  Nguyen Dinh Huy
book2.printBook();                               |  2000
___________________________________________________________________
*/

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this->publishingYear = 0;
        this->title = nullptr;
        this->authors = nullptr;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[sizeof(title) / sizeof(char) + 1];
        this->authors = new char[sizeof(authors) / sizeof(char) + 1];
        int i = 0;
        while (title[i] != '\0')
        {
            this->title[i] = title[i];
            i++;
        }
        int j = 0;
        while (authors[j] != '\0')
        {
            this->authors[j] = authors[j];
            j++;
        }
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this->setTitle(book.getTitle());
        this->setAuthors(book.getAuthors());
        this->setPublishingYear(book.getPublishingYear());
    }

    void setTitle(const char *title)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[sizeof(title) / sizeof(char) + 1];
        int i = 0;
        while (title[i] != '\0')
        {
            this->title[i] = title[i];
            i++;
        }
    }

    void setAuthors(const char *authors)
    {
        /*
         * STUDENT ANSWER
         */
        this->authors = new char[sizeof(authors) / sizeof(char) + 1];
        int j = 0;
        while (authors[j] != '\0')
        {
            this->authors[j] = authors[j];
            j++;
        }
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    char *getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->title;
    }

    char *getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] authors;
        delete[] title;
    }

    void printBook()
    {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};
