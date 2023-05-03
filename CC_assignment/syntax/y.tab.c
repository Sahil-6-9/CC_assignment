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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammer1.y"

#include <stdio.h> 
#include <string.h>
#include "ast.h"

int yylex(void);
extern FILE *yyin;

struct SymbolTable {
	char name[30];
	int return_type;
        int num_parameters;
        int parameter_types[100];
	struct Node* definition;

	char symbol[50][30];
        int num_symbols;
};

struct SymbolTable symbol_table[100];
int num_symbols = 0;
int num_functions = 0;
int current_scope = 0;

struct Node* add_node(struct Node* root, struct Node* child) {
        root->children[root->num_child++] = child;
        return root;
}

void preorderTraversal(Node* root)
{
        if(!root)
                return;

        printf("%s\n", root->name);
        for(int i=0; i<root->num_child; i++)
        {
                preorderTraversal(root->children[i]);
        }
}

int dataType = -1;


#line 116 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    DECIMAL = 259,                 /* DECIMAL  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    CHARACTER = 262,               /* CHARACTER  */
    INT = 263,                     /* INT  */
    FLOAT = 264,                   /* FLOAT  */
    CHAR = 265,                    /* CHAR  */
    VOID = 266,                    /* VOID  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    FOR = 269,                     /* FOR  */
    WHILE = 270,                   /* WHILE  */
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    DEFAULT = 273,                 /* DEFAULT  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    RETURN = 276,                  /* RETURN  */
    MAIN = 277,                    /* MAIN  */
    PRINTF = 278,                  /* PRINTF  */
    OR = 279,                      /* OR  */
    AND = 280,                     /* AND  */
    EQ = 281,                      /* EQ  */
    NE = 282,                      /* NE  */
    GE = 283,                      /* GE  */
    LE = 284                       /* LE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define DECIMAL 259
#define INTEGER 260
#define STRING 261
#define CHARACTER 262
#define INT 263
#define FLOAT 264
#define CHAR 265
#define VOID 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define BREAK 274
#define CONTINUE 275
#define RETURN 276
#define MAIN 277
#define PRINTF 278
#define OR 279
#define AND 280
#define EQ 281
#define NE 282
#define GE 283
#define LE 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "grammer1.y"
 struct Node* node; 

#line 230 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_DECIMAL = 4,                    /* DECIMAL  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_CHARACTER = 7,                  /* CHARACTER  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_PRINTF = 23,                    /* PRINTF  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_s = 49,                         /* s  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_datatype = 52,                  /* datatype  */
  YYSYMBOL_primitive_literal = 53,         /* primitive_literal  */
  YYSYMBOL_integer_literal = 54,           /* integer_literal  */
  YYSYMBOL_functions = 55,                 /* functions  */
  YYSYMBOL_function = 56,                  /* function  */
  YYSYMBOL_formal_parameters = 57,         /* formal_parameters  */
  YYSYMBOL_formal_parameter = 58,          /* formal_parameter  */
  YYSYMBOL_actual_parameters = 59,         /* actual_parameters  */
  YYSYMBOL_main = 60,                      /* main  */
  YYSYMBOL_variable = 61,                  /* variable  */
  YYSYMBOL_array_access = 62,              /* array_access  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_conditional = 64,               /* conditional  */
  YYSYMBOL_printf = 65,                    /* printf  */
  YYSYMBOL_compound = 66,                  /* compound  */
  YYSYMBOL_function_call = 67,             /* function_call  */
  YYSYMBOL_jump = 68,                      /* jump  */
  YYSYMBOL_return = 69,                    /* return  */
  YYSYMBOL_looping = 70,                   /* looping  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_declaration_list = 72,          /* declaration_list  */
  YYSYMBOL_array_declaration = 73,         /* array_declaration  */
  YYSYMBOL_value_list = 74,                /* value_list  */
  YYSYMBOL_value_block = 75,               /* value_block  */
  YYSYMBOL_non_array_declaration = 76,     /* non_array_declaration  */
  YYSYMBOL_expression = 77,                /* expression  */
  YYSYMBOL_operand = 78,                   /* operand  */
  YYSYMBOL_assignment = 79,                /* assignment  */
  YYSYMBOL_loop_expression = 80,           /* loop_expression  */
  YYSYMBOL_for = 81,                       /* for  */
  YYSYMBOL_while = 82,                     /* while  */
  YYSYMBOL_switch = 83,                    /* switch  */
  YYSYMBOL_case = 84,                      /* case  */
  YYSYMBOL_if = 85                         /* if  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,    38,     2,     2,     2,    37,     2,     2,
      39,    40,    35,    33,    43,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
      29,    24,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    77,    88,    97,   103,   109,   115,   124,
     129,   137,   142,   150,   157,   161,   181,   201,   224,   232,
     238,   244,   252,   260,   266,   272,   284,   296,   311,   316,
     321,   326,   334,   341,   352,   357,   362,   367,   372,   377,
     382,   387,   392,   397,   402,   409,   414,   422,   428,   438,
     446,   455,   460,   468,   474,   482,   487,   495,   506,   515,
     525,   530,   538,   539,   540,   545,   550,   555,   560,   565,
     570,   571,   576,   584,   589,   599,   604,   614,   619,   627,
     633,   639,   645,   653,   661,   669,   677,   689,   697,   705,
     713,   721,   729,   737,   745,   753,   758,   766,   771,   776,
     784,   795,   800,   806,   812,   821,   833,   843,   853,   860,
     869,   876
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "DECIMAL", "INTEGER", "STRING", "CHARACTER", "INT", "FLOAT", "CHAR",
  "VOID", "IF", "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "CONTINUE", "RETURN", "MAIN", "PRINTF", "'='", "OR", "AND",
  "EQ", "NE", "'<'", "'>'", "GE", "LE", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'('", "')'", "'{'", "'}'", "','", "'['", "']'", "';'", "':'",
  "$accept", "s", "program", "statements", "datatype", "primitive_literal",
  "integer_literal", "functions", "function", "formal_parameters",
  "formal_parameter", "actual_parameters", "main", "variable",
  "array_access", "statement", "conditional", "printf", "compound",
  "function_call", "jump", "return", "looping", "declaration",
  "declaration_list", "array_declaration", "value_list", "value_block",
  "non_array_declaration", "expression", "operand", "assignment",
  "loop_expression", "for", "while", "switch", "case", "if", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-208)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -208,    47,  -208,   201,  -208,    14,  -208,  -208,  -208,    15,
      22,    19,  -208,  -208,    78,    39,    43,    54,    56,    67,
      52,   102,  -208,    78,    72,    94,    78,   103,   105,  -208,
    -208,  -208,  -208,   152,    78,   104,   153,  -208,   108,   154,
      76,  -208,  -208,   155,  -208,   222,   158,  -208,    10,  -208,
    -208,  -208,    76,    76,    76,    76,  -208,  -208,  -208,  -208,
     546,  -208,   262,  -208,   302,   130,   166,   167,   181,   106,
     172,  -208,  -208,    76,   185,  -208,  -208,  -208,   230,   211,
    -208,  -208,   212,  -208,   213,   216,  -208,   227,   524,   229,
    -208,  -208,  -208,  -208,  -208,  -208,   342,    52,   118,   118,
    -208,   651,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,   242,  -208,   382,  -208,    76,
     169,    76,    76,   210,   502,   699,   281,   422,   -23,   245,
    -208,  -208,    76,  -208,  -208,  -208,  -208,  -208,  -208,   462,
    -208,   123,  -208,  -208,   711,   722,   217,   217,   180,   180,
     180,   180,   118,   118,  -208,  -208,  -208,    76,  -208,   667,
     243,   699,  -208,   244,   251,   683,   502,  -208,   128,  -208,
      76,    12,   230,   699,  -208,  -208,    52,   567,   502,    76,
      76,   502,   502,  -208,  -208,    52,   699,   -12,   588,  -208,
    -208,  -208,  -208,   279,   247,   248,  -208,  -208,   147,    -3,
      76,    -4,   502,    76,    76,  -208,  -208,   129,   609,    -2,
      76,  -208,   257,   258,  -208,   -29,   275,  -208,   129,   630,
     502,   502,  -208,   129,   261,   -15,   289,  -208,  -208,  -208,
      26,  -208,   274,   129,    75,   284,    26,   138,  -208,  -208,
     143,   285,   286,  -208,  -208,   287,  -208
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     2,     0,     1,     0,     6,     7,     8,     0,
       0,     0,    13,     3,    20,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,    20,     0,    28,    29,
      30,    21,    31,     0,     0,     0,     0,     5,     0,     0,
       0,     5,    18,     0,     5,     0,     0,     5,    28,    10,
      11,    12,     0,     0,     0,     0,    99,     9,    97,    98,
       0,    96,     0,     5,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    54,    30,     5,    26,    44,     0,    97,
       4,    34,     0,    39,     0,     0,    38,     0,     0,     0,
      56,    55,    46,    43,    45,     5,     0,    24,    80,    81,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    17,     0,    27,     0,
     103,   103,     0,     0,     0,    53,     0,     0,    77,    57,
      60,    61,     0,    40,    41,    42,    37,    35,    36,     0,
      25,     0,    23,    95,    94,    93,    89,    90,    87,    88,
      91,    92,    82,    83,    84,    85,    86,     0,    16,     0,
       0,   101,   102,     0,     0,     0,     0,   109,     0,    49,
       0,     0,     0,   100,    15,    50,     0,     0,     0,   103,
     103,     0,     0,   108,    47,    24,    78,     0,     0,    58,
      59,    22,    33,   110,     0,     0,   106,   107,     0,     0,
       0,    62,     0,   103,   103,    48,    72,     0,     0,     0,
       0,   111,     0,     0,    73,     0,    70,    71,     0,     0,
       0,     0,    65,     0,     0,     0,    63,   105,   104,    74,
       0,    64,     0,     0,     0,     0,     0,     0,    67,    69,
       0,     0,    75,    66,    68,     0,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,   -39,    82,   -66,   263,  -208,  -208,    36,
     296,   146,  -208,   -20,  -208,  -118,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,   214,  -208,   161,  -207,  -193,   165,    18,
    -208,  -111,  -114,  -208,  -208,  -208,  -208,  -208
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    45,    78,    56,    57,     3,    12,    21,
      22,   141,    13,    58,    32,    80,    81,    82,    83,    59,
      84,    85,    86,    87,   129,   130,   215,   235,   131,    88,
      61,    89,   163,    90,    91,    92,    93,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,   170,    62,   206,   217,    64,   167,   164,    96,   162,
     162,   225,   199,   222,   223,    48,    49,    50,    15,    51,
     209,   171,    18,   234,   117,    79,   237,   231,   223,   240,
      49,    50,   200,    51,    29,    30,   127,    16,   207,   218,
     210,    19,    79,   241,    79,    52,    53,     4,   183,    97,
      54,    55,   246,    14,    40,    28,   139,   187,    60,    35,
     193,    17,    38,   196,   197,   194,   195,   233,   162,   162,
      98,    99,   100,   101,    29,    30,    79,   142,    23,    48,
      49,    50,    24,    51,   211,    11,     6,     7,     8,   212,
     213,   125,   162,   162,    25,    26,    20,    79,    29,    30,
      79,    79,   227,   228,    79,    20,    27,    79,    20,    52,
      53,    50,    36,    51,    54,    55,    20,   238,   223,    79,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    49,    50,    37,    51,   159,   161,   161,
     165,   214,    33,    39,    43,    34,    79,    34,    46,    40,
     173,    34,   214,   112,   113,   114,   191,   229,    79,    79,
      79,    79,    79,   175,   214,   142,   176,   214,   184,   119,
     214,   185,    48,    49,    50,   177,    51,     6,     7,     8,
     242,   223,    79,    79,    79,   243,   223,   205,   186,   188,
     176,    29,    30,    41,    44,    47,    63,   161,   161,    95,
      79,    79,    52,    53,     5,   120,   121,    54,    55,     6,
       7,     8,     9,   110,   111,   112,   113,   114,   208,   124,
     122,   161,   161,    10,   126,    48,    49,    50,   219,    51,
       6,     7,     8,   128,    65,   132,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    52,    53,   166,   133,   134,
      54,    55,   135,    75,    76,    48,    49,    50,    77,    51,
       6,     7,     8,   136,    65,   138,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   157,   168,   172,   179,
     180,   181,   202,   203,   204,    52,    53,   220,   221,   224,
      54,    55,   230,    75,   116,    48,    49,    50,    77,    51,
       6,     7,     8,   232,    65,   236,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   239,   244,   233,   245,
      42,   198,   123,   189,   160,    52,    53,   190,     0,     0,
      54,    55,     0,    75,   118,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   140,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   158,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   169,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   174,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,     0,     0,     0,     0,    77,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,   115,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,   192,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,   201,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   216,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,   226,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,   143,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,   178,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,   182,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      20,    24,    41,     6,     6,    44,   124,   121,    47,   120,
     121,   218,    24,    42,    43,     3,     4,     5,     3,     7,
      24,    44,     3,   230,    63,    45,   233,    42,    43,   236,
       4,     5,    44,     7,    22,    23,    75,    22,    41,    41,
      44,    22,    62,   236,    64,    33,    34,     0,   166,    39,
      38,    39,   245,    39,    44,     3,    95,    45,    40,    23,
     178,    39,    26,   181,   182,   179,   180,    41,   179,   180,
      52,    53,    54,    55,    22,    23,    96,    97,    39,     3,
       4,     5,    39,     7,   202,     3,     8,     9,    10,   203,
     204,    73,   203,   204,    40,    39,    14,   117,    22,    23,
     120,   121,   220,   221,   124,    23,    39,   127,    26,    33,
      34,     5,    40,     7,    38,    39,    34,    42,    43,   139,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     4,     5,    41,     7,   119,   120,   121,
     122,   207,    40,    40,    40,    43,   166,    43,    40,    44,
     132,    43,   218,    35,    36,    37,   176,   223,   178,   179,
     180,   181,   182,    40,   230,   185,    43,   233,    40,    39,
     236,    43,     3,     4,     5,   157,     7,     8,     9,    10,
      42,    43,   202,   203,   204,    42,    43,    40,   170,   171,
      43,    22,    23,    41,    41,    41,    41,   179,   180,    41,
     220,   221,    33,    34,     3,    39,    39,    38,    39,     8,
       9,    10,    11,    33,    34,    35,    36,    37,   200,    47,
      39,   203,   204,    22,    39,     3,     4,     5,   210,     7,
       8,     9,    10,     3,    12,    24,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    33,    34,    47,    46,    46,
      38,    39,    46,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    46,    12,    46,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    44,     6,    43,    46,
      46,    40,    13,    46,    46,    33,    34,    40,    40,    24,
      38,    39,    41,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    24,    12,    41,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    42,    42,    41,    43,
      34,   185,    69,   172,   120,    33,    34,   172,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,    55,     0,     3,     8,     9,    10,    11,
      22,    52,    56,    60,    39,     3,    22,    39,     3,    22,
      52,    57,    58,    39,    39,    40,    39,    39,     3,    22,
      23,    61,    62,    40,    43,    57,    40,    41,    57,    40,
      44,    41,    58,    40,    41,    51,    40,    41,     3,     4,
       5,     7,    33,    34,    38,    39,    53,    54,    61,    67,
      77,    78,    51,    41,    51,    12,    14,    15,    16,    17,
      18,    19,    20,    21,    23,    41,    42,    46,    52,    61,
      63,    64,    65,    66,    68,    69,    70,    71,    77,    79,
      81,    82,    83,    84,    85,    41,    51,    39,    77,    77,
      77,    77,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    45,    42,    51,    42,    39,
      39,    39,    39,    54,    47,    77,    39,    51,     3,    72,
      73,    76,    24,    46,    46,    46,    46,    46,    46,    51,
      42,    59,    61,    40,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    44,    42,    77,
      71,    77,    79,    80,    80,    77,    47,    63,     6,    42,
      24,    44,    43,    77,    42,    40,    43,    77,    40,    46,
      46,    40,    40,    63,    40,    43,    77,    45,    77,    73,
      76,    61,    45,    63,    80,    80,    63,    63,    59,    24,
      44,    45,    13,    46,    46,    40,     6,    41,    77,    24,
      44,    63,    80,    80,    53,    74,    45,     6,    41,    77,
      40,    40,    42,    43,    24,    74,    45,    63,    63,    53,
      41,    42,    24,    41,    74,    75,    41,    74,    42,    42,
      74,    75,    42,    42,    42,    43,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    66,
      67,    68,    68,    69,    69,    70,    70,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    80,    80,    80,    81,    81,    82,    83,    84,    84,
      85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     8,     8,     7,     3,     1,
       0,     2,     3,     1,     0,     7,     6,     7,     1,     1,
       1,     1,     4,     7,     1,     2,     2,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     4,     6,     3,
       4,     1,     1,     2,     1,     1,     1,     2,     3,     3,
       1,     1,     4,     7,     8,     7,    11,    10,    11,    10,
       6,     6,     5,     1,     3,     3,     5,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     0,     9,     9,     5,     5,     4,     3,
       5,     7
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
  case 2: /* s: program  */
