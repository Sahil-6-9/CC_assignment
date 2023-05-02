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
#line 1 "grammer2.y"

    #include <stdio.h> 
    #include <string.h>
    #include "ast.h"

    int yylex(void);
    extern FILE *yyin;
    extern int yylineno;
    extern char* yytext; 

    struct SymbolTable {
	    char name[30];
	    int return_type;
        int num_parameters;
        int parameter_types[100];
	    struct TreeNode* definition;
        char symbol[50][30];
    };

    struct SymbolTable symbol_table[100];
    int num_symbols = 0;
    int num_functions = 0;
    int current_scope = 0;

    struct TreeNode* add_node(struct TreeNode* root, struct TreeNode* child) {
        root->children[root->num_child++] = child;
        return root;
    }

    void preorderTraversal(TreeNode* root)
    {
            if(!root)
                    return;

            printf("%s\n", root->name);
            for(int i=0; i<root->num_child; i++)
            {
                    preorderTraversal(root->children[i]);
            }
    }


#line 114 "y.tab.c"

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
    VOID = 258,                    /* VOID  */
    CHARACTER = 259,               /* CHARACTER  */
    PRINTFF = 260,                 /* PRINTFF  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    CHAR = 263,                    /* CHAR  */
    FOR = 264,                     /* FOR  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    DEFAULT = 270,                 /* DEFAULT  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    TRUE = 273,                    /* TRUE  */
    FALSE = 274,                   /* FALSE  */
    NUMBER = 275,                  /* NUMBER  */
    FLOAT_NUM = 276,               /* FLOAT_NUM  */
    ID = 277,                      /* ID  */
    STR = 278,                     /* STR  */
    RETURN = 279,                  /* RETURN  */
    MAIN = 280,                    /* MAIN  */
    OR = 281,                      /* OR  */
    AND = 282,                     /* AND  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    LE = 285,                      /* LE  */
    GE = 286,                      /* GE  */
    LT = 287,                      /* LT  */
    GT = 288,                      /* GT  */
    ADD = 289,                     /* ADD  */
    SUBTRACT = 290,                /* SUBTRACT  */
    MULTIPLY = 291,                /* MULTIPLY  */
    DIVIDE = 292,                  /* DIVIDE  */
    MODULO = 293,                  /* MODULO  */
    NOT = 294                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define CHARACTER 259
#define PRINTFF 260
#define INT 261
#define FLOAT 262
#define CHAR 263
#define FOR 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define SWITCH 268
#define CASE 269
#define DEFAULT 270
#define BREAK 271
#define CONTINUE 272
#define TRUE 273
#define FALSE 274
#define NUMBER 275
#define FLOAT_NUM 276
#define ID 277
#define STR 278
#define RETURN 279
#define MAIN 280
#define OR 281
#define AND 282
#define EQ 283
#define NE 284
#define LE 285
#define GE 286
#define LT 287
#define GT 288
#define ADD 289
#define SUBTRACT 290
#define MULTIPLY 291
#define DIVIDE 292
#define MODULO 293
#define NOT 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "grammer2.y"
 
    struct TreeNode* nd_obj; 

