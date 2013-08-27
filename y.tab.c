/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

	#include "lex.yy.c"
	int yylex();


/* Line 268 of yacc.c  */
#line 77 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELIPSIS = 303,
     RANGE = 304,
     CASE = 305,
     DEFAULT = 306,
     IF = 307,
     ELSE = 308,
     SWITCH = 309,
     WHILE = 310,
     DO = 311,
     FOR = 312,
     GOTO = 313,
     CONTINUE = 314,
     BREAK = 315,
     RETURN = 316,
     LOWER_THAN_ELSE = 317
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELIPSIS 303
#define RANGE 304
#define CASE 305
#define DEFAULT 306
#define IF 307
#define ELSE 308
#define SWITCH 309
#define WHILE 310
#define DO 311
#define FOR 312
#define GOTO 313
#define CONTINUE 314
#define BREAK 315
#define RETURN 316
#define LOWER_THAN_ELSE 317




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 243 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNRULES -- Number of states.  */
#define YYNSTATES  368

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    76,    69,     2,
      63,    64,    70,    71,    68,    72,    67,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    84,
      77,    83,    78,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    80,    86,    73,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   246,   248,   252,   254,   256,   258,
     260,   262,   264,   266,   268,   270,   272,   274,   276,   278,
     280,   282,   284,   286,   288,   290,   296,   301,   304,   306,
     308,   310,   313,   317,   319,   323,   325,   328,   332,   337,
     343,   346,   348,   352,   354,   358,   360,   363,   365,   369,
     373,   378,   382,   387,   392,   394,   397,   400,   404,   406,
     409,   411,   415,   417,   421,   423,   427,   429,   433,   436,
     438,   440,   443,   445,   447,   450,   454,   457,   461,   465,
     470,   473,   477,   481,   486,   488,   492,   497,   499,   503,
     505,   507,   509,   511,   513,   515,   519,   524,   528,   531,
     535,   539,   544,   546,   549,   551,   554,   556,   559,   565,
     573,   579,   585,   593,   600,   608,   616,   625,   633,   642,
     651,   661,   665,   668,   671,   674,   678,   680,   683,   685,
     687,   690,   694,   696,   699
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     147,     0,    -1,   151,    -1,     4,    -1,     5,    -1,    63,
     107,    64,    -1,    88,    -1,    89,    65,   107,    66,    -1,
      89,    63,    64,    -1,    89,    63,    90,    64,    -1,    89,
      67,   151,    -1,    89,     7,   151,    -1,    89,     8,    -1,
      89,     9,    -1,   105,    -1,    90,    68,   105,    -1,    89,
      -1,     8,    91,    -1,     9,    91,    -1,    92,    93,    -1,
       6,    91,    -1,     6,    63,   133,    64,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      91,    -1,    63,   133,    64,    93,    -1,    93,    -1,    94,
      70,    93,    -1,    94,    75,    93,    -1,    94,    76,    93,
      -1,    94,    -1,    95,    71,    94,    -1,    95,    72,    94,
      -1,    95,    -1,    96,    10,    95,    -1,    96,    11,    95,
      -1,    96,    -1,    97,    77,    96,    -1,    97,    78,    96,
      -1,    97,    12,    96,    -1,    97,    13,    96,    -1,    97,
      -1,    98,    14,    97,    -1,    98,    15,    97,    -1,    98,
      -1,    99,    69,    98,    -1,    99,    -1,   100,    79,    99,
      -1,   100,    -1,   101,    80,   100,    -1,   101,    -1,   102,
      16,   101,    -1,   102,    -1,   103,    17,   102,    -1,   103,
      -1,   103,    81,   103,    82,   104,    -1,   104,    -1,    91,
     106,   105,    -1,    83,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   105,    -1,   107,    68,   105,
      -1,   104,    -1,   110,    84,    -1,   110,   111,    84,    -1,
     113,    -1,   113,   110,    -1,   114,    -1,   114,   110,    -1,
     112,    -1,   111,    68,   112,    -1,   124,    -1,   124,    83,
     136,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,
      43,    -1,    44,    -1,   115,    -1,   121,    -1,    28,    -1,
     116,   151,    85,   117,    86,    -1,   116,    85,   117,    86,
      -1,   116,   151,    -1,    45,    -1,    46,    -1,   118,    -1,
     117,   118,    -1,   127,   119,    84,    -1,   120,    -1,   119,
      68,   120,    -1,   124,    -1,    82,   108,    -1,   124,    82,
     108,    -1,    47,    85,   122,    86,    -1,    47,   151,    85,
     122,    86,    -1,    47,   151,    -1,   123,    -1,   122,    68,
     123,    -1,   151,    -1,   151,    83,   108,    -1,   125,    -1,
     126,   125,    -1,   151,    -1,    63,   124,    64,    -1,   125,
      65,    66,    -1,   125,    65,   108,    66,    -1,   125,    63,
      64,    -1,   125,    63,   130,    64,    -1,   125,    63,   128,
      64,    -1,    70,    -1,    70,   127,    -1,    70,   126,    -1,
      70,   127,   126,    -1,   114,    -1,   127,   114,    -1,   129,
      -1,   129,    68,    48,    -1,   151,    -1,   129,    68,   151,
      -1,   131,    -1,   131,    68,    48,    -1,   132,    -1,   131,
      68,   132,    -1,   127,   124,    -1,   133,    -1,   127,    -1,
     127,   134,    -1,   126,    -1,   135,    -1,   126,   135,    -1,
      63,   134,    64,    -1,    65,    66,    -1,    65,   108,    66,
      -1,   135,    65,    66,    -1,   135,    65,   108,    66,    -1,
      63,    64,    -1,    63,   130,    64,    -1,   135,    63,    64,
      -1,   135,    63,   130,    64,    -1,   105,    -1,    85,   137,
      86,    -1,    85,   137,    68,    86,    -1,   136,    -1,   137,
      68,   136,    -1,   139,    -1,   140,    -1,   143,    -1,   144,
      -1,   145,    -1,   146,    -1,   151,    82,   138,    -1,    50,
     108,    82,   138,    -1,    51,    82,   138,    -1,    85,    86,
      -1,    85,   142,    86,    -1,    85,   141,    86,    -1,    85,
     141,   142,    86,    -1,   109,    -1,   141,   109,    -1,   138,
      -1,   142,   138,    -1,    84,    -1,   107,    84,    -1,    52,
      63,   107,    64,   138,    -1,    52,    63,   107,    64,   138,
      53,   138,    -1,    54,    63,   107,    64,   138,    -1,    55,
      63,   107,    64,   138,    -1,    56,   138,    55,    63,   107,
      64,    84,    -1,    57,    63,    84,    84,    64,   138,    -1,
      57,    63,    84,    84,   107,    64,   138,    -1,    57,    63,
      84,   107,    84,    64,   138,    -1,    57,    63,    84,   107,
      84,   107,    64,   138,    -1,    57,    63,   107,    84,    84,
      64,   138,    -1,    57,    63,   107,    84,    84,   107,    64,
     138,    -1,    57,    63,   107,    84,   107,    84,    64,   138,
      -1,    57,    63,   107,    84,   107,    84,   107,    64,   138,
      -1,    58,   151,    84,    -1,    59,    84,    -1,    60,    84,
      -1,    61,    84,    -1,    61,   107,    84,    -1,   148,    -1,
     147,   148,    -1,   149,    -1,   109,    -1,   124,   150,    -1,
     110,   124,   150,    -1,   140,    -1,   141,   140,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    23,    23,    24,    25,    26,    30,    31,    32,    33,
      34,    35,    36,    37,    41,    42,    46,    47,    48,    49,
      50,    51,    55,    56,    57,    58,    59,    60,    64,    65,
      69,    70,    71,    72,    76,    77,    78,    82,    83,    84,
      88,    89,    90,    91,    92,    96,    97,    98,   102,   103,
     107,   108,   112,   113,   117,   118,   122,   123,   127,   128,
     132,   133,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   151,   152,   156,   160,   161,   165,   166,
     167,   168,   172,   173,   177,   178,   182,   183,   184,   185,
     186,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   207,   208,   209,   213,   214,
     218,   219,   223,   227,   228,   232,   233,   234,   238,   239,
     240,   244,   245,   249,   250,   254,   255,   259,   260,   261,
     262,   263,   264,   265,   269,   270,   271,   272,   276,   277,
     281,   282,   286,   287,   291,   292,   296,   297,   301,   302,
     306,   307,   311,   312,   313,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   329,   330,   331,   335,   336,   340,
     341,   342,   343,   344,   345,   349,   350,   351,   355,   356,
     357,   358,   362,   363,   367,   368,   372,   373,   377,   378,
     379,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   396,   397,   398,   399,   400,   404,   405,   409,   410,
     414,   415,   419,   420,   424
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELIPSIS", "RANGE",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "LOWER_THAN_ELSE", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "primary_expr", "postfix_expr", "argument_expr_list",
  "unary_expr", "unary_operator", "cast_expr", "multiplicative_expr",
  "additive_expr", "shift_expr", "relational_expr", "equality_expr",
  "and_expr", "exclusive_or_expr", "inclusive_or_expr", "logical_and_expr",
  "logical_or_expr", "conditional_expr", "assignment_expr",
  "assignment_operator", "expr", "constant_expr", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "declarator2", "pointer",
  "type_specifier_list", "parameter_identifier_list", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "abstract_declarator2",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "file", "external_definition", "function_definition",
  "function_body", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    40,    41,    91,    93,    46,    44,    38,
      42,    43,    45,   126,    33,    47,    37,    60,    62,    94,
     124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   118,   119,   119,   120,   120,   120,   121,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   136,   136,   137,   137,   138,
     138,   138,   138,   138,   138,   139,   139,   139,   140,   140,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     1,     3,     1,     2,     3,     4,     5,
       2,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       4,     3,     4,     4,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     1,
       1,     2,     1,     1,     2,     3,     2,     3,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       3,     4,     1,     2,     1,     2,     1,     2,     5,     7,
       5,     5,     7,     6,     7,     7,     8,     7,     8,     8,
       9,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       2,     3,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   214,   104,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   108,
     109,     0,     0,   134,   209,     0,    78,    80,   102,     0,
     103,     0,   125,     0,     0,   206,   208,   127,     0,   120,
       0,   138,   136,   135,    76,     0,    82,    84,    79,    81,
       0,   107,     0,   182,     0,   212,     0,   210,     0,     0,
     126,     1,   207,     0,   121,   123,     0,   128,   139,   137,
       0,    77,     0,   211,     0,   110,     0,     0,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,   186,   178,     6,    16,    28,     0,    30,    34,    37,
      40,    45,    48,    50,    52,    54,    56,    58,    60,    73,
       0,   184,   169,   170,     0,     0,   171,   172,   173,   174,
       2,    84,   183,   213,   131,   150,     0,   140,     0,   144,
     146,   149,   142,   129,    28,    75,     0,     2,     0,   118,
       0,     0,    83,     0,   164,    85,   106,   111,     0,     0,
     113,   115,     0,     0,    20,     0,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,   202,   203,   204,     0,
       0,   150,     0,     0,    12,    13,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    62,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   180,     0,   179,   185,     0,     0,     0,
     148,   152,   151,   153,   133,     0,   132,     0,   130,   122,
     124,   119,   167,     0,   116,     0,   112,     0,   105,     0,
       0,   177,     0,     0,     0,     0,     0,     0,   201,   205,
       5,     0,   152,     0,    11,     8,     0,    14,     0,    10,
      61,    31,    32,    33,    35,    36,    38,    39,    43,    44,
      41,    42,    46,    47,    49,    51,    53,    55,    57,     0,
      74,   181,   175,   160,     0,     0,   156,     0,   154,     0,
       0,   141,   143,   145,   147,     0,   165,   114,   117,    21,
     176,     0,     0,     0,     0,     0,     0,     0,    29,     9,
       0,     7,     0,   161,   155,   157,   162,     0,   158,     0,
     166,   168,   188,   190,   191,     0,     0,     0,     0,     0,
       0,    15,    59,   163,   159,     0,     0,   193,     0,     0,
       0,     0,     0,     0,   189,   192,   194,   195,     0,   197,
       0,     0,     0,   196,   198,   199,     0,   200
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   266,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   200,
     120,   146,    53,    54,    45,    46,    26,    41,    28,    29,
      74,    75,   159,   160,    30,    63,    64,    31,    32,    33,
     135,   136,   137,   294,   139,   140,   141,   232,   233,   155,
     243,   121,   122,   123,    56,   125,   126,   127,   128,   129,
      34,    35,    36,    57,   147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -218
