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
#line 1 "grammer.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    extern FILE* yyin;
    extern int countn;
    extern char* yytext;
    struct Quadruple {
        int index;
        char Op[20];
        char arg1[20];
        char arg2[20];
        char result[20];
    } quad_node[1000];
    int cnt=0;
    int label = 0;
    int arr[100];
    int top = -1;
    int tempVariable = 0;
    char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", id);
        return temp;
    }
    int gencode(char* lhs, char* op, char* rhs){
        printf("T%d = %s%s%s\n", tempVariable, lhs, op, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,op);
        strcpy(quad_node[cnt].arg1,lhs);
        strcpy(quad_node[cnt].arg2,rhs);
        char temp_var[5]="T";
        char temp_1[5]="";
        sprintf(temp_1, "%d", tempVariable);
        strcat(temp_var,temp_1);
        strcpy(quad_node[cnt].result,temp_var);
        cnt++;
        return tempVariable;
    }
    void assignment(char* lhs, char* rhs){
        printf("%s = %s \n", lhs, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,"=");
        strcpy(quad_node[cnt].arg1,rhs);
        strcpy(quad_node[cnt].arg2,"");
        strcpy(quad_node[cnt].result,lhs);
        cnt++;
    }


#line 127 "y.tab.c"

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
#line 57 "grammer.y"

    char* lexeme;