#line 68 "grammer1.y"
        { 

                for(int i=0; i<num_functions; i++) {
                        preorderTraversal(symbol_table[i].definition);
                }
                return 1;    
        }
#line 1562 "y.tab.c"
    break;

  case 3: /* program: functions main  */
#line 78 "grammer1.y"
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "program");
                // add_node($$, $1);
                // add_node($$, $2);
                // preorderTraversal($$);
        }
#line 1574 "y.tab.c"
    break;

  case 4: /* statements: statements statement  */
#line 89 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "statements");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-1].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1586 "y.tab.c"
    break;

  case 5: /* statements: %empty  */
#line 97 "grammer1.y"
        {
                (yyval.node) = NULL;
        }
#line 1594 "y.tab.c"
    break;

  case 6: /* datatype: INT  */
#line 104 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 0;
        }
#line 1604 "y.tab.c"
    break;

  case 7: /* datatype: FLOAT  */
#line 110 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 1;
        }
#line 1614 "y.tab.c"
    break;

  case 8: /* datatype: CHAR  */
#line 116 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 2;
        }
#line 1624 "y.tab.c"
    break;

  case 9: /* primitive_literal: integer_literal  */
#line 125 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1633 "y.tab.c"
    break;

  case 10: /* primitive_literal: DECIMAL  */
