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
#line 1 "nutshparser.y"

// This is ONLY a demo micro-shell whose purpose is to illustrate the need for and how to handle nested alias substitutions and how to use Flex start conditions.
// This is to help students learn these specific capabilities, the code is by far not a complete nutshell by any means.
// Only "alias name word", "cd word", and "bye" run.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include "graph.c"

void resetPATH();
void getPATHS(char** paths);
void fixPATHS(char** paths);
void fixPATHSpipes(char*** paths, int i);

int yylex(void);
int yyerror(char *s);
int yyparse();

int runSetEnv(char *var, char *word);
int runPrintEnv(void);
int runUnsetEnv(char *var);
int runCD(char* arg);
int runCDn(void);
int runSetAlias(char *name, char *word);
int runPrintAlias();
int runRemoveAlias(char *name);
int runBasic(char *name);
int runPipe(void);
bool wildCardHelper(char* curFile, char* arg);
int runExecutable(char *file);

int argCount = 0;
int pipingArgCount = 0;
int inputCounter = 0;
int outputCounter = 0;
int pipeCount = 0;
int pipeIndex = 0; // First index of triple char array

void fixComTable(char *name);
void addArguments(char *arg);
void resetArguments();
void fixArguments();
void fixArguments_pipes();
void fixIO(char *arg);

void stderror(char *arg);
void stderr_stdout();


#line 129 "nutshparser.tab.c"

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
#ifndef YY_YY_NUTSHPARSER_TAB_H_INCLUDED
# define YY_YY_NUTSHPARSER_TAB_H_INCLUDED
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
    BYE = 258,
    SETENV = 259,
    PRINTENV = 260,
    UNSETENV = 261,
    CD = 262,
    STRING = 263,
    ALIAS = 264,
    END = 265,
    TILDE = 266,
    UNALIAS = 267,
    VALEXP = 268,
    BASIC = 269,
    AND = 270,
    INPUT = 271,
    OUTPUT = 272,
    DOUBLE = 273,
    STDERR = 274,
    STDERRSTDOUT = 275,
    EXEC = 276,
    PIPE = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "nutshparser.y"
char *string;

#line 207 "nutshparser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NUTSHPARSER_TAB_H_INCLUDED  */



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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   64

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  30
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  58

#define YYUNDEFTOK  2
#define YYMAXUTOK   277


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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    74,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    92,    96,    97,
      98,    99,   102,   103,   104,   105,   109,   110,   111,   115,
     116
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BYE", "SETENV", "PRINTENV", "UNSETENV",
  "CD", "STRING", "ALIAS", "END", "TILDE", "UNALIAS", "VALEXP", "BASIC",
  "AND", "INPUT", "OUTPUT", "DOUBLE", "STDERR", "STDERRSTDOUT", "EXEC",
  "PIPE", "$accept", "command", "args", "meta", "err", "pipe", "cmd_line", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

#define YYPACT_NINF (-11)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     4,     7,    40,    14,    27,   -11,    31,    15,     8,
      11,    32,   -11,    43,   -11,   -11,   -11,   -11,    26,    42,
      44,   -11,    45,    51,   -11,    26,    50,   -11,    11,   -11,
     -11,   -11,    53,   -11,    26,    26,   -11,   -11,    52,    26,
     -11,   -11,   -11,   -11,   -11,    54,   -11,   -11,   -11,   -11,
       2,   -11,   -11,   -11,   -11,     2,   -11,   -11
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
      22,     0,     2,     0,     4,    26,    27,    28,     0,     0,
       0,     7,     0,     0,    11,     0,     0,    14,    22,    21,
      29,    30,     0,    15,     0,     0,    16,     1,     0,     0,
      21,     5,     6,     9,     8,     0,    12,    13,    18,    23,
      22,    19,    20,     3,    10,    22,    25,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -11,   -11,    -9,    10,   -11,   -10,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    48,    34,    35,    49,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    33,     1,     2,     3,     4,     5,     6,     7,    41,
      55,     8,    56,    18,    12,    13,    46,    25,    27,    28,
       9,    29,    19,    26,    32,    51,    52,    15,    16,    17,
      30,    31,    37,    32,    39,    20,    40,    21,    22,    23,
      57,    24,    15,    16,    17,    30,    31,    15,    16,    17,
      14,    38,    42,     0,    43,    44,    15,    16,    17,    45,
      47,    50,    53,     0,    54
};