#line 249 "y.tab.c"

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
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_PRINTFF = 5,                    /* PRINTFF  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_TRUE = 18,                      /* TRUE  */
  YYSYMBOL_FALSE = 19,                     /* FALSE  */
  YYSYMBOL_NUMBER = 20,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 21,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_STR = 23,                       /* STR  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_MAIN = 25,                      /* MAIN  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_EQ = 29,                        /* EQ  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_ADD = 35,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 36,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 37,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 38,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 39,                    /* MODULO  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_functions = 52,                 /* functions  */
  YYSYMBOL_function = 53,                  /* function  */
  YYSYMBOL_functionParameters = 54,        /* functionParameters  */
  YYSYMBOL_functionParameter = 55,         /* functionParameter  */
  YYSYMBOL_main = 56,                      /* main  */
  YYSYMBOL_datatype = 57,                  /* datatype  */
  YYSYMBOL_body = 58,                      /* body  */
  YYSYMBOL_ifStatement = 59,               /* ifStatement  */
  YYSYMBOL_printStatement = 60,            /* printStatement  */
  YYSYMBOL_else = 61,                      /* else  */
  YYSYMBOL_cases = 62,                     /* cases  */
  YYSYMBOL_case = 63,                      /* case  */
  YYSYMBOL_condition = 64,                 /* condition  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_variablelist = 66,              /* variablelist  */
  YYSYMBOL_variable = 67,                  /* variable  */
  YYSYMBOL_array = 68,                     /* array  */
  YYSYMBOL_valueList = 69,                 /* valueList  */
  YYSYMBOL_valueBlock = 70,                /* valueBlock  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_arrayAccess = 72,               /* arrayAccess  */
  YYSYMBOL_relop = 73,                     /* relop  */
  YYSYMBOL_value = 74,                     /* value  */
  YYSYMBOL_return = 75                     /* return  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   390

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    66,    67,    70,    85,    93,    99,
     104,   138,   152,   157,   162,   167,   174,   183,   188,   195,
     202,   207,   213,   219,   222,   232,   238,   245,   252,   257,
     263,   271,   281,   289,   295,   303,   310,   319,   325,   330,
     337,   343,   349,   354,   361,   367,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   386,   387,   390,   391,
     394,   400,   407,   414,   421,   428,   435,   442,   449,   456,
     463,   470,   477,   484,   491,   496,   501,   508,   513,   520,
     525,   530,   535,   540,   545,   552,   557,   562,   567,   573,
     578,   585
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
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "CHARACTER",
  "PRINTFF", "INT", "FLOAT", "CHAR", "FOR", "IF", "ELSE", "WHILE",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "TRUE", "FALSE",
  "NUMBER", "FLOAT_NUM", "ID", "STR", "RETURN", "MAIN", "'='", "OR", "AND",
  "EQ", "NE", "LE", "GE", "LT", "GT", "ADD", "SUBTRACT", "MULTIPLY",
  "DIVIDE", "MODULO", "NOT", "'('", "')'", "'{'", "'}'", "','", "';'",
  "':'", "'['", "']'", "$accept", "program", "functions", "function",
  "functionParameters", "functionParameter", "main", "datatype", "body",
  "ifStatement", "printStatement", "else", "cases", "case", "condition",
  "statement", "variablelist", "variable", "array", "valueList",
  "valueBlock", "expression", "arrayAccess", "relop", "value", "return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     173,  -122,  -122,  -122,  -122,    12,   173,  -122,  -122,    55,
    -122,  -122,  -122,    -2,    35,   173,    19,    40,  -122,     3,
      47,    51,   173,  -122,   243,   243,  -122,    37,    42,    59,
      61,    63,  -122,  -122,    84,    20,   105,   243,  -122,   107,
    -122,   243,   142,    81,    71,    71,   108,    71,  -122,  -122,
    -122,  -122,   129,   -16,   137,  -122,  -122,   243,   140,  -122,
     144,   141,   153,   181,   156,    71,    71,   260,  -122,  -122,
     276,   165,   308,  -122,    71,   -15,   207,  -122,  -122,   207,
     199,    95,    71,  -122,   292,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,   204,   214,
     215,   241,   212,   -13,   -11,  -122,  -122,   137,  -122,  -122,
    -122,   216,   117,   182,  -122,   320,   331,   340,   340,   187,
     187,   187,   187,   -20,   -20,  -122,  -122,  -122,   243,   243,
      94,   -10,   -17,   210,    71,    81,  -122,  -122,  -122,  -122,
    -122,  -122,    20,   218,    57,   116,   244,   234,   219,    94,
     -12,   262,  -122,    20,   235,   308,   258,  -122,    71,   272,
    -122,   238,   243,  -122,  -122,  -122,    20,   252,    90,  -122,
     290,   274,   205,   289,  -122,   243,   243,    92,   307,  -122,
      20,   337,   243,  -122,   243,   243,  -122,   338,  -122,     0,
     161,   184,     0,    20,    97,    99,  -122,  -122,   111,   118,
     154,  -122,  -122,   339,  -122,  -122,  -122,    20,   158,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    12,    13,    14,     0,     0,     5,     3,     0,
       1,     4,     2,     0,     0,     9,     0,     0,     8,     0,
       0,     0,     0,    10,    91,    91,     7,     0,     0,     0,
       0,     0,    38,    39,     0,    89,     0,    91,    17,     0,
      23,    91,     0,     0,    89,    89,     0,    89,    87,    85,
      86,    88,     0,    45,    35,    42,    43,    21,    23,    20,
      23,    26,     0,     0,    88,    89,    89,     0,    76,    75,
       0,     0,    36,    90,    89,     0,     0,    11,     6,     0,
       0,    89,    89,    60,     0,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,     0,     0,
       0,    37,     0,     0,    45,    40,    41,    25,    22,    33,
      34,     0,     0,     0,    74,    73,    72,    65,    66,    63,
      64,    61,    62,    67,    68,    69,    70,    71,    91,    91,
       0,    47,     0,     0,    89,     0,    83,    84,    81,    82,
      79,    80,    89,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    89,     0,    44,     0,    32,    89,    28,
      18,     0,    91,    19,    29,    54,    89,     0,     0,    57,
      48,     0,     0,     0,    24,    91,    30,     0,     0,    46,
      89,     0,    91,    78,    91,    31,    49,     0,    56,    89,
       0,     0,    89,    89,     0,     0,    16,    27,     0,     0,
       0,    51,    53,     0,    50,    52,    59,    89,     0,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,   377,  -122,   362,   379,     8,   -23,  -122,
    -122,  -122,   237,  -122,  -122,   -40,   309,   311,   313,  -121,
     198,   -38,  -122,  -122,   -35,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    17,    18,     8,    36,    57,    38,
      62,   174,   148,   149,   111,    39,    54,    55,    56,   168,
     195,    67,    68,   142,    69,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    37,    41,    63,    48,   102,   152,    70,     9,    72,
      74,   165,    10,   132,     9,   134,   150,    95,    96,    97,
      49,    50,    51,    19,    48,    23,   153,    83,    84,    58,
      19,   166,    75,    60,   103,   133,   101,    75,   151,    15,
      49,    50,    51,   193,   113,   177,   112,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       1,    20,    27,     2,     3,     4,    28,    29,   194,    30,
      31,   198,   200,    32,    33,    48,    16,    13,    42,    34,
      14,    35,    21,    43,     1,    22,   208,     2,     3,     4,
      24,    49,    50,    64,    25,   156,   155,    32,    33,    48,
      44,   159,    45,    34,    46,   144,   145,   157,   146,   147,
      47,    65,    66,   109,   110,    49,    50,    51,   169,     1,
     172,    27,     2,     3,     4,    28,    29,    53,    30,    31,
      71,   169,    32,    33,   179,   180,   186,   180,    34,   176,
      35,   201,   180,   202,   203,   188,   136,   137,   138,   139,
     140,   141,   185,    59,   169,   204,   180,   169,   169,   190,
     160,   191,   205,   203,     1,    61,    27,     2,     3,     4,
      28,    29,   169,    30,    31,    73,     1,    32,    33,     2,
       3,     4,    76,    34,    77,    35,    79,     1,    78,    27,
       2,     3,     4,    28,    29,    80,    30,    31,   206,   180,
      32,    33,   209,   180,    82,   196,    34,   100,    35,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    93,    94,    95,    96,    97,    81,   197,   104,
     154,   143,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   108,     1,   128,    27,     2,
       3,     4,    28,    29,   183,    30,    31,   129,   130,    32,
      33,   131,   135,   163,   161,    34,   158,    35,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   162,   167,   173,   170,   175,   -44,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     171,   178,    98,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   181,   182,    99,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   184,   187,   114,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     189,   192,   207,    11,    26,    12,   164,   105,   107,   106,
     199
};

static const yytype_uint8 yycheck[] =
{
      35,    24,    25,    43,     4,    20,    23,    45,     0,    47,
      26,    23,     0,    26,     6,    26,    26,    37,    38,    39,
      20,    21,    22,    15,     4,    22,    43,    65,    66,    37,
      22,    43,    48,    41,    49,    48,    74,    48,    48,    41,
      20,    21,    22,    43,    82,   166,    81,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       3,    42,     5,     6,     7,     8,     9,    10,   189,    12,
      13,   192,   193,    16,    17,     4,    41,    22,    41,    22,
      25,    24,    42,    41,     3,    45,   207,     6,     7,     8,
      43,    20,    21,    22,    43,   135,   134,    16,    17,     4,
      41,    44,    41,    22,    41,   128,   129,   142,    14,    15,
      26,    40,    41,    18,    19,    20,    21,    22,   153,     3,
     158,     5,     6,     7,     8,     9,    10,    22,    12,    13,
      22,   166,    16,    17,    44,    45,    44,    45,    22,   162,
      24,    44,    45,    44,    45,   180,    29,    30,    31,    32,
      33,    34,   175,    46,   189,    44,    45,   192,   193,   182,
      44,   184,    44,    45,     3,    23,     5,     6,     7,     8,
       9,    10,   207,    12,    13,    46,     3,    16,    17,     6,
       7,     8,    45,    22,    44,    24,    45,     3,    44,     5,
       6,     7,     8,     9,    10,    42,    12,    13,    44,    45,
      16,    17,    44,    45,    48,    44,    22,    42,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    35,    36,    37,    38,    39,    46,    44,    22,
      20,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    46,     3,    43,     5,     6,
       7,     8,     9,    10,    49,    12,    13,    43,    43,    16,
      17,    49,    46,    44,    20,    22,    48,    24,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    47,    20,    11,    49,    47,    45,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      42,    49,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    26,    43,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    43,    26,    42,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      43,    43,    43,     6,    22,     6,   149,    76,    79,    76,
     192
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,    51,    52,    53,    56,    57,
       0,    53,    56,    22,    25,    41,    41,    54,    55,    57,
      42,    42,    45,    22,    43,    43,    55,     5,     9,    10,
      12,    13,    16,    17,    22,    24,    57,    58,    59,    65,
      75,    58,    41,    41,    41,    41,    41,    26,     4,    20,
      21,    22,    74,    22,    66,    67,    68,    58,    75,    46,
      75,    23,    60,    65,    22,    40,    41,    71,    72,    74,
      71,    22,    71,    46,    26,    48,    45,    44,    44,    45,
      42,    46,    48,    71,    71,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    42,    42,
      42,    71,    20,    49,    22,    67,    68,    66,    46,    18,
      19,    64,    74,    71,    42,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    43,    43,
      43,    49,    26,    48,    26,    46,    29,    30,    31,    32,
      33,    34,    73,    49,    58,    58,    14,    15,    62,    63,
      26,    48,    23,    43,    20,    71,    65,    74,    48,    44,
      44,    20,    47,    44,    62,    23,    43,    20,    69,    74,
      49,    42,    71,    11,    61,    47,    58,    69,    49,    44,
      45,    26,    43,    49,    43,    58,    44,    26,    74,    43,
      58,    58,    43,    43,    69,    70,    44,    44,    69,    70,
      69,    44,    44,    45,    44,    44,    44,    43,    69,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    54,    54,    54,
      55,    56,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     9,     3,     1,     0,
       2,     8,     1,     1,     1,     1,    11,     1,     7,     7,
       2,     2,     5,     1,     8,     3,     1,     4,     0,     2,
       3,     4,     3,     1,     1,     2,     3,     4,     1,     1,
       3,     3,     1,     1,     3,     1,     7,     4,     6,     8,
      11,    10,    11,    10,     6,     5,     3,     1,     5,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     4,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     0
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
  case 6: /* function: datatype ID '(' functionParameters ')' '{' body return '}'  */
