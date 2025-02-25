#include <string>
#pragma once

class Book
{
protected:
  int bookId;
  std::u8string author;
  std::u8string title;
  std::u8string genre;
  int publication_year;
  bool IsBorrowed;

public:
  Book(int bookId,
       std::u8string name,
       std::u8string title,
       std::u8string genre,
       int publication_year,
       bool IsBorrowed);
  void Display() const;
  void Change_status(bool status);
  bool isBorrowed() const;
  std::u8string getAuthor() const;
  std::u8string getTitle() const;
  std::u8string getGenre() const;
  int getPublicationYear() const;
  int getBookId() const;
};