static const yytype_int8 yycheck[] =
{
      10,    10,     3,     4,     5,     6,     7,     8,     9,    18,
       8,    12,    10,     3,    10,     8,    25,     7,    10,     8,
      21,    10,     8,     8,    22,    34,    35,    16,    17,    18,
      19,    20,     0,    22,     8,     8,    10,    10,    11,     8,
      50,    10,    16,    17,    18,    19,    20,    16,    17,    18,
      10,     8,    10,    -1,    10,    10,    16,    17,    18,     8,
      10,     8,    10,    -1,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    12,    21,
      24,    29,    10,     8,    10,    16,    17,    18,    26,     8,
       8,    10,    11,     8,    10,    26,     8,    10,     8,    10,
      19,    20,    22,    25,    26,    27,    28,     0,     8,     8,
      10,    25,    10,    10,    10,     8,    25,    10,    25,    28,
       8,    25,    25,    10,    10,     8,    10,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    23,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    24,    25,    25,
      25,    25,    28,    28,    28,    28,    26,    26,    26,    27,
      27
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     2,     3,     3,     2,     3,     3,
       4,     2,     3,     3,     2,     2,     2,     1,     2,     2,
       2,     1,     0,     2,     3,     1,     1,     1,     1,     1,
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
  case 2:
#line 74 "nutshparser.y"
                                                {exit(1); return 1;}
#line 1411 "nutshparser.tab.c"
    break;

  case 3:
#line 75 "nutshparser.y"
                                                { runSetEnv((yyvsp[-2].string), (yyvsp[-1].string)); return 1;}
#line 1417 "nutshparser.tab.c"
    break;

  case 4:
#line 76 "nutshparser.y"
                                                {runPrintEnv(); return 1;}
#line 1423 "nutshparser.tab.c"
    break;

  case 5:
#line 77 "nutshparser.y"
                                                {runPrintEnv(); return 1;}
#line 1429 "nutshparser.tab.c"
    break;

  case 6:
#line 78 "nutshparser.y"
                                                {runUnsetEnv((yyvsp[-1].string)); return 1;}
#line 1435 "nutshparser.tab.c"
    break;

  case 7:
#line 79 "nutshparser.y"
                                                {runCDn(); return 1;}
#line 1441 "nutshparser.tab.c"
    break;

  case 8:
#line 80 "nutshparser.y"
                                                {runCD((yyvsp[-1].string)); return 1;}
#line 1447 "nutshparser.tab.c"
    break;

  case 9:
#line 81 "nutshparser.y"
                                                {runCD((yyvsp[-1].string)); return 1;}
#line 1453 "nutshparser.tab.c"
    break;

  case 10:
#line 82 "nutshparser.y"
                                                {runSetAlias((yyvsp[-2].string), (yyvsp[-1].string)); return 1;}
#line 1459 "nutshparser.tab.c"
    break;

  case 11:
#line 83 "nutshparser.y"
                                                {runPrintAlias(); return 1;}
#line 1465 "nutshparser.tab.c"
    break;

  case 12:
#line 84 "nutshparser.y"
                                                {runPrintAlias(); return 1;}
#line 1471 "nutshparser.tab.c"
    break;

  case 13:
#line 85 "nutshparser.y"
                                                {runRemoveAlias((yyvsp[-1].string)); return 1;}
#line 1477 "nutshparser.tab.c"
    break;

  case 14:
#line 86 "nutshparser.y"
                                                {runExecutable((yyvsp[-1].string)); return 1;}
#line 1483 "nutshparser.tab.c"
    break;

  case 15:
#line 87 "nutshparser.y"
                                                {addArguments("null"); fixArguments(); runBasic((yyvsp[-1].string)); return 1;}
#line 1489 "nutshparser.tab.c"
    break;

  case 16:
#line 88 "nutshparser.y"
                                                {addArguments("null"); fixArguments(); fixArguments_pipes(); runPipe(); return 1;}
#line 1495 "nutshparser.tab.c"
    break;

  case 17:
#line 92 "nutshparser.y"
                                                {(yyval.string) = (yyvsp[0].string); fixComTable((yyvsp[0].string)); addArguments((yyvsp[0].string)); fixArguments();}
#line 1501 "nutshparser.tab.c"
    break;

  case 18:
#line 96 "nutshparser.y"
                                                {(yyval.string) = (yyvsp[-1].string); addArguments((yyvsp[-1].string)); fixIO((yyvsp[-1].string));}
#line 1507 "nutshparser.tab.c"
    break;

  case 21:
#line 99 "nutshparser.y"
                                                {fixIO((yyvsp[0].string));}
#line 1513 "nutshparser.tab.c"
    break;

  case 23:
#line 103 "nutshparser.y"
                                                {(yyval.string) = (yyvsp[-1].string); addArguments((yyvsp[-1].string));}
#line 1519 "nutshparser.tab.c"
    break;

  case 24:
#line 104 "nutshparser.y"
                                                {fixComTable((yyvsp[-1].string)); addArguments((yyvsp[-1].string)); addArguments((yyvsp[-2].string)); pipeCount++;}
#line 1525 "nutshparser.tab.c"
    break;

  case 26:
#line 109 "nutshparser.y"
                                                {inputCounter++; commandTable.in = 1; commandTable.out = 0;}
#line 1531 "nutshparser.tab.c"
    break;

  case 27:
#line 110 "nutshparser.y"
                                                {outputCounter++; commandTable.in = 0; commandTable.out = 1;}
#line 1537 "nutshparser.tab.c"
    break;

  case 28:
#line 111 "nutshparser.y"
                                                {outputCounter++; commandTable.isDouble = true; commandTable.in = 0; commandTable.out = 1;}
#line 1543 "nutshparser.tab.c"
    break;

  case 29:
#line 115 "nutshparser.y"
                                                {outputCounter++; stderror((yyvsp[0].string));}
#line 1549 "nutshparser.tab.c"
    break;

  case 30:
#line 116 "nutshparser.y"
                                                {stderr_stdout();}
#line 1555 "nutshparser.tab.c"
    break;


#line 1559 "nutshparser.tab.c"

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
#line 119 "nutshparser.y"


int runPipe() {
	printf("Pipe Count: %d\n", pipeCount);
	printf("Command Table:\n");
	for(int i = 0; i < bcIndex; i++) {
		printf("%s\n", commandTable.command[i]);
	}
	printf("Command Arguments:\n");
	for(int i = 0; i < argCount; i++) {
		printf("%s\n", commandTable.comArgs[i]); //pipingInput[i][j];
	}

	int pipe_count = 0; // Increments when | is hit; controls pipingInput array
	pipingArgCount = 0;
	for(int i = 0; i < argCount; i++) {
		if(strcmp(commandTable.comArgs[i], "NULL") == 0) { // end of commands; may need to fix for IO redirection (if applicable)
			strcpy(commandTable.pipingInput[pipe_count][pipingArgCount], commandTable.comArgs[i]);
			pipingArgCount++;
			printf("Inputting Array %d arg count: %d\n", pipe_count, pipingArgCount);
			commandTable.pipingArgCount[pipe_count] = pipingArgCount;
		} else if(strcmp(commandTable.comArgs[i], "|") == 0) { // Add NULL to end of each array
			strcpy(commandTable.pipingInput[pipe_count][pipingArgCount], "NULL");
			pipingArgCount++;
			printf("Inputting Array %d arg count: %d\n", pipe_count, pipingArgCount);
			commandTable.pipingArgCount[pipe_count] = pipingArgCount;
			pipe_count++;
			pipingArgCount = 0;
		} else {
			strcpy(commandTable.pipingInput[pipe_count][pipingArgCount], commandTable.comArgs[i]);
			pipingArgCount++;			
		}
	}

	printf("Now testing triple char array...\n");
	for(int i = 0; i < bcIndex; i++) {
		printf("Array %d:\n", i);
		for(int j = 0; j < commandTable.pipingArgCount[i]; j++) {
			printf("%s\n", commandTable.pipingInput[i][j]);
		}
	}

	// Now onto getting the correct paths situated...
	char ** paths = malloc(128 * sizeof(char*));
        getPATHS(paths);

	for(int i = 0; i < bcIndex; i++) {
                for(int j = 0; paths[j] != NULL; j++) {
                        strcpy(commandTable.pipingPaths[i][j], paths[j]);
                        strcat(commandTable.pipingPaths[i][j], "/");
                        strcat(commandTable.pipingPaths[i][j], commandTable.command[i]);
                }
        }
	printf("Printing piping paths:\n");
	for(int i = 0; i < bcIndex; i++) {
                //printf("Path set %d:\n", i);
                for(int j = 0; paths[j] != NULL; j++) {
                        printf("%s\n", commandTable.pipingPaths[i][j]);
                }
        }

	printf("Printing appended paths:\n");
	for(int i = 0; i < bcIndex; i++) {
		for(int j = 1; paths[j] != NULL; j++) {
			strcat(commandTable.pipingPaths[i][0], ":");
			strcat(commandTable.pipingPaths[i][0], commandTable.pipingPaths[i][j]);
			strcpy(commandTable.pipingPaths[i][j], "");
		}
		printf("%s\n", commandTable.pipingPaths[i][0]);
	}

	// Memory allocation...
	char *** pipedPaths = (char***)malloc(100 * sizeof(char**));
	for(int i = 0; i < 100; i++) {
		pipedPaths[i] = (char**)malloc(128 * sizeof(char*));
		for(int j = 0; j < 128; j++) {
			pipedPaths[i][j] = "";
		}
	}

	for(int i = 0; i < bcIndex; i++) {
		fixPATHSpipes(pipedPaths, i);
	}

	printf("pipedPaths is a go?\n");
	for(int i = 0; i < bcIndex; i++) {
		for(int j = 0; paths[j] != NULL; j++) {
			printf("%s\n", pipedPaths[i][j]);
		}
	}

	/*
	// Adjusting the piping input
	//char* arg_list[128][100];
	for(int i = 0; i < bcIndex; i++) {
		char* arg_list[bcIndex][commandTable.pipingArgCount[i]];
	}

	for(int i = 0; i < bcIndex; i++) {
		int argsCount = 0;
		for(int j = 0; commandTable.pipingInput[i][j] != NULL; j++) {
			arg_list[i][j] = commandTable.pipingInput[i][j];
			argsCount++;
		}
		arg_list[i][argsCount - 1] = NULL;
	}

	printf("Now printing piping input...\n");
	for(int i = 0; i < bcIndex; i++) {
		printf("Printing Array %d:\n", i);
		for(int j = 0; commandTable.pipingInput[i][j] != NULL; j++) {
			printf("%s\n", arg_list[i][j]);
		}
	}
	*/
	
	// BIG BOY TESTING...

	pid_t pid;
	int pipefds[2*pipe_count];
	int status;
	// Creating the pipes
	for(int i = 0; i < pipe_count; i++) {
		if(pipe(pipefds + i*2) < 0) {
			perror("Error: could not make pipes");
			exit(1);
		}
	}

	int commandCount = 0;
	while(strcmp(commandTable.command[commandCount], "") != 0) { // Does all the commands
		pid = fork();
		if(pid < 0) {
			exit(1);
		} else if (pid == 0) {
			// Situate PATHS
			int numPaths = 0;
			for(int i = 0; paths[i] != NULL; i++) {
				paths[i] = pipedPaths[commandCount][i];
				numPaths++;
			}
			printf("Paths for Array %d\n", commandCount);
			for(int i = 0; paths[i] != NULL; i++) {
				printf("%s\n", paths[i]);
			}
	
			// Situate Arguments
			int argCount = commandTable.pipingArgCount[commandCount];
			char* arg_list[argCount];
			for(int i = 0; i < argCount; i++) {
				arg_list[i] = commandTable.pipingInput[commandCount][i];
			}
			arg_list[argCount - 1] = NULL;

			printf("Arguments for Array %d\n", commandCount);
			for(int i = 0; i < argCount - 1; i++) {
				printf("%s\n", arg_list[i]);
			}

			// I/O redirection would happen here if first command

			// Gets input from previous command if not first command
			if(strcmp(arg_list[0], commandTable.command[commandCount]) != 0) { // Checks for first command
				if(dup2(pipefds[(commandCount - 1) * 2], STDIN_FILENO) < 0) {
					perror("dup2 in failure");
					exit(1);
				}
			}

			// Child outputs to the next command if its not the last command
			if(strcmp(arg_list[0], commandTable.command[bcIndex - 1]) != 0) { // Checks for last command
				if(dup2(pipefds[(commandCount * 2) + 1], STDOUT_FILENO) < 0) {
					perror("dup2 out failure");
					exit(1);
				}
			}
			
			// Close pipes
			for(int i = 0; i < pipe_count * 2; i++){
				close(pipefds[i]);
			}
			
			// Error testing
			printf("Number of Paths: %d\n", numPaths);
			bool didRun = false;
			bool runCount[numPaths];			
			int errvalue;

			for(int i = 0; i < numPaths; i++) {
				printf("Now executing: %s\n", paths[i]);
				execv(paths[i], arg_list);
				//errvalue = errno;
				//runCount[i] = errvalue;

				perror("Could not run command");
				printf("%s\n", paths[i]);
				runCount[i] = errno;
				exit(EXIT_FAILURE);
			}

			for(int i = 0; i < numPaths; i++) {
				if(runCount[i] == 0) {
					didRun = true;
				}
			}
			if(!didRun) {
				printf("The error generated was %d\n", EXIT_FAILURE);
				printf("That means: %s\n", strerror(EXIT_FAILURE));
				commandTable.isErr = 1;
			}
			
			exit(0);
		}
		wait(NULL);
		commandCount++;	
	}

	for(int i = 0; i < pipe_count * 2; i++) {
		close(pipefds[i]);
	}

	for(int i = 0; i < pipe_count + 1; i++) {
		wait(&status);
	}
	/*
	if (!runInBackground){
                runInBackground = false;
		wait(NULL);
        }
	*/

	free(paths);
	free(pipedPaths);	
	resetArguments();
	argCount = 0;
	pipingArgCount = 0;
	pipeCount = 0;
	return 1;
}

int runExecutable(char *file) {
    getcwd(cwd, sizeof(cwd));
	char *temp = malloc(128 * sizeof(char));
	char *f = malloc(128 * sizeof(char));
	for (int i = 1; i < strlen(file); i++){
		temp[i-1] = file[i];
	}
	strcat(f, cwd);
	strcat(f, temp);
	int i;
	int result;
	printf("Error, our nutshell doesn't have this capability\n");
	
	free(temp);
	free(file);
	free(f);
	return 1;
}

bool wildCardHelper(char* curFile, char* arg){
	if (*arg == '\0' && *curFile == '\0'){
		return true;
	}

	if(*arg == '*' && *(arg+1) != '\0' && *curFile == '\0'){
		return false;
	}
	
	if (*arg == '?' || *arg == *curFile){
		return wildCardHelper(curFile+1, arg+1);
	}
	
	if(*arg == '*'){
		return wildCardHelper(curFile, arg+1) || wildCardHelper(curFile+1, arg);
	}
	return false;
	
}

void fixComTable(char *name) {
        strcpy(commandTable.command[bcIndex], name);
	bcIndex++;
}

void addArguments(char *arg) {
	int pCount = 0;

        if(strcmp(arg, "null") == 0) {
                strcpy(commandTable.comArgs[argCount], "NULL");
		argCount++;
        } else if(inputCounter > 0 || outputCounter > 0) {
		//Skip adding argument if input or output
	} else {
		if (strchr(arg, '?') != NULL || strchr(arg, '*') != NULL) {
			bool f = false;
			char temp[100];
			DIR *d;
			struct dirent *dir;
			d = opendir(".");
			if (d){
				while ((dir = readdir(d)) != NULL){
					if (wildCardHelper(dir->d_name, arg)){
						strcpy(commandTable.comArgs[argCount], dir->d_name);
						argCount++;
						f = true;
					}
				}
				if (f){
					for(int i=pCount;i<=argCount;i++) {
						for(int j=i+1;j<=argCount-1;j++) {
							if(strcmp(commandTable.comArgs[i],commandTable.comArgs[j]) < 0) {
								strcpy(temp,commandTable.comArgs[i]);
								strcpy(commandTable.comArgs[i],commandTable.comArgs[j]);
								strcpy(commandTable.comArgs[j],temp);
							}
						}
					}
				} else{
						char *temp = malloc(128 * sizeof(char));
						int tIndex = 0;
						for (int i = 0; i < strlen(arg); i++){
							if (arg[i] == '?' || arg[i] == '*'){
							}
							else{
								temp[tIndex] = arg[i];
								tIndex++;
							}
						}
						strcpy(commandTable.comArgs[argCount], temp);
						argCount++;
						free(temp);

				}
			}
        } else {
			strcpy(commandTable.comArgs[argCount], arg);
			argCount++;
		}
        }
		
}

void fixArguments() {
	if(argCount == 2 || argCount == 3) {
                return;
        } else {
                int j = argCount - 2;
                for(int i = 1; i < j; i++) {
                        strcpy(commandTable.temp[0], commandTable.comArgs[i]);
                        strcpy(commandTable.comArgs[i], commandTable.comArgs[j]);
                        strcpy(commandTable.comArgs[j], commandTable.temp[0]);
                        j--;
                }
        }
}

void fixArguments_pipes() {
        if(bcIndex == 0 || bcIndex == 1) {
                return;
        } else {
		int j = bcIndex - 1;
                for(int i = 1; i < j; i++) {
                        strcpy(commandTable.temp[0], commandTable.command[i]);
                        strcpy(commandTable.command[i], commandTable.command[j]);
                        strcpy(commandTable.command[j], commandTable.temp[0]);
                        j--;
                }
        }
}

void resetArguments() {
        for(int i = 0; i < argCount; i++) {
                strcpy(commandTable.command[i], "");
		strcpy(commandTable.comArgs[i], "");
		strcpy(commandTable.input[i], "");
		strcpy(commandTable.output[i], "");
	}
	
	for(int i = 0; i < bcIndex; i++) {
		for(int j = 0; j < commandTable.pipingArgCount[i]; j++) {
			strcpy(commandTable.pipingInput[i][j], ""); 
		}
	}
	
	for(int i = 0; i < bcIndex; i++) {
		commandTable.pipingArgCount[i] = 0;
	}

	strcpy(commandTable.output[1], "");
	strcpy(commandTable.piping[0], "");
	commandTable.in = 0;
	commandTable.out = 0;
	commandTable.isDouble = 0;
	commandTable.stderr_stdoutput = 0;
	bcIndex = 0;
	inputIndex = 0;
	outputIndex = 0;
	inputCounter = 0;
        outputCounter = 0;
}

void fixIO(char *arg) {
	if(outputCounter > 0) {
                strcpy(commandTable.output[outputIndex], arg);
                //commandTable.out = 0;
                //commandTable.in = 0;
                outputIndex++;
                outputCounter--;
        } else if(inputCounter > 0) {
		strcpy(commandTable.input[inputIndex], arg);
		//commandTable.in = 0;
		//commandTable.out = 0;
		inputIndex++;
		inputCounter--;
	}
}

void stderror(char *arg) {
	char fixed[strlen(arg) - 2];
	for(int i = 2; i < strlen(arg); i++) { // Clip 2> from output path
		fixed[i-2] = arg[i];
	}
	//printf("%s\n", fixed);
	strcpy(commandTable.output[1], fixed);
	outputCounter--;
}

void stderr_stdout() {
	commandTable.stderr_stdoutput = true; // Flag I/O redirection from 
}

void resetPATH() {
        strcpy(varTable.word[3], ".:/bin");
}

void getPATHS(char** paths) {
        char *str = malloc(128 * sizeof(char));
        strcpy(str, varTable.word[3]);

        int init_size = strlen(str);
        char delim[] = ":";

        char *ptr = strtok(str, delim);

        int pathCount = 0;
        while (ptr != NULL)
        {
                paths[pathCount] = ptr;
                pathCount++;
		ptr = strtok(NULL, delim);
	}
}

void fixPATHS(char** paths) {
	char *str = malloc(128 * sizeof(char));
        strcpy(str, commandTable.pathsTemp[0]);

        int init_size = strlen(str);
        char delim[] = ":";

        char *ptr = strtok(str, delim);

        int pathCount = 0;
        while (ptr != NULL)
        {
                paths[pathCount] = ptr;
                pathCount++;
                ptr = strtok(NULL, delim);
        }
}

void fixPATHSpipes(char*** paths, int i) {
        char *str = malloc(128 * sizeof(char));
        strcpy(str, commandTable.pipingPaths[i][0]);

        int init_size = strlen(str);
        char delim[] = ":";

        char *ptr = strtok(str, delim);

        int pathCount = 0;
        while (ptr != NULL)
        {
                paths[i][pathCount] = ptr;
                pathCount++;
                ptr = strtok(NULL, delim);
        }
}

int yyerror(char *s) {
  printf("%s\n",s);
  return 0;
}

int runSetEnv(char *var, char *word) {
	for (int i = 0; i < varIndex; i++) {
		if(strcmp(var, word) == 0){
			printf("Error, the variable:%s and word %s equal each other.\n", var, word);
			return 1;
		}
		else if((strcmp(varTable.var[i], var) == 0) && (strcmp(varTable.word[i], word) == 0)){
			printf("Error, the variable: %s and its corresponding word: %s already exist.\n", var, word);
			return 1;
		}
		else if(strcmp(varTable.var[i], var) == 0) {
			strcpy(varTable.word[i], word);
			return 1;
		}
	}
	strcpy(varTable.var[varIndex], var);
	strcpy(varTable.word[varIndex], word);
	varIndex++;
	return 1;
	
}

int runPrintEnv() {
	/*
	if(commandTable.output[0] != "") {
		printf("Output file: %s\n", commandTable.output[0]);
	}
	*/
	pid_t pid = fork();
        if (pid < 0) {
                exit(1);
        } else if (pid == 0) {
                if(commandTable.input[0] != "") { // Checks for directing input
                        int fd0 = open(commandTable.input[0], O_RDONLY, O_APPEND); //fix input
                        dup2(fd0, STDIN_FILENO);
                        close(fd0);
                }

                if(commandTable.output[0] != "") { // Checks for directing output
                        if(!commandTable.isDouble) {
                                int fd1 = open(commandTable.output[0], O_WRONLY); //fix output
                                dup2(fd1, STDOUT_FILENO);
                                close(fd1);
                        } else if (commandTable.isDouble) {
                                int fd1 = open(commandTable.output[0], O_WRONLY | O_APPEND);
                                dup2(fd1, STDOUT_FILENO);
                                close(fd1);
                        }
                        if(commandTable.stderr_stdoutput) {
                                int fd1 = open(commandTable.output[0], O_WRONLY);
                                dup2(fd1, STDERR_FILENO);
                                close(fd1);
                        }
                }

                if(commandTable.output[1] != "") {
                        int fd1 = open(commandTable.output[1], O_WRONLY);
                        dup2(fd1, STDERR_FILENO);
                        close(fd1);
                }

		for (int i = 0; i < sizeof(varTable.var); i++) {
			if(strcmp(varTable.var[i], "") == 0) {
				resetArguments();
				//printf("Output is clean: %s\n", commandTable.output[0]);
				argCount = 0;
				exit(0);
			} else {
				printf("%s=%s\n", varTable.var[i], varTable.word[i]);
			}
		}

        }
	wait(NULL);
	
	/*
		for (int i = 0; i < sizeof(varTable.var); i++) {
			if(strcmp(varTable.var[i], "") == 0) {
				return 1;
			} else {
				printf("%s=%s\n", varTable.var[i], varTable.word[i]);
			}
		}
        */

	resetArguments();
	//printf("Output is clean: %s\n", commandTable.output[0]);
	argCount = 0;
	return 1;
}

int runUnsetEnv(char *var) {
        for (int i = 0; i < sizeof(varTable.var); i++) {
                if(strcmp(varTable.var[i], "") == 0) {
						printf("No %s variable exists.\n", var);
                        return 1;
                } else if (strcmp(var, "HOME") == 0) {
						printf("Error: cannot unset HOME\n");
						return 1;
				} else if (strcmp(var, "PATH") == 0) {
						printf("Error: cannot unset PATH\n");
                        return 1;
                } else if (strcmp(varTable.var[i], var) == 0) {
                        strcpy(varTable.word[i], "");
                        return 1;
                }
        }
        return 1;
}

int runCD(char* arg) {

	if (arg[0] != '/') { // arg is relative path
		
		char *temp = malloc(128 * sizeof(char));
		strcpy(temp, varTable.word[0]);
		strcat(temp, "/");
		strcat(temp, arg);
		
		if(chdir(temp) == 0) {
			getcwd(cwd, sizeof(cwd));
			strcpy(varTable.word[0], cwd);
			return 1;
		} else {
			getcwd(cwd, sizeof(cwd));
			strcpy(varTable.word[0], cwd);
			printf("Directory not found\n");
			return 1;
		}
		free(temp);
	}
	else { // arg is absolute path
		if(chdir(arg) == 0){
			printf("abs path \n");
			strcpy(varTable.word[0], arg);
			return 1;
		}
		else {
			printf("Directory not found\n");
                        return 1;
		}
	}
	
}

int runCDn() {
	if (chdir(varTable.word[1]) == 0){
	    getcwd(cwd, sizeof(cwd));
        strcpy(varTable.word[0], cwd);
		return 1;
	}
	printf("there was an error\n");
	return 1;
}

int runSetAlias(char *name, char *word) {
	if (strcmp(name, word) == 0){
		printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
		return 1;
	}
	struct node* n1;
	struct node* n2;
	bool createdName = false;
	bool createdWord = false;
	int i;
	for (i = 0; i < nodeIndex; i++){
		struct node* n = graph->array[i];
		if (strcmp(name, n->info->value) == 0){
			n1 = n;
			createdName = true;
		}
		if (strcmp(word, n->info->value) == 0){
			n2 = n;
			createdWord = true;
		}
		
	}
		if(!createdName){
			n1 = newNode(graph, nodeIndex, name);
		}
		if(!createdWord){
			n2 = newNode(graph, nodeIndex, word);
		}
		addEdge(graph, n1, n2);
	
	if (isCyclic(graph)){
		printf("Error, expansion of name:\"%s\"  and word:\"%s\" would create a loop.\n", name, word);
		deleteEdge(graph, n1, n2);
		return 1;
	}
	

	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(aliasTable.name[i], name) == 0) {
			strcpy(aliasTable.word[i], word);
			return 1;
		}
	}
		
	strcpy(aliasTable.name[aliasIndex], name);
	strcpy(aliasTable.word[aliasIndex], word);
	aliasIndex++;
	return 1;
}