#line 71 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-7].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-5].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));

    symbol_table[num_functions].definition = (yyval.nd_obj);
    strcpy(symbol_table[num_functions].name, (yyvsp[-7].nd_obj)->name);

    num_functions++;
}
#line 1482 "y.tab.c"
    break;

  case 7: /* functionParameters: functionParameters ',' functionParameter  */
#line 86 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy((yyval.nd_obj)->name, "formalParameters");
    (yyval.nd_obj)->num_child = 0;
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1494 "y.tab.c"
    break;

  case 8: /* functionParameters: functionParameter  */
#line 94 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1503 "y.tab.c"
    break;

  case 9: /* functionParameters: %empty  */
#line 99 "grammer2.y"
{
    (yyval.nd_obj) = NULL;
}
#line 1511 "y.tab.c"
    break;

  case 10: /* functionParameter: datatype ID  */
#line 105 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1520 "y.tab.c"
    break;

  case 11: /* main: datatype MAIN '(' ')' '{' body return '}'  */
#line 139 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-6].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));

    symbol_table[num_functions].definition = (yyval.nd_obj);
    strcpy(symbol_table[num_functions].name, (yyvsp[-6].nd_obj)->name);

    num_functions++;
}
#line 1536 "y.tab.c"
    break;

  case 12: /* datatype: INT  */