static const yytype_int16 yypact[] =
{
    1117,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,    11,    21,  1460,  -218,    37,  1517,  1517,  -218,    14,
    -218,  1361,    54,    16,  1054,  -218,  -218,  -218,    32,   -42,
      -9,  -218,  -218,  1460,  -218,   -21,  -218,  1303,  -218,  -218,
    1537,   -28,   359,  -218,    37,  -218,  1361,  -218,  1252,   842,
      54,  -218,  -218,   -45,  -218,   -14,    32,  -218,  -218,  -218,
      21,  -218,   633,  -218,   701,  -218,   779,  1537,  -218,  -218,
     377,  1042,  1042,  1070,    -5,    20,    43,    51,   614,    60,
      32,    44,    47,   650,   828,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,   151,   504,  1070,  -218,   104,    84,
     215,    55,   226,    26,    58,    63,   118,     1,  -218,  -218,
      42,  -218,  -218,  -218,   433,   505,  -218,  -218,  -218,  -218,
      94,   134,  -218,  -218,  -218,  1207,   128,   152,   170,   179,
    -218,  -218,  -218,  -218,  -218,  -218,   200,  -218,    32,  -218,
    1070,   -41,  -218,   633,  -218,  -218,  -218,  -218,  1070,    52,
    -218,   177,  1283,   828,  -218,  1070,  -218,  -218,   199,   614,
    1070,  1070,  1070,   227,   686,   204,  -218,  -218,  -218,    70,
     -32,  1422,   225,    32,  -218,  -218,   873,  1070,    32,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    1070,  -218,  1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,
    1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,  1070,
    1070,  1070,  -218,  -218,   542,  -218,  -218,   614,  1162,   914,
    -218,    53,  -218,   119,  -218,    17,  -218,  1336,  -218,  -218,
    -218,  -218,  -218,   -37,  -218,    45,  -218,  1070,  -218,   229,
     614,  -218,   -22,    -4,   102,   231,   706,    77,  -218,  -218,
    -218,  1384,   193,  1070,  -218,  -218,   109,  -218,   201,  -218,
    -218,  -218,  -218,  -218,   104,   104,    84,    84,   215,   215,
     215,   215,    55,    55,   226,    26,    58,    63,   118,   -11,
    -218,  -218,  -218,  -218,   232,   233,  -218,   224,   119,  1480,
     926,  -218,  -218,  -218,  -218,   577,  -218,  -218,  -218,  -218,
    -218,   614,   614,   614,  1070,   945,    78,   722,  -218,  -218,
    1070,  -218,  1070,  -218,  -218,  -218,  -218,   234,  -218,   235,
    -218,  -218,   242,  -218,  -218,   117,   614,   123,   957,   970,
      83,  -218,  -218,  -218,  -218,   614,   218,  -218,   614,   614,
     125,   614,   155,   998,  -218,  -218,  -218,  -218,   614,  -218,
     614,   614,   178,  -218,  -218,  -218,   614,  -218
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,  -218,    -8,  -218,   -99,    46,    64,    68,
      49,    88,    89,    82,    90,    91,    86,   -57,   -56,  -218,
     -85,    28,     5,   113,  -218,   237,  -218,   300,  -218,  -218,
     239,   -70,  -218,    72,  -218,   243,   171,    87,   -18,   -13,
     210,  -218,  -218,   -55,  -218,    81,   -82,  -217,  -203,  -152,
    -218,   -75,  -218,     6,   268,   197,  -218,  -218,  -218,  -218,
    -218,   288,  -218,   276,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      37,   242,   145,   138,   157,    24,   219,   201,   179,   180,
      42,   295,   182,   173,     1,    60,   154,     1,   219,     1,
       1,    39,    37,   148,     1,    37,   145,   148,   298,    51,
      69,   305,   260,    37,    37,     1,   221,    55,    65,    24,
       1,   149,   311,    66,   295,   241,   221,    70,     1,   306,
     226,   144,   130,    55,    37,    67,     1,    77,   142,   298,
     312,   132,   133,    71,   221,   301,    65,   209,   210,   150,
      37,   322,   164,   166,   167,   144,    37,   169,   180,    22,
     180,   249,   220,   170,    22,   252,   253,   254,   130,   257,
     175,    23,   157,   145,   251,   215,    38,   154,   144,    50,
      22,   145,   268,   271,   272,   273,   171,    23,    22,    40,
     221,   168,    47,    25,   172,    23,   228,    58,   229,    59,
     245,    44,   231,   174,   130,   130,   222,   158,   176,   132,
     267,   177,   211,   212,   218,    37,   246,   216,   221,    48,
      49,   131,   144,   217,   270,   221,   221,    25,    65,   226,
     144,   221,   292,   331,   259,   205,   206,   131,   183,   184,
     185,   317,   338,   161,   318,   290,   313,   353,   262,   130,
     221,   316,   145,   319,   202,   310,   227,   320,   240,   203,
     204,   346,   299,   264,   300,   221,   244,   348,   269,   358,
     145,   221,   234,   221,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,    60,   186,   231,   187,    72,   188,   360,
     235,   144,   230,   221,   130,   207,   208,   130,    37,   335,
     337,    37,   340,    43,   236,   302,   332,   333,   334,   144,
     213,   214,   366,   145,   327,    37,   221,   237,   262,   154,
     130,   274,   275,   350,   352,   144,   261,   297,   229,   247,
      76,   347,   282,   283,   341,   342,   238,   321,   362,   221,
     354,   276,   277,   356,   357,   308,   359,   278,   279,   280,
     281,   250,   255,   363,    76,   364,   365,    76,   258,   263,
     325,   367,   144,   309,   314,   345,   323,   324,   343,   286,
      27,   344,   355,   284,   181,   285,   289,   152,   287,   151,
     288,   130,   130,   130,   144,    40,   162,   307,   304,   239,
     124,   224,    62,    73,     0,     0,    27,    27,   329,     0,
       0,    27,   161,     0,    27,     0,   130,     0,     0,     0,
       0,     0,     0,    68,     0,   130,     0,    27,   130,   130,
       0,   130,    27,     0,     0,     0,    27,     0,   130,     0,
     130,   130,     1,    78,    79,    80,   130,    81,    82,     0,
       0,     0,    76,   181,     0,     0,    68,     0,     0,     0,
       1,    78,    79,    80,     0,    81,    82,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    83,
      84,    85,     0,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94,     0,    27,     0,     0,     0,    95,    96,
      97,    98,    99,   100,     0,    68,     1,    78,    79,    80,
     163,    81,    82,   101,    52,   102,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    68,     0,    83,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,     0,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,     1,    78,
      79,    80,     0,    81,    82,     0,     0,   101,    52,   223,
       0,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    78,    79,    80,     0,
      81,    82,     0,     0,     0,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
       1,    78,    79,    80,     0,    81,    82,   199,     0,   101,
      52,   225,    83,    84,    85,     0,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     1,    78,    79,
      80,     0,    81,    82,     0,     0,   101,    52,   291,     0,
       0,     0,     0,     0,     0,     0,     1,    78,    79,    80,
      94,    81,    82,     0,     0,     0,    95,    96,    97,    98,
      99,   100,     0,     1,    78,    79,    80,     0,    81,    82,
       0,     0,   153,   330,    83,    84,    85,     0,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     1,
      78,    79,    80,     0,    81,    82,    94,     0,   101,    52,
       0,     0,    95,    96,    97,    98,    99,   100,     0,     1,
      78,    79,    80,    94,    81,    82,     0,     0,   153,    95,
      96,    97,    98,    99,   100,     1,    78,    79,    80,     2,
      81,    82,     0,     0,   178,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    94,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,    94,
     256,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,     1,     0,     0,    94,     0,   156,     0,     0,
     315,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   339,     2,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     1,    78,    79,    80,     0,    81,    82,     0,     0,
       0,     0,    22,     0,     0,     1,    78,    79,    80,    23,
      81,    82,     0,     0,     0,     0,     2,     0,     0,     0,
       0,   158,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,     0,    94,     0,     0,   143,     0,
       0,    95,    96,    97,    98,    99,   100,     1,    78,    79,
      80,     0,    81,    82,     0,     0,     0,     0,     0,     1,
      78,    79,    80,     0,    81,    82,    94,   265,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,     1,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       1,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     1,    78,    79,    80,    94,    81,    82,
     296,     0,     0,    95,    96,    97,    98,    99,   100,    94,
       0,     0,   328,     0,     0,    95,    96,    97,    98,    99,
     100,     1,    78,    79,    80,     0,    81,    82,    94,   336,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
      94,   349,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,     0,    94,   351,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     1,    78,    79,    80,     0,
      81,    82,     0,     0,    61,     0,     0,     1,     0,     0,
       0,    94,   361,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     1,    78,    79,    80,     0,    81,    82,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,   165,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,    22,     0,     0,
       1,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       2,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,   293,   229,     0,     0,
       0,     0,    23,     0,     0,     2,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,   229,     0,     0,     0,     0,    23,     0,     0,
       2,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,   134,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   248,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   303,     0,    72,     0,    52,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   261,   293,   229,
       2,     0,     0,     0,    23,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,   229,     2,     0,
       0,     0,    23,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     2,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     2,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-218))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   153,    59,    58,    74,     0,    17,   106,    93,    94,
      23,   228,    94,    88,     3,    33,    72,     3,    17,     3,
       3,    21,    22,    68,     3,    25,    83,    68,   231,    29,
      43,    68,    64,    33,    34,     3,    68,    31,    38,    34,
       3,    86,    64,    85,   261,    86,    68,    68,     3,    86,
     125,    59,    52,    47,    54,    64,     3,    85,    58,   262,
      64,    56,    56,    84,    68,    48,    66,    12,    13,    83,
      70,    82,    80,    81,    82,    83,    76,    82,   163,    63,
     165,   163,    81,    63,    63,   170,   171,   172,    88,   174,
      90,    70,   162,   150,   169,    69,    85,   153,   106,    85,
      63,   158,   187,   202,   203,   204,    63,    70,    63,    22,
      68,    83,    25,     0,    63,    70,    63,    63,    65,    65,
      68,    84,   135,    63,   124,   125,    84,    82,    84,   124,
     186,    84,    77,    78,    16,   135,    84,    79,    68,    26,
      27,    54,   150,    80,   200,    68,    68,    34,   148,   224,
     158,    68,   227,   305,    84,    71,    72,    70,     7,     8,
       9,    84,    84,    76,   263,   221,    64,    84,   181,   169,
      68,   256,   229,    64,    70,   250,    82,    68,   150,    75,
      76,    64,    63,   183,    65,    68,   158,    64,   188,    64,
     247,    68,    64,    68,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   231,    63,   228,    65,    83,    67,    64,
      68,   229,   135,    68,   224,    10,    11,   227,   228,   314,
     315,   231,   317,    23,    64,   235,   311,   312,   313,   247,
      14,    15,    64,   300,   299,   245,    68,    68,   261,   305,
     250,   205,   206,   338,   339,   263,    63,   229,    65,    82,
      50,   336,   213,   214,   320,   322,    66,    66,   353,    68,
     345,   207,   208,   348,   349,   247,   351,   209,   210,   211,
     212,    82,    55,   358,    74,   360,   361,    77,    84,    64,
      66,   366,   300,    64,    63,    53,    64,    64,    64,   217,
       0,    66,    84,   215,    94,   216,   220,    70,   218,    66,
     219,   311,   312,   313,   322,   228,    77,   245,   237,   148,
      52,   124,    34,    47,    -1,    -1,    26,    27,   300,    -1,
      -1,    31,   245,    -1,    34,    -1,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,   345,    -1,    47,   348,   349,
      -1,   351,    52,    -1,    -1,    -1,    56,    -1,   358,    -1,
     360,   361,     3,     4,     5,     6,   366,     8,     9,    -1,
      -1,    -1,   162,   163,    -1,    -1,    76,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63,    -1,   124,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    -1,   135,     3,     4,     5,     6,
      63,     8,     9,    84,    85,    86,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   181,    -1,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    84,    85,    86,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
       3,     4,     5,     6,    -1,     8,     9,    83,    -1,    84,
      85,    86,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      63,     8,     9,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    85,    86,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,     3,
       4,     5,     6,    -1,     8,     9,    63,    -1,    84,    85,
      -1,    -1,    69,    70,    71,    72,    73,    74,    -1,     3,
       4,     5,     6,    63,     8,     9,    -1,    -1,    85,    69,
      70,    71,    72,    73,    74,     3,     4,     5,     6,    28,
       8,     9,    -1,    -1,    84,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      84,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    -1,     3,    -1,    -1,    63,    -1,    86,    -1,    -1,
      84,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    63,    -1,    -1,     3,     4,     5,     6,    70,
       8,     9,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    82,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,    63,    -1,    -1,    66,    -1,
      -1,    69,    70,    71,    72,    73,    74,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    63,     8,     9,
      66,    -1,    -1,    69,    70,    71,    72,    73,    74,    63,
      -1,    -1,    66,    -1,    -1,    69,    70,    71,    72,    73,
      74,     3,     4,     5,     6,    -1,     8,     9,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    -1,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,     0,    -1,    -1,     3,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    63,    -1,    -1,
       3,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    64,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    86,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    83,    -1,    85,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    63,    64,    65,
      28,    -1,    -1,    -1,    70,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    28,    -1,
      -1,    -1,    70,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    63,    70,   109,   110,   113,   114,   115,   116,
     121,   124,   125,   126,   147,   148,   149,   151,    85,   151,
     124,   114,   126,   127,    84,   111,   112,   124,   110,   110,
      85,   151,    85,   109,   110,   140,   141,   150,    63,    65,
     125,     0,   148,   122,   123,   151,    85,    64,   114,   126,
      68,    84,    83,   150,   117,   118,   127,    85,     4,     5,
       6,     8,     9,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    60,    61,    63,    69,    70,    71,    72,    73,
      74,    84,    86,    88,    89,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     107,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     151,   124,   109,   140,    64,   127,   128,   129,   130,   131,
     132,   133,   151,    66,    91,   104,   108,   151,    68,    86,
      83,   122,   112,    85,   105,   136,    86,   118,    82,   119,
     120,   124,   117,    63,    91,    63,    91,    91,   108,    82,
      63,    63,    63,   138,    63,   151,    84,    84,    84,   107,
     107,   127,   133,     7,     8,     9,    63,    65,    67,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    83,
     106,    93,    70,    75,    76,    71,    72,    10,    11,    12,
      13,    77,    78,    14,    15,    69,    79,    80,    16,    17,
      81,    68,    84,    86,   142,    86,   138,    82,    63,    65,
     124,   126,   134,   135,    64,    68,    64,    68,    66,   123,
     108,    86,   136,   137,   108,    68,    84,    82,    86,   133,
      82,   138,   107,   107,   107,    55,    84,   107,    84,    84,
      64,    63,   126,    64,   151,    64,    90,   105,   107,   151,
     105,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    98,    99,   100,   101,   102,   103,
     105,    86,   138,    64,   130,   134,    66,   108,   135,    63,
      65,    48,   151,    48,   132,    68,    86,   120,   108,    64,
     138,    64,    64,    64,    63,    84,   107,    84,    93,    64,
      68,    66,    82,    64,    64,    66,    64,   130,    66,   108,
      86,   136,   138,   138,   138,   107,    64,   107,    84,    84,
     107,   105,   104,    64,    66,    53,    64,   138,    64,    64,
     107,    64,   107,    84,   138,    84,   138,   138,    64,   138,
      64,    64,   107,   138,   138,   138,    64,   138
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      

/* Line 1806 of yacc.c  */
#line 2085 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 426 "parser.y"


#include <stdio.h>

extern char * yytext;
extern int column;

yyerror(char *msg)
{
	fflush(stdout);
	printf("\nerror: %*s\ncolumn %d: %*s\n", yylineno, "^", column, msg);
}

