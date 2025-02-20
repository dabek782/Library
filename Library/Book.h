#include <string>
#pragma once

class Book
{
protected:
  int bookId;
  std::string author;
  std::string title;
  std::string genre;
  int publication_year;
  bool IsBorrowed;

public:
  Book(int bookId,
       std::string name,
       std::string title,
       std::string genre,
       int publication_year,
       bool IsBorrowed);
  void Display() const;
  void Change_status(bool status);
  bool isBorrowed() const;
  std::string getAuthor() const;
  std::string getTitle() const;
  std::string getGenre() const;
  int getPublicationYear() const;
  int getBookId() const;
};
