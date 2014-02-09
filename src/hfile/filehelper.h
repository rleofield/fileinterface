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

#ifndef ti_Filehelper_H
#define ti_Filehelper_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cerrno>
#include <boost/cstdint.hpp>

using std::string;
using boost::uintmax_t;

namespace rlf_hfile_intern {


   std::string correct_slash_at_end( std::string const& path );
   std::string getbasename( std::string const& file );
   std::string getextension( std::string const& file );

   std::string working_directory();
   bool  change_directory( std::string const& in ) ;

   bool  create_directory( std::string const& in ) ;
   bool  create_directory_recursive( std::string const& in ) ;

   bool file_exists( string const& fn ) ;
   bool path_exists( string const& path ) ;
   string extension( string const& fn ) ;

   boost::uintmax_t file_size( std::string const& file ) ;



   class tSaveCurrentDirectory {
      std::string saved;
   public:
      tSaveCurrentDirectory(): saved() {
         saved = working_directory();
      }
      ~tSaveCurrentDirectory() {
         change_directory( saved );
      }
   };


   // system
   // YYYY-MM-DD_hh-mm-ss
   std::string date_time() ;



} // end of namespace






#endif

//EOF

