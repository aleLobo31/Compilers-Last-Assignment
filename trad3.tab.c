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
#line 6 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
char *generar_if (char *, char *, char *) ;
char *generar_for(char *id, char *init_expr, char *cond_expr, char *iteration, char *body);
char *my_malloc (int) ;

char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr
#define INC(x) x=x+1
#define DEC(x) x=x-1

// Variables para el manejo de ámbitos y variables locales

extern char current_scope[256];         // Si está vacío, estamos en ámbito global
extern char local_vars[100][256];       // Tabla de variables locales
extern int num_locals;                  // Contador de variables locales

void add_local_var(char *name);         // Añade una variable local a la tabla
int is_local_var(char *name);           // Comprueba si una variable es local
char* get_var_name(char *name);         // Obtiene el nombre de una variable

// ------------------------------------


#line 130 "trad3.tab.c"

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

#include "trad3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_INC = 13,                       /* INC  */
  YYSYMBOL_DEC = 14,                       /* DEC  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_PUTS = 19,                      /* PUTS  */
  YYSYMBOL_PRINTF = 20,                    /* PRINTF  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 35,                /* UNARY_SIGN  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_axioma = 48,                    /* axioma  */
  YYSYMBOL_lista_pre_main = 49,            /* lista_pre_main  */
  YYSYMBOL_main_funcion = 50,              /* main_funcion  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_lista_sentencias = 52,          /* lista_sentencias  */
  YYSYMBOL_funcion = 53,                   /* funcion  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_lista_parametros = 55,          /* lista_parametros  */
  YYSYMBOL_param = 56,                     /* param  */
  YYSYMBOL_sentencia = 57,                 /* sentencia  */
  YYSYMBOL_bloque_control = 58,            /* bloque_control  */
  YYSYMBOL_resto_condicional = 59,         /* resto_condicional  */
  YYSYMBOL_lista_cases = 60,               /* lista_cases  */
  YYSYMBOL_base_case = 61,                 /* base_case  */
  YYSYMBOL_default_case = 62,              /* default_case  */
  YYSYMBOL_iteracion = 63,                 /* iteracion  */
  YYSYMBOL_declaracion = 64,               /* declaracion  */
  YYSYMBOL_lista_elementos = 65,           /* lista_elementos  */
  YYSYMBOL_elemento = 66,                  /* elemento  */
  YYSYMBOL_lista_vars = 67,                /* lista_vars  */
  YYSYMBOL_var_init = 68,                  /* var_init  */
  YYSYMBOL_expresion = 69,                 /* expresion  */
  YYSYMBOL_termino = 70,                   /* termino  */
  YYSYMBOL_operando = 71,                  /* operando  */
  YYSYMBOL_lista_argumentos = 72           /* lista_argumentos  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,    46,     2,     2,     2,    34,     2,     2,
      38,    39,    32,    30,    42,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   107,   108,   110,   116,   115,   131,   132,
     137,   145,   144,   158,   159,   160,   164,   171,   172,   177,
     183,   184,   188,   193,   200,   202,   208,   211,   216,   217,
     220,   221,   226,   231,   232,   237,   240,   245,   249,   250,
     253,   255,   259,   260,   264,   271,   278,   287,   288,   290,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     312,   316,   317,   318,   320,   324,   329,   330,   331,   336,
     345,   346,   347
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "RETURN", "WHILE", "IF", "ELSE", "FOR",
  "INC", "DEC", "SWITCH", "CASE", "DEFAULT", "BREAK", "PUTS", "PRINTF",
  "AND", "OR", "EQ", "NEQ", "LE", "GE", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY_SIGN", "NOT", "';'", "'('", "')'", "'{'",
  "'}'", "','", "'['", "']'", "':'", "'!'", "$accept", "axioma",
  "lista_pre_main", "main_funcion", "$@1", "lista_sentencias", "funcion",
  "$@2", "lista_parametros", "param", "sentencia", "bloque_control",
  "resto_condicional", "lista_cases", "base_case", "default_case",
  "iteracion", "declaracion", "lista_elementos", "elemento", "lista_vars",
  "var_init", "expresion", "termino", "operando", "lista_argumentos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,     2,    31,   -38,   -32,     6,    -8,   -38,   -38,    -3,
      36,    34,    16,   -38,     0,   -38,    66,   -15,   -38,    77,
      95,     6,    68,   -38,    83,    36,   -38,    81,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,    -1,    64,   -22,    29,    72,
      89,    94,   115,   118,   119,   -38,   123,   -38,   -38,   -38,
      29,    29,    29,   -38,   -26,    19,    19,    29,    19,   304,
     -38,   -38,    29,    29,   171,   172,   173,   175,   -38,   304,
     304,    39,   140,    29,    29,   -38,   -38,   181,   -38,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,   200,   219,   150,   143,   144,   136,   -38,    29,
     174,    67,   164,   -38,   330,   318,   340,   340,    59,    59,
      59,    59,    32,    32,   -38,   -38,   -38,   151,   159,    29,
     160,   -38,    25,   113,   304,    29,   -38,   -38,   -38,   -38,
     238,   -38,   -38,   -38,   304,   -38,    25,   304,    92,   109,
      29,    70,   -38,   -38,   205,   255,   214,   182,   -38,   177,
     179,   -38,   102,   190,   -38,   -38,   -38,   198,   199,   207,
     -38,   286,   126,   234,   250,   215,   303,   220,   -38,   217,
     226,   -38,   236,   -38,   -38,   -38,   139,   -38,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     2,     5,     0,
      13,    44,    37,    42,     0,     4,     0,     0,    14,     0,
       0,     0,     0,    16,     0,     0,    45,     0,    43,     6,
      11,    15,    46,     8,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,    10,    17,    12,
       0,    70,     0,    66,    65,     0,     0,     0,     0,    22,
      47,    61,     0,     0,     0,     0,     0,     0,     9,    18,
      71,     0,     0,    70,     0,    62,    63,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,    67,    53,    54,    55,    56,    59,    60,
      57,    58,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    21,     0,     0,    72,     0,    68,    69,     8,     8,
       0,    30,    41,    38,    40,    20,     0,    19,     0,     0,
       0,    33,    39,    24,    28,     0,     0,     0,    31,     0,
       0,    26,     0,     0,     8,    27,     8,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     8,     0,    34,    35,    36,     0,    32,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   -38,   -38,   -38,   -34,   -38,   -38,   -38,   249,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   280,   -38,   157,
     -38,   276,   -37,   -38,    84,   227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,    33,    35,     8,    34,    17,    18,
      46,    47,   151,   141,   148,   149,   159,    48,   123,   133,
      12,    13,    70,    60,    61,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    59,     3,    37,     5,    50,    10,    38,    39,    40,
      11,    41,    73,    69,    42,    72,    51,    74,    43,    44,
      77,    52,    53,    54,    24,    92,    93,    25,    53,    54,
      14,   132,    53,    54,    15,     4,     5,   102,     6,    22,
      45,    16,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    55,    56,    57,    21,    55,
      56,    19,   124,    57,    89,    90,    91,    57,    37,     5,
      23,    58,    38,    39,    40,    58,    41,    20,    98,    42,
      26,    99,   130,    43,    44,   134,   146,   147,   137,    87,
      88,    89,    90,    91,   138,   139,    37,     5,    27,   134,
      38,    39,    40,   145,    41,    49,   126,    42,    29,    99,
      62,    43,    44,    37,     5,   157,   158,    38,    39,    40,
     161,    41,   162,    30,    42,    32,   166,    63,    43,    44,
      37,     5,    64,   143,    38,    39,    40,   176,    41,    75,
      76,    42,    78,    37,     5,    43,    44,    38,    39,    40,
     144,    41,   135,    65,    42,   136,    66,    67,    43,    44,
      68,    79,    80,    81,    82,    83,    84,   168,    85,    86,
      87,    88,    89,    90,    91,    94,    95,   119,   122,    96,
     178,    97,   120,   121,   100,    79,    80,    81,    82,    83,
      84,   128,    85,    86,    87,    88,    89,    90,    91,   129,
     131,   125,    79,    80,    81,    82,    83,    84,   127,    85,
      86,    87,    88,    89,    90,    91,   150,   153,   155,   156,
     103,    79,    80,    81,    82,    83,    84,   154,    85,    86,
      87,    88,    89,    90,    91,   160,   163,   164,   169,   117,
      79,    80,    81,    82,    83,    84,   165,    85,    86,    87,
      88,    89,    90,    91,   170,   171,   174,   173,   118,    79,
      80,    81,    82,    83,    84,   175,    85,    86,    87,    88,
      89,    90,    91,   177,    31,   140,    79,    80,    81,    82,
      83,    84,     9,    85,    86,    87,    88,    89,    90,    91,
      37,     5,   152,   142,    38,    39,    40,    28,    41,     0,
     101,    42,     0,     0,   167,    43,    44,    37,     5,     0,
       0,    38,    39,    40,     0,    41,     0,     0,    42,     0,
       0,   172,    43,    44,     0,    79,    80,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    91,    79,
       0,    81,    82,    83,    84,     0,    85,    86,    87,    88,
      89,    90,    91,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    91,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      34,    38,     0,     4,     5,    27,    38,     8,     9,    10,
       4,    12,    38,    50,    15,    52,    38,    43,    19,    20,
      57,    43,     3,     4,    39,    62,    63,    42,     3,     4,
      38,     6,     3,     4,    37,     4,     5,    74,     7,    39,
      41,     5,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    30,    31,    38,    42,    30,
      31,    27,    99,    38,    32,    33,    34,    38,     4,     5,
       4,    46,     8,     9,    10,    46,    12,    43,    39,    15,
       3,    42,   119,    19,    20,   122,    16,    17,   125,    30,
      31,    32,    33,    34,   128,   129,     4,     5,     3,   136,
       8,     9,    10,   140,    12,    41,    39,    15,    40,    42,
      38,    19,    20,     4,     5,    13,    14,     8,     9,    10,
     154,    12,   156,    40,    15,    44,   160,    38,    19,    20,
       4,     5,    38,    41,     8,     9,    10,   171,    12,    55,
      56,    15,    58,     4,     5,    19,    20,     8,     9,    10,
      41,    12,    39,    38,    15,    42,    38,    38,    19,    20,
      37,    21,    22,    23,    24,    25,    26,    41,    28,    29,
      30,    31,    32,    33,    34,     4,     4,    27,    42,     6,
      41,     6,    39,    39,    44,    21,    22,    23,    24,    25,
      26,    40,    28,    29,    30,    31,    32,    33,    34,    40,
      40,    27,    21,    22,    23,    24,    25,    26,    44,    28,
      29,    30,    31,    32,    33,    34,    11,     3,    41,    40,
      39,    21,    22,    23,    24,    25,    26,    45,    28,    29,
      30,    31,    32,    33,    34,    45,    38,    38,     4,    39,
      21,    22,    23,    24,    25,    26,    39,    28,    29,    30,
      31,    32,    33,    34,     4,    40,    39,    37,    39,    21,
      22,    23,    24,    25,    26,    39,    28,    29,    30,    31,
      32,    33,    34,    37,    25,    37,    21,    22,    23,    24,
      25,    26,     2,    28,    29,    30,    31,    32,    33,    34,
       4,     5,    37,   136,     8,     9,    10,    21,    12,    -1,
      73,    15,    -1,    -1,    18,    19,    20,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    -1,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    21,
      -1,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     4,     5,     7,    50,    53,    64,
      38,     4,    67,    68,    38,    37,     5,    55,    56,    27,
      43,    42,    39,     4,    39,    42,     3,     3,    68,    40,
      40,    56,    44,    51,    54,    52,    52,     4,     8,     9,
      10,    12,    15,    19,    20,    41,    57,    58,    64,    41,
      27,    38,    43,     3,     4,    30,    31,    38,    46,    69,
      70,    71,    38,    38,    38,    38,    38,    38,    37,    69,
      69,    72,    69,    38,    43,    71,    71,    69,    71,    21,
      22,    23,    24,    25,    26,    28,    29,    30,    31,    32,
      33,    34,    69,    69,     4,     4,     6,     6,    39,    42,
      44,    72,    69,    39,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    39,    39,    27,
      39,    39,    42,    65,    69,    27,    39,    44,    40,    40,
      69,    40,     6,    66,    69,    39,    42,    69,    52,    52,
      37,    60,    66,    41,    41,    69,    16,    17,    61,    62,
      11,    59,    37,     3,    45,    41,    40,    13,    14,    63,
      45,    52,    52,    38,    38,    39,    52,    18,    41,     4,
       4,    40,    18,    37,    39,    39,    52,    37,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    51,    50,    52,    52,
      52,    54,    53,    55,    55,    55,    56,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     2,     0,     7,     0,     3,
       2,     0,     8,     0,     1,     3,     2,     1,     3,     6,
       5,     4,     2,     4,     7,    13,     8,     8,     0,     4,
       0,     2,     6,     0,     5,     4,     4,     2,     2,     3,
       1,     1,     1,     3,     1,     3,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     2,     1,     1,     3,     4,     4,
       0,     1,     3
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
  case 2: /* axioma: lista_pre_main main_funcion  */
