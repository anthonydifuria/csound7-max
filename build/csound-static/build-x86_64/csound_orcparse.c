/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         csound_orcparse
#define yylex           csound_orclex
#define yyerror         csound_orcerror
#define yydebug         csound_orcdebug
#define yynerrs         csound_orcnerrs

/* First part of user prologue.  */
#line 141 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"

/* #define YYSTYPE ORCTOKEN* */
/* JPff thinks that line must be wrong and is trying this! */
#define YYSTYPE TREE*

#ifndef NULL
#define NULL 0L
#endif
#include "csoundCore.h"
#include <ctype.h>
#include <string.h>
#include "namedins.h"

#include "csound_orc.h"
#include "parse_param.h"

#ifdef PARCS
#include "cs_par_base.h"
#include "cs_par_orc_semantics.h"
#else
#define csp_orc_sa_instr_add(a,b)
#define csp_orc_sa_instr_add_tree(a,b)
#define csp_orc_sa_instr_finalize(a)
#define csp_orc_sa_global_read_write_add_list(a,b,c)
#define csp_orc_sa_globals_find(a,b)
#define csp_orc_sa_global_read_write_add_list1(a,b,c)
#define csp_orc_sa_interlocks(a, b)
#define csp_orc_sa_global_read_add_list(a,b)
#define csp_orc_sa_global_write_add_list(a,b);
#endif

#define namedInstrFlag csound->parserNamedInstrFlag

    extern TREE* parser_append(CSOUND * csound, TREE *first, TREE *newlast);
    extern int csound_orclex(TREE**, CSOUND *, void *);
    extern void print_tree(CSOUND *, char *msg, TREE *);
    extern TREE* constant_fold(CSOUND *, TREE *);
    extern void csound_orcerror(PARSE_PARM *, void *, CSOUND *,
                                TREE**, const char*);
    extern ORCTOKEN *lookup_token(CSOUND*,char*,void*);
#define LINE csound_orcget_lineno(scanner)
#define LOCN csound_orcget_locn(scanner)
    extern uint64_t csound_orcget_locn(void *);
    extern int csound_orcget_lineno(void *);
    extern ORCTOKEN *make_string(CSOUND *, char *);
    extern char* UNARY_PLUS;
    extern TREE* make_opcall_from_func_start(CSOUND*, int32_t, uint64_t, int32_t, TREE*, TREE*);
    extern void add_instr_variable(CSOUND *csound,  TREE *x);

