/*
202 , Alejandro Pérez Montes , Alejandro De Santos Lobo
100499978@alumnos.uc3m.es ,  100499148@alumnos.uc3m.es
*/

%{                          // SECCION 1 Declaraciones de C-Yacc

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

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token RETURN        // identifica el return
%token WHILE         // identifica el bucle while
%token IF            // identifica el if
%token ELSE          // identifica el else
%token FOR           // identifica el for
%token INC           // identifica el incremento
%token DEC           // identifica el decremento
%token SWITCH        // identifica el switch
%token CASE          // identifica el case
%token DEFAULT       // identifica el default
%token BREAK         // identifica el break
%token PUTS          // identifica la orden de impresión puts 
%token PRINTF        // identifica la orden de impresión printf
%token AND           // &&
%token OR            // ||
%token EQ            // ==
%token NEQ           // !=
%token LE            // <=
%token GE            // >=


%right '='                    // is the last operation to be performed
%left OR                      // ||
%left AND                     // &&
%left EQ NEQ                  // ==, !=
%left '<' '>' LE GE           // <, >, <=, >=
%left '+' '-'                 // lower precedence
%left '*' '/' '%'             // intermediate precedence
%left UNARY_SIGN NOT          // higher precedence

%%                            // Section 3 Grammar - Semantic Actions

axioma:     lista_pre_main main_funcion { printf ("%s%s\n", $1.code, $2.code) ; }
            ;

lista_pre_main:                                      { $$.code = gen_code("") ; }
                | declaracion ';' lista_pre_main     { sprintf (temp, "%s\n%s\n", $1.code, $3.code) ; 
                                                       $$.code = gen_code (temp) ; }
                | funcion lista_pre_main             { sprintf (temp, "%s\n%s\n", $1.code, $2.code) ; 
                                                       $$.code = gen_code (temp) ; }
                ;

main_funcion: 
      MAIN '(' ')' '{' 
        { 
            // Acción intermedia
            strcpy(current_scope, "main"); 
            num_locals = 0; 
        } 
      lista_sentencias '}' 
        { 
            // Acción final
            sprintf (temp, "(defun main ()\n%s\n)", $6.code) ; 
            $$.code = gen_code (temp) ; 
            strcpy(current_scope, ""); 
        }
    ;


lista_sentencias:                                   { $$.code = gen_code("") ; }
                | sentencia ';' lista_sentencias    { if (strlen($3.code) == 0) 
                                                          sprintf (temp, "%s", $1.code) ;
                                                      else 
                                                          sprintf (temp, "%s\n%s", $1.code, $3.code) ;
                                                      $$.code = gen_code (temp) ; }
                | bloque_control lista_sentencias   { if (strlen($2.code) == 0) 
                                                          sprintf (temp, "%s", $1.code) ;
                                                      else 
                                                          sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                                      $$.code = gen_code (temp) ; }

funcion: 
        IDENTIF '(' lista_parametros ')' '{' 
        { 
            strcpy(current_scope, $1.code);
            num_locals = 0; 
        } 
        lista_sentencias '}' 
        { 
            sprintf (temp, "(defun %s (%s)\n%s)\n", $1.code, $3.code, $7.code) ; 
            $$.code = gen_code (temp) ; 
            strcpy(current_scope, ""); 
        }
    ;

lista_parametros:
                            { $$.code = gen_code(""); }
    | param                 { $$ = $1; }
    | param ',' lista_parametros { sprintf(temp, "%s %s", $1.code, $3.code); $$.code = gen_code(temp); }
    ;

param: 
      INTEGER IDENTIF      
        { 
            add_local_var($2.code);
            $$.code = gen_code($2.code); 
        }
    ;

sentencia:    declaracion                         { $$ = $1 ; }
            | IDENTIF '=' expresion               { 
                    char *var_name = get_var_name($1.code);
                    sprintf (temp, "(setf %s %s)", var_name, $3.code) ; 
                    $$.code = gen_code (temp) ; 
                }
            | IDENTIF '[' expresion ']' '=' expresion
                {
                    char *var_name = get_var_name($1.code);
                    sprintf(temp, "(setf (aref %s %s) %s)", var_name, $3.code, $6.code);
                    $$.code = gen_code(temp);
                }
            | PRINTF '('STRING lista_elementos ')'{ $$ = $4 ; }
            | PUTS '(' STRING ')'                 { 
                    sprintf (temp, "(print \"%s\")", $3.code) ;  
                    $$.code = gen_code (temp) ; 
                }
            | RETURN expresion 
                { 
                    sprintf(temp, "(return-from %s %s)", current_scope, $2.code);
                    $$.code = gen_code(temp);
                }
            | IDENTIF '(' lista_argumentos ')' 
                { 
                    sprintf(temp, "(%s %s)", $1.code, $3.code);
                    $$.code = gen_code(temp);
                }
            ;

bloque_control: WHILE '(' expresion ')' '{' lista_sentencias '}'  { sprintf (temp, "(loop while %s do\n%s)", $3.code, $6.code) ;
                                                                  $$.code = gen_code (temp) ; }
                | FOR '(' IDENTIF '=' expresion ';' expresion ';' iteracion ')' '{' lista_sentencias '}'
                        { 
                            char *name = get_var_name($3.code);
                            $$.code = generar_for(name, $5.code, $7.code, $9.code, $12.code) ; 
                        }
            
                | IF '(' expresion ')' '{' lista_sentencias '}' resto_condicional 
                        { $$.code = generar_if($3.code, $6.code, $8.code) ; }
                
                | SWITCH '(' IDENTIF ')' '{' lista_cases default_case '}' 
                        { sprintf (temp, "(case %s\n%s\n%s)", $3.code, $6.code, $7.code) ; 
                          $$.code = gen_code (temp) ; }
                ;

resto_condicional:                                  { $$.code = gen_code ("") ; }
                | ELSE '{' lista_sentencias '}'     { $$ = $3 ; }
                ;

lista_cases:            { $$.code = gen_code ("") ; }                                        
                | base_case lista_cases { sprintf (temp, "%s %s", $1.code, $2.code) ; 
                        $$.code = gen_code (temp) ; }
                ;

base_case:      CASE NUMBER ':' lista_sentencias BREAK ';'
                    { sprintf (temp, "(%d\n  %s)", $2.value, $4.code) ; 
                    $$.code = gen_code (temp) ; }
                ;

default_case:       { $$.code = gen_code ("") ; }
                | DEFAULT ':' lista_sentencias BREAK ';'     
                    { sprintf (temp, "(otherwise\n  %s)", $3.code) ; 
                    $$.code = gen_code (temp) ; }
                ;

iteracion:   INC '(' IDENTIF ')' {  char *name = get_var_name($3.code);
                                    sprintf(temp, "(setf %s (+ %s 1))", name, name); 
                                     $$.code = gen_code(temp); }
             | DEC '(' IDENTIF ')' {  char *name = get_var_name($3.code);
                                    sprintf(temp, "(setf %s (- %s 1))", name, name); 
                                     $$.code = gen_code(temp); }
             ;

declaracion:  INTEGER lista_vars         { $$ = $2 ; }
            ;


lista_elementos:  ',' elemento                      { $$ = $2 ; }
            | ',' elemento lista_elementos { sprintf (temp, "%s\n%s", $2.code, $3.code) ;  
                                                    $$.code = gen_code (temp) ; }
            ;

elemento:    expresion          { sprintf (temp, "(princ %s)", $1.code) ; 
                                $$.code = gen_code (temp) ; }
            |  STRING           { sprintf (temp, "(princ \"%s\")", $1.code) ; 
                                $$.code = gen_code (temp) ; }
            ;

lista_vars:   var_init                   { $$ = $1 ; }
            | var_init ',' lista_vars    { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

var_init:     IDENTIF 
                { 
                    if (strlen(current_scope) > 0) add_local_var($1.code);
                    char *var_name = get_var_name($1.code);
                    sprintf (temp, "(setq %s 0)", var_name) ;
                    $$.code = gen_code (temp) ; 
                }
            | IDENTIF '=' NUMBER 
                { 
                    if (strlen(current_scope) > 0) add_local_var($1.code);
                    char *var_name = get_var_name($1.code);
                    sprintf (temp, "(setq %s %d)", var_name, $3.value) ;
                    $$.code = gen_code (temp) ; 
                }
            | IDENTIF '[' NUMBER ']'
            {
                if (strlen(current_scope) > 0) add_local_var($1.code);
                char *var_name = get_var_name($1.code);
                sprintf (temp, "(setq %s (make-array %d))", var_name, $3.value);
                $$.code = gen_code (temp);
            }
            ;
          
expresion:      termino                    { $$ = $1 ; }
            |   expresion '+' expresion    { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '-' expresion    { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '*' expresion    { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '/' expresion    { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '%' expresion    { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion AND expresion    { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion OR expresion     { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion EQ expresion     { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion NEQ expresion    { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ; // En Lisp el distinto es /=
                                           $$.code = gen_code (temp) ; }
            |   expresion '<' expresion    { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '>' expresion    { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion LE expresion     { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion GE expresion     { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

termino:        operando                           { $$ = $1 ; }                          
            |   '+' operando %prec UNARY_SIGN      { $$ = $1 ; }
            |   '-' operando %prec UNARY_SIGN      { sprintf (temp, "(- %s)", $2.code) ;
                                                     $$.code = gen_code (temp) ; }
            |   '!' operando %prec NOT             { sprintf (temp, "(not %s)", $2.code) ;
                                                    $$.code = gen_code (temp) ; }    
            ;

operando:   IDENTIF                  { 
                char *var_name = get_var_name($1.code);
                sprintf (temp, "%s", var_name) ;
                $$.code = gen_code (temp) ; 
            }
            | NUMBER                   { sprintf (temp, "%d", $1.value) ; $$.code = gen_code (temp) ; }
            | '(' expresion ')'        { $$ = $2 ; }
            | IDENTIF '(' lista_argumentos ')' 
                { 
                    sprintf(temp, "(%s %s)", $1.code, $3.code);
                    $$.code = gen_code(temp);
                }
            | IDENTIF '[' expresion ']'
                {
                    char *var_name = get_var_name($1.code);
                    sprintf(temp, "(aref %s %s)", var_name, $3.code);
                    $$.code = gen_code(temp);
                }
            ;

lista_argumentos:
                            { $$.code = gen_code(""); }
            | expresion             { $$ = $1; }
            | expresion ',' lista_argumentos { sprintf(temp, "%s %s", $1.code, $3.code); $$.code = gen_code(temp); }
            ;

%%                            // SECCION 4    Codigo en C

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