#line 104 "trad3.y"
                                        { printf ("%s%s\n", yyvsp[-1].code, yyvsp[0].code) ; }
#line 1337 "trad3.tab.c"
    break;

  case 3: /* lista_pre_main: %empty  */
#line 107 "trad3.y"
                                                     { yyval.code = gen_code("") ; }
#line 1343 "trad3.tab.c"
    break;

  case 4: /* lista_pre_main: lista_pre_main declaracion ';'  */
#line 108 "trad3.y"
                                                     { sprintf (temp, "%s\n%s\n", yyvsp[-2].code, yyvsp[-1].code) ; 
                                                       yyval.code = gen_code (temp) ; }
#line 1350 "trad3.tab.c"
    break;

  case 5: /* lista_pre_main: lista_pre_main funcion  */
#line 110 "trad3.y"
                                                     { sprintf (temp, "%s\n%s\n", yyvsp[-1].code, yyvsp[0].code) ; 
                                                       yyval.code = gen_code (temp) ; }
#line 1357 "trad3.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 116 "trad3.y"
        { 
            // Acción intermedia
            strcpy(current_scope, "main"); 
            num_locals = 0; 
        }
#line 1367 "trad3.tab.c"
    break;

  case 7: /* main_funcion: MAIN '(' ')' '{' $@1 lista_sentencias '}'  */
