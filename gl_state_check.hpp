#pragma once

#include <sstream>
#include <string>
#include <iostream>
// your gl header should go here

#define GLSTATECHECK_UNDEFINED -1

#define GLSTATECHECK_VALUE( name, a ) 																					\
	"[" name "]: " << std::to_string( a )

#define GLSTATECHECK_1I( queryEnum, defaultValue ) 																		\
	{																													\
		GLint ret;																										\
		GL_CHECK( glGetIntegerv( ( queryEnum ), &ret ) );																\
		stateCheckBuffer << "\t"  << GLSTATECHECK_VALUE( #queryEnum, ret ) 												\
						 << ",  " << GLSTATECHECK_VALUE( "DEFAULT = " #defaultValue, defaultValue ) << "\n";			\
	}

#define GLSTATECHECK_NAME_1I( queryEnum, defaultName, defaultValue ) 													\
	{																													\
		GLint ret;																										\
		GL_CHECK( glGetIntegerv( ( queryEnum ), &ret ) );																\
		stateCheckBuffer << "\t"  << GLSTATECHECK_VALUE( #queryEnum, ret ) 												\
						 << ",  " << GLSTATECHECK_VALUE( "DEFAULT = " defaultName, defaultValue ) << "\n";				\
	}

#define GLSTATECHECK_1B( queryEnum, defaultValue ) 																		\
	{																													\
		GLboolean ret;																									\
		GL_CHECK( glGetBooleanv( ( queryEnum ), &ret ) );																\
		stateCheckBuffer 	<< "\t" << GLSTATECHECK_VALUE( #queryEnum, ret ) 											\
							<< ", " << GLSTATECHECK_VALUE( "DEFAULT = " #defaultValue, defaultValue )  					\
						    << "\n";																					\
	}

#define GLSTATECHECK_1F( queryEnum, defaultValue ) 																		\
	{																													\
		GLfloat ret;																									\
		GL_CHECK( glGetFloatv( ( queryEnum ), &ret ) );																	\
		stateCheckBuffer << "\t"  << GLSTATECHECK_VALUE( #queryEnum, ret ) 												\
						 << ",  " << GLSTATECHECK_VALUE( "DEFAULT = " #defaultValue, defaultValue ) << "\n";			\
	}

#define GLSTATECHECK_NAME_1F( queryEnum, defaultName, defaultValue ) 													\
	{																													\
		GLfloat ret;																									\
		GL_CHECK( glGetFloatv( ( queryEnum ), &ret ) );																	\
		stateCheckBuffer << "\t"  << GLSTATECHECK_VALUE( #queryEnum, ret ) 												\
						 << ",  " << GLSTATECHECK_VALUE( "DEFAULT = " #defaultName, defaultValue ) << "\n";				\
	}


#define GLSTATECHECK_VALUE_2( name, a, b ) 		\
 	"[" name "]: ( " << std::to_string( a ) << ", " << std::to_string( b ) << " )"

#define GLSTATECHECK_2F( queryEnum, default0, default1 ) 																\
	{																													\
		GLfloat ret[ 2 ];																								\
		GL_CHECK( glGetFloatv( ( queryEnum ), &ret[ 0 ] ) );															\
		stateCheckBuffer 	<< "\t" << GLSTATECHECK_VALUE_2( #queryEnum, ret[ 0 ], ret[ 1 ] ) 							\
							<< ", " << GLSTATECHECK_VALUE_2( "DEFAULT", default0, default1 ) 							\
							<< "\n";																					\
	}

#define GLSTATECHECK_2I( queryEnum, default0, default1 ) 																\
	{																													\
		GLint ret[ 2 ];																									\
		GL_CHECK( glGetIntegerv( ( queryEnum ), &ret[ 0 ] ) );															\
		stateCheckBuffer 	<< "\t" << GLSTATECHECK_VALUE_2( #queryEnum, ret[ 0 ], ret[ 1 ] ) 							\
							<< ", " << GLSTATECHECK_VALUE_2( "DEFAULT", default0, default1 ) 							\
							<< "\n";																					\
	}

#define GLSTATECHECK_VALUE_4( name, a, b, c, d ) 																		\
 	"[" name "]: ( " << std::to_string( a ) << ", " 																	\
 		 << std::to_string( b ) << ", " 																				\
 		 << std::to_string( c ) << ", "  																				\
 		 << std::to_string( d ) << " )"

#define GLSTATECHECK_4F( queryEnum, default0, default1, default2, default3 ) 											\
	{																													\
		GLfloat ret[ 4 ];																								\
		GL_CHECK( glGetFloatv( ( queryEnum ), &ret[ 0 ] ) );															\
		stateCheckBuffer 	<< "\t" << GLSTATECHECK_VALUE_4( #queryEnum, ret[ 0 ], ret[ 1 ], ret[ 2 ], ret[ 3 ] ) 		\
							<< ",\n\t\t" << GLSTATECHECK_VALUE_4( "DEFAULT", default0, default1, default2, default3 ) 	\
							<< "\n";																					\
	}

#define GLSTATECHECK_4I( queryEnum, default0, default1, default2, default3 ) 											\
	{																													\
		GLint ret[ 4 ];																									\
		GL_CHECK( glGetIntegerv( ( queryEnum ), &ret[ 0 ] ) );															\
		stateCheckBuffer 	<< "\t" << GLSTATECHECK_VALUE_4( #queryEnum, ret[ 0 ], ret[ 1 ], ret[ 2 ], ret[ 3 ] ) 		\
							<< ",\n\t\t" << GLSTATECHECK_VALUE_4( "DEFAULT", default0, default1, default2, default3 ) 	\
							<< "\n";																					\
	}

#define GLSTATECHECK_SECTION( name ) \
	stateCheckBuffer << "\n\n[\t" name "\t]" << "\n\n";

void PrintAllTheState( void )
{
	std::stringstream stateCheckBuffer;

	GLSTATECHECK_SECTION( "A" )

	GLSTATECHECK_1I( GL_ACTIVE_TEXTURE, GL_TEXTURE0 )
	GLSTATECHECK_2F( GL_ALIASED_LINE_WIDTH_RANGE, GLSTATECHECK_UNDEFINED, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_2F( GL_ALIASED_POINT_SIZE_RANGE, GLSTATECHECK_UNDEFINED, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1I( GL_ALPHA_BITS, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1I( GL_ARRAY_BUFFER_BINDING, 0 )
	
	GLSTATECHECK_SECTION( "B" )

	GLSTATECHECK_1B( GL_BLEND, GL_FALSE )
	GLSTATECHECK_4F( GL_BLEND_COLOR, 0, 0, 0, 0 )
	GLSTATECHECK_1I( GL_BLEND_DST_ALPHA, GL_ZERO )
	GLSTATECHECK_1I( GL_BLEND_DST_RGB, GL_ZERO )
	GLSTATECHECK_1I( GL_BLEND_EQUATION_ALPHA, GL_FUNC_ADD )
	GLSTATECHECK_1I( GL_BLEND_EQUATION_RGB, GL_FUNC_ADD )
	GLSTATECHECK_1I( GL_BLEND_SRC_ALPHA, GL_ONE )
	GLSTATECHECK_1I( GL_BLEND_SRC_RGB, GL_ONE )
	GLSTATECHECK_1I( GL_BLUE_BITS, GLSTATECHECK_UNDEFINED )
	
	GLSTATECHECK_SECTION( "C" )

	GLSTATECHECK_4F( GL_COLOR_CLEAR_VALUE, 0, 0, 0, 0 )
	GLSTATECHECK_4F( GL_COLOR_WRITEMASK, 0, 0, 0, 0 )
	// TODO: GL_COMPRESSED_TEXTURE_FORMATS
	GLSTATECHECK_1B( GL_CULL_FACE, GL_FALSE )
	GLSTATECHECK_1I( GL_CULL_FACE_MODE, GL_BACK )
	GLSTATECHECK_1I( GL_CURRENT_PROGRAM, 0 )

	GLSTATECHECK_SECTION( "D" )

	GLSTATECHECK_1I( GL_DEPTH_BITS, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1F( GL_DEPTH_CLEAR_VALUE, 1.0f )
	GLSTATECHECK_1I( GL_DEPTH_FUNC, GL_LESS )
	GLSTATECHECK_2F( GL_DEPTH_RANGE, 0.0f, 1.0f )
	GLSTATECHECK_1B( GL_DEPTH_TEST, GL_FALSE )
	GLSTATECHECK_1B( GL_DEPTH_WRITEMASK, GL_TRUE )
	GLSTATECHECK_1B( GL_DITHER, GL_TRUE )

	GLSTATECHECK_SECTION( "E" )

	GLSTATECHECK_1I( GL_ELEMENT_ARRAY_BUFFER_BINDING, 0 )

	GLSTATECHECK_SECTION( "F" )

	GLSTATECHECK_1I( GL_FRAMEBUFFER_BINDING, 0 )
	GLSTATECHECK_1I( GL_FRONT_FACE, GL_CCW )

	GLSTATECHECK_SECTION( "G" )

	GLSTATECHECK_1I( GL_GENERATE_MIPMAP_HINT, GL_DONT_CARE )
	GLSTATECHECK_1I( GL_GREEN_BITS, GLSTATECHECK_UNDEFINED )

	GLSTATECHECK_SECTION( "I" )

	GLSTATECHECK_1I( GL_IMPLEMENTATION_COLOR_READ_FORMAT, GL_UNSIGNED_BYTE )
	GLSTATECHECK_1I( GL_IMPLEMENTATION_COLOR_READ_TYPE, GL_UNSIGNED_BYTE )

	GLSTATECHECK_SECTION( "L" )

	GLSTATECHECK_1F( GL_LINE_WIDTH, 1.0f )

	GLSTATECHECK_SECTION( "M" )

	GLSTATECHECK_1I( GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, 8 )
	GLSTATECHECK_1I( GL_MAX_CUBE_MAP_TEXTURE_SIZE, 16 )
	
	GLSTATECHECK_1I( GL_MAX_FRAGMENT_UNIFORM_VECTORS, 16 )
	
	GLSTATECHECK_1I( GL_MAX_RENDERBUFFER_SIZE, 1 )
	
	GLSTATECHECK_1I( GL_MAX_TEXTURE_IMAGE_UNITS, 8 )
	GLSTATECHECK_1I( GL_MAX_TEXTURE_SIZE, 64 )
	
	GLSTATECHECK_1I( GL_MAX_VARYING_VECTORS, 8 )
	
	GLSTATECHECK_1I( GL_MAX_VERTEX_ATTRIBS, 8 )
	GLSTATECHECK_1I( GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, 0 )
	GLSTATECHECK_1I( GL_MAX_VERTEX_UNIFORM_VECTORS, 128 )

	GLSTATECHECK_2I( GL_MAX_VIEWPORT_DIMS, GLSTATECHECK_UNDEFINED, GLSTATECHECK_UNDEFINED )

	GLSTATECHECK_SECTION( "N" )

	GLSTATECHECK_1I( GL_NUM_COMPRESSED_TEXTURE_FORMATS, 0 )

	GLSTATECHECK_1I( GL_NUM_SHADER_BINARY_FORMATS, 0 )

	GLSTATECHECK_SECTION( "P" )

	GLSTATECHECK_1I( GL_PACK_ALIGNMENT, 4 )

	GLSTATECHECK_1F( GL_POLYGON_OFFSET_FACTOR, 0.0f )
	GLSTATECHECK_1B( GL_POLYGON_OFFSET_FILL, GL_FALSE )
	GLSTATECHECK_1F( GL_POLYGON_OFFSET_UNITS, 0.0f )

	GLSTATECHECK_SECTION( "R" )

	GLSTATECHECK_1I( GL_RED_BITS, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1I( GL_RENDERBUFFER_BINDING, 0 )

	GLSTATECHECK_SECTION( "S" )

	GLSTATECHECK_1B( GL_SAMPLE_ALPHA_TO_COVERAGE, GL_FALSE )
	GLSTATECHECK_1I( GL_SAMPLE_BUFFERS, 0 )
	GLSTATECHECK_1B( GL_SAMPLE_COVERAGE, GL_FALSE )
	GLSTATECHECK_1B( GL_SAMPLE_COVERAGE_INVERT, GL_FALSE )
	GLSTATECHECK_1F( GL_SAMPLE_COVERAGE_VALUE, 1.0f )
	GLSTATECHECK_1I( GL_SAMPLES, 0 )

	GLSTATECHECK_4I( GL_SCISSOR_BOX, 0, 0, GLSTATECHECK_UNDEFINED, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1B( GL_SCISSOR_TEST, GL_FALSE )

	// TODO: GL_SHADER_BINARY_FORMATS
	GLSTATECHECK_1B( GL_SHADER_COMPILER, GL_FALSE )
	
	GLSTATECHECK_1I( GL_STENCIL_BACK_FAIL, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_BACK_FUNC, GL_ALWAYS )
	GLSTATECHECK_1I( GL_STENCIL_BACK_PASS_DEPTH_FAIL, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_BACK_PASS_DEPTH_PASS, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_BACK_REF, 0 )
	GLSTATECHECK_1I( GL_STENCIL_BACK_VALUE_MASK, 0xFF )
	GLSTATECHECK_1I( GL_STENCIL_BACK_WRITEMASK, 0xFF )
	GLSTATECHECK_1I( GL_STENCIL_BITS, GLSTATECHECK_UNDEFINED )
	GLSTATECHECK_1I( GL_STENCIL_CLEAR_VALUE, 0 )
	GLSTATECHECK_1I( GL_STENCIL_FAIL, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_FUNC, GL_ALWAYS )
	GLSTATECHECK_1I( GL_STENCIL_PASS_DEPTH_FAIL, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_PASS_DEPTH_PASS, GL_KEEP )
	GLSTATECHECK_1I( GL_STENCIL_REF, 0 )
	GLSTATECHECK_1B( GL_STENCIL_TEST, GL_FALSE )
	GLSTATECHECK_1I( GL_STENCIL_VALUE_MASK, 0xFF )
	GLSTATECHECK_1I( GL_STENCIL_WRITEMASK, 0xFF )

	GLSTATECHECK_1I( GL_SUBPIXEL_BITS, 4 )

	GLSTATECHECK_SECTION( "T" )

	GLSTATECHECK_1I( GL_TEXTURE_BINDING_2D, 0 )
	GLSTATECHECK_1I( GL_TEXTURE_BINDING_CUBE_MAP, 0 )

	GLSTATECHECK_SECTION( "U" )

	GLSTATECHECK_1I( GL_UNPACK_ALIGNMENT, 4 )

    GLSTATECHECK_SECTION( "V" )

	GLSTATECHECK_4I( GL_VIEWPORT, 0, 0, GLSTATECHECK_UNDEFINED, GLSTATECHECK_UNDEFINED )

	std::cout << stateCheckBuffer.str() << std::endl;
}