#line 126 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "csound_orcparse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_S_NEQ = 4,                      /* S_NEQ  */
  YYSYMBOL_S_AND = 5,                      /* S_AND  */
  YYSYMBOL_S_OR = 6,                       /* S_OR  */
  YYSYMBOL_S_LT = 7,                       /* S_LT  */
  YYSYMBOL_S_LE = 8,                       /* S_LE  */
  YYSYMBOL_S_EQ = 9,                       /* S_EQ  */
  YYSYMBOL_S_ADDIN = 10,                   /* S_ADDIN  */
  YYSYMBOL_S_SUBIN = 11,                   /* S_SUBIN  */
  YYSYMBOL_S_MULIN = 12,                   /* S_MULIN  */
  YYSYMBOL_S_DIVIN = 13,                   /* S_DIVIN  */
  YYSYMBOL_S_GT = 14,                      /* S_GT  */
  YYSYMBOL_S_GE = 15,                      /* S_GE  */
  YYSYMBOL_S_BITSHIFT_LEFT = 16,           /* S_BITSHIFT_LEFT  */
  YYSYMBOL_S_BITSHIFT_RIGHT = 17,          /* S_BITSHIFT_RIGHT  */
  YYSYMBOL_LABEL_TOKEN = 18,               /* LABEL_TOKEN  */
  YYSYMBOL_IF_TOKEN = 19,                  /* IF_TOKEN  */
  YYSYMBOL_DECLARE_TOKEN = 20,             /* DECLARE_TOKEN  */
  YYSYMBOL_UDO_TOKEN = 21,                 /* UDO_TOKEN  */
  YYSYMBOL_UDOSTART_DEFINITION = 22,       /* UDOSTART_DEFINITION  */
  YYSYMBOL_UDOEND_TOKEN = 23,              /* UDOEND_TOKEN  */
  YYSYMBOL_UDO_ANS_TOKEN = 24,             /* UDO_ANS_TOKEN  */
  YYSYMBOL_UDO_ARGS_TOKEN = 25,            /* UDO_ARGS_TOKEN  */
  YYSYMBOL_UDO_IDENT = 26,                 /* UDO_IDENT  */
  YYSYMBOL_VOID_TOKEN = 27,                /* VOID_TOKEN  */
  YYSYMBOL_ERROR_TOKEN = 28,               /* ERROR_TOKEN  */
  YYSYMBOL_T_OPCALL = 29,                  /* T_OPCALL  */
  YYSYMBOL_T_FUNCTION = 30,                /* T_FUNCTION  */
  YYSYMBOL_T_ASSIGNMENT = 31,              /* T_ASSIGNMENT  */
  YYSYMBOL_STRUCT_TOKEN = 32,              /* STRUCT_TOKEN  */
  YYSYMBOL_INSTR_TOKEN = 33,               /* INSTR_TOKEN  */
  YYSYMBOL_ENDIN_TOKEN = 34,               /* ENDIN_TOKEN  */
  YYSYMBOL_GOTO_TOKEN = 35,                /* GOTO_TOKEN  */
  YYSYMBOL_KGOTO_TOKEN = 36,               /* KGOTO_TOKEN  */
  YYSYMBOL_IGOTO_TOKEN = 37,               /* IGOTO_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 38,              /* STRING_TOKEN  */
  YYSYMBOL_T_IDENT = 39,                   /* T_IDENT  */
  YYSYMBOL_T_IDENTB = 40,                  /* T_IDENTB  */
  YYSYMBOL_T_TYPED_IDENT = 41,             /* T_TYPED_IDENT  */
  YYSYMBOL_T_TYPED_IDENTB = 42,            /* T_TYPED_IDENTB  */
  YYSYMBOL_T_MEMBER_IDENT = 43,            /* T_MEMBER_IDENT  */
  YYSYMBOL_T_PLUS_IDENT = 44,              /* T_PLUS_IDENT  */
  YYSYMBOL_INTEGER_TOKEN = 45,             /* INTEGER_TOKEN  */
  YYSYMBOL_NUMBER_TOKEN = 46,              /* NUMBER_TOKEN  */
  YYSYMBOL_THEN_TOKEN = 47,                /* THEN_TOKEN  */
  YYSYMBOL_ITHEN_TOKEN = 48,               /* ITHEN_TOKEN  */
  YYSYMBOL_KTHEN_TOKEN = 49,               /* KTHEN_TOKEN  */
  YYSYMBOL_ELSEIF_TOKEN = 50,              /* ELSEIF_TOKEN  */
  YYSYMBOL_ELSE_TOKEN = 51,                /* ELSE_TOKEN  */
  YYSYMBOL_ENDIF_TOKEN = 52,               /* ENDIF_TOKEN  */
  YYSYMBOL_UNTIL_TOKEN = 53,               /* UNTIL_TOKEN  */
  YYSYMBOL_WHILE_TOKEN = 54,               /* WHILE_TOKEN  */
  YYSYMBOL_DO_TOKEN = 55,                  /* DO_TOKEN  */
  YYSYMBOL_OD_TOKEN = 56,                  /* OD_TOKEN  */
  YYSYMBOL_BREAK_TOKEN = 57,               /* BREAK_TOKEN  */
  YYSYMBOL_CONTINUE_TOKEN = 58,            /* CONTINUE_TOKEN  */
  YYSYMBOL_SWITCH_TOKEN = 59,              /* SWITCH_TOKEN  */
  YYSYMBOL_CASE_TOKEN = 60,                /* CASE_TOKEN  */
  YYSYMBOL_DEFAULT_TOKEN = 61,             /* DEFAULT_TOKEN  */
  YYSYMBOL_ENDSW_TOKEN = 62,               /* ENDSW_TOKEN  */
  YYSYMBOL_FOR_TOKEN = 63,                 /* FOR_TOKEN  */
  YYSYMBOL_IN_TOKEN = 64,                  /* IN_TOKEN  */
  YYSYMBOL_TRUE_TOKEN = 65,                /* TRUE_TOKEN  */
  YYSYMBOL_FALSE_TOKEN = 66,               /* FALSE_TOKEN  */
  YYSYMBOL_TRUEK_TOKEN = 67,               /* TRUEK_TOKEN  */
  YYSYMBOL_FALSEK_TOKEN = 68,              /* FALSEK_TOKEN  */
  YYSYMBOL_S_ELIPSIS = 69,                 /* S_ELIPSIS  */
  YYSYMBOL_S_ELIPSIS2 = 70,                /* S_ELIPSIS2  */
  YYSYMBOL_T_ARRAY = 71,                   /* T_ARRAY  */
  YYSYMBOL_T_ARRAY_IDENT = 72,             /* T_ARRAY_IDENT  */
  YYSYMBOL_T_DECLARE = 73,                 /* T_DECLARE  */
  YYSYMBOL_STRUCT_EXPR = 74,               /* STRUCT_EXPR  */
  YYSYMBOL_T_MAPI = 75,                    /* T_MAPI  */
  YYSYMBOL_T_MAPK = 76,                    /* T_MAPK  */
  YYSYMBOL_77_ = 77,                       /* '?'  */
  YYSYMBOL_78_ = 78,                       /* '='  */
  YYSYMBOL_79_ = 79,                       /* '|'  */
  YYSYMBOL_80_ = 80,                       /* '#'  */
  YYSYMBOL_81_ = 81,                       /* '&'  */
  YYSYMBOL_82_ = 82,                       /* '+'  */
  YYSYMBOL_83_ = 83,                       /* '-'  */
  YYSYMBOL_84_ = 84,                       /* '*'  */
  YYSYMBOL_85_ = 85,                       /* '/'  */
  YYSYMBOL_86_ = 86,                       /* '%'  */
  YYSYMBOL_87_ = 87,                       /* '^'  */
  YYSYMBOL_S_UNOT = 88,                    /* S_UNOT  */
  YYSYMBOL_S_UMINUS = 89,                  /* S_UMINUS  */
  YYSYMBOL_S_UPLUS = 90,                   /* S_UPLUS  */
  YYSYMBOL_S_GOTO = 91,                    /* S_GOTO  */
  YYSYMBOL_T_HIGHEST = 92,                 /* T_HIGHEST  */
  YYSYMBOL_93_ = 93,                       /* ','  */
  YYSYMBOL_94_ = 94,                       /* ':'  */
  YYSYMBOL_95_ = 95,                       /* '('  */
  YYSYMBOL_96_ = 96,                       /* ')'  */
  YYSYMBOL_97_ = 97,                       /* '['  */
  YYSYMBOL_98_ = 98,                       /* ']'  */
  YYSYMBOL_99_ = 99,                       /* '.'  */
  YYSYMBOL_100_ = 100,                     /* '~'  */
  YYSYMBOL_101_ = 101,                     /* '!'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_orcfile = 103,                  /* orcfile  */
  YYSYMBOL_root_statement_list = 104,      /* root_statement_list  */
  YYSYMBOL_root_statement = 105,           /* root_statement  */
  YYSYMBOL_struct_definition = 106,        /* struct_definition  */
  YYSYMBOL_struct_arg_list = 107,          /* struct_arg_list  */
  YYSYMBOL_struct_arg = 108,               /* struct_arg  */
  YYSYMBOL_instr_definition = 109,         /* instr_definition  */
  YYSYMBOL_110_1 = 110,                    /* $@1  */
  YYSYMBOL_instr_id_list = 111,            /* instr_id_list  */
  YYSYMBOL_instr_id = 112,                 /* instr_id  */
  YYSYMBOL_udo_definition = 113,           /* udo_definition  */
  YYSYMBOL_udo_arg_list = 114,             /* udo_arg_list  */
  YYSYMBOL_udo_out_arg_list = 115,         /* udo_out_arg_list  */
  YYSYMBOL_out_type_list = 116,            /* out_type_list  */
  YYSYMBOL_out_type = 117,                 /* out_type  */
  YYSYMBOL_opcall = 118,                   /* opcall  */
  YYSYMBOL_function_call = 119,            /* function_call  */
  YYSYMBOL_statement_list = 120,           /* statement_list  */
  YYSYMBOL_statement = 121,                /* statement  */
  YYSYMBOL_if_goto = 122,                  /* if_goto  */
  YYSYMBOL_if_then = 123,                  /* if_then  */
  YYSYMBOL_if_then_base = 124,             /* if_then_base  */
  YYSYMBOL_elseif_list = 125,              /* elseif_list  */
  YYSYMBOL_elseif = 126,                   /* elseif  */
  YYSYMBOL_until = 127,                    /* until  */
  YYSYMBOL_while = 128,                    /* while  */
  YYSYMBOL_case = 129,                     /* case  */
  YYSYMBOL_case_list = 130,                /* case_list  */
  YYSYMBOL_switch = 131,                   /* switch  */
  YYSYMBOL_for_in = 132,                   /* for_in  */
  YYSYMBOL_declare_definition = 133,       /* declare_definition  */
  YYSYMBOL_expr_list = 134,                /* expr_list  */
  YYSYMBOL_expr = 135,                     /* expr  */
  YYSYMBOL_gen_array = 136,                /* gen_array  */
  YYSYMBOL_slice_array = 137,              /* slice_array  */
  YYSYMBOL_static_array = 138,             /* static_array  */
  YYSYMBOL_array_expr = 139,               /* array_expr  */
  YYSYMBOL_struct_expr = 140,              /* struct_expr  */
  YYSYMBOL_ternary_expr = 141,             /* ternary_expr  */
  YYSYMBOL_unary_expr = 142,               /* unary_expr  */
  YYSYMBOL_binary_expr = 143,              /* binary_expr  */
  YYSYMBOL_out_arg_list = 144,             /* out_arg_list  */
  YYSYMBOL_out_arg = 145,                  /* out_arg  */
  YYSYMBOL_out_arg_list_array = 146,       /* out_arg_list_array  */
  YYSYMBOL_array_identifier = 147,         /* array_identifier  */
  YYSYMBOL_assignment = 148,               /* assignment  */
  YYSYMBOL_assignment_array = 149,         /* assignment_array  */
  YYSYMBOL_in = 150,                       /* in  */
  YYSYMBOL_then = 151,                     /* then  */
  YYSYMBOL_goto = 152,                     /* goto  */
  YYSYMBOL_optnewline = 153,               /* optnewline  */
  YYSYMBOL_string = 154,                   /* string  */
  YYSYMBOL_false_const = 155,              /* false_const  */
  YYSYMBOL_true_const = 156,               /* true_const  */
  YYSYMBOL_number = 157,                   /* number  */
  YYSYMBOL_integer = 158,                  /* integer  */
  YYSYMBOL_plus_identifier = 159,          /* plus_identifier  */
  YYSYMBOL_typed_identifier = 160,         /* typed_identifier  */
  YYSYMBOL_typed_identifierb = 161,        /* typed_identifierb  */
  YYSYMBOL_identifier = 162,               /* identifier  */
  YYSYMBOL_identifierb = 163               /* identifierb  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4035

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  488

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   101,     2,    80,     2,    86,    81,     2,
      95,    96,    84,    82,    93,    83,    99,    85,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    94,     2,
       2,    78,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,    98,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    79,     2,   100,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    88,    89,    90,    91,    92
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   200,   200,   212,   214,   217,   218,   219,   220,   221,
     226,   230,   232,   234,   237,   238,   239,   242,   241,   249,
     257,   259,   264,   265,   266,   270,   295,   306,   318,   332,
     334,   336,   340,   342,   344,   346,   349,   351,   354,   355,
     364,   369,   374,   379,   386,   398,   403,   408,   415,   427,
     429,   431,   433,   435,   437,   439,   441,   443,   445,   449,
     453,   456,   460,   465,   469,   470,   480,   495,   510,   511,
     518,   519,   520,   521,   522,   523,   524,   526,   528,   530,
     536,   545,   547,   550,   553,   567,   572,   580,   583,   588,
     594,   600,   606,   613,   620,   621,   627,   635,   641,   648,
     656,   666,   676,   686,   695,   697,   699,   702,   703,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   724,   731,   738,   747,   753,
     760,   769,   776,   784,   789,   795,   801,   814,   828,   833,
     847,   851,   864,   867,   868,   869,   872,   874,   875,   877,
     878,   882,   883,   905,   908,   909,   910,   911,   912,   913,
     914,   915,   916,   917,   919,   920,   921,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     945,   947,   948,   950,   954,   956,   959,   960,   961,   962,
     965,   967,   970,   975,   980,  1004,  1006,  1008,  1010,  1012,
    1017,  1019,  1023,  1027,  1031,  1037,  1040,  1042,  1044,  1048,
    1050,  1052,  1056,  1057,  1060,  1064,  1067,  1073,  1076,  1082,
    1086,  1094,  1100,  1104,  1108,  1112
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "S_NEQ",
  "S_AND", "S_OR", "S_LT", "S_LE", "S_EQ", "S_ADDIN", "S_SUBIN", "S_MULIN",
  "S_DIVIN", "S_GT", "S_GE", "S_BITSHIFT_LEFT", "S_BITSHIFT_RIGHT",
  "LABEL_TOKEN", "IF_TOKEN", "DECLARE_TOKEN", "UDO_TOKEN",
  "UDOSTART_DEFINITION", "UDOEND_TOKEN", "UDO_ANS_TOKEN", "UDO_ARGS_TOKEN",
  "UDO_IDENT", "VOID_TOKEN", "ERROR_TOKEN", "T_OPCALL", "T_FUNCTION",
  "T_ASSIGNMENT", "STRUCT_TOKEN", "INSTR_TOKEN", "ENDIN_TOKEN",
  "GOTO_TOKEN", "KGOTO_TOKEN", "IGOTO_TOKEN", "STRING_TOKEN", "T_IDENT",
  "T_IDENTB", "T_TYPED_IDENT", "T_TYPED_IDENTB", "T_MEMBER_IDENT",
  "T_PLUS_IDENT", "INTEGER_TOKEN", "NUMBER_TOKEN", "THEN_TOKEN",
  "ITHEN_TOKEN", "KTHEN_TOKEN", "ELSEIF_TOKEN", "ELSE_TOKEN",
  "ENDIF_TOKEN", "UNTIL_TOKEN", "WHILE_TOKEN", "DO_TOKEN", "OD_TOKEN",
  "BREAK_TOKEN", "CONTINUE_TOKEN", "SWITCH_TOKEN", "CASE_TOKEN",
  "DEFAULT_TOKEN", "ENDSW_TOKEN", "FOR_TOKEN", "IN_TOKEN", "TRUE_TOKEN",
  "FALSE_TOKEN", "TRUEK_TOKEN", "FALSEK_TOKEN", "S_ELIPSIS", "S_ELIPSIS2",
  "T_ARRAY", "T_ARRAY_IDENT", "T_DECLARE", "STRUCT_EXPR", "T_MAPI",
  "T_MAPK", "'?'", "'='", "'|'", "'#'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "S_UNOT", "S_UMINUS", "S_UPLUS", "S_GOTO", "T_HIGHEST",
  "','", "':'", "'('", "')'", "'['", "']'", "'.'", "'~'", "'!'", "$accept",
  "orcfile", "root_statement_list", "root_statement", "struct_definition",
  "struct_arg_list", "struct_arg", "instr_definition", "$@1",
  "instr_id_list", "instr_id", "udo_definition", "udo_arg_list",
  "udo_out_arg_list", "out_type_list", "out_type", "opcall",
  "function_call", "statement_list", "statement", "if_goto", "if_then",
  "if_then_base", "elseif_list", "elseif", "until", "while", "case",
  "case_list", "switch", "for_in", "declare_definition", "expr_list",
  "expr", "gen_array", "slice_array", "static_array", "array_expr",
  "struct_expr", "ternary_expr", "unary_expr", "binary_expr",
  "out_arg_list", "out_arg", "out_arg_list_array", "array_identifier",
  "assignment", "assignment_array", "in", "then", "goto", "optnewline",
  "string", "false_const", "true_const", "number", "integer",
  "plus_identifier", "typed_identifier", "typed_identifierb", "identifier",
  "identifierb", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-386)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-224)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3489,  -386,  -386,  3405,   -20,   -20,   -20,   177,  -386,  -386,
    -386,  -386,  -386,  -386,  -386,  3405,  3405,  -386,  -386,  3405,
       6,    65,  3489,  -386,  -386,  -386,  -386,  -386,    12,  -386,
    -386,  -386,   226,  -386,  -386,  -386,  -386,  -386,   -40,   -21,
    3139,  -386,  3185,   -64,   -20,   -44,   489,     9,  3231,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,   109,   745,   997,  3405,
    1966,  2012,    16,  2617,  -386,  -386,  -386,   -40,   -21,  -386,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,   192,    29,   179,
       6,   149,    91,    10,  -386,  -386,  -386,  -386,  2711,  2747,
    2395,   -61,   -35,  -386,  -386,  -386,  3405,  3405,  3405,  3405,
    3405,  3405,  3405,  3405,  3405,  3405,  3405,  3972,   155,   243,
    -386,  3405,   -20,  3405,   175,  -386,  -386,  -386,  -386,  -386,
     258,    22,    18,  3061,  3405,  2151,  -386,  -386,  -386,  -386,
    -386,   175,   187,    23,  3405,  2197,    81,   162,   103,  -386,
      94,  -386,  3270,   175,  -386,   127,  -386,    98,  -386,    98,
    -386,   636,    59,  2768,  -386,    92,  -386,    92,   918,   988,
    1106,  1176,  1222,  1269,  1315,  1362,  1408,  1455,  -386,  -386,
    -386,  2058,  1501,  1548,  1594,  1641,  1687,  1734,  1780,  1827,
    1873,  1920,  3279,   216,   172,  3318,   208,   130,   204,    21,
     141,  -386,   -64,   -44,   145,  -386,  -386,  -386,     4,  3972,
    3972,    14,  -386,     6,  3405,     6,  3405,    28,    32,    33,
      34,    35,    36,    49,    51,    52,  2437,  2663,  3514,  -386,
    -386,  3972,   253,  -386,  2479,  -386,  2522,    16,   154,   170,
     -40,  -386,   214,   268,  -386,  2244,    53,  -386,  3318,    60,
     154,   170,   298,  -386,    63,  -386,    67,  -386,  -386,  -386,
    -386,  -386,  2564,   154,   170,  -386,  -386,  -386,  -386,  3405,
    -386,  -386,  3405,  -386,  3405,  -386,  3405,  -386,  3405,  -386,
    3405,  -386,  3405,  -386,  3405,  -386,  3405,  -386,  3405,  -386,
    3405,  -386,  1152,  -386,  3405,  -386,  3405,  -386,  3405,  -386,
    3405,  -386,  3405,  -386,  3405,  -386,  3405,  -386,  3405,  -386,
    3405,  -386,  3405,  3405,  2805,  3972,   314,  3405,  2342,  -386,
     135,   142,   -11,   238,   225,     7,   129,   235,  3972,  -386,
    3556,  3581,    14,  3405,   331,  -386,   248,   271,   271,  2852,
     271,   271,  2889,  -386,  -386,  -386,  -386,  -386,  -386,  -386,
    -386,  -386,  -386,   333,   334,  -386,  3623,  -386,  -386,  -386,
    3405,  -386,  3405,  3061,  -386,  2299,  -386,  -386,  -386,  -386,
    -386,    71,   269,  3089,  3089,   269,   269,   269,   269,   269,
     178,   178,  -386,  2104,   269,   347,   400,   241,    98,    98,
     -46,   -46,   -46,    92,    80,  3357,  3972,  -386,   104,  3396,
    -386,  -386,  -386,   -14,   336,  -386,   -64,   -44,   145,   315,
     -11,   -11,   339,     6,  -386,  3653,  -386,  -386,   220,    70,
    3972,  -386,  -386,  3405,  3405,  3972,  3405,  3405,  3972,  3972,
    -386,   340,  3061,  -386,  -386,  3061,  -386,  -386,   114,  -386,
    -386,   115,  -386,   150,  -386,  -386,   344,   354,   358,  3972,
    -386,   362,  3972,  3972,  2910,  2946,  3682,  3004,  3040,  3711,
    3972,  -386,  -386,  -386,     6,  -386,  3972,  3972,  3972,  3740,
    -386,  3972,  3972,  3972,  -386,  3972,  3972,  -386,  -386,  3769,
    3798,  3827,   364,  3856,  3885,  3914,  3943,   365,   366,   369,
    -386,  -386,  -386,  -386,  -386,  -386,  -386,  -386
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    79,    78,     0,     0,     0,     0,     0,   219,   220,
     221,   234,   235,   232,   233,     0,     0,    76,    77,     0,
       0,     0,     2,     4,     8,     6,     7,    68,     0,     5,
      70,    71,     0,    72,    73,    74,    75,     9,   201,   199,
       0,   195,     0,   198,     0,   197,     0,   196,     0,   224,
     230,   229,   227,   225,   228,   226,     0,     0,     0,     0,
       0,     0,   107,     0,   119,   121,   120,   118,   122,   111,
     112,   113,   117,   124,   123,   116,   115,   114,     0,     0,
       0,     0,     0,     0,    21,    22,    24,    23,     0,     0,
       0,     0,     0,     1,     3,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
      87,     0,     0,     0,     0,   206,   207,   209,   208,   205,
       0,     0,     0,   106,     0,   114,   211,   212,   214,   213,
     210,     0,     0,     0,     0,   114,     0,     0,     0,    60,
       0,    40,     0,     0,    62,     0,   153,   152,   151,   150,
     110,     0,     0,   106,   147,   146,   149,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   218,
     217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    13,    16,    15,    14,    19,   231,    17,     0,    65,
      65,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      81,    65,     0,    86,     0,   138,     0,     0,   137,   136,
       0,   194,   196,     0,    41,     0,     0,    44,     0,     0,
     200,     0,     0,    45,     0,    48,     0,   202,    69,   204,
      59,   203,     0,   139,   141,    61,   109,   108,   132,     0,
     163,   222,     0,   173,     0,   175,     0,   171,     0,   159,
       0,   167,     0,   169,     0,   161,     0,   191,     0,   193,
       0,   145,     0,   165,     0,   185,     0,   189,     0,   187,
       0,   155,     0,   157,     0,   177,     0,   179,     0,   183,
       0,   181,     0,     0,     0,    65,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    20,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,    56,    58,    57,    50,    51,    52,    53,
      55,    54,   135,     0,     0,    63,     0,    83,   133,   140,
       0,    42,     0,   104,    66,   106,    43,    46,    67,    47,
     134,     0,   162,   172,   174,   170,   158,   166,   168,   160,
     190,   192,   144,     0,   164,   184,   188,   186,   154,   156,
     176,   178,   182,   180,     0,     0,    85,    80,     0,     0,
      29,    30,    34,     0,     0,    35,    39,     0,    38,     0,
       0,     0,     0,     0,    11,     0,    89,    90,    95,     0,
      65,    96,    93,     0,     0,    65,     0,     0,    65,    65,
      82,     0,   105,   125,   143,   142,   130,   131,     0,   127,
     128,     0,    33,     0,    37,   103,     0,     0,     0,    65,
      12,     0,    65,    92,     0,     0,     0,     0,     0,     0,
      88,    84,   129,   126,     0,    32,    65,    65,    65,     0,
      18,    91,    65,    65,    99,    65,    65,    97,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,   101,   100,   102,    98,    25,    28,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -386,  -386,  -386,   351,  -386,  -386,  -302,  -386,  -386,  -386,
     164,  -386,   295,  -234,  -386,  -385,  -386,   159,   359,    50,
    -386,  -386,  -386,  -386,   266,  -386,  -386,  -308,    54,  -386,
    -386,  -386,    37,   840,  -386,  -386,  -386,   292,   468,  -386,
    -386,  -386,   193,   261,   196,   -71,  -386,  -386,   -91,   161,
     322,  1119,  -386,  -386,  -386,  -386,    -5,  -386,    -9,  -386,
       0,  -386
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,    22,    23,    24,   190,   191,    25,   318,    83,
      84,    26,   187,   394,   433,   395,    27,    62,   218,   219,
      30,    31,    32,   109,   110,    33,    34,   325,   326,    35,
      36,    37,   152,   123,    64,    65,    66,    67,    68,    69,
      70,    71,    40,    41,    42,    43,   124,   134,   204,   183,
      44,   262,    72,    73,    74,    75,    76,    86,    45,    46,
      77,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   206,    85,   202,    78,    79,    80,    87,   434,   192,
     401,    91,   141,   197,   404,    95,   392,   322,   412,    11,
      92,   234,    47,   150,   314,    11,   243,    13,    11,   202,
      13,   333,   203,   136,   392,   334,   335,   336,   337,   338,
     125,   181,   135,    11,   137,    11,    11,    13,    13,    50,
      29,   182,   339,   138,   340,   341,   354,   111,   205,   112,
      49,    11,    12,   356,    14,    93,   358,    50,    51,   468,
     359,   193,    29,   442,   323,   324,   113,   122,   114,   133,
     194,   402,   432,   140,   393,   145,    82,    52,    53,    54,
      55,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     412,   440,   393,   198,    56,    57,   142,    47,   143,   105,
     146,   235,   225,   105,   229,   315,   235,    58,   233,    59,
     232,   235,    60,    61,   186,   235,   235,   235,   235,   235,
     196,   241,   403,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   235,   254,   235,   235,   235,    49,    11,    12,
     195,    14,   235,   235,    50,    51,   235,   258,   220,    28,
     235,   236,   239,   235,   235,   248,   437,   438,    11,   423,
      13,   244,   246,   235,    52,    53,    54,    55,   426,   247,
      81,    28,   178,   179,   180,   181,   232,   235,   150,   182,
     250,    56,    57,    85,   327,   182,   330,   235,    87,    47,
      47,   249,   429,   328,    58,   331,    59,   235,   235,    60,
      61,   306,   452,   453,    11,    12,    11,    14,    47,   305,
     235,    47,    50,   255,   312,    49,    11,    12,   120,    14,
     313,   390,    50,    51,   316,   131,   413,   414,   391,   416,
     417,   396,   317,   454,   396,   192,   455,    11,    12,    13,
      14,   111,    52,    53,    54,    55,   347,   166,   167,    82,
     176,   177,   178,   179,   180,   181,    28,   350,   345,    56,
      57,   351,   188,   227,   186,   182,   106,   107,   108,   227,
     323,   324,    58,   242,    59,   166,   167,    60,    61,   185,
     227,   143,    38,   106,   221,   222,   361,    11,    12,    13,
      14,   357,   227,   397,   309,    47,   397,   193,   323,   324,
     411,   142,   398,   143,    38,   398,   194,   387,    47,   400,
      47,    47,   396,   176,   177,   178,   179,   180,   181,   396,
     396,   399,   192,   251,   410,   202,   419,   420,   182,   435,
     384,   436,   439,   451,   388,   227,    47,   456,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   457,    28,    28,
     409,   458,   319,   166,   167,   460,   182,   480,   485,   486,
     345,   345,   487,    94,   189,   223,   408,    28,   343,   310,
      28,   231,   311,   396,   397,   184,    47,     0,     0,     0,
       0,   397,   397,   398,   193,     0,   345,     0,     0,    38,
     398,   398,     0,   194,     0,    47,   228,     0,     0,     0,
      47,     0,   230,     0,     0,    47,   166,   167,    47,    47,
       0,     0,   428,   240,     0,     0,   431,   174,   175,   176,
     177,   178,   179,   180,   181,   253,   345,     0,     0,    47,
       0,     0,    47,    47,   182,   397,    47,     0,     0,    47,
      47,     0,     0,     0,   398,   345,    47,    47,    47,    47,
       0,    47,    47,    47,    28,    47,    47,     0,    39,    47,
      47,    47,     0,    47,    47,    47,    47,    28,    38,    28,
      28,   175,   176,   177,   178,   179,   180,   181,     0,     0,
      39,    38,    38,   345,     0,     0,   345,   182,     0,   345,
     345,     0,     0,     0,     0,    28,     0,     0,     0,   345,
      38,   345,     0,    38,     0,     0,     0,     0,     0,   345,
     345,   345,     0,   345,   345,   345,   345,    49,    11,    12,
       0,    14,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,   320,   321,
       0,     0,     0,     0,    28,     0,     0,     0,     0,    28,
       0,    56,    57,     0,    28,    39,     0,    28,    28,     0,
     346,     0,     0,     0,    58,   139,    59,     0,    39,    60,
      61,     0,     0,     0,     0,     0,     0,    38,    28,     0,
       0,    28,    28,     0,     0,    28,     0,     0,    28,    28,
      38,     0,    38,    38,     0,    28,    28,    28,    28,     0,
      28,    28,    28,     0,    28,    28,     0,     0,    28,    28,
      28,     0,    28,    28,    28,    28,     0,   256,    38,     0,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     164,   165,   166,   167,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   386,     0,     0,    39,    39,     0,
       0,     0,     0,     0,     0,     0,     0,   405,    38,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,    38,     0,     0,     0,     0,    38,     0,     0,
      38,    38,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,    38,   257,   182,    38,    38,     0,     0,    38,     0,
       0,    38,    38,     0,     0,     0,   148,     0,    38,    38,
      38,    38,     0,    38,    38,    38,     0,    38,    38,     0,
       0,    38,    38,    38,     0,    38,    38,    38,    38,   443,
       0,     0,     0,    39,   446,     0,     0,   449,   450,     0,
       0,     0,     0,    49,    11,    12,    39,    14,    39,    39,
      50,    51,     0,     0,     0,     0,     0,     0,   459,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    39,   469,   470,   471,     0,     0,
       0,   473,   474,     0,   475,   476,     0,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    59,    63,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,    39,    88,    89,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    39,     0,     0,    39,    39,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   149,   151,   153,
     155,   157,     0,     0,     0,     0,     0,    39,     0,     0,
      39,    39,     0,     0,    39,     0,     0,    39,    39,   260,
       0,   261,     0,     0,    39,    39,    39,    39,     0,    39,
      39,    39,     0,    39,    39,     0,     0,    39,    39,    39,
       0,    39,    39,    39,    39,   216,   217,     0,     0,     0,
       0,   224,     0,   226,     0,     0,  -223,  -223,  -223,     0,
    -223,   151,     0,  -223,  -223,     0,     0,     0,     0,     0,
       0,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,  -223,  -223,  -223,  -223,     0,     0,   263,
       0,   261,     0,     0,     0,     0,     0,     0,   150,     0,
    -223,  -223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,  -223,     0,  -223,     0,     0,  -223,  -223,
       0,     0,   304,     0,     0,   308,  -223,  -223,  -223,     0,
    -223,     0,     0,  -223,  -223,    49,    11,    12,     0,    14,
       0,     0,    50,    51,   329,     0,   332,     0,     0,     0,
       0,     0,     0,  -223,  -223,  -223,  -223,     0,     0,     0,
       0,     0,    52,    53,    54,    55,     0,     0,     0,     0,
    -223,  -223,     0,     0,     0,   353,     0,     0,   355,    56,
      57,     0,     0,  -223,     0,  -223,     0,     0,  -223,  -223,
       0,     0,    58,     0,    59,     0,     0,    60,    61,     0,
       0,     0,   362,     0,   363,     0,   364,   265,   365,   261,
     366,     0,   367,     0,   368,     0,   369,     0,   370,     0,
     371,     0,     0,     0,   374,     0,   375,     0,   376,     0,
     377,     0,   378,     0,   379,     0,   380,     0,   381,     0,
     382,     0,   383,     0,  -223,  -223,  -223,     0,  -223,     0,
       0,  -223,  -223,   372,     0,     0,   158,   159,   160,   161,
     162,   163,     0,     0,     0,     0,   164,   165,   166,   167,
       0,  -223,  -223,  -223,  -223,     0,     0,   267,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,  -223,  -223,
     252,     0,   422,     0,     0,     0,     0,     0,     0,     0,
       0,  -223,     0,  -223,     0,     0,  -223,  -223,     0,     0,
       0,     0,     0,   425,  -223,  -223,  -223,     0,  -223,     0,
       0,  -223,  -223,   269,     0,   261,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,  -223,  -223,  -223,  -223,     0,   373,     0,     0,   182,
       0,     0,     0,   444,   445,     0,   447,   448,  -223,  -223,
    -223,  -223,  -223,     0,  -223,     0,     0,  -223,  -223,     0,
     271,  -223,   261,  -223,     0,     0,  -223,  -223,   264,   266,
     268,   270,   272,   274,   276,   278,   280,  -223,  -223,  -223,
    -223,   284,   286,   288,   290,   292,   294,   296,   298,   300,
     302,     0,     0,     0,  -223,  -223,     0,  -223,  -223,  -223,
       0,  -223,     0,     0,  -223,  -223,   273,  -223,   261,  -223,
       0,     0,  -223,  -223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -223,  -223,  -223,  -223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -223,  -223,  -223,  -223,  -223,     0,  -223,     0,     0,
    -223,  -223,     0,   275,  -223,   261,  -223,     0,     0,  -223,
    -223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -223,  -223,  -223,  -223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -223,  -223,     0,
    -223,  -223,  -223,     0,  -223,     0,     0,  -223,  -223,   277,
    -223,   261,  -223,     0,     0,  -223,  -223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -223,  -223,  -223,
    -223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -223,  -223,  -223,  -223,  -223,     0,
    -223,     0,     0,  -223,  -223,     0,   279,  -223,   261,  -223,
       0,     0,  -223,  -223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -223,  -223,  -223,  -223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -223,  -223,     0,  -223,  -223,  -223,     0,  -223,     0,     0,
    -223,  -223,   283,  -223,   261,  -223,     0,     0,  -223,  -223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -223,  -223,  -223,  -223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -223,  -223,  -223,
    -223,  -223,     0,  -223,     0,     0,  -223,  -223,     0,   285,
    -223,   261,  -223,     0,     0,  -223,  -223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -223,  -223,  -223,  -223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -223,  -223,     0,  -223,  -223,  -223,     0,
    -223,     0,     0,  -223,  -223,   287,  -223,   261,  -223,     0,
       0,  -223,  -223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -223,  -223,  -223,  -223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -223,  -223,  -223,  -223,  -223,     0,  -223,     0,     0,  -223,
    -223,     0,   289,  -223,   261,  -223,     0,     0,  -223,  -223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -223,
    -223,  -223,  -223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -223,  -223,     0,  -223,
    -223,  -223,     0,  -223,     0,     0,  -223,  -223,   291,  -223,
     261,  -223,     0,     0,  -223,  -223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -223,  -223,  -223,  -223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -223,  -223,  -223,  -223,  -223,     0,  -223,
       0,     0,  -223,  -223,     0,   293,  -223,   261,  -223,     0,
       0,  -223,  -223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -223,  -223,  -223,  -223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -223,
    -223,     0,  -223,  -223,  -223,     0,  -223,     0,     0,  -223,
    -223,   295,  -223,   261,  -223,     0,     0,  -223,  -223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -223,
    -223,  -223,  -223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -223,  -223,  -223,  -223,
    -223,     0,  -223,     0,     0,  -223,  -223,     0,   297,  -223,
     261,  -223,     0,     0,  -223,  -223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -223,  -223,  -223,  -223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -223,  -223,     0,  -223,  -223,  -223,     0,  -223,
       0,     0,  -223,  -223,   299,  -223,   261,  -223,     0,     0,
    -223,  -223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -223,  -223,  -223,  -223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -223,
    -223,  -223,  -223,  -223,     0,  -223,     0,     0,  -223,  -223,
       0,   301,  -223,   261,  -223,     0,     0,  -223,  -223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -223,  -223,
    -223,  -223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -223,  -223,     0,  -223,  -223,
    -223,     0,  -223,     0,     0,  -223,  -223,   154,  -223,     0,
    -223,     0,     0,  -223,  -223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -223,  -223,  -223,  -223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -223,  -223,    49,    11,    12,     0,    14,     0,
       0,    50,    51,   156,     0,  -223,     0,  -223,     0,     0,
    -223,  -223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      49,    11,    12,     0,    14,     0,     0,    50,    51,   281,
       0,    58,     0,    59,     0,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    49,    11,    12,     0,
      14,     0,     0,    50,    51,   424,     0,    58,     0,    59,
       0,     0,    60,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    49,    11,    12,     0,    14,     0,     0,    50,
      51,     0,     0,    58,   237,    59,     0,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,    49,
      11,    12,     0,    14,     0,     0,    50,    51,     0,    58,
     245,    59,     0,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    49,    11,    12,     0,    14,
       0,     0,    50,    51,     0,     0,    58,   352,   238,     0,
     143,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,     0,    49,    11,    12,     0,    14,     0,     0,    50,
      51,     0,    58,     0,   238,     0,   143,    60,    61,     0,
       0,     0,     0,   158,   159,   160,   161,   162,   163,    52,
      53,    54,    55,   164,   165,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,     0,     0,    60,    61,   158,   159,   160,   161,
     162,   163,     0,     0,     0,     0,   164,   165,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,   389,     0,     0,   182,   360,   201,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,   164,
     165,   166,   167,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,   389,     0,     0,   182,
     360,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,   164,   165,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   158,   159,   160,   161,   162,   163,     0,
       0,     0,   182,   164,   165,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,   158,   159,   160,   161,
     162,   163,     0,     0,   182,   342,   164,   165,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,   158,   159,
     160,   161,   162,   163,     0,     0,   182,   348,   164,   165,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
     349,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,   164,   165,   166,   167,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     8,     9,    10,     0,     0,     0,     0,     0,
       0,   182,   360,     0,   168,   169,   170,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,   164,   165,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,     0,     0,
     168,   169,   170,     0,   182,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,   164,   165,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   158,   159,   160,   161,   162,   163,     0,     0,     0,
     182,   164,   165,   166,   167,     0,   199,     0,     0,     0,
       0,     0,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   164,   165,   166,   167,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,     0,
       0,     0,   200,     0,     0,     0,     0,     0,   182,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,   164,
     165,   166,   167,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,     0,     0,   259,     0,
       0,     0,     0,     0,   182,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   158,   159,   160,   161,
     162,   163,     0,     0,     0,   182,   164,   165,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   158,   159,   160,   161,   162,   163,   385,
       0,     0,   182,   164,   165,   166,   167,   415,     0,     0,
       0,     0,     0,     0,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,   164,   165,   166,   167,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
       0,     0,     0,     0,   418,     0,     0,     0,     0,   182,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     164,   165,   166,   167,     0,   462,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,   463,     0,     0,     0,     0,     0,   182,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,   164,   165,
     166,   167,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   182,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,   164,   165,   166,   167,     0,   465,
       0,     0,     0,     0,     0,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,   164,   165,   166,   167,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     0,   158,     0,   466,   161,   162,   163,     0,
       0,   182,     0,   164,   165,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   115,
     116,   117,   118,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    49,    11,    12,
       0,    14,     0,     0,    50,    51,   182,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,   128,   129,     0,
       0,     0,     0,     0,    52,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
       0,    56,    57,    49,    11,    12,     0,    14,     0,     0,
      50,    51,   120,     0,   121,     0,    59,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,     0,     0,     0,    56,    57,    49,
      11,    12,     0,    14,     0,     0,    50,    51,   131,     0,
     132,     0,    59,     0,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    11,
      12,     0,    14,    56,    57,    50,    51,    49,    11,    12,
       0,    14,     0,     0,    50,    51,    58,   144,    59,     0,
       0,    60,    61,     0,     0,    52,    53,    54,    55,     0,
       0,     0,     0,     0,    52,    53,    54,    55,     0,     0,
       0,     0,    56,    57,     0,     0,    49,    11,    12,     0,
      14,    56,    57,    50,    51,    58,     0,    59,   251,     0,
      60,    61,     0,   303,    58,     0,    59,     0,     0,    60,
      61,     0,     0,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    11,    12,     0,    14,
      56,    57,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,   307,    58,     0,    59,     0,     0,    60,    61,
       0,     0,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    11,    12,     0,    14,    56,
      57,    50,    51,    49,    11,    12,     0,    14,     0,     0,
      50,    51,    58,     0,    59,   427,     0,    60,    61,     0,
       0,    52,    53,    54,    55,     0,     0,     0,     0,     0,
      52,    53,    54,    55,     0,     0,     0,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,    56,    57,     0,
       0,    58,     1,    59,   430,     0,    60,    61,     0,     0,
      58,     0,    59,     0,     0,    60,    61,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     6,     7,     0,     8,     9,    10,     0,    11,    12,
      13,    14,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     0,     0,    17,    18,    19,     8,
       9,    10,    20,    11,    12,    13,    14,     0,     0,     1,
       0,     0,     0,     0,     0,     0,   344,    15,    16,     0,
       0,    17,    18,    19,     2,     3,     0,    20,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     8,     9,    10,     0,    11,    12,    13,    14,     2,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,   406,    17,    18,    19,     8,     9,    10,    20,
      11,    12,    13,    14,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,    15,    16,     0,   407,    17,    18,
      19,     2,     3,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     8,     9,
      10,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     2,     3,     0,     0,   421,    15,    16,     0,     0,
      17,    18,    19,     0,     0,     1,    20,   441,     8,     9,
      10,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,    15,    16,     0,     0,
      17,    18,    19,     0,     1,     0,    20,     8,     9,    10,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,    15,    16,     0,   464,    17,
      18,    19,     0,     1,     0,    20,     8,     9,    10,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     2,     3,
       0,     0,     0,   472,    15,    16,     0,   467,    17,    18,
      19,     0,     1,     0,    20,     8,     9,    10,     0,    11,
      12,    13,    14,     0,     0,     0,     0,     2,     3,     0,
       0,     0,   477,    15,    16,     0,     0,    17,    18,    19,
       0,     1,     0,    20,     8,     9,    10,     0,    11,    12,
      13,    14,     0,     0,     0,     0,     2,     3,     0,     0,
       0,   478,    15,    16,     0,     0,    17,    18,    19,     0,
       1,     0,    20,     8,     9,    10,     0,    11,    12,    13,
      14,     0,     0,     0,     0,     2,     3,     0,     0,     0,
     479,    15,    16,     0,     0,    17,    18,    19,     0,     1,
       0,    20,     8,     9,    10,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
      15,    16,     0,     0,    17,    18,    19,     0,     1,     0,
      20,     8,     9,    10,     0,    11,    12,    13,    14,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,    15,
      16,     0,   481,    17,    18,    19,     0,     1,     0,    20,
       8,     9,    10,     0,    11,    12,    13,    14,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,    15,    16,
       0,   482,    17,    18,    19,     0,     1,     0,    20,     8,
       9,    10,     0,    11,    12,    13,    14,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,    15,    16,     0,
     483,    17,    18,    19,     0,     1,     0,    20,     8,     9,
      10,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,    15,    16,     0,   484,
      17,    18,    19,     0,     0,     0,    20,     8,     9,    10,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,     0,    17,
      18,    19,     0,     0,     0,    20
};

static const yytype_int16 yycheck[] =
{
       0,    92,     7,    64,     4,     5,     6,     7,   393,    80,
       3,    20,     3,     3,   316,     3,    27,     3,   326,    39,
      20,     3,    22,     1,     3,    39,     3,    41,    39,    64,
      41,     3,    93,    97,    27,     3,     3,     3,     3,     3,
      40,    87,    42,    39,    44,    39,    39,    41,    41,    45,
       0,    97,     3,    97,     3,     3,     3,    97,    93,    99,
      38,    39,    40,     3,    42,     0,     3,    45,    46,   454,
       3,    80,    22,     3,    60,    61,    97,    40,    99,    42,
      80,   315,    96,    46,    95,    48,    82,    65,    66,    67,
      68,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     408,   403,    95,    93,    82,    83,    97,   107,    99,    97,
       1,    93,   112,    97,   114,    94,    93,    95,    96,    97,
     120,    93,   100,   101,    95,    93,    93,    93,    93,    93,
      39,   131,     3,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    93,   143,    93,    93,    93,    38,    39,    40,
       1,    42,    93,    93,    45,    46,    93,    98,     3,     0,
      93,   124,   125,    93,    93,     3,   400,   401,    39,    98,
      41,   134,   135,    93,    65,    66,    67,    68,    98,    98,
       3,    22,    84,    85,    86,    87,   186,    93,     1,    97,
      96,    82,    83,   198,   203,    97,   205,    93,   198,   199,
     200,    98,    98,   203,    95,   205,    97,    93,    93,   100,
     101,    39,    98,    98,    39,    40,    39,    42,   218,     3,
      93,   221,    45,    96,    94,    38,    39,    40,    93,    42,
      26,    96,    45,    46,    93,    93,   327,   328,    96,   330,
     331,   312,    97,    93,   315,   316,    96,    39,    40,    41,
      42,    97,    65,    66,    67,    68,     3,    16,    17,    82,
      82,    83,    84,    85,    86,    87,   107,    97,   218,    82,
      83,     3,    93,   114,    95,    97,    50,    51,    52,   120,
      60,    61,    95,    96,    97,    16,    17,   100,   101,    97,
     131,    99,     0,    50,    51,    52,   259,    39,    40,    41,
      42,     3,   143,   312,    96,   305,   315,   316,    60,    61,
      62,    97,   312,    99,    22,   315,   316,     3,   318,    94,
     320,   321,   393,    82,    83,    84,    85,    86,    87,   400,
     401,    93,   403,    98,     3,    64,     3,     3,    97,     3,
     303,    26,     3,     3,   307,   186,   346,     3,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     3,   199,   200,
     323,     3,   198,    16,    17,     3,    97,     3,     3,     3,
     320,   321,     3,    22,    79,   109,   322,   218,   217,   186,
     221,   120,   186,   454,   393,    63,   386,    -1,    -1,    -1,
      -1,   400,   401,   393,   403,    -1,   346,    -1,    -1,   107,
     400,   401,    -1,   403,    -1,   405,   114,    -1,    -1,    -1,
     410,    -1,   120,    -1,    -1,   415,    16,    17,   418,   419,
      -1,    -1,   385,   131,    -1,    -1,   389,    80,    81,    82,
      83,    84,    85,    86,    87,   143,   386,    -1,    -1,   439,
      -1,    -1,   442,   443,    97,   454,   446,    -1,    -1,   449,
     450,    -1,    -1,    -1,   454,   405,   456,   457,   458,   459,
      -1,   461,   462,   463,   305,   465,   466,    -1,     0,   469,
     470,   471,    -1,   473,   474,   475,   476,   318,   186,   320,
     321,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      22,   199,   200,   443,    -1,    -1,   446,    97,    -1,   449,
     450,    -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,   459,
     218,   461,    -1,   221,    -1,    -1,    -1,    -1,    -1,   469,
     470,   471,    -1,   473,   474,   475,   476,    38,    39,    40,
      -1,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,   199,   200,
      -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,   410,
      -1,    82,    83,    -1,   415,   107,    -1,   418,   419,    -1,
     221,    -1,    -1,    -1,    95,    96,    97,    -1,   120,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   305,   439,    -1,
      -1,   442,   443,    -1,    -1,   446,    -1,    -1,   449,   450,
     318,    -1,   320,   321,    -1,   456,   457,   458,   459,    -1,
     461,   462,   463,    -1,   465,   466,    -1,    -1,   469,   470,
     471,    -1,   473,   474,   475,   476,    -1,     1,   346,    -1,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   305,    -1,    -1,   199,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    -1,    -1,   415,    -1,    -1,
     418,   419,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,    96,    97,   442,   443,    -1,    -1,   446,    -1,
      -1,   449,   450,    -1,    -1,    -1,     1,    -1,   456,   457,
     458,   459,    -1,   461,   462,   463,    -1,   465,   466,    -1,
      -1,   469,   470,   471,    -1,   473,   474,   475,   476,   410,
      -1,    -1,    -1,   305,   415,    -1,    -1,   418,   419,    -1,
      -1,    -1,    -1,    38,    39,    40,   318,    42,   320,   321,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,   346,   456,   457,   458,    -1,    -1,
      -1,   462,   463,    -1,   465,   466,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    97,     3,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   386,    15,    16,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,   410,    -1,
      -1,    -1,    -1,   415,    -1,    -1,   418,   419,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,   439,    -1,    -1,
     442,   443,    -1,    -1,   446,    -1,    -1,   449,   450,     1,
      -1,     3,    -1,    -1,   456,   457,   458,   459,    -1,   461,
     462,   463,    -1,   465,   466,    -1,    -1,   469,   470,   471,
      -1,   473,   474,   475,   476,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,   113,    -1,    -1,    38,    39,    40,    -1,
      42,   121,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    65,    66,    67,    68,    -1,    -1,     1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    95,    -1,    97,    -1,    -1,   100,   101,
      -1,    -1,   182,    -1,    -1,   185,    38,    39,    40,    -1,
      42,    -1,    -1,    45,    46,    38,    39,    40,    -1,    42,
      -1,    -1,    45,    46,   204,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,   235,    -1,    -1,   238,    82,
      83,    -1,    -1,    95,    -1,    97,    -1,    -1,   100,   101,
      -1,    -1,    95,    -1,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,   262,    -1,   264,    -1,   266,     1,   268,     3,
     270,    -1,   272,    -1,   274,    -1,   276,    -1,   278,    -1,
     280,    -1,    -1,    -1,   284,    -1,   286,    -1,   288,    -1,
     290,    -1,   292,    -1,   294,    -1,   296,    -1,   298,    -1,
     300,    -1,   302,    -1,    38,    39,    40,    -1,    42,    -1,
      -1,    45,    46,     1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      -1,    65,    66,    67,    68,    -1,    -1,     1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
     350,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,   373,    38,    39,    40,    -1,    42,    -1,
      -1,    45,    46,     1,    -1,     3,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    65,    66,    67,    68,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   413,   414,    -1,   416,   417,    82,    83,
      38,    39,    40,    -1,    42,    -1,    -1,    45,    46,    -1,
       1,    95,     3,    97,    -1,    -1,   100,   101,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    65,    66,    67,
      68,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    82,    83,    -1,    38,    39,    40,
      -1,    42,    -1,    -1,    45,    46,     1,    95,     3,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    46,    -1,     1,    95,     3,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      38,    39,    40,    -1,    42,    -1,    -1,    45,    46,     1,
      95,     3,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    38,    39,    40,    -1,
      42,    -1,    -1,    45,    46,    -1,     1,    95,     3,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    46,     1,    95,     3,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    38,
      39,    40,    -1,    42,    -1,    -1,    45,    46,    -1,     1,
      95,     3,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    38,    39,    40,    -1,
      42,    -1,    -1,    45,    46,     1,    95,     3,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    38,    39,    40,    -1,    42,    -1,    -1,    45,
      46,    -1,     1,    95,     3,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    38,
      39,    40,    -1,    42,    -1,    -1,    45,    46,     1,    95,
       3,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    38,    39,    40,    -1,    42,
      -1,    -1,    45,    46,    -1,     1,    95,     3,    97,    -1,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    38,    39,    40,    -1,    42,    -1,    -1,    45,
      46,     1,    95,     3,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    38,    39,
      40,    -1,    42,    -1,    -1,    45,    46,    -1,     1,    95,
       3,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    -1,    38,    39,    40,    -1,    42,
      -1,    -1,    45,    46,     1,    95,     3,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    38,    39,    40,    -1,    42,    -1,    -1,    45,    46,
      -1,     1,    95,     3,    97,    -1,    -1,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    38,    39,
      40,    -1,    42,    -1,    -1,    45,    46,     1,    95,    -1,
      97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    38,    39,    40,    -1,    42,    -1,
      -1,    45,    46,     1,    -1,    95,    -1,    97,    -1,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      38,    39,    40,    -1,    42,    -1,    -1,    45,    46,     1,
      -1,    95,    -1,    97,    -1,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    38,    39,    40,    -1,
      42,    -1,    -1,    45,    46,     1,    -1,    95,    -1,    97,
      -1,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    38,    39,    40,    -1,    42,    -1,    -1,    45,
      46,    -1,    -1,    95,     3,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    38,
      39,    40,    -1,    42,    -1,    -1,    45,    46,    -1,    95,
       3,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    38,    39,    40,    -1,    42,
      -1,    -1,    45,    46,    -1,    -1,    95,     3,    97,    -1,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    -1,    38,    39,    40,    -1,    42,    -1,    -1,    45,
      46,    -1,    95,    -1,    97,    -1,    99,   100,   101,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    65,
      66,    67,    68,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    97,    -1,    -1,   100,   101,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    97,    98,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      98,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    97,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    97,    98,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,     4,     5,
       6,     7,     8,     9,    -1,    -1,    97,    98,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    47,    48,    49,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    97,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      97,    14,    15,    16,    17,    -1,    55,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    97,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    97,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    97,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     4,     5,     6,     7,     8,     9,    94,
      -1,    -1,    97,    14,    15,    16,    17,    55,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    97,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    -1,    55,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    97,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,    55,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,     4,    -1,    55,     7,     8,     9,    -1,
      -1,    97,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    38,    39,    40,
      -1,    42,    -1,    -1,    45,    46,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    83,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    46,    93,    -1,    95,    -1,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    83,    38,
      39,    40,    -1,    42,    -1,    -1,    45,    46,    93,    -1,
      95,    -1,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    42,    82,    83,    45,    46,    38,    39,    40,
      -1,    42,    -1,    -1,    45,    46,    95,    96,    97,    -1,
      -1,   100,   101,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    38,    39,    40,    -1,
      42,    82,    83,    45,    46,    95,    -1,    97,    98,    -1,
     100,   101,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
     101,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      82,    83,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    -1,    -1,   100,   101,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    42,    82,
      83,    45,    46,    38,    39,    40,    -1,    42,    -1,    -1,
      45,    46,    95,    -1,    97,    98,    -1,   100,   101,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    95,     3,    97,    98,    -1,   100,   101,    -1,    -1,
      95,    -1,    97,    -1,    -1,   100,   101,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    32,    33,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    58,    59,    35,
      36,    37,    63,    39,    40,    41,    42,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,
      -1,    57,    58,    59,    18,    19,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    39,    40,    41,    42,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    35,    36,    37,    63,
      39,    40,    41,    42,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    56,    57,    58,
      59,    18,    19,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    52,    53,    54,    -1,    -1,
      57,    58,    59,    -1,    -1,     3,    63,    34,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    58,    59,    -1,     3,    -1,    63,    35,    36,    37,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    53,    54,    -1,    56,    57,
      58,    59,    -1,     3,    -1,    63,    35,    36,    37,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    53,    54,    -1,    56,    57,    58,
      59,    -1,     3,    -1,    63,    35,    36,    37,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    23,    53,    54,    -1,    -1,    57,    58,    59,
      -1,     3,    -1,    63,    35,    36,    37,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    23,    53,    54,    -1,    -1,    57,    58,    59,    -1,
       3,    -1,    63,    35,    36,    37,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    53,    54,    -1,    -1,    57,    58,    59,    -1,     3,
      -1,    63,    35,    36,    37,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    57,    58,    59,    -1,     3,    -1,
      63,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    53,
      54,    -1,    56,    57,    58,    59,    -1,     3,    -1,    63,
      35,    36,    37,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    53,    54,
      -1,    56,    57,    58,    59,    -1,     3,    -1,    63,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    53,    54,    -1,
      56,    57,    58,    59,    -1,     3,    -1,    63,    35,    36,
      37,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    53,    54,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    63,    35,    36,    37,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,
      58,    59,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    18,    19,    20,    22,    32,    33,    35,    36,
      37,    39,    40,    41,    42,    53,    54,    57,    58,    59,
      63,   103,   104,   105,   106,   109,   113,   118,   119,   121,
     122,   123,   124,   127,   128,   131,   132,   133,   139,   140,
     144,   145,   146,   147,   152,   160,   161,   162,   163,    38,
      45,    46,    65,    66,    67,    68,    82,    83,    95,    97,
     100,   101,   119,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   154,   155,   156,   157,   158,   162,   162,   162,
     162,     3,    82,   111,   112,   158,   159,   162,   135,   135,
     135,   160,   162,     0,   105,     3,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    97,    50,    51,    52,   125,
     126,    97,    99,    97,    99,    10,    11,    12,    13,    78,
      93,    95,   134,   135,   148,   162,    10,    11,    12,    13,
      78,    93,    95,   134,   149,   162,    97,   162,    97,    96,
     134,     3,    97,    99,    96,   134,     1,   135,     1,   135,
       1,   135,   134,   135,     1,   135,     1,   135,     4,     5,
       6,     7,     8,     9,    14,    15,    16,    17,    47,    48,
      49,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    97,   151,   152,    97,    95,   114,    93,   114,
     107,   108,   147,   160,   162,     1,    39,     3,    93,    55,
      55,     3,    64,    93,   150,    93,   150,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   120,   121,
       3,    51,    52,   126,   135,   162,   135,   119,   139,   162,
     139,   145,   162,    96,     3,    93,   134,     3,    97,   134,
     139,   162,    96,     3,   134,     3,   134,    98,     3,    98,
      96,    98,   135,   139,   162,    96,     1,    96,    98,    70,
       1,     3,   153,     1,   153,     1,   153,     1,   153,     1,
     153,     1,   153,     1,   153,     1,   153,     1,   153,     1,
     153,     1,   135,     1,   153,     1,   153,     1,   153,     1,
     153,     1,   153,     1,   153,     1,   153,     1,   153,     1,
     153,     1,   153,    94,   135,     3,    39,    94,   135,    96,
     144,   146,    94,    26,     3,    94,    93,    97,   110,   112,
     120,   120,     3,    60,    61,   129,   130,   160,   162,   135,
     160,   162,   135,     3,     3,     3,     3,     3,     3,     3,
       3,     3,    98,   151,    52,   121,   120,     3,    98,    98,
      97,     3,     3,   135,     3,   135,     3,     3,     3,     3,
      98,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,     1,    94,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   134,    94,   120,     3,   134,    94,
      96,    96,    27,    95,   115,   117,   147,   160,   162,    93,
      94,     3,   115,     3,   108,   120,    56,    56,   130,   134,
       3,    62,   129,   150,   150,    55,   150,   150,    55,     3,
       3,    52,   135,    98,     1,   135,    98,    98,   134,    98,
      98,   134,    96,   116,   117,     3,    26,   115,   115,     3,
     108,    34,     3,   120,   135,   135,   120,   135,   135,   120,
     120,     3,    98,    98,    93,    96,     3,     3,     3,   120,
       3,   120,    55,    55,    56,    55,    55,    56,   117,   120,
     120,   120,    23,   120,   120,   120,   120,    23,    23,    23,
       3,    56,    56,    56,    56,     3,     3,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     106,   107,   107,   107,   108,   108,   108,   110,   109,   109,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   120,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   123,   123,   123,   123,   124,   125,   125,   126,   127,
     128,   129,   129,   130,   130,   130,   131,   132,   132,   132,
     132,   132,   132,   133,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   137,   137,   137,   137,
     137,   137,   138,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   145,   145,   145,   145,
     146,   146,   147,   147,   147,   148,   148,   148,   148,   148,
     149,   149,   149,   149,   149,   150,   151,   151,   151,   152,
     152,   152,   153,   153,   154,   155,   155,   156,   156,   157,
     158,   159,   160,   161,   162,   163
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     1,     1,     1,     1,     0,     7,     3,
       3,     1,     1,     1,     1,    10,     9,    10,    10,     3,
       3,     2,     3,     2,     1,     1,     3,     1,     1,     1,
       2,     3,     4,     4,     3,     3,     4,     4,     3,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       2,     3,     2,     2,     1,     0,     4,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     5,     4,     6,     5,     2,     1,     5,     5,
       5,     4,     3,     2,     1,     2,     5,     7,     9,     7,
       9,     9,     9,     6,     3,     4,     1,     1,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     6,     5,     5,     6,
       5,     5,     3,     4,     4,     4,     3,     3,     3,     3,
       4,     3,     5,     5,     4,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
       4,     3,     4,     3,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (parm, scanner, csound, astTree, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parm, scanner, csound, astTree); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, PARSE_PARM *parm, void *scanner, CSOUND * csound, TREE ** astTree)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parm);
  YY_USE (scanner);
  YY_USE (csound);
  YY_USE (astTree);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, PARSE_PARM *parm, void *scanner, CSOUND * csound, TREE ** astTree)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parm, scanner, csound, astTree);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, PARSE_PARM *parm, void *scanner, CSOUND * csound, TREE ** astTree)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parm, scanner, csound, astTree);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parm, scanner, csound, astTree); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, PARSE_PARM *parm, void *scanner, CSOUND * csound, TREE ** astTree)
{
  YY_USE (yyvaluep);
  YY_USE (parm);
  YY_USE (scanner);
  YY_USE (csound);
  YY_USE (astTree);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (PARSE_PARM *parm, void *scanner, CSOUND * csound, TREE ** astTree)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, csound, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* orcfile: root_statement_list  */