#line 122 "trad3.y"
        { 
            // Acción final
            sprintf (temp, "(defun main ()\n%s\n)", yyvsp[-1].code) ; 
            yyval.code = gen_code (temp) ; 
            strcpy(current_scope, ""); 
        }
#line 1378 "trad3.tab.c"
    break;

  case 8: /* lista_sentencias: %empty  */
#line 131 "trad3.y"
                                                    { yyval.code = gen_code("") ; }
#line 1384 "trad3.tab.c"
    break;

  case 9: /* lista_sentencias: lista_sentencias sentencia ';'  */
#line 132 "trad3.y"
                                                    { if (strlen(yyvsp[-2].code) == 0) 
                                                          sprintf (temp, "%s", yyvsp[-1].code) ;
                                                      else 
                                                          sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                                      yyval.code = gen_code (temp) ; }
#line 1394 "trad3.tab.c"
    break;

  case 10: /* lista_sentencias: lista_sentencias bloque_control  */
#line 137 "trad3.y"
                                                    { if (strlen(yyvsp[-1].code) == 0) 
                                                          sprintf (temp, "%s", yyvsp[0].code) ;
                                                      else 
                                                          sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                                      yyval.code = gen_code (temp) ; }
#line 1404 "trad3.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 145 "trad3.y"
        { 
            strcpy(current_scope, yyvsp[-4].code);
            num_locals = 0; 
        }
