#include <iostream>
#include <fstream>
#include "film.h"
#include "user.h"
#include "genre.h"
#include "actor.h"
#include "table.h"
#include "users.h"
#include "usersmovies.h"

using namespace std;

int main(int argc, char *argv[])
{
  Users users;
  ifstream input("database/users.zad6");
  if(!input)
  {
    ofstream out("database/users.zad6");
    if(!out)
    {
      cout<<"Users data file not found! Could not create users.zad6 file\n\nAborted!"<<endl;
      return 0;
    }
    cout<<"Users data file not found! Empty users.zad6 file created"<<endl;
    out.close();
  }
  input.close();
  users.setFilePath("database/users.zad6");
  users.LoadFromFile();
  users.SetVerbose(true);
  User temp = User(10);
 // cout<<users.getElement(temp)<<endl;
  users.RemoveElement(temp);
  //temp.ID() = 11;
  //cout<<users.getElement(temp)<<endl;
  temp.ID() = 10;
  temp.FirstName() = "Mirza";
  temp.LastName() = "Sakić";
  temp.Adress() = "4. Ul. Dr. Rose Hadživukovića, Tuzla";
  temp.Phone() = "(+387) 60 312-7-034";
  users.AddElement(temp);
  //users.printTree();
  users.AddIndexOnFirstName();
  //users.RemoveElement(temp);
  //users.printIndex(0);
  UsersMovies usersmovies;
  usersmovies.setFilePath("database/user_has_movies.zad6");
  usersmovies.LoadFromFile();
  User temp2(1);
  usersmovies.printTree();
  //usersmovies.printMoviesIndexed();
  cout<<"Korisnik : "<<users.getElement(temp2)<<" je posudio filmove: "<<endl;
  sp::vector<FilmBorrowed*> Movies = usersmovies.GetBorrowedRecordsForUser(1);
  cout<<"asdasd\n";
  for(auto i = 0;i<Movies.size();++i)
  {
    cout<<*Movies[i]<<endl;
  } 
  return 0;
}