#line 130 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1642 "y.tab.c"
    break;

  case 11: /* integer_literal: INTEGER  */
#line 138 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1651 "y.tab.c"
    break;

  case 12: /* integer_literal: CHARACTER  */
#line 143 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1660 "y.tab.c"
    break;

  case 13: /* functions: functions function  */
#line 151 "grammer1.y"
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "functions");
                // add_node($$, $1);
                // add_node($$, $2);
        }
#line 1671 "y.tab.c"
    break;

  case 15: /* function: datatype IDENTIFIER '(' formal_parameters ')' '{' statements '}'  */
#line 162 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1695 "y.tab.c"
    break;

  case 16: /* function: VOID IDENTIFIER '(' formal_parameters ')' '{' statements '}'  */
#line 182 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1719 "y.tab.c"
    break;

  case 17: /* function: IDENTIFIER '(' formal_parameters ')' '{' statements '}'  */
#line 202 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1743 "y.tab.c"
    break;

  case 18: /* formal_parameters: formal_parameters ',' formal_parameter  */
#line 225 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "formal_parameters");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1755 "y.tab.c"
    break;

  case 19: /* formal_parameters: formal_parameter  */
#line 233 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1764 "y.tab.c"
    break;

  case 20: /* formal_parameters: %empty  */
#line 238 "grammer1.y"
        {
                (yyval.node) = NULL;
        }
