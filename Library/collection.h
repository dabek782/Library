#pragma once
#include "Book.h"
#include "Member.h"
#include <map>
class Collection
{
private:
  std::map<int, Book> books;
  std::map<int, Member> members;

public:
  void AddBook(int bookId,
               std::u8string author,
               std::u8string title,
               std::u8string genre,
               int publication_year,
               bool IsBorrowed);
  void AddMember(int MemberID, std::u8string Name, std::u8string Email, int Phone);
  void DisplayBooks();
  void DisplayMembers();
  void DisplayBook(int ID);
  void DisplayMember(int MemberID);
  void RemoveBook(int ID);
  void RemoveMember(int MemberID);
  void BorrowBook(int BookID, int MemberID);
  void ReturnBook(int BookID, int MemberID);
  void DisplayBorrowedBooks(int BookID);
  void WriteToFile(std::u8string Filename);
  void ReadFromFile(std::u8string Filename);
  ~Collection();
};