#line 201 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
              if (yyvsp[0] != NULL)
                *astTree = ((TREE *)yyvsp[0]);
              csound->synterrcnt = csound_orcnerrs;
              if (csoundGetDebug(csound) & DEBUG_PARSER ||
		  csoundGetDebug(csound) & DEBUG_TREE)
                print_tree(csound, "ALL:\n", yyvsp[0]);
          }
#line 2623 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 3: /* root_statement_list: root_statement_list root_statement  */
#line 213 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                      { yyval = parser_append(csound, yyvsp[-1], yyvsp[0]); }
#line 2629 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 10: /* struct_definition: STRUCT_TOKEN identifier struct_arg_list  */
#line 227 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                  { yyval = make_node(csound,LINE,LOCN, STRUCT_TOKEN, yyvsp[-1], yyvsp[0]); }
#line 2635 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 11: /* struct_arg_list: struct_arg_list ',' struct_arg  */
#line 231 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 2641 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 12: /* struct_arg_list: struct_arg_list ',' NEWLINE struct_arg  */
#line 233 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                 { yyval = parser_append(csound, yyvsp[-3], yyvsp[0]); }
#line 2647 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 17: /* $@1: %empty  */
#line 242 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                    { csound_orcput_ilocn(scanner, LINE, LOCN); }
#line 2653 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 18: /* instr_definition: INSTR_TOKEN instr_id_list NEWLINE $@1 statement_list ENDIN_TOKEN NEWLINE  */
#line 244 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                  {  yyval = make_node(csound, (int32_t) csound_orcget_iline(scanner),
                                  csound_orcget_ilocn(scanner), INSTR_TOKEN,
                                  yyvsp[-5], yyvsp[-2]);
                    csp_orc_sa_instr_finalize(csound);
                 }
