/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "hw3_1.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>   

  struct Symbol_Table
  {
     char sym_name[10];
     char sym_type[100];
     double value;
     int sym_offset;
  }Sym[10];

  int sym_cnt=0;
  int Index=0;
  int temp_var=1;
  int offset = 0;

  char arr_temp_type[100];
  char arr_temp_name[10];
  char arrName[10];
  char arr_first_temp_type[100];
  char arr_second_temp_type[100];
  int arrcnt = 0;
  int arrStmtCnt = 0;
  int arrcheck = 0;
  int lineNo = 1;

  int first_int_array_param = 0;
  int second_int_array_param = 0;
  char first_char_array_param[2];
  char second_char_array_param[2];



  int search_symbol(char []);
  char* search_symbol_type(char []);
  void make_symtab_entry(char [],char [],double);
  void display_sym_tab();  
  void addQuadruple(char [],char [],char [],char []);
  void display_Quadruple();
  void push(char*, char*);
  char* pop();
  char* make_arr_type(int, char[], char []);
 void strintrude (char *, char *, int);

  struct Quadruple
  {
    char operator[5];
    char operand1[10];
    char operand2[10];
    char result[10];
  }QUAD[25];

 struct Stack
  {
    char *items[10];
    char *types[10];
    int top;
  }Stk;


#line 133 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    DOUBLE = 259,
    TYPE = 260,
    ID = 261,
    MAIN = 262,
    UMINUS = 263,
    UPLUS = 264
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "hw3_1.y"

    int ival;          
    double dval;
    char string[10];
    int arrval;

#line 202 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  83

#define YYUNDEFTOK  2
#define YYMAXUTOK   264


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      14,    15,    10,     8,    19,     9,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
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
       5,     6,     7,    12,    13
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    91,    93,    96,    97,   101,   102,   105,
     114,   122,   125,   134,   157,   158,   162,   163,   164,   165,
     168,   185,   201,   212,   232,   236,   238,   240,   242,   244,
     246,   334,   369,   405,   441,   479,   481,   489,   491,   503,
     509
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DOUBLE", "TYPE", "ID",
  "MAIN", "'+'", "'-'", "'*'", "'/'", "UMINUS", "UPLUS", "'('", "')'",
  "'{'", "'}'", "';'", "','", "'['", "']'", "'='", "$accept", "program",
  "body", "varstmt", "vardecl", "varlist", "arrlist", "stmtlist", "stmt",
  "arrstmt", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    43,    45,
      42,    47,   263,   264,    40,    41,   123,   125,    59,    44,
      91,    93,    61
};
# endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,   -25,   -10,    17,    -6,   -25,    16,    32,     9,    25,
      42,    32,    34,    41,     3,    35,   -25,    50,   -25,   -25,
      80,    76,    76,    76,   -25,    42,    27,    67,   -25,    71,
     -25,    77,   -25,    85,    46,    83,   -25,   -25,   -25,    -3,
     -25,    63,   -25,    81,    76,    76,    76,    76,    87,    74,
     -25,    94,    97,    98,   102,   104,    -2,    88,    54,    76,
      76,   -25,   100,   105,    90,    99,   101,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   103,
     103,   -25,   -25
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     0,     6,     0,     0,
       0,     6,    11,    10,     0,     0,     2,    24,    40,    39,
      38,     0,     0,     0,     4,     0,     0,     0,     5,     0,
       7,     0,     8,     0,     0,     0,    38,    37,    36,     0,
      16,     0,    17,    38,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,    40,    39,    38,     0,     0,     0,
       0,    35,     0,     0,     0,    31,    32,    33,    34,    29,
      12,    13,    25,    27,    20,    21,    22,    30,    23,    31,
      32,    26,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   112,   -25,   -25,   -25,    91,   -25,   -24,
     -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     9,    10,    11,    14,    15,    24,    25,    26,
      27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    38,    39,    48,     4,    59,    60,    46,    47,     6,
      12,    57,    61,     1,    58,    13,    76,     5,    34,     2,
      64,    30,    31,    65,    66,    67,    68,   -14,    17,   -14,
      18,    19,     7,    20,    48,    21,    22,     8,    79,    80,
      57,    23,    16,    17,   -18,    18,    19,    41,    20,    52,
      21,    22,    53,    32,   -15,    33,    23,    18,    19,   -18,
      43,    29,    44,    45,    46,    47,    62,   -19,    23,    63,
      18,    19,    78,    43,    49,    44,    45,    46,    47,    18,
      19,    23,    36,    50,    21,    22,    54,    55,    51,    56,
      23,    21,    22,    18,    19,    70,    43,    23,    21,    22,
      34,    34,    35,    64,    23,    69,    77,    41,    41,   -37,
     -37,   -36,   -36,    46,    47,    71,    40,    42,    72,    73,
      74,    81,    75,    28,     0,     0,    82
};

