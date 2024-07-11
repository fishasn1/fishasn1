#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <stdbool.h>

#define ABSENT "ABSENT"
#define ABSTRACT_SYNTAX "ABSTRACT-SYNTAX"
#define ALL "ALL"
#define APPLICATION "APPLICATION"
#define AUTOMATIC "AUTOMATIC"
#define BEGIN "BEGIN"
#define BIT "BIT"
#define BMPString "BMPString"
#define BOOLEAN "BOOLEAN"
#define BY "BY"
#define CHARACTER "CHARACTER"
#define CHOICE "CHOICE"
#define CLASS "CLASS"
#define COMPONENT "COMPONENT"
#define COMPONENTS "COMPONENTS"
#define CONSTRAINED "CONSTRAINED"
#define CONTAINING "CONTAINING"
#define DATE "DATE"
#define DATE_TIME "DATE-TIME"
#define DEFAULT "DEFAULT"
#define DEFINITIONS "DEFINITIONS"
#define DURATION "DURATION"
#define EMBEDDED "EMBEDDED"
#define ENCODED "ENCODED"
#define ENCODING_CONTROL "ENCODING-CONTROL"
#define END "END"
#define ENUMERATED "ENUMERATED"
#define EXCEPT "EXCEPT"
#define EXPLICIT "EXPLICIT"
#define EXPORTS "EXPORTS"
#define EXTENSIBILITY "EXTENSIBILITY"
#define EXTERNAL "EXTERNAL"
#define FALSE "FALSE"
#define FROM "FROM"
#define GeneralizedTime "GeneralizedTime"
#define GeneralString "GeneralString"
#define GraphicString "GraphicString"
#define IA5String "IA5String"
#define IDENTIFIER "IDENTIFIER"
#define IMPLICIT "IMPLICIT"
#define IMPLIED "IMPLIED"
#define IMPORTS "IMPORTS"
#define INCLUDES "INCLUDES"
#define INSTANCE "INSTANCE"
#define INSTRUCTIONS "INSTRUCTIONS"
#define INTEGER "INTEGER"
#define INTERSECTION "INTERSECTION"
#define ISO646String "ISO646String"
#define MAX "MAX"
#define MIN "MIN"
#define MINUS_INFINITY "MINUS-INFINITY"
#define NOT_A_NUMBER "NOT-A-NUMBER"
#define _NULL "NULL"
#define NumericString "NumericString"
#define OBJECT "OBJECT"
#define ObjectDescriptor "ObjectDescriptor"
#define OCTET "OCTET"
#define OF "OF"
#define OID_IRI "OID-IRI"
#define OPTIONAL "OPTIONAL"
#define PATTERN "PATTERN"
#define PDV "PDV"
#define PLUS_INFINITY "PLUS-INFINITY"
#define PRESENT "PRESENT"
#define PrintableString "PrintableString"
#define PRIVATE "PRIVATE"
#define REAL "REAL"
#define RELATIVE_OID "RELATIVE-OID"
#define RELATIVE_OID_IRI "RELATIVE-OID-IRI"
#define SEQUENCE "SEQUENCE"
#define SET "SET"
#define SETTINGS "SETTINGS"
#define SIZE "SIZE"
#define STRING "STRING"
#define SYNTAX "SYNTAX"
#define T61String "T61String"
#define TAGS "TAGS"
#define TeletexString "TeletexString"
#define TIME "TIME"
#define TIME_OF_DAY "TIME-OF-DAY"
#define TRUE "TRUE"
#define TYPE_IDENTIFIER "TYPE-IDENTIFIER"
#define UNION "UNION"
#define UNIQUE "UNIQUE"
#define UNIVERSAL "UNIVERSAL"
#define UniversalString "UniversalString"
#define UTCTime "UTCTime"
#define UTF8String "UTF8String"
#define VideotexString "VideotexString"
#define VisibleString "VisibleString"
#define WITH "WITH"