int runPrintAlias() {
	/*	
        if(commandTable.output[0] != "") {
                printf("Output file: %s\n", commandTable.output[0]);
        }
        */

	pid_t pid = fork();
        if (pid < 0) {
                exit(1);
        } else if (pid == 0) {
                if(commandTable.input[0] != "") { // Checks for directing input
                        int fd0 = open(commandTable.input[0], O_RDONLY, O_APPEND); //fix input
                        dup2(fd0, STDIN_FILENO);
                        close(fd0);
                }

                if(commandTable.output[0] != "") { // Checks for directing output
                        if(!commandTable.isDouble) {
                                int fd1 = open(commandTable.output[0], O_WRONLY); //fix output
                                dup2(fd1, STDOUT_FILENO);
                                close(fd1);
                        } else if (commandTable.isDouble) {
                                int fd1 = open(commandTable.output[0], O_WRONLY | O_APPEND);
                                dup2(fd1, STDOUT_FILENO);
                                close(fd1);
                        }
                        if(commandTable.stderr_stdoutput) {
                                int fd1 = open(commandTable.output[0], O_WRONLY);
                                dup2(fd1, STDERR_FILENO);
                                close(fd1);
                        }
                }

                if(commandTable.output[1] != "") {
                        int fd1 = open(commandTable.output[1], O_WRONLY);
                        dup2(fd1, STDERR_FILENO);
                        close(fd1);
                }
	
		// Printing aliases...
		if (aliasIndex == 0) {
                        printf("There are no available aliases\n");
			resetArguments();
			argCount = 0;
			exit(0);
                }
		for (int i = 0; i < aliasIndex; i++) {
			if(strcmp(aliasTable.name[i], "") == 0) {
				resetArguments();
				argCount = 0;
				exit(0);
			} else {
				printf("%s=%s\n", aliasTable.name[i], aliasTable.word[i]);
			}
		}
		resetArguments();
		argCount = 0;
		exit(0);
        }
        wait(NULL);
	
	/*
	if (aliasIndex == 0) {
		printf("There are no available aliases\n");
	}
	*/

	resetArguments();
        //printf("Output is clean: %s\n", commandTable.output[0]);
        argCount = 0;
	return 1;
}