#line 2663 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 19: /* instr_definition: INSTR_TOKEN NEWLINE error  */
#line 250 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                 { csound->ErrorMsg(csound, Str("No number following instr\n"));
                  csp_orc_sa_instr_finalize(csound);
                  yyval = NULL;
                 }
#line 2672 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 20: /* instr_id_list: instr_id_list ',' instr_id  */
#line 258 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                  { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 2678 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 21: /* instr_id_list: instr_id  */
#line 259 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                          { csp_orc_sa_instr_add_tree(csound, yyvsp[0]);
                    add_instr_variable(csound, yyvsp[0]);
                }
#line 2686 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 25: /* udo_definition: UDOSTART_DEFINITION identifier ',' UDO_IDENT ',' UDO_IDENT NEWLINE statement_list UDOEND_TOKEN NEWLINE  */
#line 272 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              {
                TREE *udoTop = make_leaf(csound, LINE,LOCN, UDO_TOKEN,
                                         (ORCTOKEN *)NULL);
                TREE *ident = yyvsp[-8];
                TREE *udoAns = make_leaf(csound, LINE,LOCN, UDO_ANS_TOKEN,
                                         (ORCTOKEN *)yyvsp[-6]);
                TREE *udoArgs = make_leaf(csound, LINE,LOCN, UDO_ARGS_TOKEN,
                                          (ORCTOKEN *)yyvsp[-4]);
                if (UNLIKELY(PARSER_DEBUG))
                  csound->Message(csound, "UDO COMPLETE\n");

                udoTop->left = ident;
                ident->left = udoAns;
                ident->right = udoArgs;

                udoTop->right = (TREE *)yyvsp[-2];

                yyval = udoTop;

                if (UNLIKELY(PARSER_DEBUG))
                  print_tree(csound, "UDO\n", (TREE *)yyval);

              }