typedef enum {
        TOKEN_KEYWORD_ABSENT,
        TOKEN_KEYWORD_ABSTRACT_SYNTAX,
        TOKEN_KEYWORD_ALL,
        TOKEN_KEYWORD_APPLICATION,
        TOKEN_KEYWORD_AUTOMATIC,
        TOKEN_KEYWORD_BEGIN,
        TOKEN_KEYWORD_BIT,
        TOKEN_KEYWORD_BMPString,
        TOKEN_KEYWORD_BOOLEAN,
        TOKEN_KEYWORD_BY,
        TOKEN_KEYWORD_CHARACTER,
        TOKEN_KEYWORD_CHOICE,
        TOKEN_KEYWORD_CLASS,
        TOKEN_KEYWORD_COMPONENT,
        TOKEN_KEYWORD_COMPONENTS,
        TOKEN_KEYWORD_CONSTRAINED,
        TOKEN_KEYWORD_CONTAINING,
        TOKEN_KEYWORD_DATE,
        TOKEN_KEYWORD_DATE_TIME,
        TOKEN_KEYWORD_DEFAULT,
        TOKEN_KEYWORD_DEFINITIONS,
        TOKEN_KEYWORD_DURATION,
        TOKEN_KEYWORD_EMBEDDED,
        TOKEN_KEYWORD_ENCODED,
        TOKEN_KEYWORD_ENCODING_CONTROL,
        TOKEN_KEYWORD_END,
        TOKEN_KEYWORD_ENUMERATED,
        TOKEN_KEYWORD_EXCEPT,
        TOKEN_KEYWORD_EXPLICIT,
        TOKEN_KEYWORD_EXPORTS,
        TOKEN_KEYWORD_EXTENSIBILITY,
        TOKEN_KEYWORD_EXTERNAL,
        TOKEN_KEYWORD_FALSE,
        TOKEN_KEYWORD_FROM,
        TOKEN_KEYWORD_GeneralizedTime,
        TOKEN_KEYWORD_GeneralString,
        TOKEN_KEYWORD_GraphicString,
        TOKEN_KEYWORD_IA5String,
        TOKEN_KEYWORD_IDENTIFIER,
        TOKEN_KEYWORD_IMPLICIT,
        TOKEN_KEYWORD_IMPLIED,
        TOKEN_KEYWORD_IMPORTS,
        TOKEN_KEYWORD_INCLUDES,
        TOKEN_KEYWORD_INSTANCE,
        TOKEN_KEYWORD_INSTRUCTIONS,
        TOKEN_KEYWORD_INTEGER,
        TOKEN_KEYWORD_INTERSECTION,
        TOKEN_KEYWORD_ISO646String,
        TOKEN_KEYWORD_MAX,
        TOKEN_KEYWORD_MIN,
        TOKEN_KEYWORD_MINUS_INFINITY,
        TOKEN_KEYWORD_NOT_A_NUMBER,
        TOKEN_KEYWORD_NULL,
        TOKEN_KEYWORD_NumericString,
        TOKEN_KEYWORD_OBJECT,
        TOKEN_KEYWORD_ObjectDescriptor,
        TOKEN_KEYWORD_OCTET,
        TOKEN_KEYWORD_OF,
        TOKEN_KEYWORD_OID_IRI,
        TOKEN_KEYWORD_OPTIONAL,
        TOKEN_KEYWORD_PATTERN,
        TOKEN_KEYWORD_PDV,
        TOKEN_KEYWORD_PLUS_INFINITY,
        TOKEN_KEYWORD_PRESENT,
        TOKEN_KEYWORD_PrintableString,
        TOKEN_KEYWORD_PRIVATE,
        TOKEN_KEYWORD_REAL,
        TOKEN_KEYWORD_RELATIVE_OID,
        TOKEN_KEYWORD_RELATIVE_OID_IRI,
        TOKEN_KEYWORD_SEQUENCE,
        TOKEN_KEYWORD_SET,
        TOKEN_KEYWORD_SETTINGS,
        TOKEN_KEYWORD_SIZE,
        TOKEN_KEYWORD_STRING,
        TOKEN_KEYWORD_SYNTAX,
        TOKEN_KEYWORD_T61String,
        TOKEN_KEYWORD_TAGS,
        TOKEN_KEYWORD_TeletexString,
        TOKEN_KEYWORD_TIME,
        TOKEN_KEYWORD_TIME_OF_DAY,
        TOKEN_KEYWORD_TRUE,
        TOKEN_KEYWORD_TYPE_IDENTIFIER,
        TOKEN_KEYWORD_UNION,
        TOKEN_KEYWORD_UNIQUE,
        TOKEN_KEYWORD_UNIVERSAL,
        TOKEN_KEYWORD_UniversalString,
        TOKEN_KEYWORD_UTCTime,
        TOKEN_KEYWORD_UTF8String,
        TOKEN_KEYWORD_VideotexString,
        TOKEN_KEYWORD_VisibleString,
        TOKEN_KEYWORD_WITH,
        TOKEN_TYPE_REFERENCE,
        TOKEN_IDENTIFIER,
        TOKEN_VALUE_REFERENCE,  /* equivalent to TOKEN_IDENTIFIER */
        TOKEN_MODULE_REFERENCE, /* equivalent to TOKEN_TYPE_REFERENCE */
        TOKEN_ONE_LINE_COMMENT,
        TOKEN_MULTI_LINE_COMMENT,
        TOKEN_END_OF_FILE,
        TOKEN_UNKNOWN,
        TOKEN_ERROR
} TOKEN_TYPE_ENUM;

typedef struct {
        TOKEN_TYPE_ENUM type;
        unsigned char *value;
} token_t;

typedef struct {
    char *stream;
    unsigned int pos;
    unsigned int line_num;
    unsigned int column;
} tokenizer_t;

bool is_eol(char ch);
bool is_digit(char ch);
bool is_letter(char ch);
bool is_upper_case(char ch);
bool is_lower_case(char ch);
bool is_eof(char ch);
bool is_white_space(char ch);
char next_char(tokenizer_t *tokenizer);
char peek_char(tokenizer_t *tokenizer);

tokenizer_t* tokenizer_create(char *stream);
token_t* next_token(tokenizer_t *tokenizer);
void token_free(token_t *token);
#endif /* TOKENIZER_H_ */