static const yytype_int8 yycheck[] =
{
      21,    22,    23,    27,    14,     8,     9,    10,    11,    15,
       1,    35,    15,     1,    35,     6,    18,     0,    20,     7,
      22,    18,    19,    44,    45,    46,    47,    18,     1,    20,
       3,     4,    16,     6,    58,     8,     9,     5,    59,    60,
      64,    14,    17,     1,    17,     3,     4,    20,     6,     3,
       8,     9,     6,    18,    20,    20,    14,     3,     4,    17,
       6,    20,     8,     9,    10,    11,     3,    17,    14,     6,
       3,     4,    18,     6,     3,     8,     9,    10,    11,     3,
       4,    14,     6,     6,     8,     9,     3,     4,     3,     6,
      14,     8,     9,     3,     4,    21,     6,    14,     8,     9,
      20,    20,    22,    22,    14,    18,    18,    20,    20,    10,
      11,    10,    11,    10,    11,    21,    25,    26,    21,    21,
      18,    21,    18,    11,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,    24,    14,     0,    15,    16,     5,    25,
      26,    27,     1,     6,    28,    29,    17,     1,     3,     4,
       6,     8,     9,    14,    30,    31,    32,    33,    26,    20,
      18,    19,    18,    20,    20,    22,     6,    33,    33,    33,
      30,    20,    30,     6,     8,     9,    10,    11,    32,     3,
       6,     3,     3,     6,     3,     4,     6,    32,    33,     8,
       9,    15,     3,     6,    22,    33,    33,    33,    33,    18,
      21,    21,    21,    21,    18,    18,    18,    18,    18,    33,
      33,    21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    23,    24,    24,    25,    26,    26,    27,    27,    28,
      28,    28,    29,    29,    29,    29,    30,    30,    30,    30,
      31,    31,    31,    31,    31,    32,    32,    32,    32,    32,
      32,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     2,     2,     0,     3,     3,     3,
       1,     1,     4,     4,     0,     1,     2,     2,     0,     1,
       4,     4,     4,     4,     1,     4,     4,     4,     4,     3,
       4,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 3:
#line 91 "hw3_1.y"
                 { yyerror('재입력하시오\n'); }
#line 1432 "y.tab.c"
    break;

  case 7:
#line 101 "hw3_1.y"
                          {lineNo++;}
#line 1438 "y.tab.c"
    break;

  case 8:
#line 102 "hw3_1.y"
                          {lineNo++;}
#line 1444 "y.tab.c"
    break;

  case 9:
#line 105 "hw3_1.y"
                        {   // 콤마 변수 선언
                            int i;
                            i=search_symbol((yyvsp[0].string));
                            if(i!=-1)
                              yyerror("syntax error: Multiple Declaration of Variable");
                            else
                              make_symtab_entry((yyvsp[0].string),(yyvsp[-3].string),0); // $3를 테이블 엔트리에 저장, 타입은 string타입으로 $0(이 rule이 적용되기 전의 stack의 top위치), val은 0으로 초기화
                        }
#line 1457 "y.tab.c"
    break;

  case 10:
#line 114 "hw3_1.y"
                        {                
                            int i;
                            i=search_symbol((yyvsp[0].string));
                            if(i!=-1)
                              yyerror("syntax error: Multiple Declaration of Variable");
                            else
                              make_symtab_entry((yyvsp[0].string),(yyvsp[-1].string),0);
                        }
#line 1470 "y.tab.c"
    break;

  case 12:
#line 125 "hw3_1.y"
                                {
                                    strcpy(arr_temp_name, (yyvsp[-3].string));
                                    strcpy(arr_first_temp_type, (yyvsp[-4].string));
                                    char arr_type[30] = "array(";
                                    strcpy(arr_temp_type, make_arr_type((yyvsp[-1].ival), arr_first_temp_type, arr_type));
                                    arrcnt++;
                                    make_symtab_entry(arr_temp_name, arr_temp_type, 0);
                                }
#line 1483 "y.tab.c"
    break;

  case 13:
#line 134 "hw3_1.y"
                                {
                                    char* temp;
                                    char* temp1;
                                    char* temp2;
                                    char arr_type[30] = "array(";
                                    // printf("cnt: -----%d----\n", arrcnt);
                                    if(arrcnt>=2) {
                                      // printf("first: %s\n", arr_first_temp_type);
                                      strcpy(arr_second_temp_type, arr_first_temp_type);
                                      strcpy(arr_first_temp_type, "");
                                    }
                                    strcpy(arr_first_temp_type, make_arr_type((yyvsp[-1].ival), "int", arr_type)); // arr(3, int)
                                      if(arrcnt>=2) { // 3차원 배열 타입선언을 위한 코드
                                      memmove(arr_second_temp_type + (arrcnt-1)*8 + 1*(arrcnt-1), arr_first_temp_type, strlen(arr_first_temp_type));
                                      memmove(arr_temp_type + (arrcnt-1)*8 + 1*(arrcnt-1), arr_second_temp_type, strlen(arr_second_temp_type));
                                    } else {
                                      // printf("--\n");
                                      memmove(arr_temp_type + arrcnt*8 + 1*arrcnt, arr_first_temp_type, strlen(arr_first_temp_type));
                                    }
                                    make_symtab_entry(arr_temp_name, arr_temp_type, 0);
                                    arrcnt++;
                                  }
#line 1510 "y.tab.c"
    break;

  case 20:
#line 168 "hw3_1.y"
                          {
                            int i;
                            i=search_symbol((yyvsp[-3].string));
                            if(i==-1)
                              printf("\n Undefined Variable");
                            else {
                              char temp[10];
                              if(strcmp(Sym[i].sym_type,"int")==0) // *****
                                sprintf(temp,"%d",(int)(yyvsp[-1].ival));
                              else
                                  snprintf(temp,10,"%f",(yyvsp[-1].ival));
                              addQuadruple("=","",temp,(yyvsp[-3].string));
                              
                            }
                            lineNo++;
                   }
#line 1531 "y.tab.c"
    break;

  case 21:
#line 185 "hw3_1.y"
                        {
                            int i;
                            i=search_symbol((yyvsp[-3].string));
                            if(i==-1)
                              printf("\n Undefined Variable");
                            else {
                              char temp[10];
                              if(strcmp(Sym[i].sym_type,"int")==0) // *****
                                sprintf(temp,"%d",(int)(yyvsp[-1].dval));
                              else
                                  snprintf(temp,10,"%f",(yyvsp[-1].dval));
                              addQuadruple("=","",temp,(yyvsp[-3].string));
                            }
                            lineNo++;
                   }
#line 1551 "y.tab.c"
    break;

  case 22:
#line 201 "hw3_1.y"
                   {
                        int i,j;
                        i=search_symbol((yyvsp[-3].string));
                        j=search_symbol((yyvsp[-1].string));
                        if(i==-1 || j==-1)
                          printf("\n Undefined Variable");
                        else
                          addQuadruple("=","",(yyvsp[-1].string),(yyvsp[-3].string));
                        lineNo++;
                    }
#line 1566 "y.tab.c"
    break;

  case 23:
#line 212 "hw3_1.y"
                           { 
                              char* temp;
                              char* temp1;
                              char* um = "-";
                              temp = Stk.items[Stk.top];
                              temp1 = Stk.types[Stk.top];
                              // printf("stacktop: %s\n", temp);
                              if(strncmp(temp, um, 1) == 0) { // unary일 경우..
                                char str[5],str1[5]="t";
                                sprintf(str, "%d", temp_var);
                                strcat(str1,str);                   
                                temp_var++;
                                addQuadruple("=","",pop(),str1);
                                push(str1, temp1);
                                addQuadruple("=","",pop(),(yyvsp[-3].string));
                              } else {
                                addQuadruple("=","",pop(),(yyvsp[-3].string));
                              }
                              lineNo++;
                           }
#line 1591 "y.tab.c"
    break;

  case 25:
#line 236 "hw3_1.y"
                                    { first_int_array_param = (yyvsp[-1].ival); arrStmtCnt++;}
#line 1597 "y.tab.c"
    break;

  case 26:
#line 238 "hw3_1.y"
                                    { second_int_array_param = (yyvsp[-1].ival); arrStmtCnt++;}
#line 1603 "y.tab.c"
    break;

  case 27:
#line 240 "hw3_1.y"
                                { strcpy(first_char_array_param, (yyvsp[-1].string)); arrStmtCnt++;}
#line 1609 "y.tab.c"
    break;

  case 28:
#line 242 "hw3_1.y"
                                { strcpy(second_char_array_param, (yyvsp[-1].string)); arrStmtCnt++;}
#line 1615 "y.tab.c"
    break;

  case 30:
#line 246 "hw3_1.y"
                            {
                      // printf("array 중간코드 생성 %d!!!\n", arrcnt);
                      int i;
                      char* k;
                      int t;
                      char*j;
                      char str[5],str1[5]="t";
                      char str2[5], str3[5] ="t";
                      char str4[5], str5[5] ="t";
                      sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                      strcat(str1,str);
                      temp_var++;
                      for(i=0;i<sym_cnt;i++)
                      {
                        if(strncmp(Sym[i].sym_type, "array", 5)==0) // array타입이 심볼 테이블에 있는지 확인
                        {
                          j = Sym[i].sym_type;
                        }
                      }
                      // printf("---%s---\n", j);
                      // printf("---%s---\n", arr_temp_type);
                      // printf("---%c---\n", arr_temp_type[15]);
                      if(arrStmtCnt == 1) {
                          char s1[10];       // 변환한 문자열을 저장할 배열
                          // char s2[10];       // 변환한 문자열을 저장할 배열
                          // char s3[10];       // 변환한 문자열을 저장할 배열
                          if(first_int_array_param != 0){
                            printf("%d\n", first_int_array_param);
                            sprintf(s1, "%d", first_int_array_param);
                            printf("%s\n",s1);
                          }
                          if(first_char_array_param)
                            strcpy(s1, first_char_array_param);
                          // sprintf(s3, "%d", t);
                          addQuadruple("*", "4", s1, str1);
                          strcpy(arrName, arr_temp_name);
                          strcat(arrName, "[");
                          strcat(arrName, str1);
                          strcat(arrName, "]");
                          // printf("%s\n", arrName);
                          sprintf(str4, "%d", temp_var);
                          memmove(str5+1, str4, 1);
                          addQuadruple("=","", arrName, str5);
                      } else if (arrStmtCnt == 2) {
                        //addQuadruple("",pop(),pop(),str1);
                        // printf("first param, second param: %d %d\n", first_int_array_param, second_int_array_param);
                        
                        char s1[10];       // 변환한 문자열을 저장할 배열
                        char s2[10];       // 변환한 문자열을 저장할 배열
                        char s3[10];       // 변환한 문자열을 저장할 배열
                        
                        k = (arr_temp_type + 15);
                        // printf("%d\n", atoi(k));
                        t = atoi(k) * 4;
                        sprintf(s1, "%d", first_int_array_param);    // %d를 지정하여 정수를 문자열로 저장
                        if(first_char_array_param)
                          strcpy(s1, first_char_array_param);
                        sprintf(s2, "%d", second_int_array_param);    // %d를 지정하여 정수를 문자열로 저장
                        if(second_char_array_param)
                          strcpy(s2, second_char_array_param);
                        sprintf(s3, "%d", t);    // %d를 지정하여 정수를 문자열로 저장
                        // printf("first param, second param: %s %s\n", s1, s2);
                        // printf("%d\n",atoi(arr_temp_type[15]));
                        addQuadruple("*", s3, s1, str1);
                        sprintf(str2, "%d", temp_var);
                        strcat(str3,str2);
                        addQuadruple("*", "4", s2, str3);
                        temp_var++;
                        sprintf(str4, "%d", temp_var);
                        strcat(str5,str4);
                        addQuadruple("+", str3, str1, str5);
                        strcpy(arrName, arr_temp_name);
                        strcat(arrName, "[");
                        strcat(arrName, str5);
                        strcat(arrName, "]");
                        // printf("%s\n", arrName);
                        temp_var++;
                        sprintf(str4, "%d", temp_var);
                        memmove(str5+1, str4, 1);
                        addQuadruple("=","", arrName, str5);
                        push(str5, arr_temp_type);
                        addQuadruple("=","",pop(),(yyvsp[-3].string));
                        temp_var++;
                      }
                      lineNo++;
                    }
#line 1706 "y.tab.c"
    break;

  case 31:
#line 334 "hw3_1.y"
                      {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("+",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("+",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("+",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("+",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }
#line 1746 "y.tab.c"
    break;

  case 32:
#line 369 "hw3_1.y"
                     {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("-",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("-",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("-",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("-",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }
#line 1786 "y.tab.c"
    break;

  case 33:
#line 405 "hw3_1.y"
                    {
                    char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("*",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("*",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("*",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("*",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                }
#line 1826 "y.tab.c"
    break;

  case 34:
#line 441 "hw3_1.y"
                    {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if((yyvsp[0].string) == 0) {
                          yyerror('divide by zero');
                        } else if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("/",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("/",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("/",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("/",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }
#line 1868 "y.tab.c"
    break;

  case 36:
#line 481 "hw3_1.y"
                              {
                                char* temp;
                                char temp1[5] = "-";
                                temp = pop();
                                strcat(temp1, temp);   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                                push(temp1, "int");
                              }
#line 1880 "y.tab.c"
    break;

  case 38:
#line 491 "hw3_1.y"
         {                     
        int i;
        char* j;
        i=search_symbol((yyvsp[0].string));
        j = search_symbol_type((yyvsp[0].string));
        //printf("-----%s type: %s-----\n",$1 ,j);
        if(i==-1) // symbol table에 없는 경우
          printf("\n Undefined Variable\n");
         else // 있으면 index i리턴
          push((yyvsp[0].string), j);              
        }
#line 1896 "y.tab.c"
    break;

  case 39:
#line 503 "hw3_1.y"
             {       
                char temp[10]; // 버퍼 선언
                snprintf(temp,10,"%f",(yyvsp[0].dval));   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                push(temp, "double");               // 저장된 버퍼를 스택에 push
            }
#line 1906 "y.tab.c"
    break;

  case 40:
#line 509 "hw3_1.y"
              {       
                char temp[10]; // 버퍼 선언
                snprintf(temp,10,"%d",(yyvsp[0].ival));   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                push(temp, "int");               // 저장된 버퍼를 스택에 push
            }
#line 1916 "y.tab.c"
    break;


#line 1920 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 517 "hw3_1.y"


extern FILE *yyin;
int main()
{
   
  Stk.top = -1; // 스택의 top을 -1로 초기화
  yyin = fopen("input.txt","r");
  yyparse();
  display_sym_tab();
  printf("\n\n");
  display_Quadruple();
  printf("\n\n");
  return(0);
}


void strintrude (char *s, char *t, int i) 
{     
/*문자열 s의 i 번째 위치에 문자열 t를 삽입*/ 
  int cnt; 
  char string[100], *temp = string; 
  for(cnt = 0 ; cnt < 100 ; cnt++) // init 
    string[cnt] = '\0';
  if( i < 0 && i > (int)strlen(s)) 
  {         
    fprintf(stderr, "position is out of bounds \n");         
    exit (1);         
  } 
  if (!strlen(s))         
  { 
    strcpy (s, t);         
  } 
  else if (strlen(t))  
  {     
    strcat(t,(s+i)); 
    strcpy((s+i),t); 
  }     
}

char* make_arr_type(int num, char type[10], char* arr_type)
{
  // char* arr_type = malloc(30);
  // strcpy(arr_type, "array(");
  char s[10];       // 변환한 문자열을 저장할 배열
  sprintf(s, "%d", num); 
  // printf("%s\n", s);
  strcat(arr_type, s);
  strcat(arr_type, ", ");
  strcat(arr_type, type);
  strcat(arr_type, ")");
  // printf("%s\n", arr_type);
  return arr_type;
}

int search_symbol(char sym[10])
{
  int i,flag=0;
  for(i=0;i<sym_cnt;i++)
  {
    if(strcmp(Sym[i].sym_name,sym)==0) // 심볼 테이블에 있는지 확인
    {
      flag=1;
      break;
    }
  }
  if(flag==0) // 없는 경우
    return(-1);
  else        // 있는 경우
    return(i);
}
char* search_symbol_type(char sym[10])
{
  int i;
  char*j;
  for(i=0;i<sym_cnt;i++)
  {
    if(strcmp(Sym[i].sym_name,sym)==0) // 심볼 테이블에 있는지 확인
    {
      return Sym[i].sym_type;
    }
  }
  return NULL;
}

void make_symtab_entry(char sym[10],char dtype[10],double val)
{
  for(int i=0;i<sym_cnt;i++) { // 이차원 배열 심볼테이블에 덮어쓰기
    if (strcmp(Sym[i].sym_name, sym) == 0) { // 같은게 있으면
      strcpy(Sym[i].sym_name,sym);
      strcpy(Sym[i].sym_type,dtype);
      Sym[i].value=val;
      Sym[i].sym_offset = offset;
      offset += 8;
      return;
    }
  }
  strcpy(Sym[sym_cnt].sym_name,sym);
  strcpy(Sym[sym_cnt].sym_type,dtype);
  Sym[sym_cnt].value=val; // 변수선언시에 0으로 저장
  if(strcmp(Sym[sym_cnt].sym_type, "int") == 0) {
    Sym[sym_cnt].sym_offset = offset;
    offset += 4;
  } else {
    Sym[sym_cnt].sym_offset = offset;
    offset += 8;
  }
  sym_cnt++;
}


void display_sym_tab()
{
  int i;
  printf("------------The Symbol Table--------\n\n");
  printf(" Name   Type    offset    Value");
  for(i=0;i<sym_cnt;i++)
    printf("\n %s      %s    %d       %f",Sym[i].sym_name,Sym[i].sym_type, Sym[i].sym_offset, Sym[i].value);
  printf("\n\n------------------------------------\n");
}
void display_Quadruple()
{
  int i;
  printf("----------INTERMEDIATE CODE---------\n");
  //printf("\n     Result  Operator  Operand1  Operand2  ");
  for(i=0;i<Index;i++) {
   //printf("\n %d     %s          %s          %s          %s",i,QUAD[i].result,QUAD[i].operator,QUAD[i].operand1,QUAD[i].operand2);
    if (strcmp(QUAD[i].operator, "=") == 0)
      printf("%s = %s\n", QUAD[i].result, QUAD[i].operand1);
    else 
      printf("%s = %s %s %s\n", QUAD[i].result, QUAD[i].operand1, QUAD[i].operator, QUAD[i].operand2);
  }
  printf("------------------------------------\n");
}

int yyerror(char const *s, int charCnt)
{
    if(strcmp(s, "lexical error") == 0) {
      fprintf(stderr, "%s(%d:%d)\n", s, lineNo, charCnt);
      return -1;
    } else {
      fprintf(stderr, "%s(%d)\n", s, lineNo);
      return -1;
    }
}

// 스택에 push하는 함수
void push(char *str, char* type) 
{
  Stk.top++; // 초기 -1
  Stk.items[Stk.top]=(char *)malloc(strlen(str)+1);
  strcpy(Stk.items[Stk.top],str);
  Stk.types[Stk.top]=(char *)malloc(strlen(type)+1);
  strcpy(Stk.types[Stk.top],type);
}
char * pop()
{
  int i;
  if(Stk.top==-1)
  {
     printf("\nStack Empty!! \n");
     exit(0);
  }
  char *str=(char *)malloc(strlen(Stk.items[Stk.top])+1);;
  strcpy(str,Stk.items[Stk.top]);
  free(Stk.items[Stk.top]);
  free(Stk.types[Stk.top]);
  Stk.top--;
  return(str);
}

void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])
 {
    strcpy(QUAD[Index].operator,op);
    strcpy(QUAD[Index].operand2,op2);
    strcpy(QUAD[Index].operand1,op1);
    strcpy(QUAD[Index].result,res);
    Index++;
}



/*
int r; 
double pi; 
r = 5; 
pi = 3.14; 
area = pi * r * r; 
cir = pi * r + pi * r;

r = 5
pi = 3.14
t1 = inttoreal r
t2 = pi * t1
t3 = inttoreal r
t4 = t2 * t3
area = t4
t5 = inttoreal r
t6 = pi * t5
t7 = inttoreal r
t8 = pi * t7
t9 = t6 + t8
cir = t9
*/

//에러처리
// int a d c;
// b = 10 a;