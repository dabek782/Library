#pragma once
#include <string>
#include <vector>
class Member
{
private:
  std::string Name;
  std::string Email;
  int Phone;

protected:
  std::vector<int> BorrowedBooks;
  int MemberID;

public:
  Member() = default;
  Member(int MemberID, std::string Name, std::string Email, int Phone);
  void Display() const;
  void AddBook(int BookID);
  void RemoveBook(int BookID);
};