#line 1772 "y.tab.c"
    break;

  case 21: /* formal_parameter: datatype variable  */
#line 245 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1781 "y.tab.c"
    break;

  case 22: /* actual_parameters: actual_parameters ',' variable  */
#line 253 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "actual_parameters");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1793 "y.tab.c"
    break;

  case 23: /* actual_parameters: variable  */
#line 261 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1802 "y.tab.c"
    break;

  case 24: /* actual_parameters: %empty  */
#line 266 "grammer1.y"
        {
                (yyval.node) = NULL;
        }
#line 1810 "y.tab.c"
    break;

  case 25: /* main: datatype MAIN '(' ')' '{' statements '}'  */
#line 273 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        }
#line 1826 "y.tab.c"
    break;

  case 26: /* main: MAIN '(' ')' '{' statements '}'  */
#line 285 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        }
#line 1842 "y.tab.c"
    break;

  case 27: /* main: VOID MAIN '(' ')' '{' statements '}'  */
#line 297 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);
                symbol_table[num_functions].num_symbols = 0;

                num_functions++;
        }
#line 1858 "y.tab.c"
    break;

  case 28: /* variable: IDENTIFIER  */
#line 312 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1867 "y.tab.c"
    break;

  case 29: /* variable: MAIN  */
#line 317 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1876 "y.tab.c"
    break;

  case 30: /* variable: PRINTF  */