#line 262 "y.tab.c"

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
  YYSYMBOL_functionCall = 56,              /* functionCall  */
  YYSYMBOL_actualParameters = 57,          /* actualParameters  */
  YYSYMBOL_main = 58,                      /* main  */
  YYSYMBOL_datatype = 59,                  /* datatype  */
  YYSYMBOL_body = 60,                      /* body  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_ifStatement = 65,               /* ifStatement  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_elseStatment = 68,              /* elseStatment  */
  YYSYMBOL_printStatement = 69,            /* printStatement  */
  YYSYMBOL_cases = 70,                     /* cases  */
  YYSYMBOL_case = 71,                      /* case  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_variablelist = 73,              /* variablelist  */
  YYSYMBOL_variable = 74,                  /* variable  */
  YYSYMBOL_array = 75,                     /* array  */
  YYSYMBOL_valueList = 76,                 /* valueList  */
  YYSYMBOL_valueBlock = 77,                /* valueBlock  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_arrayAccess = 79,               /* arrayAccess  */
  YYSYMBOL_value = 80,                     /* value  */
  YYSYMBOL_return = 81                     /* return  */
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
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

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
       0,    72,    72,    73,    76,    77,    80,    84,    85,    86,
      89,    92,    96,    97,   101,   105,   106,   107,   108,   112,
     112,   112,   112,   113,   114,   114,   115,   116,   117,   118,
     119,   122,   122,   122,   125,   126,   127,   130,   131,   134,
     135,   138,   151,   152,   156,   160,   163,   164,   167,   168,
     169,   170,   173,   177,   178,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   194,   195,   198,   199,   202,
     208,   214,   220,   226,   232,   238,   244,   250,   256,   262,
     268,   274,   280,   286,   287,   288,   290,   293,   308,   319,
     320,   321,   322,   323,   326,   327
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
  "functionParameters", "functionParameter", "functionCall",
  "actualParameters", "main", "datatype", "body", "$@1", "$@2", "$@3",
  "$@4", "ifStatement", "$@5", "$@6", "elseStatment", "printStatement",
  "cases", "case", "statement", "variablelist", "variable", "array",
  "valueList", "valueBlock", "expression", "arrayAccess", "value",
  "return", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,  -161,  -161,  -161,  -161,    12,    78,  -161,  -161,    17,
    -161,  -161,  -161,    31,    37,    78,   -26,     4,  -161,    60,
      51,    58,    78,   -15,  -161,  -161,   341,   341,  -161,    89,
      89,    71,    84,    87,  -161,   102,  -161,  -161,   -11,    99,
     118,   341,  -161,   108,   129,  -161,   341,  -161,  -161,  -161,
       9,    89,    89,  -161,   439,  -161,  -161,   280,   134,  -161,
      89,   120,   141,    89,  -161,   123,    -7,   125,  -161,  -161,
     341,   124,  -161,    89,   127,    60,  -161,   391,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,   128,   130,   136,   376,   407,    89,   137,   439,  -161,
      89,    67,   150,  -161,   439,  -161,    32,  -161,  -161,   451,
     462,   471,   471,   110,   110,   110,   110,    76,    76,  -161,
    -161,  -161,    89,   150,   135,  -161,  -161,   423,   140,   372,
     138,    -3,    -1,  -161,  -161,   139,    60,   303,   125,  -161,
     144,   143,   148,  -161,     0,   -13,   164,  -161,  -161,  -161,
    -161,   341,   341,    40,     1,   172,  -161,    99,   152,    89,
     190,   213,   184,   158,  -161,  -161,    99,   159,    47,  -161,
     183,   339,  -161,  -161,   163,   341,    54,   185,  -161,    99,
     170,   376,   204,   341,   236,  -161,   174,  -161,    75,   182,
      -5,  -161,   341,  -161,    75,    99,    61,    79,   188,   341,
    -161,    91,    93,   107,  -161,  -161,   189,   341,   259,  -161,
    -161,  -161,    99,   282,  -161,   122,  -161,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    15,    16,    17,     0,     0,     5,     3,     0,
       1,     4,     2,     0,     0,     9,     0,     0,     8,     0,
       0,     0,     0,    53,    10,    54,    95,    95,     7,    93,
      93,     0,     0,     0,    24,     0,    46,    47,     0,    93,
       0,    95,    23,     0,     0,    30,    95,    91,    89,    90,
      92,    93,    93,    86,    52,    85,    84,     0,     0,    19,
      93,     0,     0,    93,    92,     0,    53,    42,    50,    51,
      28,    30,    27,    93,    30,     0,    69,     0,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    87,    38,     0,     0,     0,    93,     0,    43,    94,
      93,    93,     0,    14,    45,     6,     0,    13,    83,    82,
      81,    74,    75,    72,    73,    70,    71,    76,    77,    78,
      79,    80,    93,     0,     0,    20,    31,     0,     0,    44,
      89,     0,    53,    48,    49,     0,     0,     0,    37,    29,
       0,     0,     0,    40,    56,     0,     0,    11,    12,    88,
      21,    95,    95,     0,     0,     0,    64,    93,     0,    93,
       0,     0,     0,     0,    39,    63,    93,     0,     0,    66,
      57,     0,    32,    25,     0,    95,     0,     0,    55,    93,
       0,     0,    36,    95,     0,    58,     0,    65,    93,     0,
       0,    33,    41,    26,    93,    93,     0,     0,     0,    95,
      35,     0,     0,     0,    60,    62,     0,    95,     0,    59,
      61,    68,    93,     0,    34,     0,    22,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   221,  -161,   206,  -161,  -161,   227,    14,
     -25,  -161,  -161,  -161,  -161,    46,  -161,  -161,  -161,  -161,
    -161,  -161,   -91,   115,    -2,   145,  -160,    56,   -20,   -19,
     -35,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    17,    18,    53,   106,     8,    40,
      70,    94,   140,   159,    61,    42,   141,   182,   191,    93,
     153,   164,    43,    67,    68,    69,   168,   197,    57,    55,
      56,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    41,    46,   125,    65,    33,   176,    44,    44,    54,
     156,    29,    10,    71,     9,    63,    20,    24,    74,   100,
       9,    25,    44,   145,   165,    29,   154,    44,   196,    19,
     157,    76,    77,    30,   201,   203,    19,    30,   199,    13,
      95,   101,    14,    98,   166,   146,    21,   101,   155,    22,
      75,    44,   215,   104,   162,   163,    25,    30,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    47,    15,   107,   135,    44,   127,   136,    16,    47,
     129,     1,    23,    25,     2,     3,     4,   130,    49,    50,
     189,   178,   179,    47,    26,    48,    49,    64,   185,   179,
     133,    27,   137,    47,    25,   204,   179,    51,    52,    48,
      49,    50,    58,    88,    89,    90,   131,    25,   195,    48,
      49,    64,   169,   205,   206,    59,   160,   161,    60,    51,
      52,   169,    44,    44,   148,   209,   179,   210,   206,   171,
      66,    44,    44,    62,   187,    86,    87,    88,    89,    90,
     184,   211,   179,   169,    72,    73,    44,    92,   192,   169,
     169,    96,    44,    97,    44,    44,   217,   179,   103,    99,
     102,   105,   132,    44,   208,   123,   122,   169,   124,   128,
      44,   139,   213,   143,   158,   147,   151,   144,    44,    44,
     150,   152,   167,     1,    44,    31,     2,     3,     4,    32,
      33,   170,    34,    35,   174,   175,    36,    37,   177,   180,
     183,   186,    38,   188,    39,   190,     1,   194,    31,     2,
       3,     4,    32,    33,   198,    34,    35,    11,    28,    36,
      37,   207,   212,    12,   172,    38,   200,    39,   138,     1,
       0,    31,     2,     3,     4,    32,    33,   134,    34,    35,
     202,     0,    36,    37,     0,     0,     0,   173,    38,     0,
      39,     0,     1,     0,    31,     2,     3,     4,    32,    33,
       0,    34,    35,     0,     0,    36,    37,     0,     0,     0,
     193,    38,     0,    39,     0,     1,     0,    31,     2,     3,
       4,    32,    33,     0,    34,    35,     0,     0,    36,    37,
       0,     0,     0,   214,    38,     0,    39,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,     0,   216,     0,     0,    91,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     1,     0,    31,     2,     3,     4,
      32,    33,   149,    34,    35,     0,     0,    36,    37,     0,
       0,     0,     0,    38,     0,    39,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     1,
       0,     0,     2,     3,     4,   181,     0,     0,     0,     0,
       0,     0,    36,    37,     0,     0,     0,     0,    38,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,   -52,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,   108,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   126,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,   142,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    82,    83,    84,    85,    86,    87,    88,    89,
      90
};