#line 153 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1545 "y.tab.c"
    break;

  case 13: /* datatype: FLOAT  */
#line 158 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1554 "y.tab.c"
    break;

  case 14: /* datatype: CHAR  */
#line 163 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1563 "y.tab.c"
    break;

  case 15: /* datatype: VOID  */
#line 168 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1572 "y.tab.c"
    break;

  case 16: /* body: FOR '(' statement ';' condition ';' statement ')' '{' body '}'  */
#line 175 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-10].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-8].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-6].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-4].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));
}
#line 1585 "y.tab.c"
    break;

  case 17: /* body: ifStatement  */
#line 184 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1594 "y.tab.c"
    break;

  case 18: /* body: WHILE '(' expression ')' '{' body '}'  */
#line 189 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-6].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-4].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));
}
#line 1605 "y.tab.c"
    break;

  case 19: /* body: SWITCH '(' ID ')' '{' cases '}'  */
#line 196 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-6].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-4].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));
}
#line 1616 "y.tab.c"
    break;

  case 20: /* body: statement ';'  */
#line 203 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1625 "y.tab.c"
    break;

  case 21: /* body: body body  */
#line 208 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1635 "y.tab.c"
    break;

  case 22: /* body: PRINTFF '(' printStatement ')' ';'  */
#line 214 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-4].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
}
#line 1645 "y.tab.c"
    break;

  case 24: /* ifStatement: IF '(' expression ')' '{' body '}' else  */