#line 322 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1885 "y.tab.c"
    break;

  case 31: /* variable: array_access  */
#line 327 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1894 "y.tab.c"
    break;

  case 32: /* array_access: IDENTIFIER '[' expression ']'  */
#line 335 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-3].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 1905 "y.tab.c"
    break;

  case 33: /* array_access: IDENTIFIER '[' expression ']' '[' expression ']'  */
#line 342 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 1917 "y.tab.c"
    break;

  case 34: /* statement: conditional  */
#line 353 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1926 "y.tab.c"
    break;

  case 35: /* statement: expression ';'  */
#line 358 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1935 "y.tab.c"
    break;

  case 36: /* statement: assignment ';'  */
#line 363 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1944 "y.tab.c"
    break;

  case 37: /* statement: declaration ';'  */
#line 368 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1953 "y.tab.c"
    break;

  case 38: /* statement: looping  */
#line 373 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1962 "y.tab.c"
    break;

  case 39: /* statement: compound  */
#line 378 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1971 "y.tab.c"
    break;

  case 40: /* statement: printf ';'  */
#line 383 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1980 "y.tab.c"
    break;

  case 41: /* statement: jump ';'  */
#line 388 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1989 "y.tab.c"
    break;

  case 42: /* statement: return ';'  */
#line 393 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1998 "y.tab.c"
    break;

  case 43: /* statement: case  */