int runRemoveAlias(char *name) {
	if(aliasIndex == 0){
		printf("Error, the alias table is empty\n");
		return 1;
	}
	bool found = false;
	for (int i = 0; i < aliasIndex; i++) {
		if(strcmp(aliasTable.name[i], name) == 0) {
			strcpy(aliasTable.name[i], aliasTable.name[aliasIndex-1]);
			strcpy(aliasTable.word[i], aliasTable.word[aliasIndex-1]);
			strcpy(aliasTable.name[aliasIndex-1], aliasTable.name[aliasIndex]);
			strcpy(aliasTable.word[aliasIndex-1], aliasTable.word[aliasIndex]);
			aliasIndex--;
			found = true;
		}
	}
	if (!found){
		printf("Error, alias with the name %s is not in the alias table\n", name);
	}
	
	return 1;
}

int runBasic(char *name) {

        char ** paths = malloc(128 * sizeof(char*));
        getPATHS(paths);
	
        for(int i = 0; paths[i] != NULL; i++) {
		strcpy(commandTable.pathsTemp[i], paths[i]);
		strcat(commandTable.pathsTemp[i], "/");
		strcat(commandTable.pathsTemp[i], commandTable.command[0]);
	}
	
	for(int i = 1; paths[i] != NULL; i++) {
		strcat(commandTable.pathsTemp[0], ":");
		strcat(commandTable.pathsTemp[0], commandTable.pathsTemp[i]);
		strcpy(commandTable.pathsTemp[i], "");
	}

	fixPATHS(paths);
	
        char* arg_list[argCount];

        for(int i = 0; i < argCount; i++) {
                arg_list[i] = commandTable.comArgs[i];
        }
        arg_list[argCount - 1] = NULL;

	//printf("\n");
	// Testing for arguments
	for(int i = 0; i < argCount - 1; i++) {
		printf("%s\n", arg_list[i]);
	}
	
	// Testing for I/O redirection
	//printf("Input: %d\n", commandTable.in);
	//printf("Output: %d\n", commandTable.out);
	//printf("error->output: %d\n", commandTable.stderr_stdoutput);
	
	printf("Input:\n");
	for(int i = 0; i < inputIndex; i++) {
                printf("%s\n", commandTable.input[i]);
        }
	printf("Output:\n");
	for(int i = 0; i < outputIndex; i++) {
		printf("%s\n", commandTable.output[i]);
	}
	printf("Command executing...\n");

	int errvalue;
	int sizePaths = sizeof paths / sizeof paths[0];
	bool didRun;
	bool runCount[sizePaths];	

        pid_t pid = fork();
        if (pid < 0) {
                exit(1);
        } else if (pid == 0) {
                if(commandTable.input[0] != "") { // Checks for directing input
			int fd0 = open(commandTable.input[0], O_RDONLY, O_APPEND); //fix input
			dup2(fd0, STDIN_FILENO);
			close(fd0);
		}

		if(commandTable.output[0] != "") { // Checks for directing output
			if(!commandTable.isDouble) {
				int fd1 = open(commandTable.output[0], O_WRONLY); //fix output
				dup2(fd1, STDOUT_FILENO);
				close(fd1);
			} else if (commandTable.isDouble) {
				int fd1 = open(commandTable.output[0], O_WRONLY | O_APPEND);
				dup2(fd1, STDOUT_FILENO);
				close(fd1);
			}
			if(commandTable.stderr_stdoutput) {
				int fd1 = open(commandTable.output[0], O_WRONLY);
				dup2(fd1, STDERR_FILENO);
				close(fd1);
			}
		}

		if(commandTable.output[1] != "") {
			int fd1 = open(commandTable.output[1], O_WRONLY);
			dup2(fd1, STDERR_FILENO);
			close(fd1);
		}	

		for(int i = 0; paths[i] != NULL; i++) {
                        execv(paths[i], arg_list);
			errvalue = errno;
			runCount[i] = errvalue;
                }

		for(int i = 0; i < sizePaths; i++) {
			if(runCount[i] == 0) {
				didRun = true;
			}
		}
		if(!didRun) {
			printf("The error generated was %d\n", 2);
			printf("That means: %s\n", strerror(2));
			commandTable.isErr = 1;
		}

		exit(0);
        }
	
	if (!runInBackground){
		runInBackground = false;
		wait(NULL);
	}

        free(paths);
        resetArguments();
        argCount = 0;
	runInBackground = false;
        return 1;
}
