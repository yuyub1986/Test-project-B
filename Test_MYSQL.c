#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//a version in Github 1155

void finish_with_error(MYSQL *con) // show the error message 
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL); // initial an SQL link pointer 


  if (mysql_real_connect(con, "localhost", "yu", "123",
          "testdb", 0, NULL, 0) == NULL)  // connect to the server with username and the possword 
  {
      finish_with_error(con);
  }
  printf("---->Connect to MySql successful!<----\n"); 


if (mysql_query(con, "INSERT INTO Students VALUES(4,'Jake',10)"))  
  {
      finish_with_error(con);
  }

printf("Record inserted \n");

  mysql_close(con); // close the connection 
  exit(0);
}