#line 398 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2007 "y.tab.c"
    break;

  case 44: /* statement: ';'  */
#line 403 "grammer1.y"
        {
                (yyval.node) = NULL;
        }
#line 2015 "y.tab.c"
    break;

  case 45: /* conditional: if  */
#line 410 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2024 "y.tab.c"
    break;

  case 46: /* conditional: switch  */
#line 415 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2033 "y.tab.c"
    break;

  case 47: /* printf: PRINTF '(' STRING ')'  */
#line 423 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2043 "y.tab.c"
    break;

  case 48: /* printf: PRINTF '(' STRING ',' actual_parameters ')'  */
#line 429 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-3].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2054 "y.tab.c"
    break;

  case 49: /* compound: '{' statements '}'  */
#line 439 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2063 "y.tab.c"
    break;

  case 50: /* function_call: IDENTIFIER '(' actual_parameters ')'  */
#line 447 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2073 "y.tab.c"
    break;

  case 51: /* jump: BREAK  */
#line 456 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2082 "y.tab.c"
    break;

  case 52: /* jump: CONTINUE  */
#line 461 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2091 "y.tab.c"
    break;

  case 53: /* return: RETURN expression  */
#line 469 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2101 "y.tab.c"
    break;

  case 54: /* return: RETURN  */
