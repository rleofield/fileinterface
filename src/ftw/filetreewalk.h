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

#ifndef FILETREEWALK_H
#define FILETREEWALK_H


#include "t_filename.h"

#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>

using rlf_filefn::t_filename;
using std::string;
using boost::filesystem::path;

namespace rlf_ftw {


   /*! bad_text_read
   \param [in] msg  Message
   */
   class bad_ftw: public  std::runtime_error {
   public:
      bad_ftw( string const& msg )
         :  std::runtime_error( msg ) { }
   };

   class ftw {
      std::vector <t_filename > _files;
      std::vector <t_filename > _dirs;
      std::vector <string > _include_files;
      std::vector <string > _exclude_files;
      std::vector <string > _include_folders;
      std::vector <string > _exclude_folders;
      t_filename _path;
      bool filter_file( boost::filesystem::path const& );
      bool filter_folder( boost::filesystem::path const& );
   public:
      ftw( std::string const& p ):
         _files(),
         _dirs(),
         _include_files(),
         _exclude_files(),
         _include_folders(),
         _exclude_folders(),
         _path( p ) {
      }
      void path( std::string const& p );
      std::vector <t_filename > const& files()const;
      std::vector <t_filename > const& dirs()const;

      // set inlude/exclude pattern
      // file pattern is simply searched in name of file, no wildcards
      void include_files( string const& i );
      void exclude_files( string const& i );
      void include_folders( string const& i );
      void exclude_folders( string const& i );

      // do the real scan
      void scan_folders() throw( bad_ftw );
      void scan_folder() throw( bad_ftw );


   };



} //namespace


#endif // rlf_ftw