#line 1413 "trad3.tab.c"
    break;

  case 12: /* funcion: IDENTIF '(' lista_parametros ')' '{' $@2 lista_sentencias '}'  */
#line 150 "trad3.y"
        { 
            sprintf (temp, "(defun %s (%s)\n%s)\n", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ; 
            yyval.code = gen_code (temp) ; 
            strcpy(current_scope, ""); 
        }
#line 1423 "trad3.tab.c"
    break;

  case 13: /* lista_parametros: %empty  */
#line 158 "trad3.y"
                            { yyval.code = gen_code(""); }
#line 1429 "trad3.tab.c"
    break;

  case 14: /* lista_parametros: param  */
#line 159 "trad3.y"
                            { yyval = yyvsp[0]; }
#line 1435 "trad3.tab.c"
    break;

  case 15: /* lista_parametros: lista_parametros ',' param  */
#line 160 "trad3.y"
                                 { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1441 "trad3.tab.c"
    break;

  case 16: /* param: INTEGER IDENTIF  */
#line 165 "trad3.y"
        { 
            add_local_var(yyvsp[0].code);
            yyval.code = gen_code(yyvsp[0].code); 
        }
#line 1450 "trad3.tab.c"
    break;

  case 17: /* sentencia: declaracion  */
#line 171 "trad3.y"
                                                  { yyval = yyvsp[0] ; }
#line 1456 "trad3.tab.c"
    break;

  case 18: /* sentencia: IDENTIF '=' expresion  */
#line 172 "trad3.y"
                                                  { 
                    char *var_name = get_var_name(yyvsp[-2].code);
                    sprintf (temp, "(setf %s %s)", var_name, yyvsp[0].code) ; 
                    yyval.code = gen_code (temp) ; 
                }
#line 1466 "trad3.tab.c"
    break;

  case 19: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 178 "trad3.y"
                {
                    char *var_name = get_var_name(yyvsp[-5].code);
                    sprintf(temp, "(setf (aref %s %s) %s)", var_name, yyvsp[-3].code, yyvsp[0].code);
                    yyval.code = gen_code(temp);
                }
#line 1476 "trad3.tab.c"
    break;

  case 20: /* sentencia: PRINTF '(' STRING lista_elementos ')'  */
#line 183 "trad3.y"
                                                  { yyval = yyvsp[-1] ; }
#line 1482 "trad3.tab.c"
    break;

  case 21: /* sentencia: PUTS '(' STRING ')'  */
#line 184 "trad3.y"
                                                  { 
                    sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                    yyval.code = gen_code (temp) ; 
                }
#line 1491 "trad3.tab.c"
    break;

  case 22: /* sentencia: RETURN expresion  */
#line 189 "trad3.y"
                { 
                    sprintf(temp, "(return-from %s %s)", current_scope, yyvsp[0].code);
                    yyval.code = gen_code(temp);
                }
#line 1500 "trad3.tab.c"
    break;

  case 23: /* sentencia: IDENTIF '(' lista_argumentos ')'  */
#line 194 "trad3.y"
                { 
                    sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                    yyval.code = gen_code(temp);
                }
#line 1509 "trad3.tab.c"
    break;

  case 24: /* bloque_control: WHILE '(' expresion ')' '{' lista_sentencias '}'  */
#line 200 "trad3.y"
                                                                  { sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                  yyval.code = gen_code (temp) ; }
#line 1516 "trad3.tab.c"
    break;

  case 25: /* bloque_control: FOR '(' IDENTIF '=' expresion ';' expresion ';' iteracion ')' '{' lista_sentencias '}'  */
#line 203 "trad3.y"
                        { 
                            char *name = get_var_name(yyvsp[-10].code);
                            yyval.code = generar_for(name, yyvsp[-8].code, yyvsp[-6].code, yyvsp[-4].code, yyvsp[-1].code) ; 
                        }
#line 1525 "trad3.tab.c"
    break;

  case 26: /* bloque_control: IF '(' expresion ')' '{' lista_sentencias '}' resto_condicional  */
#line 209 "trad3.y"
                        { yyval.code = generar_if(yyvsp[-5].code, yyvsp[-2].code, yyvsp[0].code) ; }
#line 1531 "trad3.tab.c"
    break;

  case 27: /* bloque_control: SWITCH '(' IDENTIF ')' '{' lista_cases default_case '}'  */
#line 212 "trad3.y"
                        { sprintf (temp, "(case %s\n%s\n%s)", yyvsp[-5].code, yyvsp[-2].code, yyvsp[-1].code) ; 
                          yyval.code = gen_code (temp) ; }
#line 1538 "trad3.tab.c"
    break;

  case 28: /* resto_condicional: %empty  */
#line 216 "trad3.y"
                                                    { yyval.code = gen_code ("") ; }
#line 1544 "trad3.tab.c"
    break;

  case 29: /* resto_condicional: ELSE '{' lista_sentencias '}'  */
#line 217 "trad3.y"
                                                    { yyval = yyvsp[-1] ; }
#line 1550 "trad3.tab.c"
    break;

  case 30: /* lista_cases: %empty  */
#line 220 "trad3.y"
                        { yyval.code = gen_code ("") ; }
#line 1556 "trad3.tab.c"
    break;

  case 31: /* lista_cases: lista_cases base_case  */
#line 222 "trad3.y"
                        { sprintf (temp, "%s %s", yyvsp[-1].code, yyvsp[0].code) ; 
                        yyval.code = gen_code (temp) ; }
#line 1563 "trad3.tab.c"
    break;

  case 32: /* base_case: CASE NUMBER ':' lista_sentencias BREAK ';'  */
#line 227 "trad3.y"
                    { sprintf (temp, "(%d\n  %s)", yyvsp[-4].value, yyvsp[-2].code) ; 
                    yyval.code = gen_code (temp) ; }
#line 1570 "trad3.tab.c"
    break;

  case 33: /* default_case: %empty  */
#line 231 "trad3.y"
                    { yyval.code = gen_code ("") ; }
#line 1576 "trad3.tab.c"
    break;

  case 34: /* default_case: DEFAULT ':' lista_sentencias BREAK ';'  */
#line 233 "trad3.y"
                    { sprintf (temp, "(otherwise\n  %s)", yyvsp[-2].code) ; 
                    yyval.code = gen_code (temp) ; }
#line 1583 "trad3.tab.c"
    break;

  case 35: /* iteracion: INC '(' IDENTIF ')'  */
#line 237 "trad3.y"
                                 {  char *name = get_var_name(yyvsp[-1].code);
                                    sprintf(temp, "(setf %s (+ %s 1))", name, name); 
                                     yyval.code = gen_code(temp); }
#line 1591 "trad3.tab.c"
    break;

  case 36: /* iteracion: DEC '(' IDENTIF ')'  */
#line 240 "trad3.y"
                                   {  char *name = get_var_name(yyvsp[-1].code);
                                    sprintf(temp, "(setf %s (- %s 1))", name, name); 
                                     yyval.code = gen_code(temp); }
#line 1599 "trad3.tab.c"
    break;

  case 37: /* declaracion: INTEGER lista_vars  */
#line 245 "trad3.y"
                                         { yyval = yyvsp[0] ; }
#line 1605 "trad3.tab.c"
    break;

  case 38: /* lista_elementos: ',' elemento  */
#line 249 "trad3.y"
                                                    { yyval = yyvsp[0] ; }
#line 1611 "trad3.tab.c"
    break;

  case 39: /* lista_elementos: lista_elementos ',' elemento  */
#line 250 "trad3.y"
                                                    { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;  
                                                    yyval.code = gen_code (temp) ; }
#line 1618 "trad3.tab.c"
    break;

  case 40: /* elemento: expresion  */
#line 253 "trad3.y"
                                { sprintf (temp, "(princ %s)", yyvsp[0].code) ; 
                                yyval.code = gen_code (temp) ; }
#line 1625 "trad3.tab.c"
    break;

  case 41: /* elemento: STRING  */
#line 255 "trad3.y"
                                { sprintf (temp, "(princ \"%s\")", yyvsp[0].code) ; 
                                yyval.code = gen_code (temp) ; }
#line 1632 "trad3.tab.c"
    break;

  case 42: /* lista_vars: var_init  */
#line 259 "trad3.y"
                                         { yyval = yyvsp[0] ; }
#line 1638 "trad3.tab.c"
    break;

  case 43: /* lista_vars: lista_vars ',' var_init  */
#line 260 "trad3.y"
                                         { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1645 "trad3.tab.c"
    break;

  case 44: /* var_init: IDENTIF  */
#line 265 "trad3.y"
                { 
                    if (strlen(current_scope) > 0) add_local_var(yyvsp[0].code);
                    char *var_name = get_var_name(yyvsp[0].code);
                    sprintf (temp, "(setq %s 0)", var_name) ;
                    yyval.code = gen_code (temp) ; 
                }
#line 1656 "trad3.tab.c"
    break;

  case 45: /* var_init: IDENTIF '=' NUMBER  */
#line 272 "trad3.y"
                { 
                    if (strlen(current_scope) > 0) add_local_var(yyvsp[-2].code);
                    char *var_name = get_var_name(yyvsp[-2].code);
                    sprintf (temp, "(setq %s %d)", var_name, yyvsp[0].value) ;
                    yyval.code = gen_code (temp) ; 
                }
#line 1667 "trad3.tab.c"
    break;

  case 46: /* var_init: IDENTIF '[' NUMBER ']'  */
#line 279 "trad3.y"
            {
                if (strlen(current_scope) > 0) add_local_var(yyvsp[-3].code);
                char *var_name = get_var_name(yyvsp[-3].code);
                sprintf (temp, "(setq %s (make-array %d))", var_name, yyvsp[-1].value);
                yyval.code = gen_code (temp);
            }
#line 1678 "trad3.tab.c"
    break;

  case 47: /* expresion: termino  */
#line 287 "trad3.y"
                                           { yyval = yyvsp[0] ; }
#line 1684 "trad3.tab.c"
    break;

  case 48: /* expresion: expresion '+' expresion  */
#line 288 "trad3.y"
                                           { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1691 "trad3.tab.c"
    break;

  case 49: /* expresion: expresion '-' expresion  */
#line 290 "trad3.y"
                                           { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1698 "trad3.tab.c"
    break;

  case 50: /* expresion: expresion '*' expresion  */
#line 292 "trad3.y"
                                           { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1705 "trad3.tab.c"
    break;

  case 51: /* expresion: expresion '/' expresion  */
#line 294 "trad3.y"
                                           { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1712 "trad3.tab.c"
    break;

  case 52: /* expresion: expresion '%' expresion  */
#line 296 "trad3.y"
                                           { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1719 "trad3.tab.c"
    break;

  case 53: /* expresion: expresion AND expresion  */
#line 298 "trad3.y"
                                           { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1726 "trad3.tab.c"
    break;

  case 54: /* expresion: expresion OR expresion  */
#line 300 "trad3.y"
                                           { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1733 "trad3.tab.c"
    break;

  case 55: /* expresion: expresion EQ expresion  */
#line 302 "trad3.y"
                                           { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1740 "trad3.tab.c"
    break;

  case 56: /* expresion: expresion NEQ expresion  */
#line 304 "trad3.y"
                                           { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ; // En Lisp el distinto es /=
                                           yyval.code = gen_code (temp) ; }
#line 1747 "trad3.tab.c"
    break;

  case 57: /* expresion: expresion '<' expresion  */
#line 306 "trad3.y"
                                           { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1754 "trad3.tab.c"
    break;

  case 58: /* expresion: expresion '>' expresion  */
#line 308 "trad3.y"
                                           { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1761 "trad3.tab.c"
    break;

  case 59: /* expresion: expresion LE expresion  */
#line 310 "trad3.y"
                                           { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1768 "trad3.tab.c"
    break;

  case 60: /* expresion: expresion GE expresion  */
#line 312 "trad3.y"
                                           { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1775 "trad3.tab.c"
    break;

  case 61: /* termino: operando  */
#line 316 "trad3.y"
                                                   { yyval = yyvsp[0] ; }
#line 1781 "trad3.tab.c"
    break;

  case 62: /* termino: '+' operando  */
#line 317 "trad3.y"
                                                   { yyval = yyvsp[-1] ; }
#line 1787 "trad3.tab.c"
    break;

  case 63: /* termino: '-' operando  */
#line 318 "trad3.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1794 "trad3.tab.c"
    break;

  case 64: /* termino: '!' operando  */
#line 320 "trad3.y"
                                                   { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                    yyval.code = gen_code (temp) ; }
#line 1801 "trad3.tab.c"
    break;

  case 65: /* operando: IDENTIF  */
#line 324 "trad3.y"
                                     { 
                char *var_name = get_var_name(yyvsp[0].code);
                sprintf (temp, "%s", var_name) ;
                yyval.code = gen_code (temp) ; 
            }
#line 1811 "trad3.tab.c"
    break;

  case 66: /* operando: NUMBER  */
#line 329 "trad3.y"
                                       { sprintf (temp, "%d", yyvsp[0].value) ; yyval.code = gen_code (temp) ; }
#line 1817 "trad3.tab.c"
    break;

  case 67: /* operando: '(' expresion ')'  */
#line 330 "trad3.y"
                                       { yyval = yyvsp[-1] ; }
#line 1823 "trad3.tab.c"
    break;

  case 68: /* operando: IDENTIF '(' lista_argumentos ')'  */
#line 332 "trad3.y"
                { 
                    sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                    yyval.code = gen_code(temp);
                }
#line 1832 "trad3.tab.c"
    break;

  case 69: /* operando: IDENTIF '[' expresion ']'  */
#line 337 "trad3.y"
                {
                    char *var_name = get_var_name(yyvsp[-3].code);
                    sprintf(temp, "(aref %s %s)", var_name, yyvsp[-1].code);
                    yyval.code = gen_code(temp);
                }
#line 1842 "trad3.tab.c"
    break;

  case 70: /* lista_argumentos: %empty  */
#line 345 "trad3.y"
                            { yyval.code = gen_code(""); }
#line 1848 "trad3.tab.c"
    break;

  case 71: /* lista_argumentos: expresion  */
#line 346 "trad3.y"
                                    { yyval = yyvsp[0]; }
#line 1854 "trad3.tab.c"
    break;

  case 72: /* lista_argumentos: lista_argumentos ',' expresion  */
#line 347 "trad3.y"
                                             { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1860 "trad3.tab.c"
    break;


#line 1864 "trad3.tab.c"

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

#line 350 "trad3.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)

char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *generar_if(char *condicion, char *rama_then, char *rama_else) 
{
    // Reservamos la memoria máxima segura (los 3 strings + margen) para bloques con múltiples instrucciones
    int max_len = strlen(condicion) + strlen(rama_then) + strlen(rama_else) + 100;
    char *resultado = (char *) my_malloc(max_len);
    
    char *then_alloc = NULL;
    char *else_alloc = NULL;
    char *then_branch = rama_then;
    char *else_branch = rama_else;

    // Evaluamos la rama THEN buscando el salto de línea (porque entre sentencias hay un salto de línea)
    if (strchr(rama_then, '\n') != NULL) {
        then_branch = (char *) my_malloc(strlen(rama_then) + 20);
        sprintf(then_branch, "(progn\n%s)", rama_then);
        then_alloc = then_branch;
    }

    // Evaluamos la rama ELSE (si existe)
    if (strlen(rama_else) > 0) {
        if (strchr(rama_else, '\n') != NULL) {
            else_branch = (char *) my_malloc(strlen(rama_else) + 20);
            sprintf(else_branch, "(progn\n%s)", rama_else);
            else_alloc = else_branch;
        }
        // Juntamos la versión con ELSE
        sprintf(resultado, "(if %s\n %s\n %s)", condicion, then_branch, else_branch);
    } else {
        // Juntamos la versión sin ELSE
        sprintf(resultado, "(if %s\n %s)", condicion, then_branch);
    }

    char *final = gen_code(resultado);

    free(resultado);
    if (then_alloc) free(then_alloc); // Liberamos la memoria
    if (else_alloc) free(else_alloc); // Liberamos la memoria
    return final;
}

char *generar_for(char *id, char *init_expr, char *cond_expr, char *iteration, char *body)
{
    char *init_code;
    char *loop_body;
    char *loop_alloc = NULL;
    int max_len;
    char *resultado;

    // Desenrrollamos la primera parte del bucle con la inicialización del iterador
    init_code = (char *) my_malloc(strlen(id) + strlen(init_expr) + 20);
    sprintf(init_code, "(setf %s %s)", id, init_expr);

    // Agregamos al final del cuerpo del bucle la iteracion y contemplamos caso de for vacío
    if (strlen(body) > 0) {
        loop_body = (char *) my_malloc(strlen(body) + strlen(iteration) + 10);
        loop_alloc = loop_body;
        sprintf(loop_body, "%s\n %s", body, iteration);
    } else {
        loop_body = iteration;
    }

    // Juntamos las dos partes y reservamos memoria
    max_len = strlen(init_code) + strlen(cond_expr) + strlen(loop_body) + 50;
    resultado = (char *) my_malloc(max_len);
    sprintf(resultado, "%s\n(loop while %s do\n %s)", init_code, cond_expr, loop_body);

    char *final = gen_code(resultado);

    free(resultado);
    if (init_code) free(init_code); // Liberamos la memoria
    if (loop_alloc) free(loop_alloc); // Liberamos la memoria
    return final;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}

char current_scope[256] = ""; // Si está vacío, estamos en ámbito global
char local_vars[100][256];    // Tabla de variables locales
int num_locals = 0;           // Contador de variables locales

void add_local_var(char *name) {
    strcpy(local_vars[num_locals++], name);
}

int is_local_var(char *name) {
    for (int i = 0; i < num_locals; i++) {
        if (strcmp(local_vars[i], name) == 0) return 1;
    }
    return 0;
}

char* get_var_name(char *name) {
    char temp_name[512];
    if (strlen(current_scope) > 0 && is_local_var(name)) {
        sprintf(temp_name, "%s_%s", current_scope, name);
        return gen_code(temp_name);
    }
    return gen_code(name);
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "return",      RETURN,
    "int",         INTEGER,
    "while",       WHILE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "inc",         INC,
    "dec",         DEC,
    "switch",      SWITCH,
    "case",        CASE,
    "default",     DEFAULT,
    "break",       BREAK,     
    "puts",        PUTS,
    "printf",      PRINTF,
    "&&",          AND,
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "<=",          LE,
    ">=",          GE,
    NULL,          0              // para marcar el fin de la tabla
} ;

t_keyword * search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