#line 475 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2110 "y.tab.c"
    break;

  case 55: /* looping: while  */
#line 483 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2119 "y.tab.c"
    break;

  case 56: /* looping: for  */
#line 488 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2128 "y.tab.c"
    break;

  case 57: /* declaration: datatype declaration_list  */
#line 496 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-1].node));
                add_node((yyval.node), (yyvsp[0].node));            
        }
#line 2140 "y.tab.c"
    break;

  case 58: /* declaration_list: declaration_list ',' array_declaration  */
#line 507 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration_list");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2153 "y.tab.c"
    break;

  case 59: /* declaration_list: declaration_list ',' non_array_declaration  */
#line 516 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration_list");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));

                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2167 "y.tab.c"
    break;

  case 60: /* declaration_list: array_declaration  */
#line 526 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2176 "y.tab.c"
    break;

  case 61: /* declaration_list: non_array_declaration  */
#line 531 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2185 "y.tab.c"
    break;

  case 64: /* array_declaration: IDENTIFIER '[' expression ']' '=' '{' value_list '}'  */
#line 541 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2194 "y.tab.c"
    break;

  case 65: /* array_declaration: IDENTIFIER '[' ']' '=' '{' value_list '}'  */
#line 546 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2203 "y.tab.c"
    break;

  case 66: /* array_declaration: IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_list '}'  */
#line 551 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2212 "y.tab.c"
    break;

  case 67: /* array_declaration: IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_list '}'  */
#line 556 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2221 "y.tab.c"
    break;

  case 68: /* array_declaration: IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_block '}'  */
#line 561 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2230 "y.tab.c"
    break;

  case 69: /* array_declaration: IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_block '}'  */
#line 566 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2239 "y.tab.c"
    break;

  case 71: /* array_declaration: IDENTIFIER '[' expression ']' '=' STRING  */
#line 572 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2248 "y.tab.c"
    break;

  case 72: /* array_declaration: IDENTIFIER '[' ']' '=' STRING  */
#line 577 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2257 "y.tab.c"
    break;

  case 73: /* value_list: primitive_literal  */
#line 585 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2266 "y.tab.c"
    break;

  case 74: /* value_list: value_list ',' primitive_literal  */
#line 590 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);

                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2277 "y.tab.c"
    break;

  case 75: /* value_block: '{' value_list '}'  */
#line 600 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2286 "y.tab.c"
    break;

  case 76: /* value_block: '{' value_list '}' ',' value_block  */
#line 605 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);

                (yyval.node)->data_type = (yyvsp[-3].node)->data_type;
        }
#line 2297 "y.tab.c"
    break;

  case 77: /* non_array_declaration: IDENTIFIER  */
#line 615 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2306 "y.tab.c"
    break;

  case 78: /* non_array_declaration: IDENTIFIER '=' expression  */
#line 620 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node)->data_type = (yyvsp[0].node)->data_type;
        }
#line 2315 "y.tab.c"
    break;

  case 79: /* expression: '!' expression  */
#line 628 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2325 "y.tab.c"
    break;

  case 80: /* expression: '+' expression  */
#line 634 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2335 "y.tab.c"
    break;

  case 81: /* expression: '-' expression  */
