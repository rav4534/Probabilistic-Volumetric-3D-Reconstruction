#ifndef vidl_io_h
#define vidl_io_h
//-----------------------------------------------------------------------------
//
// .NAME vidl_io - Video Input / Output
// .LIBRARY vidl
// .HEADER vxl package
// .INCLUDE vidl/vidl_io.h
// .FILE vidl_io.cxx
//
// .SECTION Description
//   vidl_io takes care of Input / Output of videos
//   It reads video in from filenames and creates
//   movies or clips. It saves videos into specific
//   codecs
//
// .SECTION See also
//   vidl_codec
//
// .SECTION Author
//   Nicolas Dano, september 1999
//
// .SECTION Modifications
//   Julien Esteve, May 2000
//    Ported from TargetJr
//
//-----------------------------------------------------------------------------

#include <vcl/vcl_string.h> // C++ specific includes first
#include <vbl/vbl_ref_count.h>
#include <vidl/vidl_clip_ref.h>
#include <vidl/vidl_movie_ref.h>
#include <vidl/vidl_codec_ref.h>
#include <vcl/vcl_vector.h>
#include <vcl/vcl_list.h>

class vidl_movie;
class vidl_codec;

class vidl_io //: public vbl_ref_count
{
  // PUBLIC INTERFACE----------------------------------------------------------

public:

  //---------------------------------------------------------
  // 			LoadMovie
  //---------------------------------------------------------

  static vidl_movie_ref load_movie(
	const char* fname,
        int start, int end, 
	int increment, 
	char mode = 'r'
	);

  static vidl_movie_ref load_movie(
	const vcl_list<vcl_string> &fnames,
        int start, 
	int end, 
	int increment, 
	char mode = 'r'
	);

  static vidl_movie_ref load_movie(
	const vcl_vector<vcl_string> &fnames,
        int start, 
	int end, 
	int increment, 
	char mode = 'r'
	);

  static vidl_movie_ref load_movie(
	const char* fname, 
	char mode = 'r'
	) { return load_movie(fname, 0, 0, 1, mode); }

  static vidl_movie_ref load_movie( 
	const vcl_list<vcl_string> &fnames, 
	char mode = 'r'
	) { return load_movie(fnames, 0, 0, 1, mode); }

  static vidl_movie_ref load_movie( 
	const vcl_vector<vcl_string> &fnames, 
	char mode = 'r'
	) { return load_movie(fnames, 0, 0, 1, mode); }

  //---------------------------------------------------------
  // 			LoadClip
  //---------------------------------------------------------

  static vidl_clip_ref load_clip(
	const char* fname,
        int start, 
	int end, 
	int increment, 
	char mode = 'r'
	); 

  static vidl_clip_ref load_clip(
	const vcl_list<vcl_string> &fnames, 
        int start, int end, 
	int increment, 
	char mode = 'r'
	); 

  static vidl_clip_ref load_clip(
	const vcl_vector<vcl_string> &fnames, 
        int start, int end, 
	int increment, 
	char mode = 'r'
	); 

  static vidl_clip_ref load_clip( 
	const char* fname, 
	char mode = 'r'
	) { return load_clip(fname, 0, 0, 1, mode); }

  static vidl_clip_ref load_clip(
	const vcl_list<vcl_string> &fnames, 
	char mode = 'r'
	) { return load_clip(fnames, 0, 0, 1, mode); }

  static vidl_clip_ref load_clip(
	const vcl_vector<vcl_string> &fnames, 
	char mode = 'r'
	) { return load_clip(fnames, 0, 0, 1, mode); }

  //---------------------------------------------------------

  static bool save(
	vidl_movie* movie, 
	const char* fname, 
	const char* type
	); 
  
  // returns vcl_string names  for supported types
  static vcl_list<vcl_string> supported_types(); 

  static void register_codec(vidl_codec* codec); // adds to supported_types list

private:
  
  static vcl_list<vidl_codec_ref> supported_types_;

  // Helpers-------------------------------------------------------------------

  // Functions when videos are sequences of still images
  // This may go in the public area if some people know 
  // they are dealing with images

  static vidl_clip_ref load_images(
	const vcl_list<vcl_string> &fnames,
        int start, 
	int, 
	int increment, 
	char mode = 'r'
	);

  static vidl_clip_ref load_images(
	const vcl_vector<vcl_string> &fnames,
        int start, 
	int, 
	int increment, 
	char mode = 'r'
	);

  static vidl_clip_ref load_images(
	const vcl_list<vcl_string> &fnames, 
	char mode = 'r'
	)
  	{
	return load_images(fnames, 0, 0, 1, mode);
	}

  static vidl_clip_ref load_images(
	const vcl_vector<vcl_string> &fnames, 
	char mode = 'r'
	)
  	{
	return load_images(fnames, 0, 0, 1, mode);
	}

  static bool save_images(
	vidl_movie* movie, 
	const char* fname,  
	const char* type
	);

};
#endif // vidl_io_h