#line 2714 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 26: /* udo_definition: UDOSTART_DEFINITION identifier udo_arg_list ':' udo_out_arg_list NEWLINE statement_list UDOEND_TOKEN NEWLINE  */
#line 297 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              {
                TREE *udoTop = make_leaf(csound, LINE, LOCN, UDO_TOKEN,
                                        (ORCTOKEN*)NULL);
                yyval = udoTop;
                udoTop->left = yyvsp[-7];
                yyvsp[-7]->left = yyvsp[-4];
                yyvsp[-7]->right = yyvsp[-6];
                yyval->right = yyvsp[-2];
              }
#line 2728 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 27: /* udo_definition: UDOSTART_DEFINITION identifier udo_arg_list ':' NEWLINE udo_out_arg_list NEWLINE statement_list UDOEND_TOKEN NEWLINE  */
#line 308 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              {
                TREE *udoTop = make_leaf(csound, LINE, LOCN, UDO_TOKEN,
                                        (ORCTOKEN*)NULL);
                yyval = udoTop;
                udoTop->left = yyvsp[-8];
                yyvsp[-8]->left = yyvsp[-4];
                yyvsp[-8]->right = yyvsp[-7];
                yyval->right = yyvsp[-2];
              }
#line 2742 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 28: /* udo_definition: UDOSTART_DEFINITION identifier udo_arg_list NEWLINE ':' udo_out_arg_list NEWLINE statement_list UDOEND_TOKEN NEWLINE  */
#line 320 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              {
                TREE *udoTop = make_leaf(csound, LINE, LOCN, UDO_TOKEN,
                                        (ORCTOKEN*)NULL);
                yyval = udoTop;
                udoTop->left = yyvsp[-8];
                yyvsp[-8]->left = yyvsp[-4];
                yyvsp[-8]->right = yyvsp[-7];
                yyval->right = yyvsp[-2];
              }