#line 640 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2345 "y.tab.c"
    break;

  case 82: /* expression: expression '+' expression  */
#line 646 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2357 "y.tab.c"
    break;

  case 83: /* expression: expression '-' expression  */
#line 654 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2369 "y.tab.c"
    break;

  case 84: /* expression: expression '*' expression  */
#line 662 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2381 "y.tab.c"
    break;

  case 85: /* expression: expression '/' expression  */
#line 670 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2393 "y.tab.c"
    break;

  case 86: /* expression: expression '%' expression  */
#line 678 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));

                if((yyvsp[-2].node)->data_type != 1 || (yyvsp[0].node)->data_type != 0) {
                        yyerror("INT REQUIRED IN %");
                }
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2409 "y.tab.c"
    break;

  case 87: /* expression: expression '<' expression  */
#line 690 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2421 "y.tab.c"
    break;

  case 88: /* expression: expression '>' expression  */
#line 698 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2433 "y.tab.c"
    break;

  case 89: /* expression: expression EQ expression  */
#line 706 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2445 "y.tab.c"
    break;

  case 90: /* expression: expression NE expression  */
#line 714 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2457 "y.tab.c"
    break;

  case 91: /* expression: expression GE expression  */
#line 722 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2469 "y.tab.c"
    break;

  case 92: /* expression: expression LE expression  */
#line 730 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2481 "y.tab.c"
    break;

  case 93: /* expression: expression AND expression  */
#line 738 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2493 "y.tab.c"
    break;

  case 94: /* expression: expression OR expression  */
#line 746 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2505 "y.tab.c"
    break;

  case 95: /* expression: '(' expression ')'  */
#line 754 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2514 "y.tab.c"
    break;

  case 96: /* expression: operand  */
#line 759 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2523 "y.tab.c"
    break;

  case 97: /* operand: variable  */
#line 767 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2532 "y.tab.c"
    break;

  case 98: /* operand: function_call  */
#line 772 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2541 "y.tab.c"
    break;

  case 99: /* operand: primitive_literal  */
#line 777 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2550 "y.tab.c"
    break;

  case 100: /* assignment: variable '=' expression  */
#line 785 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyvsp[-2].node)->data_type = (yyvsp[-1].node)->data_type;
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2562 "y.tab.c"
    break;

  case 101: /* loop_expression: expression  */
#line 796 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2571 "y.tab.c"
    break;

  case 102: /* loop_expression: assignment  */
#line 801 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2580 "y.tab.c"
    break;

  case 103: /* loop_expression: %empty  */
#line 806 "grammer1.y"
        {
                (yyval.node) = NULL;
        }
#line 2588 "y.tab.c"
    break;

  case 104: /* for: FOR '(' loop_expression ';' loop_expression ';' loop_expression ')' statement  */
#line 813 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-8].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2601 "y.tab.c"
    break;

  case 105: /* for: FOR '(' declaration ';' loop_expression ';' loop_expression ')' statement  */
#line 822 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-8].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2614 "y.tab.c"
    break;

  case 106: /* while: WHILE '(' loop_expression ')' statement  */
#line 834 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2625 "y.tab.c"
    break;

  case 107: /* switch: SWITCH '(' expression ')' statement  */
#line 844 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2636 "y.tab.c"
    break;

  case 108: /* case: CASE integer_literal ':' statement  */
#line 854 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2647 "y.tab.c"
    break;

  case 109: /* case: DEFAULT ':' statement  */
#line 861 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-2].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2657 "y.tab.c"
    break;

  case 110: /* if: IF '(' expression ')' statement  */
#line 870 "grammer1.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2668 "y.tab.c"
    break;

  case 111: /* if: IF '(' expression ')' statement ELSE statement  */
#line 877 "grammer1.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2680 "y.tab.c"
    break;


#line 2684 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 886 "grammer1.y"


void yyerror(const char* s) {
    printf("%s", s);
    exit(0);
    return;
}

int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    return 0;
}