static const yytype_int16 yycheck[] =
{
      19,    26,    27,    94,    39,    10,   166,    26,    27,    29,
      23,    26,     0,    41,     0,    26,    42,    19,    46,    26,
       6,    40,    41,    26,    23,    26,    26,    46,   188,    15,
      43,    51,    52,    48,   194,   195,    22,    48,    43,    22,
      60,    48,    25,    63,    43,    48,    42,    48,    48,    45,
      41,    70,   212,    73,    14,    15,    75,    48,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     4,    41,    75,    42,    94,    96,    45,    41,     4,
     100,     3,    22,   102,     6,     7,     8,    20,    21,    22,
     181,    44,    45,     4,    43,    20,    21,    22,    44,    45,
     102,    43,   122,     4,   123,    44,    45,    40,    41,    20,
      21,    22,    41,    37,    38,    39,    49,   136,    43,    20,
      21,    22,   157,    44,    45,    41,   151,   152,    41,    40,
      41,   166,   151,   152,   136,    44,    45,    44,    45,   159,
      22,   160,   161,    41,   179,    35,    36,    37,    38,    39,
     175,    44,    45,   188,    46,    26,   175,    23,   183,   194,
     195,    41,   181,    22,   183,   184,    44,    45,    44,    46,
      45,    44,    22,   192,   199,    45,    48,   212,    42,    42,
     199,    46,   207,    43,    20,    46,    43,    49,   207,   208,
      46,    43,    20,     3,   213,     5,     6,     7,     8,     9,
      10,    49,    12,    13,    20,    47,    16,    17,    49,    26,
      47,    26,    22,    43,    24,    11,     3,    43,     5,     6,
       7,     8,     9,    10,    42,    12,    13,     6,    22,    16,
      17,    43,    43,     6,    44,    22,   190,    24,   123,     3,
      -1,     5,     6,     7,     8,     9,    10,   102,    12,    13,
     194,    -1,    16,    17,    -1,    -1,    -1,    44,    22,    -1,
      24,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    -1,
      44,    22,    -1,    24,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    16,    17,
      -1,    -1,    -1,    44,    22,    -1,    24,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    49,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    49,    12,    13,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,    24,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
      -1,    -1,     6,     7,     8,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    31,    32,    33,    34,    35,    36,    37,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,    51,    52,    53,    58,    59,
       0,    53,    58,    22,    25,    41,    41,    54,    55,    59,
      42,    42,    45,    22,    74,    79,    43,    43,    55,    26,
      48,     5,     9,    10,    12,    13,    16,    17,    22,    24,
      59,    60,    65,    72,    79,    81,    60,     4,    20,    21,
      22,    40,    41,    56,    78,    79,    80,    78,    41,    41,
      41,    64,    41,    26,    22,    80,    22,    73,    74,    75,
      60,    81,    46,    26,    81,    41,    78,    78,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    49,    23,    69,    61,    78,    41,    22,    78,    46,
      26,    48,    45,    44,    78,    44,    57,    74,    42,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    48,    45,    42,    72,    42,    78,    42,    78,
      20,    49,    22,    74,    75,    42,    45,    78,    73,    46,
      62,    66,    42,    43,    49,    26,    48,    46,    74,    49,
      46,    43,    43,    70,    26,    48,    23,    43,    20,    63,
      60,    60,    14,    15,    71,    23,    43,    20,    76,    80,
      49,    78,    44,    44,    20,    47,    76,    49,    44,    45,
      26,    46,    67,    47,    60,    44,    26,    80,    43,    72,
      11,    68,    60,    44,    43,    43,    76,    77,    42,    43,
      65,    76,    77,    76,    44,    44,    45,    43,    60,    44,
      44,    44,    43,    60,    44,    76,    44,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    53,    54,    54,    54,
      55,    56,    57,    57,    58,    59,    59,    59,    59,    61,
      62,    63,    60,    60,    64,    60,    60,    60,    60,    60,
      60,    66,    67,    65,    68,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     9,     3,     1,     0,
       2,     5,     3,     1,     8,     1,     1,     1,     1,     0,
       0,     0,    14,     1,     0,     8,    10,     2,     2,     5,
       1,     0,     0,    10,     4,     2,     0,     3,     1,     2,
       0,     4,     2,     3,     4,     3,     1,     1,     3,     3,
       1,     1,     3,     1,     1,     7,     4,     6,     8,    11,
      10,    11,    10,     6,     5,     3,     1,     5,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     7,     1,
       1,     1,     1,     0,     3,     0
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
  case 15: /* datatype: INT  */
#line 105 "grammer.y"
              { (yyval.lexeme) = (yyvsp[0].lexeme); }
#line 1521 "y.tab.c"
    break;

  case 16: /* datatype: FLOAT  */
#line 106 "grammer.y"
        { (yyval.lexeme) = (yyvsp[0].lexeme); }
#line 1527 "y.tab.c"
    break;

  case 17: /* datatype: CHAR  */
#line 107 "grammer.y"
       { (yyval.lexeme) = (yyvsp[0].lexeme); }
#line 1533 "y.tab.c"
    break;

  case 18: /* datatype: VOID  */
#line 108 "grammer.y"
       { (yyval.lexeme) = (yyvsp[0].lexeme); }
#line 1539 "y.tab.c"
    break;

  case 19: /* $@1: %empty  */
#line 112 "grammer.y"
              {;}
#line 1545 "y.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 112 "grammer.y"
                            {;}
#line 1551 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 112 "grammer.y"
                                  { top++; printf("L%d: \n", label); arr[top] = label; label++; }
#line 1557 "y.tab.c"
    break;

  case 22: /* body: FOR '(' $@1 statement $@2 ';' $@3 expression ';' statement ')' '{' body '}'  */
#line 112 "grammer.y"
                                                                                                                                            {printf("iftrue(%s) goto L%d\n", (yyvsp[-6].lexeme), arr[top--]);}
#line 1563 "y.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 114 "grammer.y"
        { top++; printf("L%d: \n", label); arr[top] = label; label++; }
#line 1569 "y.tab.c"
    break;

  case 25: /* body: WHILE $@4 '(' expression ')' '{' body '}'  */
#line 114 "grammer.y"
                                                                                                       {printf("iftrue(%s) goto L%d\n", (yyvsp[-4].lexeme), arr[top--]);}
#line 1575 "y.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 122 "grammer.y"
                                    { top++; printf("iffalse(%s) goto L%d\n",(yyvsp[-1].lexeme),label); arr[top] = label; label++; }
#line 1581 "y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 122 "grammer.y"
                                                                                                                                  {printf("L%d: \n", arr[top--]);}
#line 1587 "y.tab.c"
    break;

  case 43: /* statement: ID '=' expression  */
#line 152 "grammer.y"
                    {
    assignment((yyvsp[-2].lexeme),(yyvsp[0].lexeme));
    (yyval.lexeme)=(yyvsp[-2].lexeme);
}
#line 1596 "y.tab.c"
    break;

  case 44: /* statement: datatype ID '=' expression  */
#line 156 "grammer.y"
                             {
    assignment((yyvsp[-2].lexeme),(yyvsp[0].lexeme));
    (yyval.lexeme)=(yyvsp[-2].lexeme);
}
#line 1605 "y.tab.c"
    break;

  case 45: /* statement: arrayAccess '=' expression  */
#line 160 "grammer.y"
                             {

}
#line 1613 "y.tab.c"
    break;

  case 52: /* variable: ID '=' expression  */
#line 173 "grammer.y"
                            {
    assignment((yyvsp[-2].lexeme),(yyvsp[0].lexeme));
    (yyval.lexeme)=(yyvsp[-2].lexeme);
}
#line 1622 "y.tab.c"
    break;

  case 69: /* expression: NOT expression  */
#line 202 "grammer.y"
                           {
    int a = gencode("","!",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1633 "y.tab.c"
    break;

  case 70: /* expression: expression LT expression  */
#line 208 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),"<",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1644 "y.tab.c"
    break;

  case 71: /* expression: expression GT expression  */
#line 214 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),">",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1655 "y.tab.c"
    break;

  case 72: /* expression: expression LE expression  */
#line 220 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),"<=",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1666 "y.tab.c"
    break;

  case 73: /* expression: expression GE expression  */
#line 226 "grammer.y"
                          {
    int a = gencode((yyvsp[-2].lexeme),">=",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1677 "y.tab.c"
    break;

  case 74: /* expression: expression EQ expression  */
#line 232 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),"==",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1688 "y.tab.c"
    break;

  case 75: /* expression: expression NE expression  */
#line 238 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),"!=",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1699 "y.tab.c"
    break;

  case 76: /* expression: expression ADD expression  */
#line 244 "grammer.y"
                            {
    int a = gencode((yyvsp[-2].lexeme),"+",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1710 "y.tab.c"
    break;

  case 77: /* expression: expression SUBTRACT expression  */
#line 250 "grammer.y"
                                 {
    int a = gencode((yyvsp[-2].lexeme),"-",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1721 "y.tab.c"
    break;

  case 78: /* expression: expression MULTIPLY expression  */
#line 256 "grammer.y"
                                 {
    int a = gencode((yyvsp[-2].lexeme),"*",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1732 "y.tab.c"
    break;

  case 79: /* expression: expression DIVIDE expression  */
#line 262 "grammer.y"
                               {
    int a = gencode((yyvsp[-2].lexeme),"/",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1743 "y.tab.c"
    break;

  case 80: /* expression: expression MODULO expression  */
#line 268 "grammer.y"
                               {
    int a = gencode((yyvsp[-2].lexeme),"%",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1754 "y.tab.c"
    break;

  case 81: /* expression: expression AND expression  */
#line 274 "grammer.y"
                            {
    int a = gencode((yyvsp[-2].lexeme),"&&",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1765 "y.tab.c"
    break;

  case 82: /* expression: expression OR expression  */
#line 280 "grammer.y"
                           {
    int a = gencode((yyvsp[-2].lexeme),"||",(yyvsp[0].lexeme));
    char* tempVar = genTempVariable(a);
    (yyval.lexeme) = tempVar;
    tempVariable++;
}
#line 1776 "y.tab.c"
    break;

  case 85: /* expression: arrayAccess  */
#line 288 "grammer.y"
              {
    (yyval.lexeme)=(yyvsp[0].lexeme);}
#line 1783 "y.tab.c"
    break;

  case 87: /* arrayAccess: ID '[' expression ']'  */
#line 293 "grammer.y"
                                   {
    int a = gencode("4","*",(yyvsp[-1].lexeme));
    char* tempVar = genTempVariable(a);
    tempVariable++;
    int b = gencode("","&",(yyvsp[-3].lexeme));
    char* tempVar2 = genTempVariable(b);
    tempVariable++;
    int c = gencode(tempVar,"+",tempVar2);
    char* tempVar3 = genTempVariable(c);
    tempVariable++;
    int d = gencode("","*",tempVar3);
    char* tempVar4 = genTempVariable(d);
    tempVariable++;
    (yyval.lexeme) = tempVar4;
}
#line 1803 "y.tab.c"
    break;

  case 92: /* value: ID  */
#line 322 "grammer.y"
     {(yyval.lexeme)=(yyvsp[0].lexeme);}
#line 1809 "y.tab.c"
    break;


#line 1813 "y.tab.c"

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

#line 330 "grammer.y"

 
int main() {
    yyin = fopen("input.txt", "r");
    yyparse();
    printf("ind\top\targ1\targ2\tres\n");
    for(int i=0;i<cnt;i++){
        printf("%d",quad_node[i].index);
        printf("\t");
        printf("%s",quad_node[i].Op);
        printf("\t");
        printf("%s",quad_node[i].arg1);
        printf("\t");
        printf("%s",quad_node[i].arg2);
        printf("\t");
        printf("%s",quad_node[i].result);
        printf("\n");
    }
}
 
void yyerror(const char* msg) {
    fprintf(stderr, "%s : %d : %s\n", msg, countn, yytext);
}