#line 2756 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 29: /* udo_arg_list: '(' out_arg_list ')'  */
#line 333 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = yyvsp[-1];  }
#line 2762 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 30: /* udo_arg_list: '(' out_arg_list_array ')'  */
#line 335 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = yyvsp[-1];  }
#line 2768 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 31: /* udo_arg_list: '(' ')'  */
#line 337 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, "0", NULL)); }
#line 2774 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 32: /* udo_out_arg_list: '(' out_type_list ')'  */
#line 341 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = yyvsp[-1]; }
#line 2780 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 33: /* udo_out_arg_list: '(' ')'  */
#line 343 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, "0", NULL)); }
#line 2786 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 34: /* udo_out_arg_list: VOID_TOKEN  */
#line 345 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             { yyval = make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, "0", NULL)); }
#line 2792 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 36: /* out_type_list: out_type_list ',' out_type  */
#line 350 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 2798 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 40: /* opcall: identifier NEWLINE  */
#line 365 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-1];
          }
#line 2806 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 41: /* opcall: out_arg_list expr_list NEWLINE  */
#line 370 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-2];
            yyval->right = yyvsp[-1];
          }
#line 2815 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 42: /* opcall: out_arg_list '(' ')' NEWLINE  */
#line 375 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-3];
            /*$$->right = $2; */
          }
#line 2824 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 43: /* opcall: out_arg_list identifier expr_list NEWLINE  */
#line 380 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-2];
            yyvsp[-2]->type = T_OPCALL;
            yyvsp[-2]->left = yyvsp[-3];
            yyvsp[-2]->right = yyvsp[-1];
          }
#line 2835 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 44: /* opcall: out_arg_list identifier NEWLINE  */
#line 387 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            if (yyvsp[-1]->value != NULL && yyvsp[-1]->value->lexeme != NULL &&
                strcmp(yyvsp[-1]->value->lexeme, "init") == 0) {
              yyval->left = yyvsp[-1];
              yyvsp[-1]->type = T_OPCALL;
              yyvsp[-1]->left = yyvsp[-2];
            } else {
              yyval->left = yyvsp[-2];
              yyval->right = yyvsp[-1];
            }
          }
#line 2851 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 45: /* opcall: out_arg_list_array expr_list NEWLINE  */
#line 399 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-2];
            yyval->right = yyvsp[-1];
          }
#line 2860 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 46: /* opcall: out_arg_list_array '(' ')' NEWLINE  */
#line 404 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-3];
            /*$$->right = $2; */
          }
#line 2869 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 47: /* opcall: out_arg_list_array identifier expr_list NEWLINE  */
#line 409 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            yyval->left = yyvsp[-2];
            yyvsp[-2]->type = T_OPCALL;
            yyvsp[-2]->left = yyvsp[-3];
            yyvsp[-2]->right = yyvsp[-1];
          }
#line 2880 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 48: /* opcall: out_arg_list_array identifier NEWLINE  */
#line 416 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_leaf(csound, LINE,LOCN, T_OPCALL, NULL);
            if (yyvsp[-1]->value != NULL && yyvsp[-1]->value->lexeme != NULL &&
                strcmp(yyvsp[-1]->value->lexeme, "init") == 0) {
              yyval->left = yyvsp[-1];
              yyvsp[-1]->type = T_OPCALL;
              yyvsp[-1]->left = yyvsp[-2];
            } else {
              yyval->left = yyvsp[-2];
              yyval->right = yyvsp[-1];
            }
          }
#line 2896 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 49: /* opcall: function_call NEWLINE  */
#line 428 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = yyvsp[-1]; }
#line 2902 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 50: /* opcall: function_call '+' expr_list NEWLINE  */
#line 430 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '+', yyvsp[-3], yyvsp[-1]);  }
#line 2908 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 51: /* opcall: function_call '-' expr_list NEWLINE  */
#line 432 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '-', yyvsp[-3], yyvsp[-1]); }
#line 2914 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 52: /* opcall: function_call '*' expr_list NEWLINE  */
#line 434 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '*', yyvsp[-3], yyvsp[-1]); }
#line 2920 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 53: /* opcall: function_call '/' expr_list NEWLINE  */
#line 436 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '/', yyvsp[-3], yyvsp[-1]); }
#line 2926 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 54: /* opcall: function_call '^' expr_list NEWLINE  */
#line 438 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '^', yyvsp[-3], yyvsp[-1]); }
#line 2932 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 55: /* opcall: function_call '%' expr_list NEWLINE  */
#line 440 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '%', yyvsp[-3], yyvsp[-1]); }
#line 2938 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 56: /* opcall: function_call '|' expr_list NEWLINE  */
#line 442 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '|', yyvsp[-3], yyvsp[-1]); }
#line 2944 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 57: /* opcall: function_call '&' expr_list NEWLINE  */
#line 444 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '&', yyvsp[-3], yyvsp[-1]); }
#line 2950 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 58: /* opcall: function_call '#' expr_list NEWLINE  */
#line 446 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = make_opcall_from_func_start(csound, LINE, LOCN, '#', yyvsp[-3], yyvsp[-1]); }
#line 2956 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 59: /* function_call: typed_identifierb expr_list ')'  */
#line 450 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = yyvsp[-2];
                yyvsp[-2]->type = T_FUNCTION;
                yyvsp[-2]->right = yyvsp[-1]; }
#line 2964 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 60: /* function_call: typed_identifierb ')'  */
#line 454 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = yyvsp[-1];
                yyvsp[-1]->type = T_FUNCTION; }
#line 2971 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 61: /* function_call: identifierb expr_list ')'  */
#line 457 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = yyvsp[-2];
                yyvsp[-2]->type = T_FUNCTION;
                yyvsp[-2]->right = yyvsp[-1]; }
#line 2979 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 62: /* function_call: identifierb ')'  */
#line 461 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = yyvsp[-1];
                yyvsp[-1]->type = T_FUNCTION; }
#line 2986 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 63: /* statement_list: statement_list statement  */
#line 466 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                {
                    yyval = parser_append(csound, (TREE *)yyvsp[-1], (TREE *)yyvsp[0]);
                }
#line 2994 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 65: /* statement_list: %empty  */
#line 470 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                  {
                    /* This rule allows for empty statement lists, but
                    in turn causes a lot of shift/reduce errors to be
                    reported.  The parser works with this, but we should
                    perhaps look at expanding the other rules to work
                    without statement_list in them. */
                    yyval = NULL;
                  }
#line 3007 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 66: /* statement: out_arg_list assignment expr_list NEWLINE  */
#line 481 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                {
                  yyval = (TREE *)yyvsp[-2];
                  yyval->left = (TREE *)yyvsp[-3];

                  if(yyvsp[-2]->right != NULL) {
                    TREE* op = yyvsp[-2]->right;
                    yyvsp[-2]->right = NULL;
                    op->right = (TREE *)yyvsp[-1];
                    op->left = copy_node(csound, yyvsp[-3]);
                    yyval->right = op;
                  } else {
                    yyval->right = (TREE *)yyvsp[-1];
                  }
                }
#line 3026 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 67: /* statement: out_arg_list_array assignment_array expr_list NEWLINE  */
#line 496 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                {
                  yyval = (TREE *)yyvsp[-2];
                  yyval->left = (TREE *)yyvsp[-3];

                  if(yyvsp[-2]->right != NULL) {
                    TREE* op = yyvsp[-2]->right;
                    yyvsp[-2]->right = NULL;
                    op->right = (TREE *)yyvsp[-1];
                    op->left = copy_node(csound, yyvsp[-3]);
                    yyval->right = op;
                  } else {
                    yyval->right = (TREE *)yyvsp[-1];
                  }
                }
#line 3045 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 69: /* statement: goto identifier NEWLINE  */
#line 512 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                {
                    yyvsp[-2]->left = NULL;
                    yyvsp[-2]->right = yyvsp[-1];
                    yyval = yyvsp[-2];
                }
#line 3055 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 76: /* statement: BREAK_TOKEN  */
#line 525 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound, LINE, LOCN, BREAK_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 3061 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 77: /* statement: CONTINUE_TOKEN  */
#line 527 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound, LINE, LOCN, CONTINUE_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 3067 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 78: /* statement: LABEL_TOKEN  */
#line 529 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound, LINE, LOCN, LABEL_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 3073 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 79: /* statement: NEWLINE  */
#line 531 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = NULL; }
#line 3079 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 80: /* if_goto: IF_TOKEN expr goto T_IDENT NEWLINE  */
#line 537 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              {
                  yyvsp[-2]->left = NULL;
                  yyvsp[-2]->right = make_leaf(csound, LINE,LOCN,
                                        T_IDENT, (ORCTOKEN *)yyvsp[-1]);
                  yyval = make_node(csound,LINE,LOCN, IF_TOKEN, yyvsp[-3], yyvsp[-2]);
              }
#line 3090 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 81: /* if_then: if_then_base ENDIF_TOKEN NEWLINE  */
#line 546 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = yyvsp[-2]; }
#line 3096 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 82: /* if_then: if_then_base ELSE_TOKEN statement_list ENDIF_TOKEN NEWLINE  */
#line 548 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = yyvsp[-4];
            yyval->right->next = make_node(csound,LINE,LOCN, ELSE_TOKEN, NULL, yyvsp[-2]); }
#line 3103 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 83: /* if_then: if_then_base elseif_list ENDIF_TOKEN NEWLINE  */
#line 551 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = yyvsp[-3];
            yyval->right->next = yyvsp[-2]; }
#line 3110 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 84: /* if_then: if_then_base elseif_list ELSE_TOKEN statement_list ENDIF_TOKEN NEWLINE  */
#line 554 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { TREE * tempLastNode;
            yyval = yyvsp[-5];
            yyval->right->next = yyvsp[-4];

            tempLastNode = yyval;

            while (tempLastNode->right!=NULL && tempLastNode->right->next!=NULL) {
              tempLastNode = tempLastNode->right->next;
            }
            tempLastNode->right->next = make_node(csound, LINE,LOCN, ELSE_TOKEN, NULL, yyvsp[-2]);
            }
#line 3126 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 85: /* if_then_base: IF_TOKEN expr then NEWLINE statement_list  */
#line 568 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyvsp[-2]->right = yyvsp[0];
                yyval = make_node(csound,LINE,LOCN, IF_TOKEN, yyvsp[-3], yyvsp[-2]); }
#line 3133 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 86: /* elseif_list: elseif_list elseif  */
#line 573 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { TREE * tempLastNode = yyvsp[-1];
                while (tempLastNode->right!=NULL &&
                  tempLastNode->right->next!=NULL) {
                  tempLastNode = tempLastNode->right->next;
                }
                tempLastNode->right->next = yyvsp[0];
                yyval = yyvsp[-1]; }
#line 3145 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 87: /* elseif_list: elseif  */
#line 580 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                     { yyval = yyvsp[0]; }
#line 3151 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 88: /* elseif: ELSEIF_TOKEN expr then NEWLINE statement_list  */
#line 584 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyvsp[-2]->right = yyvsp[0];
              yyval = make_node(csound,LINE,LOCN, ELSEIF_TOKEN, yyvsp[-3], yyvsp[-2]); }