#line 223 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-7].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-5].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1657 "y.tab.c"
    break;

  case 25: /* printStatement: STR ',' variablelist  */
#line 233 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1667 "y.tab.c"
    break;

  case 26: /* printStatement: STR  */
#line 239 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1676 "y.tab.c"
    break;

  case 27: /* else: ELSE '{' body '}'  */
#line 246 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-3].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));
}
#line 1686 "y.tab.c"
    break;

  case 28: /* else: %empty  */
#line 252 "grammer2.y"
{
    (yyval.nd_obj) = NULL;
}
#line 1694 "y.tab.c"
    break;

  case 29: /* cases: case cases  */
#line 258 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1704 "y.tab.c"
    break;

  case 30: /* cases: DEFAULT ':' body  */
#line 264 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1714 "y.tab.c"
    break;

  case 31: /* case: CASE NUMBER ':' body  */
#line 272 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-3].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));

}
#line 1726 "y.tab.c"
    break;

  case 32: /* condition: value relop value  */
#line 282 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[-1].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));

}
#line 1738 "y.tab.c"
    break;

  case 33: /* condition: TRUE  */
#line 290 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);

}
#line 1748 "y.tab.c"
    break;

  case 34: /* condition: FALSE  */
#line 296 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);

}
#line 1758 "y.tab.c"
    break;

  case 35: /* statement: datatype variablelist  */
#line 304 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));

}
#line 1769 "y.tab.c"
    break;

  case 36: /* statement: ID '=' expression  */
#line 311 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
    add_node((yyval.nd_obj), (yyvsp[-2].nd_obj));


}
#line 1782 "y.tab.c"
    break;

  case 37: /* statement: datatype ID '=' expression  */
#line 319 "grammer2.y"
                             {
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
    add_node((yyval.nd_obj),(yyvsp[-2].nd_obj));
}
#line 1793 "y.tab.c"
    break;

  case 38: /* statement: BREAK  */
#line 326 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1802 "y.tab.c"
    break;

  case 39: /* statement: CONTINUE  */
#line 331 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1811 "y.tab.c"
    break;

  case 40: /* variablelist: variablelist ',' variable  */
#line 338 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1821 "y.tab.c"
    break;

  case 41: /* variablelist: variablelist ',' array  */
#line 344 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1831 "y.tab.c"
    break;

  case 42: /* variablelist: variable  */
#line 350 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1840 "y.tab.c"
    break;

  case 43: /* variablelist: array  */
#line 355 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1849 "y.tab.c"
    break;

  case 44: /* variable: ID '=' expression  */
#line 362 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyval.nd_obj), (yyvsp[0].nd_obj));
}
#line 1859 "y.tab.c"
    break;

  case 45: /* variable: ID  */
#line 368 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 1868 "y.tab.c"
    break;

  case 60: /* expression: NOT expression  */
