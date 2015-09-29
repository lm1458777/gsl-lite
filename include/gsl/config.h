// Copyright 2015 by Martin Moene
//
// gsl-lite is based on GSL: Guidelines Support Library,
// https://github.com/microsoft/gsl
//
// This code is licensed under the MIT License (MIT). 
//

#pragma once

#ifndef GSL_CONFIG_H_INCLUDED
#define GSL_CONFIG_H_INCLUDED

#define  gsl_lite_VERSION "0.0.0"

#ifndef  gsl_FEATURE_HAVE_IMPLICIT_MACRO
# define gsl_FEATURE_HAVE_IMPLICIT_MACRO  1
#endif

#ifndef  gsl_FEATURE_HAVE_OWNER_MACRO
# define gsl_FEATURE_HAVE_OWNER_MACRO  1
#endif

#ifndef  gsl_CONFIG_THROWS_FOR_TESTING
# define gsl_CONFIG_THROWS_FOR_TESTING  0
#endif

#ifndef  gsl_CONFIG_CONFIRMS_COMPILATION_ERRORS
# define gsl_CONFIG_CONFIRMS_COMPILATION_ERRORS  0
#endif

#if defined(_MSC_VER)
# define gsl_COMPILER_MSVC_VERSION   ((_MSC_VER - 600 ) / 100)
#else
# define gsl_COMPILER_MSVC_VERSION   0
# define gsl_COMPILER_NON_MSVC       1
#endif

#if ( __cplusplus >= 201103L ) || gsl_COMPILER_MSVC_VERSION >= 12
# define gsl_CPP11_OR_GREATER  1
#endif

#if ( __cplusplus >= 201402L )
# define gsl_CPP14_OR_GREATER  1
#endif

// half-open range [lo..hi):
#define gsl_BETWEEN( v, lo, hi ) ( lo <= v && v < hi )

// Presence of C++ features:

#if gsl_CPP11_OR_GREATER
# define gsl_HAVE_EXPLICIT  1
#endif

#if gsl_CPP11_OR_GREATER
# define gsl_HAVE_CONSTEXPR_11  1
#endif

#if gsl_CPP11_OR_GREATER
# define gsl_HAVE_DEFAULT_FUNCTION_TEMPLATE_ARG  1
# define gsl_HAVE_ALIAS_TEMPLATE                 1
#endif

#if gsl_CPP11_OR_GREATER || gsl_COMPILER_MSVC_VERSION >= 10
# define gsl_HAVE_SHARED_PTR  1
# define gsl_HAVE_UNIQUE_PTR  1
#endif

#if gsl_CPP11_OR_GREATER || gsl_COMPILER_MSVC_VERSION >= 10
# define gsl_HAVE_NULLPTR  1
#endif

#if gsl_CPP11_OR_GREATER || gsl_COMPILER_MSVC_VERSION >= 11
# define gsl_HAVE_ARRAY  1
#endif

#if gsl_CPP14_OR_GREATER
# define gsl_HAVE_CONSTEXPR_14  1
#endif

// C++ feature usage:

#if gsl_HAVE_CONSTEXPR_11
# define gsl_constexpr constexpr
#else
# define gsl_constexpr /*nothing*/
#endif

#if gsl_HAVE_CONSTEXPR_14
# define gsl_constexpr14 constexpr
#else
# define gsl_constexpr14 /*nothing*/
#endif

#if gsl_HAVE_EXPLICIT
# define gsl_explicit /*explicit*/
#else
# define gsl_explicit /*nothing*/
#endif

#if gsl_FEATURE_HAVE_IMPLICIT_MACRO
# define implicit
#endif

#if gsl_COMPILER_MSVC_VERSION == 6
# define gsl_QUAL_NS_STD(name) name
#else
# define gsl_QUAL_NS_STD(name) std::name
#endif

#define gsl_DIMENSION_OF( a ) ( sizeof(a) / sizeof(0[a]) ) 

#endif // GSL_CONFIG_H_INCLUDED

// end of file