#line 3158 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 89: /* until: UNTIL_TOKEN expr DO_TOKEN statement_list OD_TOKEN  */
#line 589 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = make_leaf(csound,LINE,LOCN, UNTIL_TOKEN, (ORCTOKEN *)yyvsp[-4]);
                yyval->left = yyvsp[-3];
                yyval->right = yyvsp[-1]; }
#line 3166 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 90: /* while: WHILE_TOKEN expr DO_TOKEN statement_list OD_TOKEN  */
#line 595 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = make_leaf(csound,LINE,LOCN, WHILE_TOKEN, (ORCTOKEN *)yyvsp[-4]);
                yyval->left = yyvsp[-3];
                yyval->right = yyvsp[-1]; }
#line 3174 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 91: /* case: CASE_TOKEN expr_list NEWLINE statement_list  */
#line 601 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
      {
        yyval = make_leaf(csound, LINE, LOCN, CASE_TOKEN, (ORCTOKEN *)yyvsp[-3]);
        yyval->left = yyvsp[-2];
        yyval->right = yyvsp[0];
      }
#line 3184 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 92: /* case: DEFAULT_TOKEN NEWLINE statement_list  */
#line 607 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
      {
        yyval = make_leaf(csound, LINE, LOCN, DEFAULT_TOKEN, (ORCTOKEN *)yyvsp[-2]);
        yyval->right = yyvsp[0];
      }
#line 3193 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 93: /* case_list: case_list case  */
#line 614 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { TREE * tempLastNode = yyvsp[-1];
                while (tempLastNode->next != NULL) {
                  tempLastNode = tempLastNode->next;
                }
                tempLastNode->next = yyvsp[0];
                yyval = yyvsp[-1]; }
#line 3204 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 94: /* case_list: case  */
#line 620 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                   { yyval = yyvsp[0]; }
#line 3210 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 95: /* case_list: NEWLINE case_list  */
#line 622 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
             {
              yyval = yyvsp[0];
             }
#line 3218 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 96: /* switch: SWITCH_TOKEN expr NEWLINE case_list ENDSW_TOKEN  */
#line 628 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyval = make_leaf(csound,LINE,LOCN, SWITCH_TOKEN, (ORCTOKEN *)yyvsp[-4]);
          yyval->left = yyvsp[-3];
          yyval->right = yyvsp[-1];
        }
#line 3228 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 97: /* for_in: FOR_TOKEN identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 636 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN, yyvsp[-5], yyvsp[-4]);
        }
#line 3238 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 98: /* for_in: FOR_TOKEN identifier ',' identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 642 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyvsp[-7]->next = yyvsp[-5];
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN, yyvsp[-7], yyvsp[-4]);
        }
#line 3249 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 99: /* for_in: FOR_TOKEN typed_identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 649 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN,
                         make_leaf(csound,LINE,LOCN, T_TYPED_IDENT, 
                                   lookup_token(csound, yyvsp[-5]->value->lexeme, NULL)), yyvsp[-4]);
        }
#line 3261 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 100: /* for_in: FOR_TOKEN typed_identifier ',' identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 657 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_leaf(csound,LINE,LOCN, T_TYPED_IDENT, 
                         lookup_token(csound, yyvsp[-7]->value->lexeme, NULL));
          yyval->next = yyvsp[-5];
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN, yyval, yyvsp[-4]);
          }
#line 3275 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 101: /* for_in: FOR_TOKEN typed_identifier ',' typed_identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 667 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_leaf(csound,LINE,LOCN, T_TYPED_IDENT, 
                         lookup_token(csound, yyvsp[-7]->value->lexeme, NULL));
          yyval->next = make_leaf(csound,LINE,LOCN, T_TYPED_IDENT, 
                         lookup_token(csound, yyvsp[-5]->value->lexeme, NULL));
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN, yyval, yyvsp[-4]);
          }
#line 3289 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 102: /* for_in: FOR_TOKEN identifier ',' typed_identifier in expr DO_TOKEN statement_list OD_TOKEN  */
#line 677 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
          yyvsp[-7]->next = make_leaf(csound,LINE,LOCN, T_TYPED_IDENT, 
                         lookup_token(csound, yyvsp[-5]->value->lexeme, NULL));
          yyvsp[-4]->left = yyvsp[-3];
          yyvsp[-4]->right = yyvsp[-1];
          yyval = make_node(csound,LINE,LOCN, FOR_TOKEN, yyvsp[-7], yyvsp[-4]);
        }
#line 3301 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 103: /* declare_definition: DECLARE_TOKEN identifier udo_arg_list ':' udo_out_arg_list NEWLINE  */
#line 687 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
 {
   yyval = make_leaf(csound, LINE, LOCN, T_DECLARE, make_token(csound, yyvsp[-4]->value->lexeme, NULL));
   yyval->left = yyvsp[-4];
   yyval->left->left = yyvsp[-1];
   yyval->left->right = yyvsp[-3];
 }
#line 3312 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 104: /* expr_list: expr_list ',' expr  */
#line 696 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 3318 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 105: /* expr_list: expr_list ',' NEWLINE expr  */
#line 698 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = parser_append(csound, yyvsp[-3], yyvsp[0]); }
#line 3324 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 108: /* expr: '(' expr ')'  */
#line 704 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          { yyval = yyvsp[-1] ; }
#line 3330 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 109: /* expr: '(' expr error  */
#line 705 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL;  }
#line 3336 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 110: /* expr: '(' error  */
#line 706 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3342 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 125: /* gen_array: '[' expr S_ELIPSIS2 expr_list ']'  */
#line 724 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                               {
            yyval = make_leaf(csound, LINE,LOCN, T_FUNCTION, make_token(csound, "genarray", NULL));
            yyval->right = yyvsp[-3];
            parser_append(csound, yyval->right, yyvsp[-1]);
             }
#line 3352 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 126: /* slice_array: identifier '[' expr ':' expr_list ']'  */
#line 731 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                                 {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-5];
            yyval->right = parser_append(csound, yyval->right, yyvsp[-3]);
            parser_append(csound, yyval->right, yyvsp[-1]);
           }
#line 3363 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 127: /* slice_array: identifier '[' ':' expr_list ']'  */
#line 738 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                             {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-4];
            yyval->right = parser_append(csound, yyval->right,
                                       make_leaf(csound,LINE,LOCN, T_IDENT,
                                                 make_int(csound, "0", NULL)));
            parser_append(csound, yyval->right, yyvsp[-1]);
           }
#line 3376 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 128: /* slice_array: identifier '[' expr ':' ']'  */
#line 747 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                       {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-4];
            yyval->right = parser_append(csound, yyval->right, yyvsp[-2]);
           }
#line 3386 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 129: /* slice_array: expr '[' expr ':' expr_list ']'  */
#line 753 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-5];
            yyval->right = parser_append(csound, yyval->right, yyvsp[-3]);
            parser_append(csound, yyval->right, yyvsp[-1]);
           }
#line 3397 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 130: /* slice_array: expr '[' ':' expr_list ']'  */
#line 760 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                       {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-4];
            yyval->right = parser_append(csound, yyval->right,
                                       make_leaf(csound,LINE,LOCN, T_IDENT,
                                                 make_int(csound, "0", NULL)));
            parser_append(csound, yyval->right, yyvsp[-1]);
           }
#line 3410 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 131: /* slice_array: expr '[' expr ':' ']'  */
#line 769 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                 {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "slicearray", NULL));
            yyval->right = yyvsp[-4];
            yyval->right = parser_append(csound, yyval->right, yyvsp[-2]);
           }
#line 3420 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 132: /* static_array: '[' expr_list ']'  */
#line 776 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                 {
            yyval = make_leaf(csound,LINE,LOCN, T_FUNCTION, make_token(csound, "fillarray", NULL));
            yyval->right = yyvsp[-1];
          }
#line 3429 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 133: /* array_expr: array_expr '[' expr ']'  */
#line 785 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
            parser_append(csound, yyvsp[-3]->right, yyvsp[-1]);
            yyval = yyvsp[-3];
          }
#line 3438 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 134: /* array_expr: identifier '[' expr ']'  */
#line 790 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
           char* arrayName = yyvsp[-3]->value->lexeme;
            yyval = make_node(csound, LINE, LOCN, T_ARRAY,
                           make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, arrayName, NULL)), yyvsp[-1]);
          }
#line 3448 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 135: /* array_expr: function_call '[' expr ']'  */
#line 796 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
            yyval = make_node(csound, LINE, LOCN, T_ARRAY, yyvsp[-3], yyvsp[-1]);
          }
#line 3456 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 136: /* struct_expr: struct_expr '.' identifier  */
#line 802 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              char* memberName = yyvsp[0]->value->lexeme;
              // Important: Clear the next pointer of $3 to prevent it from being processed separately
              yyvsp[0]->next = NULL;
              yyval = make_node(
                csound, LINE, LOCN, STRUCT_EXPR,
                yyvsp[-2],
                make_leaf(
                          csound, LINE, LOCN, T_MEMBER_IDENT, make_token(csound, memberName, NULL)
                )
              );
            }
#line 3473 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 137: /* struct_expr: struct_expr '.' array_expr  */
#line 815 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              /* Build a struct member node from array_expr's base identifier, then
                 attach the array indexing so nested chains like a.b[0] work. */
              char* memberName = yyvsp[0]->value == NULL ?
                                  yyvsp[0]->left->value->lexeme :
                                  yyvsp[0]->value->lexeme;
              TREE* memberLeaf = make_leaf(csound, LINE, LOCN, T_MEMBER_IDENT,
                                           make_token(csound, memberName, NULL));
              TREE* structMember = make_node(csound, LINE, LOCN, STRUCT_EXPR, yyvsp[-2], memberLeaf);
              /* Now make the array_expr index the struct member */
              yyvsp[0]->left = structMember;
              yyval = yyvsp[0];
            }
#line 3491 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 138: /* struct_expr: array_expr '.' identifier  */
#line 829 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              yyvsp[0]->type = T_MEMBER_IDENT;
              yyval = make_node(csound, LINE, LOCN, STRUCT_EXPR, yyvsp[-2], yyvsp[0]);
            }
#line 3500 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 139: /* struct_expr: identifier '.' array_expr  */
#line 834 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              char* structName = yyvsp[-2]->value->lexeme;
              char* memberName = yyvsp[0]->value == NULL ?
                yyvsp[0]->left->value->lexeme :
                yyvsp[0]->value->lexeme;

              yyval = make_node(csound, LINE, LOCN, STRUCT_EXPR,
                             make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, structName, NULL)),
                             make_leaf(csound, LINE, LOCN, T_MEMBER_IDENT, make_token(csound, memberName, NULL))
              );
              yyvsp[0]->left = yyval;
              yyval = yyvsp[0];
            }
#line 3518 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 140: /* struct_expr: struct_expr '[' expr ']'  */
#line 848 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              yyval = make_node(csound, LINE, LOCN, T_ARRAY, yyvsp[-3], yyvsp[-1]);
            }
#line 3526 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 141: /* struct_expr: identifier '.' identifier  */
#line 852 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            {
              char* structName = yyvsp[-2]->value->lexeme;
              char* memberName = yyvsp[0]->value->lexeme;
              // Important: Clear the next pointer of $3 to prevent it from being processed separately
              yyvsp[0]->next = NULL;
              yyval = make_node(csound, LINE, LOCN, STRUCT_EXPR,
                             make_leaf(csound, LINE, LOCN, T_IDENT, make_token(csound, structName, NULL)),
                             make_leaf(csound, LINE, LOCN, T_MEMBER_IDENT, make_token(csound, memberName, NULL))
                   );
            }
#line 3541 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 142: /* ternary_expr: expr '?' expr ':' expr  */
#line 865 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_node(csound,LINE,LOCN, '?', yyvsp[-4],
                             make_node(csound, LINE,LOCN, ':', yyvsp[-2], yyvsp[0])); }
#line 3548 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 143: /* ternary_expr: expr '?' expr ':' error  */
#line 867 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                    { yyval = NULL; }
#line 3554 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 144: /* ternary_expr: expr '?' expr error  */
#line 868 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                { yyval = NULL; }
#line 3560 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 145: /* ternary_expr: expr '?' error  */
#line 869 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3566 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 146: /* unary_expr: '~' expr  */
#line 873 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_node(csound, LINE,LOCN, '~', NULL, yyvsp[0]);}
#line 3572 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 147: /* unary_expr: '~' error  */
#line 874 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3578 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 148: /* unary_expr: '!' expr  */
#line 875 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                { yyval = make_node(csound, LINE,LOCN,
                                                    S_UNOT, yyvsp[0], NULL); }
#line 3585 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 149: /* unary_expr: '!' error  */
#line 877 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                              { yyval = NULL; }
#line 3591 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 150: /* unary_expr: '-' expr  */
#line 879 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
              yyval = make_node(csound,LINE,LOCN, S_UMINUS, NULL, yyvsp[0]);
          }
#line 3599 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 151: /* unary_expr: '-' error  */
#line 882 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                              { yyval = NULL; }
#line 3605 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 152: /* unary_expr: '+' expr  */
#line 901 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
          {
              yyval = make_node(csound,LINE,LOCN, S_UPLUS, NULL, yyvsp[0]);
          }
