/* --------------------------------------------------------------------------
Copyright 2012 by Richard Albrecht
richard.albrecht@rleofield.de
www.rleofield.de

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------------
*/


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "boost/filesystem.hpp"
#include "boost/regex.hpp"
#include <iostream>


#include "t_filename.h"
#include "t_fncontrol.h"


using namespace std;
using rlf_filefn::t_filename;
using rlf_hfile::tFnFunctions;

namespace rlf {


   using namespace boost::filesystem;


   int exec() {

      string base = "/home/richard/wrk/snippets2/gh";
      tFnFunctions test;

      string pwd1 = test.working_folder();
      bool b = test.create_folder( "pwd1" );

      t_filename f( pwd1 );
      string p = f.path();

      string temp = pwd1;

      std::vector<rlf_filefn::t_filename> files = test.files_in_subfolders( pwd1 );
      std::vector<rlf_filefn::t_filename> files1 = test.files_in_folder( pwd1 );


      temp = pwd1 +  "jj2/kk/zz/";
      test.create_folders( temp );
      t_filename fn( temp );
      bool r = false;

      if( fn.is_folder() ) {
         r = fn.path_exists();
      } else {
         r = fn.file_exists();
      }

      if( r == true ) {
         cout << temp << " ist erreichbar" << endl;
      }


      std::vector<rlf_filefn::t_filename> subfolderlist = test.subfolders( base );
      //temp = subfolderlist[0];
      temp += "neuerfoldertest/abc";
      bool dirCreated = test.create_folders( temp );

      string pwd = test.working_folder();
      b = test.change_folder( pwd + "base" );
      b = test.change_folder( pwd + "src" );
      pwd = test.working_folder();



      return 0;
   }

} // end of ns ti


int main() {
   return rlf::exec();

}




