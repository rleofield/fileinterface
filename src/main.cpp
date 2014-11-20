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
#include "fn_control.h"
#include "filetreewalk.h"

using namespace std;
using rlf_filefn::t_filename;
using namespace rlf_hfile::fn_control;
using rlf_ftw::ftw;
//using rlf_ftw::ftwReturn;
using rlf_ftw::tExcludeFolders;
using rlf_ftw::tIncludeFiles;

namespace rlf {


   using namespace boost::filesystem;


   int exec() {

      // base must be exist or must have an / at end
      // if not exist, the last entry is interpreted as a filename
      string base = "/home/richard/wrk/snippets2/";
      //
      // C:\RAProjekte\snippets\src

      // correct base
      base =  correct_slash_at_end( base );

      string d = date_time();
      cout << "time: " << d << endl;
      string s =  int_to_string( -3, 4 );
      string s1 =  uint_to_string( 3, 4 );

      string pwd1 = working_folder();

      std::vector<rlf_filefn::t_filename> folders;
      std::vector<rlf_filefn::t_filename> files;

      t_filename fn1( base );

      rlf_ftw::ftw ftw;
      if( path_exists( base ) ) {
         //count = get_folder_count( base );
         tExcludeFolders ExcludeFolders;
         ExcludeFolders.contains = ".svn, .tmp, Debug, Release, html";
         tIncludeFiles includeFiles;
         includeFiles.last = ".cpp, .h";
         ftw.path( base );
         ftw.set_exclude_folders( ExcludeFolders );
         ftw.set_include_files( includeFiles );
         ftw.scan_folders();

         folders = ftw.folders();
         files = ftw.files();
      }

      // copy to string lists
      std::list<string> list_folders;
      std::list<string> list_files;

     for( const rlf_filefn::t_filename & fn: folders ) {
         string temp = fn.fullname();
         list_folders.push_back( temp );
      }

      for( const rlf_filefn::t_filename & fn: files ) {
         string temp = fn.filename();
         list_files.push_back( temp );
      }


      t_filename f = pwd1;
      string p = f.path();

      string temp = pwd1;
      ftw.path( pwd1 );
      ftw.scan_folders();


      files = ftw.files();
      //std::vector<rlf_filefn::t_filename> files1 = files_in_folder( pwd1 );


      temp = pwd1 +  "jj2/kk/zz/";
      create_folders( temp );
      t_filename fn = rlf_filefn::splitpath( temp );
      bool r = false;

      if( fn.is_folder() ) {
         r = fn.path_exists();
      } else {
         r = fn.file_exists();
      }

      if( r == true ) {
         cout << temp << " ist erreichbar" << endl;
      }

      ftw.path( pwd1 );
      ftw.scan_folders();


//      ret = subfolders( base );
      std::vector<rlf_filefn::t_filename> subfolderlist = ftw.folders();
      //temp = subfolderlist[0];
      temp += "neuerfoldertest/abc";
      bool dirCreated = create_folders( temp );

      string pwd = working_folder();
      bool b1 = change_folder( pwd + "base" );
      bool b2 = change_folder( pwd + "src" );
      pwd = working_folder();


      return 0;
   }

} // end of ns ti


int main() {
   return rlf::exec();

}