#line 3613 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 153: /* unary_expr: '+' error  */
#line 905 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                              { yyval = NULL; }
#line 3619 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 154: /* binary_expr: expr '+' optnewline expr  */
#line 908 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                         { yyval = make_node(csound, LINE,LOCN, '+', yyvsp[-3], yyvsp[0]); }
#line 3625 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 155: /* binary_expr: expr '+' error  */
#line 909 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3631 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 156: /* binary_expr: expr '-' optnewline expr  */
#line 910 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                      { yyval = make_node(csound ,LINE,LOCN, '-', yyvsp[-3], yyvsp[0]); }
#line 3637 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 157: /* binary_expr: expr '-' error  */
#line 911 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3643 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 158: /* binary_expr: expr S_LE optnewline expr  */
#line 912 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_LE, yyvsp[-3], yyvsp[0]); }
#line 3649 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 159: /* binary_expr: expr S_LE error  */
#line 913 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3655 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 160: /* binary_expr: expr S_GE optnewline expr  */
#line 914 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_GE, yyvsp[-3], yyvsp[0]); }
#line 3661 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 161: /* binary_expr: expr S_GE error  */
#line 915 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                { yyval = NULL; }
#line 3667 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 162: /* binary_expr: expr S_NEQ optnewline expr  */
#line 916 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_NEQ, yyvsp[-3], yyvsp[0]); }
#line 3673 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 163: /* binary_expr: expr S_NEQ error  */
#line 917 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                { yyval = NULL; }
#line 3679 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 164: /* binary_expr: expr '=' optnewline expr  */
#line 919 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                      { yyval = make_node(csound, LINE,LOCN, S_EQ, yyvsp[-3], yyvsp[0]); }
#line 3685 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 165: /* binary_expr: expr '=' error  */
#line 920 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3691 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 166: /* binary_expr: expr S_EQ optnewline expr  */
#line 921 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_EQ, yyvsp[-3], yyvsp[0]); }
#line 3697 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 167: /* binary_expr: expr S_EQ error  */
#line 922 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3703 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 168: /* binary_expr: expr S_GT optnewline expr  */
#line 923 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_GT, yyvsp[-3], yyvsp[0]); }
#line 3709 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 169: /* binary_expr: expr S_GT error  */
#line 924 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3715 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 170: /* binary_expr: expr S_LT optnewline expr  */
#line 925 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           { yyval = make_node(csound, LINE,LOCN, S_LT, yyvsp[-3], yyvsp[0]); }
#line 3721 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 171: /* binary_expr: expr S_LT error  */
#line 926 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3727 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 172: /* binary_expr: expr S_AND optnewline expr  */
#line 927 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                         { yyval = make_node(csound, LINE,LOCN, S_AND, yyvsp[-3], yyvsp[0]); }
#line 3733 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 173: /* binary_expr: expr S_AND error  */
#line 928 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                             { yyval = NULL; }
#line 3739 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 174: /* binary_expr: expr S_OR optnewline expr  */
#line 929 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                         { yyval = make_node(csound, LINE,LOCN, S_OR, yyvsp[-3], yyvsp[0]); }
#line 3745 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 175: /* binary_expr: expr S_OR error  */
#line 930 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                            { yyval = NULL; }
#line 3751 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 176: /* binary_expr: expr '*' optnewline expr  */
#line 931 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                        { yyval = make_node(csound, LINE,LOCN, '*', yyvsp[-3], yyvsp[0]); }
#line 3757 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 177: /* binary_expr: expr '*' error  */
#line 932 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3763 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 178: /* binary_expr: expr '/' optnewline expr  */
#line 933 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                        { yyval = make_node(csound, LINE,LOCN, '/', yyvsp[-3], yyvsp[0]); }
#line 3769 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 179: /* binary_expr: expr '/' error  */
#line 934 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3775 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 180: /* binary_expr: expr '^' optnewline expr  */
#line 935 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                        { yyval = make_node(csound, LINE,LOCN, '^', yyvsp[-3], yyvsp[0]); }
#line 3781 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 181: /* binary_expr: expr '^' error  */
#line 936 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3787 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 182: /* binary_expr: expr '%' optnewline expr  */
#line 937 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                        { yyval = make_node(csound, LINE,LOCN, '%', yyvsp[-3], yyvsp[0]); }
#line 3793 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 183: /* binary_expr: expr '%' error  */
#line 938 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3799 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 184: /* binary_expr: expr '|' optnewline expr  */
#line 939 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                            { yyval = make_node(csound, LINE,LOCN, '|', yyvsp[-3], yyvsp[0]); }
#line 3805 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 185: /* binary_expr: expr '|' error  */
#line 940 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3811 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 186: /* binary_expr: expr '&' optnewline expr  */
#line 941 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                            { yyval = make_node(csound, LINE,LOCN, '&', yyvsp[-3], yyvsp[0]); }
#line 3817 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 187: /* binary_expr: expr '&' error  */
#line 942 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3823 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 188: /* binary_expr: expr '#' optnewline expr  */
#line 943 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                            { yyval = make_node(csound, LINE,LOCN, '#', yyvsp[-3], yyvsp[0]); }
#line 3829 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 189: /* binary_expr: expr '#' error  */
#line 944 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                           { yyval = NULL; }
#line 3835 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 190: /* binary_expr: expr S_BITSHIFT_LEFT optnewline expr  */
#line 946 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                 { yyval = make_node(csound, LINE,LOCN, S_BITSHIFT_LEFT, yyvsp[-3], yyvsp[0]); }
#line 3841 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 191: /* binary_expr: expr S_BITSHIFT_LEFT error  */
#line 947 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                       { yyval = NULL; }
#line 3847 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 192: /* binary_expr: expr S_BITSHIFT_RIGHT optnewline expr  */
#line 949 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                 { yyval = make_node(csound, LINE,LOCN, S_BITSHIFT_RIGHT, yyvsp[-3], yyvsp[0]); }
#line 3853 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 193: /* binary_expr: expr S_BITSHIFT_RIGHT error  */
#line 950 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                        { yyval = NULL; }
#line 3859 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 194: /* out_arg_list: out_arg_list ',' out_arg  */
#line 955 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 3865 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 200: /* out_arg_list_array: out_arg_list_array ',' array_expr  */
#line 966 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
              { yyval = parser_append(csound, yyvsp[-2], yyvsp[0]); }
#line 3871 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 202: /* array_identifier: array_identifier '[' ']'  */
#line 970 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                           {
            parser_append(csound, yyvsp[-2]->right,
                           make_leaf(csound, LINE, LOCN, '[', make_token(csound, "[", NULL)));
            yyval = yyvsp[-2];
          }
#line 3881 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 203: /* array_identifier: identifier '[' ']'  */
#line 975 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                               {
            yyval = yyvsp[-2];
            yyvsp[-2]->type = T_ARRAY_IDENT;
            yyval->right = make_leaf(csound, LINE, LOCN, '[', make_token(csound, "[", NULL));
          }
#line 3891 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 204: /* array_identifier: typed_identifier '[' ']'  */
#line 980 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                                     {
            yyval = yyvsp[-2];
            // Check if this is a type annotation (e.g., "var:Type[]") vs array access
            // If the typed_identifier already has a type annotation ending with "[]",
            // keep it as T_TYPED_IDENT rather than converting to T_ARRAY_IDENT
            if (yyvsp[-2]->value && yyvsp[-2]->value->optype) {
              size_t len = strlen(yyvsp[-2]->value->optype);
              if (len >= 2 && yyvsp[-2]->value->optype[len-2] == '[' && yyvsp[-2]->value->optype[len-1] == ']') {
                // This is a type annotation like "Person[]", keep as T_TYPED_IDENT
                // Don't attach the '[' token or change the type
              } else {
                // This is array access syntax, convert to T_ARRAY_IDENT
                yyvsp[-2]->type = T_ARRAY_IDENT;
                yyval->right = make_leaf(csound, LINE, LOCN, '[', make_token(csound, "[", NULL));
              }
            } else {
              // No type annotation, treat as array access
              yyvsp[-2]->type = T_ARRAY_IDENT;
              yyval->right = make_leaf(csound, LINE, LOCN, '[', make_token(csound, "[", NULL));
            }
          }
#line 3917 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 205: /* assignment: '='  */
#line 1005 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL)); }
#line 3923 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 206: /* assignment: S_ADDIN  */
#line 1007 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, S_ADDIN, make_token(csound, "##addin", NULL)); }
#line 3929 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 207: /* assignment: S_SUBIN  */
#line 1009 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, S_SUBIN, make_token(csound, "##subin", NULL)); }
#line 3935 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 208: /* assignment: S_DIVIN  */
#line 1011 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, S_DIVIN, make_token(csound, "##divin", NULL)); }
#line 3941 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 209: /* assignment: S_MULIN  */
#line 1013 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, S_MULIN, make_token(csound, "##mulin", NULL)); }
#line 3947 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 210: /* assignment_array: '='  */
#line 1018 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL)); }
#line 3953 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 211: /* assignment_array: S_ADDIN  */
#line 1020 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL));
                  yyval->right = make_leaf(csound, LINE, LOCN, '+', make_token(csound, "+", NULL));
                }
#line 3961 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 212: /* assignment_array: S_SUBIN  */
#line 1024 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL));
                  yyval->right = make_leaf(csound, LINE, LOCN, '-', make_token(csound, "-", NULL));
                }
#line 3969 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 213: /* assignment_array: S_DIVIN  */
#line 1028 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL));
                  yyval->right = make_leaf(csound, LINE, LOCN, '/', make_token(csound, "/", NULL));
                }
#line 3977 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 214: /* assignment_array: S_MULIN  */
#line 1032 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
                { yyval = make_leaf(csound,LINE,LOCN, T_ASSIGNMENT, make_token(csound, "=", NULL));
                  yyval->right = make_leaf(csound, LINE, LOCN, '*', make_token(csound, "*", NULL));
                }
#line 3985 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 215: /* in: IN_TOKEN  */
#line 1038 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, IN_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 3991 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 216: /* then: THEN_TOKEN  */
#line 1041 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, THEN_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 3997 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 217: /* then: KTHEN_TOKEN  */
#line 1043 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, KTHEN_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4003 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 218: /* then: ITHEN_TOKEN  */
#line 1045 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, ITHEN_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4009 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 219: /* goto: GOTO_TOKEN  */
#line 1049 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, GOTO_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4015 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 220: /* goto: KGOTO_TOKEN  */
#line 1051 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, KGOTO_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4021 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 221: /* goto: IGOTO_TOKEN  */
#line 1053 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
            { yyval = make_leaf(csound,LINE,LOCN, IGOTO_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4027 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 224: /* string: STRING_TOKEN  */
#line 1061 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE,LOCN, STRING_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4033 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 225: /* false_const: FALSE_TOKEN  */
#line 1065 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
       { yyval = make_leaf(csound, LINE,LOCN, FALSE_TOKEN,
                        make_token(csound,"false", NULL)); }
#line 4040 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 226: /* false_const: FALSEK_TOKEN  */
#line 1068 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
       { yyval = make_leaf(csound, LINE,LOCN, FALSEK_TOKEN,
                        make_token(csound,"falsek", NULL)); }
#line 4047 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 227: /* true_const: TRUE_TOKEN  */
#line 1074 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
           { yyval = make_leaf(csound, LINE,LOCN, TRUE_TOKEN,
                            make_token(csound,"true", NULL)); }
#line 4054 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 228: /* true_const: TRUEK_TOKEN  */
#line 1077 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
       { yyval = make_leaf(csound, LINE,LOCN, TRUEK_TOKEN,
                        make_token(csound,"truek", NULL)); }
#line 4061 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 229: /* number: NUMBER_TOKEN  */
#line 1083 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
       { yyval = make_leaf(csound, LINE,LOCN, NUMBER_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4067 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 230: /* integer: INTEGER_TOKEN  */
#line 1087 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE, LOCN, INTEGER_TOKEN, (ORCTOKEN *)yyvsp[0]); }
#line 4073 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 231: /* plus_identifier: '+' T_IDENT  */
#line 1095 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        {
	  yyval = make_leaf(csound, LINE, LOCN, T_PLUS_IDENT, (ORCTOKEN *)yyvsp[0]);
	}
#line 4081 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 232: /* typed_identifier: T_TYPED_IDENT  */
#line 1101 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE, LOCN, T_TYPED_IDENT, (ORCTOKEN *)yyvsp[0]); }
#line 4087 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 233: /* typed_identifierb: T_TYPED_IDENTB  */
#line 1105 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE, LOCN, T_TYPED_IDENT, (ORCTOKEN *)yyvsp[0]); }
#line 4093 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 234: /* identifier: T_IDENT  */
#line 1109 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE, LOCN, T_IDENT, (ORCTOKEN *)yyvsp[0]); }
#line 4099 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;

  case 235: /* identifierb: T_IDENTB  */
#line 1113 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"
        { yyval = make_leaf(csound, LINE, LOCN, T_IDENT, (ORCTOKEN *)yyvsp[0]); }
#line 4105 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"
    break;


#line 4109 "/Users/ant/Desktop/csound7_tilde/build/csound-static/build-x86_64/csound_orcparse.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (parm, scanner, csound, astTree, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parm, scanner, csound, astTree);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parm, scanner, csound, astTree);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parm, scanner, csound, astTree, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parm, scanner, csound, astTree);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parm, scanner, csound, astTree);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1116 "/Users/ant/Desktop/csound7_tilde/build/csound-static/src/Engine/csound_orc.y"


#ifdef SOME_FINE_DAY
void
yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if (yylloc.first_line)
    fprintf(stderr, "%d.%d-%d.%d: error: ",
            yylloc.first_line, yylloc.first_column,
            yylloc.last_line, yylloc.last_column);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");

}

void
lyyerror(YYLTYPE t, char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if (t.first_line)
    fprintf(stderr, "%d.%d-%d.%d: error: ", t.first_line, t.first_column,
            t.last_line, t.last_column);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

#endif