#line 395 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1878 "y.tab.c"
    break;

  case 61: /* expression: expression LT expression  */
#line 401 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1889 "y.tab.c"
    break;

  case 62: /* expression: expression GT expression  */
#line 408 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1900 "y.tab.c"
    break;

  case 63: /* expression: expression LE expression  */
#line 415 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1911 "y.tab.c"
    break;

  case 64: /* expression: expression GE expression  */
#line 422 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1922 "y.tab.c"
    break;

  case 65: /* expression: expression EQ expression  */
#line 429 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1933 "y.tab.c"
    break;

  case 66: /* expression: expression NE expression  */
#line 436 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1944 "y.tab.c"
    break;

  case 67: /* expression: expression ADD expression  */
#line 443 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1955 "y.tab.c"
    break;

  case 68: /* expression: expression SUBTRACT expression  */
#line 450 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1966 "y.tab.c"
    break;

  case 69: /* expression: expression MULTIPLY expression  */
#line 457 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1977 "y.tab.c"
    break;

  case 70: /* expression: expression DIVIDE expression  */
#line 464 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1988 "y.tab.c"
    break;

  case 71: /* expression: expression MODULO expression  */
#line 471 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 1999 "y.tab.c"
    break;

  case 72: /* expression: expression AND expression  */
#line 478 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 2010 "y.tab.c"
    break;

  case 73: /* expression: expression OR expression  */
#line 485 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    add_node((yyvsp[-1].nd_obj), (yyvsp[-2].nd_obj));
    add_node((yyvsp[-1].nd_obj), (yyvsp[0].nd_obj));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 2021 "y.tab.c"
    break;

  case 74: /* expression: '(' expression ')'  */
#line 492 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-1].nd_obj);
}
#line 2030 "y.tab.c"
    break;

  case 75: /* expression: value  */
#line 497 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2039 "y.tab.c"
    break;

  case 76: /* expression: arrayAccess  */
#line 502 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2048 "y.tab.c"
    break;

  case 77: /* arrayAccess: ID '[' expression ']'  */
#line 509 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-3].nd_obj);
}
#line 2057 "y.tab.c"
    break;

  case 78: /* arrayAccess: ID '[' expression ']' '[' expression ']'  */
#line 514 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-6].nd_obj);
}
#line 2066 "y.tab.c"
    break;

  case 79: /* relop: LT  */
#line 521 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2075 "y.tab.c"
    break;

  case 80: /* relop: GT  */
#line 526 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2084 "y.tab.c"
    break;

  case 81: /* relop: LE  */
#line 531 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2093 "y.tab.c"
    break;

  case 82: /* relop: GE  */
#line 536 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2102 "y.tab.c"
    break;

  case 83: /* relop: EQ  */
#line 541 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2111 "y.tab.c"
    break;

  case 84: /* relop: NE  */
#line 546 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2120 "y.tab.c"
    break;

  case 85: /* value: NUMBER  */
#line 553 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2129 "y.tab.c"
    break;

  case 86: /* value: FLOAT_NUM  */
#line 558 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2138 "y.tab.c"
    break;

  case 87: /* value: CHARACTER  */
#line 563 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2147 "y.tab.c"
    break;

  case 88: /* value: ID  */
#line 568 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[0].nd_obj);
}
#line 2156 "y.tab.c"
    break;

  case 89: /* value: %empty  */
#line 573 "grammer2.y"
{
    (yyval.nd_obj) = NULL;
}
#line 2164 "y.tab.c"
    break;

  case 90: /* return: RETURN value ';'  */
#line 579 "grammer2.y"
{
    (yyval.nd_obj) = (TreeNode*)malloc(sizeof(TreeNode));
    (yyval.nd_obj) = (yyvsp[-2].nd_obj);
    add_node((yyvsp[-2].nd_obj), (yyvsp[-1].nd_obj));
}
#line 2174 "y.tab.c"
    break;

  case 91: /* return: %empty  */
#line 585 "grammer2.y"
{
    (yyval.nd_obj) = NULL;
}
#line 2182 "y.tab.c"
    break;


#line 2186 "y.tab.c"

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

#line 590 "grammer2.y"


int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    for(int i=0; i<num_functions; i++) {
        preorderTraversal(symbol_table[i].definition);
    }
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s : %d : %s\n", msg, yylineno, yytext);
}
